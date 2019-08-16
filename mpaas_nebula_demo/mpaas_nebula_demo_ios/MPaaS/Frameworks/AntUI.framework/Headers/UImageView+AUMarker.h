//
//  UImageView+AUMarker.h
//  AntUI
//
//  Created by 莜阳 on 2018/6/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

typedef NS_ENUM(NSInteger, AUImageViewPostion) {
    AUImageViewPostionTopLeft,          // regular table view
    AUImageViewPostionTopRight,         // preferences style table view
    AUImageViewPostionBottomLeft,
    AUImageViewPostionBottomRight
};


@interface UIImageView (AUMarker)

- (void)au_setMarkerView:(UIView *)markView
              atPosition:(AUImageViewPostion)position;

@end
