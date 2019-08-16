//
//  MAOverlayRenderer.h
//  MAMapKit
//
//
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "MAOverlay.h"
#import "MALineDrawType.h"

#define kMAOverlayRendererDefaultStrokeColor [UIColor colorWithRed:0.3 green:0.63 blue:0.89 alpha:0.8]
#define kMAOverlayRendererDefaultFillColor [UIColor colorWithRed:0.77 green:0.88 blue:0.94 alpha:0.8]

/**
 该类是地图覆盖物Renderer的基类, 提供绘制overlay的接口但并无实际的实现（render相关方法只能在重写后的glRender方法中使用）
 */
@interface MAOverlayRenderer : NSObject

/**
*  初始化并返回一个Overlay Renderer
*
*  @param overlay 关联的overlay对象
*
*  @return 初始化成功则返回overlay view,否则返回nil
*/
- (instancetype)initWithOverlay:(id <MAOverlay>)overlay;

/**
 *  关联的overlay对象
 */
@property (nonatomic, readonly, retain) id <MAOverlay> overlay;

/**
 *  将MAMapPoint转化为相对于receiver的本地坐标
 *
 *  @param mapPoint 要转化的MAMapPoint
 *
 *  @return 相对于receiver的本地坐标
 */
- (CGPoint)pointForMapPoint:(MAMapPoint)mapPoint;

/**
 *  将相对于receiver的本地坐标转化为MAMapPoint
 *
 *  @param point 要转化的相对于receiver的本地坐标
 *
 *  @return MAMapPoint
 */
- (MAMapPoint)mapPointForPoint:(CGPoint)point;

/**
 *  将MAMapRect转化为相对于receiver的本地rect
 *
 *  @param mapRect 要转化的MAMapRect
 *
 *  @return 相对于receiver的本地rect
 */
- (CGRect)rectForMapRect:(MAMapRect)mapRect;

/**
 *  将相对于receiver的本地rect转化为MAMapRect
 *
 *  @param rect 要转化的相对于receiver的本地rect
 *
 *  @return MAMapRect
 */
- (MAMapRect)mapRectForRect:(CGRect)rect;

/**
 *  缓存的OpenGLES坐标
 */
@property (nonatomic) CGPoint *glPoints;

/**
 *  缓存的OpenGLES坐标 个数
 */
@property (nonatomic) NSUInteger glPointCount;

/**
 *  将MAMapPoint转换为opengles可以直接使用的坐标
 *
 *  @param mapPoint MAMapPoint坐标
 *
 *  @return 直接支持的坐标
 */
- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint;

/**
 *  批量将MAMapPoint转换为opengles可以直接使用的坐标
 *
 *  @param mapPoints MAMapPoint坐标数据指针
 *  @param count     个数
 *
 *  @return 直接支持的坐标数据指针(需要调用者手动释放)
 */
