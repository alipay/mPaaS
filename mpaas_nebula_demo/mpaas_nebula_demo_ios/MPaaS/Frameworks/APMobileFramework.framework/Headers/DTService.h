//
//  DTService.h
//  MobileCore
//
//  Created by WenBi on 13-4-3.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

/**
 * \code DTService 代表一个服务。
 */
@protocol DTService <NSObject>

@required

/**
 * 启动一个服务。框架在完成初始化操作后，会调用该方法。
 *
 * 如果一个服务要启动一个应用，必须在该法被调用之后，才能启动其它的应用。
 */
- (void)start;

@optional

/**
 *  服务已经完成创建。
 */
- (void)didCreate;

/**
 *  服务即将释放。
 */
- (void)willDestroy;

@end

typedef id<DTService> IDTService;

/**
 *  根据指定的key获取scheme
 *
 *  @param key 标识scheme的key，可以是以下任意一个值：
 *      - alipay
 *      - alipays
 *      - alipayqr
 *      - alipass
 *      - alpauto
 *      - aw
 *      - alipaywifi
 *
 *  @return 如果当前版本是rc版本，以上的key值会追回 _rc 后返回，否则原样返回。
 *
 *  比如：
 *  <pre>NSString *scheme = DTSchemeGetName(@"alipays")</pre>
 *  在rc版本中，scheme变量的值为：alipays_rc，在非rc的版本中，scheme变量的值为：alipays。
 */
NSString * DTSchemeGetName(NSString *key);

/**
 *  对传入的URL字符串按照scheme的规则进行规范处理。
 *
 *  @param URLString 表示URL的字符串
 *
 *  @return 对指定的URL按照rc的规则进行处理后的URL字符串。
 */
NSString * DTSchemeNormalizeURLString(NSString *URLString);

/**
 *  对指定的URL对象按照scheme的规则进行规范处理。
 *
 *  @param aURL 需要处理的URL对象。
 *
 *  @return 对指定的URL对象按照rc的规则进行处理后的URL对象。
 */
NSURL * DTSchemeNormalizeURL(NSURL *aURL);
