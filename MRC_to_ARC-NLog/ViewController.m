//
//  ViewController.m
//  MRC_to_ARC-NLog
//
//  Created by Wang,Guoxiang on 16/8/24.
//  Copyright © 2016年 Wang,Guoxiang. All rights reserved.
//

#import "ViewController.h"
#import "NLog.h"

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UIView *indicatorView;

@end

@implementation ViewController
- (IBAction)clickButton:(UIButton *)sender {
    if (self.indicatorView.backgroundColor==[UIColor blackColor]) {
        self.indicatorView.backgroundColor=[UIColor redColor];
    }else{
        self.indicatorView.backgroundColor=[UIColor blackColor];
    }
    
    [NLog send:@"2"
        params:[NSDictionary dictionaryWithObjectsAndKeys:
                @"ui", @"category",
                @"click", @"click",
                @"button2", @"label"
                , nil]
   immediately:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
