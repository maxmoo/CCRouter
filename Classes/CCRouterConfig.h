//
//  CCRouterConfig.h
//  bilibili
//
//  Created by Tocoding on 2021/7/28.
//  Copyright © 2021 tocoding. All rights reserved.
//

#import <Foundation/Foundation.h>


//可用于拦截url自定义处理(这里提供了一个思路)
NS_ASSUME_NONNULL_BEGIN

@interface CCRouterConfig : NSObject

+ (instancetype)sharedInstance;
- (NSString *)selectorStringForKey:(NSString *)key;
- (NSArray *)checkArray;

@end

NS_ASSUME_NONNULL_END
