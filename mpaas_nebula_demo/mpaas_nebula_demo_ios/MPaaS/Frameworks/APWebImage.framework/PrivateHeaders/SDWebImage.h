/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Florent Vilmart
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <APWebImage/SDWebImageCompat.h>

#if SD_UIKIT
#import <UIKit/UIKit.h>
#endif

//! Project version number for WebImage.
FOUNDATION_EXPORT double WebImageVersionNumber;

//! Project version string for WebImage.
FOUNDATION_EXPORT const unsigned char WebImageVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <WebImage/PublicHeader.h>

#import <APWebImage/SDWebImageManager.h>
#import <APWebImage/SDWebImageCacheKeyFilter.h>
#import <APWebImage/SDWebImageCacheSerializer.h>
#import <APWebImage/SDImageCacheConfig.h>
#import <APWebImage/SDImageCache.h>
#import <APWebImage/SDMemoryCache.h>
#import <APWebImage/SDDiskCache.h>
#import <APWebImage/SDImageCacheDefine.h>
#import <APWebImage/SDImageCachesManager.h>
#import <APWebImage/UIView+WebCache.h>
#import <APWebImage/UIImageView+WebCache.h>
#import <APWebImage/UIImageView+HighlightedWebCache.h>
#import <APWebImage/SDWebImageDownloaderConfig.h>
#import <APWebImage/SDWebImageDownloaderOperation.h>
#import <APWebImage/SDWebImageDownloaderRequestModifier.h>
#import <APWebImage/SDImageLoader.h>
#import <APWebImage/SDImageLoadersManager.h>
#import <APWebImage/UIButton+WebCache.h>
#import <APWebImage/SDWebImagePrefetcher.h>
#import <APWebImage/UIView+WebCacheOperation.h>
#import <APWebImage/UIImage+Metadata.h>
#import <APWebImage/UIImage+MultiFormat.h>
#import <APWebImage/UIImage+MemoryCacheCost.h>
#import <APWebImage/SDWebImageOperation.h>
#import <APWebImage/SDWebImageDownloader.h>
#import <APWebImage/SDWebImageTransition.h>
#import <APWebImage/SDWebImageIndicator.h>
#import <APWebImage/SDImageTransformer.h>
#import <APWebImage/UIImage+Transform.h>
#import <APWebImage/SDAnimatedImage.h>
#import <APWebImage/SDAnimatedImageView.h>
#import <APWebImage/SDAnimatedImageView+WebCache.h>
#import <APWebImage/SDImageCodersManager.h>
#import <APWebImage/SDImageCoder.h>
#import <APWebImage/SDImageAPNGCoder.h>
#import <APWebImage/SDImageGIFCoder.h>
#import <APWebImage/SDImageIOCoder.h>
#import <APWebImage/SDImageFrame.h>
#import <APWebImage/SDImageCoderHelper.h>
#import <APWebImage/SDImageGraphics.h>
#import <APWebImage/UIImage+GIF.h>
#import <APWebImage/UIImage+ForceDecode.h>
#import <APWebImage/NSData+ImageContentType.h>
#import <APWebImage/SDWebImageDefine.h>
#import <APWebImage/SDWebImageError.h>

// Mac
#if __has_include(<SDWebImage/NSImage+Compatibility.h>)
#import <APWebImage/NSImage+Compatibility.h>
#endif
#if __has_include(<SDWebImage/NSButton+WebCache.h>)
#import <APWebImage/NSButton+WebCache.h>
#endif
#if __has_include(<SDWebImage/SDAnimatedImageRep.h>)
#import <APWebImage/SDAnimatedImageRep.h>
#endif

// MapKit
#if __has_include(<SDWebImage/MKAnnotationView+WebCache.h>)
#import <APWebImage/MKAnnotationView+WebCache.h>
#endif
