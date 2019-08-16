#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BannerView_AUBannerView//程序自动生成
//
//  AUBannerCollectionView.h
//  AntUI
//
//  Created by maizhelun on 2017/7/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUCollectionView.h"
#import "AUBannerContentProtocol.h"

@interface AUBannerCollectionView : AUCollectionView <AUBannerContentProtocol>

@property (nonatomic, assign)   NSInteger currentPage;
@property (nonatomic, assign)   UIEdgeInsets padding;
@property (nonatomic, weak)     id<AUBannerContentDelegate> contentDelegate;

@end

#endif//程序自动生成
