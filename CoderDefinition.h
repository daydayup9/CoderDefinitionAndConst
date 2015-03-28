//
//  CoderDefinition.h
//  CoderDefinition
//
//  Created by SHB on 15/2/26.
//  Copyright (c) 2015年 CoderSHB. All rights reserved.
//
//  本宏文件收录了iOS开发常用的宏，本人会不定时的更新，希望大家批评指正，给予支持。如果大家有什么好的建议、想法可以联系本人，Email：CoderSHB@163.com

#ifndef ______CoderDefinition_h
#define ______CoderDefinition_h

/*************************  屏幕相关  *************************/

/** 获取屏幕尺寸、宽度、高度 */
#define kScreen_RECT ([[UIScreen mainScreen] bounds])
#define kScreen_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define kScreen_HEIGHT ([UIScreen mainScreen].bounds.size.height)


/*************************  硬件相关  *************************/

/** 判断是真机还是模拟器 */
#if TARGET_OS_IPHONE
//  iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//  iPhone Simulator
#endif

/** 判断是否为iPhone */
#define isiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

/** 判断是否是iPad */
#define isiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

/** 判断是否为iPod */
#define isiPod ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

/** 判断是否 Retina屏 */
#define isRetina ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale == 2.0f))

/** 设备是否为iPhone 4/4S 分辨率320x480，像素640x960，@2x */
#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

/** 设备是否为iPhone 5C/5/5S 分辨率320x568，像素640x1136，@2x */
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

/** 设备是否为iPhone 6 分辨率375x667，像素750x1334，@2x */
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

/** 设备是否为iPhone 6 Plus 分辨率414x736，像素1242x2208，@3x */
#define iPhone6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)


/*************************  系统相关  *************************/

/** 获取系统版本 */
#define iOS_VERSION ([[[UIDevice currentDevice] systemVersion] floatValue])
#define CurrentSystemVersion ([[UIDevice currentDevice] systemVersion])

/** 是否为iOS6 */
#define iOS6 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) ? YES : NO)

/** 是否为iOS7 */
#define iOS7 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) ? YES : NO)

/** 是否为iOS8 */
#define iOS8 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) ? YES : NO)

/** 获取当前语言 */
#define kCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

/** 获取APP名称 */
#define APP_NAME ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])

/** 获取APP版本 */
#define APP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])

/** 获取APP build版本 */
#define APP_BUILD ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])


/*************************  内存相关  *************************/

/** 使用ARC和不使用ARC */
#if __has_feature(objc_arc)
//  compiling with ARC
#else
//  compiling without ARC
#endif

/** 释放对象 */
#if !__has_feature(objc_arc)

/** 释放一个对象 */
#define kRelease_safely(__POINTER) { [__POINTER release]; __POINTER = nil; }

/** 释放一个对象 */
#define kDelete_safely(__POINTER) if(__POINTER) { [__POINTER release], __POINTER = nil; }

#endif


/*************************  本地文档相关  *************************/

/** 定义UIImage对象 */
#define kImageNamed(_pointer) ([UIImage imageNamed:[UIUtil imageName:_pointer]])

/** 定义UIImage对象并从本地文件读取加载图片 */
#define kImage(name) ([UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:name ofType:nil]])

/** 读取本地图片 */
#define kLoadImage(file,ext) ([UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]])

/** 获取Documents目录 */
#define kDocumentsPath ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])

/** 获得Documents下指定文件名的文件路径 */
#define kFilePath(filename) ([[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingPathComponent:filename];)

/** 获取Library目录 */
#define kLibraryPath ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])

/** 获取Caches目录 */
#define kCachesPath ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])

/** 获取Tmp目录 */
#define kTmpPath NSTemporaryDirectory()


/*************************  颜色相关  *************************/

/** 清除背景色 */
#define kClearColor [UIColor clearColor]

/** 背景色 */
#define kBackgroundColor [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

/** 获取随机色 */
#define kRandomColor ([UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0f])

/** 根据RGB16进制值获取颜色（16进制->10进制） */
#define kColorWithRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/** 带有RGBA的颜色设置 */
#define kColorWithRGBA(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

/** 获取RGB颜色 */
#define kRGB(r,g,b) kColorWithRGBA(r,g,b,1.0f)


/*************************  Quartz 2D相关  *************************/

//后续添加中...


/*************************  其他未分类  *************************/

/** 定义一个APPKEY */
#define APPKEY                @"APPKEY"

/** 定义一个API */
#define APIURL                @"http://xxxxx/"

/** 字体定义 */
#define kFontSize(size) [UIFont systemFontOfSize:size]
#define kFontWihtNameAndSize(name,fontSize) [UIFont fontWithName:name size:fontSize]

/** 由弧度获取角度 */
#define radianToDegrees(radian) (radian * 180.0)/(M_PI)

/** 由角度获取弧度 */
#define kDegreesToRadian(degrees) (M_PI * (degrees) / 180.0)

/** NSFileManager 实例化 */
#define kFileManager [NSFileManager defaultManager]

/** NSUserDefaults 实例化 */
#define kUserDefalut [NSUserDefaults standardUserDefaults]

/** NSNotificationCenter 实例化 */
#define kNotificationCenter [NSNotificationCenter defaultCenter]

/** UIApplication 实例化 */
#define kApplication [UIApplication sharedApplication]

/** GCD */
#define kGCDWithGlobal(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define kGCDWithMain(block) dispatch_async(dispatch_get_main_queue(),block)


/*************************  打印日志  *************************/

/** 调试（DEBUG）状态，打开LOG功能 */
#ifdef DEBUG
#   define kLog(...) NSLog(__VA_ARGS__);
/** 发布（RELEASE）状态，关闭LOG功能 */
#else
#   define kLog(...)
#endif

/** 调试（DEBUG）状态下打印当前方法名，行数以及自定义的内容 */
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

/** 重写NSLog,Debug模式下打印日志和当前行数 */
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

/** DEBUG  模式下打印日志,当前行 并弹出一个警告 */
#ifdef DEBUG
#   define ULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define ULog(...)
#endif


/*************************  ARC和MRC环境下的单例宏代码  *************************/

/** 定义.h文件中类方法 */
#define singleton_h(name) + (instancetype)shared##name;

/*************************  使用GCD实现单例  *************************/

/** 当前是MRC环境 */
#if !__has_feature(objc_arc)

#define singleton_m_GCD(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [self alloc] init]; \
} \
}); \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
-(oneway void)release \
{ \
} \
\
- (instancetype)autorelease \
{ \
return _instance; \
} \
\
- (instancetype)retain \
{ \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
} \
\
-(NSUInteger)retainCount \
{ \
return 1; \
}


#else /** 当前是ARC环境 */

#define singleton_m_GCD(name) \
static id _instance = nil; \
+ (instancetype)shared##name{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [self alloc] init]; \
} \
}); \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
+(id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
} 

#endif


/*************************  使用@synchronized实现单例  *************************/

/** 当前是MRC环境 */
#if !__has_feature(objc_arc)

#define singleton_m_synchronized(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [self alloc] init]; \
} \
} \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
} \
return _instance; \
} \
\
-(oneway void)release \
{ \
} \
\
- (instancetype)autorelease \
{ \
return _instance; \
} \
\
- (instancetype)retain \
{ \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
} \
\
-(NSUInteger)retainCount \
{ \
return 1; \
}

#else /** 当前是ARC环境 */

#define singleton_m_synchronized(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [self alloc] init]; \
} \
} \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
} \
return _instance; \
} \
\
+(id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
}

#endif


#endif