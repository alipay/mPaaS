#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUListItemProtocols.h
//  AntUI
//
//  Created by sara on 16/10/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^AUImageRequestProgressBlock)(double percentage,long long partialBytes,long long totalBytes);
typedef void (^AUImageRequestCompletionBlock)(UIImage *image, NSError *error);

@interface AUImageRequestModel : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *business;
@property (nonatomic, strong) UIImage *placeholder;
@property (nonatomic, assign) CGSize zoom;
@property (nonatomic, assign) CGSize originalSize;
@property (nonatomic, copy) AUImageRequestProgressBlock progress;
@property (nonatomic, copy) AUImageRequestCompletionBlock complete;

@end

/**
 AUSingleTitleListItem可以设置和访问的数据项
 */
@protocol AUSingleTitleListItemModelDelegate <NSObject>

@property (nonatomic, copy)      NSString   *subtitle;          //副标题
@property (nonatomic, strong)    UIImage    *leftImage;         //左边图片
@property (nonatomic, strong)    UIImage    *rightImage;        //右边文字前的图片
@property (nonatomic, strong)    UIImage    *rightAssistImage;  //右边文字后的图片
@property (nonatomic, assign)    CGSize  leftimageSize;         //左边图片大小可定制，不设置使用默认大小22
@property (nonatomic, assign)    CGSize  rightAssistImageSize;  //右边文字后的图片大小可定制，不设置使用默认大小22

@end

/**
 AUDoubleTitleListItem可以设置和访问的数据项
 */
@protocol AUDoubleTitleListItemModelDelegate <NSObject>

@property (nonatomic, copy)      NSString   *subtitle;          //副标题
@property (nonatomic, strong)    UIImage    *leftImage;         //左边图片
@property (nonatomic, strong)    AUImageRequestModel   *leftImgRequest;  //左边图片的请求参数
@property (nonatomic, assign)    CGSize  leftimageSize;         //左边图片大小可定制，不设置使用默认大小
@property (nonatomic, copy)      NSString   *timeString;        //右边时间
@property (nonatomic, copy)      NSString   *rightAssistString; //右边辅助信息，默认居中
@property (nonatomic, assign)    NSInteger subtitleLines;       //辅助标题行数，(业务方必须指定具体行数)
@property (nonatomic, strong) UIImage *rightImage;  // 默认居中，默认尺寸44px
//@property (nonatomic, assign)   BOOL    showAccessory;          //是否展示辅助图标

@end

/**
 AUCheckBoxListItem可以设置和访问的数据项

 */
@protocol AUCheckBoxListItemModelDelegate <NSObject>
//@property (nonatomic, assign)   BOOL    showAccessory;          //是否展示辅助图标

@end

/**
 AUMultiListItemDelagate 可以设置和访问的数据项
 
 */
@protocol AUMultiListItemDelagate <NSObject>

@property (nonatomic, copy)   NSString *subtitle;                   //副标题
@property (nonatomic, strong) UIImage    *leftImage;                //左边图片
//@property (nonatomic, assign) CGSize    leftimageSize;                //左边图片
@property (nonatomic, assign) BOOL    showAccessory;                //是否展示辅助图标
@property (nonatomic, assign) NSInteger subtitleLines;     // 设置副标题的行数

@end


/**
 AUMultiListBottomAssistDelagate 可以设置和访问的数据项
 
 */
@protocol AUMultiListBottomAssistDelagate <NSObject>

@property (nonatomic, strong) NSString *originalText;      // 文字来源
@property (nonatomic, strong) NSString *timeDesc;         // 时间信息描述
@property (nonatomic, strong) NSString *othersDesc;      // 其他描述信息

@end


/**
 AUParallelTitleListItem可以设置和访问的数据项
 
 */
@protocol AUParallelTitleListItemModelDelegate <NSObject>
@property (nonatomic, copy)      NSString   *subtitle;          //标题二
@property (nonatomic, copy)      NSString   *describe;          //描述一
@property (nonatomic, copy)      NSString   *subDescribe;       //描述二

@end


/**
 AULineBreakListItem可以设置和访问的数据项
 
 */
@protocol AULineBreakListItemModelDelegate <NSObject>
@property (nonatomic, copy)      NSString   *subtitle;          //副标题
@end


/**
 AUCouponsItemDelagate 可以设置和访问的数据项
 
 */
@protocol AUCouponsItemDelagate <NSObject>

@property (nonatomic, copy)   NSString *subtitle;              //副标题
@property (nonatomic, strong) UIImage    *leftImage;          //左边图片
@property (nonatomic, strong) UIImage    *leftImageUrl;      //左边图片链接
@property (nonatomic, strong) NSString *assistDesc;         // 文字辅助说明
@property (nonatomic, assign) NSInteger totalWidth;        // 设置卡片宽度

@end


/**
 TTTAttributeLabelDelagate 富文本协议
 
 */

@protocol TTTAttributeLabelDelagate <NSObject>

@property (nonatomic, copy)   NSString *attributeText;              // 富文本内容
@property (nonatomic, copy)   NSString *linkText;                   // 富文本链接文案
@property (nonatomic, copy)   NSString *linkURL;                   // 富文本跳转链接

@end

#endif//程序自动生成
