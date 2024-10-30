//
//  MPLauncherAppDelegate.h

#import <Foundation/Foundation.h>

@interface MPLauncherAppDelegate : NSObject <DTMicroApplicationDelegate>

- (UIViewController *)rootControllerInApplication:(DTMicroApplication *)application;

@end
