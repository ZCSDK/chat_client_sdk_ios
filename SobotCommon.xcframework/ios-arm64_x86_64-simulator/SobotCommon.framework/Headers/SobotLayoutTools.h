//
//  SobotLayoutTools.h
//  SobotOrderSDK
//
//  Created by zhangxy on 2022/3/21.
//
//  ========================================================
//  使用说明 (2026-05 评估)
//  ========================================================
//  本文件大部分老 API(sobotLayoutPaddingXxx / sobotLayoutMarginXxx 等)存在以下问题:
//    1. 双套 API 同名不同行为:sobotLayoutPaddingRight 与 sobotLayoutRight constant 符号相反
//    2. sobotLayoutPaddingLeft/Right 用物理 Left/Right,不响应 RTL(阿语场景翻车)
//    3. 不支持 GTE/LTE/multiplier/priority/safeAreaLayoutGuide,复杂场景必须降级到原生
//    4. sobotLayoutPaddingView 等的 `if (value != 0)` 静默跳过 0 值的逻辑容易踩坑
//    5. 命名误导:sobotLayoutLeft 内部用 leadingAnchor,sobotLayoutTop 是同侧对齐不是堆叠
//
//  新代码推荐方案:
//    A. 高频场景 (pin 四边 / 设 size / 居中) → 用本文件底部 4 个新 helper
//       (统一加 Anchor 前缀,与老函数区分,标识内部用 NSLayoutAnchor API):
//       - sobotLayoutAnchorPinEdges          撑满到容器(支持 UIEdgeInsets)
//       - sobotLayoutAnchorPinSafeAreaEdges  撑满到容器 safeAreaLayoutGuide
//       - sobotLayoutAnchorSetSize           设 width + height
//       - sobotLayoutAnchorCenterIn          centerX + centerY 居中
//    B. 其他场景 → 直接用 iOS 9+ 原生 anchor API,无须再封装:
//       [view.leadingAnchor constraintEqualToAnchor:other.leadingAnchor constant:16].active = YES;
//       [view.widthAnchor   constraintLessThanOrEqualToConstant:200].active = YES;
//
//  老 API 不删、不打 deprecated (现有调用上千处),保留作为"使用的例子备份"。
//  ========================================================
//
//  ========================================================
//  老 API 正负方向对照表 (踩坑必看)
//  ========================================================
//
//  贴边 (view 相对 sup 内缩 16pt):
//  +-------------+-----------------------------------+-----------------------+-------------------------------------+
//  | 意图        | A 组 (PaddingXxx)                 | B 组 (LayoutXxx)      | 原生 anchor 等价                    |
//  +-------------+-----------------------------------+-----------------------+-------------------------------------+
//  | 距 sup 左 16 | sobotLayoutPaddingLeft( 16 )      | sobotLayoutLeft( 16 ) | view.leading  = sup.leading  + 16   |
//  | 距 sup 右 16 | sobotLayoutPaddingRight( -16 ) ⚠️ | sobotLayoutRight( 16 )| view.trailing = sup.trailing - 16   |
//  | 距 sup 顶 16 | sobotLayoutPaddingTop( 16 )       | sobotLayoutTop( 16 )  | view.top      = sup.top      + 16   |
//  | 距 sup 底 16 | sobotLayoutPaddingBottom( -16 ) ⚠️| sobotLayoutBottom( 16 )| view.bottom  = sup.bottom   - 16   |
//  +-------------+-----------------------------------+-----------------------+-------------------------------------+
//
//  兄弟堆叠 (view 与 other 间距 8pt):
//  +---------------------+--------------------------------+-----------------------------+-----------------------------------+
//  | 意图                | A 组 (MarginXxx)               | B 组 (XxxMargin)            | 原生 anchor 等价                  |
//  +---------------------+--------------------------------+-----------------------------+-----------------------------------+
//  | view 在 other 右 8  | sobotLayoutMarginLeft( 8 )     | sobotLayoutLeftMargin( 8 )  | view.leading  = other.trailing + 8|
//  | view 在 other 左 8  | sobotLayoutMarginRight( -8 )⚠️| sobotLayoutRightMargin( 8 ) | view.trailing = other.leading  - 8|
//  | view 在 other 下 8  | sobotLayoutMarginTop( 8 )      | sobotLayoutTopMargin( 8 )   | view.top      = other.bottom   + 8|
//  | view 在 other 上 8  | sobotLayoutMarginBottom( -8 )⚠️| sobotLayoutBottomMargin( 8 )| view.bottom   = other.top      - 8|
//  +---------------------+--------------------------------+-----------------------------+-----------------------------------+
//
//  ⚠️ 高亮提醒:
//    · B 组 8 个函数 全部统一为 "调用方传正数 = 距离"。
//      sobotLayoutRight / Bottom / RightMargin / BottomMargin 内部已做 `-constant` 翻转,
//      sobotLayoutLeft / Top / LeftMargin / TopMargin 不翻转(语义本来就是正数)。
//
//    · A 组 (PaddingXxx / MarginXxx) 仍是 NSLayoutConstraint 原生 constant 方向:
//      Left / Top 正数,Right / Bottom 负数。与 B 组的 "贴右/底" 和 "上/左方向堆叠" 符号相反。
//
//    · 不确定时,优先用 原生 anchor (上表最右列写法),正负永远遵循 NSLayoutConstraint 数学约定
//  ========================================================

