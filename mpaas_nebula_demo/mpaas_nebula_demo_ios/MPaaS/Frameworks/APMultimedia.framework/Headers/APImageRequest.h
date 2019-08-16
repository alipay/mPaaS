//
//  APImageRequest.h
//  APMultimedia
//
//  Created by Monster on 16/6/14.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMMConst.h"
#import "APBaseDownloadRequest.h"
@class APImageDownloadResponse;

/**
   图片请求的类型，包括等比图 大图 原图和裁切图四种 具体见：https://lark.alipay.com/amm/apis/about-crop
 */
typedef enum : NSUInteger {
    APImageRequestTypeScale = 0, //等比缩放
    APImageRequestTypeBig = 1, //大图
    APImageRequestTypeOriginal = 2,      //原图
    APImageRequestTypeCut = 4          //非等比裁剪文件
} APImageRequestTypeEnum;



typedef void (^APImageDownloadRequestComplete)(APImageDownloadResponse *response);
typedef void (^APImageDownloadPJPEGBlock)(NSString *identifier,UIImage *pImage);

extern NSString* const kExternalRemoteLogCityCodeKey;


@interface APImageRequest : APBaseDownloadRequest <NSCopying>

/**
 *  当设置imageRequestType这个值的时候， 以imageRequestType的设置值为准。https://lark.alipay.com/amm/apis/about-crop 当imageRequestType未设置，则走以前的老逻辑根据originalSize和zoom的值来决定imageRequestType； 强烈建议设置此值来决定。智能裁切的默认类型为APImageRequestTypeCut
 *  根据size和originalSize来计算图片的类型（原图，大图，等比缩略图，裁切缩略图），计算规则如下
    1、originalSize为CGSizeZero，表示原图
    2、size为CGSizeZero，表示大图（此时originalSize不能为CGSizeZero）
    3、如果size和originalSize的宽高比是一样的（两者的差的绝对值小于0.001），则图片类型为等比缩略图，否则是裁切缩略图
 */
@property (nonatomic, assign) APImageRequestTypeEnum imageRequestType;

/**
 *   当为等比图或者裁切图时候，决定返回图片的大小。
 ＊  当是等比图的时候，返回图片的一条边的尺寸和zoom相等，另外一条边小于或者等于zoom的另外一条边，当为裁切图的时候。返回尺寸和zoom相同
 */
@property (nonatomic, assign) CGSize zoom;

/**
  下载进度回调
 */
@property (nonatomic, copy) APMMProcessiveBlock progress;

/**
 下载完成回调
 */
@property (nonatomic, copy) APImageDownloadRequestComplete downLoadCompletion;

/**
 *  0为默认值回调返回是UIImage，为1时返回是NSData;
 */
@property (nonatomic, assign) NSUInteger respType;


#pragma mark - 其他可选项
/**
 *  下载图片的质量,针对弱网情况下损失图片质量从而节省流量快速拉取图片的方式，[30-80]之间，缺省为80。
 ＊  当缓存中存在更高质量的图片存在时 会直接返回高质量的图片。该字段对于原图请求 不起作用
 */
@property (nonatomic, assign) NSUInteger qualityValue;
/**
 * 默认APMultimediaTaskExecuteSequenceAuto,由多媒体本身进行控制
 * 请注意:由于底层下载并发的缘故，这里设置的任务执行顺序并不保证按严格顺序执行！设置了以后任务会在任务管理器中按照FIFO/LIFO的顺序被调度（但任务加到任务管理器是并发的，有可能业务调用顺序是1-->2-->3，但并发的关系，任务进任务管理器的顺序可能是3-->2-->1，这里和业务调用的顺序可能有出入）。如果期望按照严格顺序执行，那请调用方自己保证串行下载！
 */
@property (nonatomic, assign) APMultimediaTaskExecuteSequence executeSequence;

