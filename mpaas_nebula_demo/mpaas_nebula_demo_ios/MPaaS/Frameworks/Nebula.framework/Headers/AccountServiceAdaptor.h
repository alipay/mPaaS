//
//  SAAccountService.h
//  AccountManager
//
//  Created by weitingLuo on 13-4-15.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <AliLoginAccount/AliLoginAccount.h>
//#import <AliLoginAutoLogin/AliLoginAutoLoginManager.h>

#define kSAAccountDidExitNotification @"SAAccountDidExitNotification"
#define kAPLoginControllerDidFinishNotification @"APLoginControllerDidFinishNotification"
#define LOGIN_NOTIFICATION_ACCOUNTCHANGED @"login_notifaction_changeAccount"

//#define ELoginResult NSUInteger
//#define kLoginSource @"loginSource"

//#import <AliLoginAutoLogin/AliLoginAutoLogin.h>

@class SAUserInfo;

/**
 * 用户信息服务
 */
@protocol SAAccountService <DTService>

/**
 *  当前账户
 */
@property (nonatomic,strong,readonly) SAUserInfo *userInfo;

/**
 *账户列表
 *最新的一个在最后一个位置；
 */
@property (nonatomic, readonly, strong) NSMutableArray *accountList;

/**
 *  最后登录用户的userId
 */
@property (nonatomic, strong) NSString *lastUserId;


/**
 * 脱敏手机号
 */
@property (nonatomic, readonly, strong) NSString *desensityPhoneNumber;


/**
 * 脱敏登录号
 */
@property (nonatomic, readonly, strong) NSString *desensityLoginID;

/**
 *  设置当前账户
 */
- (BOOL)setCurrentUser:(SAUserInfo *)currentUser;

/**
 *  验证是否有效的账户
 */
- (BOOL)isValidUser:(SAUserInfo *)user;

/**
 *  通过userId或loginId创建一个账户
 *  如果账户列表中存在userId或loginId，返回存在的账户
 *  否则创建一个新账户
 */
- (SAUserInfo *)createNewUserWithUserId:(NSString *)userId loginId:(NSString *)loginId;

/**
 *  删除一个账户
 */
- (BOOL)deleteAccountWithName:(NSString *)username;

/**
 *  删除一个账户的淘宝账户
 */
- (void)deleteTaobaoAccountWithLoginId:(NSString *)loginId;

/**
 *  新增一个账户。如果此账户存在，则更新。
 *
 *  如果外部希望更新某一账户的数据，先使用findUserById，拿到SAUserInfo的对象，将数据更新在这个对象中，再调用此方法。
 */
- (BOOL)addAccountWithUserInfo:(SAUserInfo *)user;

/**
 *  更新账户， loginID和userID至少一个不唯一，建议使用userID；会优先使用userId查找，如果loginID、userID均找不到对应的userInfo，则返回失败；
 */
-(BOOL)updateAccountInfo:(SAUserInfo *)userInfo;

/**
 *  根据登录名查找用户
 */
- (SAUserInfo *)findUserByLoginId:(NSString *)loginId;

/**
 *  根据userId查找用户
 */
- (SAUserInfo *)findUserByUserId:(NSString *)userId;

/**
 *  返回本地所有账户的名字
 */
- (NSArray *)allAccountName;

/**
 * 返回所有账户
 */
- (NSArray *)allAccount;

/**
 * 根据类型返回所有账户
 */
//- (NSArray *)accountsWithLoginType:(SSLoginType)loginType;

/**
 * 根据类型返回账户
 * 最多返回returnNumber个账户
 */
//- (NSArray *)accountsWithLoginType:(SSLoginType)loginType returnNumber:(int)number;

/**
 * 根据类型返回账户的loginId
 */
//- (NSArray *)loginIdsWithLoginType:(SSLoginType)loginType;

/**
 * 添加账户, 从快捷导入账户后调用那个此方法添加
 */
- (void)addAccountWithMSUserFlagEntityInArray:(NSArray *)accounts;

/**
 *  添加账户
 */
- (void)addAccountWithSAUserInfoInArray:(NSArray *)accounts;

/**
 * 更新账户。替换所有账户。
 */
- (BOOL)updateAllAccounts:(NSArray *)updateAccounts;


/**
 *  安全退出当前账户
 */
- (void)resetCurrentAccount;

/**
 * 保存账户
 */
- (void)saveAccount;

/**
 * 隐藏手机号
 */
- (NSString *)hideRule:(NSString *)string;


/**
 删除当前账户时候用到（只给账户管理中删除当前账号使用，其他业务请勿调用）
 */
