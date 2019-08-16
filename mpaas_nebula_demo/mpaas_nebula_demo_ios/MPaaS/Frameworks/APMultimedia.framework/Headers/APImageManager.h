//
//  APImageManager.h
//  APMultimedia
//
//  Created by Wang Yuanqiu on 15/3/31.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "APMMConst.h"
#import "APImageRequest.h"
#import <Photos/Photos.h>
#import "APBaseUploadRequest.h"

@class CLLocation;

/**
 * 上传下载状态
 */
typedef enum : NSUInteger {
    Download_Waiting = 0,                  //等待执行
    Download_Running = 1,                  //正在执行
    Download_Cancel = 2,                   //取消执行
    Download_Fail = 3,                     //执行失败
    Download_Success = 4,                  //执行成功
    Download_TaskRecord_NotFound = 5                   //仅用于查询状态进度时找不到taskRecord时返回
} ImageDownloadStatus;

/**
 * iCloud同步状态
 */
typedef enum : NSUInteger {
    APiCloudStateUnknown = 0,                  //iCloud同步状态未知
    APiCloudStateDownloading = 1,                  //iCloud同步中
    APiCloudStateDownloadSuccess = 2,             //iCloud同步成功
    APiCloudStateDownloadFailed = 3               //iCloud同步失败
}APiCloudDownloadStatus;

//图片压缩等级
typedef enum : NSUInteger {
    ImageCompressQualityLow,    //低质量压缩 压缩比最大
    ImageCompressQualityMid,    //中质量压缩 压缩比中等
    ImageCompressQualityHigh,   //高质量压缩 压缩比最小
    ImageCompressNone,          //不压缩
    ImagecompressDefault,       //默认压缩，根据网络情况进行低、中、高进行压缩
} ImageCompressQualityLevelEnum;

//超长/宽图的智能裁剪
typedef enum : NSUInteger {
    ImageSmartCutOpen,          //智能裁剪开启
    ImageSmartCutClose,         //智能裁剪关闭
} ImageSmartCutEnum;

//单个文件
@class APImageUploadResponse;
typedef void (^APImageUploadCompletion)(NSString *identifier, NSError *error);
typedef void (^APImageUploadRequestCompletion)(APImageUploadResponse *response);
typedef void (^APImageRequestCompletion)(UIImage *image, NSError *error);
typedef APImageRequestCompletion APImageDownloadCompletion;
typedef APImageRequestCompletion APImageThumbnailCompletion;
typedef void (^APImageDownloadWithIdCompletion)(NSString *identifier, UIImage *image,  NSError *error);

/**
 *  批量上传状态回调
 *
 *  @param APBatchUpImageRecord array 上传对应成功或失败的结果
 *  @param error 错误信息
 */
typedef void (^APBatchImageUploadCompletion)(NSArray *apBatchUpImageRecords, NSError *error);
typedef void (^APStoreImageToPhotoCompleteHandler)(NSString *assetURLString, NSError *error);

@interface APBatchUpImageRecord : NSObject
@property (nonatomic, strong) NSString *localId;
@property (nonatomic, strong) NSString *cloudId;
@property (nonatomic, strong) NSURL *url;
@property (nonatomic, assign) BOOL isOriginal;
@property (nonatomic, strong) NSError *error;
/**
 上传到服务器端文件长度
 */
@property (nonatomic, assign)NSUInteger fileSize;

/**
 对于部分业务 gif上传动态图会生成动态图cloudid+首帧图cloud ID，此处为首帧图id
 */
@property (nonatomic,copy) NSString* thumbnailIdForGif;

@end

typedef NS_ENUM(NSUInteger, APGifOption) {
    APGifOptionAlwaysThumbnail,// 无论什么压缩级别，始终上传首帧图
    APGifOptionAlwaysAnimatedImage, //无论什么压缩级别，始终上传动态图
    APGifOptionAnimatedImageWhenCompressNone //当不压缩的时候 上传动态图，否则上传首帧图
};

@interface APImageUploadRequest : APBaseUploadRequest <NSCopying>

/**
 压缩级别
 */
@property (nonatomic, assign) ImageCompressQualityLevelEnum compress;


/**
 上传完成后的回调，只有在上传成功后才会回调，生成local ID的接口不会回调
 */
@property (nonatomic, copy) APImageUploadRequestCompletion complete;

/**
 上传的图片是否到公有域，默认值为NO，如果需要在钱包(支付宝)外访问的该图片的场景(不需要鉴权），可以考虑设置此值
 */
