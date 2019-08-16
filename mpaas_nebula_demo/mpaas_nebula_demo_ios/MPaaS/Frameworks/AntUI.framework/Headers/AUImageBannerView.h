#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BannerView_AUBannerView//程序自动生成
//
//  AUImageBannerView.h
//  AntUI
//
//  Created by maizhelun on 2017/7/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>
#import "AUBannerContentProtocol.h"
#import "AUIImageView.h"
#import "AUBannerView.h"

typedef void(^BannerImageBindOperation)(AUIImageView *imageView, NSString *imageURL, NSInteger pos);


@interface AUImageBannerView : AUBannerView

@property (nonatomic, strong) NSArray   *actionUrls;
@property (nonatomic, strong) NSArray   *images;
@property (nonatomic, strong) UIImage   *placeholder;


/**
 设置这个可以替换掉默认的图片加载方式

 @param operation 自定义图片加载方式的block回调
 */
- (void)setImageBindOperation:(BannerImageBindOperation)operation;

@end

#endif//程序自动生成
