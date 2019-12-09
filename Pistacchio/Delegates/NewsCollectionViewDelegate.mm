//
//  NewsCollectionViewDelegate.m
//  Pistacchio
//
//  Created by Liguo Jiao on 4/12/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "NewsCollectionViewDelegate.h"
#import "SharedConstants.h"
#import "Pistacchio-Swift.h"

@interface NewsCollectionViewDelegate()
@property (nonatomic, weak) UICollectionView *view;
@end


@implementation NewsCollectionViewDelegate
{
    std::shared_ptr<std::vector<news_by_topic::Doc>> _news;
}

- (instancetype)initWithTargetView:(UICollectionView *)view data:(std::shared_ptr<std::vector<news_by_topic::Doc>>)news
{
    self = [super init];
    if (self)
    {
        view.delegate = self;
        view.dataSource = self;
        self.view = view;
        _news = news;
    }
    return self;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    if (_news == nullptr) {
        return 0;
    }
    auto t = *_news;
    //std::size(_news);//std::count(_news.get()->begin(), _news.get()->end(), 0);
    NSNumber *total = [NSNumber numberWithUnsignedLong:t.size()];
    return [total integerValue];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    NewsCViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:NEWS_COLLECTION_CELL_ID forIndexPath:indexPath];
    auto news = *_news;
    auto date = news[indexPath.row].get_pub_date();
    auto title = news[indexPath.row].get_headline()->get_main();
    auto subTitle = news[indexPath.row].get_abstract();
    auto artical = news[indexPath.row].get_web_url();
    auto preview = *news[indexPath.row].get_multimedia();

    if (preview.size() > 0) {
        auto previewUrl = preview[0].get_url();
    }

    NSURL *articalUrl = [NSURL URLWithString:[NSString stringWithCString:artical->c_str() encoding:NSUTF8StringEncoding]];
    cell.newsRedirectUrl = articalUrl;
    cell.newsDate = [NSString stringWithCString:date->c_str() encoding:NSUTF8StringEncoding];
    cell.newsTitle = [NSString stringWithCString:title->c_str() encoding:NSUTF8StringEncoding];
    cell.newsSubtitle = [NSString stringWithCString:title->c_str() encoding:NSUTF8StringEncoding]; //For now, just testing
    [cell loadData];

//    cell.newsImageUrl
//    auto subHeader = news[indexPath.row].


    
    return cell;
}

- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    return UIEdgeInsetsMake(DEFAULT_PADDING*2, 0, DEFAULT_PADDING*5, 0);
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    CGFloat width = collectionView.safeAreaLayoutGuide.layoutFrame.size.width - DEFAULT_PADDING * 6;
    CGFloat height = collectionView.frame.size.width/1.5;

    CGSize defaultSize = CGSizeMake(width, height);
    return defaultSize;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
