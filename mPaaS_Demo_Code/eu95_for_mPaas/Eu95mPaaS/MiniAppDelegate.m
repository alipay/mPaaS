//
//  MiniAppDelegate.m
//  mpaas-tinyapp-ios
//
//  Created by admin on 2024/5/14.
//

#import "MiniAppDelegate.h"
//#import "CSMainWindow.h"

#import "MiniAppViewController.h"

@interface MiniAppDelegate ()

@property(nonatomic, strong) UIViewController *rootController;

@end

@implementation MiniAppDelegate

- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application {
//    return CSMainWindow.sharedManager.rootViewController;
    return self.rootController;
}

- (void)application:(DTMicroApplication *)application willStartLaunchingWithOptions:(NSDictionary *)options {
//    CSMainWindow.sharedManager.rootViewController = [MiniAppViewController new];
    self.rootController = [[MiniAppViewController alloc] init];
}

@end
