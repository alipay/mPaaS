#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_FloatMenu_AUFloatMenu//程序自动生成
//
//  UIViewController+AUFloatMenu.h
//  WealthAccount
//
//  Created by 沫竹 on 2018/6/13.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBarButtonItem.h"


//__weak typeof(self) weakSelf = self;
//[self navBarRightItem_setMoreMenus:^(AUNavItemView *menuItem, NSInteger index, BOOL *hasNext) {
//    if (index == 1) {
//        menuItem.itemTitle = WAM_TEXT(@"帮助");
//        [menuItem setNomarlStateIconFontName:kICONFONT_HELP withSize:AUNavItemPreferedIconSize color:RGB(0x757575)];
//        menuItem.tapAction = ^{
//            [weakSelf gotoIntruction];
//        };
//        *hasNext = NO;
//    }
//    else {
//        menuItem.itemTitle = WAM_TEXT(@"提现免费额度");
//        [menuItem setNomarlStateIconFontName:kICONFONT_HELP withSize:AUNavItemPreferedIconSize color:RGB(0x757575)];
//        menuItem.tapAction = ^{
//            NSString *url = [freeCreditMenuConfig[@"url"] length] > 0 ?  freeCreditMenuConfig[@"url"] : @"alipays://platformapi/startapp?appId=60000010&url=%2Fwww%2Fquota_query%2Findex.htm";
//            BEEFee_OpenURL(url);
//        };
//        *hasNext = YES;
//    }
//}];
@interface UIViewController (AUFloatMenu)

- (AUBarButtonItem *)navBarRightItem_setMoreMenus:(void(^)(AUNavItemView *menuItem, NSInteger index, BOOL *hasNext))menuItemsConfig;

@end

#endif//程序自动生成