@property (nonatomic, assign) BOOL isPublic;


/**
 上传之前会对待已经压缩的数据进行编码，转化成其他的格式，比如webp/heif上传到服务器端，节省流量和耗时。
 */
@property (nonatomic, assign) BOOL enableOptimizeNetworkTraffic;



#pragma mark - GIF

@property (nonatomic, assign) BOOL thumbnailWithGifWhenCompressNone DEPRECATED_MSG_ATTRIBUTE("this property deprecated, please use gifOption instead");


@property (nonatomic, assign) APGifOption gifOption;

/**
 是否为gif生成首帧图id，默认为NO。
 */
@property (nonatomic, assign) BOOL generateThumbnailForGif;


#pragma mark - 保险箱
/**
 额外的参数 只识别已经定义APRequestExtraParamKey.h中的kExtraParams* key
 */
@property (nonatomic, copy) NSDictionary* extraParams;


- (BOOL)isValid;

@end

@interface APImageUploadResponse : NSObject 
@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, copy) NSString* publicUrl;
/**
 上传到服务器端文件长度
 */
@property (nonatomic, assign)NSUInteger fileSize;

/**
 对于部分业务 gif上传动态图会生成动态图cloudid+首帧图cloud ID，此处为首帧图id
 */
@property (nonatomic,copy) NSString* thumbnailIdForGif;

- (instancetype)initWithError:(NSError *)error;
- (instancetype)initWithIdentifier:(NSString *)identifier error:(NSError *)error isPublic:(BOOL)isPublic;

- (instancetype)initWithIdentifier:(NSString *)identifier error:(NSError *)error isPublic:(BOOL)isPublic userInfo:(NSDictionary *)userInfo;
@end

@interface APImageManager : NSObject

+ (instancetype)manager;


#pragma mark - upload
/**
 *  图片上传
 *
 *  @param filePath 图片本地沙盒全路径
 *  @param business 业务存储标识
 *  @param compress 压缩等级
 *  @param progress 上传进度百分比
 *  @param complete 完成
 *
 *  @return 立即返回任务对象，可用于取消
 */
- (NSString *)uploadWithImage:(UIImage *)image
                     business:(NSString *)business
                     compress:(ImageCompressQualityLevelEnum)compress
                     progress:(APMMProcessiveBlock)progress
                   completion:(APImageUploadCompletion)complete;
- (NSString *)uploadWithImage:(UIImage *)image request:(APImageUploadRequest *)uploadRequest;

- (NSString *)uploadWithImageData:(NSData *)imageData
                     business:(NSString *)business
                     compress:(ImageCompressQualityLevelEnum)compress
                     progress:(APMMProcessiveBlock)progress
                   completion:(APImageUploadCompletion)complete;
- (NSString *)uploadWithImageData:(NSData *)imageData request:(APImageUploadRequest *)uploadRequest;

- (NSString *)uploadWithALAsset:(ALAsset *)asset
                       business:(NSString *)business
                       compress:(ImageCompressQualityLevelEnum)compress
                       progress:(APMMProcessiveBlock)progress
                     completion:(APImageUploadCompletion)complete;
- (NSString *)uploadWithALAsset:(ALAsset *)asset request:(APImageUploadRequest *)uploadRequest;

- (NSString *)uploadRetryWithLocalId:(NSString *)localId
                            business:(NSString *)business
                            progress:(APMMProcessiveBlock)progress
                          completion:(APImageUploadCompletion)complete;

/**
 根据local ID上传

 @param localId localID
 @param uploadRequest 上传参数。 compress和isPublic参数以生成localID的设置为准
 @return local ID
 */
- (NSString *)uploadRetryWithLocalId:(NSString *)localId request:(APImageUploadRequest *)uploadRequest;

/**
 *  通过UIImage得到其localId，下次上传可直接使用此ID
 *
 *  @param image
 *  @compressLevel  压缩等级，低、中、不压缩
 *
 *  @return localId
 */
- (NSString*)getLocalIdWithImage:(UIImage*)image compressLevel:(ImageCompressQualityLevelEnum)level;

/**
 根据上传参数和图片生成local ID

 @param image 图片
 @param request 上传的参数， 无需设置block
 @return local ID
 */
- (NSString *)getLocalIdWithImage:(UIImage*)image request:(APImageUploadRequest*)request;

/**
 *  通过ALAsset或者PHAsset得到其localId，下次上传可直接使用此ID 此方法对于比较大的图片 耗时比较高，不建议在主线程使用。
 *
 *  @param asset         ALAsset或者PHAsset
 *  @param compressLevel 压缩等级，低、中、不压缩
 *
 *  @return localId
 */
