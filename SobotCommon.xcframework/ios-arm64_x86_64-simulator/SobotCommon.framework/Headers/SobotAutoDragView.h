//
//  SobotAutoDragView.h
//  SobotCommon
//
//  Created by zhangxy on 2025/1/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/**
 拖拽方式
 - DraggingTypeDisabled :不能拖拽
 - DraggingTypeNormal: 正常拖拽
 - DraggingTypeRevert: 释放后还原
 - DraggingTypePullOver: 自动靠边,只会靠左右两边
 - DraggingTypeAdsorb: 靠边时自动吸附边缘，可吸附四周
 - DraggingTypePullOverLeft: 自动靠左边
 - DraggingTypePullOverRight: 自动靠右边
 */
typedef NS_ENUM(NSUInteger, SobotDraggingType) {
    SobotDraggingTypeDisabled,
    SobotDraggingTypeNormal,
    SobotDraggingTypeRevert,
    SobotDraggingTypePullOver,
    SobotDraggingTypeAdsorb,
    SobotDraggingTypePullOverLeft,
    SobotDraggingTypePullOverRight,
};
@interface SobotAutoDragView : UIView

// 最小顶部空隙
@property(nonatomic,assign) CGFloat topSpace;

// 底部空隙
@property(nonatomic,assign) CGFloat bottomSpace;


// 右边空隙
@property(nonatomic,assign) CGFloat rightSpace;


// 左边空隙
@property(nonatomic,assign) CGFloat leftSpace;


/**
 默认：SobotDraggingTypeNormal
 */
@property(nonatomic,assign) SobotDraggingType draggingType;

// 是否使用停止动画
@property(nonatomic,assign) BOOL isShakeAnimation;

@property (strong, nonatomic) void(^TapClickBlock)(SobotAutoDragView *view);

// 如果返回UIColor，会自动赋值给self.layer.borderColor,返回空不处理
// sView为控件本身
@property (nonatomic, copy, nullable) UIColor *(^traitCollectionChangedBlock)(UITraitCollection *previousTraitCollection,UIView *sView); // 点击事件Block

/// 横向位置约束(可选,Auto Layout 模式下注入)
/// 不设置 → 走 frame 模式(直接改 self.center.x);
/// 设置 → 拖拽时把 center.x 的变化量累加到 constant 上(适用于 left/right/leading/trailing,无 multiplier)
@property (nonatomic, weak, nullable) NSLayoutConstraint *horizontalConstraint;

/// 纵向位置约束(可选,Auto Layout 模式下注入,语义同 horizontalConstraint)
@property (nonatomic, weak, nullable) NSLayoutConstraint *verticalConstraint;

-(void)updateMaxSize;

@end

NS_ASSUME_NONNULL_END