- (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count;

/**
 *  将屏幕尺寸转换为OpenGLES尺寸
 *
 *  @param windowWidth 屏幕尺寸
 *
 *  @return OpenGLES尺寸
 */
- (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth;

/**
 *  OpenGLES坐标系发生改变, 重新计算缓存的OpenGLES坐标
 */
- (void)referenceDidChange;

/**
 *  使用OpenGLES 绘制线
 *
 *  @param points      OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount  点个数
 *  @param strokeColor 线颜色
 *  @param lineWidth   OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param looped      是否闭合, 如polyline会设置NO, polygon会设置YES
 */
- (void)renderLinesWithPoints:(CGPoint *)points
                   pointCount:(NSUInteger)pointCount
                  strokeColor:(UIColor *)strokeColor
                    lineWidth:(CGFloat)lineWidth
                       looped:(BOOL)looped;

/**
 *  使用OpenGLES 绘制线
 *
 *  @param points       OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount   点个数
 *  @param strokeColor  线颜色
 *  @param lineWidth    OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param looped       是否闭合, 如polyline会设置NO, polygon会设置YES
 *  @param lineJoinType 线连接点样式
 *  @param lineCapType  线端点样式
 *  @param lineDash     是否是虚线
 */
- (void)renderLinesWithPoints:(CGPoint *)points
                   pointCount:(NSUInteger)pointCount
                  strokeColor:(UIColor *)strokeColor
                    lineWidth:(CGFloat)lineWidth
                       looped:(BOOL)looped
                 LineJoinType:(MALineJoinType)lineJoinType
                  LineCapType:(MALineCapType)lineCapType
                     lineDash:(BOOL)lineDash;

/**
 *  使用OpenGLES 按指定纹理绘制线
 *
 *  @param points     OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount 点个数
 *  @param lineWidth  线OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param textureID  指定的纹理 使用- (void)loadStrokeTextureImage:(UIImage *)textureImage;加载
 *  @param looped     是否闭合, 如polyline会设置NO, polygon会设置YES
 */
- (void)renderTexturedLinesWithPoints:(CGPoint *)points
                           pointCount:(NSUInteger)pointCount
                            lineWidth:(CGFloat)lineWidth
                            textureID:(GLuint)textureID
                               looped:(BOOL)looped;

/**
 *  使用OpenGLES 绘制多纹理线
 *
 *  @param points           OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount       点个数
 *  @param lineWidth        线OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param textureIDs       各段指定的纹理 使用- (BOOL)loadStrokeTextureImages:(NSArray *)textureImages;加载,在strokeTextureIDs属性中获取
 *  @param drawStyleIndexes 纹理索引数组，成员为NSNumber,且为非负数，负数按0处理
 *  @param looped           是否闭合, 如polyline会设置NO, polygon会设置YES
 */
- (void)renderTexturedLinesWithPoints:(CGPoint *)points
                           pointCount:(NSUInteger)pointCount
                            lineWidth:(CGFloat)lineWidth
                           textureIDs:(NSArray *)textureIDs
                     drawStyleIndexes:(NSArray *)drawStyleIndexes
                               looped:(BOOL)looped;

/**
 *  使用OpenGLES 绘制多段颜色线
 *
 *  @param points           OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount       点个数
 *  @param strokeColors     各段指定的颜色
 *  @param drawStyleIndexes 颜色索引数组，成员为NSNumber,且为非负数，负数按0处理
 *  @param isGradient       颜色是否渐变
 *  @param lineWidth        线OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param looped           是否闭合, 如polyline会设置NO, polygon会设置YES
 *  @param lineJoinType     线连接点样式
 *  @param lineCapType      线端点样式
 *  @param lineDash         是否虚线
 */
- (void)renderLinesWithPoints:(CGPoint *)points
                   pointCount:(NSUInteger)pointCount
                 strokeColors:(NSArray *)strokeColors
             drawStyleIndexes:(NSArray *)drawStyleIndexes
                   isGradient:(BOOL)isGradient
                    lineWidth:(CGFloat)lineWidth
                       looped:(BOOL)looped
                 LineJoinType:(MALineJoinType)lineJoinType
                  LineCapType:(MALineCapType)lineCapType
                     lineDash:(BOOL)lineDash;

/**
 *  使用OpenGLES 绘制区域
 *
 *  @param points           OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount       点个数
 *  @param fillColor        填充颜色
 *  @param usingTriangleFan 若必为凸多边形输入YES，可能为凹多边形输入NO
 */
- (void)renderRegionWithPoints:(CGPoint *)points
                    pointCount:(NSUInteger)pointCount
                     fillColor:(UIColor *)fillColor
              usingTriangleFan:(BOOL)usingTriangleFan;

/**
 *  使用OpenGLES 绘制区域(带轮廓线)
 *  注：strokeLineWidth为0 或 strokeColor为nil 时不绘制轮廓线。
 *
 *  @param points             OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount         点个数
 *  @param fillColor          填充颜色
 *  @param strokeColor        轮廓线颜色
 *  @param strokeLineWidth    轮廓线宽。OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param strokeLineJoinType 轮廓线连接点样式
 *  @param strokeLineDash     轮廓线是否是虚线
 *  @param usingTriangleFan   若必为凸多边形输入YES，可能为凹多边形输入NO
 */
- (void)renderStrokedRegionWithPoints:(CGPoint *)points pointCount:(NSUInteger)pointCount
                           fillColor:(UIColor *)fillColor
                          strokeColor:(UIColor *)strokeColor
                     strokeLineWidth:(CGFloat)strokeLineWidth
                   strokeLineJoinType:(MALineJoinType)strokeLineJoinType
                      strokeLineDash:(BOOL)strokeLineDash
                    usingTriangleFan:(BOOL)usingTriangleFan;

/**
 *  使用OpenGLES 绘制区域(带纹理轮廓线)
 *  注：strokeLineWidth为0 或 strokeTexture为0 时不绘制轮廓线。
 *
 *  @param points           OpenGLES坐标系点指针, 参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param pointCount       点个数
 *  @param fillColor        填充颜色
 *  @param strokeLineWidth  轮廓线宽。OpenGLES支持线宽尺寸, 参考 - (CGFloat)glWidthForWindowWidth:(CGFloat)windowWidth
 *  @param strokeTexture    轮廓线纹理。使用- (void)loadStrokeTextureImage:(UIImage *)textureImage;加载
 *  @param usingTriangleFan 若必为凸多边形输入YES，可能为凹多边形输入NO
 */
- (void)renderTextureStrokedRegionWithPoints:(CGPoint *)points
                                 pointCount:(NSUInteger)pointCount
                                  fillColor:(UIColor *)fillColor
                            strokeTineWidth:(CGFloat)strokeLineWidth
                            strokeTextureID:(GLuint)strokeTexture
                           usingTriangleFan:(BOOL)usingTriangleFan;

/**
 *  使用OpenGLES 绘制图片
 *
 *  @param textureID OpenGLES纹理ID
 *  @param points    OpenGLES坐标系点指针,纹理矩形的四个顶点坐标,其第一个坐标为图片左上角，依次顺时针传入其他顶点 ,参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 */
- (void)renderIconWithTextureID:(GLuint)textureID points:(CGPoint *)points;

/**
 *  使用OpenGLES 绘制图片
 *
 *  @param textureID     OpenGLES纹理ID
 *  @param points        OpenGLES坐标系点指针,纹理矩形的四个顶点坐标,其第一个坐标为图片左上角，依次顺时针传入其他顶点 ,参考- (CGPoint)glPointForMapPoint:(MAMapPoint)mapPoint, - (CGPoint *)glPointsForMapPoints:(MAMapPoint *)mapPoints count:(NSUInteger)count
 *  @param modulateColor 调节颜色值, 最终颜色 = 纹理色 * modulateColor. 如只需要调节alpha的话就设置为[red=1, green=1, blue=1, alpha=0.5]
 */
- (void)renderIconWithTextureID:(GLuint)textureID points:(CGPoint *)points modulateColor:(UIColor *)modulateColor;

/**
 *  绘制函数(子类需要重载来实现)
 */
- (void)glRender;


#pragma mark - draw property

/**
 *  笔触纹理id
 *  修改纹理id参考 - (GLuint)loadStrokeTextureImage:(UIImage *)textureImage
 */
@property (nonatomic, readonly) GLuint strokeTextureID;

/**
 *  加载纹理图片，纹理ID存储在成员strokeTextureID中。纹理图片为nil时，清空原有纹理
 *
 *  @param textureImage 纹理图片（需满足：长宽相等，且宽度值为2的次幂）。若为nil，则清空原有纹理
 *
 *  @return openGL纹理ID, 若纹理加载失败返回0
 */
- (GLuint)loadStrokeTextureImage:(UIImage *)textureImage;

@end
