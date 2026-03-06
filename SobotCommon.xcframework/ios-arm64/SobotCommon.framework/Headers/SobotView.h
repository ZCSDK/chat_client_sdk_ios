//
//  SobotView.h
//  SobotOnline
//
//  Created by zhangxy on 2020/8/7.
//  Copyright © 2020 sobot. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotView : UIView

@property(nonatomic,strong) NSString *borderColorName;
@property(nonatomic,strong) NSString *bundleName;


@property(nonatomic,strong) id objTag;


// 如果返回UIColor，会自动赋值给self.layer.borderColor,返回空不处理
// sView为控件本身
@property (nonatomic, copy, nullable) UIColor *(^traitCollectionChangedBlock)(UITraitCollection *previousTraitCollection,UIView *sView); // 点击事件Block

@end

NS_ASSUME_NONNULL_END
