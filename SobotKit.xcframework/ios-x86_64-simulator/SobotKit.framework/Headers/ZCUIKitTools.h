//
//  ZCUIKitTools.h
//  SobotKit
//
//  Created by zhangxy on 2022/9/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <SobotCommon/SobotCommon.h>

//用户SDK颜色值
static SobotTypeColor const _Nullable SobotColorTextLinkRight = @"SobotColorTextLinkRight";// 右边气泡中链接色
static SobotTypeColor const _Nullable SobotColorTextRed = @"SobotColorTextRed";//白色背景,转浅黑背景
static SobotTypeColor const _Nullable SobotColorBgSubF5 = @"SobotColorBgSubF5";//白色背景,转浅黑背景
static SobotTypeColor const _Nullable SobotColorBgF0 = @"SobotColorBgF0";//白色背景,转浅黑背景
static SobotTypeColor const _Nullable SobotColorBgBlock = @"SobotColorBgBlock";//白色背景,转浅黑背景

static SobotTypeColor const _Nullable SobotColorBorderF0240 = @"SobotColorBorderF0240";//白色背景,转浅黑背景

static SobotTypeColor const _Nullable SobotColorBgSubF5Press = @"SobotColorBgSubF5Press";//白色背景,转浅黑背景
static SobotTypeColor const _Nullable SobotColorBgButtonGrey1 = @"SobotColorBgButtonGrey1";//白色背景,转浅黑背景
static SobotTypeColor const _Nullable SobotColorBgButtonGrey2 = @"SobotColorBgButtonGrey2";//白色背景,转浅黑背景


static SobotTypeColor const _Nullable SobotColorBorderF0 = @"SobotColorBorderF0";//白色背景,转浅黑背景

static SobotTypeColor const _Nullable SobotColorYellowBg = @"SobotColorYellowBg";//评价黄色背景

static SobotTypeColor const _Nullable SobotColorYellowLight = @"SobotColorYellowLight";//白色背景,转浅黑背景

static SobotTypeColor const _Nullable SobotColorYellowDark = @"SobotColorYellowDark";//白色背景,转浅黑背景

static SobotTypeColor const _Nullable SobotColorTextSubDark = @"SobotColorTextSubDark";// 客服昵称 机器人昵称 提示语文字颜色

static SobotTypeColor const _Nullable SobotColorGreenLightBg = @"SobotColorGreenLightBg";// 选项选中时的浅色绿背景

static SobotTypeColor const _Nullable SobotColorCellSelBg = @"SobotColorCellSelBg";// 语言选择cell选中的颜色

static SobotTypeColor const _Nullable SobotColorSkillCellSelBg = @"SobotColorSkillCellSelBg";// 技能组1选择cell选中的颜色

static SobotTypeColor const _Nullable SobotColorSkillCellBg = @"SobotColorSkillCellBg";// 技能组1选择cell选中的颜色

static SobotTypeColor const _Nullable SobotColorSkillCellBoardBg = @"SobotColorSkillCellBoardBg";// 技能组样式1边框线条颜色 

static SobotTypeColor const _Nullable SobotColorNoticeBg = @"SobotColorNoticeBg";// 通告背景色 消息气泡

static SobotTypeColor const _Nullable SobotColorNoticeBg1 = @"SobotColorNoticeBg1";// 通告背景色 顶部背景色

static SobotTypeColor const _Nullable SobotColorNoticeLinkColor = @"SobotColorNoticeLinkColor";// 通告超链颜色

static SobotTypeColor const _Nullable SobotOrderFileBg = @"SobotOrderFileBg";// 留言附件背景颜色
static SobotTypeColor const _Nullable SobotColorBgUnRead = @"SobotColorBgUnRead";// 留言附件背景颜色
static SobotTypeColor const _Nullable SobotColorNavcBgC = @"SobotColorNavcBgC";// 导航栏默认颜色 支持暗夜 白和黑

static SobotTypeColor const _Nullable SobotColorAlterViewBg = @"SobotColorAlterViewBg";// 半弹窗页面背景色 暗夜#2C2C2C  白天白色
static SobotTypeColor const _Nullable SobotColorBg4D = @"SobotColorBg4D";// 语音提示与，4D4D4D-->2C2C2C

// 导航栏 黑色文字颜色
//static SobotTypeColor const _Nullable SobotColorTextBlack = @"SobotColorTextBlack";
NS_ASSUME_NONNULL_BEGIN
// 留言详情中的留言和评价按钮背景色
static SobotTypeColor const _Nullable SobotColorBgOrderButton = @"SobotColorBgOrderButton";
// 时区的颜色
static SobotTypeColor const _Nullable SobotColorZoneBg = @"SobotColorZoneBg";//
/// 自定义颜色
@interface ZCUIKitTools : NSObject