- (NSString*)getLocalIdWithAsset:(id)asset compressLevel:(ImageCompressQualityLevelEnum)compressLevel;


/**
  根据上传参数和ALAseet或者PHAsset生成local ID

 @param asset ALAsset或者PHAsset
 @param request 上传的参数， 无需设置block
 @return local ID
 */
- (NSString *)getLocalIdWithAsset:(id)asset request:(APImageUploadRequest *)request;

- (NSString *)getLocalIdWithImageData:(NSData *)imageData request:(APImageUploadRequest *)request;

/**
 *  通过UIImage得到其localId，下次上传可直接使用此ID
 *
 *  @param image    image description
 *  @param compress compress description
 *
 *  @return return localId
 */
- (NSString*)getLocalIdWithImage:(UIImage*)image compress:(BOOL)compress;


/**
 *  根据localId获取到图片压缩级别
 *
 *  @param localId  图片localId
 *
 *  @return 图片压缩级别
 */
- (ImageCompressQualityLevelEnum)getCompressLevelFromLocalId:(NSString *)localId;

/**
 * 获取iCloud同步的状态
 */
- (APiCloudDownloadStatus)getiCloudStatusWithLocalID:(NSString*)localID;

/**
 * 获取iCloud同步的进度
 * 进度区间[-1,100],返回-1，表示当前无法获取iCloud同步进度
 */
- (double)getiCloudProgressWithLocalID:(NSString*)localID;

/**
 * 根据localID注册iCloud相关的状态，进度回调
 * attention:回调不保证在主线程回调，如需要主线程操作，调用方保证切至主线程。
 */
-(void)registeriCloudStatusHandler:(void(^)(APiCloudDownloadStatus status))icloudStatus progressHandler:(APMMProcessiveBlock)iCloudProgress forLocalID:(NSString*)localID;

#pragma mark - download

/**
 * 支持DJANGO图片下载，以及外部url图片下载，主线程返回回调
 * 指定缩略图大小，取回云端图片
 * django图片下载
 * 1 originalSize 为0时，将原图下载
 * 2 zoom 为0时，将大图下载
 * 3 originalSize和zoom的宽高比不是一样的（两者的差的绝对值小于0.001）话将缩放下载
 * 4 否则将等比按照zoom的宽高下载
 */
- (NSString *)getImage:(NSString *)identifier
              business:(NSString *)business
                  zoom:(CGSize)size
          originalSize:(CGSize)size
              progress:(APMMProcessiveBlock)progress
            completion:(APImageDownloadCompletion)complete;

/*
 * 支持DJANGO图片下载，以及外部url图片下载，主线程返回回调
 *
 */
- (NSString *)getImage:(NSString *)identifier
              business:(NSString *)business
                  zoom:(CGSize)size
          originalSize:(CGSize)size
              progress:(APMMProcessiveBlock)progress
      withIdCompletion:(APImageDownloadWithIdCompletion)complete;

/**
 * 支持DJANGO图片下载，以及外部url图片下载,主线程返回回调
 * 指定缩略图大小，取回云端图片
 * 按照zoom的size等比压缩尺寸下载
 *
 */
- (NSString *)getImage:(NSString *)identifier
              business:(NSString *)business
                  zoom:(CGSize)size
              progress:(APMMProcessiveBlock)progress
            completion:(APImageDownloadCompletion)complete;

/**
 * 指定缩略图大小，取回本地上传的图片
 * zoom size为0将获取大图，其余将获取小图,
 * 大图存在小图不存在的情况会裁剪出小图
 */
- (void)getImageWithUploadLocalId:(NSString *)LocalId zoom:(CGSize)size completion:(APImageDownloadCompletion)complete;

- (void)getImageWithUploadLocalId:(NSString *)localId zoom:(CGSize)size withIdCompletion:(APImageDownloadWithIdCompletion)complete;


/**
 *  支持DJANGO图片下载，以及外部url图片下载 (仅DJango图片支持不同Q值下载)
 *
 *  @param param    APImageRequestParam
 *  @param progress
 *  @param complete 下载完成回调，主线程返回
 *
 *  @return
 */
- (NSString *)getImage:(NSString*)identifier
               request:(APImageRequest*)request;

#pragma mark - cancel

/**
 * 取消上传任务
 */
- (BOOL)cancelTaskWithLocalId:(NSString*)localId;

