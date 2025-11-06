//
//  ZCVisitorConfig.h
//  SobotKit
//
//  Created by zhangxy on 2024/9/25.
//

#import <UIKit/UIKit.h>
#import <SobotCommon/SobotCommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCVisitorConfig : SobotBaseEntity

/**
 用于判断
 */
@property (nonatomic,strong) NSString *app_key;
@property (nonatomic,strong) NSString *partnerId;


@property (nonatomic,strong) NSString *rebotTheme;
@property (nonatomic,strong) NSString *topBarColor;
@property (nonatomic,strong) NSString *hotlineName;
@property (nonatomic,strong) NSString *hotlineTel;

@property(nonatomic,copy) NSString *rebotThemeBack;
@property(nonatomic,copy) NSString *topBarFlag;
@property(nonatomic,copy) NSString *topBarBackStyle;
@property(nonatomic,copy) NSString *topBarFontIconColorStyle;
@property(nonatomic,copy) NSString *topBarFontIconColor;
@property(nonatomic,copy) NSString *rebotThemeStyle;// 主题模式0-浅色，1-深色，2-跟随系统



//访客配置：
//{"pageNo":null,"pageCount":null,"totalCount":null,"pageSize":null,"retCode":"000000","retMsg":"操作成功","data":{"rebotTheme":"#4ADABE,#0DAEAF","topBarColor":"#4ADABE,#0DAEAF","hotlineName":"服务热线收到撒旦范德萨范德萨范德萨发大师傅士大夫大师傅士大夫大师傅士大夫的十分士大夫但是f","hotlineTel":"10001000",
//"rebotThemeBack":"#FFFFFF",
//"topBarFlag":1,
//"topBarBackStyle":2,
//"topBarFontIconColorStyle":1,
//"topBarFontIconColor":"#ffffff",
//"rebotThemeStyle":1}}
@end

NS_ASSUME_NONNULL_END
