//
//  MPRPCViewController.m
//  Eu95mPaaS
//
//  Created by 冯冠华 on 2024/4/18.
//

#import "MPRPCViewController.h"
#import <MBProgressHUD/MBProgressHUD.h>

#import "RpcDemoClient.h"
#import "BannerJsonPostReq.h"

#import "RoterClient.h"

#import "POCClient.h"
#import "ArticleList0JsonGetReq.h"


@interface MPRPCViewController ()

@end

@implementation MPRPCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CREATE_UI({
        BUTTON_WITH_ACTION(NSLocalizedString(@"调用RPC POST", nil), exampleRpcPostRequest)
        BUTTON_WITH_ACTION(NSLocalizedString(@"调用RPC Get", nil), exampleRpcGetRequest)

//        BUTTON_WITH_ACTION(NSLocalizedString(@"路由", nil), roueRpcRequest)
//        BUTTON_WITH_ACTION(NSLocalizedString(@"触发熔断", nil), rongduanRpcRequest)
    })
}

#pragma  mark -调用RPC和限流
-(BannerJsonPostReq *)rep{
    BannerJsonPostReq *postRep = [[BannerJsonPostReq alloc] init];
    postRep.username = @"mPaaS";
    postRep.password = @"hello";
    return postRep;
}

-(void)exampleRpcPostRequest{
    __block NSString *response;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [DTRpcAsyncCaller callAsyncBlock:^{
        @try {
            RpcDemoClient *client = [[RpcDemoClient alloc] init];
            response = [client bannerJsonPost:[self rep]];

        } @catch (DTRpcException *exception) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                NSString *errorMsg = [NSString stringWithFormat:@"Rpc Exception code : %d", exception.code];
                [AUToast presentToastWithin:self.view withIcon:AUToastIconNetFailure text:errorMsg duration:1 logTag:@"demo" completion:nil];
                APLog(errorMsg);
            });
        }
    } completion:^{
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (response && [response isKindOfClass:[NSDictionary class]]) {
            [AUToast presentToastWithin:self.view 
                               withIcon:AUToastIconSuccess text:[response JSONString_mp] duration:1 logTag:@"demo" completion:nil];
        }else{
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconSuccess text:response duration:1 logTag:@"demo" completion:nil];
        }
    }];
}

-(void)exampleRpcGetRequest{
    __block NSString *response;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [DTRpcAsyncCaller callAsyncBlock:^{
        @try {
            RpcDemoClient *client = [[RpcDemoClient alloc] init];
            response = [client articleList0JsonPost];

        } @catch (DTRpcException *exception) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                NSString *errorMsg = [NSString stringWithFormat:@"Rpc Exception code : %d", exception.code];
                [AUToast presentToastWithin:self.view withIcon:AUToastIconNetFailure text:errorMsg duration:1 logTag:@"demo" completion:nil];
                APLog(errorMsg);
            });
        }
    } completion:^{
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (response && [response isKindOfClass:[NSDictionary class]]) {
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconSuccess text:[response JSONString_mp] duration:1 logTag:@"demo" completion:nil];
        }
    }];

}


#pragma  mark -路由
-(void)roueRpcRequest{
    __block NSString *response;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [DTRpcAsyncCaller callAsyncBlock:^{
        @try {
            RoterClient *client = [[RoterClient alloc] init];
            response = [client bannerJsonPost];
        } @catch (DTRpcException *exception) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                NSString *errorMsg = [NSString stringWithFormat:@"Rpc Exception code : %d", exception.code];
                [AUToast presentToastWithin:self.view withIcon:AUToastIconNetFailure text:errorMsg duration:1 logTag:@"demo" completion:nil];
                APLog(errorMsg);
            });
        }
    } completion:^{
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (response && [response isKindOfClass:[NSDictionary class]]) {
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconSuccess text:[response JSONString_mp] duration:1 logTag:@"demo" completion:nil];
        }
    }];
}

#pragma  mark -熔断
-(ArticleList0JsonGetReq *)jsonGetReq{
    ArticleList0JsonGetReq *req = [[ArticleList0JsonGetReq alloc] init];
//    req.cid = @"222";
    req.cid = @"触发熔断条件";
    return req;
}

-(void)rongduanRpcRequest{
    __block NSString *response;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [DTRpcAsyncCaller callAsyncBlock:^{
        @try {
            POCClient *client = [[POCClient alloc] init];
            response = [client articleList0JsonGet:[self jsonGetReq]];
        } @catch (DTRpcException *exception) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                NSString *errorMsg = [NSString stringWithFormat:@"Rpc Exception code : %d", exception.code];
                [AUToast presentToastWithin:self.view withIcon:AUToastIconNetFailure text:errorMsg duration:1 logTag:@"demo" completion:nil];
                APLog(errorMsg);
            });
        }
    } completion:^{
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (response && [response isKindOfClass:[NSDictionary class]]) {
            [AUToast presentToastWithin:self.view
                               withIcon:AUToastIconSuccess text:[response JSONString_mp] duration:1 logTag:@"demo" completion:nil];
        }
    }];

}



@end
