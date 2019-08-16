//
//  H5WebViewController+TabBar.h
//  NebulaBiz
//
//  Created by Jianlei Wu on 9/27/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Nebula/Nebula.h>
#import "H5TabbarManager.h"
#import "H5TabBarItem.h"

/**
 H5WebViewController+TabBar.h
 */
@interface H5WebViewController (TabBar)<AUSearchTitleViewDelegate, AUSearchBarDelegate, TabBarProtocol>
@property (nonatomic) H5TabbarManager *tabBarManager;
@end
