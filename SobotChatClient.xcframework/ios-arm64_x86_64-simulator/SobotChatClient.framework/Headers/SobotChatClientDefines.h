//
//  SobotChatClientDefines.h
//  SobotChatClient
//
//  Created by zhangxy on 2022/8/30.
//
#import <Foundation/Foundation.h>
#import <SobotCommon/SobotCommon.h>
#import <SobotChatClient/SobotChatClientCache.h>

/**
 * 新版满意度邀评流程发布开关，默认关闭。
 * 0：保持2026-11-20需求开始前的评价行为，包含原资格查询和原记频。
 * 1：启用MANUAL/SYSTEM来源、新查询参数、loading及展示后记频。
 * SobotChatClient与SobotKit须使用相同取值重新编译；宿主宏不改变预编译SDK。
 */
#ifndef SOBOT_ENABLE_NEW_EVALUATION
#define SOBOT_ENABLE_NEW_EVALUATION 0
#endif

// 构建时只接受0或1，避免错误配置意外开启新需求。
#if SOBOT_ENABLE_NEW_EVALUATION != 0 && SOBOT_ENABLE_NEW_EVALUATION != 1
#error SOBOT_ENABLE_NEW_EVALUATION_must_be_0_or_1
#endif

/**
 * 大模型 SSE 后台短时保活与回前台历史恢复总开关。
 *
 * 1（默认）：启用 beginBackgroundTask 和前台历史对账。
 * 0：编译期完全移除上述增量逻辑，恢复为改造前的 SSE 后台行为。
 *
 * 发包时可直接修改本默认值，也可在 Build Settings > Preprocessor Macros 中传入
 * SOBOT_ENABLE_AI_BACKGROUND_STREAM_RECOVERY=0 覆盖，无需宿主增加后台 capability。
 */
#ifndef SOBOT_ENABLE_AI_BACKGROUND_STREAM_RECOVERY
#define SOBOT_ENABLE_AI_BACKGROUND_STREAM_RECOVERY 1
#endif

/**
 * REQ-7132210170 在线访客附件类型限制发布开关（不作用于留言）。
 * 1（默认）：启用上传前类型校验及文件单选；0：跳过本地类型校验并恢复文件多选。
 * 原有大小限制、服务端上传拒绝及失败重试不受开关影响。
 * 可修改此默认值，或在编译 SobotKit 时通过 Preprocessor Macros 传入
 * SOBOT_ENABLE_VISITOR_FILE_TYPE_LIMIT=0；仅修改宿主 App 的宏不会改变已编译的 SDK。
 * 配置模型字段/解析和语言资源始终保留，避免切换开关改变模型接口。
 */
#ifndef SOBOT_ENABLE_VISITOR_FILE_TYPE_LIMIT
#define SOBOT_ENABLE_VISITOR_FILE_TYPE_LIMIT 1
#endif

// 国际化
#define SobotKitLocalString(key) [SobotChatClientCache localKitString:key]
#define SobotKitIsRTLLayout [SobotChatClientCache checkKitIsRTLLayout]

// 资源
#define SobotKitGetImage(imageName) [SobotUITools getSysImageByName:imageName bundleName:ChatClientBundelName]
// 颜色
#define UIColorFromKitModeColor(themeColorKey) [SobotUITools getSobotThemeModeColor:themeColorKey  bundleName:ChatClientBundelName]
#define UIColorFromKitModeColorAlpha(themeColorKey,a) [SobotUITools getSobotThemeModeColor:themeColorKey alpha:a bundleName:ChatClientBundelName]

// 底部弹出标题高度
#define ZCSheetTitleHeight   57

// 是否开启自动提醒   414 废弃 从初始化接口获取
//#define Sobot_isEnableAutoTips @"Sobot_isEnableAutoTips"

// 企业ID
#define Sobot_CompanyId @"Sobot_CompanyId"
#define Sobot_UId @"Sobot_UId"
// 是否收集日志
#define Sobot_collectFlag @"Sobot_collectFlag"

// 初始化返回的UID
#define Sobot_ChatClientCurUID @"Sobot_ChatClientCurUID"

// 初始化信息过时信息
#define Sobot_ConfigExperiseInfoHeader @"Sobot_ConfigExperiseInfo_"

// 查询的地址信息
#define Sobot_CacheURLHeader @"Sobot_CacheURL_"

// 未读消息缓存 key 前缀 (NSUserDefaults)
// 完整 key = Sobot_UnreadMsgHeader + appKey + "+" + partnerid
// 缓存内容已脱敏(仅 count + 通用文案), 仅用于杀 App 后冷启动恢复未读数
#define Sobot_UnreadMsgHeader @"Sobot_UnreadMsg_"


#pragma mark - 日志脱敏工具
//
// 用于规避 CWE-532 (敏感数据写日志) / CWE-200 (信息泄漏)
// 适用场景: SobotLog 本地缓存日志会被上传服务端, 不应包含 token/appKey/sign 等

/// 中间打码: "abcdefgh" -> "ab****gh"
/// @param s 原文; nil/空串返回 @""
/// @param keepHead 保留头部字符数
/// @param keepTail 保留尾部字符数
NS_INLINE NSString *sobotRedact(NSString *s, NSUInteger keepHead, NSUInteger keepTail) {
    if (s == nil || ![s isKindOfClass:[NSString class]] || s.length == 0) return @"";
    if (s.length <= keepHead + keepTail) return @"***";
    return [NSString stringWithFormat:@"%@****%@",
            [s substringToIndex:keepHead],
            [s substringFromIndex:s.length - keepTail]];
}

