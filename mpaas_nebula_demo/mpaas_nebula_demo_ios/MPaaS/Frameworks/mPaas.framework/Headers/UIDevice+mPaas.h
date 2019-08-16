//
//  MPDeviceInfo.h
//  MPMisc
//
//  Created by shenmo on 6/25/15.
//  Copyright (c) 2015 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    kMPDevice_Screen_IPHONE_LOW,  // not retina iphone
    kMPDevice_Screen_IPHONE4,     // 4 or 4s
    kMPDevice_Screen_IPHONE5,     // 5 or 5s or 5c
    kMPDevice_Screen_IPHONE6,     // 6
    kMPDevice_Screen_IPHONE6p,    // 6 plus
    kMPDevice_Screen_IPAD_LOW,    // pad not retina
    kMPDevice_Screen_IPAD_RETINA, // pad with retina
} kMPDeviceScreenCategory;

@interface UIDevice (mPaas)

+ (kMPDeviceScreenCategory)deviceScreenCategory;

@end
