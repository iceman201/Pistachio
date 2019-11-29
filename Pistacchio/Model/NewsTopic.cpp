//
//  NewsTopic.cpp
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#include "NewsTopic.hpp"

namespace nlohmann {
    void from_json(const json & j, news_by_topic::Person & x);
    void to_json(json & j, const news_by_topic::Person & x);

    void from_json(const json & j, news_by_topic::Byline & x);
    void to_json(json & j, const news_by_topic::Byline & x);

    void from_json(const json & j, news_by_topic::Headline & x);
    void to_json(json & j, const news_by_topic::Headline & x);

    void from_json(const json & j, news_by_topic::Keyword & x);
    void to_json(json & j, const news_by_topic::Keyword & x);

    void from_json(const json & j, news_by_topic::Legacy & x);
    void to_json(json & j, const news_by_topic::Legacy & x);

    void from_json(const json & j, news_by_topic::Multimedia & x);
    void to_json(json & j, const news_by_topic::Multimedia & x);

    void from_json(const json & j, news_by_topic::Doc & x);
    void to_json(json & j, const news_by_topic::Doc & x);

    void from_json(const json & j, news_by_topic::Meta & x);
    void to_json(json & j, const news_by_topic::Meta & x);

    void from_json(const json & j, news_by_topic::Response & x);
    void to_json(json & j, const news_by_topic::Response & x);

    void from_json(const json & j, news_by_topic::TestQuestions & x);
    void to_json(json & j, const news_by_topic::TestQuestions & x);

    void from_json(const json & j, news_by_topic::DocumentType & x);
    void to_json(json & j, const news_by_topic::DocumentType & x);

    void from_json(const json & j, news_by_topic::Major & x);
    void to_json(json & j, const news_by_topic::Major & x);

    void from_json(const json & j, news_by_topic::Name & x);
    void to_json(json & j, const news_by_topic::Name & x);

    void from_json(const json & j, news_by_topic::Type & x);
    void to_json(json & j, const news_by_topic::Type & x);

    void from_json(const json & j, news_by_topic::NewsDesk & x);
    void to_json(json & j, const news_by_topic::NewsDesk & x);

    void from_json(const json & j, news_by_topic::SectionName & x);
    void to_json(json & j, const news_by_topic::SectionName & x);

    void from_json(const json & j, news_by_topic::Source & x);
    void to_json(json & j, const news_by_topic::Source & x);

    void from_json(const json & j, news_by_topic::TypeOfMaterial & x);
    void to_json(json & j, const news_by_topic::TypeOfMaterial & x);

    inline void from_json(const json & j, news_by_topic::Person& x) {
        x.set_firstname(j.at("firstname").get<std::string>());
        x.set_middlename(news_by_topic::get_untyped(j, "middlename"));
        x.set_lastname(j.at("lastname").get<std::string>());
        x.set_qualifier(news_by_topic::get_untyped(j, "qualifier"));
        x.set_title(news_by_topic::get_untyped(j, "title"));
        x.set_role(j.at("role").get<std::string>());
        x.set_organization(j.at("organization").get<std::string>());
        x.set_rank(j.at("rank").get<int64_t>());
    }

