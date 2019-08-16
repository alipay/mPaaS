#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BannerView_AUBannerView//程序自动生成
//
//  AUBannerContentViewProtocol.h
//  AntUI
//
//  Created by maizhelun on 2017/7/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 AUBannerView Content的代理
 */
@protocol AUBannerContentDelegate <UIScrollViewDelegate>

- (void)didBeginDrag;
- (void)didEndDrag;
- (void)didScrollToPage:(NSInteger)pos;
- (void)didTapedAtPos:(NSInteger)pos;
- (UIView *)itemAtPos:(NSInteger)pos;
- (NSInteger)numberOfItems;

@end


/**
 AUBannerView Content需要实现的协议
 */
@protocol AUBannerContentProtocol <NSObject>

@property (nonatomic, assign)   NSInteger currentPage;
@property (nonatomic, assign)   UIEdgeInsets padding;
@property (nonatomic, weak)     id<AUBannerContentDelegate> contentDelegate;
- (NSIndexPath *)turnToPage:(NSUInteger)page animation:(BOOL)animation;
- (void)reloadView;

@end



/**
 AUBannerView子类可以继承的方法
 */
@protocol AUBannerViewSubClass <AUBannerContentDelegate>

- (CGSize)itemViewSize;

@end

#endif//程序自动生成
