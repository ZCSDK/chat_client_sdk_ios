//
//  SobotNetwork.h
//  SobotNetwork
//
//  Created by zhangxy on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SobotRequest.h"


// 自定义超时时间，每次请求header中增加此参数，单位毫秒，默认30秒
FOUNDATION_EXPORT NSString * const SobotRequestHeaderTimeoutInterval;

/**
 *  开始请求，每次发送请求时调用
 */
typedef void(^SobotStartLoadingBlock)(id taskReq);

/**
 *  请求成功
 *
 *  @param dict 成功后，解析的返回
 */
typedef void(^SobotSuccessBlock)(id response,NSDictionary *dict,NSData *data);

/**
 *  请求完成，不管失败、成功，只要完成都会执行，可为nil
 *
 *  @param response 请求返回NSURLResponse
 */
typedef void(^SobotFinishBlock)(id response,NSData *data, NSString *jsonString);

/**
 *  请求失败
 *
 *  @param response     请求返回NSURLResponse
 *  @param connectError 失败的connectError
 */
typedef void(^SobotFailBlock)(id response,NSString *errorMsg,NSError *connectError);


/**
 *  上传、下载进度
 *
 *  @param progress 上传、下载进度，如0.2，0.5
 */
typedef void(^SobotProgressBlock)(id taskReq,CGFloat progress);


typedef NSURLSessionConfiguration * (^SobotUpdateURLCconfigBlock)(NSURLSessionConfiguration *config);

/**
 * SobotNetwork 网络请求门面。
 *
 * 推荐使用单例 + 实例方法:
 *   [[SobotNetwork shared] get:url params:... ...];
 *   [[SobotNetwork shared] post:url params:... ...];
 *   [[SobotNetwork shared] clearTask];
 *
 * 老的类方法 +get:/+post:/+url:/+clearTask 仍可用,但已标记 deprecated。
 * 回调均在主线程。
 */
@interface SobotNetwork : NSObject

#pragma mark - 单例

+ (instancetype)shared;
+ (SobotNetwork *)shareSobotNetwork __deprecated_msg("Use [SobotNetwork shared]");

#pragma mark - 配置

- (void)setUpdateConfigBlock:(SobotUpdateURLCconfigBlock)block;
+ (void)setUpdateConfigBlock:(SobotUpdateURLCconfigBlock)block __deprecated_msg("Use [[SobotNetwork shared] setUpdateConfigBlock:]");

#pragma mark - 取消

- (void)clearTask;
+ (void)clearTask __deprecated_msg("Use [[SobotNetwork shared] clearTask]");

#pragma mark - 调试

- (void)get:(NSString *)api_url params:(NSDictionary *)paramters;
+ (void)get:(NSString *)api_url params:(NSDictionary *)paramters __deprecated_msg("Use [[SobotNetwork shared] get:params:]");

#pragma mark - GET

- (void)get:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock;

- (void)get:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock
   progress:(SobotProgressBlock)proressBlock;

+ (void)get:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock __deprecated_msg("Use [[SobotNetwork shared] get:params:header:begin:success:fail:finish:]");

+ (void)get:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock
   progress:(SobotProgressBlock)proressBlock __deprecated_msg("Use [[SobotNetwork shared] get:...:progress:]");

#pragma mark - POST

- (void)post:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock;

- (void)post:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
  paramsMode:(SobotParameterMode)mode
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock
    progress:(SobotProgressBlock)proressBlock;

+ (void)post:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock __deprecated_msg("Use [[SobotNetwork shared] post:...]");

+ (void)post:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
  paramsMode:(SobotParameterMode)mode
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock
    progress:(SobotProgressBlock)proressBlock __deprecated_msg("Use [[SobotNetwork shared] post:...paramsMode:...progress:]");

#pragma mark - URL (任意 method)

- (void)url:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
 paramsMode:(SobotParameterMode)mode
     mothed:(NSString *)mothed
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock
   progress:(SobotProgressBlock)proressBlock;

+ (void)url:(NSString *)api_url
     params:(NSDictionary *)paramters
     header:(NSDictionary *)header
 paramsMode:(SobotParameterMode)mode
     mothed:(NSString *)mothed
      begin:(SobotStartLoadingBlock)beginBlock
    success:(SobotSuccessBlock)successBlock
       fail:(SobotFailBlock)failBlock
     finish:(SobotFinishBlock)finishBlock
   progress:(SobotProgressBlock)proressBlock __deprecated_msg("Use [[SobotNetwork shared] url:...]");

@end
