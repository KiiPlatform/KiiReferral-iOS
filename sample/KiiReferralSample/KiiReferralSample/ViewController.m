//
//  ViewController.m
//  KiiReferralSample
//
//  Created by Chris on 5/25/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#import "ViewController.h"

#import <KiiReferral/KiiReferral.h>
#import <KiiSDK/Kii.h>

@interface ViewController ()

@end

@implementation ViewController

- (IBAction)showShareDialog:(id)sender
{
    NSDictionary *myDataDict = @{@"user_type": @"pro", @"player_score": [NSNumber numberWithInteger:293]};
    
    KRShareViewController *vc = [KRShareViewController shareViewWithConfigurationKey:@"points_earned"];
    //    [vc setCustomInfo:myDataDict];
    [self presentViewController:vc animated:TRUE completion:nil];
}

- (IBAction)refreshStats:(id)sender
{
    // get all the stats for this user
    [KiiReferral getUserTotals:[KiiUser currentUser]
               completionBlock:^(KRStatisticObject *stats, NSError *error) {
                   
                   if(error == nil) {
                       
                       _userIDLabel.text = [KiiUser currentUser].uuid;
                       _statView.text = [stats describe:TRUE];
                       
                       // this prints out the stat object to the log
                       [stats describe];
                       
                   } else {
                       NSLog(@"Error getting user totals: %@", error);
                   }
                                      
               }];
}

- (void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    _userIDLabel.text = [KiiUser currentUser].uuid;
    
    _statView.text = @"Loading Stats...";
    
    [self refreshStats:nil];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
