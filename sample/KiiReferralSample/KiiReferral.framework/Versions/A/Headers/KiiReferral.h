//
//
// Copyright 2014 Kii Corporation
// http://kii.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//

#import <Foundation/Foundation.h>
#import <FacebookSDK/FacebookSDK.h>
#import <KiiAnalytics/KiiAnalytics.h>
#import <KiiSDK/Kii.h>

#import "KRShareViewController.h"
#import "KRStatisticObject.h"

/** The callback used when statistics are pulled from the server.
 
 If error == nil, the request was successful. The statistics will be returned in the form of a KRStatisticObject
 */
typedef void (^KRStatisticCallback)(KRStatisticObject *stats, NSError *error);

/**
 The main class that helps drive KiiReferral
 */
@interface KiiReferral : NSObject

///---------------------------------------------------------------------------------------
/// @name Required
///---------------------------------------------------------------------------------------

/** Initialize the KiiReferral SDK
 
 Should be called in your AppDelegate's application:didFinishLaunchingWithOptions: method after Kii and KiiAnalytic libraries are initialized.
 
 @param appID Your Kii Application ID
 @param appKey Your Kii Application Key
 */
+ (void) beginWithAppID:(NSString*)appID
                 andKey:(NSString*)appKey;


/** Handler for Facebook SDK
 
 This method should be implemented in your AppDelegate as follows:

    - (BOOL)application:(UIApplication *)application
                openURL:(NSURL *)url
      sourceApplication:(NSString *)sourceApplication
             annotation:(id)annotation
    {
        [FBSession.activeSession setStateChangeHandler:^(FBSession *session, FBSessionState state, NSError *error) {
            [KiiReferral facebookSessionChanged:session state:state error:error];
        }];
 
        return [FBAppCall handleOpenURL:url sourceApplication:sourceApplication];
    }

 @param session The Facebook session passed in by the setStateChangeHandler block
 @param state The Facebook session state passed in by the setStateChangeHandler block
 @param error The error passed in by the setStateChangeHandler block
 */
+ (void) facebookSessionChanged:(FBSession*)session
                          state:(FBSessionState)state
                          error:(NSError*)error;

///---------------------------------------------------------------------------------------
/// @name Required
///---------------------------------------------------------------------------------------

/** Retrieves the statistics for a given user
 
 This is an asynchronous method that makes a server request. It will pull statistics like # of shares, clicks, and conversions. This can be useful for reward systems and user tracking
 
 @param user The user to retrieve statistics for
 @param complete A block to be called when the request is completed
 */
+ (void) getUserTotals:(KiiUser*)user
       completionBlock:(KRStatisticCallback)complete;


///---------------------------------------------------------------------------------------
/// @name Debug/Testing Methods
///---------------------------------------------------------------------------------------

/** Turn on/off debug logging
 
 Should only be used in development mode

 @param loggingOn TRUE if logging should be turned on, FALSE otherwise
*/
+ (void) setLogging:(BOOL)loggingOn;

/** Check for a potential conversion
 
 Usually, the SDK only checks for conversions on the first application launch. In development/testing mode, it may be beneficial to check for this on each launch to expedite testing. This method will override the default and check for a conversion on demand.  This should not be called in production.
 */
+ (void) forceCheckConversion;

/** Load and store the latest referral configuration
 
 Usually, the SDK only retrieves the configuration from the portal periodically. This method will override the default and get the latest configuration on demand. This is helpful for development mode when you are making changes in the dev portal and want to see the changes reflected on the client more quickly. This should not be called in production.
 */
+ (void) forceConfigRefresh;

@end