@property (nonatomic, assign) BOOL isGif DEPRECATED_MSG_ATTRIBUTE("please use useSourceType instead"); //无论是否设置此值，对于gif非原图，始终取首帧图，需要动态图，请请求原图。设置此值的效果等同于设置useSourceType，请使用useSourceType属性。
@property (nonatomic, assign) BOOL useSourceType;//默认为NO；如果设置成YES默认返回原始图片格式类型,如果原始图片格式类型是png，请求返回的图片也是png格式，gif类型除外 gif对于基于首帧图返回静态图，对于原图 返回动态图。在移动网络下，默认会下载webp或者HEVC的等格式的图来节省流量，但默认的webp或者hevc属于有损压缩，会导致图片质量降低。当useSourceType设置为YES，会导致网络流量加大，但能保证wifi相同质量的图片质量。

/**
 *  文件md5值，用作下载后完整性校验
 */
@property (nonatomic, strong) NSString* md5;


/**
   埋点的额外信息，暂时只支持kExternalRemoteLogCityCodeKey这个key值
 */
@property (nonatomic, copy) NSDictionary<NSString*, NSString*> *externalRemoteLogInfo;

/**
 *  透传埋点信息（内部使用）
 */
@property (nonatomic, strong) NSMutableDictionary* internalRemoteLogInfo;

/**
 *  兼容以前的老接口 原始图片的尺寸。当imageRequestType未指定的情况下 根据originalSize和zoom确定请求图片的类型，不建议使用，建议指定imageRequestType来制定需要的图片格式。
 */
@property (nonatomic, assign) CGSize originalSize;
/**
 *  图像id的别名，别名必须惟一。如果此参数存在，在id查不到缓存时，由别名查询缓存
 *  查到缓存后会检查id与alias是否一致，如果不一致，则表示alias过期，会在后台更新
 */
@property (nonatomic, strong) NSString *aliasIdentifier;

/**
只在imageView Category中使用
 */
@property (nonatomic, strong) UIImage *placeholder; // 占位图

#pragma mark - 渐显
/**
 * 是否需要支持下载渐显，目前只支持DJANGO图片，而且渐显只支持jpeg格式的图片,设置了该block则说明需要
 */
@property (nonatomic, copy) APImageDownloadPJPEGBlock downloadPJPEGBlock;

/**
 * 是否需要支持下载渐显，目前只支持DJANGO图片，而且渐显只支持jpeg格式的图片,设置为YES则说明需要，当设置了downloadPJPEGBlock字段时，该字段设置与否都会走渐显下载图片
 * 使用场景:使用UIImageView(APImageCache)类别类下载图片时
 */
@property (nonatomic, assign) BOOL usePJPEG;

/**
 *  校验APImageRequest是否有效。
 *
 *  @return
 */
- (BOOL)isValid;

#pragma mark - 额外的参数

/**
 额外的参数 只识别已经定义APRequestExtraParamKey.h中的kExtraParams* key
 */
@property (nonatomic, copy) NSDictionary* extraParams;

@end

@interface APImageDownloadResponse : NSObject

/**
 *  cloud Id 或者是外部URL
 */
@property (nonatomic, strong) NSString* identifier;

/**
 *  下载返回的图片对象
 */
@property (nonatomic, strong) UIImage* image;

/**
 *  如果请求失败，error中包含失败信息
 */
@property (nonatomic, strong) NSError* error;

/**
 *  当请求二进制数据的数据的时候 imageData是图片的二进制表示
 */
@property (nonatomic, strong) NSData* imageData;

+ (instancetype)responseWithError:(NSError *)error identifier:(NSString*)identifier;
+ (instancetype)responseWithImage:(UIImage *)image error:(NSError*)error identifier:(NSString*)identifier;
+ (instancetype)responseWithImage:(UIImage *)image identifier:(NSString*)identifier;
+ (instancetype)responseWithData:(NSData *)imageData identifier:(NSString*)identifier;
+ (instancetype)responseWithObject:(NSObject *)object identifier:(NSString*)identifier;

@end
