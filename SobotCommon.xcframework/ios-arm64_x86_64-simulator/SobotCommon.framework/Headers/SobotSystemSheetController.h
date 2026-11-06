#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 全宽 Sheet 公共容器。子类只需在 buildSheetContent / buildSheetFooter 中布置业务视图。
/// 基于 UIKit 自定义呈现控制器，背景铺满当前窗口；高度、旋转、窗口切换由基类处理。
@interface SobotSystemSheetController : UIViewController

@property (nonatomic, copy) NSString *sheetTitle;
@property (nonatomic) BOOL showsCloseButton;
@property (nonatomic) BOOL showsHeaderDivider;
@property (nonatomic) BOOL showsFooter;
@property (nonatomic) BOOL isRTL;
@property (nonatomic, strong) UIColor *sheetBackgroundColor;
@property (nonatomic, strong) UIColor *footerBackgroundColor;
@property (nonatomic, strong) UIColor *dividerColor;
/// 子类内容希望占用的高度。基类会按当前窗口可用高度裁剪，内容应自行支持滚动。
@property (nonatomic) CGFloat preferredBodyHeight;
@property (nonatomic, copy, nullable) void (^didDismiss)(void);

@property (nonatomic, strong, readonly) UIView *sheetContentView;
@property (nonatomic, strong, readonly) UIView *sheetFooterView;
/// 标题、内容、底部按钮共用的横向交互安全边界；背景始终覆盖整个 Sheet。
@property (nonatomic, strong, readonly) UILayoutGuide *sheetForegroundGuide;

- (void)buildSheetContent;
- (void)buildSheetFooter;
/// 入窗后及窗口尺寸、安全区、尺寸类别变化且 Auto Layout 完成时调用。
/// 子类只在业务内容确需变更列数、资源等布局规则时重写；无需手工改外层 frame。
- (void)sheetEnvironmentDidChange;
- (void)invalidateSheetLayout;
- (void)presentFromViewController:(UIViewController *)presenter animated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;
- (void)closeSheetAnimated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
