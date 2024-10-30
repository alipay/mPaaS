//
//  DemoHomeViewController.h
//  AntUIDemo
//
//  Created by 莜阳 on 2017/9/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DemoBasicView.h"

#define AU_DEMO(name,dic,iconName) [self setup_category_content:name subItemDic:dic logoPath:iconName];

@interface DemoHomeViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, DemoBasicViewItemDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, strong) NSMutableArray *dataArray;
@property (nonatomic, assign) CGFloat totalHeight;

- (void)setup_category_content:(NSString *)categoryName
                    subItemDic:(NSDictionary *)subItemDic
                      logoPath:(NSString *)logoPath;

@end
