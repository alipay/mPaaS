//
//  DialogDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DialogDemoViewController.h"
//#import "AUAuthorizeDialog.h"
//#import "AUDialogString.h"
//#import "AUImageDialog+AULottieStyle.h"

#define kButtonMarginTop 10.0

@interface DialogDemoViewController () <AUDialogDelegate>

@end

@implementation DialogDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    NSMutableArray *models = [[NSMutableArray alloc] init];
    
    DemoFunctionListModel *model = [[DemoFunctionListModel alloc] init];
    model.title = @"普通弹框 A";
    model.target = self;
    model.selector = @selector(onButton1Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"普通弹框 B";
    model.target = self;
    model.selector = @selector(onButton2Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"普通弹框带富文本message样式";
    model.target = self;
    model.selector = @selector(onButton11Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"无标题弹框";
    model.target = self;
    model.selector = @selector(onButton3Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"图文弹框";
    model.target = self;
    model.selector = @selector(onButton4Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"带输入框弹框";
    model.target = self;
    model.selector = @selector(onButton5Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"多行列表弹框(行动点超过两个)";
    model.target = self;
    model.selector = @selector(onButton6Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"多行列表弹框(行动点内容过长时)";
    model.target = self;
    model.selector = @selector(onButton7Clicked:);
    [models addObject:model];
    
//    model = [[DemoFunctionListModel alloc] init];
//    model.title = @"内容区是富文本";
//    model.target = self;
//    model.selector = @selector(onButton8Clicked:);
//    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"大图文弹窗样式";
    model.target = self;
    model.selector = @selector(onButton9Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"服务授权弹窗样式";
    model.target = self;
    model.selector = @selector(onButton10Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"AUOperationResultDialog 弹窗";
    model.target = self;
    model.selector = @selector(onButton12Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"后台模式弹窗";
    model.target = self;
    model.selector = @selector(onButton13Clicked:);
    [models addObject:model];

    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"自定义弹窗弹窗";
    model.target = self;
    model.selector = @selector(onButton15Clicked:);
    [models addObject:model];
    
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"自定义弹窗弹窗 + 关闭";
    model.target = self;
    model.selector = @selector(onButton16Clicked:);
    [models addObject:model];


    model = [[DemoFunctionListModel alloc] init];
    model.title = @"支持Lottie动画的弹窗";
    model.target = self;
    model.selector = @selector(onButton17Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"支持带展位图的Lottie弹窗";
    model.target = self;
    model.selector = @selector(onButton18Clicked:);
    [models addObject:model];
    
    model = [[DemoFunctionListModel alloc] init];
    model.title = @"大图文弹窗自定义内容区域样式";
    model.target = self;
    model.selector = @selector(onButton19Clicked:);
    [models addObject:model];
    
    self.functionList = [NSArray arrayWithArray:models];
}

- (void)onButton1Clicked:(id) sender
{
    AUImageDialog *imageDialog = [[AUImageDialog alloc] initWithImageUrl:@"https://t12.baidu.com/it/u=2492288507,2171405997&fm=173&app=12&f=JPEG?w=490&h=376&s=49223C722D584DC8444138D60000D0B2" placeholder:nil
                                                                   title:@"测试" message:@"刷卡缴费实际开发" delegate:nil];
    [imageDialog addButton:@"取消" actionBlock:nil];
    [imageDialog show];
    
//    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题"
//                                                           message:@"告知当前状态,信息和解决方法"];
//    [dialog addButton:@"确定" actionBlock:nil];
//    dialog.isSupportAutorotate = YES;
//    [dialog show];
}

- (void)onButton11Clicked:(id) sender
{
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题"
                                                           message:AUDialogRichString(@"你将要通过生活号，获得商家提供的服务，请先阅读并同意<a href='https://render.alipay.com/p/f/fd-jahn0csf/index.html'>《生活号服务使用须知》</a>")];
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog setLinkActionBlock:^BOOL(NSString *link) {
        NSLog(@"hello back");
        return NO;
    }];
    [dialog show];
}

- (void)onButton2Clicked:(id) sender
{
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题单行"
                                                           message:@"说明当前状态、提示用户解决方案，最好不要超过两行。"];
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog addCancelButton:@"取消" actionBlock:nil];
    [dialog show];
}

- (void)onButton3Clicked:(id) sender
{
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:nil
                                                           message:@"说明当前状态、提示用户解决方案，最好不要超过两行。"];
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog addCancelButton:@"取消" actionBlock:nil];
    [dialog show];
}

- (void)onButton4Clicked:(id) sender
{
    UIView *customView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 135, 135)];
    customView.backgroundColor = RGB(0xd8d8d8);
    AUImageDialog *dialog = [[AUImageDialog alloc] initWithCustomView:customView];
    dialog.title = @"标题单行";
    dialog.message = @"说明当前状态、提示用户解决方案，最好不要超过两行。";
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog setCloseButtonActionBlock:^{
        NSLog(@"点击了关闭按钮");
    }];
    [dialog show];
    
    
//    UIView *customView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 375, 400)];
//    customView.backgroundColor = RGB(0xd8d8d8);
//    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithCustomView:customView];
//    [dialog setCustomViewEdge:AUEdgeMake(0, 0, 0, 0)];
//    dialog.message = @"说明当前状态、提示用户解决方案，最好不要超过两行。";
//    [dialog addButton:@"确定" actionBlock:nil];
//    [dialog addButton:@"OK" actionBlock:nil];
//    [dialog show];
}

- (void)onButton5Clicked:(id) sender
{
    AUInputDialog *dialog = [[AUInputDialog alloc] initWithTitle:@"标题单行"
                                                         message:@"说明当前状态、提示用户解决方案，最好不要超过两行。"
                                                     placeholder:@"给朋友留言"
                                                        delegate:self
                                                    buttonTitles:@"取消", @"确定", nil];
    [dialog show];
}

- (void)onButton6Clicked:(id) sender
{
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题单行"
                                                           message:@"说明当前状态、提示用户解决方案，最好不要超过两行。"];
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog addButton:@"更多" actionBlock:nil];
    [dialog addCancelButton:@"取消" actionBlock:nil];
    [dialog show];
}