/// 获取当前主体风格
+(SobotThemeMode ) getZCThemeStyle;

#pragma mark -- 更新导航栏的主题色
+(SobotThemeMode ) getZCNavcThemeStyle;

// 获取手机验证吗规则
+(NSString *) zcgetTelRegular;

// 获取url正则表达式
+(NSString *)zcgetUrlRegular;

+ (int)IntervalDay:(NSString *)filePath;


#define imageVALIDMINUTES 3
#define voiceVALIDMINUTES 3
+(BOOL)imageIsValid:(NSString *)filePath;
+(BOOL)videoIsValid:(NSString *)filePath;

/**
 *  是否开启语音开关
 *
 *  @return return
 */
+(BOOL) zcgetOpenRecord;

/**
 *  是否设置相册的背景图片
 *
 *  @return 默认为NO
 */
+(BOOL) zcgetPhotoLibraryBgImage;

// 置顶的通告背景
+(UIColor *)getNotifitionTopViewBgColor;
+(UIColor *)getNotifitionTopViewLabelColor;

#pragma mark 自定义字体
+(UIFont *)zcgetTitleFont;
+(UIFont *)zcgetSubTitleFont;
+(UIFont *)zcgetListKitTitleFont;
+(UIFont *)zcgetListKitDetailFont;
+(UIFont *)zcgetListKitTimeFont;
+(UIFont *)zcgetKitChatFont;
+(UIFont *)zcgetVoiceButtonFont;
+(UIFont *)zcgetTitleGoodsFont;
+(UIFont *)zcgetGoodsDetFont;
#pragma mark -- 自定义字体颜色

#pragma mark -- 导航栏客服头像是否黑色半透明固定显示
+(BOOL)isHeaderBlackBackgroudColor;

#pragma Mark -- 导航栏是否要监听系统切换暗夜或者白天的事件 实时修改导航栏的颜色
+(BOOL)isChangNavcBackgroudColor;

/// 聊天页面背景色
+(UIColor *)zcgetChatBackgroundColor;

/// 设置导航栏颜色
+(UIColor *)zcgetNavBackGroundColorWithSize:(CGSize)size;

// 导航栏是白色还是黑色 1 light 2 dark 3 color
// 导航栏上面的头像 占位图有3种样式 对应导航栏颜色
+(int)getNavBackGroundColorType;

/// 设置是否使用黑色
+(BOOL)isBlackColorIcon;

/// 设置主题按钮的背景色
/// @param size 按钮的size
///  V7 取接口返回的，使用接口返回，返回什么用什么 本地不做对比
+(UIColor *)zcgetRobotBackGroundColorWithSize:(CGSize)size;

/// V7 主题按钮的文字颜色 是根据主题色的最后一个颜色值去判断是要显示白色还黑色
/// 主题色按钮和气泡背景上边的文字图标颜色  接口都会返回数据的取接口
+(UIColor *)getServerThemeTextColor;

// 当前主题文字的颜色是不是黑色
+(BOOL)isBlackServerThemeTextColor;

/// 设置主题按钮的背景颜色
+(UIColor *)zcgetServerThemeBgColor;
/// 主题按钮的背景颜色 v7
+(UIColor *)zcgetServerThemeBgColor:(CGFloat) alpha;

/// 设置按钮的文字颜色
+(UIColor *)zcgetRobotBtnTitleColor;
/**
 *  顶部字体颜色
 *
 *  @return 导航文字颜色
 */
+(UIColor *)zcgetTopViewTextColor;

/// 更多按钮的 文字颜色 默认黑色
+(UIColor *)zcgetTextNolColor;

+(UIColor *)zcgetChatBottomLineColor;

+(UIColor *)zcgetChatBgBottomColor;

/// 留言提交按钮的背景颜色
+(UIColor *)zcgetLeaveSubmitImgColor;

/// 自定义卡片商品价格标签的文字颜色
+(UIColor *)zcgetPricetTagTextColor;
/**
 *   留言页面 中 提交按钮的文字颜色
 */
+(UIColor *)zcgetLeaveSubmitTextColor;

/// 获取留言提交成功页面背景色
+(UIColor *)zcgetLeaveSuccessViewBgColor;

/// 左边气泡颜色
+(UIColor *)zcgetLeftChatColor;

/// 左边气泡选中的颜色
+(UIColor *)zcgetChatLeftSelBgColor;
/**
 *  右边气泡颜色
 */
