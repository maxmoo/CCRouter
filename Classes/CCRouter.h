//
//  CCRouter.h
//  bilibili
//
//  Created by Tocoding on 2021/7/27.
//  Copyright © 2021 tocoding. All rights reserved.
//

/**
 *模块间
 *需创建一个管理注册的类，实现协议CCRouterProtocol中的方法
 *
 *模块内
 *有两种选择可以使用openUrl，不过要自行设置过滤规则和方法，参考config
 *也可以使用jumper中的方法直接跳转
 */

#import <Foundation/Foundation.h>

extern NSString *const CCRouterParameterURL;
extern NSString *const CCRouterParameterCompletion;
extern NSString *const CCRouterParameterUserInfo;

/**
 *  routerParameters 里内置的几个参数会用到上面定义的 string
 */
typedef void (^CCRouterHandler)(NSDictionary *routerParameters);

/**
 *  需要返回一个 object，配合 objectForURL: 使用
 */
typedef id (^CCRouterObjectHandler)(NSDictionary *routerParameters);


@interface CCRouter : NSObject


/**
 *  注册 URLPattern 对应的 Handler，在 handler 中可以初始化 VC，然后对 VC 做各种操作
 *
 *  @param URLPattern 带上 scheme，如 CC://beauty/:id
 *  @param handler    该 block 会传一个字典，包含了注册的 URL 中对应的变量。
 *                    假如注册的 URL 为 CC://beauty/:id 那么，就会传一个 @{@"id": 4} 这样的字典过来
 */
+ (void)registerURLPattern:(NSString *)URLPattern toHandler:(CCRouterHandler)handler;

/**
 *  注册 URLPattern 对应的 ObjectHandler，需要返回一个 object 给调用方
 *
 *  @param URLPattern 带上 scheme，如 CC://beauty/:id
 *  @param handler    该 block 会传一个字典，包含了注册的 URL 中对应的变量。
 *                    假如注册的 URL 为 CC://beauty/:id 那么，就会传一个 @{@"id": 4} 这样的字典过来
 *                    自带的 key 为 @"url" 和 @"completion" (如果有的话)
 */
+ (void)registerURLPattern:(NSString *)URLPattern toObjectHandler:(CCRouterObjectHandler)handler;

/**
 *  注册某一模块
 *  @param targetName targetName
 *
 */
+ (void)registerTarget:(NSString *)targetName;

/**
 *  取消注册某个 URL Pattern
 *
 *  @param URLPattern URLPattern
 */
+ (void)deregisterURLPattern:(NSString *)URLPattern;

/**
 *  取消注册某个 target Pattern
 *
 *  @param targetName targetName
 */
+ (void)deregisterTarget:(NSString *)targetName;

/**
 *  打开此 URL
 *  会在已注册的 URL -> Handler 中寻找，如果找到，则执行 Handler
 *
 *  @param URL 带 Scheme，如 CC://beauty/3
 */
+ (void)openURL:(NSString *)URL;

/**
 *  打开此 URL，同时当操作完成时，执行额外的代码
 *
 *  @param URL        带 Scheme 的 URL，如 CC://beauty/4
 *  @param completion URL 处理完成后的 callback，完成的判定跟具体的业务相关
 */
+ (void)openURL:(NSString *)URL completion:(void (^)(id result))completion;

/**
 *  打开此 URL，带上附加信息，同时当操作完成时，执行额外的代码
 *
 *  @param URL        带 Scheme 的 URL，如 CC://beauty/4
 *  @param userInfo 附加参数
 *  @param completion URL 处理完成后的 callback，完成的判定跟具体的业务相关
 */
+ (void)openURL:(NSString *)URL withUserInfo:(NSDictionary *)userInfo completion:(void (^)(id result))completion;

/**
 *  打开此 URL，带上附加信息，同时当操作完成时，执行额外的代码
 *
 *  @param URL        带 Scheme 的 URL，如 CC://beauty/4
 *  @param targetName target的名字
 *  @param userInfo 附加参数
 *  @param completion URL 处理完成后的 callback，完成的判定跟具体的业务相关
 */

+ (void)openURL:(NSString *)URL targetName:(NSString *)targetName withUserInfo:(NSDictionary *)userInfo completion:(void (^)(id result))completion;

/**
 * 查找谁对某个 URL 感兴趣，如果有的话，返回一个 object
 *
 *  @param URL 带 Scheme，如 CC://beauty/3
 */
+ (id)objectForURL:(NSString *)URL;

/**
 * 查找谁对某个 URL 感兴趣，如果有的话，返回一个 object
 *
 *  @param URL 带 Scheme，如 CC://beauty/3
 *  @param userInfo 附加参数
 */
+ (id)objectForURL:(NSString *)URL withUserInfo:(NSDictionary *)userInfo;

/**
 *  是否可以打开URL
 *
 *  @param URL 带 Scheme，如 CC://beauty/3
 *
 *  @return 返回BOOL值
 */
+ (BOOL)canOpenURL:(NSString *)URL;
+ (BOOL)canOpenURL:(NSString *)URL matchExactly:(BOOL)exactly;

/**
 *  调用此方法来拼接 urlpattern 和 parameters
 *
 *  #define CC_ROUTE_BEAUTY @"beauty/:id"
 *  [CCRouter generateURLWithPattern:CC_ROUTE_BEAUTY, @[@13]];
 *
 *
 *  @param pattern    url pattern 比如 @"beauty/:id"
 *  @param parameters 一个数组，数量要跟 pattern 里的变量一致
 *
 *  @return 返回生成的URL String
 */
+ (NSString *)generateURLWithPattern:(NSString *)pattern parameters:(NSArray *)parameters;

@end

