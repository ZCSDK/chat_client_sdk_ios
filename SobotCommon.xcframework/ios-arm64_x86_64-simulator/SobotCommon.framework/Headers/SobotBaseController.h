//
//  SobotBaseController.h
//  SobotOnline
//
//  Created by zhangxy on 2020/8/5.
//  Copyright © 2020 sobot. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SobotCommon/SobotUITools.h>
#import <SobotCommon/SobotCommonDefine.h>
#import <SobotCommon/SobotFontColor.h>
#import <SobotCommon/SobotLayoutAdaptive.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,SobotButtonClick) {
    SobotButtonClickBack = 0,
    SobotButtonClickBackChat,
    SobotButtonClickClose,
    SobotButtonClickMenu,
    SobotButtonClickRight,
    SobotButtonClickItem1,
    SobotButtonClickItem2,
    SobotButtonClickItem3,
    SobotButtonClickTransfer,
    SobotButtonClickFavoriter,
    SobotButtonClickBlock,
    SobotButtonClickEdit, // 新建工单
    SobotButtonClickSearch,// 搜索工单
    SobotButtonClickCommit,// 提交
    SobotButtonClickMore,// 点击更多
    SobotButtonClickStart,// 标记
    SobotButtonClickSort,// 排序
    SobotButtonClickDelImg,//删除图片
    SobotButtonClickReply,// 回复工单
    SobotButtonClickActivate,//激活工单
    SobotButtonClickEvaluate,// 评价
    SobotButtonClickTEL,// 电话
};

/// sobot_layoutViews:axis:insets: 的排列方向
/// - SobotLayoutAxisVertical:   views 数组在内容区内 垂直堆叠。
///                              首 view 顶部贴导航下方,末 view 底部贴 safeArea 底,
///                              所有 view 的左右边贴 safeArea(大屏自动限宽居中)。
///                              中间 view 之间的间距由调用方自行加约束(基类不管中间)。
/// - SobotLayoutAxisHoritional: views 数组在内容区内 水平排列(分栏场景)。
///                              首 view leading 贴左,末 view trailing 贴右,
///                              所有 view 上下贴(导航下 → safeArea 底)。
typedef NS_ENUM(NSInteger,SobotLayoutAxis) {
    SobotLayoutAxisVertical = 1,
    SobotLayoutAxisHoritional = 2,
};

@interface SobotBaseController : UIViewController

// 内容相对于view的正在开始坐标，主要计算导航的高度
@property(nonatomic,assign) CGFloat currentContentY;

@property(nonatomic,strong) NSString *bundleName;
/**
 *  顶部的View
 */
@property(nonatomic,strong) UIView *topView;

// 顶部view 内容视图
@property(nonatomic,strong) UIView *topContentView;

/**
 *  关闭按钮（返回）
 */
@property(nonatomic,strong) UIButton *backButton;

/**
  更多按钮，SobotButtonClickRight
 */
@property(nonatomic,strong) UIButton *moreButton;

/**
 *  标题
 */
@property(nonatomic,strong) UILabel *__nullable titleLabel;

@property(nonatomic,strong) NSString *backTitle;

// 是否使用自定义导航栏 不使用系统导航栏
@property(nonatomic,assign) BOOL navcBarHidden;
/**
 *
 *  导航条底部线条
 *
 **/
@property (nonatomic,strong) UIView * bottomLine;


// 约束相关
@property(nonatomic,strong)NSLayoutConstraint *topViewEH;
@property(nonatomic,strong) NSLayoutConstraint *titleViewEW;
@property(nonatomic,strong)NSLayoutConstraint *titleViewEH;
@property(nonatomic,strong)NSLayoutConstraint *topViewPL;
@property(nonatomic,strong)NSLayoutConstraint *topViewPR;

@property(nonatomic,strong)NSLayoutConstraint *topContentViewPL;
@property(nonatomic,strong)NSLayoutConstraint *topContentViewPR;
@property(nonatomic,strong)NSLayoutConstraint *topContentViewEH;


-(void)goBack;

-(void)buttonClick:(UIButton *) sender;

// 打开新页面
-(void)autoOpenNewVC:(UIViewController *)controller;
-(void)openNav:(UIViewController *)controller;
-(void)openNav:(UIViewController *)controller sound:(NSString *__nullable)soundName;

-(void)openWithPresent:(UIViewController *)controller;
-(void)openWithPresent:(UIViewController *)controller sound:(NSString *__nullable)soundName animated:(BOOL) anmated;



