//
//  NBLogProtocol.h
//  NebulaLogging
//
//  Created by Glance on 16/11/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APLogTrackContext;

/**
 复写TrackAgent需实现的协议，至少有一个pageStart/end周期，且必须配对出现
 在pageEnd时可添加自有业务所需的日志项
 可继承NBLogTrackAgent抽象基类做继承复写
 */
@protocol NBLogTrackAgentProtocol <NSObject>
@optional

/**
 在pageEnd时可添加自有业务所需的日志项

 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等

 @return 额外的自定义业务日志
 */
- (NSDictionary *)extraPageEndParamForPSDContext:(PSDContext *)psdContext trackContext:(APLogTrackContext *)trackContext;

/**
 由H5或RN前端报告页面开始，默认作为一次pageStart; 或持续报告页面信息

 @param psdContext Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param data 前端在页面加载后向容器报告初始化信息"spm"，或细节信息"spmDetail",参考文档jsapi-reportData

 @return 由报告信息创建或更新后的APRemoteLogging上下文
 */
- (APLogTrackContext *)context:(PSDContext *)psdContext didReportData:(NSDictionary *)data;

/**
 页面第一次将要出现，不建议使用
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext willFirstAppear:(APLogTrackContext *)trackContext;

/**
 页面第一次已经出现，不建议使用
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext didFirstAppear:(APLogTrackContext *)trackContext;


/**
 所在ViewController将要被压至次栈顶或出栈，可选为pageEnd

 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext willDisAppear:(APLogTrackContext *)trackContext;

/**
 所在ViewController已经被压至次栈顶或出栈，可选为pageEnd
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext didDisAppear:(APLogTrackContext *)trackContext;


/**
 UIKIT中的viewWillAppear，并且页面是由pop引起的，可选为pageStart

 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext willResume:(APLogTrackContext *)trackContext;


/**
 UIKIT中的viewDidAppear，并且页面是由pop引起的，可选为pageStart
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */

- (void)context:(PSDContext *)psdContext didResume:(APLogTrackContext *)trackContext;
// 所在PSDPage被销毁(UIWebView中的一次主文档更新)


/**
 Nebula中的psdContentPage析构且VC未更换，即同VC内页面主文档更换

 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext didMainDocChange:(APLogTrackContext *)trackContext;

/**
 接入客户端应用，如支付宝钱包，由后台进入前台，可选为pageStart
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext willAppResume:(APLogTrackContext *)trackContext;

/**
 接入客户端应用，如支付宝钱包，由前台进入后台，可选为pageEnd
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 */
- (void)context:(PSDContext *)psdContext willAppPause:(APLogTrackContext *)trackContext;


@end


@protocol NBLogClickAgentProtocol <NSObject>
@optional

/**
 在点击时可添加自有业务所需的日志项
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等
 
 @return 额外的自定义业务日志
 */
- (NSDictionary *)extraClickParamForPSDContext:(PSDContext *)psdContext trackContext:(APLogTrackContext *)trackContext;

/**
 控件点击

 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param data 前端在区块点击时上报日志相关数据, 参考文档jsapi-autoClick
 */
- (void)context:(PSDContext *)psdContext didClickWithData:(NSDictionary *)data;

@end

@protocol NBLogExtraParamProtocol <NSObject>

/**
 可添加自有业务所需的自动日志公共项
 
 @param psdContext   Nebula框架中定义的上下文，可取到View/VC/Session等对象
 @param trackContext APReoteLogging组件上定义的上下文，可取到spmId，bizType等

 @return 额外的自定义业务日志
 */
- (NSDictionary *)extraParamForPSDContext:(PSDContext *)psdContext trackContext:(APLogTrackContext *)trackContext;


@end