/**
 * 取消批量上传任务
 * param localIds: NSString or APBatchUpImageRecord object Array
 */
- (void)cancelTaskWithLocalIds:(NSArray*)localIds;

/**
 * 取消下载任务
 */
- (BOOL)cancelGetImage:(NSString*)identifier zoom:(CGSize)size
          originalSize:(CGSize)originalSize;


#pragma mark - batch

/**
 *  通过array获取批量的id
 *  @param assetArray  asset Array
 *  @param imageSize 为了提升渲染性能，可预先裁剪一批指定size的图片,用于渲染图片
 *  @param compressLevel 压缩等级，低、中、不压缩
 *
 *  @return APBatchUpImageRecord array
 */
- (NSArray*)getLocalIdsWithArray:(NSArray *)assetArray size:(CGSize)size compressLevel:(ImageCompressQualityLevelEnum)compressLevel;



/**
 *  批量上传图片
 *
 *  @param array    图片AlAsset的Array, localId or APBatchUpImageRecord
 *  @param compress 是否压缩
 *  @param progress 单个图片上传进度
 *  @param complete 批量上传完成block
 */

- (void)batchUploadImageWithLocalIds:(NSArray*)localIds
                            business:(NSString *)business
                          completion:(APBatchImageUploadCompletion)complete;

- (void)batchUploadImageWithLocalIds:(NSArray*)localIds
                              request:(APImageUploadRequest *)request
                          completion:(APBatchImageUploadCompletion)complete;





#pragma mark - cache

/*!
   根据identifier获取图片缓存 identifier可以为CloudID/LocalID/外部url（http、https）
 
 --------*******-----
 同步获取缓存接口，在主线程调用可能存在卡顿，建议使用异步接口获取。如果一定要在主线程使用推荐用法： 先调用isImageCacheExsit接口判断cache存在，存在则可以调用同步接口。不存在则需要通过异步的方式解决。
 ----*******-----
 
   针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
   1、originalSize为CGSizeZero，表示原图
   2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
   3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

   @param identifier identifier 或者 外部url（http、https）
   @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果identifier参数为外部url类型的话，可穿任意size，建议CGSizeZero
   @param originalSize 原图size 取原图，请传CGSizeZero；如果identifier参数为外部url类型的话，可穿任意size，建议CGSizeZero
   @return 返回UIImage对象
 */
- (UIImage *)getImageCacheForIdentifier:(NSString *)identifier size:(CGSize)size originalSize:(CGSize)originalSize;

/**
 *  根据request同步获取图片缓存
 *   --------*******-----
     同步获取缓存接口，在主线程调用可能存在卡顿，建议使用异步接口获取。如果一定要在主线程使用推荐用法： 先调用isImageCacheExsit接口判断cache存在，存在则可以调用同步接口。不存在则需要通过异步的方式解决。
 *   ----*******-----
 *  @param identifier cloudId、url等
 *  @param request    APImageRequest
 *
 *  @return APImageDownloadResponse
 */
- (APImageDownloadResponse *)syncGetImageCacheForIdentifier:(NSString*)identifier request:(APImageRequest*)request;

/**
 *  根据identifier获取图片缓存 identifier可以为CloudID/LocalID/外部url（http、https）

 *  针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param cloudId cloudID 或者 外部url（http、https）
 *  @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param originalSize 原图size 取原图，请传CGSizeZero；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param complete 回调，返回identifier UIImage error
 */
- (void)getImageCacheForIdentifier:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize complete:(APImageDownloadWithIdCompletion)complete;

/**
 *  根据request异步获取图片缓存
 *
 *  @param identifier cloudId、url等
 *  @param request    APImageRequest
 */
- (void)asyncGetImageCacheForIdentifier:(NSString*)identifier request:(APImageRequest*)request;

/**
 *  根据identifier获取图片缓存的NSData数据 identifier可以为CloudID/LocalID/外部url（http、https）

 *   --------*******-----
 同步获取缓存接口，在主线程调用可能存在卡顿，建议使用异步接口获取。如果一定要在主线程使用推荐用法： 先调用isImageCacheExsit接口判断cache存在，存在则可以调用同步接口。不存在则需要通过异步的方式解决。
 *   ----*******-----
 
 *  针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param identifier identifier 或者 外部url（http、https）
 *  @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果identifier参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param originalSize 原图size 取原图，请传CGSizeZero；如果identifier参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *
 *  @return 图片缓存的NSData数据
 */
