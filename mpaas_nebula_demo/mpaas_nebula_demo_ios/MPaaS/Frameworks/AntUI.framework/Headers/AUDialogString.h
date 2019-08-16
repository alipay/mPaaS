#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogString.h
//  AntUI
//
//  Created by 沫竹 on 2017/12/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface AUDialogString : NSObject

@property (nonatomic, copy) NSString *richString;

+ (instancetype)richString:(NSString *)string;

@end

NS_INLINE AUDialogString *AUDialogRichString(NSString *string)
{
    return [AUDialogString richString:string];
}

#endif//程序自动生成
