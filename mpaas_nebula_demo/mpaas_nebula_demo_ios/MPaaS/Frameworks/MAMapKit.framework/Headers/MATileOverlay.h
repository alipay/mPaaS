//
//  MATileOverlay.h
//  MapKit_static
//
//  Created by Li Fei on 11/22/13.
//  Copyright (c) 2013 songjian. All rights reserved.
//

#import "MAOverlay.h"

/**
 *  该类是覆盖在球面墨卡托投影上的图片tiles的数据源
 */
@interface MATileOverlay : NSObject <MAOverlay>

/**
 *  根据指定的URLTemplate生成tileOverlay
 *
 *  @param URLTemplate URLTemplate是一个包含"{x}","{y}","{z}","{scale}"的字符串,"{x}","{y}","{z}","{scale}"会被tile path的值所替换，并生成用来加载tile图片数据的URL 。例如： http://server/path?x={x}&y={y}&z={z}&scale={scale}
 *
 *  @return 以指定的URLTemplate字符串生成tileOverlay
 */
- (id)initWithURLTemplate:(NSString *)URLTemplate;

/**
 *  默认tileSize 256x256
 */
@property (readonly) CGSize tileSize;

/**
 *  tileOverlay的可见最小Zoom值
 */
@property NSInteger minimumZ;

/**
 *  tileOverlay的可见最大Zoom值
 */
@property NSInteger maximumZ;

/**
 *  同initWithURLTemplate:中的URLTemplate
 */
@property (readonly) NSString *URLTemplate;

/**
 *  暂未开放
 */
@property (nonatomic) BOOL canReplaceMapContent;

/**
 *  区域外接矩形，可用来设定tileOverlay的可渲染区域
 */
@property (nonatomic) MAMapRect boundingMapRect;

@end

struct MATileOverlayPath{
    NSInteger x;
    NSInteger y;
    NSInteger z;
    CGFloat contentScaleFactor;
};
typedef struct MATileOverlayPath MATileOverlayPath;

/**
 *  子类可覆盖CustomLoading中的方法来自定义加载MKTileOverlay
 */
@interface MATileOverlay (CustomLoading)

/**
*  以tile path生成URL。用于加载tile,此方法默认填充URLTemplate
*
*  @param path tile path
*
*  @return 以tile path生成tileOverlay
*/
- (NSURL *)URLForTilePath:(MATileOverlayPath)path;

/**
 *  加载被请求的tile,并以tile数据或加载tile失败error访问回调block;默认实现为首先用URLForTilePath去获取URL,然后用异步NSURLConnection加载tile
 *
 *  @param path   tile path
 *  @param result 用来传入tile数据或加载tile失败的error访问的回调block
 */
- (void)loadTileAtPath:(MATileOverlayPath)path result:(void (^)(NSData *tileData, NSError *error))result;

@end
