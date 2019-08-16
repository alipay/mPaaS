//
//  MPZipKit.h
//  MPZipKit
//
//  Created by shenmo on 12/27/14.
//  Copyright (c) 2014 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSData (DTGZip)
- (NSData*) compressGZip;
- (NSData*) decompressGZip;

- (id) initWithGZipFile:(NSString*)path;
- (BOOL) writeToGZipFile:(NSString*)path;
@end


@protocol DTZipArchiveDelegate <NSObject>
@optional
-(void) ErrorMessage:(NSString*) msg;
-(BOOL) OverWriteOperation:(NSString*) file;

@end

@interface DTZipArchive : NSObject {
    //@private
    //	zipFile		_zipFile;
    //	unzFile		_unzFile;
    //
    //	NSString*   _password;
    //	id			_delegate;
}

//@property (nonatomic, retain) id delegate;

-(BOOL) CreateZipFile2:(NSString*) zipFile;
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;
-(BOOL) CloseZipFile2;

-(BOOL) UnzipOpenFile:(NSString*) zipFile;
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite;
-(BOOL) UnzipCloseFile;

- (NSError*) GetLastError;

@end
