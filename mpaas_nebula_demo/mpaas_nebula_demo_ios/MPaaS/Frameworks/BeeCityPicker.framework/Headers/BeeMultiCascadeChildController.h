//
//  BeeMultiCascadeChildController.h
//  BeeCityPicker
//
//  Created by 莜阳 on 2017/7/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@protocol BeeMultiCascadeDelegate <NSObject>

@optional
- (void)cancelMultiCascadeController:(UIViewController *)viewController;
- (void)didSelecData:(NSArray *)data viewController:(UIViewController *)viewController;

@end

@interface BeeMultiCascadeChildController : UIViewController

@property (nonatomic, weak) id <BeeMultiCascadeDelegate>delegate;

@property (nonatomic, strong) UIView *maskView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *closeImgView;
@property (nonatomic, strong) AUSegment *segment;
@property (nonatomic, strong) AUTableView *tableView; // 内容区
@property (nonatomic, strong) NSString *segmentDefaultDesc; // 

@property (nonatomic, assign) NSInteger selectedRows;

- (instancetype)initWithParams:(NSDictionary *)params;

@end
