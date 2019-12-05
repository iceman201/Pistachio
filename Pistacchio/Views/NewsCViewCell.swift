//
//  NewsCViewCell.swift
//  Pistacchio
//
//  Created by Liguo Jiao on 5/12/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

import UIKit
import PureLayout
import WebKit

class NewsCViewCell: UICollectionViewCell {


    override init(frame: CGRect) {
        super.init(frame: frame)
        loadView()
    }
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func loadView() {
        let container = UIView()
        container.layer.cornerRadius = 5
        container.layer.masksToBounds = true
        container.backgroundColor = .brown
        self.addSubview(container)
        container.autoPinEdgesToSuperviewSafeArea()

        let newsImageView = WKWebView()
        newsImageView.backgroundColor = .purple
        container.addSubview(newsImageView)
        newsImageView.autoPinEdge(toSuperviewEdge: .top)
        newsImageView.autoMatch(.width, to: .width, of: container)
        newsImageView.autoMatch(.height, to: .height, of: container, withMultiplier: 0.7)

        let newsTitle = UILabel()
        newsTitle.backgroundColor = .darkGray
        container.addSubview(newsTitle)
        newsTitle.autoPinEdge(.top, to: .bottom, of: newsImageView)
        newsTitle.autoMatch(.width, to: .width, of: container)
        newsTitle.autoMatch(.height, to: .height, of: container, withMultiplier: 0.2)

        let date = UILabel()
        date.backgroundColor = .link
        container.addSubview(date)
        date.autoPinEdge(.top, to: .bottom, of: newsTitle)
        date.autoMatch(.width, to: .width, of: container)
        date.autoPinEdge(toSuperviewEdge: .bottom)


    }
}
