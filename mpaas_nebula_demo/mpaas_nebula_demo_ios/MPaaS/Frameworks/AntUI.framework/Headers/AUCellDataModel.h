#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_CardMenu_AUCardMenu//程序自动生成
//
//  AUCellDataModel.h
//  AntUI
//
//  Created by 祝威 on 16/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/*！
 @class       AUMultiStyleCellView
 @abstract    UIView
 @discussion  menu中的子view
 */

@interface AUCellDataModel : NSObject

@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *titleText;
@property (nonatomic, strong) NSString *descText;
@property (nonatomic, strong) NSString *checkMarkUrl; // 对勾
@property (nonatomic, strong) NSString *indicatorUrl; // 右指示箭头
@property (nonatomic, strong) NSArray *buttonsArray; // NSArray<NSString>
@property (nonatomic, strong) NSDictionary *extendDic; // 给业务方使用的扩展字段
@property (nonatomic, assign) BOOL selectedState; // 当前model选中状态，默认是 NO 即不选中
@property (nonatomic, assign) BOOL highlightState; //是否要高亮，默认NO,不高亮

@end

#endif//程序自动生成
