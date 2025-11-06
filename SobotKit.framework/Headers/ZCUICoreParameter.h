//
//  ZCUICoreParameter.h
//  SobotKit
//
//  Created by zhangxinyao on 2025/9/9.
//

#import <Foundation/Foundation.h>
#import <SobotChatClient/SobotChatClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCUICoreParameter : NSObject

// 临时变量记录本次会话是否给机器人发送给自定义消息
@property(nonatomic,assign) BOOL goodMsgSendToRobot;

// 临时变量记录本次会话是否给客服发送给自定义消息
@property(nonatomic,assign) BOOL goodMsgSendToService;

// 已经加载过历史记录
@property(nonatomic,assign) BOOL isHadCidLoaded;

// 是否锁定当前的消息
@property(nonatomic,assign) BOOL isLockMsg;
// 锁定当前消息的个数
@property(nonatomic,assign) int lockMsgCount;


//defaultQuestionFlag：“问题是否解决”默认选中状态：(0)-未解决 (1)-解决 (-1)-不选中
//defaultType：默认显示星级  0-5星,1-0星 / 0-10分，1-5分，2-0分，3-不选中
//isQuestionFlag：人工客服是否解决问题开关  1-开启 0-关闭
//isQuestionMust：“问题是否解决”是否为必填选项： 0-非必填 1-必填
//scoreFlag：星级类型 0-旧版5星级评价  1-nps评价
//status：模板状态开关 0-关闭 1-开启
@property(nonatomic,strong) ZCSatisfactionConfig *_Nullable satisfactionConfig; // 评价选项
@property(nonatomic,strong) ZCSatisfactionConfig *_Nullable aiAgentSatisfactionConfig; // 大模型机器人评价选项
@property(nonatomic,strong) ZCSatisfactionConfig *_Nullable satisfactionLeaveConfig; // 留言评价选项
@property(nonatomic,assign) BOOL isCommentAiAgentCid; // 是否已经评价过当前大模型会话
@property(nonatomic,assign) BOOL isLoadAiAgentCid; // 是否已经评价过当前大模型会话
@property(nonatomic,strong) NSString *_Nullable commentTipsString; // 是否已经评价原因


@property(nonatomic,assign) BOOL isShowRobotHello; // 是否显示机器人欢迎语
@property(nonatomic,assign) BOOL isShowRobotGuide; // 是否显示机器人常见问题


@property(nonatomic,assign) BOOL isShowAdminHello; // 是否显示人工欢迎语


// 结束会话之前是否为人工模式，方便评价时获取当前状态
@property(nonatomic,assign) BOOL isAdminServerBeforeCloseSession;
@property (nonatomic,assign) BOOL isEvaluationService; // 是否评价过人工
@property (nonatomic,assign) BOOL isEvaluationRobot; // 是否评价过机器人

// 是否发送过消息
@property (nonatomic,assign) BOOL isSendToUser;
@property (nonatomic,assign) BOOL isSendToRobot;

// 当前转人工选中的技能组
@property (nonatomic,copy) NSString *checkGroupId;
@property (nonatomic,copy) NSString *checkGroupName;


/** 未知说辞计数*/
@property (nonatomic, assign) NSUInteger unknownWordsCount;

// 是否直接去转人工，不在查询询前表单的接口
@property(nonatomic,assign) BOOL isShowForm;

// 是否显示过通告信息
@property(nonatomic,assign) BOOL isShowNotice;

// 是否已经执行过转人工，再发送消息的时候使用，YES时，说明已经转过人工了，但是未说过话不做真正的转人工调用
@property (nonatomic,assign) BOOL isAfterConnectUser;


// 是否执行过一次转人工（延迟转人工有用）
@property (nonatomic,assign) BOOL isDoConnectedUser;


// 是否离线
@property(nonatomic,assign) BOOL isOffline;

// 是否是拉黑
@property (nonatomic,assign) BOOL isOfflineBeBlack;


// 快捷菜单
@property(nonatomic,strong)NSDictionary *_Nullable robotDict;
@property(nonatomic,strong)NSDictionary *_Nullable manualDict;


// 0,进入会话（不会使用，默认合并到机器人和人工中），1机器人会话，2人工
@property(nonatomic,assign)int opportunity;
// 上一次展示的列表，如果不相同则说明切了
@property(nonatomic,assign)int lastOpportunity;

@end

NS_ASSUME_NONNULL_END
