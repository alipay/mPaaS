#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BadgeView_AUBadgeView//程序自动生成
//
//  AUBadgeView0.m
//  MPBadgeService
//
//  Created by jinzhidong on 2018/3/14.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "AUBadgeView0.h"

#define kDefaultBadgeViewBgEdgeInset UIEdgeInsetsMake(0, 8, 0, 8)

@interface AUBadgeView0 ()
{
    UIImageView *_badgeImageView;   // 显示红点视图
    UILabel     *_titleLabel;       // 显示数字的视图
    NSString    *_lastStyle;        // 记录上次红点的style
    UIImage     *_customBadgeImage; // 自定义红点图片
}

@end

@implementation AUBadgeView0

- (id)init
{
    self = [self initWithFrame:CGRectZero];
    if (self) {
        
    }
    return self;
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.userInteractionEnabled = NO;
        
        _badgeImageView = [[UIImageView alloc] initWithFrame:CGRectZero];
        
        _titleLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        _titleLabel.backgroundColor = [UIColor clearColor];
        _titleLabel.textColor = [UIColor whiteColor];
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.font = [UIFont boldSystemFontOfSize:12];
        [_badgeImageView addSubview:_titleLabel];
        
        [self addSubview:_badgeImageView];
    }
    return self;
}

- (void)setcustomBadgeImage:(UIImage *)customBadgeImage
{
    _lastStyle = nil;
    _titleLabel.text = nil;
    _customBadgeImage = customBadgeImage;
    _badgeImageView.image = customBadgeImage;
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}


#pragma mark - Util methods
- (BOOL)isPureInt:(NSString *)str
{
    NSScanner *scanner = [NSScanner scannerWithString:str];
    NSInteger iNumber = 0;
    return [scanner scanInteger:&iNumber] && [scanner isAtEnd];
}

- (UIImage *)bundledImageNamed:(NSString *)name
{
    NSString *imageName = [NSString stringWithFormat:@"badgeView/%@", name];
    return AUBundleImage(imageName);
}

- (CGSize)sizeWithString:(NSString *)str withFont:(UIFont *)font
{
    CGSize textSize = CGSizeZero;
    if (!str || !font) {
        return textSize;
    }
    
    if ([str respondsToSelector:@selector(sizeWithAttributes:)]) {
        textSize = [str sizeWithAttributes:[NSDictionary dictionaryWithObject:font forKey:NSFontAttributeName]];
    }
    else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        textSize = [str sizeWithFont:font];
#pragma clang diagnostic pop
    }
    
    textSize.width = ceil(textSize.width);
    textSize.height = ceil(textSize.height);
    return textSize;
}


#pragma mark - APBadgeWidget
- (void)drawBadgeStyle:(NSString *)style
{
    if ([self isLastStyle:style]) {
        return;
    }
    
    // 检查是否显示badge
    if (nil == style) {
        _titleLabel.text = nil;
        _badgeImageView.image = nil;
        _lastStyle = nil;
        return;
    }
    
    // 设置badge要显示的样式
    if (_customBadgeImage) {
        _badgeImageView.image = _customBadgeImage;
    }
    else if ([style isEqualToString:@"."]) {
        [self drawBadgeRedPoint];
    }
    else if ([[style lowercaseString] isEqualToString:@"new"]) {
        [self drawBadgeNew];
    }
    else if ([style integerValue] > 0 && [self isPureInt:style]) {
        [self drawBadgeNumber:style];
    }
    else if ([style isEqualToString:@"惠"] || [style isEqualToString:@"hui"]) {
        [self drawBadgeFavour];
    }
    else if ([style isEqualToString:@"xin"]) {
        [self drawBadgeXin];
    }
    else if ([style isEqualToString:@"hongbao"]) {
        [self drawBadgeRedEnvelope];
    }
    else if ([style isEqualToString:@"wufu"]) {
        [self drawBadgeFuKa];
    }
    else {
        return;
    }
    
    // 根据badge的宽度，设置所在视图及父视图的宽度
    CGRect frame = self.frame;
    frame.size = _badgeImageView.bounds.size;
    self.frame = frame;
    
    _lastStyle = style;
}

- (void)drawBadgeRedPoint
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_dot_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeNew
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_new_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeFavour
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_favour_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeXin
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_xin_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeRedEnvelope
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_hongbao_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeFuKa
{
    _titleLabel.text = nil;
    _badgeImageView.image = [self bundledImageNamed:@"badge_fuka_bg"];
    
    CGRect frame = CGRectZero;
    frame.size = _badgeImageView.image.size;
    _badgeImageView.frame = frame;
}

- (void)drawBadgeNumber:(NSString *)num
{
    _titleLabel.font = [UIFont boldSystemFontOfSize:12];
    
    UIImage *badgeImage = nil;
    CGSize imageSize = CGSizeZero;
    if ([num integerValue] > 99) {
        _titleLabel.text = nil;
        badgeImage = [self bundledImageNamed:@"badge_more_bg"];
    }
    else {
        _titleLabel.text = num;
        badgeImage = [self bundledImageNamed:@"badge_single_bg"];
    }
    
    imageSize = badgeImage.size;
    if ([num length] > 1 && [num integerValue] < 100) {
        CGSize textSize = [self sizeWithString:num withFont:_titleLabel.font];
        textSize.width += 8;
        if (textSize.width > imageSize.width) {
            imageSize.width = textSize.width;
            badgeImage = [badgeImage resizableImageWithCapInsets:kDefaultBadgeViewBgEdgeInset];
        }
    }
    
    _badgeImageView.image = badgeImage;
    CGRect frame = CGRectZero;
    frame.size = imageSize;
    _badgeImageView.frame = frame;
    
    if (_titleLabel.text) {
        frame = _titleLabel.frame;
        frame.size = _badgeImageView.bounds.size;
        if (![_titleLabel.text isEqualToString:@"1"]) {
            frame.size.width += 0.5;
        }
        
        
        //iOS7上需要上移1.5个像素才能居中，此处加该判断
        NSString *ver = [UIDevice currentDevice].systemVersion;
        if([ver hasPrefix:@"7"]){
            frame.size.height -= 1.5/[UIScreen mainScreen].scale;
        }else{
            frame.size.height -= 1/[UIScreen mainScreen].scale;
            
        }
        //        if(CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(375, 667))) {
        //            frame.size.height -= 1/[UIScreen mainScreen].scale;
        //        }
        //        else {
        //               frame.size.height -= 0.5/[UIScreen mainScreen].scale;
        //           }
        
        
        _titleLabel.frame = frame;
    }
}

- (BOOL)isLastStyle:(NSString *)badgeValue
{
    BOOL result = NO;
    if ([[badgeValue lowercaseString] isEqualToString:@"new"]) {
        result = [_lastStyle isEqualToString:@"new"];
        return result;
    }
    else if ([badgeValue isEqualToString:@"惠"] || [badgeValue isEqualToString:@"hui"]){
        result = [_lastStyle isEqualToString:@"惠"] || [_lastStyle isEqualToString:@"hui"];
        return result;
    }
    else if ([badgeValue integerValue] > 0 && [self isPureInt:badgeValue]){
        if([badgeValue integerValue] > 99){
            if([_lastStyle integerValue] > 99){
                return YES;
            }
            else{
                return NO;
            }
        }
        else{
            result = [badgeValue isEqualToString:_lastStyle];
            return result;
        }
    }
    else if (!badgeValue){
        result = !_lastStyle;
        return result;
    }
    else{
        result = [badgeValue isEqualToString:_lastStyle];
        return result;
    }
    
}

@end


#endif//程序自动生成
