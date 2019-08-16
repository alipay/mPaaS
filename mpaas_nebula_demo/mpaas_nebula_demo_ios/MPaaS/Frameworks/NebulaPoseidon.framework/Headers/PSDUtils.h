//
//  PSDUtils.h
//  NebulaPoseidon
//
//  Created by theone on 2017/9/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PSDWebView.h"

//********************** Encode ***********************//
NSStringEncoding PSDEncodingFromAcceptCharset(NSString *acceptCharset, NSString *documentCharset);
BOOL PSDIsNonByteBasedEncoding(NSStringEncoding currentEncodeing);
BOOL PSDIsUTF7Encoding(NSStringEncoding currentEncodeing);
NSStringEncoding PSDEncodingForFormSubmission(NSStringEncoding currentEncodeing);
NSString* PSDURLEncodeString(NSString *string);
NSDictionary *PSDURLGetQuery(NSString *queryString);
NSString *PSDURLEncodeData(NSData *data);
NSURL *PSDURLWithFixedString(NSString *URLString);
NSString *PSDGetCookiesStrWithUrlAndCookies(NSURL *url, NSArray *cookies);
NSArray *PSDGetFilterCookies(NSArray *cookies);
BOOL PSDShouldUseNewMethodSyncWKCookies();
NSString *PSDMD5(NSString *string);
NSString *PSGetTokenWithContentView(PSDContentView *view);
NSString *PSDReplaceString(NSString *jsStr,NSString *targetStr, NSString *replaceStr);
NSString *PSDReplaceBridgeWithContentView(PSDContentView *view,NSString *js);
BOOL PSDIsMainFrameRequest(NSURLRequest *request);//用来判断UIWebView的请求是否是主Frame的请求
NSString *PSDString(id obj);
