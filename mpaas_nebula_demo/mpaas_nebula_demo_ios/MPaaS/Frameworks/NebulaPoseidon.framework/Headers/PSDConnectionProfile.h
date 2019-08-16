//
//  PSDConnectionProfile.h
//  Poseidon
//
//  Created by chenwenhong on 14-10-14.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//访问路由
@interface PSDRouter : NSObject

@property(nonatomic, copy) NSString         *url;
@property(nonatomic, copy) NSString         *redirectUrl;
@property(nonatomic, assign) NSInteger      statusCode;
@property(nonatomic, weak) PSDRouter        *previousRouter;
@property(nonatomic, strong) PSDRouter      *nextRouter;
@property(nonatomic, weak) PSDRouter        *lastRouter;
@property(nonatomic, strong) NSDate         *startDate;
@property(nonatomic, strong) NSDate         *finishDate;

- (instancetype)initWithUrl:(NSString *)url statusCode:(NSInteger)statusCode redirectUrl:(NSString *)redirectUrl;

- (void)addRouter:(PSDRouter *)nextRouter;

@end

@interface PSDConnectionProfile : NSObject

@property(nonatomic, copy) NSString *channelId; // 通道ID
@property(nonatomic, strong) NSDate *startDate; // 请求发起时间
@property(nonatomic, strong) NSDate *firstByteDate; // 首字节时间
@property(nonatomic, strong) NSDate *lastByteDate; // 尾字时间
@property(nonatomic, strong) NSDate *finishLoadDate; // 完成时间

@property(nonatomic, assign) double reqStartTime;
@property(nonatomic, assign) double firstByteTime;
@property(nonatomic, assign) double lastByteTime;
@property(nonatomic, assign) double finishLoadTime;

@property(nonatomic, strong) NSMutableArray *requestURLs; // 请求的所有url
@property(nonatomic, strong) NSMutableArray *arrProfiles; // 请求的所有profile

@property(nonatomic, assign) int statusCode; // 当前statusCode，不会merge
@property(nonatomic, assign) int statusCode105Number; // 105个数
@property(nonatomic, assign) int statusCode302Number; // 302个数
@property(nonatomic, assign) int statusCode304Number; // 304个数
@property(nonatomic, assign) int statusCode300_399Number; // 300+个数（不包含304）
@property(nonatomic, assign) int statusCode404Number; // 404个数
@property(nonatomic, assign) int statusCode400_499Number; // 400+个数
@property(nonatomic, assign) int statusCode500_599Number; // 500+个数
@property(nonatomic, assign) int statusCode1000Number; // 1000个数

@property(nonatomic, assign) int htmlNumber; // html页面个数
@property(nonatomic, assign) int cssNumber; // css文件个数
@property(nonatomic, assign) int jsNumber; // js文件个数
@property(nonatomic, assign) int imageNumber; // 图片资源个数
@property(nonatomic, assign) int otherNumber; // 其他资源个数
@property(nonatomic, assign) int totalNumber; // 请求总数

@property(nonatomic, assign) float mainDocHtmlSize; // 主页面html大小
@property(nonatomic, assign) float htmlTotalSize; // html文档总大小
@property(nonatomic, assign) float cssTotalSize; // css总大小
@property(nonatomic, assign) float jsTotalSize; // js总大小
@property(nonatomic, assign) float imageTotalSize; // 图片总大小
@property(nonatomic, assign) float otherTotalSize; // 其他资源总大小
@property(nonatomic, assign) float totalSize; // 总大小

@property(nonatomic, assign) int resourceSize50kNumber; // 资源大于50K的个数
@property(nonatomic, assign) int resourceSize200kNumber; // 资源大于200K的个数
@property(nonatomic, assign) int syncAjaxNumber; // 同步ajax请求个数

@property(nonatomic, assign) int imageSize60kNumber; // 图片大于60K的个数
@property(nonatomic, strong) NSMutableArray *imageSize60kUrls; // 图片超60k的urls
@property(nonatomic, strong) NSMutableArray *resourceSize200kUrls; // 资源超200k的urls

@property(nonatomic, assign) BOOL       isXHR;
@property(nonatomic, assign) BOOL       isMainDoc;
@property(nonatomic, strong) PSDRouter  *router;
@property(nonatomic, strong) NSString   *gzip;
@property(nonatomic, strong) NSString   *contentType;

@property(nonatomic, strong) NSDictionary *netInfo; // 网络链路埋点
@property (nonatomic, assign) BOOL isLocal;             //通过X-LocalRes判断是否为离线请求

- (void)reset; // 重置

- (void)merge:(PSDConnectionProfile *)profile; // 除了startDate，startTime，status

- (void)printProfile;

@end
