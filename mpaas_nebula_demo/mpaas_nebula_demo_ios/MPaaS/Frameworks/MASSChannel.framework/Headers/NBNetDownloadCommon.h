//
//  NBNetDownloadCommon.h
//  MASSChannel
//
//  Created by myy on 16/6/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSMutableDictionary+MASSDictionary.h"


typedef NS_ENUM(NSInteger, NBNetDSourceType)
{
    NBNetDSourceTypeFileid = 0,
    NBNetDSourceTypeTfs = 1,
};

typedef NS_ENUM(NSInteger, NBNetMMDPCmdType) {
    NBNetMMDPCmdTypeFileDownload = 0,
    NBNetMMDPCmdTypeImageDownload = 1,
    NBNetMMDPCmdTypeImageMark = 2,
};


typedef NS_ENUM(NSInteger, NBNetDResultType)
{
    NBNetDReturnData = 0,
    NBNetDReturnPath = 1,
    NBNetDReturnDataAndPath = 2,
};


typedef NS_ENUM(SInt32, NBNetDImageScale) {
    NBNetDImageScaleNoscale = 0,
    NBNetDImageScaleScale = 1,
    NBNetDImageScaleScaleandtrim = 2,
    NBNetDImageScaleTrim = 3,
};

typedef NS_ENUM(SInt32, NBNetDImageFormat) {
    NBNetDImageFormatNoformat = 0,
    NBNetDImageFormatPng = 1,
    NBNetDImageFormatJpg = 2,
    NBNetDImageFormatWebp = 3,
    NBNetDImageFormatTiff = 4,
    NBNetDImageFormatBmp = 5,
};


//@interface NBNetDImageParam : NSObject
//@property (nonatomic)UInt32 width;
//@property (nonatomic)UInt32 height;
//@property (nonatomic)NBNetDImageScale scale;
//@property (nonatomic)UInt32 quality;
//@property (nonatomic)NBNetDImageFormat format;
//@property (nonatomic)BOOL   gradual;
////+ (NBNetDImageParam*)buildFromZoomString:(NSString*)zoom;
///**
// *  打日志用
// *
// *  @return
// */
//- (NSString*)buildIndexKey;
///**
// *  组成真实django格式
// *
// *  @return
// */
//- (NSString*)toZoomString;
//@end


//@interface NBNetDTextMarkParam : NSObject
//@property (nonatomic,strong) NSString* text;
//@property (nonatomic,strong) NSString* color;
//@property (nonatomic)UInt32 size;
//@property (nonatomic)UInt32 transparency;
//@property (nonatomic)UInt32 position;
//@property (nonatomic)UInt32 fonttype;
///**
// *  tostring
// *
// *  @return
// */
//- (NSString*)buildIndexKey;
//@end


//@interface NBNetDImageMarkParam : NSObject
//@property (nonatomic,strong) NSString* fileid;
//@property (nonatomic)UInt32 position;
//@property (nonatomic)UInt32 width;
//@property (nonatomic)UInt32 height;
//@property (nonatomic)UInt32 x;
//@property (nonatomic)UInt32 y;
//@property (nonatomic)NBNetDImageScale scale;
//@property (nonatomic)UInt32 transparency;
//@property (nonatomic)UInt32 percent;
///**
// *  tostring
// *
// *  @return
// */
//- (NSString*)buildIndexKey;
//@end


