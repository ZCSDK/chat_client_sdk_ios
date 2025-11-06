//
//  SobotKxActionMenu.h
//  SobotCommon
//
//  Created by zhangxinyao on 2025/9/23.
//

#import <UIKit/UIKit.h>
#import <SobotCommon/SobotMenuItem.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SobotKxActionMenuDelegate <NSObject>

-(void) onActionMenuItem:(SobotMenuItem *) item;

@end

@interface SobotKxActionMenu : UIView

/**
 *  代理
 */
@property (nonatomic, weak  ) id <SobotKxActionMenuDelegate> delegate;
@property (nonatomic, assign) int                       selectIndex;


/**
 *  创建对象方法
 */
- (instancetype)initWithDelegate:(id<SobotKxActionMenuDelegate> _Nullable)delegate arr:(NSArray *) array;

- (void) setActionClickBlock:(void (^)(SobotMenuItem *item)) ItemClickblock;

-(void)show:(UIView *)sender;

- (void)dissmisMenu;

- (BOOL) isShowing;

@end

NS_ASSUME_NONNULL_END
