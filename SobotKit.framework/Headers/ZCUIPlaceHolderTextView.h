//
//  UIPlaceHolderTextView.h
//  Tutu
//
//  Created by zhangxinyao on 14-11-21.
//  Copyright (c) 2014年 zxy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <SobotCommon/SobotCommon.h>

/**
 *  <#Description#>
 */
@interface ZCUIPlaceHolderTextView : UITextView {
    
}


@property (nonatomic,strong)SobotEmojiLabel *placeHolderLabel;
@property(nonatomic, strong) NSLayoutConstraint  *layoutPlaceTop;


/**
 *  占位文字的字体大小
 */
@property (nonatomic,strong) UIFont *placeholederFont;

@property(nonatomic, assign) NSInteger maxPlaceHolderLines;
/**
 *  占位文字
 */
@property(nonatomic, strong) NSString  *placeholder;
/**
 *  占位页面link颜色
 */
@property(nonatomic, strong) UIColor *placeholderLinkColor;
/**
 *  占位页面背景颜色
 */
@property(nonatomic, strong) UIColor *placeholderColor;

@property(nonatomic, assign) CGFloat placeHolderH;


/**
 *  <#Description#>
 *
 *  @param notification 通知
 */
-(void)textChanged:(NSNotification*)notification;

/**
 *  设置行间距
 */
@property (nonatomic,assign) int LineSpacing;

@property (nonatomic,assign) int type; // 1.占位文字要设置 文字颜色

@property (nonatomic,assign) BOOL isAddLink;//不设置超链
//起始间距
@property (nonatomic,assign) CGFloat sx;
@end
