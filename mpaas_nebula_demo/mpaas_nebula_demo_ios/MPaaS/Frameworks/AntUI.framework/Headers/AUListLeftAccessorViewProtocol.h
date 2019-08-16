#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUListLeftAccessorViewProtocol.h
//  AntUI
//
//  Created by maizhelun on 2017/3/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AUListItemLeftAccessorType) {
    AUListItemLeftAccessorTypeNone,
    AUListItemLeftAccessorTypeIcon,
    AUListItemLeftAccessorTypeLabel,
    AUListItemLeftAccessorTypeView,
};

typedef NS_ENUM(NSInteger, AUListItemRightAccessorType) {
    AUListItemRightAccessorTypeNone,
    AUListItemRightAccessorTypeIcon,
    AUListItemRightAccessorTypeView, // 自定义UIView的子类
};

typedef NS_ENUM(NSInteger, AUListItemBadgeAreaType) {
    AUListItemBadgeAreaTypeDefault,
};

@protocol AUListItemLeftAccessorViewProtocol <NSObject>

@property (nonatomic, assign) AUListItemLeftAccessorType leftAccessorType;
@property (nonatomic, strong) UIView *leftAccessorView;

@end



#endif//程序自动生成
