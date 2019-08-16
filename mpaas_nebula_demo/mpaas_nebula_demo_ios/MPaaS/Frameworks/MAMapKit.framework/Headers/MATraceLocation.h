//
//  MATraceLocation.h
//  MAMapKit
//
//  Created by shaobin on 16/9/1.
//  Copyright © 2016年 AutoNavi. All rights reserved.
//

#if MA_INCLUDE_TRACE_CORRECT

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface MATracePoint : NSObject

@property (nonatomic, assign) CLLocationDegrees latitude;
@property (nonatomic, assign) CLLocationDegrees longitude;

@end

@interface MATraceLocation : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D loc;
@property (nonatomic, assign) double angle;
@property (nonatomic, assign) double speed; //单位km/h
@property (nonatomic, assign) double time; //单位毫秒

@end

#endif
