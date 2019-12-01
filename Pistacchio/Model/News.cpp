//
//  News.cpp
//  Pistacchio
//
//  Created by Liguo Jiao on 1/12/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#include "News.hpp"
#include <stdio.h>

namespace nlohmann {
    void from_json(const json & j, news_by_topic::Person& x) {
        x.set_firstname(news_by_topic::get_optional<std::string>(j, "firstname"));
        x.set_middlename(news_by_topic::get_optional<std::string>(j, "middlename"));
        x.set_lastname(news_by_topic::get_optional<std::string>(j, "lastname"));
        x.set_qualifier(news_by_topic::get_untyped(j, "qualifier"));
        x.set_title(news_by_topic::get_untyped(j, "title"));
        x.set_role(news_by_topic::get_optional<std::string>(j, "role"));
        x.set_organization(news_by_topic::get_optional<std::string>(j, "organization"));
        x.set_rank(news_by_topic::get_optional<int64_t>(j, "rank"));
    }

    void to_json(json & j, const news_by_topic::Person & x) {
        j = json::object();
        j["firstname"] = x.get_firstname();
        j["middlename"] = x.get_middlename();
        j["lastname"] = x.get_lastname();
        j["qualifier"] = x.get_qualifier();
        j["title"] = x.get_title();
        j["role"] = x.get_role();
        j["organization"] = x.get_organization();
        j["rank"] = x.get_rank();
    }

    void from_json(const json & j, news_by_topic::Byline& x) {
        x.set_original(news_by_topic::get_optional<std::string>(j, "original"));
        x.set_person(news_by_topic::get_optional<std::vector<news_by_topic::Person>>(j, "person"));
        x.set_organization(news_by_topic::get_optional<news_by_topic::Source>(j, "organization"));
    }

    void to_json(json & j, const news_by_topic::Byline & x) {
        j = json::object();
        j["original"] = x.get_original();
        j["person"] = x.get_person();
        j["organization"] = x.get_organization();
    }

    void from_json(const json & j, news_by_topic::Headline& x) {
        x.set_main(news_by_topic::get_optional<std::string>(j, "main"));
        x.set_kicker(news_by_topic::get_optional<std::string>(j, "kicker"));
        x.set_content_kicker(news_by_topic::get_untyped(j, "content_kicker"));
        x.set_print_headline(news_by_topic::get_optional<std::string>(j, "print_headline"));
        x.set_name(news_by_topic::get_untyped(j, "name"));
        x.set_seo(news_by_topic::get_untyped(j, "seo"));
        x.set_sub(news_by_topic::get_untyped(j, "sub"));
    }

    void to_json(json & j, const news_by_topic::Headline & x) {
        j = json::object();
        j["main"] = x.get_main();
        j["kicker"] = x.get_kicker();
        j["content_kicker"] = x.get_content_kicker();
        j["print_headline"] = x.get_print_headline();
        j["name"] = x.get_name();
        j["seo"] = x.get_seo();
        j["sub"] = x.get_sub();
    }

    void from_json(const json & j, news_by_topic::Keyword& x) {
        x.set_name(news_by_topic::get_optional<news_by_topic::Name>(j, "name"));
        x.set_value(news_by_topic::get_optional<std::string>(j, "value"));
        x.set_rank(news_by_topic::get_optional<int64_t>(j, "rank"));
        x.set_major(news_by_topic::get_optional<news_by_topic::Major>(j, "major"));
    }

    void to_json(json & j, const news_by_topic::Keyword & x) {
        j = json::object();
        j["name"] = x.get_name();
        j["value"] = x.get_value();
        j["rank"] = x.get_rank();
        j["major"] = x.get_major();
    }

    void from_json(const json & j, news_by_topic::Legacy& x) {
        x.set_xlarge(news_by_topic::get_optional<std::string>(j, "xlarge"));
        x.set_xlargewidth(news_by_topic::get_optional<int64_t>(j, "xlargewidth"));
        x.set_xlargeheight(news_by_topic::get_optional<int64_t>(j, "xlargeheight"));
        x.set_thumbnail(news_by_topic::get_optional<std::string>(j, "thumbnail"));
        x.set_thumbnailwidth(news_by_topic::get_optional<int64_t>(j, "thumbnailwidth"));
        x.set_thumbnailheight(news_by_topic::get_optional<int64_t>(j, "thumbnailheight"));
        x.set_widewidth(news_by_topic::get_optional<int64_t>(j, "widewidth"));
        x.set_wideheight(news_by_topic::get_optional<int64_t>(j, "wideheight"));
        x.set_wide(news_by_topic::get_optional<std::string>(j, "wide"));
    }

    void to_json(json & j, const news_by_topic::Legacy & x) {
        j = json::object();
        j["xlarge"] = x.get_xlarge();
        j["xlargewidth"] = x.get_xlargewidth();
        j["xlargeheight"] = x.get_xlargeheight();
        j["thumbnail"] = x.get_thumbnail();
        j["thumbnailwidth"] = x.get_thumbnailwidth();
        j["thumbnailheight"] = x.get_thumbnailheight();
        j["widewidth"] = x.get_widewidth();
        j["wideheight"] = x.get_wideheight();
        j["wide"] = x.get_wide();
    }

