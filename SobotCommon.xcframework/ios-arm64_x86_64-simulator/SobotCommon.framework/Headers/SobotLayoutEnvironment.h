//
//  SobotLayoutEnvironment.h
//  SobotUI
//
//  全局 Layout 环境单例,持有当前 sizeClass / safeArea / keyboard 状态。
//  由 SobotClientBaseController 在 viewWillTransitionToSize: / traitCollectionDidChange:
//  / viewSafeAreaInsetsDidChange 中主动调用 update 方法,
//  本类不主动监听任何系统通知,避免重复广播。
//

#import <UIKit/UIKit.h>
#import <SobotCommon/SobotLayoutAdaptive.h>

NS_ASSUME_NONNULL_BEGIN

/// sizeClass 变化广播
FOUNDATION_EXPORT NSNotificationName const SobotLayoutSizeClassDidChangeNotification;

/// userInfo 键
FOUNDATION_EXPORT NSString * const SobotLayoutNotificationKeyNewSizeClass;     // NSNumber
FOUNDATION_EXPORT NSString * const SobotLayoutNotificationKeyOldSizeClass;     // NSNumber
FOUNDATION_EXPORT NSString * const SobotLayoutNotificationKeyWindowSize;       // NSValue(CGSize)
FOUNDATION_EXPORT NSString * const SobotLayoutNotificationKeySafeAreaInsets;   // NSValue(UIEdgeInsets)

@interface SobotLayoutEnvironment : NSObject

+ (instancetype)sharedEnv;

@property (nonatomic, assign, readonly) SobotLayoutSizeClass sizeClass;
@property (nonatomic, assign, readonly) CGSize windowSize;
@property (nonatomic, assign, readonly) UIEdgeInsets safeAreaInsets;
@property (nonatomic, assign, readonly) CGFloat keyboardHeight;

/// 是否横屏(基于 windowSize 宽 > 高)
@property (nonatomic, assign, readonly) BOOL isLandscape;

/// 是否高度紧凑(window 高 < 500,典型为 iPhone 横屏)
@property (nonatomic, assign, readonly) BOOL isHeightCompact;

#pragma mark - update 接口(由基类调用,业务侧无需主动调)

- (void)updateForWindowSize:(CGSize)size;
- (void)updateForViewController:(UIViewController *)vc;
- (void)updateSafeAreaInsets:(UIEdgeInsets)insets;
- (void)updateKeyboardHeight:(CGFloat)h;

@end

NS_ASSUME_NONNULL_END
