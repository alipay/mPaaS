#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUTableview//程序自动生成
//
//  AUTableview.h
//  AntUI
//
//  Created by 莜阳 on 17/4/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@interface AUTableView : UITableView

@end

/**
 * 根据IndexPath返回无文案时Section的HeaderView
 *
 */
UIView *AUSegmentEmptyHeaderViewForIndexPath(NSInteger section);

/**
 * 根据IndexPath返回无文案时Section的HeaderView的高度
 * 2018.10.1 目前统一为48px;
 */
CGFloat AUSegmentEmptyHeaderHeightForIndexPath(NSInteger section);

#endif//程序自动生成
