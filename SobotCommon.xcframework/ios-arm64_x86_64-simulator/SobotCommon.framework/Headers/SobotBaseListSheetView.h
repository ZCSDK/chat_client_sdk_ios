//
//  SobotBaseListSheetView.h
//  SobotCommon
//
//  Created by zhangxinyao on 2026/1/23.
//

#import <UIKit/UIKit.h>
#import <SobotCommon/SobotCommon.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^SobotBaseListSheetViewItemBlock)(id itemModel,NSInteger index);



@interface SobotBaseListSheetView : UIView<UITableViewDataSource,UITableViewDelegate>

@property(nonatomic,strong)NSString  *bundleName;

-(SobotBaseListSheetView*)initActionSheet:(NSString *)bundleName;

@property(nonatomic,strong)NSMutableArray *listArray;
@property(nonatomic,strong)SobotTableView *listView;

// 按钮动态高度
@property(nonatomic,strong)SobotButton *backButton;
@property(nonatomic,strong)UILabel *titleLabel;
@property(nonatomic,strong)NSLayoutConstraint *listViewH;
@property(nonatomic,strong)NSString  *titleName;

- (void)showInView;

- (void)tappedCancel:(BOOL) isClose;

@property (nonatomic,copy) SobotBaseListSheetViewItemBlock baseSheetItemClickBlock;

@end

NS_ASSUME_NONNULL_END
