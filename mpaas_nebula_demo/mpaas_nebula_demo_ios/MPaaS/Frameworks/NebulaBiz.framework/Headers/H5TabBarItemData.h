//
//  H5TabBarItemData.h
//  NebulaBiz
//
//  Created by Glance on 17/2/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5TabBarItemData : NSObject

//"url": "https://www.baidu.com",//兼容魔法参数
//"launchParams":{canPullDown:true},
//"name": "tab1",
//"tag": "tab11",
//"icon": "https://zos.alipayobjects.com/rmsportal/IOwBUWsFOQyNYhhAxDgb.png",
//"activeIcon": "https://zos.alipayobjects.com/rmsportal/KdyZNLUKgFfAAHreQzoj.png",
//"redDot": -1


@property (nonatomic, strong) NSString *url;
@property (nonatomic, copy) NSString *launchParamsTag;
@property (nonatomic, copy) NSDictionary *launchParams;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *tag;
@property (nonatomic, strong) NSNumber *textColor;
@property (nonatomic, strong) NSNumber *selectedColor;
@property (nonatomic, strong) NSString *icon;
@property (nonatomic, strong) NSString *activeIcon;
@property (nonatomic, strong) NSString *redDot;
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, assign) float waitRender;
@property (nonatomic, assign) float transDuration;
@property(nonatomic, assign) float unselectedScale; // 非选中状态的放大值, 最大1.5倍,暂时不支持缩小
@property(nonatomic, assign) float selectedScale;   // 选中状态的放大值, 最大1.5倍,暂时不支持缩小



- (instancetype) initWithDictionary:(NSDictionary *)dict;


@end
