#import <UIKit/UIKit.h>

@interface SobotImgTextButton : UIButton

// 如果返回UIColor，会自动赋值给self.layer.borderColor,返回空不处理
// sView为控件本身
@property (nonatomic, copy, nullable) UIColor *_Nullable(^traitCollectionChangedBlock)(UITraitCollection * _Nullable previousTraitCollection,UIView *_Nullable sView);

// 图片尺寸
@property (nonatomic, strong) id _Nullable obj;

@property (nonatomic, strong) UIColor * _Nullable imgBackgroudColor;
@property (nonatomic, assign) CGSize imageSize;         // 图片大小
@property (nonatomic, assign) CGFloat imageTitleSpacing; // 图片与标题间隔
@property (nonatomic, assign) int numberOfLines; // 文字行
@property (nonatomic, assign) UIEdgeInsets imageOutEdge; // 图片与图片背景的间隔


- (void)setIcon:(UIImage *_Nullable)icon title:(NSString *_Nullable)title;

// 需要添加SobotImageView
- (void)setIconURL:(NSURL *_Nullable)url placeImage:(UIImage *_Nullable) image title:(NSString *_Nullable)title;

-(UIImageView *_Nullable)getImageView;
-(UIImageView *_Nullable)getImageBgView;
-(UILabel *_Nullable)getTitleLabel;

@end
