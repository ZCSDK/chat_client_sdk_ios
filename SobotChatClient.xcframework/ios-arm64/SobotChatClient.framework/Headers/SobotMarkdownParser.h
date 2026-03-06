//
//  SobotMarkdownParser.h
//  SobotChatClientSDKTest
//
//  Created by zhangxinyao on 2025/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotMarkdownParser : NSObject


/// 把html内容，封装到h5页面中，添加了页面头信息
/// - Parameter html: 存html网页文本
+ (NSString *)addHtmlToWebPage:(NSString *)html;


/// 解析mark内容，并根据img标签拆分
/// - Parameter markdown: markdown文本
+(NSMutableArray *)parseMarkdownBySplitImage:(NSString *)markdown;

// 拆分内容为图片和文本数组
+ (NSMutableArray *)splitContentIntoImagesAndText:(NSString *)content;


/// 把md数据，格式化为html
/// - Parameter markdown: md文本
+ (NSString *)convertMarkdownToHTML:(NSString *)markdown;



@end

NS_ASSUME_NONNULL_END
