#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUBaseListItem+AcessorView.h
//  AntUI
//
//  Created by maizhelun on 2017/3/9.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUBaseListItem.h"

typedef NS_ENUM(NSInteger, AUListItemAccessoryType) {
    AUListItemAccessoryTypeNone = UITableViewCellAccessoryNone,// don't show any accessory view
    AUListItemAccessoryDisclosureIndicator = UITableViewCellAccessoryDisclosureIndicator,
    AUListItemAccessoryDisclosureIndicatorWhite,  //
    AUListItemAccessoryDetailDisclosureButton = UITableViewCellAccessoryDetailDisclosureButton,
    AUListItemAccessoryCheckmark = UITableViewCellAccessoryCheckmark, // checkmark. doesn't track
    AUListItemAccessoryDetailButton = UITableViewCellAccessoryDetailButton, // info button. tracks

    UITableViewCellAccessoryCheckmarkNotChecked = 10000, // Checkmark，但是是未选中状态. doesn't track
    UITableViewCellAccessorySwitch, // Switch. track
    UITableViewCellAccessoryActivityIndicatorWhite, // ActivityIndicator. track
    UITableViewCellAccessoryActivityIndicatorGray, // ActivityIndicator. track
};

@interface AUBaseListItem (AcessorView)

@property (nonatomic) AUListItemAccessoryType    accessoryType;

- (NSMutableDictionary *)accessorView_cache;

@end

#endif//程序自动生成
