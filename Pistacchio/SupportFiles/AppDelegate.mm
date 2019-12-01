//
//  AppDelegate.m
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "AppDelegate.h"
#import "NewsHelper.h"

@interface AppDelegate ()
@property (nonatomic, strong) NewsHelper *services;
@end

@implementation AppDelegate

- (instancetype)init
{
    self = [super init];
    if (self) {
        NewsHelper *services = [[NewsHelper alloc] init];
        [services setDelegate:self];
        self.services = services;
    }
    return self;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [self.services serviceStart];
    return YES;
}


#pragma mark - UISceneSession lifecycle

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
