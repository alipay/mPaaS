//
//  DemoAUQRCodeViewController.m
//  AntUI
//

//  Created by 莜阳 on 2017/5/31.
//

#import "DemoAUQRCodeViewController.h"
#import <AntUI/AUQRCodeView.h>
#import "AntUIShellObject.h"


@interface DemoAUQRCodeViewController()

@property (nonatomic, strong) AUQRCodeView *qrCodeView1;

@end

@implementation DemoAUQRCodeViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:scrollView];
    CGRect frame = CGRectMake(0, 0, self.view.width, AUCommonUIGetScreenHeight());
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称";
//            model.bottomTitle = @"用支付宝二维码，关注生活号";
//            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
            model.topLeftIcon = @"https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png";

        }];
        [scrollView addSubview:qrCodeView];
    }
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"群名称";
            model.topSubtitle = @"城市 区域";
            model.bottomTitle = @"用支付宝二维码，关注生活号";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
//            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.topLeftIcon = @"https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png";
            
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"群名称";
            model.topSubtitle = @"城市 区域";
            model.bottomTitle = @"用支付宝二维码，关注生活号";
            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
            model.topLeftIcon = @"https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png";
            
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称";
            model.bottomTitle = @"用支付宝二维码，关注生活号";
            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.actionButtonTitle = @"保存到本地";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
            
            model.topLeftIcon = @"https://os.alipayobjects.com/rmsportal/MTGSumLYsIHiGTc.png";
            
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称";
            model.bottomTitle = @"用支付宝二维码，关注生活号";
            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.actionButtonTitle = @"点击生成吱口令";
            model.actionButtonMessage = @"推荐生活号给微信、QQ好友";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称";
            model.bottomTitle = @"用支付宝二维码，关注生活号";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0xbbbbbb] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称";
            model.bottomMessage = @"该二维码将在2017年11月05日失效";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
        }];
        [scrollView addSubview:qrCodeView];
    }
    
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    {
        AUQRCodeView *qrCodeView = [[AUQRCodeView alloc] initWithFrame:frame model:^(QRDataModel *model) {
            model.topLeftIcon = [UIImage imageWithColor_au:[UIColor colorWithRGB:0x108ee9] size:CGSizeMake(54, 54)];
            model.topTitle = @"生活号名称2";
            model.qrCodeIcon = [UIImage imageNamed:@"APCommonUI_ForDemo.bundle/QR_Icon"];
        }];
        _qrCodeView1 = qrCodeView;
        [qrCodeView startLoading];
        [self performSelector:@selector(updateUIByRPCResult:) withObject:@"text text" afterDelay:5];
        
        [scrollView addSubview:qrCodeView];
    }
    frame.origin.y = CGRectGetMaxY(frame) + 15;
    [scrollView setContentSize:CGSizeMake(self.view.width, frame.origin.y)];
}

//
- (void)updateUIByRPCResult:(NSString *)text
{
    [_qrCodeView1 stopLoading];
    _qrCodeView1.bottomTitleLabel.text = @"title";
    _qrCodeView1.bottomMessageLabel.text = text;
}

@end