- (NSData *)getImageCacheDataForIdentifier:(NSString *)identifier size:(CGSize)size originalSize:(CGSize)originalSize;

/**
 *  删除指定identifier的所有缓存文件，包括内存缓存和disk缓存
 *
 *  @param identifier 图片localId or cloudId or 外部图片url（http/https）
 */
- (void)clearCacheForIdentifier:(NSString *)identifier;

/**
 *  给一个外部url（http/https链接)，获取该url对应的原图在cache中的绝对路径
 *  目前主要提供给首页性能优化使用。
 *  不支持DJANGO ID
 *
 *  @param url 外部url（http/https链接)
 *
 *  @return url对应图片原图缓存文件的绝对路径，注意：该路径对应的文件可能不存在，调用方需要自己做校验。
 */
+ (NSString*)getOriginalImageFilePathWithUrl:(NSString*)url;

/**
 *  查询图片缓存是否存在，首先从内存缓存中查找，找不到再去diskCache中查找
 *  Django图片支持缩略图，大图，原图查找

 *  针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param identifier   CloudID or LocalID or URL(http/https)
 *  @param size         图片大小，针对Django图片查询大图传CGSizeZero;外部url图片，可传任意size
 *  @param originalSize 原图大小，针对Django图片查询原图传CGSizeZero;外部url图片，可传任意size
 *
 *  @return 在cache中查找到则返回YES，否则返回NO
 */
- (BOOL)isImageCacheExsitFor:(NSString*)identifier size:(CGSize)size originalSize:(CGSize)originalSize;

/**
 查询图片缓存是否存在，首先从内存缓存中查找，找不到再去diskCache中查找

 @param identifier CloudID or LocalID or URL(http/https)
 @param request APImageRequest
 @return 缓存是否存在
 */
- (BOOL)isImageCacheExsitFor:(NSString*)identifier request:(APImageRequest*)request;


/**
  根据identifier获取图片缓存的位置，不建议主线程使用，无特殊用途，不建议业务方直接使用该接口获取图片路径，建议使用其他接口直接获取UIImage对象

 @param identifier localID cloud ID 或者url
 @param request image request 请求
 @return 如果缓存存在，返回缓存的绝对路径，否则为nil
 */
- (NSString *)cachePathWithIdentifier:(NSString*)identifier request:(APImageRequest*)request;

/**
 *  存储图片到缓存中， 同步方法 可能耗时比较长，不要在主线程调用
 *
 *  @param image      需要缓存的图片
 *  @param identifier identifier identifier可以为CloudID/LocalID/外部url,存储到缓存中后，可以根据这个identifier从缓存中获取存储的image
 *  @param request    APImageRequest
 *
 *  @return 是否存储成功
 */
- (BOOL)storeImageIntoCache:(UIImage *)image withIdentifier:(NSString *)identifier imageRequest:(APImageRequest *)request;

#pragma mark 查询图片下载状态，进度

/**
 *  该接口只支持图片下载的状态查询
 *  由cloudid size originalSize来计算一个key，用于任务管理器中查找下载任务，如果找到，则返回当前的taskRecord的状态。
 *  找不到则查询下cache中是否已存在，如果cache中已经存在，返回Download_Success。
 *  默认返回Download_TaskRecord_NotFound
 *
 *  根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图
 *  @param cloudId      Django CloudID，不支持LocalID和外部url
 *  @param size         图片大小 大图传CGSizeZero,此时originalSize不能传CGSizeZero
 *  @param originalSize 原图大小 原图传CGSizeZero
 *
 *  @return 当前图片的下载状态
 */
- (ImageDownloadStatus)getStatusOfCloudID:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize;

- (ImageDownloadStatus)getStatusOfCloudID:(NSString *)cloudId request:(APImageRequest *)request;

/**
 *  该接口只支持图片下载的进度查询
 *  由cloudid size originalSize来计算一个key，用于任务管理器中查找下载任务，如果找到，则返回当前的taskRecord的进度。
 *  找不到则查询下cache中是否已存在，如果cache中已经存在，返回100.0。
 *  默认返回0.0

 *  根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param cloudId      Django CloudID，不支持LocalID和外部url
 *  @param size         图片大小 大图传CGSizeZero,此时originalSize不能传CGSizeZero
 *  @param originalSize 原图大小 原图传CGSizeZero
 *
 *  @return 当前图片的下载进度
 */
- (double)getProgressOfCloudID:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize;

- (double)getProgressOfCloudID:(NSString *)cloudId request:(APImageRequest *)request;

#pragma mark 存储图片到系统相册

