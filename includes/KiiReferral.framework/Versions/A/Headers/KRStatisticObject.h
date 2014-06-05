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

@interface KRStatisticObject : NSObject

// totals
@property (nonatomic, assign) NSUInteger shareCount;
@property (nonatomic, assign) NSUInteger conversionCount;
@property (nonatomic, assign) NSUInteger clickCount;

// network-based
@property (nonatomic, assign) NSUInteger facebookShares;
@property (nonatomic, assign) NSUInteger facebookClicks;
@property (nonatomic, assign) NSUInteger facebookConversions;

@property (nonatomic, assign) NSUInteger twitterShares;
@property (nonatomic, assign) NSUInteger twitterClicks;
@property (nonatomic, assign) NSUInteger twitterConversions;

- (void) describe;
- (NSString*) describe:(BOOL)returnString;

@end
