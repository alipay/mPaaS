//
//  MPABViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/7/1.
//

#import "MPABViewController.h"

@interface MPABViewController ()

@property (nonatomic,strong) UIButton *sureButton;

@end

@implementation MPABViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"AB实验室";

    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"拉取开关配置信息", nil), forceLoadConfig)
        BUTTON_WITH_ACTION(NSLocalizedString(@"开关配置按钮", nil), testForABTest)
    })
    
    // 创建UIButton
//    self.sureButton = [UIButton buttonWithType:UIButtonTypeCustom];
//    [self.sureButton ]
//    [self.sureButton setTitle:@"提交" forState:UIControlStateNormal];
//    self.sureButton.frame = CGRectMake(100, 100, 150, 50);
//    [self.sureButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
//    [self.sureButton.titleLabel setFont:[UIFont systemFontOfSize:18]];
//    [self.sureButton addTarget:self action:@selector(buttonTapped:) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:self.sureButton];
    
}

//通过RPC 主动拉取服务端配置
-(void)forceLoadConfig{
    [[MPConfigInterface sharedService] forceLoadConfig];
}

- (void)testForABTest{
    
    NSString *value = [[MPConfigInterface sharedService] stringValueForKey:@"ButtonTitleConfigKey"];
    if ([value isEqualToString:@"sure"]) {
//        [self.sureButton setTitle:@"确定" forState:UIControlStateNormal];
    }else{
//        [self.sureButton setTitle:@"提交" forState:UIControlStateNormal];
    }
}
@end
