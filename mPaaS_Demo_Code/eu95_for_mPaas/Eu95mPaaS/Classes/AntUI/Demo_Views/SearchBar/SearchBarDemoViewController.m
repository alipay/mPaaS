//
//  SearchBarDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/25.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "SearchBarDemoViewController.h"

@interface SearchBarDemoViewController ()

@property (nonatomic, assign) NSInteger code;

@end


@implementation SearchBarDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    AUSearchBar *searchBar = nil;
    
    if (self.code == 1)  {
        AUSearchBar *searchBar = [[AUSearchBar alloc] initWithStyle:AUSearchBarStyleNormal];
        searchBar.searchTextField.placeholder = @"搜索栏样式(AUSearchBarStyleNormal)";
        searchBar.delegate = self;
        searchBar.isSupportHanziMode = YES;
        searchBar.shouldShowVoiceButton = YES;
        self.navigationItem.titleView = searchBar;
        
        self.navigationItem.leftBarButtonItem = nil;
        self.navigationItem.rightBarButtonItem = nil;
        self.navigationItem.hidesBackButton = YES;
        return;
    }
    // 搜索栏样式2
    else if (self.code == 2)  {
        AUSearchBar *searchBar = [[AUSearchBar alloc] initWithStyle:AUSearchBarStyleDetail];
        searchBar.searchTextField.placeholder = @"搜索栏样式(AUSearchBarStyleDetail)";
        searchBar.delegate = self;
        searchBar.isSupportHanziMode = YES;
        searchBar.shouldShowVoiceButton = YES;
        self.navigationItem.titleView = searchBar;
        
        self.navigationItem.leftBarButtonItem = nil;
        self.navigationItem.rightBarButtonItem = nil;
        self.navigationItem.hidesBackButton = YES;
        return;
    }
    
    {
        searchBar = [[AUSearchBar alloc] initWithStyle:AUSearchBarStyleNormal];
        searchBar.searchTextField.placeholder = @"搜索栏样式(AUSearchBarStyleNormal)";
        searchBar.delegate = self;
        searchBar.origin_mp = CGPointMake(0, self.topMargin);
        searchBar.isSupportHanziMode = YES;
        searchBar.shouldShowVoiceButton = YES;
        [self.view addSubview:searchBar];
    }
    
    {
        CGPoint point = CGPointMake(0, CGRectGetMaxY(searchBar.frame) + 10);
        searchBar = [[AUSearchBar alloc] initWithStyle:AUSearchBarStyleDetail];
        searchBar.searchTextField.placeholder = @"搜索栏样式(AUSearchBarStyleDetail)";
        searchBar.origin_mp = point;
        searchBar.delegate = self;
        searchBar.isSupportHanziMode = YES;
        searchBar.shouldShowVoiceButton = YES;
        searchBar.inputMaxLength = 4;
        [self.view addSubview:searchBar];
    }
    
    {
        CGPoint point = CGPointMake(0, CGRectGetMaxY(searchBar.frame) + 10);
        searchBar = [[AUSearchBar alloc] initWithStyle:AUSearchBarStyleNone];
        searchBar.searchTextField.placeholder = @"搜索栏样式(AUSearchBarStyleDetail)";
        searchBar.origin_mp = point;
        searchBar.delegate = self;
        searchBar.isSupportHanziMode = YES;
        searchBar.shouldShowVoiceButton = YES;
        searchBar.inputMaxLength = 4;
        [self.view addSubview:searchBar];
    }
    
    AUButton *btn = nil;
    {
        btn = [AUButton buttonWithStyle:AUButtonStyle1];
        btn.frame = CGRectMake(kDemoGlobalMargin, searchBar.bottom+50, AUCommonUIGetScreenWidth()-kDemoGlobalMargin*2, btn.height);
        btn.titleLabel.font = [UIFont systemFontOfSize:12];
        [btn setTitle:@"实例(AUSearchBarStyleNormal)" forState:UIControlStateNormal];
        [self.view addSubview:btn];
        
        __weak typeof(self) weakSelf = self;
        
//        [btn setAu_action:^{
//            
//            SearchBarDemoViewController *vc = [[SearchBarDemoViewController alloc] init];
//            vc.code = 1;
//            vc.title = weakSelf.title;
//            [weakSelf.navigationController pushViewController:vc animated:YES];
//        }];
        self.topMargin = btn.bottom + 10;
    }
    
    {
//        CGFloat y = CGRectGetMaxY(btn.frame) + 10;
        btn = [AUButton buttonWithStyle:AUButtonStyle1];
        btn.frame = CGRectMake(kDemoGlobalMargin, self.topMargin, AUCommonUIGetScreenWidth()-kDemoGlobalMargin*2, btn.height);
        [btn setTitle:@"实例(AUSearchBarStyleDetail)" forState:UIControlStateNormal];
        btn.titleLabel.font = [UIFont systemFontOfSize:12];
        [self.view addSubview:btn];
        
        __weak typeof(self) weakSelf = self;
//        [btn setAu_action:^{
//            SearchBarDemoViewController *vc = [[SearchBarDemoViewController alloc] init];
//            vc.code = 2;
//            vc.title = weakSelf.title;
//            [weakSelf.navigationController pushViewController:vc animated:YES];
//        }];
    }

}

#pragma mark - AUSearchBarDelegate

- (BOOL)searchBarTextShouldBeginEditing:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarTextShouldBeginEditing");
    return YES;
}

- (BOOL)searchBarTextShouldEndEditing:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarTextShouldEndEditing");
    return YES;
}

// called when text starts editing
- (void)searchBarTextDidBeginEditing:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarTextDidBeginEditing");
}

// called when text ends editing
- (void)searchBarTextDidEndEditing:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarTextDidEndEditing");
}

// called when text changes (including clear)
- (void)searchBar:(AUSearchBar *)searchBar textDidChange:(NSString *)searchText
{
    NSLog(@"textDidChange");
}

// called before text changes
- (BOOL)searchBar:(AUSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    NSLog(@"shouldChangeTextInRange");
    return YES;
}

// called when keyboard search button pressed
- (void)searchBarSearchButtonClicked:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarSearchButtonClicked");
}

- (void)searchBarCancelButtonClicked:(AUSearchBar *) searchBar
{
    NSLog(@"searchBarCancelButtonClicked");
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)searchBarBackButtonClicked:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarBackButtonClicked");
    [self.navigationController popViewControllerAnimated:YES];
}

- (BOOL)searchBarShouldClear:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarShouldClear");
    return YES;
}

- (void)searchBarOpenVoiceAssister:(AUSearchBar *)searchBar
{
    NSLog(@"searchBarOpenVoiceAssister");
    AUNoticeDialog *alert = [[AUNoticeDialog alloc] initWithTitle:@"点击了voiceButton" message:nil];
    [alert addButton:@"确定" actionBlock:nil];
    [alert show];
}



@end