    void from_json(const json & j, news_by_topic::Multimedia& x) {
        x.set_rank(news_by_topic::get_optional<int64_t>(j, "rank"));
        x.set_subtype(news_by_topic::get_optional<std::string>(j, "subtype"));
        x.set_caption(news_by_topic::get_untyped(j, "caption"));
        x.set_credit(news_by_topic::get_untyped(j, "credit"));
        x.set_type(news_by_topic::get_optional<news_by_topic::Type>(j, "type"));
        x.set_url(news_by_topic::get_optional<std::string>(j, "url"));
        x.set_height(news_by_topic::get_optional<int64_t>(j, "height"));
        x.set_width(news_by_topic::get_optional<int64_t>(j, "width"));
        x.set_legacy(news_by_topic::get_optional<news_by_topic::Legacy>(j, "legacy"));
        x.set_sub_type(news_by_topic::get_optional<std::string>(j, "subType"));
        x.set_crop_name(news_by_topic::get_optional<std::string>(j, "crop_name"));
    }

    void to_json(json & j, const news_by_topic::Multimedia & x) {
        j = json::object();
        j["rank"] = x.get_rank();
        j["subtype"] = x.get_subtype();
        j["caption"] = x.get_caption();
        j["credit"] = x.get_credit();
        j["type"] = x.get_type();
        j["url"] = x.get_url();
        j["height"] = x.get_height();
        j["width"] = x.get_width();
        j["legacy"] = x.get_legacy();
        j["subType"] = x.get_sub_type();
        j["crop_name"] = x.get_crop_name();
    }

    void from_json(const json & j, news_by_topic::Doc& x) {
        x.set_abstract(news_by_topic::get_optional<std::string>(j, "abstract"));
        x.set_web_url(news_by_topic::get_optional<std::string>(j, "web_url"));
        x.set_snippet(news_by_topic::get_optional<std::string>(j, "snippet"));
        x.set_lead_paragraph(news_by_topic::get_optional<std::string>(j, "lead_paragraph"));
        x.set_source(news_by_topic::get_optional<news_by_topic::Source>(j, "source"));
        x.set_multimedia(news_by_topic::get_optional<std::vector<news_by_topic::Multimedia>>(j, "multimedia"));
        x.set_headline(news_by_topic::get_optional<news_by_topic::Headline>(j, "headline"));
        x.set_keywords(news_by_topic::get_optional<std::vector<news_by_topic::Keyword>>(j, "keywords"));
        x.set_pub_date(news_by_topic::get_optional<std::string>(j, "pub_date"));
        x.set_document_type(news_by_topic::get_optional<news_by_topic::DocumentType>(j, "document_type"));
        x.set_news_desk(news_by_topic::get_optional<std::string>(j, "news_desk"));
        x.set_section_name(news_by_topic::get_optional<std::string>(j, "section_name"));
        x.set_byline(news_by_topic::get_optional<news_by_topic::Byline>(j, "byline"));
        x.set_type_of_material(news_by_topic::get_optional<news_by_topic::TypeOfMaterial>(j, "type_of_material"));
        x.set_id(news_by_topic::get_optional<std::string>(j, "_id"));
        x.set_word_count(news_by_topic::get_optional<int64_t>(j, "word_count"));
        x.set_uri(news_by_topic::get_optional<std::string>(j, "uri"));
        x.set_subsection_name(news_by_topic::get_optional<std::string>(j, "subsection_name"));
        x.set_print_section(news_by_topic::get_optional<std::string>(j, "print_section"));
        x.set_print_page(news_by_topic::get_optional<std::string>(j, "print_page"));
    }

    void to_json(json & j, const news_by_topic::Doc & x) {
        j = json::object();
        j["abstract"] = x.get_abstract();
        j["web_url"] = x.get_web_url();
        j["snippet"] = x.get_snippet();
        j["lead_paragraph"] = x.get_lead_paragraph();
        j["source"] = x.get_source();
        j["multimedia"] = x.get_multimedia();
        j["headline"] = x.get_headline();
        j["keywords"] = x.get_keywords();
        j["pub_date"] = x.get_pub_date();
        j["document_type"] = x.get_document_type();
        j["news_desk"] = x.get_news_desk();
        j["section_name"] = x.get_section_name();
        j["byline"] = x.get_byline();
        j["type_of_material"] = x.get_type_of_material();
        j["_id"] = x.get_id();
        j["word_count"] = x.get_word_count();
        j["uri"] = x.get_uri();
        j["subsection_name"] = x.get_subsection_name();
        j["print_section"] = x.get_print_section();
        j["print_page"] = x.get_print_page();
    }

    void from_json(const json & j, news_by_topic::Meta& x) {
        x.set_hits(news_by_topic::get_optional<int64_t>(j, "hits"));
        x.set_offset(news_by_topic::get_optional<int64_t>(j, "offset"));
        x.set_time(news_by_topic::get_optional<int64_t>(j, "time"));
    }

