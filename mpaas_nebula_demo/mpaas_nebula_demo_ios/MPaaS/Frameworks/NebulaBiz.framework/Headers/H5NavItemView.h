//
//  H5NavItemView.h
//  NebulaBiz
//
//  Created by Glance on 17/1/19.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>

@class H5NavItemView;

typedef void(^delayCallback)();

@protocol H5NavItemViewDelegate <NSObject>
- (void)onClicked:(H5NavItemView *)view;
@end

@interface H5NavItemView : AUNavItemView
@property(nonatomic, weak) id<H5NavItemViewDelegate> h5NavItemViewDelegate;
@property(nonatomic, copy) NSString *itemTag;

+ (NSArray<H5NavItemView *> *) itemsFromDataSource:(NSArray *)menus delegate:(id<H5NavItemViewDelegate>)delegate;

@end

