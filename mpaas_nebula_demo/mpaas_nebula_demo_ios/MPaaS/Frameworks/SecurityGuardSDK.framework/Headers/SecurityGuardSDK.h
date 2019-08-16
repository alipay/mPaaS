//
//  SecurityGuardSDK.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 2016/12/29.
//  Copyright © 2016年 Li Fengzhong. All rights reserved.
//

#ifndef SecurityGuardSDK_h
#define SecurityGuardSDK_h

#import <Foundation/Foundation.h>

 

#ifdef _SG_INTERNAL_VERSION_

#import "SecurityGuardManager.h"
#import "SecurityGuardParamContext.h"
#import "DP.h"

#import "Initialize/IInitializeComponent.h"
#import "AtlasEncrypt/IAtlasEncryptComponent.h"
#import "NoCaptcha/INoCaptchaComponent.h"
#import "NoCaptcha/NoCaptchaDefine.h"
#import "UATrace/IUATraceComponent.h"
#import "DynamicDataEncrypt/IDynamicDataEncryptComponent.h"
#import "SecurityDNS/ISecurityDNSComponent.h"
#import "StaticDataEncrypt/IStaticDataEncryptComponent.h"
#import "StaticDataEncrypt/StaticDataEncryptDefine.h"
#import "SimulatorDetect/ISimulatorDetectComponent.h"
#import "DataCollection/IDataCollectionComponent.h"
#import "RootDetect/IRootDetectComponent.h"
#import "SecurityBody/ISecurityBodyComponent.h"
#import "StaticDataStore/IStaticDataStoreComponent.h"
#import "StaticDataStore/StaticDataStoreDefine.h"
#import "DynamicDataStore/IDynamicDataStoreComponent.h"
#import "IndieKit/IIndieKitComponent.h"
#import "IndieKit/IndieKitDefine.h"
#import "SecureSignature/ISecureSignatureComponent.h"
#import "SecureSignature/SecureSignatureDefine.h"

#else

#import "JAQ/SecurityCipher.h"
#import "JAQ/SecuritySignature.h"
#import "JAQ/SecurityStorage.h"
#import "JAQ/SecurityVerification.h"
#import "JAQ/SimulatorDetect.h"

#endif

#import "Open/IOpenSecurityGuardPlugin.h"
#import "Open/OpenSecurityGuardManager.h"
#import "Open/OpenSecurityGuardParamContext.h"
#import "Open/OpenUMID/IOpenUMIDComponent.h"
#import "Open/OpenStaticKeyEncrypt/IOpenStaticKeyEncryptComponent.h"
#import "Open/OpenStaticKeyEncrypt/OpenStaticKeyEncryptDefine.h"
#import "Open/OpenStaticDataStore/IOpenStaticDataStoreComponent.h"
#import "Open/OpenStaticDataStore/OpenStaticDataStoreDefine.h"
#import "Open/OpenStaticDataEncrypt/IOpenStaticDataEncryptComponent.h"
#import "Open/OpenStaticDataEncrypt/OpenStaticDataEncryptDefine.h"
#import "Open/OpenSimulatorDetect/IOpenSimulatorDetectComponent.h"
#import "Open/OpenSecurityBody/IOpenSecurityBodyComponent.h"
#import "Open/OpenSecurityBody/OpenSecurityBodyDefine.h"
#import "Open/OpenSecureSignature/IOpenSecureSignatureComponent.h"
#import "Open/OpenSecureSignature/OpenSecureSignatureDefine.h"
#import "Open/OpenOpenSDK/IOpenOpenSDKComponent.h"
#import "Open/OpenNoCaptcha/IOpenNoCaptchaComponent.h"
#import "Open/OpenNoCaptcha/OpenNoCaptchaDefine.h"
#import "Open/OpenInitialize/IOpenInitializeComponent.h"
#import "Open/OpenDynamicDataStore/IOpenDynamicDataStoreComponent.h"
#import "Open/OpenDynamicDataEncrypt/IOpenDynamicDataEncryptComponent.h"
#import "Open/OpenDataCollection/IOpenDataCollectionComponent.h"
#import "Open/OpenAtlasEncrypt/IOpenAtlasEncryptComponent.h"




#endif /* SecurityGuardSDK_h */
