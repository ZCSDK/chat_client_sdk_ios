//
//  ZCTitleView.h
//  SobotKit
//
//  Created by lizh on 2022/9/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZCTitleView : UIView


/**
 设置聊天页面顶部标题
 @param nickTitle 客服昵称
 @param imageUrl 图片地址(支持本地和网络地址) 企业的logo URL 或者 客服和机器人的头像
 @param companyTitle 企业名称
 */
-(void)setNickTitle:(NSString *)nickTitle companyTitle:(NSString*)companyTitle title:(NSString *)title image:(NSString *)imageUrl topBarType:(int)topBarType firstLetter:(NSString *)firstLetter statusStr:(NSString *)statusStr isShowFirst:(BOOL)isShowFirst;

// 刷新UI是否是横屏
-(void)setlayout:(BOOL)landspace;

/// 系统导航栏会按 titleView 的固有宽度决定是否居中；折叠屏尺寸变化前先更新透明占位宽度。
/// 自定义导航由外层约束决定宽度，调用本方法不会改变其布局。
-(void)prepareForNavigationContainerWidth:(CGFloat)width;

-(void)setLogoImgLayrightItem:(NSArray*)rightItem leftItem:(NSArray *)leftItem;

// 设置文字颜色是否是黑或者白色
-(void)setisBlackColorIcon:(BOOL)isBlack;
@end


NS_ASSUME_NONNULL_END
