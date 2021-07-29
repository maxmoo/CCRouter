//
//  CCRouterConfig.m
//  bilibili
//
//  Created by Tocoding on 2021/7/28.
//  Copyright © 2021 tocoding. All rights reserved.
//

#import "CCRouterConfig.h"
#import "CCJumper.h"

@implementation CCRouterConfig

+ (instancetype)sharedInstance
{
    static CCRouterConfig *config;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        config = [[CCRouterConfig alloc] init];
    });
    return config;
}

- (NSString *)selectorStringForKey:(NSString *)key {
    NSInteger index = [[self checkArray] indexOfObject:key];
    switch (index) {
        case 0:
            return @"push:";
            break;
        case 1:
            return @"present:";
        default:
            break;
    }
    return @"defaultMethod";
}


- (NSArray *)checkArray {
    return @[@"push",
             @"present"];
}

#pragma mark - selectors
- (void)push:(NSDictionary *)params {
    /*
     key:class
     key:info
     */
    if (!params[@"class"]) {
        [self defaultMethod];
        return;
    }
    
    NSMutableDictionary *valueDic = [NSMutableDictionary dictionaryWithDictionary:params[@"info"]];
    
    if (params[@"block"]) {
        [valueDic setValue:params[@"block"] forKey:@"completion"];
    }
    
    [[CCJumper sharedInstence] pushViewController:params[@"class"] withPropertyValueDic:valueDic animated:YES];
}

- (void)present:(NSDictionary *)params {
    if (!params[@"class"]) {
        [self defaultMethod];
        return;
    }
    
    NSMutableDictionary *valueDic = [NSMutableDictionary dictionaryWithDictionary:params[@"info"]];
    
    if (params[@"block"]) {
        [valueDic setValue:params[@"block"] forKey:@"completion"];
    }
        
    [[CCJumper sharedInstence] presentiewController:params[@"class"] withPropertyValueDic:valueDic animated:YES];
}

- (void)defaultMethod {
    NSLog(@"default method!!!");
}

@end
