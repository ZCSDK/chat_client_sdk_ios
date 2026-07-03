//
//  SobotBaseListSheetCell.h
//  SobotCommon
//
//  Created by zhangxinyao on 2026/1/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface SobotBaseListSheetCell : UITableViewCell

@property(nonatomic,strong)NSString *bundleName;

@property(nonatomic,strong)UIView *bgView;
@property(nonatomic,strong)UIImageView *imgLogo;
@property(nonatomic,strong)UILabel *titleLab;
@property(nonatomic,strong)UIImageView *imgArrow;

-(void)dataToView:(NSString *) title logo:(NSString *)logoName show:(BOOL) showArrow;

@end
NS_ASSUME_NONNULL_END