#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>

NS_ASSUME_NONNULL_BEGIN

//第一个参数 view1: 要设置的视图；
//第二个参数 attr1: view1要设置的属性，稍后详解；
//第三个参数 relation: 视图view1和view2的指定属性之间的关系，稍后详解；
//第四个参数 view2: 参照的视图；
//第五个参数 attr2: 参照视图view2的属性，稍后详解；
//第六个参数 multiplier: 视图view1的指定属性是参照视图view2制定属性的多少倍；
//第七个参数 c: 视图view1的指定属性需要加的浮点数。
//根据参数的讲解，得出计算公式如下：
//view1.attr1 [=GreaterThan , >= , <=LessThan] view2.attr2 * multiplier + c;
// Leading 首部
// Trailing 尾部
// Baseline 文本底部标线
// right/bottom/Trailing
@interface SobotLayoutTools : NSObject

/// 设置位置、宽高属性、x、y坐标
/// @param value 具体的值
/// @param view 当前要设置的view
/// @param otherView 相对的view，如果是宽、高，可以为空
/// @param attribute 当前的属性
/// @param otherAttribute 对方属性
/// @param relation  关系：大于、小于、等于
NSLayoutConstraint *sobotLayoutRelationAttribute(float value,UIView *view,UIView * _Nullable otherView,NSLayoutAttribute attribute,NSLayoutAttribute otherAttribute,NSLayoutRelation relation);


/// 设置View的宽，高
/// @param width 宽
/// @param height 高
/// @param view 要设置的View
/// @param relation 关系：>=、<=、=
NSArray *sobotLayoutSize(float width,float height,UIView *view,NSLayoutRelation relation);
NSLayoutConstraint *sobotLayoutEqualWidth(float width,UIView *view,NSLayoutRelation relation);
NSLayoutConstraint *sobotLayoutEqualHeight(float height,UIView *view,NSLayoutRelation relation);

/// 和父类等宽，width是0，否则是相对于父类左右的间隔
/// @param width 间隔，默认左右相等
/// @param view 自己
/// @param superView 所在的父类
NSArray *sobotLayoutEqualWidthView(float width,UIView *view,UIView *superView);

/// 控件上、下、左、右的距离
/// @param top 上
/// @param bottom 下,注意需要是负数，例如-50
/// @param left 坐
/// @param right 右,注意需要是负数，例如-50
/// @param view 当前布局的控件
/// @param superView 当前相对控件，注意sub和sup的区别,super的时候是负数，其它情况正常
NSArray *sobotLayoutPaddingView(float top,float bottom,float left,float right,UIView *view,UIView *superView);
NSArray *sobotLayoutPaddingWithAll(float top,float bottom,float left,float right,UIView *view,UIView *superView);
NSArray *sobotLayoutMarginView(float top,float bottom,float left,float right,UIView *view,UIView *otherView);
NSArray *sobotLayoutMarginWithAll(float top,float bottom,float left,float right,UIView *view,UIView *otherView);



/// 注意right和bottom要设置负数
/// @param top 距离，0也添加
/// @param view 自己
/// @param superView 相对父类
NSLayoutConstraint *sobotLayoutPaddingTop(float top,UIView *view,UIView *superView);
NSLayoutConstraint *sobotLayoutPaddingBottom(float bottom,UIView *view,UIView *superView);
NSLayoutConstraint *sobotLayoutPaddingLeft(float left,UIView *view,UIView *superView);
NSLayoutConstraint *sobotLayoutPaddingRight(float right,UIView *view,UIView *superView);

