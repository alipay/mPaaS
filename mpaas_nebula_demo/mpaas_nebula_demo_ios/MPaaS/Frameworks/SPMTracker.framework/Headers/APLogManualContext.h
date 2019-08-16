//
//  APLogSpmContext.h
//  APRemoteLogging
//
//  Created by majie on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//重构手动spm埋点，解决ios8以下，生命周期的问题
@interface APLogManualPageInfo : NSObject<NSCopying>

@property (atomic, weak) NSObject *weakIndex;

//当前页面流水号
@property (atomic, strong) NSString *pageId;

//当前页面spmid
@property (atomic, strong) NSString *pageSpmId;

//打开时间
@property (atomic, strong) NSNumber *t1;

//页面打开时间
@property (atomic, strong) NSString *startTime;

//应用appid
@property (atomic, strong) NSString *appId;

//是否已经调用过pageEnd
@property (atomic, assign) BOOL didEnd;
// 来源cell的spm，没有兜底，不许求改
@property (atomic, copy) NSString *referSpm;
// 来源cell的spm，允许修改，优先使用上个页面的lastSPM兜底，其次上个页面的pageSpmId兜底
@property(atomic, strong) NSString *srcSPM;
// 当前页面最后点击的SPM
@property(atomic, strong) NSString *lastSPM;
// refer的PageInfo
@property(atomic, strong) APLogManualPageInfo *referPageInfo;

// 全链路 p-root
@property(atomic, copy) NSString *pRoot;
// 全链路 p-pre
@property(atomic, copy) NSString *pPre;
// 全链路 p-pre2
@property(atomic, copy) NSString *pPre2;
// 页面重复（锁屏、进后台）埋的点
@property(atomic)  BOOL isPageRepeat;
// 多步回退
@property(atomic) BOOL isMultistepBack;
// 页面刷新
@property(atomic) BOOL isRefresh;
// refer2 前两步的页面
@property(atomic, copy) NSString *refer;
@property(atomic, copy) NSString *refer2;

+ (void)filterPageInfo:(APLogManualPageInfo *)pageInfo;
+ (APLogManualPageInfo *)createPageInfoWithSpmId:(NSString *)spmid index:(NSObject *)index;
+ (void)updatePageId:(APLogManualPageInfo *)pageInfo WithSpmid:(NSString *)spmid;

@end

@interface APLogManualContext : NSObject

+ (instancetype)sharedInstance;

//上一个页面的spmid
@property (atomic, strong) NSString *lastPageSpmId;

//上一个页面流水号
@property (atomic, strong) NSString *lastPageId;

//上一个页面
@property (atomic, strong) NSString *lastViewId;

//上一个页面的pageInfo，包含srcSPM、lastSPM、pageId等
@property (atomic, strong) APLogManualPageInfo *lastPageInfo;


- (APLogManualPageInfo *)pageInfoForKey:(NSString *)key;
- (void)updatePageInfo:(APLogManualPageInfo *)pageInfo withSpmId:(NSString *)spmId;
- (void)updatePageInfo:(NSObject *)index withSrcSpm:(NSString *)srcSpm;
- (void)updatePageInfo:(APLogManualPageInfo *)pageInfo withLastSpm:(NSString *)lastSpm;
- (void)insertPageInfo:(APLogManualPageInfo *)pageInfo forKey:(NSString *)key;
- (void)checkWeakPageInfo;
- (NSString *)getSrcSpmFromDict:(NSObject *)index;

@end