/**
 *  存储图片到系统相册
 *  针对DjangoID的图片，支持大图，原图，或者根据size和originalSize计算出来的一个等比或者非等比（裁切）的图
 *  针对外部url（http/https）图片，目前只支持原图存储
 *  @param identifier   DjanogId 或者外部url（http/https）
 *  @param size         图片大小，针对DjangoID，存大图传CGSizeZero；外部url图片可任意传
 *  @param originalSize 原图大小，针对DjangoID，存原图传CGSizeZero；外部url图片可任意传
 *  @param complete     存储完回调，不保证在主线程执行
 */
- (void)storeImageToPhotoWithIdentifier:(NSString*)identifier size:(CGSize)size originalSize:(CGSize)originalSize
                               complete:(APStoreImageToPhotoCompleteHandler)complete;

/**
 *  存储图片到系统相册
 *
 *  @param image    要存储的图片
 *  @param complete 存储完回调,不保证在主线程执行
 */
- (void)storeImageToPhotoAblum:(UIImage *)image complete:(APStoreImageToPhotoCompleteHandler)complete;

#pragma mark - Utils

/**
 *  解析外部url，对于tfs上存储的图片，url中可能含有占位符，该方法会处理占位符以获取真实请求的url，其中替换后的size会乘以屏幕的scale
 *
 *  @param urlString 外部url的字符串
 *  @param size      请求图片的大小,业务不需要乘以scale
 *
 *  @return 返回解析之后的图片url地址，如果不含占位符，直接返回原始url
 *          如果有占位符，会根据传入的size，将url转成离请求最接近的url
 */
- (NSString *)resolveImageUrlString:(NSString *)urlString size:(CGSize)size;

/**
 *  给外部的url增加business占位符，如果用返回后的url去下载图片，business是以此存储的，而不是getImage接口中的
 *
 *  @param business  此url对应的图片在存储是附带的business类型
 *  @param urlString 图片的url
 *
 *  @return 增加business占位符之后的url，以其作为key与原始的urlString作为key，访问的是同一个对象
 */
- (NSString *)addBusiness:(NSString *)business toUrlString:(NSString *)urlString;

/**
 *  传入图片的cloudid， 生成临时访问的url(H5使用)
 *  文档说明参考：http://idoc.alipay.net/longfei.ylf/Multimedia-SDK-doc/jsapi/image/buildUrl.html
 *  AlipayJSBridge.call('buildUrl', {
 *      'id': 'xxxxx', //  图片cloudid
 *      'width': 100, //期待的宽
 *      'height': 100, //期待的高
 *      ‘match’: 0， //缩放模式， 0： 等比缩放， 1： 居中裁切
 *      'quality': 80 //图片质量, 取值（1-100），负值表示不启用
 *  }, function (result) {
 *      console.log(result.url);
 *  });
 *
 *  @param request 请求的参数，见上方注释
 *
 *  @return 返回生成的url
 */
- (NSString *)buildUrl:(NSDictionary *)request;


/**
 将url收敛到另外一个域名下的url

 @param urlStr 被收敛的url
 @return 如果urlStr支持域名收敛，则返回域名收敛后的url，否则返回urlStr
 */
+ (NSString *)convergeDomainWithUrl:(NSString *)urlStr;

#pragma mark - CLLocation

/**
 *  获取UIImage，PHAsset或者ALAsset中地理位置信息，UIImage只支持通过APVideoRecord takePicture方法获取的UIImage对象
 *
 *  @param image  UIImage，ALAsset或者PHAsset对象
 *
 *  @return CLLocation 地理位置信息
 */
- (CLLocation *)locationFromImage:(id)image;

@end

#pragma mark - 水印
@interface APImageManager (WaterMark)

- (NSString *)generalKeyForGetWaterWithId:(NSString *)identifier
                                 sourceId:(NSString *)sourceId
                                     zoom:(CGSize)size
                                 position:(NSUInteger)position
                             transparency:(NSUInteger)transparency
                                    width:(NSUInteger)width
                                   height:(NSUInteger)height
                                     xgap:(NSUInteger)xgap
                                     ygap:(NSUInteger)ygap;

