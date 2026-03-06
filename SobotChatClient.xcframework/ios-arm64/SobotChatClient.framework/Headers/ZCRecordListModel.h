//
//  ZCRecordListModel.h
//  SobotChatClient
//
//  Created by lizh on 2022/9/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCRecordListModel : NSObject
//"content":"ydysy",
//"flag":1,
//"newFlag":1,
//"ticketCode":20190305000001,
//"ticketId":"235a803c9fc64419ad12fa3f761640bb",
//"time":1551777295,
//"timeStr":"2019-03-05 17:14:55"

@property (nonatomic,copy) NSMutableAttributedString * contentAttr; // 工单描述
@property (nonatomic,assign) int flag;  //1 创建了  2 受理了 3 关闭了


// 4.2.1版本新增字段，回复记录状态
@property (nonatomic,assign) int acceptStatus;

@property (nonatomic,assign) int newFlag; // 是否更新
@property (nonatomic,copy) NSString * ticketCode;  //工单编号

@property (nonatomic,copy) NSString * serviceNick;// 客服昵称
@property (nonatomic,copy) NSString * customerId;// 客户id
// flag ==2 时 ，有子集  replayList

@property (nonatomic,strong) NSMutableArray * replayList;
@property (nonatomic,copy) NSString * dealUserName; // 回复的昵称 客服昵称或者用户昵称
@property (nonatomic,copy) NSString * replyContent;// 回复内容
@property (nonatomic,assign)  int startType; // 0 客服  1客户
@property (nonatomic,copy) NSString * replyTime; // 回复的时间 时间戳1552296719 需要处理
@property (nonatomic,copy) NSString * replyTimeStr; // 回复的时间 时间戳1552296719 需要处理
@property (nonatomic,strong) NSMutableAttributedString *replyTimeStrAttr;

// flag == 3 的时候有子集 触发评价相关
//@property (nonatomic,assign) int isEvalution; // isEvalution


@property (nonatomic,assign) int  defaultQuestionFlag;// 是否解决



@property (nonatomic,assign) int txtFlag ; //评价文本框开关  0 关闭  1 开启
@property (nonatomic,strong) NSMutableArray * ticketScoreInfooList;// （星级内容

// 4.2.5版本接口新增字段，返回工单内容的文件列表
@property (nonatomic,strong) NSMutableArray * ticketFileList; // 文件

// 4.2.3版本 接口数据改动
@property (nonatomic,copy) NSString * content; // 工单描述
@property (nonatomic,assign) int isEvaluation;//是否评价过
@property (nonatomic,assign) int isOpen;// isOpen（是否开启满意度评价  0 未开启  1 开启）
@property (nonatomic,copy) NSString * remark;// 反馈意见
@property (nonatomic,copy) NSString * score;// 评价得分
@property (nonatomic,copy) NSString * tag;// 评价标签

@property (nonatomic,copy) NSString * time;
@property (nonatomic,copy) NSString * timeStr;

// 显示暂无回复
@property (nonatomic,assign)BOOL isShowNoData;
// 区头是否展开
@property (nonatomic,assign)BOOL isLookOpen;

/**********************V7 新版留言详情页面 接口使用***************************/
@property (nonatomic,copy) NSString * ticketId; // 工单id
@property (nonatomic,copy) NSString * ticketTitle; // 标题
// 问题描述
@property(nonatomic,copy) NSString *ticketContent;
@property(nonatomic,assign) int ticketStatus;  //1 创建了  2 受理了 3 关闭了
@property(nonatomic,copy)NSString *ticketCreateTime;// 工单创建时间（毫秒级）
@property(nonatomic,assign) BOOL isShowSatisficatiobButton;// 是否展示满意度评价按钮（满足满意度评价条件且未评价时才展示） 1 是 0 否
@property(nonatomic,assign) BOOL isEvaluated;// 是否已评价  1 是 0 否
// 2.8.2
@property (nonatomic,strong) NSMutableArray * fileList; // 文件
@property (nonatomic,strong) NSMutableArray *replyList;// 有值才显示，每一条的回复记录
@property (nonatomic,strong) NSDictionary * cusNewSatisfactionVO;// 评价配置

-(id)initWithMyDict:(NSDictionary *)dict;
@end

// 每一条回复工单的记录，新接口去掉了首条已创建的数据
@interface ZCRecordListDetailModel : NSObject
@property (nonatomic,copy) NSString *acceptStatus;
@property (nonatomic,copy) NSString *companyId;
@property (nonatomic,copy) NSString *dealLogId;
@property (nonatomic,copy) NSString *dealUserId;
@property (nonatomic,copy) NSString *dealUserName;
@property (nonatomic,copy) NSString *duration;
@property (nonatomic,copy) NSString *logStatus;
@property (nonatomic,copy) NSString *previousStatus;
@property (nonatomic,copy) NSString *previousUserId;
@property (nonatomic,copy) NSString *previousUserName;
@property (nonatomic,copy) NSString *replyTimeStr;
@property (nonatomic,copy) NSString *replyTitle;
@property (nonatomic,copy) NSString *replyType;
@property (nonatomic,copy) NSString *ticketId;
@property (nonatomic,copy) NSString *ticketReplyTypeNew;
@property (nonatomic,copy) NSString *updateUserId;
@property (nonatomic,copy) NSString *serviceNick;

//*************************** V7 新版接口使用
@property(nonatomic,assign) int itemType;// 1 回复  2 评价
@property(nonatomic,assign) int startType;// 更新人类型：0客服，1普通用户 2触发器 3工单机器人
@property(nonatomic,copy)NSString *updateUserName;// 客服名(用户名)
@property(nonatomic,copy)NSString *replyContent;// 回复内容
@property (nonatomic,strong)NSMutableArray * fileList; // 文件 附件
@property (nonatomic,copy)NSString *replyTime;// 回复时间（毫秒级）

// 评价的数据
@property(nonatomic,copy)NSString *score;// 评分
@property(nonatomic,assign)int questionFlag;// 问题是否解决，0-未解决 1-解决 -1-未选择
@property(nonatomic,copy)NSString *remark;// 用户评价
@property(nonatomic,strong)NSMutableArray *tags; // 标签数组
-(id)initWithMyDict:(NSDictionary *)dict;
@end
NS_ASSUME_NONNULL_END