/// 敏感 key 判定 (大小写不敏感) — sobotSanitizeDict / sobotRedactURL 共用
/// 新增字段统一在这里加, 不要在调用点手动追加 override
NS_INLINE BOOL sobotIsSensitiveKey(NSString *key) {
    if (key == nil || ![key isKindOfClass:[NSString class]] || key.length == 0) return NO;
    static NSSet *blocklist;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        blocklist = [NSSet setWithObjects:
            // 鉴权凭据
            @"appkey", @"app_key", @"channelflag",   // channelFlag 在 Sobot 接口里 = app_key 别名
            @"sign", @"signature",
            @"token", @"devicetoken", @"device_token", @"access_token", @"accesstoken",
            @"password", @"pwd",
            // 用户身份 (访客唯一标识, 在 URL / dict 中都不应明文落地)
            @"uid", @"cid", @"partnerid", @"puid",
            @"idcard", @"id_card",
            // 联系方式
            @"tel", @"phone", @"mobile", @"email",
            nil];
    });
    return [blocklist containsObject:[key lowercaseString]];
}

/// dict 脱敏: 黑名单 key 的 value 用 sobotRedact 替换
/// 调用方: 序列化 / 上传 / 日志输出 dict 前调用本函数
/// @return 脱敏副本; 原 dict 不变
NS_INLINE NSDictionary *sobotSanitizeDict(NSDictionary *d) {
    if (d == nil || ![d isKindOfClass:[NSDictionary class]]) return d;
    NSMutableDictionary *clean = [NSMutableDictionary dictionaryWithDictionary:d];
    for (id k in d.allKeys) {
        if (!sobotIsSensitiveKey(k)) continue;
        id v = d[k];
        if ([v isKindOfClass:[NSString class]]) {
            clean[k] = sobotRedact((NSString *)v, 2, 2);
        } else {
            clean[k] = @"***";
        }
    }
    return clean;
}

/// URL 脱敏: 把 query 中黑名单 key 的 value 替换为打码值
/// 适用场景: 网络失败日志记录完整 URL 时, 避免泄漏 sign/appkey
/// @return 同 host+path, query 黑名单 value 已替换; 解析失败回退到原串
NS_INLINE NSString *sobotRedactURL(NSString *url) {
    if (url == nil || ![url isKindOfClass:[NSString class]] || url.length == 0) return @"";
    NSURLComponents *c = [NSURLComponents componentsWithString:url];
    if (c == nil || c.queryItems.count == 0) return url;
    NSMutableArray<NSURLQueryItem *> *items = [NSMutableArray arrayWithCapacity:c.queryItems.count];
    for (NSURLQueryItem *it in c.queryItems) {
        if (sobotIsSensitiveKey(it.name)) {
            [items addObject:[NSURLQueryItem queryItemWithName:it.name value:sobotRedact(it.value, 2, 2)]];
        } else {
            [items addObject:it];
        }
    }
    c.queryItems = items;
    return c.string ?: url;
}



/**
 *  @enum 网络请求
 */
typedef NS_ENUM(NSInteger, ZCNetWorkCode) {
    /**
     *  访问成功。
     */
     ZC_NETWORK_SUCCESS = 0,
    
    /**
     *  访问成功，但是空数据。
     */
     ZC_NETWORK_NULL_DATA = 1,
    
    /**
     发送时新增数据
     */
    ZC_NETWORK_New_Data = 2,
    
    /**
     发送时新增刷新数据 用于处理 大模型机器人触发的转人工操作
     */
    ZC_NETWORK_AI_Refresh_Data = 3,
    /**
             大模型机器人 点踩点赞 显示
     */
    ZC_NETWORK_AI_COMMENT_TYPE = 5,
    /**
             大模型机器人发送 请求接口超时，如果当前是大模型表单的变量需要将页面变成初始化成功的状态
     */
    ZC_NETWORK_AI_VariableTimeOut = 6,
    
    /**
     *  连接失败。
     */
     ZC_NETWORK_FAIL = -1,
    
    /**
     *  参数错误。
     */
    ZC_NETWORK_PARAMETER_FAIL = -2,
    
    /**
     *  有编码错误。
     */
    ZC_KNOWNCODE_FAIL = -3,

    /**
     *  上传文件类型不支持。
     */
    ZC_NETWORK_UPLOAD_UNSUPPORTED_FILE_TYPE = -4,
};

/**
 *  @enum 智齿消息业务状态码
 */
typedef NS_ENUM(NSInteger, ZCMessageSendCode) {
    /**
     *  发送消息成功。
     */
     ZC_SENDMessage_Success = 0,
    /**
     *  新消息回复。
     */
     ZC_SENDMessage_New = 1,
    
    /**
     *  发送消息失败。
     */
     ZC_SENDMessage_FAIL = -1,
    
    /**
     *  发送消息失败
     */
    ZC__SENDMessage_FAIL_STATUS = 1002,
    /**
     *  发送消息为空
     */
     ZC_SENDMessage_NULL = -2,
    
    /**
     *  文件不存在。
     */
     ZC_File_NotFound = -1000,
    
};
