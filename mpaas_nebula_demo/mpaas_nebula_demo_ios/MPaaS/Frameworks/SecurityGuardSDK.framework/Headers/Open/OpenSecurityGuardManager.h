//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>

/**
 *  各compoent的compoentid，在获取component对象时传入
 */
typedef enum {
    /**
     *  签名component
     */
    OpenSecureSignatureComponentID,
    /**
     *  动态存储component
     */
    OpenDynamicDataStoreComponentID,
    /**
     *  静态存储component
     */
    OpenStaticDataStoreComponentID,
    /**
     *  初始化component
     */
    OpenInitComponentID,
    /**
     *  静态加解密component
     */
    OpenStaticDataEncryptCompnentID,
    /**
     *  data collection compnent
     */
    OpenDataCollectionCompnentID,
    /**
     *  dynamic data encrypt componentID
     */
    OpenDynamicDataEncryptComponentID,
    /**
     *  StaticKeyEncrypt componentID
     */
    OpenStaticKeyEncryptComponentID,
    /**
     *  UMID componentID
     */
    OpenUMIDComponentID,
	/**
     *  OpenSDK componentID
     */
    OpenOpenSDKComponentID,
    /**
     *  AtlasEncrypt ComponentID
     */
    OpenAtlasEncryptComponentID,
    /** 
     *  SimulatorDetect ComponentID
     */
    OpenSimulatorDetectComponentID,
    /**
     *  NoCpatcha ComponentID
     */
    OpenNoCaptchaComponentID,
    /**
     *  SecurityBody ComponentID
     */
    OpenSecurityBodyComponentID,
    /**
     *  无效component
     */
    OpenInvalidComponentID
    
} OpenSecurityGuardComponentID;



/**
 *  签名接口，详细定义见：IOpenSecureSignatureComponent.h
 */
@protocol IOpenSecureSignatureComponent;

/**
 *  动态数据存储接口，详细定义见：IOpenDynamicDataStoreComponent.h
 */
@protocol IOpenDynamicDataStoreComponent;

/**
 *  静态数据存储接口，详细定义见：IOpenStaticDataStoreComponent.h
 */
@protocol IOpenStaticDataStoreComponent;

/**
 *  静态数据存储接口，详细定义见：IOpenStaticDataEncryptComponent.h
 */
@protocol IOpenStaticDataEncryptComponent;

/**
 *  数据采集接口，详细定义见：IOpenDataCollectionComponent.h
 */
@protocol IOpenDataCollectionComponent;

/**
 *  动态数据加密接口，详细定义见：IOpenDynamicDataEncryptComponent.h
 */
@protocol IOpenDynamicDataEncryptComponent;

/**
 *  静态密钥安全加密接口，详细定义见：IOpenStaticKeyEncryptComponent.h
 */
@protocol IOpenStaticKeyEncryptComponent;

/**
 *  获取 umid 接口， 详细定义见 IUMIDComponent.h
 */
@protocol IOpenUMIDComponent;

/**
 *  获取 openSDK 接口， 详细定义见 IOpenOpenSDKComponent.h
 */
@protocol IOpenOpenSDKComponent;

/**
 *  增强加解密接口， 详细定义见 IOpenAtlasEncryptComponent.h
 */
@protocol IOpenAtlasEncryptComponent;

/**
 *  NoCaptcha接口， 详细定义见 IOpenNocpatchaComponent.h
 */
@protocol IOpenNoCaptchaComponent;

/**
 *  模拟器检测接口， 详细定义见 IOpenSimulatorDetectComponent.h
 */
@protocol IOpenSimulatorDetectComponent;

/**
 *  人机接口， 详细定义见 IOpenSecurityBodyComponent.h
 */
@protocol IOpenSecurityBodyComponent;

/**
 *  SecurityGuardSDK管理类
 */
@interface OpenSecurityGuardManager : NSObject

/**
 *  获取SecurityGuardManager单例对象
 *
 *  @return SecurityGuardManager单例对象
 */
