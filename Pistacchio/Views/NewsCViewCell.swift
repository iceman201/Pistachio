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

@objcMembers
class NewsCViewCell: UICollectionViewCell {

    var newsTitle: String?
    var newsSubtitle: String?
    var newsDate: String?//Date?
    var newsRedirectUrl: URL?
    var newsImageUrl: URL?

    private var newsImageView: WKWebView?
    private var newsTitleLabel: UILabel?
    private var newsSubtitleLabel: UILabel?
    private var newsDateLabel: UILabel?

    override init(frame: CGRect) {
        super.init(frame: frame)
        loadView()
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func loadData() {
        if let imageUrl = newsImageUrl {
            self.newsImageView?.load(URLRequest(url: imageUrl))
        }
        self.newsTitleLabel?.text = self.newsTitle ?? ""
        self.newsSubtitleLabel?.text = self.newsSubtitle ?? ""
        self.newsDateLabel?.text = self.newsDate ?? ""

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
        self.newsImageView = newsImageView

        let newsTitle = UILabel()
        newsTitle.backgroundColor = .lightGray
        newsTitle.adjustsFontSizeToFitWidth = true
        newsImageView.addSubview(newsTitle)
        newsTitle.autoMatch(.width, to: .width, of: newsImageView)
        newsTitle.autoMatch(.height, to: .height, of: newsImageView, withMultiplier: 0.4)
        newsTitle.autoPinEdge(toSuperviewEdge: .bottom)
        self.newsTitleLabel = newsTitle;

        let newsSubtitle = UILabel()
        newsSubtitle.backgroundColor = .darkGray
        container.addSubview(newsSubtitle)
        newsSubtitle.autoPinEdge(.top, to: .bottom, of: newsImageView)
        newsSubtitle.autoMatch(.width, to: .width, of: container)
        newsSubtitle.autoMatch(.height, to: .height, of: container, withMultiplier: 0.2)
        self.newsSubtitleLabel = newsSubtitle

        let date = UILabel()
        date.backgroundColor = .link
        container.addSubview(date)
        date.autoPinEdge(.top, to: .bottom, of: newsSubtitle)
        date.autoMatch(.width, to: .width, of: container)
        date.autoPinEdge(toSuperviewEdge: .bottom)
        self.newsDateLabel = date;

    }
}
