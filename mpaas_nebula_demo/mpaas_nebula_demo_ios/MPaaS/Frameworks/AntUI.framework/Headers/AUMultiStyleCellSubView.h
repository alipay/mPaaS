#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_CardMenu_AUCardMenu//程序自动生成
//
//  AUMultiStyleCellSubView.h
//  AntUI
//
//  Created by 祝威 on 16/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUCellDataModel.h"




//
@protocol AUButtonPanelDelegate <NSObject>

@required
- (void)DidClickButton:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath;

@end

/**
 * needIcon标记当前自定义button是否需要设置image
 */
@interface AUActionButton : UIButton

@property (nonatomic, assign) BOOL needIcon;

@end

//

/**
 * 生成buttons的面板，目前支持持生成两行两列的button，若需扩展，后续将会提供
 */

@interface AUButtonPanel : UIView
{
    NSArray *_buttonArray;
    NSArray *_CellViewArray;
}
@property (nonatomic, weak) id<AUButtonPanelDelegate> buttonDelegate;

- (instancetype)initWithFrame:(CGRect)frame buttonArray:(NSArray *)buttonArray cellViewArray:(NSArray *)CellViewArray;

@end


@class AUIconView;
/**
 *  图标 + 主标题 + 位于主标题下方的副标题 的cellView
 */

@interface AUHeaderCellView : UIControl

@property (nonatomic, strong) AUIconView *iconImg;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *descLabel;
@property (nonatomic, strong) AUIconView *checkMarkImageView; // 对勾
@property (nonatomic, strong) AUIconView *indicatorImageView; // 右指示箭头
@property (nonatomic, assign) BOOL hightlightState;

- (instancetype)initWithFrame:(CGRect)frame dataModel:(AUCellDataModel *)model;

@end

#endif//程序自动生成
