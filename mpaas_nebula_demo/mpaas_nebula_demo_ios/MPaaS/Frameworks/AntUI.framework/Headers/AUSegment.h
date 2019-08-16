#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Segment_AUSegment//程序自动生成
//
//  AUSegment.h
//  AntUI
//
//  Created by sara on 16/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUSegmentedControlItem.h"
#import "UIView+Helper.h"

#define UI_AUSegment

@class AUSegment;
@class AUSegmentItemModel;


@protocol AUSegmentedControlDelegate <UIScrollViewDelegate>
//AUSegment点击事件回调
@optional

- (void)didSegmentValueChanged:(AUSegment*)segmentControl;

- (void)didSelectSegmentItemModel:(AUSegmentItemModel*)selectedItemModel;//

@end

// segment 默认高度
#define     AUSegmentHeight     AU_SPACE13

/**
    分段切换组件
    文档地址 https://yuque.antfin-inc.com/antui/auidoc/ios_ausegment
 */
@interface AUSegment : UIScrollView

/**
 初始化函数

 @param frame  frame
 @param titles 数组：包含所有标题字符串

 @return 返回AUSegment实例
 */
- (instancetype)initWithFrame:(CGRect)frame titles:(NSArray<NSString*> *)titles;

/**
 禁用init方法
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 禁用initWithFrame方法
 */
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/**
 AUSegmentedControlDelegate
 */
@property (nonatomic, weak)     id <AUSegmentedControlDelegate> delegate;

/**/

/**
 标题数组
 */
@property (nonatomic, strong)   NSMutableArray *titles;

/**
 * 菜单字体
 */
@property (nonatomic, copy) UIFont *titleFont;

/**
 当前选中的segment
 */
@property (nonatomic, assign)   NSInteger selectedSegmentIndex;


/**
 选中项的颜色（包括文字和滑块）
 */
@property (nonatomic, copy)     UIColor *selecedColor;

/**
 * 每个文字菜单水平方向的左右边距
 * 默认为21像素
 * 当为红点样式时，则fixedItemWidth不起作用，所有菜单不是固定宽度
 */
@property(nonatomic, assign)    NSInteger textHorizontalPadding;

/**
 * 是否使用固定菜单宽度
 * 默认YES，方便兼容老的菜单样式
 * 当为YES时，则horizontalPadding不起作用，所有菜单固定同一宽度
 */
@property (nonatomic, assign) BOOL fixedItemWidth;

/**
 * 是否自动滚动选中菜单项到合适位置（优先中间位置，不够位置时再靠边显示）
 * 默认为NO
 */
@property (nonatomic, assign) BOOL autoScroll;

/**
 * 点击后是否自动更新指示条到当前选中item的下标
 * 默认为YES
 */
@property (nonatomic, assign) BOOL autoChangeSelectedIndex;

/*
 * model数组
 */
@property(nonatomic, strong) NSMutableArray<AUSegmentItemModel *> *itemModels;

/*
 * 10.1.60 新增
 * itemPanelMargin 设置第一个item左边距离边界的间距，最后一个item的右边距离j边界的间距自动与之一致
 * 设置之后则textHorizontalPadding不起作用
 */
@property (nonatomic, assign) CGFloat itemToEdgeSpace;

/*
 * 10.1.60 新增，与itemPanelMargin配合使用
 * itemSpace 设置每个item之间的间距，从第一个item的右边开始算，其与第二个item之间的间距
 * 设置之后则textHorizontalPadding不起作用
 */
@property (nonatomic, assign) CGFloat itemSpace;

/**
 支持中间插入多项

 @param array 插入的标题数组s
 @param indexes 插入的indexs
 */
- (void)insertTitleArray:(NSArray<NSString*> *)array atIndexes:(NSIndexSet *)indexes;


/**
 支持在末尾新增多项

 @param array 新增的标题数组
 */
- (void)addTitleArray:(NSArray<NSString*>*)array;

/**
 * 设置自动滚动到指定下标位置，注意：只滚动展示item，选中指示条保持不变
 * 默认与selectedSegmentIndex(即选中项保持一致)
 */
- (void)autoScrollToIndex:(NSInteger)index;

- (BOOL)segmentItemIsInVisualAear:(NSInteger)index;

@end


@interface AUSegmentItemModel : NSObject

@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) UIImage *img;
@property(nonatomic, copy) NSString *imgId;
@property(nonatomic, copy) NSString *badgeNumber;
@property(nonatomic, copy) NSString *badgeWidgetId;
@property(nonatomic, assign) BOOL badgeReserved;    // 设置当前item是否要预留红点位置，如果不预留则红点展示时界面可能有跳动感
@property(nonatomic, strong) NSDictionary *extendInfo; // 扩展字段

@end


@interface AUSegment (ItemModel)



/**
 * 第二版的初始化函数
 * @param frame  frame
 * @param menus  item 数组
 */
- (instancetype) initWithFrame:(CGRect)frame menus:(NSArray<AUSegmentItemModel *>*)menus;

/**
 支持更新控件item项
 
 @param items 需要更新的item数组，主要用于增删或者全部更新已有model数据
 */
- (void)updateItems:(NSArray<AUSegmentItemModel *>*)items;

/**
 支持更新控件item项
 
 @param items 删除已有数据，重新替换为新的item数据
 */
- (void)updateItemModel:(AUSegmentItemModel *)model
                atIndex:(NSInteger)index;

@end


// 右边显示行动点按钮，默认显示加号 +
@interface AUSegment (AUActionIcon)

- (void)showActionIcon:(BOOL)showIcon target:(id)target action:(SEL)action;

@end



#endif//程序自动生成
