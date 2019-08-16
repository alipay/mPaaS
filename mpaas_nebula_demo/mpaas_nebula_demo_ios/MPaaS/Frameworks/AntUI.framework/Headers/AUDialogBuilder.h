#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogBuilder.h
//  AntUI
//
//  Created by QiXin on 2016/9/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUEdge.h"

typedef NS_ENUM(NSInteger, AUDialogActionStyle) {
    AUDialogActionStyleDefault = 0,
    AUDialogActionStyleCancel,
    AUDialogActionStyleDestructive = AUDialogActionStyleDefault
};

typedef NS_ENUM(NSInteger, AUDialogBuilderType) {
    AUDialogBuilderType_Normal = 0,
    AUDialogBuilderType_List,
    AUDialogBuilderType_Input,
    AUDialogBuilderType_ImageNormal,
    AUDialogBuilderType_ImageAction,
    AUDialogBuilderType_operationResult,
    AUDialogBuilderType_Custom_Normal,
    AUDialogBuilderType_Custom_List,
    AUDialogBuilderType_Custom_Input,
    AUDialogBuilderType_Custom_ImageNormal,
    AUDialogBuilderType_Large_Image,
    AUDialogBuilderType_Custom_Normal_WithCloseBtn,
    AUDialogBuilderType_Custom_Large_Image
};

@class AUDialogButton;
@interface AUDialogBuilder : NSObject

@property (nonatomic, strong) NSString *title;

@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSAttributedString *attributedMessage;
@property (nonatomic, strong) NSString *richMessage;

@property (nonatomic, strong) UIImage  *image;
@property (nonatomic, strong) NSString *linkText;
@property (nonatomic, strong) NSString *placeholder;

@property (nonatomic, assign) BOOL      grayMessage;
@property (nonatomic, assign) CGSize    imageSize;

@property (nonatomic, strong) UILabel        *titleLabel;
@property (nonatomic, strong) UILabel        *messageLabel;

@property (nonatomic, strong) UIImageView    *imageView;
@property (nonatomic, strong) UITextField    *textField;
@property (nonatomic, strong) AUDialogButton *closeButton;
@property (nonatomic, strong) AUDialogButton *linkButton;
@property (nonatomic, strong) UIView *customView;   // 自定义内容区域
@property (nonatomic, strong) AUEdge *edge;    // 自定义内容区域边距
@property (nonatomic, strong) UIColor *closeBtnColor; // 右上角叉叉按钮的自定义色值

@property (nonatomic, assign) AUDialogBuilderType builderType;
@property (nonatomic, assign) BOOL listButtonOrderFromBottom; // 是否从底部开始布局第一个按钮（默认从顶部开始）

- (void)addButton:(AUDialogButton *)button;
- (void)addButton:(AUDialogButton *)button actionStyle:(AUDialogActionStyle)style;
- (void)enableButton:(BOOL)enable atIndex:(NSInteger)index;
- (void)setLinkActionBlock:(BOOL (^)(NSString *))linkActionBlock;

- (void)buildAlertContentView:(UIView *)contentView;
- (void)buildAlertButtonView:(UIView *)buttonView
              containerWidth:(CGFloat)containerWidth;

- (void)updateTitleLayout;
- (void)updateMessageLayout;
- (void)updateTitleMesgUI;

- (nullable NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;

- (void) setupButtonTitleColor:(nullable UIColor *)color atIndex:(NSInteger)buttonIndex;
//- (nullable UIButton *)buttonAtIndex:(NSInteger)buttonIndex;
@property(nonatomic,readonly) NSInteger numberOfButtons;

@end

#endif//程序自动生成
