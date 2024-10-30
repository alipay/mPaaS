//
//  DemoIconFontViewController.m
//  AntUI
//
//  Created by maizhelun on 2016/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "DemoIconFontViewController.h"
//#import "AUIconView.h"
#import "IconfontZoomingViewController.h"
//#import "AUFontLoader.h"
#import <Photos/Photos.h>


#define ICONFONT_UNICODE_DEFINE
#define ICONFONT_NAME_DEFINE

@interface DemoIconFontViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) NSArray *array;
@property (nonatomic, strong) NSArray *nameArray;

@end

@implementation DemoIconFontViewController {
    UITableView *_tableView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    NSString *path = [[NSBundle mainBundle] pathForResource:@"9c95a1b9577175c6d406b884909cef56 2" ofType:@""];
//    NSData *data = [NSData dataWithContentsOfFile:path];
//
//    NSError *error = nil;
//    [AUFontLoader registerFontWithData:data error:&error];
//
//    NSLog(@"%@", error);
//    return;
    
//    UIFont *font = [UIFont fontWithName:@"asdfsdf" size:123];
//    NSLog(@"%@", font);
    
//    NSMutableArray *result1 = [[NSMutableArray alloc] init];
//    NSMutableArray *result2 = [[NSMutableArray alloc] init];
//
//    CGFloat maxY = 0;
//    NSArray *array = @[@"iconfont.bundle/test_1",@"iconfont.bundle/test_2",@"iconfont.bundle/test_3",@"iconfont.bundle/test_4"];
//    NSArray *sizeArray = @[@700, @400, @200, @100];
//    for (NSInteger i = 0; i < array.count; i ++) {
//        NSString *name = array[i];
//
//        CGFloat x = 0;
//        CGFloat y = maxY;
//
//        CGFloat size = [sizeArray[i] floatValue];
//        {
//            CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
//            UIImage *image = [UIImage iconWithName:kICONFONT_SHARE width:size color:nil];
//            UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
//            imageView.y = y;
//            [self.view addSubview:imageView];
//            double cost = CFAbsoluteTimeGetCurrent() - start;
//            [result2 addObject:@(cost)];
//        }
//
//        {
//            CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
//            UIImage *image = [UIImage imageNamed:name];
//            UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
//            imageView.y = maxY;
//            imageView.x = x;
//            maxY = maxY + image.size.height;
//            x = image.size.width;
//            [self.view addSubview:imageView];
//            double cost = CFAbsoluteTimeGetCurrent() - start;
//            [result1 addObject:@(cost)];
//        }
//
//
//
//
//
//    }
////    UIImage *image = [AUIconFont]
////    NSLog(@"%d X %d : %@", );
//    for (NSInteger i = 0; i < array.count; i ++) {
//        NSInteger size = [sizeArray[i] floatValue];
//        NSLog(@"%d X %d : %@ %@", size,size,result1[i], result2[i]);
//    }
//
//    return;
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeNone;
    self.title = @"iconfont(size : 30 X 30)";
    // Do any additional setup after loading the view.
    
    UITableView *tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    tableView.delegate = self;
    tableView.dataSource = self;
    tableView.estimatedRowHeight = NO;
    _tableView = tableView;
    tableView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    [tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"ICONFONTTableViewCell"];
    [self.view addSubview:tableView];
    
//    [UIImage unregisterIconFont:kICONFONT_FONTNAME fontPath:kICONFONT_FONTPATH];
//    [UIImage registerIconFont:kICONFONT_FONTNAME fontPath:kICONFONT_FONTPATH];
//    [AUFontLoader unregisterFontWithName:kICONFONT_FONTNAME];
    
//    NSString *path = [[NSBundle mainBundle] pathForResource:@"goldword" ofType:@"ttf"];
//    NSString *name = [AUFontLoader registerFontWithPath:path error:NULL];
//    
//    UIImage *imagea = [UIImage iconWithName:@"汉" fontName:name width:30 color:RGB(0xffffff)];
//    NSLog(@"%@", imagea);
    
    ICONFONT_UNICODE_DEFINE{
_array = @[kICONFONT_MAILLIST, kICONFONT_NEWS_WRITE, kICONFONT_NEWS_COMMENT, kICONFONT_NEWS_FAVORITES, kICONFONT_SETTING, kICONFONT_XIAOZHANGBEN_, kICONFONT_MORE, kICONFONT_BARCODE, kICONFONT_BACK, kICONFONT_COMPLAIN, kICONFONT_SEARCH, kICONFONT_SHARE, kICONFONT_DELETE, kICONFONT_ITEMLIST, kICONFONT_SCANCODE, kICONFONT_DRAGDOWN, kICONFONT_PRAISE, kICONFONT_MAP, kICONFONT_CHECKBOX_SELECTED, kICONFONT_NOTICE, kICONFONT_XIAOZHANGBEN_1, kICONFONT_CANCEL_STYLE1, kICONFONT_USER_ADD, kICONFONT_COMMENT, kICONFONT_ZHI1, kICONFONT_CHOOSE, kICONFONT_BILL, kICONFONT_ADD, kICONFONT_USER, kICONFONT_USER_SETTING, kICONFONT_DUN, kICONFONT_CASHIER, kICONFONT_VOICE, kICONFONT_CANCEL_STYLE2, kICONFONT_CANCEL_STYLE3, KICONFONT_CHECKBOX_NORMAL, kICONFONT_DETAIL, kICONFONT_SYSTEM_RELOAD, kICONFONT_SHH_CYFW, kICONFONT_LIUYAN, kICONFONT_SHANGJIADIANHUA, kICONFONT_SHANGJIAKEFU, kICONFONT_GROUP_CHAT, kICONFONT_HEART, kICONFONT_CONTACTS, kICONFONT_PHONECONTACTS, kICONFONT_MINUS_SQUARE_O, kICONFONT_PLUS_SQUARE_O, kICONFONT_HELP, kICONFONT_ALIPAYLOGO_H, kICONFONT_ALIPAYLOGO_Z, kICONFONT_GUANZHU, kICONFONT_ALIPAYLOGO_R, kICONFONT_SLICE, kICONFONT_HONGBAO, kICONFONT_SLICE1, kICONFONT_SYSTEM_ANT, kICONFONT_SYSTEM_ANTTALK, kICONFONT_FIN_EDIT, kICONFONT_SYSTEM_SUOXIAO, kICONFONT_SYSTEM_FANGDA, kICONFONT_SYSTEN_TRIANGLE, kICONFONT_SYSTEN_KEY, kICONFONT_HUABEI, kICONFONT_BINGTU, kICONFONT_SYSTEM_CANCEL_BOLD, kICONFONT_YONGHUZICHANZHUANHUCOPY, kICONFONT_SHUALIAN, kICONFONT_ZHANGDANDANGQIANXIANG, kICONFONT_ZHANGDANFEIDANGQIAN, kICONFONT_ICON_TEST, kICONFONT_SYSTEM_INFORMATION, kICONFONT_RECTANGLE, kICONFONT_TIXINGLINGDANG, kICONFONT_HUANGGUAN, kICONFONT_JIEPINGFANKUI, kICONFONT_HANGYE_GIFT, kICONFONT_HANGYE_NOTE, kICONFONT_HANGYE_BUS, kICONFONT_SHENGHUOHAO_V, kICONFONT_SYSTEM_DOWLOAD, kICONFONT_HANGYE_CHENGCHEDOU, kICONFONT_SYSTEM_WAIT_L, kICONFONT_SYSTEM_DEFEATED, kICONFONT_SYSTEM_SERCH, kICONFONT_SYSTEM_DELETEB, kICONFONT_SYSTEM_ADDRESSBOOK, kICONFONT_SYSTEM_CARD, kICONFONT_WARNING_CIRCLE, kICONFONT_SYSTEM_CHARGE, kICONFONT_SYSTEM_COMPLAIN, kICONFONT_SYSTEM_COMPLAINT, kICONFONT_SYSTEM_CONCEAL, kICONFONT_SYSTEM_COPY, kICONFONT_SYSTEM_DISLIKE3, kICONFONT_SYSTEM_EXPRESSFEE, kICONFONT_SYSTEM_DISLIKE, kICONFONT_SYSTEM_FRIENDS, kICONFONT_SYSTEM_JINZHI, kICONFONT_SYSTEM_JUJUE, kICONFONT_SYSTEM_INTERNET, kICONFONT_SYSTEM_LOADINGC, kICONFONT_SYSTEM_LOCK, kICONFONT_SYSTEM_LOADINGB, kICONFONT_SYSTEM_PAYMENT, kICONFONT_SYSTEM_PHONEBOOK, kICONFONT_SYSTEM_REMIND, kICONFONT_SYSTEM_SELECT, kICONFONT_SYSTEM_PEOPLENO, kICONFONT_SYSTEM_SHAREB, kICONFONT_SYSTEM_TRACKPARCEL, kICONFONT_SYSTME_EXPRESSDELIV, kICONFONT_SYSTEM_WARNING3, kICONFONT_SYTEM_COLLECT, kICONFONT_SYSTEM_WAIT, kICONFONT_FOLLOW, kICONFONT_SYSTEM_KOUBEIMIAN, kICONFONT_SYSTEM_QUESTION, kICONFONT_CLOSEXIAN, kICONFONT_SYSTEM_MAP2, kICONFONT_EXCLAMATION_CIRCLE_O, kICONFONT_CROSS_CIRCLE_O, kICONFONT_LIKE, kICONFONT_SYSTEM_TIPSXIAN, kICONFONT_SYSTEM_KOUBEIXIAN, kICONFONT_SYSTEM_CLOSEA, kICONFONT_LOEFT, kICONFONT_PHONE, kICONFONT_SYSTEM_TIPS, kICONFONT_SYSYTEM_ADDPERSON, kICONFONT_SYSYTEM_TIXING, kICONFONT_SYSTEM_FRIENDSZ, kICONFONT_SYSTEM_FRIENDSB, kICONFONT_SYSTEM_NOEYE, kICONFONT_KNOWLEDGE_SHAREPIC, kICONFONT_SYSTEM_NOSOUND, kICONFONT_ZHI];;
}
    
    ICONFONT_NAME_DEFINE{
_nameArray = @[@"kICONFONT_MAILLIST", @"kICONFONT_NEWS_WRITE", @"kICONFONT_NEWS_COMMENT", @"kICONFONT_NEWS_FAVORITES", @"kICONFONT_SETTING", @"kICONFONT_XIAOZHANGBEN_", @"kICONFONT_MORE", @"kICONFONT_BARCODE", @"kICONFONT_BACK", @"kICONFONT_COMPLAIN", @"kICONFONT_SEARCH", @"kICONFONT_SHARE", @"kICONFONT_DELETE", @"kICONFONT_ITEMLIST", @"kICONFONT_SCANCODE", @"kICONFONT_DRAGDOWN", @"kICONFONT_PRAISE", @"kICONFONT_MAP", @"kICONFONT_CHECKBOX_SELECTED", @"kICONFONT_NOTICE", @"kICONFONT_XIAOZHANGBEN_1", @"kICONFONT_CANCEL_STYLE1", @"kICONFONT_USER_ADD", @"kICONFONT_COMMENT", @"kICONFONT_ZHI1", @"kICONFONT_CHOOSE", @"kICONFONT_BILL", @"kICONFONT_ADD", @"kICONFONT_USER", @"kICONFONT_USER_SETTING", @"kICONFONT_DUN", @"kICONFONT_CASHIER", @"kICONFONT_VOICE", @"kICONFONT_CANCEL_STYLE2", @"kICONFONT_CANCEL_STYLE3", @"KICONFONT_CHECKBOX_NORMAL", @"kICONFONT_DETAIL", @"kICONFONT_SYSTEM_RELOAD", @"kICONFONT_SHH_CYFW", @"kICONFONT_LIUYAN", @"kICONFONT_SHANGJIADIANHUA", @"kICONFONT_SHANGJIAKEFU", @"kICONFONT_GROUP_CHAT", @"kICONFONT_HEART", @"kICONFONT_CONTACTS", @"kICONFONT_PHONECONTACTS", @"kICONFONT_MINUS_SQUARE_O", @"kICONFONT_PLUS_SQUARE_O", @"kICONFONT_HELP", @"kICONFONT_ALIPAYLOGO_H", @"kICONFONT_ALIPAYLOGO_Z", @"kICONFONT_GUANZHU", @"kICONFONT_ALIPAYLOGO_R", @"kICONFONT_SLICE", @"kICONFONT_HONGBAO", @"kICONFONT_SLICE1", @"kICONFONT_SYSTEM_ANT", @"kICONFONT_SYSTEM_ANTTALK", @"kICONFONT_FIN_EDIT", @"kICONFONT_SYSTEM_SUOXIAO", @"kICONFONT_SYSTEM_FANGDA", @"kICONFONT_SYSTEN_TRIANGLE", @"kICONFONT_SYSTEN_KEY", @"kICONFONT_HUABEI", @"kICONFONT_BINGTU", @"kICONFONT_SYSTEM_CANCEL_BOLD", @"kICONFONT_YONGHUZICHANZHUANHUCOPY", @"kICONFONT_SHUALIAN", @"kICONFONT_ZHANGDANDANGQIANXIANG", @"kICONFONT_ZHANGDANFEIDANGQIAN", @"kICONFONT_ICON_TEST", @"kICONFONT_SYSTEM_INFORMATION", @"kICONFONT_RECTANGLE", @"kICONFONT_TIXINGLINGDANG", @"kICONFONT_HUANGGUAN", @"kICONFONT_JIEPINGFANKUI", @"kICONFONT_HANGYE_GIFT", @"kICONFONT_HANGYE_NOTE", @"kICONFONT_HANGYE_BUS", @"kICONFONT_SHENGHUOHAO_V", @"kICONFONT_SYSTEM_DOWLOAD", @"kICONFONT_HANGYE_CHENGCHEDOU", @"kICONFONT_SYSTEM_WAIT_L", @"kICONFONT_SYSTEM_DEFEATED", @"kICONFONT_SYSTEM_SERCH", @"kICONFONT_SYSTEM_DELETEB", @"kICONFONT_SYSTEM_ADDRESSBOOK", @"kICONFONT_SYSTEM_CARD", @"kICONFONT_WARNING_CIRCLE", @"kICONFONT_SYSTEM_CHARGE", @"kICONFONT_SYSTEM_COMPLAIN", @"kICONFONT_SYSTEM_COMPLAINT", @"kICONFONT_SYSTEM_CONCEAL", @"kICONFONT_SYSTEM_COPY", @"kICONFONT_SYSTEM_DISLIKE3", @"kICONFONT_SYSTEM_EXPRESSFEE", @"kICONFONT_SYSTEM_DISLIKE", @"kICONFONT_SYSTEM_FRIENDS", @"kICONFONT_SYSTEM_JINZHI", @"kICONFONT_SYSTEM_JUJUE", @"kICONFONT_SYSTEM_INTERNET", @"kICONFONT_SYSTEM_LOADINGC", @"kICONFONT_SYSTEM_LOCK", @"kICONFONT_SYSTEM_LOADINGB", @"kICONFONT_SYSTEM_PAYMENT", @"kICONFONT_SYSTEM_PHONEBOOK", @"kICONFONT_SYSTEM_REMIND", @"kICONFONT_SYSTEM_SELECT", @"kICONFONT_SYSTEM_PEOPLENO", @"kICONFONT_SYSTEM_SHAREB", @"kICONFONT_SYSTEM_TRACKPARCEL", @"kICONFONT_SYSTME_EXPRESSDELIV", @"kICONFONT_SYSTEM_WARNING3", @"kICONFONT_SYTEM_COLLECT", @"kICONFONT_SYSTEM_WAIT", @"kICONFONT_FOLLOW", @"kICONFONT_SYSTEM_KOUBEIMIAN", @"kICONFONT_SYSTEM_QUESTION", @"kICONFONT_CLOSEXIAN", @"kICONFONT_SYSTEM_MAP2", @"kICONFONT_EXCLAMATION_CIRCLE_O", @"kICONFONT_CROSS_CIRCLE_O", @"kICONFONT_LIKE", @"kICONFONT_SYSTEM_TIPSXIAN", @"kICONFONT_SYSTEM_KOUBEIXIAN", @"kICONFONT_SYSTEM_CLOSEA", @"kICONFONT_LOEFT", @"kICONFONT_PHONE", @"kICONFONT_SYSTEM_TIPS", @"kICONFONT_SYSYTEM_ADDPERSON", @"kICONFONT_SYSYTEM_TIXING", @"kICONFONT_SYSTEM_FRIENDSZ", @"kICONFONT_SYSTEM_FRIENDSB", @"kICONFONT_SYSTEM_NOEYE", @"kICONFONT_KNOWLEDGE_SHAREPIC", @"kICONFONT_SYSTEM_NOSOUND", @"kICONFONT_ZHI"];;
}
    
    
    
    
    for (NSString *name in _array) {
        if ([UIImage isIconExists_au:name inFont:kICONFONT_FONTNAME]) {
            NSLog(@"%@存在", name);
        }
        else {
            NSLog(@"%@不存在", name);
        }
    }
    
    if (![UIImage isIconExists_au:@"\U0000e312" inFont:kICONFONT_FONTNAME]) {
        NSLog(@"不存在");
    }
    
    self.navigationItem.rightBarButtonItem = [AUBarButtonItem barButtonItemWithTitle:@"截图" target:self action:@selector(saveImage)];
    
}