+(UIColor *)zcgetRightChatColor;

// 设置右边气泡颜色
+(UIColor *)zcgetRightChatColorWithSize:(CGSize)size;

/// 右边气泡选中的颜色
+(UIColor *)zcgetChatRightSelBgColor;

/// 右边气泡选中
+(UIColor *)zcgetRightChatSelectdeColor;
/// 左边气泡选中
+(UIColor *)zcgetLeftChatSelectedColor;
/**
 *  左边气泡里面文字颜色
 */
+(UIColor *)zcgetLeftChatTextColor;

/**
 *  聊天语音cell选中的背景色
 */
//+(UIColor *)zcgetChatRightVideoSelBgColor;


/// 聊天语音翻译背景颜色
+(UIColor *)zcgetRightChatVoiceTextBgColor;

/// 聊天语音翻译文字颜色
+(UIColor *)zcgetRightChatVoiceTextColor;

/**
 *  聊天气泡中左边链接的颜色
 */
+(UIColor *)zcgetChatLeftLinkColor;

/**
 *  聊天气泡中右边链接的颜色
 */
+(UIColor *)zcgetChatRightlinkColor;

/**
 *  右边气泡里面文字颜色
 */
+(UIColor *)zcgetRightChatTextColor;

/**
 *  浅灰色背景颜色
 *  F8F9FA
 */
+(UIColor *)zcgetLightGrayBackgroundColor;

/**
 *  浅灰色背景颜色,浅灰色变纯黑
 *  F8F9FA
 */
+(UIColor *)zcgetLightGrayDarkBackgroundColor;

/**
 *  占位文字颜色
 */
+(UIColor *)zcgetTextPlaceHolderColor;

/**
 *  留言记录cell 白色背景view 颜色
 */
+(UIColor *)zcgetMsgRecordCellBgColor;

/**
 *   评价按钮边框线颜色
 */
+(UIColor *)zcgetCommentButtonLineColor;

/**
 *   评价弹出选项颜色
 */
+(UIColor *)zcgetCommentItemButtonBgColor;

/**
 *   评价弹出选项选中颜色
 */
//+(UIColor *)zcgetCommentItemSelButtonBgColor;

/**
 *  客服评价页面 满意度星级说明
 */
+(UIColor *)zcgetScoreExplainTextColor;

/**
 *  提交评价按钮的文字颜色
 */
+(UIColor *)zcgetSubmitEvaluationButtonColor;

/**
 *
 *  通告的文字颜色
 *
 *  @return UIColor
 */
+(UIColor *)getNotifitionTopViewLabelColor;

/**
 *  文件查看 按钮 背景颜色
 */
+(UIColor *)zcgetDocumentBtnDownColor;

/**
 *  时间文字的颜色
 */
+(UIColor *)zcgetTimeTextColor;

/**
 * 商品详情cell中发送按钮的文字颜色
 *
 */
+(UIColor *)zcgetGoodsSendColor;

/**
 *  获取导航颜色
 */
+(UIColor *) zcgetBgBannerColor;

/**
*  输入框文本颜色
*
*  @return
*/
+(UIColor *)zcgetChatTextViewColor;

/**
 *
 *  帮助中心 导航条文字font
 *
 **/
+(UIFont *)zcgetscTopTextFont;

/**
 *
 *  帮助中心 导航条背景色
 *
 **/
+(UIColor *)zcgetscTopBgColor;

/**
 *
 * 帮助中心 导航条中间文字颜色
 *
 **/
+(UIColor *)zcgetscTopTextColor;

// 2.8.0
/**
 *  文件查看 ImgProgress 背景颜色
 */
+(UIColor *)zcgetDocumentLookImgProgressColor;

/// 聊天文本间距
+(CGFloat )zcgetChatLineSpacing;


/// 聊天间隔线颜色
+(UIColor *)zcgetLineRichColor;

/**
 *   评价弹出页面 ，按钮文字颜色
 */
//+(UIColor *)zcgetCommentPageButtonTextColor;

/**
 * 评价页面中 已解决，未解决 按钮的 高亮状态的文字颜色
 */
+(UIColor *)zcgetSatisfactionTextSelectedColor;

/**
 *  提交评价后会话将结束
 */
+(UIColor *)zcgetSatisfactionColor;



/// 非主题色按钮背景颜色
+(UIColor *)zcgetItemButtonBgColor;

/**
 *   评价按钮文字颜色
 */
+(UIColor *)zcgetCommentCommitButtonColor;

/**
 *  暂不评价文字颜色
 */