    inline void to_json(json & j, const news_by_topic::Person & x) {
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

    inline void from_json(const json & j, news_by_topic::Byline& x) {
        x.set_original(j.at("original").get<std::string>());
        x.set_person(j.at("person").get<std::vector<news_by_topic::Person>>());
        x.set_organization(news_by_topic::get_optional<std::string>(j, "organization"));
    }

    inline void to_json(json & j, const news_by_topic::Byline & x) {
        j = json::object();
        j["original"] = x.get_original();
        j["person"] = x.get_person();
        j["organization"] = x.get_organization();
    }

    inline void from_json(const json & j, news_by_topic::Headline& x) {
        x.set_main(j.at("main").get<std::string>());
        x.set_kicker(news_by_topic::get_untyped(j, "kicker"));
        x.set_content_kicker(news_by_topic::get_untyped(j, "content_kicker"));
        x.set_print_headline(j.at("print_headline").get<std::string>());
        x.set_name(news_by_topic::get_untyped(j, "name"));
        x.set_seo(news_by_topic::get_untyped(j, "seo"));
        x.set_sub(news_by_topic::get_untyped(j, "sub"));
    }

    inline void to_json(json & j, const news_by_topic::Headline & x) {
        j = json::object();
        j["main"] = x.get_main();
        j["kicker"] = x.get_kicker();
        j["content_kicker"] = x.get_content_kicker();
        j["print_headline"] = x.get_print_headline();
        j["name"] = x.get_name();
        j["seo"] = x.get_seo();
        j["sub"] = x.get_sub();
    }

    inline void from_json(const json & j, news_by_topic::Keyword& x) {
        x.set_name(j.at("name").get<news_by_topic::Name>());
        x.set_value(j.at("value").get<std::string>());
        x.set_rank(j.at("rank").get<int64_t>());
        x.set_major(j.at("major").get<news_by_topic::Major>());
    }

    inline void to_json(json & j, const news_by_topic::Keyword & x) {
        j = json::object();
        j["name"] = x.get_name();
        j["value"] = x.get_value();
        j["rank"] = x.get_rank();
        j["major"] = x.get_major();
    }

    inline void from_json(const json & j, news_by_topic::Legacy& x) {
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

    inline void to_json(json & j, const news_by_topic::Legacy & x) {
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

    inline void from_json(const json & j, news_by_topic::Multimedia& x) {
        x.set_rank(j.at("rank").get<int64_t>());
        x.set_subtype(j.at("subtype").get<std::string>());
        x.set_caption(news_by_topic::get_untyped(j, "caption"));
        x.set_credit(news_by_topic::get_untyped(j, "credit"));
        x.set_type(j.at("type").get<news_by_topic::Type>());
        x.set_url(j.at("url").get<std::string>());
        x.set_height(j.at("height").get<int64_t>());
        x.set_width(j.at("width").get<int64_t>());
        x.set_legacy(j.at("legacy").get<news_by_topic::Legacy>());
        x.set_sub_type(j.at("subType").get<std::string>());
        x.set_crop_name(j.at("crop_name").get<std::string>());
    }

    inline void to_json(json & j, const news_by_topic::Multimedia & x) {
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

    inline void from_json(const json & j, news_by_topic::Doc& x) {
        x.set_abstract(j.at("abstract").get<std::string>());
        x.set_web_url(j.at("web_url").get<std::string>());
        x.set_snippet(j.at("snippet").get<std::string>());
        x.set_lead_paragraph(j.at("lead_paragraph").get<std::string>());
        x.set_source(j.at("source").get<news_by_topic::Source>());
        x.set_multimedia(j.at("multimedia").get<std::vector<news_by_topic::Multimedia>>());
        x.set_headline(j.at("headline").get<news_by_topic::Headline>());
        x.set_keywords(j.at("keywords").get<std::vector<news_by_topic::Keyword>>());
        x.set_pub_date(j.at("pub_date").get<std::string>());
        x.set_document_type(j.at("document_type").get<news_by_topic::DocumentType>());
        x.set_news_desk(j.at("news_desk").get<news_by_topic::NewsDesk>());
        x.set_section_name(j.at("section_name").get<news_by_topic::SectionName>());
        x.set_byline(j.at("byline").get<news_by_topic::Byline>());
        x.set_type_of_material(j.at("type_of_material").get<news_by_topic::TypeOfMaterial>());
        x.set_id(j.at("_id").get<std::string>());
        x.set_word_count(j.at("word_count").get<int64_t>());
        x.set_uri(j.at("uri").get<std::string>());
        x.set_subsection_name(news_by_topic::get_optional<std::string>(j, "subsection_name"));
        x.set_print_section(news_by_topic::get_optional<std::string>(j, "print_section"));
        x.set_print_page(news_by_topic::get_optional<std::string>(j, "print_page"));
    }

    inline void to_json(json & j, const news_by_topic::Doc & x) {
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

    inline void from_json(const json & j, news_by_topic::Meta& x) {
        x.set_hits(j.at("hits").get<int64_t>());
        x.set_offset(j.at("offset").get<int64_t>());
        x.set_time(j.at("time").get<int64_t>());
    }

    inline void to_json(json & j, const news_by_topic::Meta & x) {
        j = json::object();
        j["hits"] = x.get_hits();
        j["offset"] = x.get_offset();
        j["time"] = x.get_time();
    }

    inline void from_json(const json & j, news_by_topic::Response& x) {
        x.set_docs(j.at("docs").get<std::vector<news_by_topic::Doc>>());
        x.set_meta(j.at("meta").get<news_by_topic::Meta>());
    }

    inline void to_json(json & j, const news_by_topic::Response & x) {
        j = json::object();
        j["docs"] = x.get_docs();
        j["meta"] = x.get_meta();
    }

    inline void from_json(const json & j, news_by_topic::TestQuestions& x) {
        x.set_status(j.at("status").get<std::string>());
        x.set_copyright(j.at("copyright").get<std::string>());
        x.set_response(j.at("response").get<news_by_topic::Response>());
    }

    inline void to_json(json & j, const news_by_topic::TestQuestions & x) {
        j = json::object();
        j["status"] = x.get_status();
        j["copyright"] = x.get_copyright();
        j["response"] = x.get_response();
    }

    inline void from_json(const json & j, news_by_topic::DocumentType & x) {
        if (j == "article") x = news_by_topic::DocumentType::ARTICLE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::DocumentType & x) {
        switch (x) {
            case news_by_topic::DocumentType::ARTICLE: j = "article"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::Major & x) {
        if (j == "N") x = news_by_topic::Major::N;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::Major & x) {
        switch (x) {
            case news_by_topic::Major::N: j = "N"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::Name & x) {
        if (j == "glocations") x = news_by_topic::Name::GLOCATIONS;
        else if (j == "organizations") x = news_by_topic::Name::ORGANIZATIONS;
        else if (j == "persons") x = news_by_topic::Name::PERSONS;
        else if (j == "subject") x = news_by_topic::Name::SUBJECT;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::Name & x) {
        switch (x) {
            case news_by_topic::Name::GLOCATIONS: j = "glocations"; break;
            case news_by_topic::Name::ORGANIZATIONS: j = "organizations"; break;
            case news_by_topic::Name::PERSONS: j = "persons"; break;
            case news_by_topic::Name::SUBJECT: j = "subject"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::Type & x) {
        if (j == "image") x = news_by_topic::Type::IMAGE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::Type & x) {
        switch (x) {
            case news_by_topic::Type::IMAGE: j = "image"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::NewsDesk & x) {
        if (j == "Business") x = news_by_topic::NewsDesk::BUSINESS;
        else if (j == "None") x = news_by_topic::NewsDesk::NONE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::NewsDesk & x) {
        switch (x) {
            case news_by_topic::NewsDesk::BUSINESS: j = "Business"; break;
            case news_by_topic::NewsDesk::NONE: j = "None"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::SectionName & x) {
        if (j == "Business Day") x = news_by_topic::SectionName::BUSINESS_DAY;
        else if (j == "U.S.") x = news_by_topic::SectionName::U_S;
        else if (j == "World") x = news_by_topic::SectionName::WORLD;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::SectionName & x) {
        switch (x) {
            case news_by_topic::SectionName::BUSINESS_DAY: j = "Business Day"; break;
            case news_by_topic::SectionName::U_S: j = "U.S."; break;
            case news_by_topic::SectionName::WORLD: j = "World"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::Source & x) {
        if (j == "AP") x = news_by_topic::Source::AP;
        else if (j == "Reuters") x = news_by_topic::Source::REUTERS;
        else if (j == "The New York Times") x = news_by_topic::Source::THE_NEW_YORK_TIMES;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::Source & x) {
        switch (x) {
            case news_by_topic::Source::AP: j = "AP"; break;
            case news_by_topic::Source::REUTERS: j = "Reuters"; break;
            case news_by_topic::Source::THE_NEW_YORK_TIMES: j = "The New York Times"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, news_by_topic::TypeOfMaterial & x) {
        if (j == "News") x = news_by_topic::TypeOfMaterial::NEWS;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const news_by_topic::TypeOfMaterial & x) {
        switch (x) {
            case news_by_topic::TypeOfMaterial::NEWS: j = "News"; break;
            default: throw "This should not happen";
        }
    }
}
