//
//  CCRouterProtocol.h
//  bilibili
//
//  Created by Tocoding on 2021/7/27.
//  Copyright © 2021 tocoding. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CCRouterProtocol <NSObject>

@required

/// 是否可以注册url
/// @param params {@"url":url}
- (BOOL)canRegisterUrl:(NSDictionary *)params;
- (void)reRegisterAll;
- (void)deregisterAll;

@end
