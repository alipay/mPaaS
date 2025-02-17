//
//  ActionSheetDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ActionSheetDemoViewController.h"
//#import "AUActionSheetItem+ForTinyApp.h"
#import <AntUI/AUActionSheet.h>
#import <AntUI/AUActionSheetItem+ForTinyApp.h>

@interface ActionSheetDemoViewController () <UIActionSheetDelegate>

@end

@implementation ActionSheetDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"常规样式";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"带消息提示";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"包含注释与删除";
    model.target = self;
    model.selector = @selector(onButton3Clicked:);
    [models addObject:model];

    self.functionList = [NSArray arrayWithArray:models];
    
    AUIconView *imgR = [[AUIconView alloc] initWithFrame:CGRectMake(0, 0, 18, 18) name:kICONFONT_SEARCH];
    imgR.color = RGB(0xffffff); // home_rightitem
    AUBarButtonItem *rightitem = [[AUBarButtonItem alloc] initWithImage:imgR.image style:UIBarButtonItemStylePlain target:self action:nil];
    self.navigationItem.rightBarButtonItem = rightitem;
    
    
    self.navigationItem.titleView = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, AUCommonUIGetScreenWidth(), AUCustomNavigationBarHeight)];
}

- (void)onButton1Clicked:(id) sender
{
    // 错误用法
//    AUActionSheet *actionSheet = [[AUActionSheet alloc] init];
//    [actionSheet addButtonWithTitle:@"取消"];
//    [actionSheet showFromRect:CGRectZero inView:self.view animated:YES];
//    return;
    
    AUActionSheet *actionSheet = [[AUActionSheet alloc] initWithTitle:nil
                                                             delegate:self
                                                    cancelButtonTitle:@"取消"
                                               destructiveButtonTitle:nil
                                                    otherButtonTitles:@"选项一",@"选项二",@"选项三", nil];
    [actionSheet show];
}

- (void)onButton2Clicked:(id) sender
{
    NSMutableArray *array = [[NSMutableArray alloc] init];
    
    AUActionSheetItem *item = [[AUActionSheetItem alloc] init];
    item.title = @"选项一";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleRedDot;
    __weak typeof (item) weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    [array addObject:item];
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"选项二";
    item.type = AUActionSheetButtonTypeCustom;
    item.titleColor = [UIColor redColor];
    item.badgeViewStyle = AUBadgeViewStyleNumber;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyNumber:@(99)};
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    
    [array addObject:item];
    

    item = [[AUActionSheetItem alloc] init];
    item.title = @"选项三";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleText;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyText:@"new"};
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    [array addObject:item];
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"开启增强版提醒";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleText;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyText:@"推荐"};
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    
    [array addObject:item];
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"选项四";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleText;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyText:@"支持动图"};
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    
    [array addObject:item];
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"标题很长标题很长标题很长标题很长标题很长标题很长标题很长标题很长标题很长标题很长标题很长";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleText;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyText:@"红点很长红点很长红点很长"};
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"业务方主动限制字数";
    item.type = AUActionSheetButtonTypeCustom;
    item.badgeViewStyle = AUBadgeViewStyleText;
    item.badgeViewAttributes = @{kAUBadgeViewAttributeKeyText:@"红点很长红点很长红点很长",
                                 kAUBadgeViewAttributeKeyMaxTextLength:@(3)
                                 };
    
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    
    [array addObject:item];
    
    item = [[AUActionSheetItem alloc] init];
    item.title = @"提供小程序使用接口";
    item.type = AUActionSheetButtonTypeCustom;
    NSError *error;
    [item au_for_tiny_app_setBageStyle:kActionSheetBageStyleForTinyAppText
                               content:@"一二三四五六七"
                                 error:&error];  
    
    weakItem = item;
    item.actionBlock = ^{
        NSLog(@"%@",weakItem.title);
    };
    
    [array addObject:item];
  
    AUActionSheet *actionSheet = [[AUActionSheet alloc] initWithTitle:nil
                                                             delegate:self
                                                    cancelButtonTitle:@"取消"
                                               destructiveButtonTitle:nil
                                                                items:array];
    [actionSheet show];

}

- (void)onButton3Clicked:(id) sender
{
    AUActionSheet *actionSheet = [[AUActionSheet alloc] initWithTitle:@"这是提供一行或二行注释, 通过信息澄清的方式避免产生用户疑问。"
                                                             delegate:self
                                                    cancelButtonTitle:@"取消"
                                               destructiveButtonTitle:@"确认删除"
                                                    otherButtonTitles:nil];
    [actionSheet show];
}

@end
