//
//  MAMapView.h
//  MAMapKit
//
//  Created by 翁乐 on 3/17/16.
//  Copyright © 2016 le.weng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MAOverlay.h"
#import "MAOverlayRenderer.h"
#import "MAAnnotationView.h"
#import "MACircle.h"
#import "MAUserLocation.h"
#import "MAMapStatus.h"
#import "MAIndoorInfo.h"

#pragma mark - ENUM

typedef NS_ENUM(NSInteger, MAMapType)
{
    MAMapTypeStandard = 0,  // 普通地图
    MAMapTypeSatellite,     // 卫星地图
    MAMapTypeStandardNight, // 夜间视图
    MAMapTypeNavi,          // 导航视图
    MAMapTypeBus            // 公交视图
};

typedef NS_ENUM(NSInteger, MAUserTrackingMode)
{
    MAUserTrackingModeNone              = 0,    // 不追踪用户的location更新
    MAUserTrackingModeFollow            = 1,    // 追踪用户的location更新
    MAUserTrackingModeFollowWithHeading = 2     // 追踪用户的location与heading更新
};

typedef NS_ENUM(NSInteger, MATrafficStatus)
{
    MATrafficStatusSmooth = 1,                  //!< 1 通畅
    MATrafficStatusSlow,                        //!< 2 缓行
    MATrafficStatusJam,                         //!< 3 阻塞
    MATrafficStatusSeriousJam,                  //!< 4 严重阻塞
};

/**
 * @brief 绘制overlay的层级
 */
typedef NS_ENUM(NSInteger, MAOverlayLevel) {
    MAOverlayLevelAboveRoads = 0, //!< 在地图底图标注和兴趣点图标之下绘制overlay
    MAOverlayLevelAboveLabels // 在地图底图标注和兴趣点图标之上绘制overlay
};

#pragma mark - animation

/**
 * @brief 中心点(MAMapPoint)key, 封装成[NSValue valueWithMAMapPoint:].
 */
extern NSString * const kMAMapLayerCenterMapPointKey;

/**
 * @brief 缩放级别key, 范围[minZoomLevel, maxZoomLevel], 封装成NSNumber.
 */
extern NSString * const kMAMapLayerZoomLevelKey;

/**
 * @brief 旋转角度key, 范围[0, 360), 封装成NSNumber.
 */
extern NSString * const kMAMapLayerRotationDegreeKey;

/**
 * @brief 摄像机俯视角度, 范围[0, 45], 封装成NSNumber.
 */
extern NSString * const kMAMapLayerCameraDegreeKey;


@protocol MAMapViewDelegate;

@interface MAMapView : UIView

#pragma mark - mapView normalProperty/normalFuction

@property (nonatomic, weak) id <MAMapViewDelegate> delegate;

/**
 * @brief 是否显示底图标注
 */
@property (nonatomic, assign, getter = isShowsLabels) BOOL showsLabels;

/**
 * @brief 是否显示交通
 */
@property (nonatomic, getter = isShowTraffic) BOOL showTraffic;

/**
 * @brief 是否显示楼块，默认为YES
 */
@property (nonatomic, getter = isShowsBuildings) BOOL showsBuildings;

/**
 * @brief 在当前缩放级别下, 基于地图中心点, 1 screen point 对应的距离(单位是米).
 */
@property (nonatomic, readonly) double metersPerPointForCurrentZoom;

/**
 * @brief 在指定的缩放级别下, 基于地图中心点, 1 screen point 对应的距离(单位是米).
 * @param zoomLevel 指定的缩放级别, 在[minZoomLevel, maxZoomLevel]范围内.
 * @return 对应的距离(单位是米)
 */
- (double)metersPerPointForZoomLevel:(CGFloat)zoomLevel;

/**
 *  标识当前地图中心位置是否在中国范围外。此属性不是精确判断，不能用于边界区域。
 */
@property (nonatomic, readonly) BOOL isAbroad;

/**
 *  设置实时交通颜色
 *  key为 MATrafficStatus
 */
