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

#import "KRShareViewController.h"
#import "KRStatisticObject.h"

// pref keys
#define KRConfigKey                     @"kiireferral-config"
#define KRConfigRefreshedKey            @"kiireferral-config-refreshed"
#define KRConfigCheckedConversionKey    @"kiireferral-config-referral-checked"

// config keys
#define KRConfigConversionURLKey        @"conversionURL"
#define KRConfigDefaultMessageKey       @"defaultMessage"
#define KRConfigGenerateURLKey          @"generateURL"

@class KiiUser, KRStatisticObject;

enum {
    KRSourceFacebook = 1,
    KRSourceTwitter = 2,
    KRSourceDirect = 3,
    KRSourceEmail = 4
};
typedef NSUInteger KRSource;

typedef void (^KRFriendCallback)(NSArray *contacts, NSError *error);
typedef void (^KRStatisticCallback)(KRStatisticObject *stats, NSError *error);
typedef void (^KRLinkCallback)(NSString *urlString, NSError *error);

@interface KiiReferral : NSObject

+ (void) facebookSessionChanged:(FBSession*)session
                          state:(FBSessionState)state
                          error:(NSError*)error;

+ (BOOL) canAccessFacebook;
+ (BOOL) canAccessTwitter;
+ (void) getFacebookFriends:(KRFriendCallback)callback;
+ (void) getTwitterFriends:(KRFriendCallback)callback;
+ (void) setTwitterLoggedIn:(BOOL)loggedIn;

+ (void) getUserTotals:(KiiUser*)user completionBlock:(KRStatisticCallback)complete;

+ (void) generateLink:(KRSource)source
          withSubject:(NSString*)subject
           andMessage:(NSString*)msg
     andConfiguration:(NSString*)configuration
        andCustomInfo:(NSDictionary*)customInfo
      completionBlock:(KRLinkCallback)complete;


+ (void) beginWithAppID:(NSString*)appID andKey:(NSString*)appKey;
+ (void) completeShares;

+ (void) setLogging:(BOOL)loggingOn;
+ (void) forceCheckConversion;
+ (void) forceConfigRefresh;

+ (UIImage*) getBundleImage:(NSString*)name;

@end