AUToast *toast;
- (void)saveImage
{
    toast = AUToastShow(self.view, AUToastIconLoading, nil, @"AntUIDemo");
    
//    UIGraphicsBeginImageContext(_tableView.frame.size);
//    CGContextRef context = UIGraphicsGetCurrentContext();
//    [_tableView.layer renderInContext:context];
//    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
//    UIGraphicsEndImageContext();
    
    UIImage *image = [self getCapture];
    
    // UIImageWriteToSavedPhotosAlbum 这个方法,默认保存到系统相机胶卷,但是@selector后面的方法 必须是这种格式:  - (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;
    //保存图片到系统相册
    UIImageWriteToSavedPhotosAlbum(image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
    
//    __weak DemoIconFontViewController *weakSelf = self;
//    [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
//        PHAssetChangeRequest *req = [PHAssetChangeRequest creationRequestForAssetFromImage:image];
//    } completionHandler:^(BOOL success, NSError * _Nullable error) {
//        NSLog(@"success = %d, error = %@", success, error);
//
//    }];
}


- (NSArray *)splitImage:(UIImage *)image height:(CGFloat)height
{
    CGImageRef tmpImgRef = image.CGImage;
    
    if (image.size.height <= height) {
        return @[image];
    }
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    CGFloat y = 0;
    while (y < image.size.height * [UIScreen mainScreen].scale) {
        CGImageRef aImageRef = CGImageCreateWithImageInRect(tmpImgRef, CGRectMake(0, y, image.size.width * [UIScreen mainScreen].scale, height * [UIScreen mainScreen].scale));
        UIImage *aImage = [UIImage imageWithCGImage:aImageRef];
        CGImageRelease(aImageRef);
        [array addObject:aImage];
        
        y += height * [UIScreen mainScreen].scale;
    }
    
    return array;
}

- (UIImage *)composeImg:(NSArray *)images {
//    UIImage *img = [UIImage imageNamed:@"0.png"];
//    CGImageRef imgRef = img.CGImage;
//    CGFloat w = CGImageGetWidth(imgRef);
//    CGFloat h = CGImageGetHeight(imgRef);
//
//    //以1.png的图大小为底图
//    UIImage *img1 = [UIImage imageNamed:@"1.png"];
//    CGImageRef imgRef1 = img1.CGImage;
//    CGFloat w1 = CGImageGetWidth(imgRef1);
//    CGFloat h1 = CGImageGetHeight(imgRef1);
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    CGSize maxSize = CGSizeZero;
    

    CGPoint point = CGPointZero;
    for (NSInteger i = 0; i < images.count; i ++) {
        UIImage *img1 = images[i];
        CGImageRef imgRef1 = img1.CGImage;
        CGFloat w1 = CGImageGetWidth(imgRef1);
        CGFloat h1 = CGImageGetHeight(imgRef1);
        
        CGRect frame = CGRectMake(point.x, point.y, w1, h1);
        [array addObject:[NSValue valueWithCGRect:frame]];
        
        if (maxSize.height < CGRectGetMaxY(frame)) {
            maxSize.height = CGRectGetMaxY(frame);
        }
        if (maxSize.width < CGRectGetMaxX(frame)) {
            maxSize.width = CGRectGetMaxX(frame);
        }
        
        // 换行
        if (i % 3 == 2) {
            point.x = 0;
            point.y = maxSize.height;
        }
        else {
            point.x = CGRectGetMaxX(frame);
        }
    }
    
    
    //以1.png的图大小为画布创建上下文
    UIGraphicsBeginImageContext(maxSize);
    
    
    for (NSInteger i = 0; i < array.count; i ++) {
        [images[i] drawInRect:[((NSValue *)array[i]) CGRectValue]];//先把1.png 画到上下文中
    }
    
    UIImage *resultImg = UIGraphicsGetImageFromCurrentImageContext();//从当前上下文中获得最终图片
    UIGraphicsEndImageContext();//关闭上下文
    return resultImg;
}

- (UIImage*)getCapture
{
    
    
    CGPoint offset= [_tableView contentOffset];
    _tableView.contentOffset = CGPointMake(0.0,0.0);
    
    CGRect visibleRect = _tableView.bounds;
    
    UIGraphicsBeginImageContextWithOptions(_tableView.contentSize,_tableView.opaque,0.0);
    [_tableView.layer renderInContext:UIGraphicsGetCurrentContext()];
    
    while(_tableView.contentSize.height>=(visibleRect.origin.y + visibleRect.size.height)){
        
        visibleRect.origin.y +=visibleRect.size.height;
        
        [_tableView scrollRectToVisible:visibleRect animated:NO];
        
        [_tableView.layer renderInContext:UIGraphicsGetCurrentContext()];
    }
    
    UIImage * image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    _tableView.contentOffset = offset;
    
    
    NSArray *images = [self splitImage:image height:600];
    
    image = [self composeImg:images];
    
    return image;
    
//    UIGraphicsBeginImageContextWithOptions(CGSizeMake(_tableView.contentSize.width, _tableView.contentSize.height),false, 0.0);
//    CGContextRef context = UIGraphicsGetCurrentContext();
//    CGRect previousFrame = _tableView.frame;
//    _tableView.frame = CGRectMake(_tableView.frame.origin.x, _tableView.frame.origin.y, _tableView.contentSize.width, _tableView.contentSize.height);
//    [_tableView.layer renderInContext:context];
//    _tableView.frame = previousFrame;
//    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
//    UIGraphicsEndImageContext();
//    return image;
    
    
    UIImage* viewImage = nil;
    UITableView *scrollView = _tableView;
    UIGraphicsBeginImageContextWithOptions(scrollView.contentSize, NO, [UIScreen mainScreen].scale);
    {
        CGPoint savedContentOffset = scrollView.contentOffset;
        CGRect savedFrame = scrollView.frame;
        
        scrollView.contentOffset = CGPointZero;
        scrollView.frame = CGRectMake(0, 0, scrollView.contentSize.width, scrollView.contentSize.height);
        
        [scrollView.layer renderInContext: UIGraphicsGetCurrentContext()];
        viewImage = UIGraphicsGetImageFromCurrentImageContext();
        
        scrollView.contentOffset = savedContentOffset;
        scrollView.frame = savedFrame;
    }
    UIGraphicsEndImageContext();
    
    
    
    return viewImage;
}

/**
 *  写入图片后执行的操作
 *
 *  @param image       写入的图片
 *  @param error       错误信息
 *  @param contextInfo UIImageWriteToSavedPhotosAlbum第三个参数
 */
- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo {
    AUToastShowWithAutoHide(self.view, AUToastIconNone, !error ? @"保存成功" : @"保存失败", @"AntUIDemo");
    [toast dismissToast];
}

//- (void)setupNav
//{
//    AUBarButtonItem *item = [AUBarButtonItem barButtonItemWithTitle:@"反注册" target:self action:@selector(iconfontRegister)];
//}
//
//- (void)iconfontRegister
//{
//    [UIImage unregisterIconFont:kICONFONT_FONTNAME fontPath:kICONFONT_FONTPATH];
//}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
 #pragma mark - Navigation
 
 // In a storyboard-based application, you will often want to do a little preparation before navigation
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
 // Get the new view controller using [segue destinationViewController].
 // Pass the selected object to the new view controller.
 }
 */

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{

    return 60;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _array.count / 2 + (_array.count % 2);
}

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"ICONFONTTableViewCell"];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    // 第一列
    {
        if (![cell.contentView viewWithTag:1]) {
            AUIconView *view = [[AUIconView alloc] initWithFrame:CGRectZero name:_array[indexPath.row]];
            view.tag = 1;
            
            view.size_mp = CGSizeMake(30, 30);
            view.origin_mp = CGPointMake(50, 5);
            view.color = RGB(0x2b91e2);
            [cell.contentView addSubview:view];
        }
        if (![cell.contentView viewWithTag:2]) {
            UILabel *label = [[UILabel alloc] init];
            label.font = [UIFont systemFontOfSize:10];
            label.minimumScaleFactor = 0.1;
            label.adjustsFontSizeToFitWidth = YES;
            label.textColor = [UIColor grayColor];
            label.tag = 2;
            
            label.size_mp = CGSizeMake(180, 10);
            label.origin_mp = CGPointMake(10, 40);
            [cell.contentView addSubview:label];
        }
        
        AUIconView *view = [cell.contentView viewWithTag:1];
        view.name = _array[indexPath.row * 2];
        
        UILabel *label = [cell.contentView viewWithTag:2];
        label.text = _nameArray[indexPath.row * 2];
        
        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(clickView:)];
        [view addGestureRecognizer:gesture];
        view.userInteractionEnabled = YES;
    }
    
    
    // 第二列
    {
        if (![cell.contentView viewWithTag:3]) {
            AUIconView *view = [[AUIconView alloc] initWithFrame:CGRectZero name:_array[indexPath.row]];
            view.tag = 3;
            
            view.size_mp = CGSizeMake(30, 30);
            view.origin_mp = CGPointMake(230, 5);
            view.color = RGB(0x2b91e2);
            [cell.contentView addSubview:view];
        }
        if (![cell.contentView viewWithTag:4]) {
            UILabel *label = [[UILabel alloc] init];
            label.font = [UIFont systemFontOfSize:10];
            label.textColor = [UIColor grayColor];
            label.minimumScaleFactor = 0.1;
            label.adjustsFontSizeToFitWidth = YES;
            label.tag = 4;
            
            label.size_mp = CGSizeMake(195, 10);
            label.origin_mp = CGPointMake(200, 40);
            [cell.contentView addSubview:label];
        }
        
        AUIconView *view = [cell.contentView viewWithTag:3];
        UILabel *label = [cell.contentView viewWithTag:4];
        if ((indexPath.row * 2 + 1) < _array.count) {
            view.name = _array[indexPath.row * 2 + 1];
            label.text = _nameArray[indexPath.row * 2 + 1];
        } else {
            view.name = nil;
            label.text = nil;
        }
        
        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(clickView:)];
        [view addGestureRecognizer:gesture];
        view.userInteractionEnabled = YES;
    }
    
    return cell;
}

- (void)clickView:(UITapGestureRecognizer *) gestureRecognizer
{
    AUIconView *view = (AUIconView *)gestureRecognizer.view;
    NSLog(@"%@",view.name);
    
    IconfontZoomingViewController *vc = [[IconfontZoomingViewController alloc] init];
    vc.iconName = view.name;
    vc.iconColor = view.color;
    [self.navigationController pushViewController:vc animated:YES];
    
}


@end