// key=@(tag) value = @{title,img,imgsel}
@property(nonatomic,strong)NSDictionary *navItemsSource;
// 创建导航头
// 当self.navigationController && !self.navigationController.navigationBarHidden时，会自动调用createCustomTitleView
-(void)createVCTitleView;
/// 仅创建自定义导航栏， 后期不再使用，直接使用createVCTitleView
-(void)createCustomTitleView;


// 仅设置自定义导航，1.0.2之后废弃
-(void)setNavigationBarLeft:(NSArray *__nullable)leftTags right:(NSArray *__nullable)rightTags;


/// 设置导航
/// @param leftTags 左侧按钮
/// @param rightTags 右侧按钮
/// @param autoSetting 是否设置导航颜色
-(void)setNavigationBarLeft:(NSArray *__nullable)leftTags right:(NSArray *__nullable)rightTags setBarStyle:(BOOL) autoSetting;

/// 仅设置左右按钮
/// @param leftTags 左边
/// @param rightTags 右边
-(void)updateBannerLeftTags:(NSArray *__nullable)leftTags rightTags:(NSArray *__nullable)rightTags;


/// 设置顶部导航栏或者自定义View 左右按钮的数据 以及titleView的数据 、title数据
/// @param leftTags 左边按钮的数据
/// @param rightTags 右边按钮的数据
/// @param titleView titleview  自定义view 默认空
-(void)setLeftTags:(NSArray *__nullable)leftTags rightTags:(NSArray *__nullable)rightTags titleView:(UIView * __nullable)titleView ;
-(void)updateBannerLeftTags:(NSArray *__nullable)leftTags rightTags:(NSArray *__nullable)rightTags titleView:(UIView * __nullable)titleView;


/// 设置标题 （系统导航、自定义view）
/// @param title 标题昵称
-(void)setNavTitle:(NSString *) title;

// 设置标题颜色
-(void)setNavTitleColor:(UIColor *)textColor;

/// 设置导航颜色
/// - Parameter color: 导航颜色
-(void)setTopBackgroudColor:(UIColor *) color;
-(void)setTopBackgroudColor:(UIColor *) color titleColor:(UIColor *) titleColor;


// 获取nav上的button
-(UIButton *)getNavButtonWithTag:(NSInteger )tag;

// 获取页面内容的起始坐标
-(CGFloat )getVCContentY;


/// 当显示底部Bar菜单时，返回bar的高度
-(CGFloat) getVCBarHeight;

-(void)createPlaceHolderView:(UIView *) superView title:(NSString *) title desc:(NSString *__nullable )message image:(UIImage *__nullable )  tipImage block:(void(^__nullable)(UIButton *_Nonnull btn,NSInteger tag))  refreshClick;

-(void)createPlaceHolderView:(UIView *) superView title:(NSString *) title desc:(NSString *__nullable )message image:(UIImage *__nullable)  tipImage imgSize:(CGSize)size block:(void(^__nullable)(UIButton *_Nonnull btn,NSInteger tag)) refreshClick;
- (void)removePlaceholderView;

#pragma mark - 阶段一 · 自适应布局接管(opt-in,默认关闭)

/// 启用自适应布局接管(默认 NO,opt-in)
/// 想吃 sizeClass / safeArea 钩子 + Environment 的 VC,在自己的 viewDidLoad super 之后设 YES
@property (nonatomic, assign) BOOL enableAdaptiveLayout;

/// 横屏隐藏系统状态栏偏好(默认 YES,仅当 enableAdaptiveLayout=YES 才生效)
/// 新管道下:isLandscape && sizeClass==Compact 才隐(iPad 横屏不隐)
@property (nonatomic, assign) BOOL landscapeHideStatusBar;

/// sizeClass 变化钩子,子类按需重写
- (void)sobot_sizeClassDidChange:(SobotLayoutSizeClass)newClass;

/// safeArea 变化钩子,子类按需重写
- (void)sobot_safeAreaInsetsDidChange:(UIEdgeInsets)insets;

/// 集中设置实例默认值,所有 init 入口统一调用(init / initWithNibName:bundle: / initWithCoder:)
/// 子类可重写以追加自己的默认值,**必须先调 [super sobot_setupDefaults]**
/// 调用时机:[super init] 内部 — 早于 viewDidLoad,确保 view 生命周期开始前所有默认值已 ready
- (void)sobot_setupDefaults;


#pragma mark - 阶段一 · 内容区布局 helper(可选,推荐用法)