@property (nonatomic, copy) NSDictionary <NSNumber *, UIColor *> *trafficStatus;

/**
 *  是否允许对annotationView根据zIndex进行排序，默认为YES。
 *  当annotationView数量比较大时可能会引起性能问题，可以设置此属性为NO。
 */
@property (nonatomic, assign) BOOL allowsAnnotationViewSorting;

/**
 * @brief 当前地图的经纬度范围，设定的该范围可能会被调整为适合地图窗口显示的范围
 */
@property (nonatomic) MACoordinateRegion region;
- (void)setRegion:(MACoordinateRegion)region animated:(BOOL)animated;

/**
 * @brief 根据当前地图视图frame的大小调整region范围
 * @param region 要调整的经纬度范围
 * @return 调整后的经纬度范围
 */
- (MACoordinateRegion)regionThatFits:(MACoordinateRegion)region;

/**
 * @brief 可见区域
 */
@property (nonatomic) MAMapRect visibleMapRect;
- (void)setVisibleMapRect:(MAMapRect)mapRect animated:(BOOL)animated;

/**
 * @brief 调整投影矩形比例
 * @param mapRect 要调整的投影矩形
 * @return 调整后的投影矩形
 */
- (MAMapRect)mapRectThatFits:(MAMapRect)mapRect;

/**
 * @brief 根据嵌入数据来调整投影矩形比例
 * @param mapRect 要调整的投影矩形
 * @param insets 嵌入数据
 * @return 调整后的投影矩形
 */
- (MAMapRect)mapRectThatFits:(MAMapRect)mapRect edgePadding:(UIEdgeInsets)insets;

/**
 * @brief 根据当前地图视图frame的大小调整投影范围
 * @param mapRect 要调整的投影范围
 */
