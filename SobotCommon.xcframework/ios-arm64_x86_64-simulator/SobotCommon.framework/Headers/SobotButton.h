//
//  SobotButton.h
//  SobotOnline
//
//  Created by zhangxy on 2020/8/7.
//  Copyright © 2020 sobot. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotButton : UIButton

// 如果需要自动折行，设置YES
@property(nonatomic,assign) BOOL autoHeight;

// 按下的alpha的值
@property(nonatomic,assign) CGFloat pressAlpha;

// 由于内部判断暗黑准确，需要外部指定
@property(nonatomic,strong) UIColor *pressHoverColor;
// 设置为YES的时候，添加按下和抬起事件
@property(nonatomic,assign) BOOL openHoverStyle;
// 切换圆角度数
@property(nonatomic,assign) CGFloat  pressRadius;
// 切换圆角的枚举值 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
@property(nonatomic,assign) UIRectCorner pressHoverCorners;

// 扩展参数
@property(nonatomic,strong) id obj;

// normal状态图片名称
@property(nonatomic,strong) NSString *imageName;

// 选中状态图片名称
@property(nonatomic,strong) NSString *imageNameHighlighted;

// 边框颜色key
@property(nonatomic,strong) NSString *borderColorName;

@property(nonatomic,strong) NSString *bundleName;
// 父类的View
@property(nonatomic,strong) UIView *supViewObj;

// 如果返回UIColor，会自动赋值给self.layer.borderColor,返回空不处理
// sView为控件本身
@property (nonatomic, copy, nullable) UIColor *(^traitCollectionChangedBlock)(UITraitCollection *previousTraitCollection,UIView *sView); // 点击事件Block

-(void) addTapHandle:(void(^)(SobotButton *btnObj)) clickBlock;



-(void) onHoverTouchDown:(void(^)(UIView *hoverView)) touchDown;



// 按钮按下和抬起事件
- (void)buttonHoverTouchDown:(SobotButton *)button;
- (void)buttonHoverTouchUp:(SobotButton *)button;


@end

NS_ASSUME_NONNULL_END