/// 内容区顶部锚点(用于子类页面把内容贴到"导航下方")
///
/// 返回的 anchor 已经自动处理三种场景,横竖屏 / 导航类型 / iOS 版本切换全自驱:
///   1. 自定义导航(self.topView != nil):  返回 self.topView.bottomAnchor
///   2. 系统导航 + iOS 11+:              返回 self.view.safeAreaLayoutGuide.topAnchor
///      (UIKit 自动处理 translucent / 不 translucent,实际位置 = navBar 底)
///   3. 系统导航 + iOS 9/10:             返回 self.topLayoutGuide.bottomAnchor
///      (iOS 7+ API,实际位置 = navBar 底,与 safeAreaLayoutGuide 行为一致)
///
/// 用法:
///   [myView.topAnchor constraintEqualToAnchor:[self sobot_contentTopAnchor] constant:16].active = YES;
- (NSLayoutYAxisAnchor *)sobot_contentTopAnchor;

/// 给一组 view 自动套上「导航避让 + safeArea 避让 + 大屏限宽」约束
///
/// 行为:
///   • 首 view 顶部贴 sobot_contentTopAnchor(导航下方),末 view 底部贴 safeArea.bottom
///   • 数组中所有 view 的左右边贴 safeArea.leading/trailing
///   • 大屏 Regular/Wide 自动限宽并 centerX 居中(maxWidth 由 SobotLayoutAdaptive 决定)
///   • 全部用 NSLayoutAnchor 引用,横竖屏 / 灵动岛 / 刘海切换时 UIKit 自驱响应,无需手动 reload
///   • 内部缓存约束,重复调用会先 deactivate 上次的再生成新的(支持运行时重新布局)
///   • iOS 9/10 兼容(safeAreaLayoutGuide 缺失时 fallback 到 self.view)
///
/// 不负责的事:
///   • 中间 view 之间的相对约束(如 view1.bottom = view2.top + 8),调用方自己加
///   • view 的 width/height 内部尺寸,调用方自己加 size 约束或让内部 intrinsicContentSize 撑开
///
/// 适用场景:简单顶层布局(1~3 个 view 垂直/水平堆叠)。复杂多层嵌套不建议套此 helper。
///
/// @param views   要排列的顶层 view 数组(必须已 addSubview 到 self.view)
/// @param axis    排列方向 — SobotLayoutAxisVertical / SobotLayoutAxisHoritional
/// @param insets  四边外边距 — top 叠加到「导航避让」之上,bottom/left/right 叠加到 safeArea 之上
- (void)sobot_layoutViews:(NSArray<UIView *> *)views
                     axis:(SobotLayoutAxis)axis
                   insets:(UIEdgeInsets)insets;

/// 方式二:自适应内容容器属性(懒加载,首次访问时自动创建,默认 insets = UIEdgeInsetsZero)
///
/// 容器自动完成:
///   • top    贴 sobot_contentTopAnchor(自定义 topView 底 / 系统导航 safeArea.top)
///   • bottom 贴 safeArea.bottom(自动避让 home indicator)
///   • leading/trailing 贴 safeArea(自动避让灵动岛/刘海)
///   • 大屏 Regular/Wide 自动限宽并 centerX 居中
///   • 全部用 NSLayoutAnchor 引用,横竖屏切换 UIKit 自驱响应,无需手动 reload
///
/// 与 sobot_layoutViews 的对比:
///   • sobot_layoutViews — 函数式,接收 view 数组,适合 1~3 个 view 简单堆叠
///   • 本属性           — OOP 容器,业务只需关心容器内布局,完全不用碰 self.view / safeArea / 导航
///
/// 简单用法(默认 insets = Zero):
///   [self.sobotContentContainer addSubview:self.scrollView];
///   [self.sobotContentContainer addSubview:self.btmView];
///   // ... 业务在 container 内部加任意约束,无需关心外部适配
///
/// 自定义 insets:首次访问本属性之前调用 sobot_createContentContainerWithInsets:
///   - (void)viewDidLoad {
///       [super viewDidLoad];
///       [self sobot_createContentContainerWithInsets:UIEdgeInsetsMake(20, 16, 0, 16)];
///       [self.sobotContentContainer addSubview:...];
///   }
@property (nonatomic, strong, readonly, nullable) UIView *sobotContentContainer;

/// sobot_createContentContainer 的配置版,容器与外界保持 insets 外边距。
/// 首次调用会创建容器,后续调用直接返回已创建的(insets 参数忽略)。
/// 创建后可通过 sobotContentContainer 属性访问。
/// @param insets 四边外边距(top 叠加到导航避让之上,bottom/left/right 叠加到 safeArea 之上)
- (UIView *)sobot_createContentContainerWithInsets:(UIEdgeInsets)insets;

@end

NS_ASSUME_NONNULL_END

