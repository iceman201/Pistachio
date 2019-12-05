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

- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(nonnull UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    CGSize itemSize = [(UICollectionViewFlowLayout *)collectionViewLayout itemSize];
    CGFloat spacing = [(UICollectionViewFlowLayout *)collectionViewLayout minimumLineSpacing];

    NSInteger count = 1;
    CGFloat totalCellWidth = itemSize.width * count;
    CGFloat totalSpacingWidth = spacing * ((count - 1) < 0 ? 0 : count - 1);
    CGFloat leftInset = (collectionView.bounds.size.width - (totalCellWidth + totalSpacingWidth)) / 2;
    if (leftInset < 0)
    {
        UIEdgeInsets inset = [(UICollectionViewFlowLayout *)collectionViewLayout sectionInset];
        return inset;
    }
    CGFloat rightInset = leftInset;
    CGFloat topInsert = DEFAULT_PADDING * (CGFloat)2;
    UIEdgeInsets sectionInset = UIEdgeInsetsMake(topInsert, leftInset, 0, rightInset);
    return sectionInset;
}
//
//- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
//{
//
//}


- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    
}


@end