- (void)onButton7Clicked:(id) sender
{
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题单行"
                                                           message:@"说明当前状态、提示用户解决方案，最好不要超过两行。"];
    [dialog addButton:@"去设置开启通知" actionBlock:nil];
    [dialog addButton:@"更多" actionBlock:nil];
    
    dialog.listButtonOrderFromBottom = YES; // 可以调整列表的button的布局顺序
    
    [dialog show];
}

- (void)onButton8Clicked:(id) sender
{
    NSString *contentStr = @"消息是富文本，消息是富文本消息是富文本消息是富文本";
    
    // 初始化属性字符串
    NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:[contentStr stringByAppendingString:@""]];
    [attrStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(6, 6)];
    [attrStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:25] range:NSMakeRange(0, 12)];
    [attrStr addAttributes:@{
                             NSForegroundColorAttributeName : [UIColor yellowColor],
                             NSBackgroundColorAttributeName : [UIColor lightGrayColor]
                             }
                     range:NSMakeRange(0,6)];
    
    AUNoticeDialog *dialog = [[AUNoticeDialog alloc] initWithTitle:@"标题单行"
                                                           message:attrStr];
    [dialog addButton:@"OK" actionBlock:nil];
    [dialog show];
}

- (void)onButton9Clicked:(id) sender
{
    UIImage *image = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xD8D8D8] size:CGSizeMake(100, 100)];
    AUImageDialog *dialog = [[AUImageDialog alloc] initWithLargeImage:image title:@"标题单行" message:@"说明当前状态，提示用户解决方案，最好不要超过两行" delegate:self];
    [dialog addButton:@"取消" actionBlock:nil];
    [dialog addButton:@"确定" actionBlock:nil];
    [dialog resetCloseIconColor:[UIColor redColor]];
    [dialog show];
}


- (void)onButton10Clicked:(id) sender
{
    AUAuthorizeDialog *dialog =
    [[AUAuthorizeDialog alloc] initWithTitle:@"服务授权"
                                     message:@"同意<a href='http://www.baidu.com'>《用户授权协议》</a><a>《芝麻服务协议及相关授权条款》</a><a>《骑行用户信息授权协议》</a><a>《单车方用户服务协议》</a>"
                                   authTitle:@"授权 <b>ofo小黄车</b> 获取以下信息为你服务"
                                 authDetails:@[@"获得你的公开信息（昵称、头像、性别等）",@"使用身份信息（姓名、手机号、证件）办理业务",@"查询你的芝麻分等信用信息，如尚未开通芝麻信用服务，则予以开通"]
                                     bizName:@"demo"];
    [dialog setCancelButtonActionBlock:^{
        NSLog(@"点击了取消按钮");
    }];
    
    [dialog setConfirmButton:@"确定授权" actionBlock:^{
        NSLog(@"点击了授权按钮");
    }];
    
    [dialog setLinkActionBlock:^BOOL(NSString *urlString) {
        NSLog(@"点击了%@",urlString);
        return YES;// YES，antui会自动打开url；NO，业务自己调用打开方法
    }];
    
    [dialog show];
}