- (void)deleteLastUserId;

@end


//
//  AuthService.h
//  AuthService
//
//  Created by weitingLuo on 13-4-17.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//


@class MSUserLogoutResult;
//@class SSAuthCountryInfo;
/**
 *session超时消息
 */

//extern NSString * const kSSMsgSessionInvalid;

/*
 * key值各模块指定，按如下优先级选择一个即可：rpc的operationType、所在类的类名、appid、模块名
 *
 */




/**
 * \code SSAuthService 类提供授权服务中心功能。
 */
@protocol SSAuthService <DTService>

/**
 *当前用户信息
 */
@property (readonly, strong) SAUserInfo *userInfo;

//标示是否账密页已经显示出来
@property(atomic, assign) BOOL hasLoginViewControllerDisplayed;

//标示是否走rpc特殊通道，防止锁线程
@property(atomic, assign) BOOL isSpecialChannelRPC;


/* 9.6之后不推荐再使用此方法
 @function      用当前账户先同步调用免登接口, 失败起帐密
 @abstract      前台模调用doAuth;
 @return
 */
- (BOOL)doAuthWithForegroundMode;

/* 9.6之后不推荐再使用此方法，请使用
 *  - (BOOL)doAuthLoginSyncForeground:(BOOL)foreground params:(NSDictionary*)params;
 * 同步调用免登接口；
 *
 * 供MobileFoundation处理RPC session失效时使用
 * 供快捷维护登录态使用；
 *
 */
- (BOOL)doAuthWithBackgroundMode;


/*
 * 同步接口
 *
 * @foreground 必须，YES：用当前账户先同步调用免登接口, 失败起帐密；
 *                  NO:  用当前账户同步调用免登接口；
 * @params     可选，作为统计使用；params中key为kAuthSource；
 * 供MobileFoundation处理RPC session失效时使用
 * params里的key为kLoginSource，值
 * 供快捷维护登录态使用；
 *
 */
- (BOOL)doAuthLoginSyncForeground:(BOOL)foreground params:(NSDictionary*)params;



- (void)doLogoutWith:(NSString *)logoutType completion:(void(^)(MSUserLogoutResult *result))completion;

/**
 *  登出
 */
- (void)doLogout;
/**
 *@function isLoggedIn
 *@abstract 判断是否已经登录
 *@return 返回是否已经登录
 */
- (BOOL)isLoggedIn;


/**
 * 用于框架组拉起账密页；其他业务请勿使用
 * 如果本次冷启动为账密页，则completeBlock在账密页展示后回调框架；
 * 如果本次冷启动为免登，则completeBlock直接回调，不会等免登结果； 免登如果失败，再起账密页也不会再调用completeBack；
 * SSAuthService保证会在主线程回调completeBlock，并且只会回调一次；
 *
 */
- (void)showLoginViewControllerIfNeed:(void(^)())completeBlock;

/**
 *  是否会显示账密页
 *
 *  @return YES 会显示，NO 不会显示
 */
- (BOOL)shouldShowLoginViewController;


#pragma mark - 新的登录接口
//帐密登录。userInfo传nil则使用当前用户,仅用于安全内部调用,业务不要调用
- (void)loginPureForegroundAyncWithUser:(SAUserInfo*)userInfo
                             onComplete:(void(^)(BOOL isLoggedIn))onComplete;

//帐密登录。仅用于安全内部调用,业务不要调用
- (void)loginPureForegroundAsyncWithExtraInfo:(NSDictionary *)extraInfo
                                   onComplete:(void(^)(BOOL isLoggedIn))onComplete;

//账密登录
- (void)loginPureForegroundAsyncWithUser:(SAUserInfo*)userInfo
                               extraInfo:(NSDictionary *)extraInfo
                              onComplete:(void(^)(BOOL isLoggedIn))onComplete;
//报活动态信息，仅供钱包使用
-(void)reportDeviceLocationInfo:(NSDictionary*)userInfo callback:(void(^)(BOOL isSucess, NSString *msgError))onComplete;

/**
 *  同步返回最近一次收到devcieLocation服务端返回时，服务段时间和客户端时间的差值（服务端减客户端,秒数）
 *  如无，返回0
 */
-(NSTimeInterval)getTimeDiff;


//登录客户端开关
- (BOOL)getValueOfSwitch:(NSString *)switchName sensitiveCompare:(BOOL)sensitive defaultValue:(BOOL)defaultValue;


#pragma mark - 仅安全线内部使用
//删除登录的cookie，仅供安全线内部模块使用，外部模块勿调；
-(void)deleteLoginCookie;

