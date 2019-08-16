//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_IOpenSimulatorDetectComponent_h
#define SecurityGuardSDK_IOpenSimulatorDetectComponent_h

/**
 *  模拟器检测接口
 */
@protocol IOpenSimulatorDetectComponent <NSObject>

/**
 *  判断当前设备是否是iOS模拟器
 */
- (BOOL) isSimulator;

@end

#endif
