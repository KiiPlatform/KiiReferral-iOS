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

/**
 A native object that holds various statistics related to KiiReferral
 */
@interface KRStatisticObject : NSObject

///---------------------------------------------------------------------------------------
/// @name Totals
///---------------------------------------------------------------------------------------

/** Total number of shares */
@property (nonatomic, assign) NSUInteger shareCount;

/** Total number of conversions */
@property (nonatomic, assign) NSUInteger conversionCount;

/** Total number of clicks */
@property (nonatomic, assign) NSUInteger clickCount;


///---------------------------------------------------------------------------------------
/// @name Network-based figures
///---------------------------------------------------------------------------------------

/** Total number of shares via facebook */
@property (nonatomic, assign) NSUInteger facebookShares;

/** Total number of clicks via facebook */
@property (nonatomic, assign) NSUInteger facebookClicks;

/** Total number of conversions via facebook */
@property (nonatomic, assign) NSUInteger facebookConversions;

/** Total number of shares via twitter */
@property (nonatomic, assign) NSUInteger twitterShares;

/** Total number of clicks via twitter */
@property (nonatomic, assign) NSUInteger twitterClicks;

/** Total number of conversions via twitter */
@property (nonatomic, assign) NSUInteger twitterConversions;

/** Total number of shares via email */
@property (nonatomic, assign) NSUInteger emailShares;

/** Total number of clicks via email */
@property (nonatomic, assign) NSUInteger emailClicks;

/** Total number of conversions via email */
@property (nonatomic, assign) NSUInteger emailConversions;

/** Total number of shares via sms */
@property (nonatomic, assign) NSUInteger smsShares;

/** Total number of clicks via sms */
@property (nonatomic, assign) NSUInteger smsClicks;

/** Total number of conversions via sms */
@property (nonatomic, assign) NSUInteger smsConversions;

/** Prints a descriptive, readable string containing the statistics within this Statistic Object
 */
- (void) describe;

/** Generates or prints a descriptive, readable string containing the statistics within this Statistic Object
 
 @param returnString TRUE if a descriptive string should be returned, FALSE if the string should be printed to log
 @return A descriptive string of the statistic object, if returnString is TRUE
 */
- (NSString*) describe:(BOOL)returnString;

@end
