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


@end

NS_ASSUME_NONNULL_END
