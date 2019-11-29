//
//  ViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "ViewController.h"
#include <iostream>
#include <iomanip>
//#include <nlohmann_json/json.hpp>
#include "NewsTopic.hpp"
#include <string>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:@"https://api.nytimes.com/svc/search/v2/articlesearch.json?q=finance&page=10&sort=newest&api-key=DzA9CAMEDhbyT6AYhW0CzdftgT623Fni"]];
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        if (data != nil)
        {
            NSString *jsonString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            const char * _Nullable text = [jsonString UTF8String];
            nlohmann::json data = nlohmann::json::parse(text);
            std::cout << data;
        }
    }];
    [task resume];
}


@end
