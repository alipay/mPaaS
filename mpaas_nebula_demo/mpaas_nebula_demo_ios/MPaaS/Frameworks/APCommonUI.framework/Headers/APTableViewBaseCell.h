//
//  ALPTableViewBaseCell.h
//  TestTable
//
//  Created by zhiyuan.yzy on 13-4-1.
//  Copyright (c) 2013年 zhiyuan.yzy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APTableViewCell.h"



@interface APTableViewBaseCell : APTableViewCell

@property(nonatomic, strong) UILabel *cellTitle;                  //左侧主标题
@property(nonatomic, strong) UILabel *cellInfo;                   //右侧提示信息
@property(nonatomic, strong) UIImageView *cellLogo;               //左侧头像图标
@property(nonatomic, strong) UIImageView *cellInfoImg;            //右侧提示图标，位置同提示信息
@property(nonatomic, strong) UIImageView *arrowImageView;         //未设置
@property(nonatomic, strong) UIImageView *cellBackgroundImageView;//未设置
@property(nonatomic, strong) UIImageView *topLineImageView;       //未设置
@property(nonatomic, strong) UIImageView *bottomLineImageView;    //底部通栏横线
@property(nonatomic, strong) UIImageView *separatorLineImageView; //与左侧文本对齐底部横线
@property(nonatomic, strong) UIColor *normalBackground;
@property(nonatomic, strong, readonly) UISwitch *cellSwitch;      //开关
@property(nonatomic, assign) CGFloat imageSize;                   //左侧图片大小，不设置会使用默认值21
@property(nonatomic, assign) CGSize infoImageSize;                //右侧提示图片大小，不设置会使用图片原大小

/**
 *  返回cell高度
 *
 *  @return 高度值
 */
+ (float)cellHeight;

/**
 * 重置所有子控件，reuse时应调此方法
 */
- (void)reset;

/**
 *  设置左侧头像图标cellLogo
 *
 *  @param img 显示图片
 */
- (void)setLogoImg:(UIImage *)img;

/**
 *  注意：需要引入SDWebImage.framework才能有效！设置头像为指定url,并设置默认头像,defaultImg不可为空
 *
 *  @param imgUrl     图片url
 *  @param defaultImg 默认图片UIImage实例
 */
- (void)setLogoImgWithUrl:(NSString *)imgUrl withDefault:(UIImage *)defaultImg;

/**
 * 设置主标题cellTitle
 */
- (void)setTitle:(NSString* )title;

/**
 * 设置右侧展开图标
 */
- (void)setExtendLogo;

/**
 * 设置默认背景色
 */
- (void)setNormalBackground:(UIColor *)normalColor;

/**
 * 设置选中背景色
 */
- (void)setSelectedBackground:(UIColor *)selectedColor;

/**
 * 设置提示信息cellInfo，对主标题信息进行补充，靠右显示，有展开图标则显示于展开图标左边
 */
- (void)setInfo:(NSString *)info;

/**
 * 设置提示信息的宽度，已到达显示更多的文字
 */
- (void)setInfoLabelWidth:(CGFloat)width;

/**
 * 设置提示图标与提示文案之间的间距，不设置默认为30px
 */
- (void)setMarginBetweenInfoTitleAndImage:(CGFloat)margin;

/**
 * 设置提示信息cellInfo字体颜色
 */
- (void)setInfoFontColor:(UIColor *)color;

/**
 * 设计提示图标cellInfoImg，位置同提示信息cellInfo，提示信息和提示图标同时只能设一个
 */
- (void)setInfoImg:(UIImage *)img;

/**
 *  注意：需要引入SDWebImage.framework才能有效！设置提示头像为指定url,并设置默认头像,defaultImg不可为空
 *
 *  @param imgUrl     图片url
 *  @param defaultImg 默认图片UIImage实例
 */
- (void)setInfoImgWithUrl:(NSString *)imgUrl withDefault:(UIImage *)defaultImg;



/**
 * 设置具体详情信息，此类无此效果，richcell可设置
 */
- (void)setInfoDetail:(NSString *)detail;

/**
 *  是否显示展开图标
 *
 */
- (BOOL)isShowExtend;

/**
 *  cell的contentView上添加子view
 *
 *  @param subView 要添加的子view
 */
- (void)addView:(UIView *)subView;

/**
 *  是否显示顶部通栏横线
 *
 *  @param yesOrNo bool值
 */
- (void)enableTopLineImageView:(BOOL)yesOrNo;

/**
 *  是否显示底部通栏横线
 *
 *  @param yesOrNo bool值
 */
- (void)enableLineImageView:(BOOL)yesOrNo;

/**
 *  是否显示自定义分割横线，与左侧文本保持对齐
 *
 *  @param yesOrNo bool值
 */
- (void)enableSeparatorLineImageView:(BOOL)yesOrNo;



/**
 *  设置图片大小
 */
- (void)setImageSize:(CGFloat)imageSize;


@end



@interface APTableViewBaseCell(SwitchExtend)


+(Class) switchClass;

/**
 * 设置开关
 * @prama isOpen 默认开关设置
 * @prama target 开关事件响应对象
 * @prama selector 开关事件响应方法
 */
- (void)setSwitchWithDefault:(BOOL) isOpne withTarget:(id) target withSelector:(SEL) selector;

@end


