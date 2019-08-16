//
//  H5ImageLibrary.h
//  NebulaBiz
//
//  Created by 扶瑶 on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const NBIconType;

/**
 *  默认图片类型
 */
typedef NS_ENUM(NSInteger, NBImageType) {
    NBImageTypeUnknown = 0,
    NBImageTypeUser,                // 用户
    NBImageTypeFilter,              // 筛选
    NBImageTypeSearch,              // 搜索
    NBImageTypeAdd,                 // 添加
    NBImageTypeSettings,            // 设置
    NBImageTypeScan,                // 扫一扫
    NBImageTypeInfo,                // 信息
    NBImageTypeHelp,                // 帮助
    NBImageTypeLocate,              // 定位
    NBImageTypeMail                 // 邮箱
};

/**
 *  图片风格
 */
typedef NS_ENUM(NSInteger, NBImageStyle) {
    NBImageStyleBlue,
    NBImageStyleWhite
};

/**
 *  图片所在容器类型
 */
typedef NS_ENUM(NSInteger, NBImageContainer) {
    NBImageContainerUnknown = 0,
    NBImageContainerOptionMenu
};

@interface H5ImageLibrary : NSObject

/**
 *  通过icontype名称及容器生成UIImage对象
 *  内部通过iconfont/png等方式加载指定名称的默认图片
 *
 *  @param name      icontype名称
 *  @param container 容器
 *
 *  @return UIImage
 */
+ (UIImage *)imageWithName:(NSString *)name
                 container:(NBImageContainer)container
                imageStype:(NBImageStyle)style;


@end
