//
//  MPAntUIDemoDef.h
//  MPAntUIDemo
//
//  Created by shifei.wkp on 2018/12/18.
//  Copyright © 2018 alipay. All rights reserved.
//

#ifndef MPAntUIDemoDef_h
#define MPAntUIDemoDef_h

#define BUTTON_WITH_ACTION(_title, _sel)  \
{   \
    AUButton *button = [AUButton buttonWithStyle:AUButtonStyle1 title:_title target:self action:@selector(_sel)];    \
    button.frame = CGRectMake(hMargin, vPadding + (index++) * (height + vMargin), width, height);   \
    [scrollView addSubview:button]; \
}

#define CREATE_UI(_addButton)   \
{   \
    UIScrollView *scrollView = [[UIScrollView alloc] init];  \
    [self.view addSubview:scrollView];  \
    [scrollView mas_makeConstraints:^(MASConstraintMaker *make) {    \
        make.top.mas_equalTo(self.mas_topLayoutGuide);  \
        make.bottom.mas_equalTo(self.mas_bottomLayoutGuide);    \
        make.left.mas_equalTo(self.view.mas_left);  \
        make.right.mas_equalTo(self.view.mas_right);    \
    }]; \
    CGFloat hMargin = 0.05 * self.view.width, vMargin = 15; \
    CGFloat width = self.view.width - 2 * hMargin, height = 44; \
    NSInteger index = 0;    \
    CGFloat vPadding = 50;  \
    _addButton  \
    CGFloat maxY = 2 * vPadding + (index - 1) * (height + vMargin) + height;    \
    if (maxY > scrollView.height) { \
        scrollView.contentSize = CGSizeMake(scrollView.width, maxY);    \
    }   \
}


#endif /* MPAntUIDemoDef_h */
