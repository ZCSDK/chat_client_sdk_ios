//
//  SobotSocketConnect.h
//  SobotTcpServer
//
//  Created by zhangxy on 2021/9/23.
//

#import <Foundation/Foundation.h>
#import <SobotCommon/SobotTcpDataProcessor.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotSocketConnect : NSObject

// socket链接地址
@property (strong, nonatomic) NSString *tcpAddress;

+(SobotSocketConnect *)shareSocketConnect;

/// 创建新的链接，如果已经创建会断开重新链接
/// @param address  链接的地址，例如127.0.0.1:8080
-(void)connect:(NSString *) address delegate:(id<SobotTcpDataDelegate> _Nullable) delegate;


/// 检查是否链接，如果未链接，则尝试链接
-(void)checkConnect;


/// 断开链接
-(void)closeConnected;

// 仅能发布文本
-(void)sendMessage:(NSString *) text;


/// 字典不能为空
/// @param dict 必须包含事例字段
///  [exDict setObject:dict[@"u"] forKey:@"u"];
///  [exDict setObject:dict[@"deviceToken"] forKey:@"deviceToken"];
///  [exDict setObject:dict[@"appid"] forKey:@"appid"];
///  [exDict setObject:dict[@"puid"] forKey:@"puid"];
///  [exDict setObject:dict[@"debug"] forKey:@"debug"];
///  connectMsgId = dict[@"msgId"];
-(void)sendConnectMessage:(NSDictionary *)dict;



/// 检查消息类型,判断重复(_repeatDict 加锁,IM/轮询共享),并对正常业务消息回 IM ack。
/// 内部 confirmMsg: 已根据 self.connected 判断,IM 未连时 ack 自动 no-op,
/// 因此轮询路径直接调用本方法即可(轮询的 HTTP /ack 由业务层另行触发)。
/// @param dict 收到的消息字典
/// @return YES = 控制消息/重复消息,业务层不再处理
-(BOOL)checkMessageUnUsed:(NSDictionary *) dict;


@end

NS_ASSUME_NONNULL_END
