#import "SobotSystemSheetController.h"

NS_ASSUME_NONNULL_BEGIN

/// SobotSheetSelectView 的系统 Sheet 实现样例：搜索、单选列表与底部确认。
/// 业务只布置 sheetContentView / sheetFooterView，外层区域由基类处理。
@interface SobotSystemSheetSelectController : SobotSystemSheetController

@property (nonatomic, copy) NSArray<NSString *> *items;
@property (nonatomic, copy, nullable) NSString *selectedItem;
@property (nonatomic, copy) NSString *searchPlaceholder;
@property (nonatomic, copy) NSString *confirmTitle;
@property (nonatomic, copy, nullable) void (^didSelectItem)(NSString *item, NSUInteger originalIndex);

- (instancetype)initWithTitle:(NSString *)title items:(NSArray<NSString *> *)items;

@end

NS_ASSUME_NONNULL_END
