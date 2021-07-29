//
//  CCRouterHelper.h
//  bilibili
//
//  Created by Tocoding on 2021/7/28.
//  Copyright © 2021 tocoding. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CCJumper : NSObject
/*
    初始化单例
 */
+ (CCJumper *_Nonnull)sharedInstence;
/**  push有参数跳转界面
 * @param className  要push的界面类名
 * @param dic        界面所需参数字典
 */
- (void)pushViewController:(NSString *_Nonnull)className
 withPropertyValueDic:(NSMutableDictionary *_Nullable)dic animated:(BOOL)animated;
/**  present有参数跳转界面
 * @param className  要present的界面类名
 * @param dic        界面所需参数字典
 */
- (void)presentiewController:(NSString *_Nonnull)className
    withPropertyValueDic:(NSMutableDictionary *_Nullable)dic animated:(BOOL)animated;
/**
 * @return UIViewController  当前根控制器
 */
- (UIViewController *_Nonnull)topViewController;

@end

NS_ASSUME_NONNULL_END
