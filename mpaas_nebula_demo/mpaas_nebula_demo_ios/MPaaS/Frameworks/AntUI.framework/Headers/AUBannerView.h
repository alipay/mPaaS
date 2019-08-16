#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BannerView_AUBannerView//程序自动生成
//
//  AUBannerView.h
//  AntUI
//
//  Created by maizhelun on 2017/6/26.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUPageControl.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aubannerview
//#########################################################


typedef NS_ENUM(NSUInteger, AUBannerStyle) {
    AUBannerStyleDeepColor, // 深色样式
    AUBannerStyleLightColor // 浅色样式
};

@interface AUBannerViewConfig : NSObject

@property (nonatomic, assign) AUBannerStyle                  style;                       // 默认的样式
@property (nonatomic, strong) UIColor                       *pageControlNormalColor;      // 默认色
@property (nonatomic, strong) UIColor                       *pageControlSelectedColor;    // 选中色
@property (nonatomic, assign) CGFloat                        pageControlMarginBottom;     // 分页标识距离底部的margin
@property (nonatomic, assign) BOOL                           pageControlDotTapEnabled;    // 分页标识圆点是否支持点击（默认为NO）
@property (nonatomic, assign) UIEdgeInsets                   contentViewMargin;           // 内容区边距
@property (nonatomic, assign) UIEdgeInsets                   contentViewPadding;          // 内容空白区，滚动时会经过该区域
@property (nonatomic, assign) BOOL                           autoTurn;                    // 自动轮播（默认YES）
@property (nonatomic, assign) BOOL                           autoStartTurn;               // 自动开始轮播
@property (nonatomic, assign) CGFloat                        duration;                    // 自动轮播间隔
@property (nonatomic, assign) BOOL                           neverAdjustContentInset;     // 对于隐藏导航栏后，将bannerview居顶的业务，需要设置该参数为YES，否则在iOS11的设备上面会向下偏差20个像素

@end


@class AUBannerView;
@protocol AUBannerViewDelegate <NSObject>

@required
- (NSInteger)numberOfItemsInBannerView:(AUBannerView *)bannerView;
- (UIView *)bannerView:(AUBannerView *)bannerView itemViewAtPos:(NSInteger)pos;

@optional
- (void)bannerView:(AUBannerView *)bannerView didTapedItemAtPos:(NSInteger)pos;
- (CGFloat)bannerView:(AUBannerView *)bannerView durationOfItemAtPos:(NSInteger)pos;
- (void)bannerView:(AUBannerView *)bannerView didExposureItemAtPos:(NSInteger)pos;
@end



@interface AUBannerView : UIView

AU_UNAVAILABLE_INIT

@property (nonatomic, readonly) UIView                  *contentView;   // 内容区视图
@property (nonatomic, readonly) AUPageControl           *pageControl;   // 分页标识视图

@property (nonatomic, copy)     NSString                *bizType;       // 业务标识
@property (nonatomic, assign)   NSInteger                currentPage;   // 当前页码（从0开始）
@property (nonatomic, weak)     id<AUBannerViewDelegate> delegate;      // 数据源和事件代理


/**
 创建banner视图

 @param frame frame
 @param bizType 业务标识（不能为空）
 @param configOperation 配置block
 @return banner视图
 */
- (instancetype)initWithFrame:(CGRect)frame
                      bizType:(NSString *)bizType
                   makeConfig:(void(^)(AUBannerViewConfig *config))configOperation;


/**
 开始自动轮播（如果autoStartTurn设置为NO，才需要调用这个方法）
 */
- (void)startTurning;


/**
 重新加载banner（数据源变更，需调用此方法重新加载数据）
 */
- (void)reloadData;

@end





//################################
//####### UIImage ################
//################################

@interface AUBannerView (Image)

/**
 创建图片的banner视图
 注意：需要保持imageURLs和actionURLs相等，否则创建失败

 @param frame frame
 @param bizType 业务标识（不能为空）
 @param images 图片集合（可为图片链接字符串，或者image对象）
 @param placeholder 图片占位图（UIImage对象）
 @param actionURLs 图片点击后的跳转链接（字符串，如果某张图不支持跳转，请设置[NSNull null]）
 @param configOperation banner视图的配置参数
 @return 轮播图片的banner视图
 */
+ (instancetype)bannerViewWithFrame:(CGRect)frame
                            bizType:(NSString *)bizType
                             images:(NSArray *)images
                        placeholder:(UIImage *)placeholder
                         actionURLs:(NSArray *)actionURLs
                         makeConfig:(void(^)(AUBannerViewConfig *config))configOperation;

@end




//################################
//####### Extension ##############
//################################


@interface AUBannerView (Extension)

/**
 更新bannerview配置
 会自动触发reload事件

 @param update update的block
 */
- (void)updateConfigOperation:(void(^)(AUBannerViewConfig *config))update;

@end



#endif//程序自动生成
