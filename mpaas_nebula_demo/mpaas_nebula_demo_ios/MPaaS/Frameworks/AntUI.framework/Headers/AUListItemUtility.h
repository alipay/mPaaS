#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUListItemUtility.h
//  AntUI
//
//  Created by sara on 17/3/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

struct DoubleSize {
    CGSize leftSize;
    CGSize rightSize;
};
typedef struct DoubleSize DoubleSize;

CG_INLINE DoubleSize DoubleSizeMake(CGSize leftSize, CGSize rightSize) {
    DoubleSize doublesize;
    doublesize.leftSize = leftSize;
    doublesize.rightSize = rightSize;
    return doublesize;
}


@interface DoubleLabelStretchModel : NSObject

@property (nonatomic,copy)      NSString *leftTitle;
@property (nonatomic,copy)      NSString *rightTitle;
@property (nonatomic,assign)    CGFloat middleSpacing;
@property (nonatomic,copy)      UIFont *leftFont;
@property (nonatomic,copy)      UIFont *rightFont;
@property (nonatomic,assign)    CGFloat totalWidth;
@property (nonatomic,assign)    NSInteger leftNumberOfLines;
@property (nonatomic,assign)    NSInteger rightNumberOfLines;

@property (nonatomic,strong)    AUScalingModel *scalingModel;
@property (nonatomic,assign)    BOOL higherleftTitlePriority;

@end



@interface AUListItemUtility : NSObject

+ (DoubleSize)calculateSizeForModel:(DoubleLabelStretchModel*)model;

@end

#endif//程序自动生成
