//
//  H5Utils.h
//  H5Service
//
//  Created by tgf on 14-1-22.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaSDK/NBFileManager.h>
#import <APWebImage/SDWebImage.h>

@class H5Service;
@class H5WebViewController;
@class OPAppManageService;
@class NebulaAppService;
@class SPSafePayService;
@class MyFavoritesService;
@protocol UploadAdressBookService;
@protocol APShortLinkService;
@protocol APConfigService;

#pragma mark - Get Service
/************************************* Get Service ********************************************/
H5Service                   *H5GetH5Service();
#ifndef NB_INSIDE
id<SAAccountService>        H5GetSAAccountService();
id<SSAuthService>           H5GetSSAuthService();
#endif
OPAppManageService          *H5GetOPAppManageService();
NebulaAppService            *H5GetNebulaAppService();
id                          H5GetSPSafePayService();
id<UploadAdressBookService> H5GetUploadAdressBookService();
id<APShortLinkService>      H5GetAPShortLinkService();
id<APConfigService>         H5GetAPConfigService();
id                          H5GetMyFavoritesService();


#pragma mark - Color
/*************************************** Color ************************************************/
UIColor *H5ColorWithWebString(NSString *colorString); // #aarrggbb 、 #rrggbb 、 rgb(rr,gg,bb) 、 argb(aa,rr,gg,bb)
UIColor *H5ColorWithHex(int hex); // 0xAARRGGBB、0xRRGGBB



#pragma mark - Image
/*************************************** Image ************************************************/
//UIImage *captureView(UIView *theView, CGRect fra);
UIImage *H5ReSizeImage(UIImage *image, CGSize reSize);
UIImage *H5LoadImageFromBundle(NSString *bundleName, NSString *name);
void    H5DownloadImage(NSURL *url, SDWebImageDownloaderCompletedBlock block);
UIImage *H5ImageFromColor(UIColor *color, CGSize size);


#pragma mark - URL
/**************************************** URL *************************************************/
BOOL H5IsURL(NSString *str);
BOOL H5IsAlipayHost(NSString *host);
BOOL H5IsMyBankHost(NSString *host);
BOOL H5IsFileURL(NSString *url);
BOOL H5IsUrlInAlipayWhitelist(NSURL *url); //判断是否在支付宝域
BOOL H5IsUrlInAliWhitelist(NSURL *url); // 判断是否是在集团域内
BOOL H5IsUrlInSeriousAliWhitelist(NSURL *url); // 判断是否是在严格的集团域内
BOOL H5IsUrlInPartnerWhitelist(NSURL *url); //判断是否在合作伙伴域内
BOOL H5IsUrlInRpcWhitelist(NSURL *url); //判断是否在RPC接口调用白名单内
BOOL H5IsUrlInSSLVerifyDomain(NSURL *url); // 判断是否是在需要校验SSL请求的白名单内
BOOL H5UrlEqualsIgnoreHash(NSString *u1, NSString *u2);
//NSString *H5URLEncode(NSString *str);
//NSString *H5URLDecode(NSString *url);
NSString *H5URLString(NSString *urlString, NSURL *baseURL);
NSDictionary *H5URLGetQuery(NSString *urlString);
NSString *H5GetAlipayURL(NSString *url);
NSString *H5StripLandingURL(NSString *url); //剥离landing前缀
NSString *H5BasicURLFromAlipaysOrLanding(NSString *url); //从alipays或landing中取出真实url


#pragma mark - Encrypt & Decrypt
/********************************** Encrypt & Decrypt *****************************************/
//NSString    *H5MD5(NSString *string);
//NSString    *H5MD5OfData(NSData *data);
//NSString    *H5Base64Encode(NSData *data);
//NSData      *H5Base64Decode(NSString *string);
uint32_t    H5CRC(NSData *data);
UIImage     *H5Base64Decode2Image(NSString *string);


#pragma mark - JSON
/**************************************** JSON ***********************************************/
id          H5ReadJSON(NSString *file);
BOOL        H5WriteJSON(NSString *file, id object);
id          H5ParseJSONData(NSData *data);
id          H5ParseJSONString(NSString *string);
NSString    *H5JSONString(id object);



#pragma mark - Regex
/**************************************** Regex ***********************************************/
BOOL H5RegexTest(NSString *str, NSArray *patterns);
BOOL H5OppositeRegexTest(NSString *str, NSArray *patterns);



#pragma mark - Dict
/**************************************** Dict ************************************************/
NSDictionary *H5DictMerge(NSDictionary *a, NSDictionary *b);



#pragma mark - Log
/***************************************** Log ************************************************/
void H5PrintLog(NSString *str);
void H5PrintLogFromSource(NSString *str, NSString *source);



