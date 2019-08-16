#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUListItemModel.h
//  AntUI
//
//  Created by sara on 16/10/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AUListItemProtocols.h"
#import "AUScalingModel.h"

@interface AUListItemModel : NSObject

@property (nonatomic, copy)      NSString   *title;             //主标题
@property (nonatomic, assign)   UITableViewCellAccessoryType accessoryType; //辅助图标样式
@property (nonatomic, assign)   BOOL needCorner;    // 是否需要圆角，默认有圆角
@property (nonatomic, strong)   AUScalingModel *scalingModel; //放大模式
@property (nonatomic, assign)   BOOL higherleftTitlePriority ; //是否优先保证左边显示

- (void)clearData;


@end


#endif//程序自动生成
