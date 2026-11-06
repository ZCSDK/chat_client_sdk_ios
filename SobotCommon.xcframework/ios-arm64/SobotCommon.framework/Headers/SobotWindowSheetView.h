#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 加到触发页面所属 window 的 View Sheet。背景铺满 window，交互内容避开安全区。
/// 子类只需在 buildSheetContent / buildSheetFooter 中布置业务内容。
@interface SobotWindowSheetView : UIView

@property (nonatomic, copy) NSString *sheetTitle;
@property (nonatomic) BOOL showsCloseButton;
@property (nonatomic) BOOL showsHeaderDivider;
@property (nonatomic) BOOL showsFooter;
@property (nonatomic) BOOL isRTL;
@property (nonatomic, strong) UIColor *sheetBackgroundColor;
@property (nonatomic, strong) UIColor *footerBackgroundColor;
@property (nonatomic, strong) UIColor *dividerColor;
@property (nonatomic) CGFloat preferredBodyHeight;
@property (nonatomic, copy, nullable) void (^didDismiss)(void);

@property (nonatomic, strong, readonly) UIView *sheetContentView;
@property (nonatomic, strong, readonly) UIView *sheetFooterView;
@property (nonatomic, strong, readonly) UILayoutGuide *sheetForegroundGuide;

- (void)buildSheetContent;
- (void)buildSheetFooter;
/// 在窗口尺寸、安全区域或尺寸类别发生变化且布局完成后调用。
- (void)sheetEnvironmentDidChange;
- (void)invalidateSheetLayout;

/// 从已入窗的视图找到正确 scene 的 window；未入窗时返回 NO。
- (BOOL)showFromView:(UIView *)sourceView animated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;
- (BOOL)showInWindow:(UIWindow *)window animated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;
- (void)dismissAnimated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