#pragma mark - Date
/**************************************** Date ************************************************/
long long H5TimeStamp(NSDate *date);
long long H5TimeDiff(NSDate *date1, NSDate *date2);


#pragma mark - NSString
/************************************** NSString **********************************************/
NSString *H5String(NSString *str, NSString *defaultStr);
NSString *H5NonemptyString(NSString *str, NSString *defaultStr); // 取非空的那个
NSString *H5ExistString(NSString *str); // 不是NSString的话返回空字符串


#pragma mark - NSArray
/************************************** NSArray ***********************************************/
NSArray *H5Array(NSArray *arr, NSArray *defaultArr);

#pragma mark - NSDictionary
/************************************** NSDict ***********************************************/
NSDictionary *H5Dictionary(NSDictionary *dict, NSDictionary *defaultDict);

#pragma mark - Network
/*************************************** Network **********************************************/
NSString    *H5NetWorkName(); // 运营商名称
NSString    *H5NetWorkType(); // 网络类型：NOTREACHABLE、UNKNOWN、2G、3G、4G、WIFI
NSString    *H5WifiSSID();    // 获取WIFI下的SSID名称
NSString    *H5GatewayIP();   // 获取默认网关IP地址
NSString    *H5DNSIP(NSURL *url);       // 解释DNS 耗时操作

BOOL        H5IsIntranet(BOOL *completed); // 判断是否内网，completed表示是否已经完成dns解析，如果completed是NO，则返回NO。不必缓存该值，内部已做处理。


#pragma mark - Size
/**************************************** Size ************************************************/
CGSize getKeyboardSize(id sender);


#pragma mark - Other
/**************************************** Other ***********************************************/
void H5Swizzle(Class c, SEL orig, SEL newSEL);

Class H5GetWebViewClass(NSURL *url, NSString *appId, BOOL isH5NormalMode);

NSString *H5GetErrorHtmlContent(NSError *error, NSDictionary *params, NSString **errorTitle);
NSString *H5GetErrorHtmlContentNew(NSError *error, NSDictionary *params, NSString **errorTitle);
NSMutableDictionary *H5ErrorHtmlInfo(NSURL* url, NSString* spdy);

BOOL H5IsSystemScheme(NSString *scheme);
BOOL H5IsAlipayScheme(NSString *scheme);
BOOL H5IsAFWealthScheme(NSString *scheme);
NSDictionary *H5OptionsWithURL(NSString *url);

BOOL H5IsSPDYErrorDomain(NSError *error);
NSString *H5GetWebsiteNameByHost(NSString *host);

double H5GetUsedMemory();


NSArray *H5dynamicJsUrlByUrl(NSString *url, NSString *referer, NSString *appId, NSString *publicId, NSArray *ruleGroups);

NSDictionary *H5filterBoolString(NSDictionary *dic);

NSURL *H5fixGotoUrl(NSString *url, NSString *defaulturl);

BOOL  H5IsH5App(NSString *appId);
BOOL  H5IsTinyApp(NSString *appId);
BOOL  H5isH5Browser(NSString *appId);

NSCachedURLResponse *H5GetCachedResponse(NSString *url);

BOOL  H5IsMainDocumentUrl(NSURL *mainUrl, NSURL *url);

NSString *H5GetInjectViewIdFromVc(UIViewController *vc);

UIImage *H5SnapShot(CGSize size, UIView *view, BOOL isWK);

UIImage *H5SnapshotWithView(UIView *view,BOOL shouldStripView);

NSURL *H5StaticRouterUrl(H5WebViewController *webViewController, NSURL *origUrl, NSInteger origCode);

BOOL  H5ShouldSaveDataWithKey(NSString *key, NSString *business);

UIImage * _Nullable H5CachableAUBundleImage(NSString * _Nonnull imageName);

BOOL H5IsVcVisible(UIViewController *vc);

#pragma mark - getPrivateName

# ifdef DEBUG
#define DECLAREPRIVATE(a, b, c) \
+ (NSString *)getName_##a \
{ \
NSString *base64Str = @""#b""; \
NSString *decodeStr = [NSString stringWithBase64EncodedString:base64Str]; \
NSCAssert([decodeStr isEqualToString:@""#c""], @"缺陷修复类编码异常，请处理"); \
NSCAssert(NSClassFromString(decodeStr)||NSSelectorFromString(decodeStr), @"缺陷修复类名不存在，请处理"); \
return decodeStr; \
}
# else
#define DECLAREPRIVATE(a, b, c) \
+ (NSString *)getName_##a \
{ \
NSString *base64Str = @""#b""; \
NSString *decodeStr = [NSString stringWithBase64EncodedString:base64Str]; \
return decodeStr; \
}
# endif