+(UIColor *)zcgetNoSatisfactionTextColor;

/**
 * 评价页面中 已解决，未解决 按钮的 高亮状态的 背景颜色
 */
+(UIColor *)zcgetSatisfactionBgSelectedColor;

/**
 *  商品卡片中发送按钮的背景色
 */
+(UIColor *)zcgetGoodSendBtnColor;

/**
 *   按钮主题背景色
 */
+(UIColor *)zcgetButtonThemeBgColor;


/**
 *    导航栏背景颜色
 */
+(UIColor *)zcgetTopViewBgColor;

/**
 *    请您留言 和留言记录 以及选中的线条颜色
 */
+(UIColor *)zcgetLeaveTitleTextColor;


/**
 引用消息，左右文字和竖线颜色
 */
+(UIColor *)zcgetReferenceLeftLineColor;
+(UIColor *)zcgetReferenceLeftNameColor;
+(UIColor *)zcgetReferenceLeftTextColor;
+(UIColor *)zcgetReferenceRightLineColor;
+(UIColor *)zcgetReferenceRightNameColor;
+(UIColor *)zcgetReferenceRightTextColor;


/// 引导语行间距，3.0.3新增
+(CGFloat )zcgetChatGuideLineSpacing;

// 设置是否日文换行模式
+(CGFloat)zcgetChatLineBreakModel;

+(NSString *)removeAllHTMLTag:(NSString *)html;
// 设置模型的显示内容
+(void)zcModelStringToAttributeString:(id ) temModel;

+(NSMutableAttributedString *_Nullable)parseStringArtribute:(NSMutableAttributedString *_Nonnull) attr linespace:(CGFloat )lineSpace font:(UIFont *_Nonnull) font textColor:(UIColor *_Nonnull) textColor linkColr:(UIColor *_Nonnull)linkColor;

+(UIColor *)zcgetThemeToWhiteColor;

// 获取资源的NSMutableAttributedString
+(void) attributedStringByHTML:(NSString *)html textColor:(UIColor *) textColor linkColor:(UIColor *) linkColor result:(void(^)(NSMutableAttributedString *attr,NSString *htmlText)) attrBlock;

+(NSString *) getHexStringByColor:(UIColor *) color;

+(UIImage *) getFileIcon:(NSString * ) filePath fileType:(int) type;


/**
 *  设置View 边框
 *
 *  @param color       边框颜色
 *  @param borderWidth 边框宽度
 *  @param view        要设置的View
 */
+ (void)addBottomBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addBottomBorderWithColor:(UIColor *)color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat)viewWidth withView:(UIView *) view;
+ (void)addLeftBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addRightBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat) viewWidth withView:(UIView *) view;

+(CGFloat)getHeightContain:(NSString *)string font:(UIFont *)font Width:(CGFloat) width;
// 带行高
+(CGFloat)getHeightContain:(NSString *)string font:(UIFont *)font Width:(CGFloat) width LineHeight:(CGFloat)LineHeight;
+(CGFloat)getWidthContain:(NSString *)string font:(UIFont *)font Height:(CGFloat) height;
// 计算文本的最大宽度
+(CGFloat)getLabelTextWidthWith:(NSString *)tip font:(UIFont*)font hight:(CGFloat)hight;

// 添加圆角的方法
+(void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii withView:(UIView *) view;

+(void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii
                 viewRect:(CGRect)rect withView:(UIView *) view;


// 获取当前是否支持镜像
+(BOOL)getSobotIsRTLLayout;

// 设置镜像翻转
+(void)setViewRTLtransForm:(UIView *)view;
+(void)setViewRTLtransForm:(UIView *)view  deep:(BOOL) allSubviews;
+(void)setViewRTLSemantic:(UIView *)view;
+(void)setViewRTLSemantic:(UIView *)view deep:(BOOL) allSubviews;

//
+(NSMutableAttributedString *)getOtherColorString:(NSString *)string Color:(UIColor *)Color withString:(NSString *)originalString;
// 设置换行模式
+(void)setLabLineBreakModel:(UILabel *)lab;

// 设置指定颜色的透明度
+(UIColor *)colorWithHex:(NSString *)hex alpha:(CGFloat)alpha;
// 是否是黑色的主题图片
+(BOOL)isBlackThemeButtonColor;
// 获取字符串首字母（支持中英文）
+ (NSString *)firstLetterOfString:(NSString *)string;



/// 圆角为10的阴影圆角背景
/// - Parameter bgView: 需要设置的View
+(void)changeChatCardBgBorderColor:(UIView *) bgView;
@end

NS_ASSUME_NONNULL_END
