//
//  NewsHelper.m
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "NewsHelper.h"
#include "NewsTopic.hpp"
#import "macros.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>

@interface NewsHelper()
{
    std::shared_ptr<std::vector<news_by_topic::Doc>> docs;
}
@property (nonatomic, weak) id<NetworkServices> delegate;
//static NewsHelper *newsServices;
@end

@implementation NewsHelper

- (void)setDelegate:(id)delegate
{
    _delegate = delegate;
}

- (void)serviceStart
{
    [self fetchAllNewsData:^(BOOL success) {
        if (success)
        {
            NSLog(@"haha");
        }
    }];
}

- (void)fetchAllNewsData:(void(^) (BOOL success))finished
{
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:[self getServerAddress]]];
    NSURLSession *session = [NSURLSession sharedSession];
    WEAK_SELF;
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        STRONG_SELF_OR_RETURN;
        NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
        switch ([httpResponse statusCode]) {
            case 200:
                if (data != nil)
                {
                    NSString *jsonString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
                    const char * _Nullable text = [jsonString UTF8String];
                    news_by_topic::json data = news_by_topic::json::parse(text);
                    auto news = data.get<news_by_topic::Welcome>();
                    self->docs = news.get_response()->get_docs();
                    finished(YES);
                }
                else
                {
                    finished(NO);
                }
                break;
            default:
                finished(NO);
                break;
        };
    }];
    [task resume];
}

- (std::shared_ptr<std::vector<news_by_topic::Doc>>)getArticles
{
    return self->docs;
}

- (NSString *)getServerAddress
{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Services" ofType:@"plist"];
    NSDictionary *service = [NSDictionary dictionaryWithContentsOfFile:path];
    NSString *api = [service valueForKey:@"ArticleSearch"];
    NSString *topic = @"finance&page";
    NSString *token = @"DzA9CAMEDhbyT6AYhW0CzdftgT623Fni";
    NSString *apiUrl = [NSString stringWithFormat:@"%@?q=%@page=10&sort=newest&api-key=%@", api, topic, token];
    return apiUrl;
}

@end
