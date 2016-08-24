//
//  AppDelegate.m
//  MRC_to_ARC-NLog
//
//  Created by Wang,Guoxiang on 16/8/24.
//  Copyright © 2016年 Wang,Guoxiang. All rights reserved.
//

#import "AppDelegate.h"

#import "NLog.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [NLog startWithAppId:@"9" configs:@{@"encryptToken": @"5D97EEF8-3127-4859-2222-82E6C8FABD80"}];
    
    //以下这段代码，完全拷贝原先的示例demo，纯属做尝试用
    
    //    [[NLog getTracker:@"wenku"] setSampleRate:0.05];
    
    [NLog set:@"protocolParameter"
          val:[NSDictionary dictionaryWithObjectsAndKeys:
               @"protocolkey", @"originalkey",
               @"ea",@"eventAction"
               , nil]];
    
    [NLog set:@"paid" val:@"11111111" isMutable:YES];
    /*
     [NLog set:@"c" val:@"TODO"];
     
     [NLog set:@"av" val:@"TODO"];
     
     [NLog set:@"i" val:@"TODO"];
     */
    
    //    [NLog set:@"test" val: [NSNumber numberWithInt:1]];
    
    //    [NLog set:@"test中文" val: @"中文"];
    
    [NLog send:@"millertype"
        params:[NSDictionary dictionaryWithObjectsAndKeys:
                @"miller-framework-value",@"nlogframework",
                nil]];
    
    [NLog send:@"test protocol"
        params:[NSDictionary dictionaryWithObjectsAndKeys:
                @"originalval",@"originalkey",
                @"中文VAL",@"中文KEY",
                nil]];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
