#import <Foundation/Foundation.h>


#import "APMImageCompressOptions.h"

@interface APMGIFCompression : NSObject

+ (NSData *)compressGIFData:(NSData *)gifData compressLevel:(APMImageCompressQualityLevelEnum)compressLevel maxEdge:(int)maxEdge;

@end
