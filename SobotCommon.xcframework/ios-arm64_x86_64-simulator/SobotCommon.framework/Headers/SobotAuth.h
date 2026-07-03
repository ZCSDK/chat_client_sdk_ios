//
//  SobotAuth.h
//  SobotAuth
//
//  Created by zhangxy on 2021/8/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SobotAuth : NSObject

+(NSString *) getAuthVersion;


/// 根据固定key获取加密串，拼接方式：参数+key,
/// @param paramters 参与加密的字段
+(NSString *) getParameterDefaultSign:(NSDictionary *) paramters;


/// 根据指定key获取加密串，拼接方式：参数+key,
/// @param paramters 参与加密的字段
/// @param key 加密的私钥，如果不指定不额外添加
+(NSString *) getParameterSign:(NSDictionary *) paramters withKey:(nullable NSString *) key;


/// 按字段顺序使用内置签名密钥生成 MD5 签名，等价于
/// MD5(field1 + field2 + ... + fieldN + 内置key)
/// 与 getParameterDefaultSign: 区别：字段顺序由调用方显式提供，不依赖 NSDictionary 遍历顺序
/// @param fields 按服务端约定顺序的字段数组，nil 或非字符串元素按空串处理
+(NSString *) sobotSignWithFields:(NSArray<NSString *> *) fields;

@end

NS_ASSUME_NONNULL_END
