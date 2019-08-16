#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUDoubleTitleListItem//程序自动生成
//
//  AUDoubleTitleListItem.h
//  AntUI
//
//  Created by sara on 16/10/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBaseListItem.h"

typedef NS_ENUM(NSInteger, AUDoubleTitleListItemStyle) {
    AUDoubleTitleListItemStyleDefault, //有左图，高度是144，图标76 (不含分割线，单位:px，包含分割线的实际高度是146px)
    AUDoubleTitleListItemStyleValue1,  // 无左图，高度144，(不含分割线，单位:px，包含分割线的实际高度是146px)
    AUDoubleTitleListItemStyleValue2,  // 有左图，高度144，图标88 (单位:px，同上)
};

@interface AUDoubleTitleListItem : AUBaseListItem<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate>

@property(nonatomic,strong) UILabel *subtitleLabel;
@property(nonatomic,strong) UIImageView *leftImageView;
@property(nonatomic,strong) UILabel* timeLabel;
@property(nonatomic,strong) UILabel *rightAssistLabel;

/**
 设置cell展示所需的所有数据

 @param block 传入的block
 */
- (void)setModelBlock:(void(^)(AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate>*model))block;

/**
 初始化函数
 
 @param reuseIdentifier 标识
 @param style 自定义的类型，详见AUDoubleTitleListItemStyle
 @return 返回self实例
 */
- (instancetype)initWithReuseIdentifier:(NSString*)reuseIdentifier customStyle:(AUDoubleTitleListItemStyle)style;


/**
 根据不同style返回不同高度
 
 @param style 自定义类型，详见AUDoubleTitleListItemStyle
 @return 返回cell高度值
 */
+ (CGFloat)cellHeightForStyle:(AUDoubleTitleListItemStyle)style;



/**
 根据不同style返回动态高度
 
 @param style 自定义类型，详见AUDoubleTitleListItemStyle
 @param block 数据模型 详见 AUDoubleTitleListItemModelDelegate
 需要注意：1.该方法务必传入model.accessoryType的确切值 2.如果需要换行，请业务指定具体行数subtitleLines
 @return 返回cell高度值
 */
+ (CGFloat)cellHeightForStyle:(AUDoubleTitleListItemStyle)style
                   modelBlock:(void(^)(AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate>*model))block;

@end

#endif//程序自动生成
