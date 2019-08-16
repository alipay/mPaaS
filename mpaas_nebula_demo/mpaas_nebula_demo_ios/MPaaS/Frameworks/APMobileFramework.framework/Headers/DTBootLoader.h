//
//  DTBootLoader.h
//  APMobileFramework
//
//  Created by shenmo on 5/7/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^DTBootPhaseBlock)();

@interface DTBootPhase : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, copy) DTBootPhaseBlock block;

// 预定义的Phase

/**
 *  创建Window的阶段。
 *  该方法会回调[[[DTFrameworkInterface sharedInstance] bootLoader] createWindow]方法拿到UIWindow对象。
 */
+ (DTBootPhase*)setupWindow;

/**
 *  创建Window与显示Window是两个不同的事件，所以分开
 *  该方法调用[[DFContext sharedContext].window makeKeyAndVisible];
 */
+ (DTBootPhase*)showWindow;

/**
 *  创建NavigationController的阶段。
 *  该方法会回调[[[DTFrameworkInterface sharedInstance] bootLoader] createNavigationController]方法拿到UINavigationController对象。
 */
+ (DTBootPhase*)setupNavigationController;

/**
 *  启动那些只需要执行一次的服务，比如环境配置服务等。同时在默认的DTBootLoader中，这种服务会率先启动。
 *  要使用这个预定义的Phase，需要使用框架的servicesMap功能，配置文件写法参考[DTFrameworkInterface servicesMapConfiguration]方法说明。
 *  请在ServicesMap中配置一个叫"RunOnceServices"的分组，并把只需要执行一次的服务配置在该分组中。
 *  @"RunOnceServices"这个分组不需要配置到"[AUTOSTART]"中。
 */
+ (DTBootPhase*)startRunonceServices;

/**
 *  配置在@"Services"中的服务使用lazyLoading字段标识是否随应用启动而启动。这个DTBootPhase启动所有非lazyLoad的服务。
 */
+ (DTBootPhase*)startNonlazyloadServices;

/**
 *  配置在@"ServicesMap"中的服务，可以通过"[AUTOSTART]"设置是否随应用启动而自动启动，同时可以指定是否同步还是异步。这个DTBootPhase完成这个操作。
 */
+ (DTBootPhase*)startAutostartServicesMapGroups;

/**
 *  使用框架的servicesMap功能后，可以在某个DTBootPhase中启动某个分组下的所有服务，并指定同步或异步。
 *  灵活使用可以很好的控制启动流程，减少启动时不必要的开销，提升启动速度。
 *
 *  如果asynchronous为YES，可以指定priority设置异步启动服务的线程优先级。取值为dispatch_get_global_queue的优先级取值。
 *      DISPATCH_QUEUE_PRIORITY_HIGH
 *      DISPATCH_QUEUE_PRIORITY_DEFAULT
 *      DISPATCH_QUEUE_PRIORITY_LOW
 *      DISPATCH_QUEUE_PRIORITY_BACKGROUND
 */
+ (DTBootPhase*)startServicesMapWithName:(NSString*)groupName asynchronous:(BOOL)asynchronous priority:(long)identifier;

/**
 *  启动Launcher应用，Launcher的配置参考[DTFrameworkInterface applicationsConfiguration]
 */
+ (DTBootPhase*)startLauncher;

/**
 *  执行block的自定义Phase
 */
+ (DTBootPhase*)phaseWithName:(NSString*)name block:(DTBootPhaseBlock)block;

/**
 *  每个DTBootPhase的执行方法
 */
- (void)execute;

@end

@interface DTBootLoader : NSObject

/**
 *  执行指定的Phases数组，这个方法本身并没有什么复杂逻辑，只是按顺序调用phases数组中DTBootPhase类的execute方法。
 */
- (void)executePhases:(NSArray<DTBootPhase*> *)phases;

#pragma mark - 可以在子类中重写的方法

/**
 *  框架默认的实现为依次执行：
        [DTBootPhase setupWindow],                      // 创建window
        [DTBootPhase setupNavigationController],        // 创建主NavigationController
        [DTBootPhase startRunonceServices],             // 运行那些只运行一次就可以，并且需要率先启动的服务
        [DTBootPhase startNonlazyloadServices],         // 启动其它所有非lazyload的服务
        [DTBootPhase startAutostartServicesMapGroups],  // 启动在ServicesMap的"[AUTOSTART]"数组中指定需要自动启动的服务分组
        [DTBootPhase showWindow],                       // 显示主Window
        [DTBootPhase startLauncher],                    // 启动Launcher应用，显示出主界面
 
 *  其中setupWindow，setupNavigationController会回调DTBootLoader的方法。
 *  通常满足绝大多数应用的个性化需求，只需要配置自己的Services即可。
 *
 *  如果仍不满足需求，可以在DTBootLoader中的子类中重写start方法，自定义需要执行的Phases。
 *  需要覆盖DTFrameworkInterface的bootLoader方法，返回自己的DTBootLoader子类的实例。
 */
- (void)start;

/**
 *  默认为空方法，这两个回调由框架在自己在didFinishLaunching中回调。启动bootLoader前调用。
 */
- (void)willStartBootLoader;

/**
 *  默认为空方法，这两个回调由框架在自己在didFinishLaunching中回调。启动bootLoader后调用。
 */
- (void)didStartBootLoader;

/**
 *  [DTBootPhase setupWindow]方法会回调到该方法，接入应用可以创建自定义的UIWindow。
 *
 *  框架默认的实现为创建一个普通的UIWindow，并给它的backgroundColor设置为[[DTFrameworkInterface sharedInstance] defaultBackgroundColor]的值。
 */
- (UIWindow*)createWindow;

/**
 *  [DTBootPhase setupNavigationController]方法会回调该方法，接入应用可以创建自定义的UINavigationController。
 *
 *  框架默认的实现为：
        当接入了CommonUI时，也就是有APNavigationBar子类时，使用APNavigationBar。并且可以使用APCommonUI的主题管理功能配置导航栏。
        否则使用内部类DFNavigationController，接入应用需要自己使用UIAppearance来配置导航栏。
 */
- (UINavigationController*)createNavigationController;

@end
