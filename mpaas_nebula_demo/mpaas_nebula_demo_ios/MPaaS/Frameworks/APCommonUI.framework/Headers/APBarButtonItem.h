//
//  APBarButtonItem.h
//  APCommonUI
//
//  Created by WenBi on 13-12-8.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <AntUI/AUBarButtonItem.h>

@class APVisualStyle;

/**
 *  A bar button item is a button used for a <code>UIToolBar</code> or <code>APNavigationBar</code.
 */
__deprecated_msg("APBarButtonItem 已经废弃，请直接使用 AUBarButtonItem")
@interface APBarButtonItem : AUBarButtonItem //UIBarButtonItem

@property(nonatomic, strong) APVisualStyle *visualStyle NS_UNAVAILABLE;

@end
