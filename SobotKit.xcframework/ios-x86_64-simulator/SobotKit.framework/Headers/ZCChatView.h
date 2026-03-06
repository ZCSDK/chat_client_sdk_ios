//
//  ZCChatView.h
//  SobotKit
//
//  Created by zhangxy on 2022/8/30.
//

#import <UIKit/UIKit.h>
#import "ZCTitleView.h"
NS_ASSUME_NONNULL_BEGIN

@protocol ZCChatViewDelegate <NSObject>

@optional
// 头部点击事件，(返回/清理消息)
//-(void)topViewBtnClick:(ZCButtonClickTag )Tag;


/// 设置聊天页面导航栏 标题+ 头像 + 企业昵称+ 状态+ 无人接待场景的设置
/// @param title 标题中间显示 大字体
/// @param url 头像
/// @param nick 昵称
/// @param company 企业名称
/// @param topBarType 样式1或者样式2
/// @param firstLetter 首字母
/// @param statusStr 状态描述字段
/// @param isShowFirst 是否显示首字母控件
-(void)onTitleChanged:(NSString *)title imageUrl:(NSString *) url nick:(NSString *)nick company:(NSString *)company topBarType:(int)topBarType firstLetter:(NSString *)firstLetter statusStr:(NSString *)statusStr isShowFirst:(BOOL)isShowFirst;


- (void)onPageConnectStatusChange:(BOOL)isArtificial;

/// 返回页面
/// @param isAction 是否返回
/// @param isClose 返回是否结束会话
-(void)onBackFinish:(BOOL) isAction closeClick:(BOOL ) isClose;

// 更新导航栏颜色
-(void)chatInitSuccesed;

-(void)jumpDocumentVC:(UIViewController*)docVC;

@end

@interface ZCChatView : UIView

// 设置页面代理
@property (nonatomic,weak) id<ZCChatViewDelegate>delegate;

@property(nonatomic,copy) UITableView *listTable;

-(void)loadDataToView;

// 更新数据
-(void)viewReloadTableData;

-(void)beginAniantions;

/// 是否为点击关闭按钮
/// @param isClose YES，点击关闭
-(void)closeChatView:(BOOL) isClose;

-(void)backChatView;

// 获取输入框 用户自定义
-(UITextView *)getChatTextView;

-(void)hiddenKeyboard;
@end

NS_ASSUME_NONNULL_END
