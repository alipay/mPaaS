//
//  MAAnnotationView.h
//  MAMapKitDemo
//
//  Created by songjian on 13-1-7.
//  Copyright (c) 2013年 songjian. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, MAAnnotationViewDragState)
{
    MAAnnotationViewDragStateNone = 0,      //!< 静止状态
    MAAnnotationViewDragStateStarting,      //!< 开始拖动
    MAAnnotationViewDragStateDragging,      //!< 拖动中
    MAAnnotationViewDragStateCanceling,     //!< 取消拖动
    MAAnnotationViewDragStateEnding         //!< 拖动结束
};

@protocol MAAnnotation;

/**
 标注view
 */
@interface MAAnnotationView : UIView

/**
*  初始化并返回一个annotation view
*
*  @param annotation      关联的annotation对象
*  @param reuseIdentifier 如果要重用view,传入一个字符串,否则设为nil,建议重用view
*
*  @return 初始化成功则返回annotation view,否则返回nil
*/
- (id)initWithAnnotation:(id <MAAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;

/**
 *  复用标识
 */
@property (nonatomic, readonly, copy) NSString *reuseIdentifier;

/*!
 @brief z值，大值在上，默认为0。
 */
@property (nonatomic, assign) NSInteger zIndex;


/**
 *  当从reuse队列里取出时被调用, 子类重新必须调用super
 */
- (void)prepareForReuse;

/**
 *  关联的annotation
 */
@property (nonatomic, strong) id <MAAnnotation> annotation;

/**
 *  显示的image
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  默认情况下, annotation view的中心位于annotation的坐标位置，可以设置centerOffset改变view的位置，正的偏移使view朝右下方移动，负的朝左上方，单位是屏幕坐标
 */
@property (nonatomic) CGPoint centerOffset;

/**
 *  默认情况下, 弹出的气泡位于view正中上方，可以设置calloutOffset改变view的位置，正的偏移使view朝右下方移动，负的朝左上方，单位是屏幕坐标
 */
@property (nonatomic) CGPoint calloutOffset;

/**
 *  默认为YES,当为NO时view忽略触摸事件
 */
@property (nonatomic, getter=isEnabled) BOOL enabled;

/**
 *  是否高亮
 */
@property (nonatomic, getter=isHighlighted) BOOL highlighted;

/**
 *  设置是否处于选中状态, 外部如果要选中请使用mapView的selectAnnotation方法
 */
@property (nonatomic, getter=isSelected) BOOL selected;
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;

/**
 *  是否允许弹出默认callout
 */
@property (nonatomic) BOOL canShowCallout;

/**
 *  显示在气泡左侧的view
 */
@property (strong, nonatomic) UIView *leftCalloutAccessoryView;

/**
 *  显示在气泡右侧的view
 */
@property (strong, nonatomic) UIView *rightCalloutAccessoryView;

/**
 *  是否支持拖动
 */
@property (nonatomic, getter=isDraggable) BOOL draggable NS_AVAILABLE(NA, 4_0);

/**
 *  当前view的拖动状态
 */
@property (nonatomic) MAAnnotationViewDragState dragState NS_AVAILABLE(NA, 4_0);

/**
 *  设置view的拖动状态
 *
 *  @param newDragState 新的拖动状态
 *  @param animated     是否动画
 */
- (void)setDragState:(MAAnnotationViewDragState)newDragState animated:(BOOL)animated NS_AVAILABLE(NA, 4_2);

@end
