//
//  SobotCallCache.h
//  SobotCallSDK
//
//  Created by zhangxy on 2022/7/4.
//

#import <Foundation/Foundation.h>
#import <SobotChatClient/SobotChatClientDefines.h>

#define ChatClientBundelName @"SobotKit"

// 链接点击
typedef BOOL (^SobotChatClientLinkClickBlock)(id _Nullable object,NSString * _Nullable linkUrl);;

// 页面事件监听
typedef void (^SobotChatClientPageLoadBlock)(id _Nullable object,int type);

NS_ASSUME_NONNULL_BEGIN

@interface SobotChatClientCache : NSObject

+(SobotChatClientCache *) shareSobotCallCache;

+(NSString *)localKitString:(NSString *) key;

/// 按指定语言获取 SobotKit 文案，用于语言选择流程中“展示语言”和最终语言未绑定的场景。
/// @param language 语言码，例如 km、hi、zh-Hans、zh-Hant；区域码会按本地资源归一化。
+(NSString *)localKitString:(NSString *)key language:(NSString *)language;

// 检测当前配置语言是否为RTL
+(BOOL)checkKitIsRTLLayout;

+(UIImage *)getKitSysImage:(NSString *)imageName;


+(void)uploadLogMsg;

/// 上传日志
/// @param updateWithOutFlag YES强制直接上传
-(void)uploadLogMsg:(BOOL) updateWithOutFlag;

@end

NS_ASSUME_NONNULL_END
