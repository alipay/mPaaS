//
//  DemoFunctionListViewController.h
//  AntUI
//
//  Created by zhaolei on 2017/8/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoBaseViewController.h"

@interface DemoFunctionListModel : NSObject

@property(nonatomic, copy) NSString *title;
@property(nonatomic, weak) id target;
@property(nonatomic, assign) SEL selector;

@end

@interface DemoFunctionListViewController : DemoBaseViewController

@property (nonatomic, strong) NSArray<DemoFunctionListModel *> *functionList;

@end
