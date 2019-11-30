//
//  ViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "ViewController.h"
#import "NewsHelper.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    NewsHelper *news = [[NewsHelper alloc] init:@"https://api.nytimes.com/svc/search/v2/articlesearch.json?q=finance&page=10&sort=newest&api-key=DzA9CAMEDhbyT6AYhW0CzdftgT623Fni"];
    
}


@end
