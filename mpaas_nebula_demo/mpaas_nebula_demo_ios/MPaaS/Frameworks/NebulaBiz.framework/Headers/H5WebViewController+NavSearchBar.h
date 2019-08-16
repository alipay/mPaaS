//
//  H5WebViewController+NavSearchBar.h
//  NebulaBiz
//
//  Created by Glance on 16/12/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Nebula/Nebula.h>

@interface H5WebViewController (NavSearchBar)<AUSearchTitleViewDelegate,AUSearchBarDelegate>

// --------- searchNavigationBar
@property(nonatomic, readonly)   UIView *searchNavigationBar;
@property(nonatomic, readonly) AUSearchBar *searchBar;
@property(nonatomic, readonly) BOOL shouldCheckCreatedSearchBarAfterViewAppear;

- (BOOL)shouldCreateAndAdjustNavSearchBarBeforeAppear;
- (void)createAndAdjustNavSearchBarBeforeAppear;
- (void)setSearchNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated attributes:(NSDictionary<NSString *, id> *)attributes callback:(PSDJsApiResponseCallbackBlock) callback delegate:(id<AUSearchBarDelegate>)delegate;
- (void)setSearchNavigationBarAttributes:(NSDictionary<NSString *, id> *)attributes;
// searchNavigationBar --------- //

@end
