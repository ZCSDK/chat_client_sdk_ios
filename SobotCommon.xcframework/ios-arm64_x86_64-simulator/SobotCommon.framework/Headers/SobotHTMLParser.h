// Objective-C port of the ZMarkupParser core. See SobotHTMLParser-NOTICE.txt.
#ifndef SOBOT_HTML_PARSER_H
#define SOBOT_HTML_PARSER_H
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

/// 样式优先级；对应原库的 code / HTML style 两种策略。
typedef NS_ENUM(NSUInteger, SobotHTMLStylePolicy) {
    SobotHTMLStylePolicyPreferHTML,
    SobotHTMLStylePolicyPreferCode
};

/// 图片节点的同步附件工厂。此回调在解析线程执行，不应访问视图或同步下载。
typedef NSTextAttachment * _Nullable (^SobotHTMLAttachmentProvider)(NSURL *URL, NSDictionary<NSString *, NSString *> *attributes);

/// 每个解析器持有选项快照；创建后调用方修改原选项不会改变正在进行的解析。
@interface SobotHTMLParserOptions : NSObject <NSCopying>
/// 根字体；默认与原库一致为 12pt。
@property(nonatomic,strong) UIFont *font;
/// 根文字色；nil 表示不附加显式颜色。
@property(nonatomic,strong,nullable) UIColor *textColor;
/// 链接自定义色；nil 使用原库蓝色和下划线默认样式。
@property(nonatomic,strong,nullable) UIColor *linkColor;
/// 默认 YES，对齐原库先解码实体再扫描的行为；可关闭以处理已经解码的数据。
@property(nonatomic,assign) BOOL decodeEntities;
/// 默认 YES，沿用原库 UIFontMetrics 字体缩放。
@property(nonatomic,assign) BOOL scalesFonts;
/// 默认优先使用 HTML 行内样式。
@property(nonatomic,assign) SobotHTMLStylePolicy stylePolicy;
/// 按标签名称配置的文字属性，键使用 NSAttributedStringKey。
@property(nonatomic,copy) NSDictionary<NSString *, NSDictionary<NSAttributedStringKey,id> *> *tagStyles;
/// 按 class 名称配置样式；无需实现浏览器样式表。
@property(nonatomic,copy) NSDictionary<NSString *, NSDictionary<NSAttributedStringKey,id> *> *classStyles;
/// 按 id 名称配置样式。
@property(nonatomic,copy) NSDictionary<NSString *, NSDictionary<NSAttributedStringKey,id> *> *identifierStyles;
/// 有序列表起点；原库默认 1，不从 HTML start 属性读取。
@property(nonatomic,assign) NSInteger listStart;
/// 水平分隔线的短横线数量；原库默认 7。
@property(nonatomic,assign) NSUInteger horizontalRuleLength;
/// 文本表格列宽；nil 时按首行文字长度计算。
@property(nonatomic,strong,nullable) NSNumber *tableColumnLength;
/// 文本表格列之间的空格数；默认 3。
@property(nonatomic,assign) NSUInteger tableColumnSpacing;
/// 图片附件工厂；nil 时返回带 URL 的占位附件，不主动下载。
@property(nonatomic,copy,nullable) SobotHTMLAttachmentProvider attachmentProvider;
@end

/// 保留扫描→修复→节点树→样式合并→富文本输出的完整文字解析流程。
/// 不使用系统 HTML 文档导入，不操作 UIView；每次调用的可变状态独立。
@interface SobotHTMLParser : NSObject
/// 创建默认选项解析器。
- (instancetype)init;
/// 复制选项，建立可跨线程调用的解析器。
- (instancetype)initWithOptions:(SobotHTMLParserOptions *)options NS_DESIGNATED_INITIALIZER;
/// 同步解析，运行在调用方线程；SDK 历史队列直接调用此方法。
- (NSMutableAttributedString *)renderHTML:(nullable NSString *)html;
/// 保留输入文字已有属性；解析样式覆盖同名属性。
- (NSMutableAttributedString *)renderAttributedHTML:(NSAttributedString *)html;
/// 对齐原库异步接口：后台解析，主线程交付；SDK 历史入口不使用此接口。
- (void)renderHTML:(NSString *)html completion:(void (^)(NSAttributedString *result))completion;
/// 仅实体解码，保留未知及无效实体原文。
+ (NSString *)decodeEntities:(NSString *)text;
@end

/// 核心图片节点保留 URL 与占位；下载及视图替换由 SDK 图片组件负责。
@interface SobotHTMLTextAttachment : NSTextAttachment
/// 原始图片地址，仅作数据保存。
@property(nonatomic,strong,readonly) NSURL *sourceURL;
/// 用 HTML 中的尺寸创建附件；不执行网络请求。
- (instancetype)initWithURL:(NSURL *)URL width:(CGFloat)width height:(CGFloat)height;
@end
NS_ASSUME_NONNULL_END
#endif
