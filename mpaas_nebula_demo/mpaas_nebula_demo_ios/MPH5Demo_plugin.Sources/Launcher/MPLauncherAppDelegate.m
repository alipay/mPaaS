//
//  MPLauncherAppDelegate.m
//  MPH5Demo_plugin
//
//  Created by vivi.yw on 2019/03/28.
//  Copyright © 2019 ORGNIZATION_NAME. All rights reserved.
//

#import "MPLauncherAppDelegate.h"
#import "MPTabBarViewController.h"

@interface MPLauncherAppDelegate ()

@property (nonatomic, strong) MPTabBarViewController* rootVC;

@end

@implementation MPLauncherAppDelegate

- (id)init
{
    self = [super init];
    if (self) {
        NSArray *baseImgs = [NSArray arrayWithObjects:
                             @"TabBar_HomeBar",
                             @"TabBar_Discovery",
                             @"TabBar_PublicService",
                             @"TabBar_Friends", nil];
        NSArray *selectImgs = [NSArray arrayWithObjects:
                               @"TabBar_HomeBar_Sel",
                               @"TabBar_Discovery_Sel",
                               @"TabBar_PublicService_Sel",
                               @"TabBar_Friends_Sel", nil];
        
        UIViewController* tab1ViewController = (UIViewController *) [self createLoggingViewController:@"DemoViewController"];
        UIViewController* tab2ViewController = [[DTViewController alloc] init];
        UIViewController* tab3ViewController = [[DTViewController alloc] init];
        UIViewController* tab4ViewController = [[DTViewController alloc] init];
        
        NSArray *navArray = @[tab1ViewController, tab2ViewController, tab3ViewController, tab4ViewController];
        NSArray *titles = @[@"Tab1", @"Tab2", @"Tab3", @"Tab4"];
        for (int i = 0; i < [navArray count]; i ++)
        {
            UIImage *bImg = [UIImage imageNamed:baseImgs[i]];
            UIImage *selectImg = [UIImage imageNamed:selectImgs[i]];
            
            UITabBarItem *item = [[UITabBarItem alloc] initWithTitle:titles[i] image:bImg selectedImage:selectImg];
            item.selectedImage = [item.selectedImage imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
            item.image = [item.image imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
            item.tag = i;
            [(UIViewController *)navArray[i] setTabBarItem:item];
            ((UIViewController *)navArray[i]).title = titles[i];
        }
        
        self.rootVC = [[MPTabBarViewController alloc] init];
        self.rootVC.viewControllers = navArray;
        self.rootVC.selectedIndex = 0;
        [self.rootVC.delegate tabBarController:self.rootVC didSelectViewController:tab1ViewController];
    }
    return self;
}

- (id)createLoggingViewController:(NSString *)className
{
    id vc;
    Class cl = NSClassFromString(className);
    if (cl != Nil) {
        vc = [[cl alloc]init];
    }
    else {
        vc = (DTViewController *)[[DTViewController alloc] init];
    }
    return vc;
}


- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application
{
    return self.rootVC;
}

- (void)applicationDidFinishLaunching:(DTMicroApplication *)application
{
    
}

- (void)application:(DTMicroApplication *)application willResumeWithOptions:(NSDictionary *)launchOptions
{
    
}


@end
