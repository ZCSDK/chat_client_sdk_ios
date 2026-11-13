#ifndef SOBOT_HTML_RENDERER_H
#define SOBOT_HTML_RENDERER_H
#import "SobotHTMLParser.h"
NS_ASSUME_NONNULL_BEGIN
/// SDK 适配入口；核心 parser 不知道聊天主题色、style 注入等业务约定。
@interface SobotHTMLRenderer : NSObject
/// 模型入口，保留 SDK 字号及正文/链接颜色占位符。
+ (NSMutableAttributedString *)renderHTML:(NSString *)html;
/// 独立 Label 入口，使用真实字体和文字色。
+ (NSMutableAttributedString *)renderHTML:(NSString *)html font:(UIFont *)font color:(UIColor *)color;
@end
NS_ASSUME_NONNULL_END
#endif
