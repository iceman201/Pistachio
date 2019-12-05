//
//  NewsCollectionViewDelegate.m
//  Pistacchio
//
//  Created by Liguo Jiao on 4/12/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "NewsCollectionViewDelegate.h"
#import "SharedConstants.h"

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
    return 1;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:NEWS_COLLECTION_CELL_ID forIndexPath:indexPath];
    cell.backgroundColor = [UIColor redColor];
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