    void to_json(json & j, const news_by_topic::Meta & x) {
        j = json::object();
        j["hits"] = x.get_hits();
        j["offset"] = x.get_offset();
        j["time"] = x.get_time();
    }

    void from_json(const json & j, news_by_topic::Response& x) {
        x.set_docs(news_by_topic::get_optional<std::vector<news_by_topic::Doc>>(j, "docs"));
        x.set_meta(news_by_topic::get_optional<news_by_topic::Meta>(j, "meta"));
    }

    void to_json(json & j, const news_by_topic::Response & x) {
        j = json::object();
        j["docs"] = x.get_docs();
        j["meta"] = x.get_meta();
    }

    void from_json(const json & j, news_by_topic::Welcome& x) {
        x.set_status(news_by_topic::get_optional<std::string>(j, "status"));
        x.set_copyright(news_by_topic::get_optional<std::string>(j, "copyright"));
        x.set_response(news_by_topic::get_optional<news_by_topic::Response>(j, "response"));
    }

    void to_json(json & j, const news_by_topic::Welcome & x) {
        j = json::object();
        j["status"] = x.get_status();
        j["copyright"] = x.get_copyright();
        j["response"] = x.get_response();
    }

    void from_json(const json & j, news_by_topic::Source & x) {
        if (j == "Reuters") x = news_by_topic::Source::REUTERS;
        else if (j == "The New York Times") x = news_by_topic::Source::THE_NEW_YORK_TIMES;
        else if (j == "The Associated Press" || j == "AP") x = news_by_topic::Source::AP;
        else if (j == "International Herald Tribune" || j == "IHT") x = news_by_topic::Source::IHT;
        else {
            std::cout << "New Source\n" << j << "\n";
            x = news_by_topic::Source::OTHER;
//            throw "Input JSON does not conform to schema";
        };
    }

    void to_json(json & j, const news_by_topic::Source & x) {
        switch (x) {
            case news_by_topic::Source::REUTERS: j = "Reuters"; break;
            case news_by_topic::Source::THE_NEW_YORK_TIMES: j = "The New York Times"; break;
            default: throw "This should not happen";
        }
    }

    void from_json(const json & j, news_by_topic::DocumentType & x) {
        if (j == "article") x = news_by_topic::DocumentType::ARTICLE;
        else throw "Input JSON does not conform to schema";
    }

    void to_json(json & j, const news_by_topic::DocumentType & x) {
        switch (x) {
            case news_by_topic::DocumentType::ARTICLE: j = "article"; break;
            default: throw "This should not happen";
        }
    }

    void from_json(const json & j, news_by_topic::Major & x) {
        if (j == "N") x = news_by_topic::Major::N;
        else throw "Input JSON does not conform to schema";
    }

    void to_json(json & j, const news_by_topic::Major & x) {
        switch (x) {
            case news_by_topic::Major::N: j = "N"; break;
            default: throw "This should not happen";
        }
    }

    void from_json(const json & j, news_by_topic::Name & x) {
        if (j == "glocations") x = news_by_topic::Name::GLOCATIONS;
        else if (j == "organizations") x = news_by_topic::Name::ORGANIZATIONS;
        else if (j == "persons") x = news_by_topic::Name::PERSONS;
        else if (j == "subject") x = news_by_topic::Name::SUBJECT;
        else throw "Input JSON does not conform to schema";
    }

    void to_json(json & j, const news_by_topic::Name & x) {
        switch (x) {
            case news_by_topic::Name::GLOCATIONS: j = "glocations"; break;
            case news_by_topic::Name::ORGANIZATIONS: j = "organizations"; break;
            case news_by_topic::Name::PERSONS: j = "persons"; break;
            case news_by_topic::Name::SUBJECT: j = "subject"; break;
            default: throw "This should not happen";
        }
    }

    void from_json(const json & j, news_by_topic::Type & x) {
        if (j == "image") x = news_by_topic::Type::IMAGE;
        else throw "Input JSON does not conform to schema";
    }

    void to_json(json & j, const news_by_topic::Type & x) {
        switch (x) {
            case news_by_topic::Type::IMAGE: j = "image"; break;
            default: throw "This should not happen";
        }
    }

    void from_json(const json & j, news_by_topic::TypeOfMaterial & x) {
        if (j == "briefing") x = news_by_topic::TypeOfMaterial::BRIEFING;
        else if (j == "News") x = news_by_topic::TypeOfMaterial::NEWS;
        else{
            x = news_by_topic::TypeOfMaterial::OTHER;
            std::cout << j;
        }
    }

    void to_json(json & j, const news_by_topic::TypeOfMaterial & x) {
        switch (x) {
            case news_by_topic::TypeOfMaterial::BRIEFING: j = "briefing"; break;
            case news_by_topic::TypeOfMaterial::NEWS: j = "News"; break;
            default: throw "This should not happen";
        }
    }
}
