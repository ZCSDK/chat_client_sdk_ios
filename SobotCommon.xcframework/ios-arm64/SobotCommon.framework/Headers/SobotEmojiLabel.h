//
//  SobotEmojiLabel.h
//  SobotEmojiLabel
//
//  Created by molon on 5/19/14.
//  Copyright (c) 2014 molon. All rights reserved.
//

#import "SobotAttributedLabel.h"

/**
 *  SobotEmojiLabelLinkType
 */
typedef NS_OPTIONS(NSUInteger, SobotEmojiLabelLinkType) {
    /** url type */
    SobotEmojiLabelLinkTypeURL = 0,
    /** Email type */
    SobotEmojiLabelLinkTypeEmail,
    /** PhoneNumber Type */
    SobotEmojiLabelLinkTypePhoneNumber,
    /** At Type */
    SobotEmojiLabelLinkTypeAt,
    /** PoundSign Type */
    SobotEmojiLabelLinkTypePoundSign,
};


@class SobotEmojiLabel;
@protocol SobotEmojiLabelDelegate <SobotAttributedLabelDelegate>

@optional
- (void)SobotEmojiLabel:(SobotEmojiLabel*)emojiLabel didSelectLink:(NSString*)link withType:(SobotEmojiLabelLinkType)type;


@end

/**
 * SobotEmojiLabel
 */
@interface SobotEmojiLabel : SobotAttributedLabel

@property (nonatomic, assign) BOOL disableEmoji; //禁用表情
@property (nonatomic, assign) BOOL disableThreeCommon; //禁用电话，邮箱，连接三者

@property (nonatomic, assign) BOOL isNeedAtAndPoundSign; //是否需要话题和@功能，默认为不需要

@property (nonatomic, copy) NSString *customEmojiRegex; //自定义表情正则
@property (nonatomic, copy) NSString *customEmojiPlistName; //xxxxx.plist 格式
@property (nonatomic, copy) NSString *customEmojiBundleName; //自定义表情图片所存储的bundleName xxxx.bundle格式
@property (nonatomic,assign) BOOL isGuideCell;// 是否是多轮会话的•
@property (nonatomic, assign) BOOL preserveExternalParagraphStyle; // 是否保留外部富文本段落样式
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-property-synthesis"
@property (nonatomic, weak) id<SobotEmojiLabelDelegate> delegate; //点击连接的代理方法
#pragma clang diagnostic pop

@property (nonatomic, copy, readonly) id emojiText; //外部能获取text的原始副本


// 是否启用表情按下效果，默认为NO
@property (nonatomic, assign) BOOL enableEmojiPressEffect;
// 当前按下的表情key
@property (nonatomic, copy) NSString *currentPressedEmojiKey;

// 当前按下的表情范围
@property (nonatomic, assign) NSRange currentPressedEmojiRange;

// 按钮文案映射字典，key为数字字符串，value为显示文本
// 例如: @{@"0": @"选项A", @"1": @"选项B"}
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *buttonTextMap;

// 按钮图片映射字典，key为数字字符串，value为UIImage
// 例如: @{@"0": iconImage, @"1": anotherImage}
@property (nonatomic, strong) NSDictionary<NSString *, UIImage *> *buttonImageMap;

// 按钮图标大小，默认 12.0
@property (nonatomic, assign) CGFloat buttonIconSize;

// 按钮边框宽度，默认 1.0
@property (nonatomic, assign) CGFloat buttonBorderWidth;

// 按钮边框颜色，默认使用文本颜色
@property (nonatomic, strong) UIColor *buttonBorderColor;

// 按钮文案字号，默认使用 label 的字号
@property (nonatomic, assign) CGFloat buttonTextFontSize;

// 按钮文字颜色，默认 SobotColorTextMain
@property (nonatomic, strong) UIColor *buttonTextColor;

// 按钮高度，默认 28.0
@property (nonatomic, assign) CGFloat buttonHeight;

// 按钮背景色，默认白色
@property (nonatomic, strong) UIColor *buttonBackgroundColor;

// 按钮阴影颜色，默认无阴影
@property (nonatomic, strong) UIColor *buttonShadowColor;

// 按钮阴影偏移量，默认 CGSizeZero
@property (nonatomic, assign) CGSize buttonShadowOffset;

// 按钮阴影模糊半径，默认 0
@property (nonatomic, assign) CGFloat buttonShadowRadius;

// 按钮阴影透明度，默认 0
@property (nonatomic, assign) CGFloat buttonShadowOpacity;

// 按钮左右外边距（与文案之间的间距），默认 4.0
@property (nonatomic, assign) CGFloat buttonHorizontalMargin;

// 按钮不可点击状态的编号集合
@property (nonatomic, strong) NSSet<NSString *> *disabledButtonNumbers;

// 按钮不可点击状态的文本颜色（支持暗夜模式）
@property (nonatomic, strong) UIColor *buttonDisabledTextColor;

// 按钮不可点击状态的边框颜色（支持暗夜模式）
@property (nonatomic, strong) UIColor *buttonDisabledBorderColor;

// 按钮不可点击状态的背景颜色（支持暗夜模式）
@property (nonatomic, strong) UIColor *buttonDisabledBackgroundColor;

// 创建NSMutableAttributedString 会导致卡顿，在UITableViewCell慎用
- (void) setHTML:(NSString *)html;

- (CGSize)preferredSizeWithMaxWidth:(CGFloat)maxWidth;


-(void)setLinkColor:(UIColor *) color;


+ (NSString *)getNormalStringFilterHTMLString:(NSString *)htmlStr;

-(NSMutableDictionary *) getTextADict:(NSString *) searchText;


@end
