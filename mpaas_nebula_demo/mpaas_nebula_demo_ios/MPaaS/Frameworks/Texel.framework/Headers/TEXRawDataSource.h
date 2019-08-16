//
//  TEXRawDataSource.h
//  Texel
//
//  Created by Cloud on 2017/5/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"

@interface TEXRawDataSource : TEXSource
// 如果没有设置的话，就直接在当前线程里面处理，不自己创建
@property (nonatomic, strong) TEXContext *context;

- (instancetype)initWithSize:(CGSize)size;

- (void)setRawData:(const void *)data;

@end
