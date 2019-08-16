#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUNCssItemView.h
//  AntUI
//
//  Created by maizhelun on 2017/3/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNListItemDefine.h"

AUNClass_h(AUNView, UIView)
AUNClass_h(AUNbutton, UIButton)
AUNClass_h(AUNImageView, UIImageView)
AUNClass_h(AUNLabel, UILabel)




@interface AUNViewRound : NSObject

@property (nonatomic, strong) NSString *leftId;
@property (nonatomic, strong) NSString *rightId;
@property (nonatomic, strong) NSString *topId;
@property (nonatomic, strong) NSString *bottomId;

@end

@interface UIView (AUN)

@property (nonatomic, strong) NSString *AU_id;
@property (nonatomic, assign) UIEdgeInsets AU_margin;
@property (nonatomic, assign) CGSize AU_size;
@property (nonatomic, strong) AUNViewRound *AU_round;

- (void)setAU_cssItem:(NSString *)key value:(NSString *)value;

- (void)layoutAgain;

@end


@interface AUNCssItemView : UIView

- (instancetype)initWithCss:(NSString *)css;
+ (CGFloat)heightFromCss:(NSString *)css;

@property (nonatomic, strong) NSDictionary  *components;
@property (nonatomic, copy  ) NSString      *css;

#pragma mark - 禁止访问
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (void)setFrame:(CGRect)frame NS_UNAVAILABLE;

@end

#endif//程序自动生成
