//
//  MAGroundOverlayRenderer.h
//  MapKit_static
//
//  Created by Li Fei on 11/13/13.
//  Copyright (c) 2013 songjian. All rights reserved.
//

#if MA_INCLUDE_OVERLAY_GROUND

#import "MAOverlayRenderer.h"
#import "MAGroundOverlay.h"

/**
 *  此类是将MAGroundOverlay中的覆盖图片显示在地图上的renderer
 */
@interface MAGroundOverlayRenderer : MAOverlayRenderer

/**
*  具有覆盖图片，以及图片覆盖的区域
*/
@property (nonatomic ,readonly) MAGroundOverlay *groundOverlay;

/**
 *  根据指定的GroundOverlay生成将图片显示在地图上Renderer
 *
 *  @param groundOverlay 制定了覆盖图片，以及图片的覆盖区域的groundOverlay
 *
 *  @return 以GroundOverlay新生成Renderer
 */
- (instancetype)initWithGroundOverlay:(MAGroundOverlay *)groundOverlay;

@end

#endif
