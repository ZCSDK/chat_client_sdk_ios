//
//  ZCVariableModel.h
//  SobotChatClient
//
//  Created by lizh on 2026/1/14.
//

#import <Foundation/Foundation.h>
#import <SobotCommon/SobotCommon.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZCVariableModel : SobotBaseEntity
//[
//  {
//    "variableId": "variableId_edc69722ca73",// 变量id
//    "variableName": "variableName_0e48b4e81eff",// 变量名称
//    "variableCode": "variableCode_ac8b087fb568",// 变量码
//    "variableValue": "variableValue_dafacd970521",// 变量收集值
//    "variableType": "CHARACTER", // 变量类型 CHARACTER-字符，NUMBER-数字，ENUMERATION-枚举
//    "enumList": { // 枚举字段   key是语言标识，value是每个语言下的枚举集合
//      "zh":[
//          {
//           "id": "id_34e35c08d8c9",// 枚举id
//           "label": "label_bf99228c2298" // 枚举值
//          }
//      ]
//    },
//    "errorMsg": "errorMsg_b1f3fcd5115a" // 错误信息
//  }
//]
@property(nonatomic,copy)NSString *variableId;
@property(nonatomic,copy)NSString *variableName;
@property(nonatomic,copy)NSString *variableCode;
@property(nonatomic,copy)NSString *variableValue;
@property(nonatomic,copy)NSString *variableType;
@property(nonatomic,strong)NSMutableDictionary *enumList;
// 数据源，上传接口使用
@property(nonatomic,strong)NSMutableDictionary *sorceEnumList;
@property(nonatomic,copy)NSString *errorMsg;
@property(nonatomic,strong)NSString *fieldSaveValue;
// 1.文本 2 数字 3 下拉
@property(nonatomic,assign)int type;
/**
 *  对象封装
 *
 *  @param dict 获取数据解析后的数据
 *
 *  @return ZCLibConfig
 */
-(id)initWithMyDict:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
