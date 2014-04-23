# Table of Contents
- [Introduction to KiiReferral](#intro)
- [Can I add this to my app?](#can-i-add)
	- [Kii Labs & Disclaimer](#labs-disclaimer)
- [Setup & Usage](#setup-usage)
	- [Prerequisites](#prereqs)
	- [Portal Configuration](#portal-config)
		- [Activate Kii Referral](#portal-activation)
		- [Add your app's Apple ID](#portal-apple-id)
		- [Set up your default messaging](#portal-default-messaging)
		- [Adding message configurations](#portal-message-config)
		- [Creating campaigns](#portal-create-campaign)
	- [Add the KiiReferral Library](#add-lib)
	- [Write the Code](#write-code)
		- [Initialize the Library](#init-lib)
		- [Show the Share View](#show-share-view)
			- [Simple use](#simple-use)
			- [Custom Configuration Key](#custom-config-key)
			- [Add custom metadata](#add-custom-metadata)
		- [Get the user's referral statistics](#get-ref-stats)

## <a name="intro"/>Introduction to KiiReferral
**KiiReferral** is a tool created by **Kii Labs** that allows you to quickly add social sharing and referral tracking to your app in just a few minutes. The features currently include:

- Generate campaigns and referral links from the developer portal
- Track shares, clicks and conversions in real-time
- Allow users to share links via Facebook, Twitter and email directly from the app
- Track conversions on a user-level via the SDK
	- Trigger events when conversions occur (i.e. give bonus points, extra features, etc)

## <a name="can-i-add"/>Can I add this to my app?
Currently, **KiiReferral** is only available for iOS, and you must have a developer account set up with **Kii** as well as an application set up within your Kii account (for API keys, etc).

If you don't yet have a **Kii** account, don't worry - it's simple and free to get started. To sign up, visit [developer.kii.com](http://developer.kii.com). 

### <a name="labs-disclaimer"/>Kii Labs & Disclaimer
**KiiReferral** is a project developed and maintained by **Kii Labs**, which provides *beta-level* tools for your use with **Kii**'s cloud functionality. We cannot guarantee these tools will be maintained or grow in a backwards-compatible way - so please use at your own risk and take notice of changes from version to version to avoid issues.

## <a name="setup-usage"/>Setup & Usage
Getting started is easy, and as with **Kii**'s cloud SDKs - the methods and classes are simple and powerful so you can implement using only a few lines of code.

### <a name="prereqs"/>Prerequisites
In order to successfully follow the setup, you must have the following:

1. Apple's developer tools [for iOS](http://developer.apple.com/ios)
2. A [Kii Developer Account](http://developer.kii.com)
3. A Kii application provisioned
4. Kii's Cloud SDK [added to your application](http://documentation.kii.com/en/starts/ios/adding-kii-cloud-sdk-to-your-application/)
5. Kii's Analytics SDK [added to your application](http://documentation.kii.com/en/starts/ios/adding-kii-analytics-sdk-to-your-application/)

### <a name="portal-config"/>Portal Configuration
#### <a name="portal-activation"/>Activate Kii Referral
In order to utilize this **Kii Labs** feature, you must first activate it. To do so, follow these steps:

1. Log into [developer.kii.com](http://developer.kii.com)
2. Navigate to the app you wish to add this functionality to
3. Click on the **Labs** tab on the left-hand side
4. Select the **KiiReferral** tab on the top
5. Click the **Activate** button

#### <a name="portal-apple-id"/>Add your app's Apple ID
When the links your users generate are clicked, they are taken to the iTunes Store in order to download your application. In order for this to work, you must add your app's Apple ID (found in iTunes Connect) to the Kii Referral portal.

#### <a name="portal-default-messaging"/>Set up your default messaging
When your users open the share screen, the message that will be sent to their networks is pre-filled with some text - which is configurable via the default messaging pane as shown below:

// todo: add screencap

#### <a name="portal-message-config"/>Adding message configurations
If you wish to add alternate messaging based on the user status or flow of your app, you can set up alternate configuration keys with associated messages as shown below:

// todo: add screencap

To learn how to utilize these within the SDK, check out the [Custom Configuration Key](#custom-config-key) code section.

#### <a name="portal-create-campaign"/>Creating campaigns
As a developer, you may wish to track a campaign on social media to find out the effectiveness of your message. Create campaigns using the form as shown below and receive a shortened link that will track clicks and referrals.

### <a name="add-lib"/>Add The KiiReferral Library
To add the library to your project, simply download the repository associated with this GitHub page and drag the KiiReferralLib folder into your project.

### <a name="write-code"/>Write the code

#### <a name="init-lib"/>Initialize the library
This can be placed directly after your Kii and KiiAnalytics initialization code in your project's AppDelegate.m file as shown:
   						
	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
	{    
		NSString *appID = @"MY_KII_APP_ID";
		NSString *appKey = @"MY_KII_APP_KEY";
	    
    	// start up kii
    	[Kii beginWithID:appID andKey:appKey];
    	
    	// start up kii analytics
    	[KiiAnalytics beginWithID:appID andKey:appKey];
    	
    	// start up kii referral
    	[KiiReferral beginWithID:appID andKey:appKey];
    	
    	// finish your initialization code
    	...
    	
    	return YES;
    }

#### <a name="show-share-view"/>Show the share view
This is the view that allows your users to post messages from within your app. Simply present the **Kii Referral** view controller and the library will take care of the rest:

> **Note:** There must be a currently authenticated Kii User, otherwise the user will receive errors when they try to share! It's best to check this before presenting the view.

##### <a name="simple-use"/>Simple use
If you wish to show your default message/configuration, you can simply use the following code:

    KRShareViewController *vc = [KRShareViewController shareView];
    [self presentViewController:vc animated:TRUE completion:nil];

##### <a name="custom-config-key"/>Custom configuration key
If you wish to use a custom configuration key, simply specify that key using the following setup:

    KRShareViewController *vc = [KRShareViewController shareViewWithConfigurationKey:@"my-configuration-key"];
    [self presentViewController:vc animated:TRUE completion:nil];

##### <a name="add-custom-metadata"/>Add custom metadata
If you wish to track other metrics about the share that is taking place, you can set an NSDictionary filled with parameters to associate with the share. Some examples of this might be: user level, location, device type, player type, points scored, etc. Those metrics can then be utilized (if you choose) later on in Kii's Analytics dashboard.

To add custom metadata, use the following technique:

    NSDictionary *myDataDict = @{@"user_type": @"pro", @"player_score": [NSNumber numberWithInteger:293]};

    KRShareViewController *vc = [KRShareViewController shareViewWithConfigurationKey:@"my-configuration-key"];
    [vc setCustomInfo:myDataDict];
    [self presentViewController:vc animated:TRUE completion:nil];

#### <a name="get-ref-stats"/>Get the user's referral statistics
You might choose to offer the user points or rewards based on how much they are sharing your app (and how many people actually convert!). You can use a simple SDK method to retrieve all of these results:

    [KiiReferral getUserTotals:[KiiUser currentUser]
               completionBlock:^(KRStatisticObject *stats, NSError *error) {
               	if(error == nil) {
               		[stats describe];
               	} else {
               		NSLog(@"Error getting user totals: %@", error);
               	}
               }];

Open up the KRStatisticObject.h file (or command-click on the KRStatistic object declaration in the completion block) to view a list of properties accessible within this object.