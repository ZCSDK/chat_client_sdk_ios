//
//  SobotSSEClient.h
//  SobotNetwork
//
//  Created by zhangxinyao on 2025/10/29.
//  Migrated from SobotChatClient/https/SobotHttpRequest on 2026-05-21.
//
//  注意:本类的类型/枚举/类名与旧 SobotHttpRequest.h 有意避开命名冲突,
//  方便老项目里仍保留 SobotHttpRequest.{h,m} 的工程同时引入 SobotCommon。
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Handlers

typedef void (^SobotSSEEventHandler)(NSString * _Nonnull event, NSString * _Nullable data);
typedef void (^SobotSSEErrorHandler)(NSError * _Nullable error);

#pragma mark - 重连策略

typedef NS_ENUM(NSUInteger, SobotSSEReconnectStrategy) {
    SobotSSEReconnectStrategyNever,     // 不自动重连
    SobotSSEReconnectStrategyImmediate, // 立即重连
    SobotSSEReconnectStrategyDelayed,   // 延迟重连(需指定 reconnectInterval)
};

#pragma mark - 订阅配置

@interface SobotSSESubscribeConfig : NSObject

@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *headers;

@property (nonatomic, assign) SobotSSEReconnectStrategy reconnectStrategy;  // 默认 Immediate
@property (nonatomic, assign) NSTimeInterval reconnectInterval;             // 默认 3.0,仅 Delayed 时生效

// 断线续传:服务端 id: 字段,通过 Last-Event-ID 头回传
@property (nonatomic, copy, nullable) NSString *lastEventID;

// 参数传输方式
@property (nonatomic, assign) BOOL useJSONBody;     // 默认 NO:参数拼到 URL;YES:POST + application/json
@property (nonatomic, strong, nullable) id parameters;  // NSDictionary 或 NSArray

@end

#pragma mark - SSE 客户端

/**
 * SSE (Server-Sent Events) 客户端,内部按 key 区分多个并发订阅。
 *
 * 用法 1:单 SSE 流(简单场景)
 *   SobotSSESubscribeConfig *cfg = [SobotSSESubscribeConfig new];
 *   cfg.url = @"https://ai/llm/stream";
 *   [[SobotSSEClient shared] subscribeWithKey:@"ai_stream"
 *                                      config:cfg
 *                                eventHandler:^(NSString *e, NSString *d) { ... }
 *                                errorHandler:^(NSError *err) { ... }];
 *
 * 用法 2:并发多 SSE 流(常规业务流 + 消息监听流同时存在)
 *   [[SobotSSEClient shared] subscribeWithKey:@"business" config:cfgA ...];
 *   [[SobotSSEClient shared] subscribeWithKey:@"notify"   config:cfgB ...];
 *   // 互不影响,各自独立的 task / buffer / handlers / 重连
 *
 * 用法 3:取消
 *   [[SobotSSEClient shared] unsubscribeWithKey:@"business"];
 *   [[SobotSSEClient shared] unsubscribeAll];
 *
 * 用法 4:同 key 重复 subscribe
 *   旧订阅会先收到一次 NSURLErrorCancelled,然后新订阅启动。
 *
 * 注意:eventHandler / errorHandler 在主线程回调(便于 UI 流式渲染),与其他 SobotNetwork API 一致。
 */
@interface SobotSSEClient : NSObject

+ (instancetype)shared;

#pragma mark 订阅 / 取消

- (void)subscribeWithKey:(NSString *)key
                  config:(SobotSSESubscribeConfig *)config
            eventHandler:(nullable SobotSSEEventHandler)eventHandler
            errorHandler:(nullable SobotSSEErrorHandler)errorHandler;

- (void)unsubscribeWithKey:(NSString *)key;
- (void)unsubscribeAll;

#pragma mark 查询

- (BOOL)isConnectedForKey:(NSString *)key;
- (NSArray<NSString *> *)allActiveKeys;

#pragma mark Last-Event-ID 持久化(按 key 区分)

- (void)saveLastEventID:(NSString *)eventID forKey:(NSString *)key;
- (nullable NSString *)loadLastEventIDForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
