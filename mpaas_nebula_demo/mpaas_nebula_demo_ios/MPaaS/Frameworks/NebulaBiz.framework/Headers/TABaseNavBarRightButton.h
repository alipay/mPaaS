//
//  TANavBarRightButton.h
//  TinyappService
//
//  Created by 闻蹊 on 2018/5/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TABaseBarButtonItem.h"

@interface TABaseNavBarRightButton : UIView
{
    BOOL _isLight;
}
@property (nonatomic, strong) NSMutableDictionary *badgeAttributes;
@property (nonatomic, strong) NSMutableDictionary *badgeInfoDic;

- (void)changeColor:(BOOL)isLight;
// iOS11以下调整右侧关闭按钮的间距
+ (UIBarButtonItem *)spaceItemLowerThanIOS11;
@end