/// 注意right和bottom要设置负数
/// @param top 距离，0也添加
/// @param view 自己
/// @param otherView 相对同级别
NSLayoutConstraint *sobotLayoutMarginTop(float top,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutMarginBottom(float bottom,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutMarginLeft(float left,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutMarginRight(float right,UIView *view,UIView *otherView);


/// 水平相同布局,平均所有控件，即childViews.width=view
/// @param space 各个控件中的间隔
/// @param view 第一个控件
/// @param childViews 所有子控件，不包含第一个
NSArray *sobotLayoutEqualWidthSubView(float space,UIView *view,NSArray *childViews);



/// 中心点对齐
/// @param centerX x坐标 centerY y坐标
/// @param view 当前view
/// @param otherView 相对view，注意此处是同级view
NSLayoutConstraint *sobotLayoutEqualCenterX(CGFloat centerX,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutEqualCenterY(CGFloat centerY,UIView *view,UIView *otherView);


/// 水平、垂直布局
/// @param space 间隔
/// @param view 第一个view，childViews中不要包含第一个
/// @param childViews 所有需要布局的view，不要包含第一个
NSArray *sobotLayoutHorizontalSpaces(float space,UIView *view,NSArray *childViews);
NSArray *sobotLayoutVerticalSpace(float space,UIView *view,NSArray *childViews);



/// 修改约束，其实就是重新设置，后面设置的会覆盖之前的设置
/// @param view 当前view
/// @param topView 相对view
/// @param constant 新的约束值
NSLayoutConstraint *sobotLayoutUpdateVerticalDistanceTop(UIView *view,UIView *topView,float constant);
NSLayoutConstraint *sobotLayoutUpdateVerticalDistanceBottom(UIView *view,UIView *bottomView,float constant);
NSLayoutConstraint *sobotLayoutUpdateViewHeight(UIView *view,float constant);
NSLayoutConstraint *sobotLayoutUpdateViewWidth(UIView *view,float constant);

// Anchor方式设置同向的约束
NSLayoutConstraint *sobotLayoutLeft(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutRight(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutTop(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutBottom(CGFloat constant,UIView *view,UIView *otherView);

// Anchor方式设置相邻的间隔约束
NSLayoutConstraint *sobotLayoutLeftMargin(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutRightMargin(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutTopMargin(CGFloat constant,UIView *view,UIView *otherView);
NSLayoutConstraint *sobotLayoutBottomMargin(CGFloat constant,UIView *view,UIView *otherView);


#pragma mark - 推荐使用的高频 helper (4 个,内部用 NSLayoutAnchor API + 已 activate)

/// 把 view 撑满到 container 的四边,可加内边距。leading/trailing 自动响应 RTL。
/// 返回的约束已 activate,不需要再 addConstraint。
/// @param view      要约束的子 view
/// @param container 容器,通常是父 view
/// @param insets    四边内边距,贴齐传 UIEdgeInsetsZero
NSArray<NSLayoutConstraint *> *sobotLayoutAnchorPinEdges(UIView *view, UIView *container, UIEdgeInsets insets);

/// 把 view 撑满到 container 的 safeAreaLayoutGuide 四边(自动避让灵动岛/刘海/home indicator)。
/// iOS 9 / 10 没有 safeAreaLayoutGuide,自动 fallback 到 sobotLayoutAnchorPinEdges(直接贴 container 四边)。
/// 已 activate。
NSArray<NSLayoutConstraint *> *sobotLayoutAnchorPinSafeAreaEdges(UIView *view, UIView *container, UIEdgeInsets insets);

/// 设置 view 的 width + height(等于约束)。已 activate。
/// width 或 height 传 0 也会加约束(不像老的 sobotLayoutSize 会静默跳过)。
NSArray<NSLayoutConstraint *> *sobotLayoutAnchorSetSize(UIView *view, CGSize size);

/// view 在 container 内 centerX + centerY 居中。已 activate。
NSArray<NSLayoutConstraint *> *sobotLayoutAnchorCenterIn(UIView *view, UIView *container);

@end

NS_ASSUME_NONNULL_END
