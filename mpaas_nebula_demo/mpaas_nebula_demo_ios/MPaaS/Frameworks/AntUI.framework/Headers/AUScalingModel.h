//
//  AUScalingModel.h
//  AntUI
//
//  Created by Wang on 2018/9/17.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUScalingModel : NSObject

@property (nonatomic,strong) NSDictionary<NSString*,NSNumber*> *scalingValue;

//返回设置最大的放大倍数
-(CGFloat) maxScalingValue;

-(NSNumber *) valueForItem:(NSString*)key;

-(UIFont *) newFontForItem:(NSString *)key originFont:(UIFont *) font;

-(CGSize) newSizeForItem:(NSString *)key originSize:(CGSize) size;
@end

AUScalingModel *AUScalingModelMake(CGFloat scale);
