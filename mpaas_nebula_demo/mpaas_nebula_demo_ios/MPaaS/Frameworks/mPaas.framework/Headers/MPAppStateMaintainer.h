//
//  MPAppStateMaintainer.h
//  APMPaaS
//
//  Created by qiwei on 01/12/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#if defined __cplusplus
extern "C" {
#endif

void MPAppState_OnApplicationDidFinishLaunching(UIApplication *application);
void MPAppState_OnApplicationDidBecomeActive(UIApplication *application);
void MPAppState_OnApplicationDidEnterBackground(UIApplication *application);
void MPAppState_OnApplicationWillEnterForeground(UIApplication *application);

#if defined __cplusplus
};
#endif