/**
 *  水印缩略图下载
 *
 *  @param identifier   需要加水印的原图文件 ID
 *  @param business     业务存储标识
 *  @param sourceId     水印来源图文件ID
 *  @param size         按照zoom的size等比压缩尺寸下载（不可为0，0）
 *  @param position     水印位置，参考以下九宫格方位，[1-9]，默认值：5
 
 *   1左上    2中上    3右上
 *   4左中    5中部    6右中
 *   7左下    8中下    9右下
 
 *  @param transparency 水印来源图透明度，(0,100]，如果设为100则不透明
 *  @param width        水印来源图宽，(0,200]  由于服务端压力 后续该参数会变更为枚举值2个 即指定值如
 *  @param height       水印来源图高，(0,200]
 *  @param xgap         水平边距, 距离图片边缘的水平距离，单位像素， 这个参数只有当水印位置是左上，左中，左下， 右上，右中，右下才有意义，取值范围：[0,4096]
 *  @param ygap         垂直边距, 距离图片边缘的垂直距离，单位像素， 这个参数只有当水印位置是左上，中上， 右上，左下，中下，右下才有意义，取值范围：[0,4096]
 *  @param P            对当前水印来源图进行按主图的比例缩放，如10表示基于主图的10%进行处理，比如主图尺寸为1000x1000，则P=10表示把水印来源图缩放成100x100,取值范围(0,100]
 *  @param progress     进度回调
 *  @param complete     完成回调
 *  @return 同步返回任务对象，可用于取消
 */
- (NSString *)getWaterMarkImageWithId:(NSString *)identifier
                             business:(NSString *)business
                             sourceId:(NSString *)sourceId
                                 zoom:(CGSize)size
                             position:(NSUInteger)position
                         transparency:(NSUInteger)transparency
                                width:(NSUInteger)width
                               height:(NSUInteger)height
                                 xgap:(NSUInteger)xgap
                                 ygap:(NSUInteger)ygap
                                    p:(NSUInteger)p
                             progress:(APMMProcessiveBlock)progress
                     withIdCompletion:(APImageDownloadWithIdCompletion)complete;

/**
 *  添加图片水印接口，对已有CloudId图片增加水印sourceId
 *
 *  @param identifier   需要加水印的原图文件 ID
 *  @param sourceId     水印来源图文件ID
 *  @param size         按照zoom的size等比压缩尺寸下载（不可为0，0）
 *  @param position     水印位置，参考以下九宫格方位，[1-9]，默认值：5
 
 *   1左上    2中上    3右上
 *   4左中    5中部    6右中
 *   7左下    8中下    9右下
 
 *  @param transparency 水印来源图透明度，(0,100]，如果设为100则不透明
 *  @param width        水印来源图宽，(0,200]  由于服务端压力 后续该参数会变更为枚举值2个 即指定值如
 *  @param height       水印来源图高，(0,200]
 *  @param xgap         水平边距, 距离图片边缘的水平距离，单位像素， 这个参数只有当水印位置是左上，左中，左下， 右上，右中，右下才有意义，取值范围：[0,4096]
 *  @param ygap         垂直边距, 距离图片边缘的垂直距离，单位像素， 这个参数只有当水印位置是左上，中上， 右上，左下，中下，右下才有意义，取值范围：[0,4096]
 *  @param P            对当前水印来源图进行按主图的比例缩放，如10表示基于主图的10%进行处理，比如主图尺寸为1000x1000，则P=10表示把水印来源图缩放成100x100,取值范围(0,100]
 *  @param progress     进度回调
 *  @param complete     完成回调
 *  @return 同步返回任务对象，可用于取消
 */
- (NSString *)generalWaterMarkImageWithId:(NSString *)identifier
                                 sourceId:(NSString *)sourceId
                                     zoom:(CGSize)size
                                 position:(NSUInteger)position
                             transparency:(NSUInteger)transparency
                                    width:(NSUInteger)width
                                   height:(NSUInteger)height
                                     xgap:(NSUInteger)xgap
                                     ygap:(NSUInteger)ygap
                                        p:(NSUInteger)p
                                 progress:(APMMProcessiveBlock)progress
                               completion:(APImageUploadCompletion)complete;


/**
 *  取消水印下载
 *
 *  @param key
 *
 *  @return YES 成功，NO 失败
 */
- (BOOL)cancelGetWaterMarkImage:(NSString*)key;

@end

#pragma mark - 缩略图
@interface APImageManager (Thumbnail)

/**
 * 缩放并压缩图片尺寸
 */
- (UIImage *)thumbnailWithFilePath:(NSString *)filePath
                              zoom:(CGSize)size
                          smartCut:(ImageSmartCutEnum)cut;

- (UIImage *)thumbnailWithImage:(UIImage *)image
                           zoom:(CGSize)size
                       smartCut:(ImageSmartCutEnum)cut;

