//
//  TYBackgroundActivityMaintainer.h
//  TianYan
//
//  Created by qiwei on 2018/7/11.
//  Copyright © 2018 Alipay. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "TYBackgroundActivity.h"

#if defined __cplusplus
extern "C" {
#endif
    
    void TYBackgroundActivity_OnEvent(TYBackgroundEventSource source,TYBackgroundEventTime time);
    
#if defined __cplusplus
}
#endif