//截屏反馈信息传递
- (void)updateFeedBackInfo:(NSDictionary *)params;
- (void)feedBackInfoDelete;

/**
 检测到被拷贝之后调用（仅供防拷贝使用）
 
 @param sourceId 必须传  调用方自定义来源
 */
- (void)resetLogin:(NSString *)sourceId;


/**
 防拷贝是否已经设置过本地的登录态（仅供防拷贝使用）
 
 @return YES:为已经设置过
 */
- (BOOL)isDeviceCopyHasLogout;

/**
 无密用户重置密码后修改userinfon中的标记hasQueryPassword
 */
- (void)resethasQueryPasswordFlag;


/**
 防拷贝从安全SDK获取设备信息
 
 @return 设备信息
 */
- (NSString *)deviceInfoFromAPSecSecuritySDK;

@end


@interface SAUserInfo : NSObject <NSCoding>
{
}

//账户id
//readonly
@property (nonatomic, copy) NSString *loginId;

//双登录名中的另一个loginId，和上面的当前loginId相对的。双登录名指邮箱和手机号都可作为loginId。
@property (nonatomic, copy) NSString *otherLoginId;

//淘宝账户，当用淘宝账户登录成功后会记录。
@property (nonatomic, copy) NSString *taobaoLoginId;

//用户标志
@property (nonatomic, copy) NSString *userId;

//免登标志
@property(nonatomic, assign) BOOL autoLoginEnabled;

//用户头像地址
@property (nonatomic,copy) NSString *iconUrl;

//登陆时间,用户登录时间
@property (nonatomic,copy) NSString *loginServerTime;

//帐密登陆时间,用户登录时间
@property (nonatomic,copy) NSString *loginServerTime_withPwd;

//淘宝的登陆session
@property (nonatomic,copy) NSString *taobaoSid;

//条码支付token
@property (nonatomic,copy) NSString *barcodePayToken;

//安全支付token
@property (nonatomic,copy) NSString *extern_token;

//登陆token
@property (nonatomic,copy) NSString *loginToken;

//本次登录获取得到的sessionId
@property(nonatomic, strong) NSString *sessionId;

//客户端当前的最新版本
@property (nonatomic,copy) NSString *currentProductVersion;

//AppId，itunes里支付宝应用的id，目前的值是：333206289
@property (nonatomic,copy) NSString *appId;

/**
 * 升级提示
 * 0：无需升级
 * 1：可选择升级
 * 2：强制升级
 */
@property (nonatomic,copy) NSString *existNewVersion;

@property (nonatomic,copy) NSString *updateMemo;

//版本路径
@property (nonatomic,copy) NSString *downloadURL;

//支付宝登录验证码URL
@property (nonatomic,copy) NSString *loginCheckCodeUrl;

//支付宝登录验证码图片
@property (nonatomic,copy) NSString *loginCheckCodeImg;

//淘宝校验码图片data参数
@property (nonatomic,copy) NSString *tbCheckCodeId;

//淘宝校验码链接
@property (nonatomic,copy) NSString *tbCheckCodeUrl;

//登录上下文，json格式的字符串
@property (nonatomic,copy) NSString *loginContext;


//密码
@property (nonatomic, copy) NSString *password;

//登录类型
//@property (nonatomic, assign) SSLoginType loginType;

//是否开启小额免密支付
@property(nonatomic, copy) NSString *swPwdSwitch;

//手势：手势密码
@property(nonatomic, copy) NSString *gesturePassword;

//手势：是否设置手势（何武）
@property (nonatomic, assign) BOOL isSkipGesture;

//手势：是否设置手势（何武）
@property (nonatomic, assign) int gestureTryCount;

//手势：手势密码模式（0为普通模式，1为便捷模式）
@property(nonatomic, assign) int gestureMode;

//手势：是否隐藏手势密码轨迹
@property (nonatomic, assign) BOOL isHideGestureTrack;

//是否指纹解锁开启
@property (nonatomic, assign) BOOL isFingerprintLockScreenEnable;

//锁屏设置是否开启
- (BOOL)isLockScreenEnabled;

//用户名称,用户的真实姓名
@property (nonatomic, copy) NSString *userName;

//绑定的手机号
@property (nonatomic, copy) NSString *mobileNo;

// 是否实名制用户
@property (nonatomic, assign) BOOL isRealNamed;

//是否是实名认证用户
//实名制是实名认证的基础；
@property (nonatomic, assign) BOOL isCertified;
/**
 * 账户是否绑定手机号
 */

@property(nonatomic, assign) BOOL mobileBinded;
/**
 * 是否有设置密保问题
 */

