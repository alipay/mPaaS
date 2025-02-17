//
//  DemoBasicView.h
//  AntUI
//
//  Created by 莜阳 on 2017/7/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//


#define DemoViewDeaultHeight    61

@class DemoBasicViewItem;
@class DemoBasicView;

@interface DemoModel : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIImage *logoImage;
@property (nonatomic, strong) NSMutableDictionary *itemList;
@property (nonatomic, assign) NSInteger sectionHeight;

@end

@protocol DemoBasicViewItemDelegate <NSObject>

@optional
- (void)didClickBasicViewItem:(DemoBasicViewItem *)item vcName:(NSString *)vcName;
- (void)viewDidUpdateLayout:(UIView *)view viewHeight:(CGFloat)viewHeight;

@end

@interface DemoBasicViewItem : UIControl

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *acesoryView;

@end


@interface DemoBasicView : UIControl

@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, strong) UIImageView *leftLogoView;
@property (nonatomic, strong) UIImageView *rightAccessoryView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIControl *bottomListView;  // 底下列表
@property (nonatomic, strong) DemoModel *model;
@property (nonatomic, weak) id<DemoBasicViewItemDelegate> delegate;
@property (nonatomic, assign) BOOL hideBottomlistView;

- (void)setupDataModel:(DemoModel *)model;
- (CGFloat)bottomListHeight;

@end

@interface DemoBasicViewCell : UITableViewCell

@property (nonatomic, strong) DemoBasicView *basicView;
//@property (nonatomic, assign) BOOL hideBottomlistView;

- (void)setupDataModel:(DemoModel *)model;

@end

