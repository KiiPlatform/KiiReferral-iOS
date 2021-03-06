//
//  AppDelegate.m
//  KiiReferralSample
//
//  Created by Chris on 5/25/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#import "AppDelegate.h"

#import <KiiReferral/KiiReferral.h>
#import <KiiSDK/Kii.h>

@implementation AppDelegate

- (void) authenticate
{
    NSString *username = @"kiireferraltest1";
    NSString *password = @"password";
    
    NSError *err;
    
    // try to authenticate
    [KiiUser authenticateSynchronous:username withPassword:password andError:&err];
    
    // if we couldn't authenticate, the user may not exist
    if(err != nil) {
        err = nil; // reset the tracking error
        
        // try to register the user
        KiiUser *user = [KiiUser userWithUsername:username andPassword:password];
        [user performRegistrationSynchronous:&err];
    }
    
    NSLog(@"Authenticated with error: %@ => %@", err, [KiiUser currentUser].uuid);
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSString *kiiAppID = @"";
    NSString *kiiAppKey = @"";
    
//    NSAssert(![kiiAppID isEqualToString:@""] && ![kiiAppKey isEqualToString:@""],
//             @"Enter your Kii App credentials to the sample AppDelegate.m!");
    
    // ensure we have a fb id
    NSString *fbAppID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"FacebookAppID"];
    NSArray *urlTypes = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleURLTypes"];
    
    NSString *fbURL = [[[urlTypes lastObject] objectForKey:@"CFBundleURLSchemes"] lastObject];

    NSAssert(![fbAppID isEqualToString:@"YOUR_FACEBOOK_APP_ID"] && ![fbURL isEqualToString:@"YOUR_FACEBOOK_URL_SCHEME"],
             @"Enter your Facebook App ID and URL scheme to KiiReferralSample-Info.plist");
    
    // Override point for customization after application launch.
    // Initialize the Kii SDK!
    [Kii beginWithID:kiiAppID
              andKey:kiiAppKey];
    
    [KiiAnalytics beginWithID:kiiAppID
                       andKey:kiiAppKey
                      andSite:kiiAnalyticsSiteUS];
    
    // start up kii referral
    [KiiReferral beginWithAppID:kiiAppID
                         andKey:kiiAppKey];
    
    // forces the configuration to be pulled from the server.
    // by default, configuration is only pulled periodically.
    // this method should be for testing only and should be
    // removed before going into production.
    [KiiReferral forceConfigRefresh];
    
    // use this to turn on logging while we're developing
    [KiiReferral setLogging:TRUE]; // default is FALSE
    
    // use this while testing to force conversion checking.
    // otherwise, the app will only check once (upon installation)
    [KiiReferral forceCheckConversion];
    
    // default authenticate a test user
    [self authenticate]; // this is a synchronous call, so will block the UI thread
    
    return YES;
}

@end
