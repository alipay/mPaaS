#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogButton.h
//  AntUI
//
//  Created by QiXin on 2016/9/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUDialogBuilder.h"

typedef void (^AUDialogActionBlock)();

@interface AUDialogButton : UIButton

@property (nonatomic, assign) NSInteger buttonIndex;
@property (nonatomic, copy) AUDialogActionBlock actionBlock;
@property (nonatomic, assign) AUDialogActionStyle actionStyle;
@property (nonatomic, assign) BOOL customlizedTitleColor;


@end


@interface AUDialogNormalButton : AUDialogButton
@end

@interface AUDialogActionButton : AUDialogButton
@end

#endif//程序自动生成
