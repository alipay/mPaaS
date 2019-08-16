//
//  APCheckBox.h
//  AlipayPortal
//
//  Created by WenBi on 12-5-29.
//  Copyright (c) 2012年 aliPay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, APCheckBoxType) {
    APCheckBoxTypeDefault,  // The default image size is 30*30.
    APCheckBoxTypeMain,     // The default image size is 48*48.
};

/**
 *  A checkbox is a specific type of two-states control that can be either checked or unchecked.
 */
@interface APCheckBox : UIControl

/**
 *  A boolean value indicates whether the <code>APCheckBox</code> is checked.
 *
 *  The default value is NO.
 */
@property(nonatomic, assign, getter = isChecked) BOOL checked;

/**
 *  A boolean value indicates whether the <code>APCheckBox</code> is disable.
 *
 *  The default is NO. if YES, ignores touch
 */
@property(nonatomic, assign) BOOL disable;

/** Gets or sets the image for check state. */
@property(nonatomic, strong) UIImage *checkedImage;

/** Gets or sets the image for unchecked state. */
@property(nonatomic, strong) UIImage *uncheckedImage;

/** Gets or sets the image for disable state */
@property(nonatomic, strong) UIImage *disableImage;

/**
 *  The inset or outset margins for the rectangle around the check-box's image.
 *  The default value is <code>UIEdgeInsetsMake(0, 0, 0, 7.0)<code>.
 *  The default value is <code>UIEdgeInsetsMake(0, 0, 0, 10.0)<code> in iPhone6 plus.
 */
@property(nonatomic, assign) UIEdgeInsets imageEdgeInsets;

/** Returns the label used for title of check box. */
@property(nonatomic, strong, readonly) UILabel *titleLabel;

/** 设置选框与文字之间的描述图片 ，按图片大小显示*/
@property(nonatomic, strong) UIImage *infoImage;

/**
 *  Returns an initialized <code>APCheckBox</code> object with the height of 20.0.
 *  The default image size of 30*30.
 *
 *  @return An initialized check box object.
 */
- (id)init;

/**
 *  Returns an initialized <code>APCheckBox</code> object with the height of 24.0.
 *  The default image size of 48*48.
 *
 *  @param type APCheckBoxType
 *
 *  @return An initialized check box object.
 */
- (id)initWithType:(APCheckBoxType)type;

@end
