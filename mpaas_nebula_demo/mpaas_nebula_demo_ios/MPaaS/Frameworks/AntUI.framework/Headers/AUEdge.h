//
//  AUEdgeInsets.h
//  AntUI
//
//  Created by 沫竹 on 2017/12/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUEdge : NSObject

@property (nonatomic, strong) NSNumber *top;
@property (nonatomic, strong) NSNumber *left;
@property (nonatomic, strong) NSNumber *bottom;
@property (nonatomic, strong) NSNumber *right;

@end

//static AUEdge *AUEdgeMakeNum(NSNumber *top, NSNumber *left, NSNumber *bottom, NSNumber *right)
//{
//    AUEdge *insets = [AUEdge new];
//    insets.left = left;
//    insets.top = top;
//    insets.right = right;
//    insets.bottom = bottom;
//    return insets;
//}


static AUEdge *AUEdgeMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right)
{
    AUEdge *insets = [AUEdge new];
    insets.left = @(left);
    insets.top = @(top);
    insets.right = @(right);
    insets.bottom = @(bottom);
    return insets;
}

NS_INLINE CGFloat AUEdgeGetLeft(AUEdge *edge, CGFloat defaultValue)
{
    return edge.left ? [edge.left floatValue] : defaultValue;
}

NS_INLINE CGFloat AUEdgeGetRight(AUEdge *edge, CGFloat defaultValue)
{
    return edge.right ? [edge.right floatValue] : defaultValue;
}

NS_INLINE CGFloat AUEdgeGetBottom(AUEdge *edge, CGFloat defaultValue)
{
    return edge.bottom ? [edge.bottom floatValue] : defaultValue;
}

NS_INLINE CGFloat AUEdgeGetTop(AUEdge *edge, CGFloat defaultValue)
{
    return edge.top ? [edge.top floatValue] : defaultValue;
}
