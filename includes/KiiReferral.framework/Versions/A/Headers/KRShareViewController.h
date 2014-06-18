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

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

/**
 The user interface and controller that drives the share view
 */
@interface KRShareViewController : UIViewController
<MFMailComposeViewControllerDelegate>

/** Any custom data to be tracked along with the share and referrals */
@property (nonatomic, strong) NSDictionary *customInfo;

/** Generates a new KRShareViewController
 
 This method must be used to initialize a share view before it is shown to a user. Once initialized, the view can be presented to the user.
 
 @return A new KRShareViewController object
 */
+ (KRShareViewController*) shareView;

/** Generates a new KRShareViewController with a custom configuration key
 
 This method must be used to initialize a share view before it is shown to a user. Once initialized, the view can be presented to the user.

 @param configurationKey A file-specific URI
 @return A new KRShareViewController object
 */
+ (KRShareViewController*) shareViewWithConfigurationKey:(NSString*)configurationKey;

@end
