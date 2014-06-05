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
    NSString *kiiAppID = @"d62edb9b";
    NSString *kiiAppKey = @"dc7914230597eb7d43ebc4b8eccb4283";
    
    NSAssert(![kiiAppID isEqualToString:@""] && ![kiiAppKey isEqualToString:@""],
             @"Enter your Kii App credentials to the sample AppDelegate.m!");
    
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
    
    // use this to turn on logging while we're developing
    [KiiReferral setLogging:TRUE]; // default is FALSE
    
    // use this while testing to force conversion checking.
    // otherwise, the app will only check once (upon installation)
    [KiiReferral forceCheckConversion];
    
    // default authenticate a test user
    [self authenticate]; // this is a synchronous call, so will block the UI thread
    
    return YES;
}
							

// During the Facebook login flow, your app passes control to the Facebook iOS app or Facebook in a mobile browser.
// After authentication, your app will be called back with the session information.
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation
{
    // Note this handler block should be the exact same as the handler passed to any open calls.
    [FBSession.activeSession setStateChangeHandler:
     ^(FBSession *session, FBSessionState state, NSError *error) {
         [KiiReferral facebookSessionChanged:session state:state error:error];
     }];
    return [FBAppCall handleOpenURL:url sourceApplication:sourceApplication];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Handle the user leaving the app while the Facebook login dialog is being shown
    // For example: when the user presses the iOS "home" button while the login dialog is active
    [FBAppCall handleDidBecomeActive];
}

@end
