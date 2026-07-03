//
//  SobotRotatingCircleView.h
//  SobotKit
//
//  Created by zhangxinyao on 2025/10/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotRotatingCircleView : UIView

// 圆环颜色 (默认蓝色)
@property (nonatomic, strong) UIColor *circleColor;
@property (nonatomic, strong) UIColor *circleTintColor;
// 圆环线宽 (默认3.0)
@property (nonatomic, assign) CGFloat lineWidth;

// 旋转速度 (默认1.0),值越小旋转越快
@property (nonatomic, assign) CGFloat duration;

// 高亮部分形状
@property (nonatomic, assign) CAShapeLayerLineCap lineCap;

// 高亮部分长度(0.4) 值越大高亮部分越长
@property (nonatomic, assign) CGFloat strokeEnd;

// 是否正在动画
@property (nonatomic, readonly) BOOL isAnimating;

// 开始动画
- (void)startAnimating;
// 停止动画
- (void)stopAnimating;

@end

NS_ASSUME_NONNULL_END
