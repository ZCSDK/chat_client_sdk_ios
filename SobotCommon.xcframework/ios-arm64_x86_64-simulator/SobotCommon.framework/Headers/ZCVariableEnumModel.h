//
//  ZCVariableEnumModel.h
//  SobotChatClient
//
//  Created by lizh on 2026/1/15.
//

#import <SobotCommon/SobotCommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCVariableEnumModel : SobotBaseEntity
//{
//           "id": "id_34e35c08d8c9",// 枚举id
//           "label": "label_bf99228c2298" // 枚举值
//          }
@property(nonatomic,copy)NSString *emumId;
@property(nonatomic,copy)NSString *enumName;
-(id)initWithMyDict:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
