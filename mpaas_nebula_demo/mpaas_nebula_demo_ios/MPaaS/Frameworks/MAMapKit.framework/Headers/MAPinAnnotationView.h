//
//  MAPinAnnotationView.h
//  MAMapKitDemo
//
//  Created by songjian on 13-1-7.
//  Copyright (c) 2013年 songjian. All rights reserved.
//

#import "MAAnnotationView.h"

typedef NS_ENUM(NSInteger, MAPinAnnotationColor){
    MAPinAnnotationColorRed = 0,    //!< 红色大头针
    MAPinAnnotationColorGreen,      //!< 绿色大头针
    MAPinAnnotationColorPurple      //!< 紫色大头针
};
//typedef NSUInteger MAPinAnnotationColor;

/*!
 @brief 提供类似大头针效果的annotation view
 */
@interface MAPinAnnotationView : MAAnnotationView

/*!
 @brief 大头针的颜色，有MAPinAnnotationColorRed, MAPinAnnotationColorGreen, MAPinAnnotationColorPurple三种
 */
@property (nonatomic) MAPinAnnotationColor pinColor;

/*!
 @brief 动画效果
 */
@property (nonatomic) BOOL animatesDrop;

@end
