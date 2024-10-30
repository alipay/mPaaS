//
//  DemoAPAlertViewController.m
//  AntUIDemo
//
//  Created by Wang on 2019/3/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "DemoAPAlertViewController.h"
//#import "APAlertView.h"
@implementation DemoAPAlertViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"APAlertView 1)";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    self.functionList = [NSArray arrayWithArray:models];
}

-(void) onButton1Clicked:(id)sender
{
    APAlertView *alert = [[APAlertView alloc] initWithTitle:@""
                                                    message:@"message"
                                                   delegate:self
                                          cancelButtonTitle:__TEXT(@"ALPAuthorize", @"ALPAuthorize:确定", @"确定")
                                          otherButtonTitles:nil];
    alert.tag = 6001;
    [alert show];
}

- (void)alertView:(UIAlertView *) alertView clickedButtonAtIndex:(NSInteger) buttonIndex
{
    NSLog([NSString stringWithFormat:@"APAlertView %d clicked %d",alertView.tag,buttonIndex]);

}

@end
