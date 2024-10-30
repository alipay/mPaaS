//
//  DemoListWithHeaderViewController.h
//  AntUI
//
//  Created by zhaolei on 2017/8/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoBaseViewController.h"

@interface DemoContentModel : NSObject

@property(nonatomic, copy) NSString *headerTitle;
@property(nonatomic, strong) UIView *contentView;

@end

@interface DemoListWithHeaderViewController : DemoBaseViewController

@property(nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray<DemoContentModel *> *contentModelList;

- (UIView *)getNewWrapView;

@end
