//
//  PopoverDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "PopoverDemoViewController.h"
#import "PopMenuDemoViewController.h"

@interface PopoverDemoViewController ()

@end

@implementation PopoverDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"带图标和红点";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"仅显示图标";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"仅显示文本";
    model.target = self;
    model.selector = @selector(onButton3Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"底部浮层";
    model.target = self;
    model.selector = @selector(onButton4Clicked:);
    [models addObject:model];

    self.functionList = models;
}

- (void)onButton1Clicked:(id) sender
{
    NSMutableArray *array = [[NSMutableArray alloc]initWithCapacity:4];
    
    NSArray *items = @[@"添加朋友",@"发起群聊",@"扫一扫",@"收钱",@"帮助"];
    int i = 0;
    for (NSString *typeName in items)  {
        AUNavItemView *item = [[AUNavItemView alloc]initWithFrame:CGRectMake(20, 0, 0, 40)];
        item.itemTitle = typeName;
        item.isNavigationItem = NO;
        //支持iconfont
        //     item.nomarlStateIconFontName = kICONFONT_USER_ADD;
        if (i == 0 ) {
            item.badgeNumber = @"1";
            UIImage *image = [UIImage imageNamed:@"ap_add_friend"];
            item.nomarlStateIconImage = image;
        } else if(i == 1) {
            item.badgeNumber = @"10";
            UIImage *image = [UIImage imageNamed:@"ap_group_talk"];
            item.nomarlStateIconImage = image;
        } else if(i == 2) {
            item.badgeNumber = @"100";
            UIImage *image = [UIImage imageNamed:@"ap_scan"];
            item.nomarlStateIconImage = image;
        } else if(i == 3) {
            item.badgeNumber = @"5";
            UIImage *image = [UIImage imageNamed:@"ap_qrcode"];
            item.nomarlStateIconImage = image;
        } else if(i == 4) {
            UIImage *image = [UIImage imageNamed:@"ap_help"];
            item.nomarlStateIconImage = image;
        }
        i++;
        
        [array addObject:item];
    }
    
    [AUFloatMenu showAtPostion:CGPointMake(0, 0)
                   startOrignY:70
                         items:array];
}

- (void)onButton2Clicked:(id) sender
{
    NSMutableArray *array = [[NSMutableArray alloc]initWithCapacity:4];
    
    NSArray *items = @[@"添加朋友",@"发起群聊",@"扫一扫",@"收钱",@"帮助"];
    int i = 0;
    for (NSString *typeName in items)  {
        AUNavItemView *item = [[AUNavItemView alloc]initWithFrame:CGRectMake(20, 0, 0, 40)];
        item.itemTitle = typeName;
        item.isNavigationItem = NO;
        //支持iconfont
        //     item.nomarlStateIconFontName = kICONFONT_USER_ADD;
        if (i == 0 ) {
            UIImage *image = [UIImage imageNamed:@"ap_add_friend"];
            item.nomarlStateIconImage = image;
        } else if(i == 1) {
            UIImage *image = [UIImage imageNamed:@"ap_group_talk"];
            item.nomarlStateIconImage = image;
        } else if(i == 2) {
            UIImage *image = [UIImage imageNamed:@"ap_scan"];
            item.nomarlStateIconImage = image;
        } else if(i == 3) {
            UIImage *image = [UIImage imageNamed:@"ap_qrcode"];
            item.nomarlStateIconImage = image;
        } else if(i == 4) {
            UIImage *image = [UIImage imageNamed:@"ap_help"];
            item.nomarlStateIconImage = image;
        }
        i++;
        
        [array addObject:item];
    }
    
    [AUFloatMenu showAtPostion:CGPointMake(0, 0)
                   startOrignY:70
                         items:array];
}

- (void)onButton3Clicked:(id) sender
{
    NSMutableArray *array = [[NSMutableArray alloc]initWithCapacity:4];
    
    NSArray *items = @[@"添加朋友",@"发起群聊",@"扫一扫",@"收钱",@"帮助"];
    for (NSString *typeName in items)  {
        AUNavItemView *item = [[AUNavItemView alloc]initWithFrame:CGRectMake(0, 0, 0, 40)];
        item.itemTitle = typeName;
        item.isNavigationItem = NO;
        [array addObject:item];
    }
    
    [AUFloatMenu showAtPostion:CGPointMake(0, 0)
                   startOrignY:70
                         items:array];
}

- (void)onButton4Clicked:(id) sender
{
    PopMenuDemoViewController *vc = [[PopMenuDemoViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

@end
