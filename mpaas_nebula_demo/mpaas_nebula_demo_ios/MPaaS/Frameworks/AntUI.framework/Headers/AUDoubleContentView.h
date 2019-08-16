#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUDoubleTitleListItem//程序自动生成
//
//  AUDoubleContentView.H
//  AntUI
//
//  Created by sara on 17/4/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUDoubleTitleListItem.h"

@interface AUDoubleContentView : UIView <TTTAttributedLabelDelegate>
@property(nonatomic, strong) UILabel *titleLabel;     // 标题
@property(nonatomic,strong) UILabel *subtitleLabel;
@property(nonatomic,strong) UIImageView *leftImageView;
@property(nonatomic,strong) UILabel* timeLabel;
@property(nonatomic,strong) UILabel* rightAssistLabel;
@property(nonatomic, assign) NSUInteger style;
@property(nonatomic, assign) CGSize leftimageSize;
@property(nonatomic, assign) NSInteger subtitleLines;
@property(nonatomic, assign) UITableViewCellAccessoryType accessoryType;
@property(nonatomic, strong) TTTAttributedLabel *attributelabel;    // 富文本样式，目前主要支持副标题的富文本样式
@property(nonatomic, assign) CGFloat maxWidth;
@property (nonatomic,strong) AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate>* model;

- (CGSize)sizeOfleftImage;

/**
 设置富文本样式
 
 @param attributeText 富文本的文案，包含链接色的文案
 @param linkText      富文本链接色文案
 @param linkURL       富文本链接文案跳转链接
 */

- (void)setTTTAttributeText:(NSString *)attributeText
                   linkText:(NSString *)linkText;

@end

@interface AUDoubleContentView (Utils)

+ (CGFloat)accessoryViewSize:(AUListItemAccessoryType)type;
+ (CGFloat)cellMaxWidthByModel:(AUListItemModel<AUDoubleTitleListItemModelDelegate, TTTAttributeLabelDelagate> *)model
                         style:(AUDoubleTitleListItemStyle)style;
+ (NSMutableParagraphStyle *)DoubleTitleParagraphStyle;

@end

#endif//程序自动生成