@property(nonatomic, assign) BOOL setSecurityQA;
/**
 * 支付盾
 */

@property(nonatomic, assign) BOOL openedUKey;
/**
 * 数字证书
 */

@property(nonatomic, assign) BOOL openedDigitalCert;
/**
 * 短信动态校验码
 */

@property(nonatomic, assign) BOOL openedDynamicPwd;
/**
 * 是否开启手机宝令
 */

@property(nonatomic, assign) BOOL openedMobileOtp;

/**
 * 上次安全等级分数
 */
@property(nonatomic, copy) NSString *lastSecurityScore;

/**
 * 账户类型
 */
//@property(nonatomic, assign) SCAccountType accountType;

/**
 * 是否引导绑定银行卡，废弃，业务不要用
 */
@property(nonatomic, assign) BOOL isBindCard;

/**
 * 登录返给客户端的扩展结果，实名制相关信息就放在这里
 */
@property(nonatomic, strong) NSDictionary *extResAttrs;

/**
 * 用户类型: 个人/商家
 *  @"1"： 企业用户；
 *  @"2"： 个人
 */
@property(nonatomic, strong) NSString *customerType;

/**
 * 标识是否新用户
 */
@property(nonatomic, assign) BOOL isNewUser;

/**
 *  显示名字
 *
 *  企业实名用户显示用户名，非实名用户返回nil；
 *  个人有昵称用户显示昵称，无昵称是实名认证或实名制用户显示用户名，其他返回nil；
 *  备注名属于好友对用户的标注，不属于账户属性，不在userInfo内；
 */
@property(nonatomic, strong) NSString *showName;

/**
 *  昵称
 *
 *  透传用户的昵称字段
 */
@property(nonatomic, strong) NSString *nick;

/**
 *  会员等级，value 有四种 'primary,golden,platinum,diamond'
 *  不是每个账户都有值；
 */
@property(nonatomic, strong) NSString *memberGrade;


/**
 *  极简钱包标示：
 wallet_standard  支付宝钱包标准版
 * wallet_simple_young  支付宝钱包极简儿童版
 * wallet_simple_general  支付宝钱包极简普通版
 * wallet_simple_old  支付宝钱包极简老年版
 * wallet_init 支付宝钱包版本未设置，当从CIF查询不到数据，返回此类型
 */
@property(nonatomic, strong) NSString *walletEdition;


//登录状态，YES：此账户已登录   NO：此账户未登录
/**
 *  9.6.9之后，isLoginState会进行持久化处理，用户登陆成功后，会持久化为YES；
 *  只有在安全退出、设备锁被踢、免登失败被踢到账密页，设置为NO
 *
 *  所以：此值返回YES，不再代表登录通知已发，需要通过loginFinishNotification字段判定；
 */
@property (nonatomic, assign) BOOL isLoginState;


/**
 *  本次登录成功时，发出的登录通知缓存；
 *  用于依赖登录通知启动的业务在错过登录通知的情况下，进行查询；
 *  通知的数据和字段和kAPLoginControllerDidFinishNotification完全相同.
 *
 *  重要：9.6.9之后，isLoginState会进行持久化处理，是否错过本次登录通知需要以本字段是否有值来判定；
 *  本字段有值代表登录通知已发，本字段为空，代表登录通知还未发送；
 *
 */
@property(nonatomic, strong) NSNotification *loginFinishNotification;


/**
 *  账户状态
 *
 *  注意：userInfo只保证@"T"状态的及时性；如果为Q状态，需要业务方再去判定一次；
 *
 *  @"Q" : 需要补全身份信息
 *  @"T" : 不需要补全身份信息
 *  值为@"T"时，不需要补全身份信息，为@"Q"时，需要业务方自己再去判定一次；
 *
 */
@property(nonatomic, strong) NSString *enabledStatus;

//新增类型 淘宝会员名、在读大学生认证状态、收货地址个数、性别
@property(nonatomic, strong) NSString *taobaoNick;
@property(nonatomic, strong) NSString *studentCertify;
@property(nonatomic, strong) NSString *gender;
@property(nonatomic, strong) NSString *addressCount;
@property(nonatomic, strong) NSString *loginNumber;
@property(nonatomic, strong) NSString *loginEmail;

//操作员Id
@property(nonatomic, strong) NSString *operatorId;
//操作员名称
@property(nonatomic, strong) NSString *operatorName;
//操作员类型
@property(nonatomic, strong) NSString *operatorType;

//无密标志，用户是否有登录密码（原银行业务的查询密码）
@property(nonatomic, assign) BOOL hasQueryPassword;

@end
