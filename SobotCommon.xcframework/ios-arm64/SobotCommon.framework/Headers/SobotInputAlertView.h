//
//  SobotInputAlertView.h
//  SobotUI
//
//  通用文本输入弹框：标题 + 消息 + 文本输入区（带字数限制）+ 取消/其它按钮
//  与 SobotAlertView 同目录、同 API 风格；多 placeholder / maxLength 两个入参。
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SobotInputAlertView;

@protocol SobotInputAlertViewDelegate <NSObject>

- (void)sobotInputAlertView:(SobotInputAlertView *)alertView
       clickedButtonAtIndex:(NSInteger)buttonIndex
                       text:(NSString *)text;

@end

@interface SobotInputAlertView : UIView

/**
 *  @param title              标题
 *  @param message            副文（可空）
 *  @param placeholder        输入框 placeholder（可空）
 *  @param maxLength          字数上限；0 表示不限制
 *  @param cancelButtonTitle  取消按钮文案（可空）
 *  @param otherTitles        其它按钮文案，nil 结尾
 */
- (nullable instancetype)initWithTitle:(nullable NSString *)title
                                message:(nullable NSString *)message
                            placeholder:(nullable NSString *)placeholder
                              maxLength:(NSUInteger)maxLength
                      cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                      otherButtonTitles:(nullable NSString *)otherTitles, ... NS_REQUIRES_NIL_TERMINATION;

/**
 *  显示弹框，按钮点击回调 (view, selectIndex, text)
 */
- (void)showWithCompletion:(void (^ _Nullable)(SobotInputAlertView * _Nullable alertView,
                                                NSInteger selectIndex,
                                                NSString *text))completion;

/**
 *  代理形式（与 block 二选一）
 */
- (void)show;
- (void)dismissView;

@property (nullable, nonatomic, weak) id<SobotInputAlertViewDelegate> delegate;

@property (nonatomic, strong) id objTag;
@property (nonatomic, assign) BOOL isAutoClose;     // 默认 YES

/// 主题配色（与 SobotAlertView 一致开放）
@property (nullable, nonatomic, strong) UIColor *bgColor;
@property (nullable, nonatomic, strong) UIColor *contentColor;
@property (nullable, nonatomic, strong) UIColor *titleColor;
@property (nullable, nonatomic, strong) UIColor *messageColor;
@property (nullable, nonatomic, strong) UIColor *btnColor;
@property (nullable, nonatomic, strong) UIColor *btnCancelColor;

@end

NS_ASSUME_NONNULL_END