- (void)setVisibleMapRect:(MAMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animate;

/**
 * @brief 将经纬度转换为指定view坐标系的坐标
 * @param coordinate 经纬度
 * @param view 指定的view
 * @return 基于指定view坐标系的坐标
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;

/**
 * @brief 将指定view坐标系的坐标转换为经纬度
 * @param point 指定view坐标系的坐标
 * @param view 指定的view
 * @return 经纬度
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView *)view;

/**
 * @brief 将经纬度region转换为指定view坐标系的rect
 * @param region 经纬度region
 * @param view 指定的view
 * @return 指定view坐标系的rect
 */
- (CGRect)convertRegion:(MACoordinateRegion)region toRectToView:(UIView *)view;

/**
 * @brief 将指定view坐标系的rect转换为经纬度region
 * @param rect 指定view坐标系的rect
 * @param view 指定的view
 * @return 经纬度region
 */
- (MACoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView *)view;

#pragma mark - Limitation
/*!
 @brief 设置可见地图区域的矩形边界，如限制地图只显示北京市范围. 
 */
@property (nonatomic, assign) MACoordinateRegion limitRegion;

/*!
 @brief 设置可见地图区域的矩形边界，如限制地图只显示北京市范围.
 */
@property (nonatomic, assign) MAMapRect limitMapRect;

#pragma mark - mapView control
/**
 * @brief 当前地图的中心点，改变该值时，地图的比例尺级别不会发生变化
 */
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

/**
 * @brief 缩放级别（默认3-19，有室内地图时为3-20）
 */
@property (nonatomic) CGFloat zoomLevel;
- (void)setZoomLevel:(CGFloat)zoomLevel animated:(BOOL)animated;

/**
 * @brief 最小缩放级别
 */
@property (nonatomic) CGFloat minZoomLevel;

/**
 * @brief 最大缩放级别（有室内地图时最大为20，否则为19）
 */
@property (nonatomic) CGFloat maxZoomLevel;

/**
 * @brief 根据指定的枢纽点来缩放地图
 * @param zoomLevel 缩放级别
 * @param pivot 枢纽点(基于地图view的坐标系)
 * @param animated 是否动画
 */
- (void)setZoomLevel:(CGFloat)zoomLevel atPivot:(CGPoint)pivot animated:(BOOL)animated;

/**
 * @brief 设置地图旋转角度(逆时针为正向)
 */
@property (nonatomic) CGFloat rotationDegree;

/**
 * @brief 设置地图旋转角度(逆时针为正向)
 * @param animated 动画
 * @param duration 动画时间
 */
- (void)setRotationDegree:(CGFloat)rotationDegree animated:(BOOL)animated duration:(CFTimeInterval)duration;

/**
 * @brief 设置地图相机角度(范围为[0.f, 60.f]，但高于40度的角度需要在16级以上才能生效)
 */
@property (nonatomic) CGFloat cameraDegree;

- (void)setCameraDegree:(CGFloat)cameraDegree animated:(BOOL)animated duration:(CFTimeInterval)duration;


- (void)setMapStatus:(MAMapStatus *)status
            animated:(BOOL)animated;

/**
 * @brief 设置地图状态
 * @param animated 是否动画
 * @param duration 动画时间 默认动画时间为0.35s
 */
- (void)setMapStatus:(MAMapStatus *)status
            animated:(BOOL)animated
            duration:(CFTimeInterval)duration;

- (MAMapStatus *)getMapStatus;


#pragma mark mapView controlEnable
/**
 * @brief 是否支持缩放
 */
@property (nonatomic, getter = isZoomEnabled) BOOL zoomEnabled;

/**
 * @brief 是否支持平移
 */
@property (nonatomic, getter = isScrollEnabled) BOOL scrollEnabled;

/**
 * @brief 是否支持旋转
 */
@property (nonatomic, getter = isRotateEnabled) BOOL rotateEnabled;

/**
 * @brief 是否支持camera旋转
 */
@property (nonatomic, getter = isRotateCameraEnabled) BOOL rotateCameraEnabled;

/**
 * @brief 是否支持天空模式，默认为YES. 开启后，进入天空模式后，annotation重用可视范围会缩减
 */
@property (nonatomic, getter = isSkyModelEnabled) BOOL skyModelEnable;

/**
 * @brief 是否支持单击地图获取POI信息(默认为YES)
 对应的回调是 - (void)mapView:(MAMapView *)mapView didTouchPois:(NSArray *)pois
 */
@property (nonatomic) BOOL touchPOIEnabled;

/**
 *  是否以screenAnchor点作为锚点进行缩放，默认为YES。如果为NO，则以手势中心点作为锚点
 */
@property (nonatomic, assign) BOOL zoomingInPivotsAroundAnchorPoint;

#pragma mark - userLocation
/**
 * @brief 是否显示用户位置
 */
@property (nonatomic) BOOL showsUserLocation;

/**
 * @brief 当前的位置数据
 */
@property (nonatomic, readonly) MAUserLocation *userLocation;

/**
 * @brief 是否自定义用户位置精度圈(userLocationAccuracyCircle)对应的 view, 默认为 NO.
 如果为YES: 会调用 - (MAOverlayRenderer *)mapView:(MAMapView *)mapView rendererForOverlay:(id <MAOverlay>)overlay 若返回nil, 则不加载.
 如果为NO : 会使用默认的样式.
 */
@property (nonatomic) BOOL customizeUserLocationAccuracyCircleRepresentation;

/**
 * @brief 用户位置精度圈 对应的overlay.
 */
@property (nonatomic, readonly) MACircle *userLocationAccuracyCircle;

/**
 * @brief 定位用户位置的模式
 */
@property (nonatomic) MAUserTrackingMode userTrackingMode;
- (void)setUserTrackingMode:(MAUserTrackingMode)mode animated:(BOOL)animated;

/**
 * @brief 当前位置再地图中是否可见
 */
@property (nonatomic, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;

#pragma mark - userlocation locationOption
/**
 * @brief 设定定位的最小更新距离。默认为kCLDistanceFilterNone，会提示任何移动。
 */
@property(nonatomic) CLLocationDistance distanceFilter;

/**
 * @brief 设定定位精度。默认为kCLLocationAccuracyBest。
 */
@property(nonatomic) CLLocationAccuracy desiredAccuracy;

/**
 * @brief 设定最小更新角度。默认为1度，设定为kCLHeadingFilterNone会提示任何角度改变。
 */
@property(nonatomic) CLLocationDegrees headingFilter;

/**
 *  指定定位是否会被系统自动暂停。默认为YES。只在iOS 6.0之后起作用。
 */
@property(nonatomic) BOOL pausesLocationUpdatesAutomatically;

/**
 * 是否允许后台定位。默认为NO。只在iOS 9.0之后起作用。
 * 设置为YES的时候必须保证 Background Modes 中的 Location updates处于选中状态，否则会抛出异常。
 */
@property (nonatomic) BOOL allowsBackgroundLocationUpdates;

#pragma mark - annotation
/**
 * @brief 向地图窗口添加标注，需要实现MAMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotation 要添加的标注
 */
- (void)addAnnotation:(id <MAAnnotation>)annotation;

/**
 * @brief 向地图窗口添加一组标注，需要实现MAMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 * @param annotations 要添加的标注数组
 */
- (void)addAnnotations:(NSArray *)annotations;

/**
 * @brief 移除标注
 * @param annotation 要移除的标注
 */
- (void)removeAnnotation:(id <MAAnnotation>)annotation;

/**
 * @brief 移除一组标注
 * @param annotations 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray *)annotations;

/**
 * @brief 标注数组
 */
@property (nonatomic, readonly) NSArray *annotations;

/**
 * @brief 获取指定投影矩形范围内的标注
 * @param mapRect 投影矩形范围
 * @return 标注集合
 */
- (NSSet *)annotationsInMapRect:(MAMapRect)mapRect;

/**
 * @brief 根据标注数据过去标注view
 * @param annotation 标注数据
 * @return 对应的标注view
 */
- (MAAnnotationView *)viewForAnnotation:(id <MAAnnotation>)annotation;

/**
 * @brief 从复用内存池中获取制定复用标识的annotation view
 * @param identifier 复用标识
 * @return annotation view
 */
- (MAAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/**
 * @brief 选中标注数据对应的view
 * @param annotation 标注数据
 * @param animated 是否有动画效果
 */
- (void)selectAnnotation:(id <MAAnnotation>)annotation animated:(BOOL)animated;

/**
 * @brief 取消选中标注数据对应的view
 * @param annotation 标注数据
 * @param animated 是否有动画效果
 */
- (void)deselectAnnotation:(id <MAAnnotation>)annotation animated:(BOOL)animated;

/**
 * @brief 处于选中状态的标注数据数据(其count == 0 或 1)
 */
@property (nonatomic, copy) NSArray *selectedAnnotations;

/**
 * @brief annotation 可见区域
 */
@property (nonatomic, readonly) CGRect annotationVisibleRect;

/**
 设置地图使其可以显示数组中所有的annotation, 如果数组中只有一个则直接设置地图中心为annotation的位置。
 * @param annotations 需要显示的annotation
 * @param animated    是否执行动画
 */
- (void)showAnnotations:(NSArray *)annotations animated:(BOOL)animated;

/**
 *  设置地图使其可以显示数组中所有的annotation, 如果数组中只有一个则直接设置地图中心为annotation的位置。
 *
 *  @param annotations 需要显示的annotation
 *  @param insets      insets 嵌入边界
 *  @param animated    是否执行动画
 */
- (void)showAnnotations:(NSArray *)annotations edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

#pragma mark - overlay
/**
 * @brief Overlay数组
 */
@property (nonatomic, readonly) NSArray *overlays;

/**
 * @brief 取位于level下的overlays
 */
- (NSArray *)overlaysInLevel:(MAOverlayLevel)level;

/**
 * @brief 向地图窗口添加Overlay。
 需要实现MAMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer。
 默认添加层级：MAGroundOverlay默认层级为MAOverlayLevelAboveRoads，其余overlay类型默认层级为MAOverlayLevelAboveLabels
 * @param overlay 要添加的overlay
 */
- (void)addOverlay:(id <MAOverlay>)overlay;

/**
 * @brief 向地图窗口添加一组Overlay，需要实现MAMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
 默认添加层级：MAOverlayLevelAboveLabels
 
 * @param overlays 要添加的overlay数组
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 * @brief 向地图窗口添加Overlay，需要实现MAMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
 * @param overlay 要添加的overlay
 * @param level 添加的overlay所在层级
 */
- (void)addOverlay:(id <MAOverlay>)overlay level:(MAOverlayLevel)level;

/**
 * @brief 向地图窗口添加一组Overlay，需要实现MAMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
 * @param overlays 要添加的overlay数组
 * @param level 添加的overlay所在层级
 */
- (void)addOverlays:(NSArray *)overlays level:(MAOverlayLevel)level;

/**
 * @brief 移除Overlay
 * @param overlay 要移除的overlay
 */
- (void)removeOverlay:(id <MAOverlay>)overlay;

/**
 * @brief 移除一组Overlay
 * @param overlays 要移除的overlay数组
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 * @brief 在指定层级的指定的索引处添加一个Overlay
 * @param overlay 要添加的overlay
 * @param index 指定的索引
 * @param level 指定的层级
 
 注：各个层级的索引分开计数；
 若index大于level层级的最大索引，则添加至level层级的最大索引之后。
 */
- (void)insertOverlay:(id <MAOverlay>)overlay atIndex:(NSUInteger)index level:(MAOverlayLevel)level;

/**
 * @brief 在指定的Overlay之上插入一个overlay
 * @param overlay 带添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <MAOverlay>)overlay aboveOverlay:(id <MAOverlay>)sibling;

/**
 * @brief 在指定的Overlay之下插入一个overlay
 * @param overlay 带添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <MAOverlay>)overlay belowOverlay:(id <MAOverlay>)sibling;

/**
 * @brief 在指定的索引处添加一个Overlay
 * @param overlay 要添加的overlay
 * @param index 指定的索引
 */
- (void)insertOverlay:(id <MAOverlay>)overlay atIndex:(NSUInteger)index;

/**
 * @brief 交换指定索引处的Overlay
 * @param index1 索引1
 * @param index2 索引2
 */
- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2;

/**
 * @brief 交换两个overlay
 * @param overlay1 overlay1
 * @param overlay2 overlay2
 */
- (void)exchangeOverlay:(id <MAOverlay>)overlay1 withOverlay:(id <MAOverlay>)overlay2;

/**
 * @brief 查找指定overlay对应的Renderer，如果该View尚未创建，返回nil
 * @param overlay 指定的overlay
 * @return 指定overlay对应的Renderer
 */
- (MAOverlayRenderer *)rendererForOverlay:(id <MAOverlay>)overlay;

/**
 设置地图使其可以显示数组中所有的overlay, 如果数组中只有一个则直接设置地图中心为overlay的位置。
 * @param overlays    需要显示的overlays
 * @param animated    是否执行动画
 */
- (void)showOverlays:(NSArray *)overlays animated:(BOOL)animated;

/**
 *  设置地图使其可以显示数组中所有的overlay, 如果数组中只有一个则直接设置地图中心为overlay的位置。
 *
 *  @param overlays    需要显示的overlays
 *  @param insets      insets 嵌入边界
 *  @param animated    是否执行动画
 */
- (void)showOverlays:(NSArray *)overlays edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;


#pragma mark - Cache

/**
 @brief 清除所有磁盘上缓存的地图数据(不包括离线地图)。
 */
- (void)clearDisk;

#pragma mark - compassView

/**
 * @brief 是否显示罗盘
 */
@property (nonatomic, assign) BOOL showsCompass;

/**
 * @brief 罗盘原点位置
 */
@property (nonatomic) CGPoint compassOrigin;

/**
 * @brief 罗盘的宽高
 */
@property (nonatomic, readonly) CGSize compassSize;

/**
 * @brief 设置罗盘的图片
 */
- (void)setCompassImage:(UIImage *)image;

#pragma mark - scaleView
/**
 * @brief 是否显示比例尺
 */
@property (nonatomic) BOOL showsScale;

/**
 * @brief 比例尺原点位置
 */
@property (nonatomic) CGPoint scaleOrigin;

/**
 * @brief 比例尺的最大宽高
 */
@property (nonatomic, readonly) CGSize scaleSize;

#pragma mark - Logo
/**
 * @brief 地图类型
 */
@property (nonatomic) MAMapType mapType;

/**
 * @brief logo位置, 必须在mapView.bounds之内，否则会被忽略
 */
@property (nonatomic) CGPoint logoCenter;

/**
 * @brief logo的宽高
 */
@property (nonatomic, readonly) CGSize logoSize;

#if MA_INCLUDE_INDOOR
#pragma mark - indoorView

/**
 * @brief 是否显示室内地图
 */
@property (nonatomic, getter = isShowsIndoorMap) BOOL showsIndoorMap;

/**
 * @brief 是否显示室内地图默认控件
 */
@property (nonatomic, getter = isShowsIndoorMapControl) BOOL showsIndoorMapControl;

/**
 * @brief 默认室内地图控件的最大宽高
 */
@property (nonatomic, readonly) CGSize indoorMapControlSize;

/**
 * @brief 设置默认室内地图控件位置
 */
- (void)setIndoorMapControlOrigin:(CGPoint)origin;

/**
 * @brief 设置当前室内地图楼层数
 */
- (void)setCurrentIndoorMapFloorIndex:(NSInteger)floorIndex;

/**
 * @brief 清空室内地图缓存
 */
- (void)clearIndoorMapCache;
#endif

#pragma mark - snapshot

/**
 * @brief 在指定区域内截图(默认会包含该区域内的annotationView)
 * @param rect 指定的区域
 * @return 截图image
 */
- (UIImage *)takeSnapshotInRect:(CGRect)rect;

/**
 * @brief 在指定区域内截图(默认会包含该区域内的annotationView),并且返回截屏是否完整
 * @param rect 指定的区域
 * @param block 回调block(resultImage 是返回的图片,state是返回的状态：0代表截图时地图载入不完整，1代表地图载入完整）
 */
- (void)takeSnapshotInRect:(CGRect)rect withCompletionBlock:(void (^)(UIImage *resultImage, NSInteger state))block;

#pragma mark - renderFrame

/**
 * @brief 最大帧数，有效的帧数为：60、30、20、10等能被60整除的数。默认为60
 */
@property (nonatomic, assign) NSUInteger maxRenderFrame;

/**
 * @brief 是否允许降帧，默认为YES
 */
@property (nonatomic, assign) BOOL isAllowDecreaseFrame;

#pragma mark - openGLES
/**
 * @brief 停止/开启 OpenGLES 指令绘制操作
 对应的回调是 - (void)mapView:(MAMapView *)mapView didChangeOpenGLESDisabled:(BOOL)openGLESDisabled
 */
@property (nonatomic) BOOL openGLESDisabled;

#pragma makr - offline
/**
 * @brief 将离线地图解压到 Documents/3dvmap/ 目录下后，调用此函数使离线数据生效,
 对应的回调分别是 offlineDataWillReload:(MAMapView *)mapView, offlineDataDidReload:(MAMapView *)mapView.
 */
- (void)reloadMap;

@end

#pragma mark - MAMapViewDelegate
@protocol MAMapViewDelegate <NSObject>

@optional

/**
 * @brief 地图区域即将改变时会调用此接口
 * @param mapView 地图View
 * @param animated 是否动画
 */
- (void)mapView:(MAMapView *)mapView regionWillChangeAnimated:(BOOL)animated;

/**
 * @brief 地图区域改变完成后会调用此接口
 * @param mapView 地图View
 * @param animated 是否动画
 */
- (void)mapView:(MAMapView *)mapView regionDidChangeAnimated:(BOOL)animated;

/**
 *  地图将要发生移动时调用此接口
 *
 *  @param mapView       地图view
 *  @param wasUserAction 标识是否是用户动作
 */
- (void)mapView:(MAMapView *)mapView mapWillMoveByUser:(BOOL)wasUserAction;

/**
 *  地图移动结束后调用此接口
 *
 *  @param mapView       地图view
 *  @param wasUserAction 标识是否是用户动作
 */
- (void)mapView:(MAMapView *)mapView mapDidMoveByUser:(BOOL)wasUserAction;

/**
 *  地图将要发生缩放时调用此接口
 *
 *  @param mapView       地图view
 *  @param wasUserAction 标识是否是用户动作
 */
- (void)mapView:(MAMapView *)mapView mapWillZoomByUser:(BOOL)wasUserAction;

/**
 *  地图缩放结束后调用此接口
 *
 *  @param mapView       地图view
 *  @param wasUserAction 标识是否是用户动作
 */
- (void)mapView:(MAMapView *)mapView mapDidZoomByUser:(BOOL)wasUserAction;

/**
 * @brief 地图开始加载
 * @param mapView 地图View
 */
- (void)mapViewWillStartLoadingMap:(MAMapView *)mapView;

/**
 * @brief 地图加载成功
 * @param mapView 地图View
 */
- (void)mapViewDidFinishLoadingMap:(MAMapView *)mapView;

/**
 * @brief 地图加载失败
 * @param mapView 地图View
 * @param error 错误信息
 */
- (void)mapViewDidFailLoadingMap:(MAMapView *)mapView withError:(NSError *)error;

/**
 * @brief 根据anntation生成对应的View
 * @param mapView 地图View
 * @param annotation 指定的标注
 * @return 生成的标注View
 */
- (MAAnnotationView *)mapView:(MAMapView *)mapView viewForAnnotation:(id <MAAnnotation>)annotation;

/**
 * @brief 当mapView新添加annotation views时，调用此接口
 * @param mapView 地图View
 * @param views 新添加的annotation views
 */
- (void)mapView:(MAMapView *)mapView didAddAnnotationViews:(NSArray *)views;

/**
 * @brief 当选中一个annotation views时，调用此接口
 * @param mapView 地图View
 * @param view 选中的annotation views
 */
- (void)mapView:(MAMapView *)mapView didSelectAnnotationView:(MAAnnotationView *)view;

/**
 * @brief 当取消选中一个annotation views时，调用此接口
 * @param mapView 地图View
 * @param view 取消选中的annotation views
 */
- (void)mapView:(MAMapView *)mapView didDeselectAnnotationView:(MAAnnotationView *)view;

/**
 * @brief 在地图View将要启动定位时，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewWillStartLocatingUser:(MAMapView *)mapView;

/**
 * @brief 在地图View停止定位后，会调用此函数
 * @param mapView 地图View
 */
- (void)mapViewDidStopLocatingUser:(MAMapView *)mapView;

/**
 * @brief 位置或者设备方向更新后，会调用此函数
 * @param mapView 地图View
 * @param userLocation 用户定位信息(包括位置与设备方向等数据)
 * @param updatingLocation 标示是否是location数据更新, YES:location数据更新 NO:heading数据更新
 */
- (void)mapView:(MAMapView *)mapView didUpdateUserLocation:(MAUserLocation *)userLocation updatingLocation:(BOOL)updatingLocation;

/**
 * @brief 定位失败后，会调用此函数
 * @param mapView 地图View
 * @param error 错误号，参考CLError.h中定义的错误号
 */
- (void)mapView:(MAMapView *)mapView didFailToLocateUserWithError:(NSError *)error;

/**
 * @brief 拖动annotation view时view的状态变化，ios3.2以后支持
 * @param mapView 地图View
 * @param view annotation view
 * @param newState 新状态
 * @param oldState 旧状态
 */
- (void)mapView:(MAMapView *)mapView annotationView:(MAAnnotationView *)view didChangeDragState:(MAAnnotationViewDragState)newState
   fromOldState:(MAAnnotationViewDragState)oldState;

/**
 * @brief 根据overlay生成对应的Renderer
 * @param mapView 地图View
 * @param overlay 指定的overlay
 * @return 生成的覆盖物Renderer
 */
- (MAOverlayRenderer *)mapView:(MAMapView *)mapView rendererForOverlay:(id <MAOverlay>)overlay;

/**
 * @brief 当mapView新添加overlay renderers时，调用此接口
 * @param mapView 地图View
 * @param overlayRenderers 新添加的overlay renderers
 */
- (void)mapView:(MAMapView *)mapView didAddOverlayRenderers:(NSArray *)overlayRenderers;

/**
 * @brief 标注view的accessory view(必须继承自UIControl)被点击时，触发该回调
 * @param mapView 地图View
 * @param view callout所属的标注view
 * @param control 对应的control
 */
- (void)mapView:(MAMapView *)mapView annotationView:(MAAnnotationView *)view calloutAccessoryControlTapped:(UIControl *)control;

/**
 *  标注view的calloutview整体点击时，触发改回调。
 *
 *  @param mapView 地图的view
 *  @param view calloutView所属的annotationView
 */
- (void)mapView:(MAMapView *)mapView didAnnotationViewCalloutTapped:(MAAnnotationView *)view;

/**
 * @brief 当userTrackingMode改变时，调用此接口
 * @param mapView 地图View
 * @param mode 改变后的mode
 * @param animated 动画
 */
- (void)mapView:(MAMapView *)mapView didChangeUserTrackingMode:(MAUserTrackingMode)mode animated:(BOOL)animated;

/**
 * @brief 当openGLESDisabled变量改变时，调用此接口
 * @param mapView 地图View
 * @param openGLESDisabled 改变后的openGLESDisabled
 */
- (void)mapView:(MAMapView *)mapView didChangeOpenGLESDisabled:(BOOL)openGLESDisabled;

/**
 * @brief 当touchPOIEnabled == YES时，单击地图使用该回调获取POI信息
 * @param mapView 地图View
 * @param pois 获取到的poi数组(由MATouchPoi组成)
 */
- (void)mapView:(MAMapView *)mapView didTouchPois:(NSArray *)pois;

/**
 * @brief 单击地图回调，返回经纬度
 * @param mapView 地图View
 * @param coordinate 经纬度
 */
- (void)mapView:(MAMapView *)mapView didSingleTappedAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief 长按地图，返回经纬度
 * @param mapView 地图View
 * @param coordinate 经纬度
 */
- (void)mapView:(MAMapView *)mapView didLongPressedAtCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * @brief 地图初始化完成（在此之后，可以进行坐标计算）
 * @param mapView 地图View
 */
- (void)mapInitComplete:(MAMapView *)mapView;

#if MA_INCLUDE_INDOOR
/**
 *  室内地图出现,返回室内地图信息
 *
 *  @param mapView        地图View
 *  @param indoorInfo     室内地图信息
 */
- (void)mapView:(MAMapView *)mapView didIndoorMapShowed:(MAIndoorInfo *)indoorInfo;

/**
 *  室内地图楼层发生变化,返回变化的楼层
 *
 *  @param mapView        地图View
 *  @param indoorInfo     变化的楼层
 */
- (void)mapView:(MAMapView *)mapView didIndoorMapFloorIndexChanged:(MAIndoorInfo *)indoorInfo;

/**
 *  室内地图消失后,返回室内地图信息
 *
 *  @param mapView        地图View
 *  @param indoorInfo     室内地图信息
 */
- (void)mapView:(MAMapView *)mapView didIndoorMapHidden:(MAIndoorInfo *)indoorInfo;
#endif //end of MA_INCLUDE_INDOOR

#pragma mark - offline delegate
/**
 * @brief 离线地图数据将要被加载, 调用reloadMap会触发该回调，离线数据生效前的回调.
 * @param mapView 地图View
 */
- (void)offlineDataWillReload:(MAMapView *)mapView;

/**
 * @brief 离线地图数据加载完成, 调用reloadMap会触发该回调，离线数据生效后的回调.
 * @param mapView 地图View
 */
- (void)offlineDataDidReload:(MAMapView *)mapView;

@end
