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


/// 拆分 Markdown 文本、图片和回答中的 HTML 媒体块。
/// 视频识别完整的 <video>...</video> 或内含该标签的 <div data-video>...</div>，不会把裸视频 URL 提升为视频卡片；附件需符合既有 HTML 附件格式。
/// - Parameter markdown: markdown文本
+(NSMutableArray *)parseMarkdownBySplitImage:(NSString *)markdown;

// 拆分内容为图片和文本数组
+ (NSMutableArray *)splitContentIntoImagesAndText:(NSString *)content;


/// 把md数据，格式化为html（流式版本）
/// 与 convertMarkdownToHTML 的区别：
/// - 完整表格行（以|开头且以|结尾）正常生成 <tr>，并强制闭合 </table>，可立即渲染
/// - 未完成行（以|开头但不以|结尾）先闭合已有表格，再作为纯文本追加，不破坏 HTML 结构
/// - Parameter markdown: md文本（流式接收中的不完整内容）
+ (NSString *)convertMarkdownToHTMLForStreaming:(NSString *)markdown;



/// 把md数据，格式化为html（流式版本）
/// - Parameter markdown: md文本（流式接收中的不完整内容）
+ (NSString *)convertMarkdownToHTML:(NSString *)markdown;

@end

NS_ASSUME_NONNULL_END
