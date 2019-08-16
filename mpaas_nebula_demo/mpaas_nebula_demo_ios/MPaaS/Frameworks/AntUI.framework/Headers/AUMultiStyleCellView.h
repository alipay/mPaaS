#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_CardMenu_AUCardMenu//程序自动生成
//
//  AUMultiStyleCellView.h
//  AntUI
//
//  Created by 祝威 on 16/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUCellDataModel.h"

@class AUMultiStyleCellView;
@protocol AUMultiStyleCellDelegate <NSObject>

@optional
/**
 *  点击事件回调
 *
 *  @param dataModel 点击的view对应的数据模型
 *  @param indexPath 点击的view在CellDataModel中的下标(若 CellDataModel.buttonsArray == nil ,则 row 默认取值为 -1)
 */
- (void)DidClickCellView:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath;
- (void)DidClickCellButton:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath;
- (void)DidClickCellView:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath cellView:(AUMultiStyleCellView *)cellView;
@end


/**
 *  融合多样式的cellview
 *  1. 图标 + 主标题
 *  2. 图标 + 主标题 + 位于主标题下方的副标题
 *  3. 图标 + 主标题 + 多行多列的带边框按钮控件
 */

@interface AUMultiStyleCellView : UIView

@property (nonatomic, weak) id<AUMultiStyleCellDelegate> delegate;
@property (nonatomic, strong) NSArray *cellDataArray;

// 如果cellDataArray为空等同于调用 initWithFrame 方法
- (instancetype)initWithFrame:(CGRect)frame
                cellDataArray:(NSArray *)cellDataArray
                     isUpward:(BOOL)isUpward;

// 提供处理当前cellView选中与否的状态
- (void)updateSelectedState;


@end

#endif//程序自动生成