- (UIImage *)thumbnailWithALAsset:(ALAsset *)asset
                             zoom:(CGSize)size
                         smartCut:(ImageSmartCutEnum)cut;

/**
 * 支持从ALAsset获取缩略图
 */
- (UIImage *)thumbnailWithAsset:(ALAsset*)asset
                           zoom:(CGSize)size
                       smartCut:(ImageSmartCutEnum)cut;

/**
 * 支持从ALAsset和PHAsset获取缩略图，PHAsset支持从iCloud下载
 */
- (void)thumbnailWithAsset:(id)asset
                      zoom:(CGSize)size
                  smartCut:(ImageSmartCutEnum)cut
                  progress:(APMMProcessiveBlock)progress
                  complete:(APImageThumbnailCompletion)complete;

- (UIImage *)thumbnailWithData:(NSData *)data
                          zoom:(CGSize)size
                      smartCut:(ImageSmartCutEnum)cut;

/**
 *  缩放并压缩图片尺寸
 *
 *  @param localId  图片localId
 *  @param cloudId  图片cloudId
 *
 *  @return 立即返回缩放的图片
 */
- (UIImage *)thumbnailWithLocalId:(NSString *)localId
                             zoom:(CGSize)size;

- (UIImage *)thumbnailWithCloudId:(NSString *)cloudId
                             zoom:(CGSize)size;


@end

@interface APImageManager (JSAPI)

/**
 对localID对应的数据进行压缩 返回新的localID，同步，耗时方法，不要再在主线程调用
 
 @param localID  local ID
 @param compress 压缩级别
 @param business 业务标示
 @return 新的local ID
 */
- (NSString *)compressImageFromLocalID:(NSString *)localID
                         compressLevel:(ImageCompressQualityLevelEnum)compress
                              business:(NSString *)business;



@end


@interface APImageManager (Deprecated)

/*!
 根据cloudID 或者 外部url（http、https）获取缓存图片
 外部url的只能获取原图
 @param cloudId cloudID 或者 外部url（http、https）
 @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 @param originalSize 原图size 取原图，请传CGSizeZero；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 */
- (UIImage *)getCacheImageForCloudId:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize DEPRECATED_MSG_ATTRIBUTE("replace by getImageCacheForIdentifier:size:originalSize:");

/**
 *  获取外部url的图片，主线程返回回调
 */
- (NSString *)getExternalImageWithUrl:(NSString *)urlString business:(NSString *)business progress:(APMMProcessiveBlock)progress completion:(APImageDownloadCompletion)complete DEPRECATED_MSG_ATTRIBUTE("replace by getImage:business:zoom:originalSize:progress:completion:");

/*
 * 根据url获取缓存图片
 * Attention:该接口已deprecated，请用getCacheImageForCloudId:size:originalSize:方法
 */
- (UIImage *)getCacheExternalImageForUrl:(NSString *)url DEPRECATED_MSG_ATTRIBUTE("replace by getImageCacheForIdentifier:size:originalSize:");

/**
 *  根据identifier获取图片缓存 identifier可以为CloudID/LocalID/外部url（http、https）

 *  针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param cloudId cloudID 或者 外部url（http、https）
 *  @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param originalSize 原图size 取原图，请传CGSizeZero；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param complete 回调，返回identifier UIImage error
 */

- (void)getCacheImageForCloudId:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize complete:(APImageDownloadWithIdCompletion)complete DEPRECATED_MSG_ATTRIBUTE("replace by getImageCacheForIdentifier:size:originalSize:complete:");

/**
 *  根据cloudId获取图片缓存的NSData数据

 *  针对Django图片，根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
 *  1、originalSize为CGSizeZero，表示原图
 *  2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
 *  3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图

 *  @param cloudId cloudID 或者 外部url（http、https）
 *  @param size 指定缩略图size ；取大图，请传CGSizeZero ；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *  @param originalSize 原图size 取原图，请传CGSizeZero；如果cloudid参数为外部url类型的话，可穿任意size，建议CGSizeZero
 *
 *  @return 图片缓存的NSData数据
 */
- (NSData *)getCacheDataForCloudId:(NSString *)cloudId size:(CGSize)size originalSize:(CGSize)originalSize DEPRECATED_MSG_ATTRIBUTE("replace by getImageCacheDataForIdentifier:size:originalSize:");

- (void)clearCacheForExternameImageUrl:(NSString *)url DEPRECATED_MSG_ATTRIBUTE("replace by clearCacheForIdentifier:");

@end
