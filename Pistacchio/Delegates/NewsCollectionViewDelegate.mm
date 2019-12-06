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
//@property (nonatomic, weak) id<UICollectionViewDelegate> collectionViewDelegate;
@end


@implementation NewsCollectionViewDelegate

- (instancetype)initWithTargetView:(UICollectionView *)view
{
    self = [super init];
    if (self) {
        view.delegate = self;
        view.dataSource = self;
    }
    return self;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return 20;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    NewsCViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:NEWS_COLLECTION_CELL_ID forIndexPath:indexPath];
    return cell;
}

- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    return UIEdgeInsetsMake(DEFAULT_PADDING*2, 0, DEFAULT_PADDING*5, 0);
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    CGFloat width = collectionView.safeAreaLayoutGuide.layoutFrame.size.width - DEFAULT_PADDING * 6;
    CGFloat height = collectionView.frame.size.width/2;

    CGSize defaultSize = CGSizeMake(width, height);
    return defaultSize;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
