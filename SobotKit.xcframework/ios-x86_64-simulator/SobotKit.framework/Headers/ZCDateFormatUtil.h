//
//  ZCDateFormatUtil.h
//  SobotKit
//
//  Created by Assistant on 2025/09/09.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 按国际化规范格式化时间戳的工具类
/// 规则：
/// - 今日：仅显示“时:分”，例如 15:30
/// - 本年且非今日：按国际化显示“月 日 时:分”，例如（英文）May 30, 14:00；（中/日）5月30日 14:00
/// - 非本年：按国际化显示“月 日 年 时:分”，例如（英文）May 30, 2025 14:00；（中/日）2025年5月30日 14:00
@interface ZCDateFormatUtil : NSObject


/// 把时间戳转换为国际化格式的日期字符串
/// - Parameter timestampString: 时间戳
+ (NSString *)formatV7Timestamp:(NSString*)timestampString;


/// 使用系统当前语言与区域设置，格式化时间戳（单位：秒）
/// - Parameter timestamp: Unix 时间戳，单位秒
/// - Returns: 本地化后的时间文案
+ (NSString *)formatTimestamp:(NSTimeInterval)timestamp;

/// 使用指定 locale（如 zh-Hans、zh-Hant、ja、en_US）格式化时间戳（单位：秒）
/// - Parameters:
///   - timestamp: Unix 时间戳，单位秒
///   - localeIdentifier: 语言区域标识，如 @"zh-Hans"、@"zh-Hant"、@"ja"、@"en_US"
+ (NSString *)formatTimestamp:(NSTimeInterval)timestamp localeIdentifier:(nullable NSString *)localeIdentifier;


/// 将日期字符串转换为国际化显示格式
/// - Parameter dateString: 输入的日期字符串，格式如 "2025-08-17 01:04"
/// - Returns: 国际化后的日期字符串，例如：英文 "17 Aug, 2025 01:04"，中文 "2025年8月17日 01:04"
+ (NSString *)formatDateStringToLocalizedString:(NSString *)dateString;

/// 将日期字符串转换为国际化显示格式（指定 locale）
/// - Parameters:
///   - dateString: 输入的日期字符串，格式如 "2025-08-17 01:04"
///   - localeIdentifier: 语言区域标识，如 @"zh-Hans"、@"en_US"，传 nil 使用系统当前语言
/// - Returns: 国际化后的日期字符串
+ (NSString *)formatDateStringToLocalizedString:(NSString *)dateString localeIdentifier:(nullable NSString *)localeIdentifier;



/// 获取国际化的formate
/// - Parameters:
///   - language: 当前语言
///   - sameYear: 当为YES时，不显示年
+(NSDateFormatter *)getDateNSDateFormatter:(NSString *) language sameYear:(BOOL) sameYear;

/// 时间戳字符串转：把不同精度的时间戳转换为秒
/// - Parameter timestampString: 时间戳:(秒、毫秒、微妙、纳秒)
+ (NSTimeInterval)safeConvertTimestampString:(NSString *)timestampString;


/// 把日期字符串转换为日期对象
/// - Parameter dateString: 日期字符串：
//@"yyyy-MM-dd HH:mm:ss",     // 2025-08-17 01:04:30
//@"yyyy/MM/dd HH:mm:ss",     // 2025/08/17 01:04:30
//@"yyyy.MM.dd HH:mm:ss",     // 2025.08.17 01:04:30
//@"yyyy-MM-dd'T'HH:mm:ssZ",  // ISO 8601 with timezone
//@"yyyy-MM-dd'T'HH:mm:ss",   // ISO 8601: 2025-08-17T01:04:30
//@"yyyy-MM-dd HH:mm",        // 2025-08-17 01:04
//@"yyyy/MM/dd HH:mm",        // 2025/08/17 01:04
//@"yyyy.MM.dd HH:mm",        // 2025.08.17 01:04
//@"yyyyMMdd HH:mm",          // 20250817 01:04
///
+ (NSDate *)parseDateString:(NSString *)dateString;
@end

NS_ASSUME_NONNULL_END





