//
//  TinyAppCommonDefine.h
//  TinyAppCommon
//
//  Created by 应俊康 on 2017/12/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef TinyAppCommonDefine_h
#define TinyAppCommonDefine_h

#define TALog(format,...) NSLog(@"[TinyApp] %@",  [NSString stringWithFormat:format,## __VA_ARGS__])

#define STR_EMPTY(str) (![str isKindOfClass:[NSString class]]||str.length <= 0)
#define IMAGE_FORMAT_ARRAY @[@"jpeg",@"jpg",@"png",@"gif",@"webp",@"tiff",@"bmp"]


#define kError                      @"error"
#define kError_Msg                  @"errorMessage"
#define TA_STORAGE_TAG              @"TINY_APP_SERVICE"
#define kUnknown_Error_Msg          @"未知错误"

#define TinyWebview_element         @"TinyWebview_element"
#define TinyWebview_Webview         @"TinyWebview_Webview"

#define TAWeakSelf(type)    __weak typeof(type) weak##type = type;
#define TAStrongSelf(type)  __strong typeof(type) type = weak##type;

typedef NS_ENUM(NSUInteger, TA_APP_TYPE) {
    TA_TINY_APP = 1,
    TA_DSL_APP = 2,
    TA_H5_APP = 0,
    TA_ERROR = -1
};

//event
#define kTAEvent_EmbedWebviewCreate @"tinyapp.embedwebview.create"


//UI
#define TA_ANIMATE_TIMTE     0.2f
#define TA_ASSISTANT_BGCOLOR [UIColor colorWithRed:0.1 green:0.1 blue:0.1 alpha:0.6]
#endif /* TinyAppCommonDefine_h */
