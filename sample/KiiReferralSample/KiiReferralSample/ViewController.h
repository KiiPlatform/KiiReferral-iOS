//
//  ViewController.h
//  KiiReferralSample
//
//  Created by Chris on 5/25/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (nonatomic, strong) IBOutlet UILabel *userIDLabel;
@property (nonatomic, strong) IBOutlet UITextView *statView;

- (IBAction)showShareDialog:(id)sender;
- (IBAction)refreshStats:(id)sender;

@end
