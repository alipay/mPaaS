#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUMultiListItem//程序自动生成
//
//  AUMultiListItem.h
//  AntUI
//
//  Created by 莜阳 on 17/3/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUListItemModel.h"
#import "AUBaseListItem.h"

typedef AUListItemModel<AUMultiListItemDelagate, AUMultiListBottomAssistDelagate> AUMultiListItemModel;

@interface AUMultiListItem : AUBaseListItem

// 设置cell的model数据
- (void)setDataModel:(void(^)(AUMultiListItemModel * model))modelBlock;

// 默认以屏幕宽度来计算cell的高度
+ (CGFloat)cellHeightForModel:(void(^)(AUMultiListItemModel * model))modelBlock;

@end


#endif//程序自动生成
