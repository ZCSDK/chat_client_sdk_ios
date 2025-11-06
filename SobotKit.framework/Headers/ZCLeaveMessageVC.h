//
//  ZCLeaveMessageVC.h
//  SobotKit
//
//  Created by lizh on 2025/9/8.
//  V7 新版UI 该页面 存放 留言模块view + 留言记录View (新建VC 区分旧版的VC)

#import <SobotKit/SobotKit.h>
#import <SobotCommon/SobotCommon.h>
#import "ZCMessageTemplateView.h"
#import "ZCUIKitTools.h"
#import <SobotKit/SobotKit.h>
#import <SobotChatClient/SobotChatClient.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZCLeaveMessageVC : SobotClientBaseController

// 0 留言模版 1显示留言记录 （有留言记录先显示留言记录）
@property(nonatomic,assign)int type;
// 是否显示创建留言按钮
@property(nonatomic,assign)BOOL isShowCreate;
@property(nonatomic,strong)NSDictionary *Dic;
@property(nonatomic,assign)BOOL isRecord;// 是否直接跳转到留言记录页面
@property(nonatomic,assign)BOOL isShow;
@property(nonatomic,copy)NSString *tipMsg;
@property(nonatomic,assign)BOOL isExist;
// 仅显示留言模版页面
@property(nonatomic,assign)BOOL isOnlyTemplateView;
// 记录页面层级 处理多级跳转的问题
@property(nonatomic,assign)int level;

//////以下数据是从外抛api的接口获取的用户直接启动留言页面
// 从外抛api 直接进入留言页面 用户如果传了模版ID直接跳转到留言编辑页面不再弹留言模版页面
@property(nonatomic,copy) NSString *leaveTemplateId;
@property (nonatomic , assign) BOOL enclosureShowFlag;
@property (nonatomic , assign) BOOL enclosureFlag;
@property (nonatomic , assign) BOOL telFlag;
@property (nonatomic , assign) BOOL emailFlag;
@property (nonatomic , assign) BOOL telShowFlag;
@property (nonatomic , assign) BOOL emailShowFlag;
@property (nonatomic,strong) NSString *msgTmp;
@property (nonatomic,strong) NSString *msgTxt;
@property(nonatomic,assign) BOOL isNavOpen;
// 是否仅显示留言记录，开放接口
@property(nonatomic,assign) BOOL isOnlyShow;
// 当前是使用开放api
@property(nonatomic,assign) BOOL isOpenApi;
// 记录留言记录的数据
@property(nonatomic,strong) NSMutableArray *tempRecordArray;
@property(nonatomic,strong) UIViewController *byController;
@property(nonatomic,assign) int isOpenEditType;
-(id)initWithType:(int)type;

@end

NS_ASSUME_NONNULL_END
