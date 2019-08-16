#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUSingleTitleListItem//程序自动生成
//
//  AUSingleTitleListItem.h
//  AntUI
//
//  Created by sara on 16/9/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUBaseListItem.h"

typedef NS_ENUM(NSInteger, AUSingleTitleListItemStyle) {
    AUSingleTitleListItemStyleDefault,  // 高度是92，图标60*60
    AUSingleTitleListItemStyleValue1,  // 高度110，图标72
};

@interface AUSingleTitleListItem : AUBaseListItem

@property(nonatomic,strong) UILabel *subtitleLabel;
@property(nonatomic,strong) UIImageView *leftImageView;
@property(nonatomic,strong) UIImageView *rightImageView;
@property(nonatomic,strong) UIImageView *rightAssistImageView;

/**重要
 初始化函数
 
 @param reuseIdentifier 重用标识
 @param block           外部传入的block，一般外部会在此block中设置title、leftimage等
 
 @return                返回self实例
 */
- (instancetype)initWithReuseIdentifier:(NSString*)reuseIdentifier model:(void(^)(AUListItemModel<AUSingleTitleListItemModelDelegate>*model))block  __deprecated_msg("预计废弃，请勿继续使用");



/**
 设置cell展示所需的所有数据
 
 @param block 传入的block
 */
- (void)setModelBlock:(void(^)(AUListItemModel<AUSingleTitleListItemModelDelegate>*model))block;

/**
 设置左侧图片Image的identifier，
 已经处理唯一Id标示，不用担心reuse之后图片串的问题
 */
- (void) setLeftImageIdentifier:(AUImageRequestModel *)identifier;

/**
 初始化函数

 @param reuseIdentifier 标识
 @param style 自定义的类型，详见AUSingleTitleListItemStyle
 @return 返回self实例
 */
- (instancetype)initWithReuseIdentifier:(NSString*)reuseIdentifier customStyle:(AUSingleTitleListItemStyle)style;



/**
 根据不同style返回不同高度

 @param style 样式
 @return 自定义类型，详见AUSingleTitleListItemStyle
 */
+ (CGFloat)cellHeightForStyle:(AUSingleTitleListItemStyle)style;



@end

@interface AUSingleTitleListItem (ScalingSupport)

+ (CGFloat)cellHeightForStyle:(AUSingleTitleListItemStyle)style scalingModel:(AUScalingModel *) scalingModel;

@end

#endif//程序自动生成
