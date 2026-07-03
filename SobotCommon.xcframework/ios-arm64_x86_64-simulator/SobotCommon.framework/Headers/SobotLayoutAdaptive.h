//
//  SobotLayoutAdaptive.h
//  SobotUI
//
//  阶段一 · 横屏 / 大屏自适应 — 无状态工具类
//  包含 sizeClass 枚举 + 换算函数 + 各档位 metrics 纯函数。
//  所有方法均为类方法,不持有任何状态。
//
//  与同目录下的 SobotLayoutTools(NSLayoutConstraint 约束 helper)是两个正交业务:
//   - SobotLayoutTools    : 怎么布约束(anchor / padding / margin)
//   - SobotLayoutAdaptive : 不同尺寸档位用什么值(sizeClass / metrics)
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 布局尺寸档位
/// - Compact: iPhone 全形态 + 高度紧凑设备(window 短边 < 500)
/// - Regular: 600 <= width < 1024 (iPad 竖屏 / Split View 半屏 / 小型 Pad)
/// - Wide:    width >= 1024 (iPad 横屏 / iPad Pro)
typedef NS_ENUM(NSInteger, SobotLayoutSizeClass) {
    SobotLayoutSizeClassCompact = 0,
    SobotLayoutSizeClassRegular,
    SobotLayoutSizeClassWide
};

@interface SobotLayoutAdaptive : NSObject

#pragma mark - sizeClass 换算

/// 根据 window 尺寸(注意不是屏宽)计算 sizeClass
+ (SobotLayoutSizeClass)sizeClassFromSize:(CGSize)windowSize;

/// 枚举的字符串描述,用于日志
+ (NSString *)descriptionForSizeClass:(SobotLayoutSizeClass)c;

#pragma mark - 键盘相关(PR3 使用)

/// 计算键盘弹出后内容区底部应避让的高度
/// @param kbEndFrame 键盘最终 frame(来自 UIKeyboardFrameEndUserInfoKey,window 坐标)
/// @param view       参考 view(通常是 chatView 的 _ppView 或 superview)
/// @return 避让高度(0 表示键盘未与 view 相交)
+ (CGFloat)keyboardAvoidingBottomInsetForFrame:(CGRect)kbEndFrame
                                        inView:(UIView *)view;

/// 输入框底部「额外间距」(替代硬编码的 +10 / +16)
+ (CGFloat)chatBottomExtraForSizeClass:(SobotLayoutSizeClass)c;

#pragma mark - 安全区 / 状态栏(PR2 使用)

/// 横屏隐藏状态栏时,顶部应保留的最小避让高度(参考值)
+ (CGFloat)minTopInsetForSizeClass:(SobotLayoutSizeClass)c
                 isStatusBarHidden:(BOOL)hidden;

#pragma mark - 容器(PR4 / 二期使用)

/// 页面内容最大宽度(Compact 返回 CGFLOAT_MAX 表示不限宽)
+ (CGFloat)contentMaxWidthForSizeClass:(SobotLayoutSizeClass)c;

/// 页面左右 margin
+ (CGFloat)pageHorizontalMarginForSizeClass:(SobotLayoutSizeClass)c;

@end

NS_ASSUME_NONNULL_END