- (void)onButton12Clicked:(id) sender
{
    UIImage *img = [UIImage imageNamed:@"sharepay_send_success"];
    AUOperationResultDialog *dialog = [[AUOperationResultDialog alloc] initWithImage:img  message:@"已发送" delegate:nil];
    [dialog addButton:@"返回" actionBlock:^{
        NSLog(@"click back");
     }];
    [dialog addButton:@"知道了" actionBlock:nil];
    [dialog show];
}


- (void)onButton13Clicked:(id) sender
{
    UIImage *img = [UIImage imageNamed:@"sharepay_send_success"];
    AUOperationResultDialog *dialog = [[AUOperationResultDialog alloc] initWithImage:img  message:@"已发送" delegate:nil];
    [dialog addButton:@"返回" actionBlock:^{
        NSLog(@"click back");
    }];
    [dialog addButton:@"知道了" actionBlock:nil];
    [dialog show];
    
    AUNoticeDialog *dialog2 = [[AUNoticeDialog alloc] initWithTitle:@"标题单行"
                                                           message:@""];
    [dialog2 addButton:@"OK" actionBlock:nil];
    [dialog2 show];
    
    [self performSelector:@selector(setInBackgroundMode) withObject:nil afterDelay:1];
    [self performSelector:@selector(setInForgroundMode) withObject:nil afterDelay:3];
}

-(void) onButton15Clicked:(id)sender
{
    UIView *view = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 200, 200)];
    view.backgroundColor = [UIColor blueColor];
    AUDialogBaseView *base = [[AUNoticeDialog alloc]initWithCustomView:view];
    base.title = @"标题";
    base.message = @"message";
    [base addButtonWithTitle:@"确定"];
    [base addButtonWithTitle:@"取消"];
    [base show];
}
-(void) onButton16Clicked:(id)sender
{
    UIView *view = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 200, 200)];
    view.backgroundColor = [UIColor blueColor];
    AUDialogBaseView *base = [[AUNoticeDialog alloc]initWithCustomView:view type:AUDialogBuilderType_Custom_Normal_WithCloseBtn];
    //base.title = @"标题";
    //base.message = @"message";
    [base onCloseBtnClickedAction:^{
        [base dismiss];
    }];
    [base addButtonWithTitle:@"确定"];
    [base addButtonWithTitle:@"取消"];
    [base show];
}

-(void) onButton17Clicked:(id)sender
{
//    AUImageDialog *dialog = [[AUImageDialog alloc] initWithLottieFilePath:[[NSBundle mainBundle] pathForResource:@"lottie/refresh_default" ofType:@"json" inDirectory:@"APCommonUI.bundle"] title:@"主标题" message:@"副标题" delegate:self];
//
//    [dialog addButtonWithTitle:@"确定"];
//    [dialog addButtonWithTitle:@"取消"];
//    [dialog show];
}

-(void) onButton18Clicked:(id)sender
{
//    AUImageDialog *dialog = [[AUImageDialog alloc] initWithLottieFilePath:[[NSBundle mainBundle] pathForResource:@"lottie/refresh_default" ofType:@"json" inDirectory:@"APCommonUI.bundle"] placeHolder:[UIImage imageWithColor_au:RGB(0x108ee9) size:CGSizeMake(48, 48)] title:@"主标题" message:@"副标题" delegate:self];
//    
//    [dialog addButtonWithTitle:@"确定"];
//    [dialog addButtonWithTitle:@"取消"];
//    [dialog show];
}

- (void)onButton19Clicked:(id)sender
{
    UIImage *image = [UIImage imageWithColor_au:RGB(0X108EE9) size:CGSizeMake(self.view.width, 150)];
    UIImage *image1 = [UIImage imageWithColor_au:RGB(0xd8d8d8) size:CGSizeMake(self.view.width, 50)];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:image1];
    AUImageDialog *dialog = [[AUImageDialog alloc] initWithLargeImage:image customView:imageView];
    [dialog addButtonWithTitle:@"确定"];
    [dialog addButtonWithTitle:@"取消"];
    [dialog show];
}


- (void)setInForgroundMode
{
    [[AUDialogManager shareInstance] setIsBackGroundMode:NO];
}

- (void)setInBackgroundMode
{
    [[AUDialogManager shareInstance] setIsBackGroundMode:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
