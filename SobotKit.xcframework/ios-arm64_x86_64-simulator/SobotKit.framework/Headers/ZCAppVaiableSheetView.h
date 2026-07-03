//
//  ZCAppVaiableSheetView.h
//  SobotKit
//
//  Created by lizh on 2026/1/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^RobotTrunServerBlock)(BOOL isback,  NSMutableArray * _Nonnull formSubmitInfos);
@interface ZCAppVaiableSheetView : UIView
// 当前展示的自定义字段的集合
@property(nonatomic,strong) NSMutableArray *listArray;
@property (nonatomic,copy) RobotTrunServerBlock trunServerBlock;

@property(nonatomic,strong) NSMutableArray *formSubmitInfos;

// 记录是否提交过  是否编辑过，是否是历史记录 0 未提交 1 提交过有error 2 提交完成 已成历史记录
@property(nonatomic,assign)int variableCommitType;
@property(nonatomic,strong) NSString *robotid;// 切换机器人使用
-(void)vaiableDissmisPageSheet;
// 刷新页面高度
-(void)updataPage;
@end

NS_ASSUME_NONNULL_END
