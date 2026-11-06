#import "SobotWindowSheetView.h"

NS_ASSUME_NONNULL_BEGIN

/// View Sheet 示例：搜索、选择、动态高度、底部按钮、RTL。
@interface SobotWindowSheetSelectView : SobotWindowSheetView

- (instancetype)initWithTitle:(NSString *)title items:(NSArray<NSString *> *)items;

@property (nonatomic, copy) NSArray<NSString *> *items;
@property (nonatomic, copy, nullable) NSString *selectedItem;
@property (nonatomic, copy) NSString *searchPlaceholder;
@property (nonatomic, copy) NSString *confirmTitle;
@property (nonatomic, copy, nullable) void (^didSelectItem)(NSString *item, NSUInteger index);

@end

NS_ASSUME_NONNULL_END