+ (OpenSecurityGuardManager*) getInstance;

/**
 *  获取SecurityGuardManager单例对象
 *
 *  @param authCode 初始化传入authcode
 *
 *  @return SecurityGuardManager单例对象
 */
+ (OpenSecurityGuardManager*) getInstance: (NSString *)authCode
                                    error: (NSError * __autoreleasing *)error;

/**
 *  获取安全签名接口
 *
 *  @return 返回签名接口，失败时nil
 */
- (id<IOpenSecureSignatureComponent>) getSecureSignatureComp;



/**
 *  获取动态数据存储接口
 *
 *  @return 返回动态数据存储接口，失败时nil
 */
- (id<IOpenDynamicDataStoreComponent>) getDynamicDataStoreComp;



/**
 *  获取静态数据存储接口
 *
 *  @return 返回静态数据存储接口，失败时nil
 */
- (id<IOpenStaticDataStoreComponent>) getStaticDataStoreComp;



/**
 *  获取静态数据加密接口
 *
 *  @return 返回模拟器检测模块，失败时nil
 */
- (id<IOpenStaticDataEncryptComponent>) getStaticDataEncryptComp;



/**
 *  获取数据采集接口
 *
 *  @return 返回数据采集接口，失败时返回nil
 */
- (id<IOpenDataCollectionComponent>) getDataCollectionComp;



/**
 *  获取动态数据存储接口
 *
 *  @return 返回动态数据存储接口，失败时返回nil
 */
- (id<IOpenDynamicDataEncryptComponent>) getDynamicDataEncryptComp;



/**
 *  获取静态密钥安全加解密接口
 *
 *  @return 返回静态密钥安全加解密接口，失败时返回nil
 */
- (id<IOpenStaticKeyEncryptComponent>) getStaticKeyEncryptComp;



/**
 *  获取UMID接口
 *
 *  @return 返回UMID接口，失败返回nil
 */
- (id<IOpenUMIDComponent>) getUMIDComp;

/**
 *  获取OpenSDK接口
 *
 *  @return 返回OpenSDK接口，失败返回nil
 */
- (id<IOpenOpenSDKComponent>) getOpenOpenSDKComp;

/**
 *  获取增强加密接口
 *
 *  @return 返回增强加密接口，失败返回nil
 */
- (id<IOpenAtlasEncryptComponent>) getAtlasEncryptComp;

/**
 *  获取NoCaptcha接口
 *
 *  @return 返回NoCaptcha接口，失败返回nil
 */
- (id<IOpenNoCaptchaComponent>) getNoCaptchaComp;

/**
 *  获取模拟器检测接口
 *
 *  @return 返回模拟器检测接口，失败返回nil
 */
- (id<IOpenSimulatorDetectComponent>) getSimulatorDetectComp;

/**
 *  获取人机接口
 *
 *  @return 返回模拟器检测接口，失败返回nil
 */
- (id<IOpenSecurityBodyComponent>) getSecurityBodyComp;


/**
 *  根据传入的component id获取对应的component对象
 *
 *  @param componentId 目标compoent的id
 *
 *  @return 返回componentId对应的component对象，失败时返回nil
 */
- (id) getComponent: (OpenSecurityGuardComponentID) componentId;

/**
 *  根据传入的 protocol 获取接口
 *
 *  @param protocol 要获取的 interface
 *
 *  @return 返回的实现 protocol 的对象
 */
- (id) getInterface: (Protocol*) protocol;



/**
 *  获取sdk当前版本号
 *
 *  @return sdk当前版本号
 */
- (NSString*) getSDKVersion;



/**
 *  是否为外部版本的无线保镖SDK
 *
 *  @return 是否为外部版本的无线保镖SDK
 */
- (BOOL) isOpen;



/**
 *  设置用户数据，用于数据上报
 *
 *  @return 无
 */
+ (BOOL) setGlobalUserData: (NSString *) key
           GlobalUserValue: (NSString *) value;


@end
