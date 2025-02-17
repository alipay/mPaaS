//
//  DemoVerticalTabViewController.m
//  AntUIDemo
//
//  Created by zhaolei on 2018/4/12.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "DemoVerticalTabViewController.h"
#import "AUVerticalTabView.h"

static int i = 0;

@interface DemoVerticalTabData : NSObject <AUVerticalTabViewDataProtocol>{
    NSString *_tabName;
    int _index;
}

- (NSString *)tabName;

@end

@implementation DemoVerticalTabData

- (instancetype)init
{
    self = [super init];
    if (self) {
        _index = i++;
    }
    return self;
}

- (NSString *)tabName
{
    
    NSArray *array = @[@"选项一",@"选项二",@"选项三",@"选项四",@"不超过五字",@"选项五",@"选项六"];
    
    if(_tabName.length == 0){
        _tabName = array[_index];
    }
    return _tabName;
}

@end

@interface DemoVerticalTabViewController ()

@end

@implementation DemoVerticalTabViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.contentView.hidden = YES;
    self.headerView.hidden = YES;
    self.footerView.hidden = YES;
    
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    NSArray *datas = @[[DemoVerticalTabData new],
                       [DemoVerticalTabData new],
                       [DemoVerticalTabData new],
                       [DemoVerticalTabData new],
                       [DemoVerticalTabData new],
                       [DemoVerticalTabData new],
                       [DemoVerticalTabData new]];
    
    __block UILabel *label = [[UILabel alloc] init];
    label.font = [UIFont systemFontOfSize:30.0];
    [self.view addSubview:label];
    
    __weak typeof(self)weakSelf = self;    
    AUVerticalTabView *tabView = [AUVerticalTabView verticalTabViewWithDatas:datas
                                                            selectedCallback:^(AUVerticalTabView *verticalTabView ){
                                                                [weakSelf updateLabel:label
                                                                              tabView:verticalTabView];
                                                            }
                                                                      height:self.view.height
                                                                    business:@"AntUI"];
    [self.view addSubview:tabView];
    [self updateLabel:label
              tabView:tabView];

    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)updateLabel:(UILabel *) label
            tabView:(AUVerticalTabView *) tabView
{
    label.text = [tabView.verticalTabViewDatas objectAtIndex:tabView.selectedIndex].tabName;
    [label sizeToFit];
    label.left = tabView.right + 50;
    label.centerY = tabView.centerY;
}

@end
