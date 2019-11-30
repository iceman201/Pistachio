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
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Services" ofType:@"plist"];
    NSDictionary *service = [NSDictionary dictionaryWithContentsOfFile:path];
    NSString *api = [service valueForKey:@"ArticleSearch"];
    NSString *topic = @"finance&page";
    NSString *token = @"DzA9CAMEDhbyT6AYhW0CzdftgT623Fni";
    NSString *apiUrl = [NSString stringWithFormat:@"%@?q=%@page=10&sort=newest&api-key=%@", api, topic, token];
    NewsHelper *news = [[NewsHelper alloc] init:apiUrl];
    [news getArticles];
    [self.view setBackgroundColor:[UIColor redColor]];
    
}
//https://api.nytimes.com/svc/search/v2/articlesearch.json?q=finance&page=10&sort=newest&api-key=DzA9CAMEDhbyT6AYhW0CzdftgT623Fni"

@end
