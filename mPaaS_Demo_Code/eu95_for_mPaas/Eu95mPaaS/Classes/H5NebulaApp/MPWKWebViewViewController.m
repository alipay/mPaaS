//
//  MPWKWebViewViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/7/2.
//

#import "MPWKWebViewViewController.h"

@interface MPWKWebViewViewController ()

@end

@implementation MPWKWebViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    UIWebView *webView = [[UIWebView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:webView];

    NSURL *url = [NSURL URLWithString:@"https://qr.chinaums.com/netpay-portal/alipay2/h5Pay.do?msgId=115W&requestTimestamp=2024-07-02+13%3A25%3A17&merOrderId=115WPP000005291719897917934&srcReserve=XDHJT20240702132518007509G1C3B5874102BB893E06375740B0AB14E&mid=898310042154003&tid=00001783&instMid=H5DEFAULT&expireTime=2024-07-02+13%3A30%3A17&totalAmount=3000&originalAmount=3000&notifyUrl=https%3A%2F%2Fdhjt-uat.chinaums.com%2FqueryService%2FScanCodePay%3Fversion%3D20191031%26payFlag%3DH5DEFAULT&returnUrl=https%3A%2F%2Fdhjt-uat.chinaums.com%2FqueryService%2FScanCodePayCallback%3Fversion%3D20191031%26payFlag%3DH5DEFAULT&openAppId=8a81c1bd6f19b0a0016fa7de92590064&msgSrc=OPENPLATFORM&msgType=trade.h5Pay&sign=76FD1DED62DA1F014D00C680C3909B90"];
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:url];
    [webView loadRequest:request];

}


@end
