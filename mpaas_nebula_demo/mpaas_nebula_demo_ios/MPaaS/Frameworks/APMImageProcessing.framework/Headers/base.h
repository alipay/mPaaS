//
//  base.h
//  APMImageProcessing
//
//  Created by Monster on 16/9/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int blue;
    int green;
    int red;
    int black;
} sCalcColor;

#ifndef base_h
#define base_h


void calc_pic_color(sCalcColor *color, const uint8_t *src, int width, int height);

#endif /* base_h */
