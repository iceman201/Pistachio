//
//  NewsTopic.hpp
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#ifndef NewsTopic_hpp
#define NewsTopic_hpp

#include <stdio.h>
#include "json.hpp"

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace news_by_topic {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    class Person {
        public:
        Person() = default;
        virtual ~Person() = default;

        private:
        std::string firstname;
        nlohmann::json middlename;
        std::string lastname;
        nlohmann::json qualifier;
        nlohmann::json title;
        std::string role;
        std::string organization;
        int64_t rank;

        public:
        const std::string & get_firstname() const { return firstname; }
        std::string & get_mutable_firstname() { return firstname; }
        void set_firstname(const std::string & value) { this->firstname = value; }

        const nlohmann::json & get_middlename() const { return middlename; }
        nlohmann::json & get_mutable_middlename() { return middlename; }
        void set_middlename(const nlohmann::json & value) { this->middlename = value; }

        const std::string & get_lastname() const { return lastname; }
        std::string & get_mutable_lastname() { return lastname; }
        void set_lastname(const std::string & value) { this->lastname = value; }

        const nlohmann::json & get_qualifier() const { return qualifier; }
        nlohmann::json & get_mutable_qualifier() { return qualifier; }
        void set_qualifier(const nlohmann::json & value) { this->qualifier = value; }

        const nlohmann::json & get_title() const { return title; }
        nlohmann::json & get_mutable_title() { return title; }
        void set_title(const nlohmann::json & value) { this->title = value; }

        const std::string & get_role() const { return role; }
        std::string & get_mutable_role() { return role; }
        void set_role(const std::string & value) { this->role = value; }

        const std::string & get_organization() const { return organization; }
        std::string & get_mutable_organization() { return organization; }
        void set_organization(const std::string & value) { this->organization = value; }

        const int64_t & get_rank() const { return rank; }
        int64_t & get_mutable_rank() { return rank; }
        void set_rank(const int64_t & value) { this->rank = value; }
    };

    class Byline {
        public:
        Byline() = default;
        virtual ~Byline() = default;

        private:
        std::string original;
        std::vector<Person> person;
        std::shared_ptr<std::string> organization;

        public:
        const std::string & get_original() const { return original; }
        std::string & get_mutable_original() { return original; }
        void set_original(const std::string & value) { this->original = value; }

        const std::vector<Person> & get_person() const { return person; }
        std::vector<Person> & get_mutable_person() { return person; }
        void set_person(const std::vector<Person> & value) { this->person = value; }

        std::shared_ptr<std::string> get_organization() const { return organization; }
        void set_organization(std::shared_ptr<std::string> value) { this->organization = value; }
    };

    enum class DocumentType : int { ARTICLE };

    class Headline {
        public:
        Headline() = default;
        virtual ~Headline() = default;

        private:
        std::string main;
        nlohmann::json kicker;
        nlohmann::json content_kicker;
        std::string print_headline;
        nlohmann::json name;
        nlohmann::json seo;
        nlohmann::json sub;

        public:
        const std::string & get_main() const { return main; }
        std::string & get_mutable_main() { return main; }
        void set_main(const std::string & value) { this->main = value; }

        const nlohmann::json & get_kicker() const { return kicker; }
        nlohmann::json & get_mutable_kicker() { return kicker; }
        void set_kicker(const nlohmann::json & value) { this->kicker = value; }

        const nlohmann::json & get_content_kicker() const { return content_kicker; }
        nlohmann::json & get_mutable_content_kicker() { return content_kicker; }
        void set_content_kicker(const nlohmann::json & value) { this->content_kicker = value; }

        const std::string & get_print_headline() const { return print_headline; }
        std::string & get_mutable_print_headline() { return print_headline; }
        void set_print_headline(const std::string & value) { this->print_headline = value; }

        const nlohmann::json & get_name() const { return name; }
        nlohmann::json & get_mutable_name() { return name; }
        void set_name(const nlohmann::json & value) { this->name = value; }

        const nlohmann::json & get_seo() const { return seo; }
        nlohmann::json & get_mutable_seo() { return seo; }
        void set_seo(const nlohmann::json & value) { this->seo = value; }

        const nlohmann::json & get_sub() const { return sub; }
        nlohmann::json & get_mutable_sub() { return sub; }
        void set_sub(const nlohmann::json & value) { this->sub = value; }
    };

    enum class Major : int { N };

    enum class Name : int { GLOCATIONS, ORGANIZATIONS, PERSONS, SUBJECT };

    class Keyword {
        public:
        Keyword() = default;
        virtual ~Keyword() = default;

        private:
        Name name;
        std::string value;
        int64_t rank;
        Major major;

        public:
        const Name & get_name() const { return name; }
        Name & get_mutable_name() { return name; }
        void set_name(const Name & value) { this->name = value; }

        const std::string & get_value() const { return value; }
        std::string & get_mutable_value() { return value; }
        void set_value(const std::string & value) { this->value = value; }

        const int64_t & get_rank() const { return rank; }
        int64_t & get_mutable_rank() { return rank; }
        void set_rank(const int64_t & value) { this->rank = value; }

        const Major & get_major() const { return major; }
        Major & get_mutable_major() { return major; }
        void set_major(const Major & value) { this->major = value; }
    };

    class Legacy {
        public:
        Legacy() = default;
        virtual ~Legacy() = default;

        private:
        std::shared_ptr<std::string> xlarge;
        std::shared_ptr<int64_t> xlargewidth;
        std::shared_ptr<int64_t> xlargeheight;
        std::shared_ptr<std::string> thumbnail;
        std::shared_ptr<int64_t> thumbnailwidth;
        std::shared_ptr<int64_t> thumbnailheight;
        std::shared_ptr<int64_t> widewidth;
        std::shared_ptr<int64_t> wideheight;
        std::shared_ptr<std::string> wide;

        public:
        std::shared_ptr<std::string> get_xlarge() const { return xlarge; }
        void set_xlarge(std::shared_ptr<std::string> value) { this->xlarge = value; }

        std::shared_ptr<int64_t> get_xlargewidth() const { return xlargewidth; }
        void set_xlargewidth(std::shared_ptr<int64_t> value) { this->xlargewidth = value; }

        std::shared_ptr<int64_t> get_xlargeheight() const { return xlargeheight; }
        void set_xlargeheight(std::shared_ptr<int64_t> value) { this->xlargeheight = value; }

        std::shared_ptr<std::string> get_thumbnail() const { return thumbnail; }
        void set_thumbnail(std::shared_ptr<std::string> value) { this->thumbnail = value; }

        std::shared_ptr<int64_t> get_thumbnailwidth() const { return thumbnailwidth; }
        void set_thumbnailwidth(std::shared_ptr<int64_t> value) { this->thumbnailwidth = value; }

        std::shared_ptr<int64_t> get_thumbnailheight() const { return thumbnailheight; }
        void set_thumbnailheight(std::shared_ptr<int64_t> value) { this->thumbnailheight = value; }

        std::shared_ptr<int64_t> get_widewidth() const { return widewidth; }
        void set_widewidth(std::shared_ptr<int64_t> value) { this->widewidth = value; }

        std::shared_ptr<int64_t> get_wideheight() const { return wideheight; }
        void set_wideheight(std::shared_ptr<int64_t> value) { this->wideheight = value; }

        std::shared_ptr<std::string> get_wide() const { return wide; }
        void set_wide(std::shared_ptr<std::string> value) { this->wide = value; }
    };

    enum class Type : int { IMAGE };

    class Multimedia {
        public:
        Multimedia() = default;
        virtual ~Multimedia() = default;

        private:
        int64_t rank;
        std::string subtype;
        nlohmann::json caption;
        nlohmann::json credit;
        Type type;
        std::string url;
        int64_t height;
        int64_t width;
        Legacy legacy;
        std::string sub_type;
        std::string crop_name;

        public:
        const int64_t & get_rank() const { return rank; }
        int64_t & get_mutable_rank() { return rank; }
        void set_rank(const int64_t & value) { this->rank = value; }

        const std::string & get_subtype() const { return subtype; }
        std::string & get_mutable_subtype() { return subtype; }
        void set_subtype(const std::string & value) { this->subtype = value; }

        const nlohmann::json & get_caption() const { return caption; }
        nlohmann::json & get_mutable_caption() { return caption; }
        void set_caption(const nlohmann::json & value) { this->caption = value; }

        const nlohmann::json & get_credit() const { return credit; }
        nlohmann::json & get_mutable_credit() { return credit; }
        void set_credit(const nlohmann::json & value) { this->credit = value; }

        const Type & get_type() const { return type; }
        Type & get_mutable_type() { return type; }
        void set_type(const Type & value) { this->type = value; }

        const std::string & get_url() const { return url; }
        std::string & get_mutable_url() { return url; }
        void set_url(const std::string & value) { this->url = value; }

        const int64_t & get_height() const { return height; }
        int64_t & get_mutable_height() { return height; }
        void set_height(const int64_t & value) { this->height = value; }

        const int64_t & get_width() const { return width; }
        int64_t & get_mutable_width() { return width; }
        void set_width(const int64_t & value) { this->width = value; }

        const Legacy & get_legacy() const { return legacy; }
        Legacy & get_mutable_legacy() { return legacy; }
        void set_legacy(const Legacy & value) { this->legacy = value; }

        const std::string & get_sub_type() const { return sub_type; }
        std::string & get_mutable_sub_type() { return sub_type; }
        void set_sub_type(const std::string & value) { this->sub_type = value; }

        const std::string & get_crop_name() const { return crop_name; }
        std::string & get_mutable_crop_name() { return crop_name; }
        void set_crop_name(const std::string & value) { this->crop_name = value; }
    };

    enum class NewsDesk : int { BUSINESS, NONE };

    enum class SectionName : int { BUSINESS_DAY, U_S, WORLD };

    enum class Source : int { AP, REUTERS, THE_NEW_YORK_TIMES };

    enum class TypeOfMaterial : int { NEWS };

    class Doc {
        public:
        Doc() = default;
        virtual ~Doc() = default;

        private:
        std::string abstract;
        std::string web_url;
        std::string snippet;
        std::string lead_paragraph;
        Source source;
        std::vector<Multimedia> multimedia;
        Headline headline;
        std::vector<Keyword> keywords;
        std::string pub_date;
        DocumentType document_type;
        NewsDesk news_desk;
        SectionName section_name;
        Byline byline;
        TypeOfMaterial type_of_material;
        std::string id;
        int64_t word_count;
        std::string uri;
        std::shared_ptr<std::string> subsection_name;
        std::shared_ptr<std::string> print_section;
        std::shared_ptr<std::string> print_page;

        public:
        const std::string & get_abstract() const { return abstract; }
        std::string & get_mutable_abstract() { return abstract; }
        void set_abstract(const std::string & value) { this->abstract = value; }

        const std::string & get_web_url() const { return web_url; }
        std::string & get_mutable_web_url() { return web_url; }
        void set_web_url(const std::string & value) { this->web_url = value; }

        const std::string & get_snippet() const { return snippet; }
        std::string & get_mutable_snippet() { return snippet; }
        void set_snippet(const std::string & value) { this->snippet = value; }

        const std::string & get_lead_paragraph() const { return lead_paragraph; }
        std::string & get_mutable_lead_paragraph() { return lead_paragraph; }
        void set_lead_paragraph(const std::string & value) { this->lead_paragraph = value; }

        const Source & get_source() const { return source; }
        Source & get_mutable_source() { return source; }
        void set_source(const Source & value) { this->source = value; }

        const std::vector<Multimedia> & get_multimedia() const { return multimedia; }
        std::vector<Multimedia> & get_mutable_multimedia() { return multimedia; }
        void set_multimedia(const std::vector<Multimedia> & value) { this->multimedia = value; }

        const Headline & get_headline() const { return headline; }
        Headline & get_mutable_headline() { return headline; }
        void set_headline(const Headline & value) { this->headline = value; }

        const std::vector<Keyword> & get_keywords() const { return keywords; }
        std::vector<Keyword> & get_mutable_keywords() { return keywords; }
        void set_keywords(const std::vector<Keyword> & value) { this->keywords = value; }

        const std::string & get_pub_date() const { return pub_date; }
        std::string & get_mutable_pub_date() { return pub_date; }
        void set_pub_date(const std::string & value) { this->pub_date = value; }

        const DocumentType & get_document_type() const { return document_type; }
        DocumentType & get_mutable_document_type() { return document_type; }
        void set_document_type(const DocumentType & value) { this->document_type = value; }

        const NewsDesk & get_news_desk() const { return news_desk; }
        NewsDesk & get_mutable_news_desk() { return news_desk; }
        void set_news_desk(const NewsDesk & value) { this->news_desk = value; }

        const SectionName & get_section_name() const { return section_name; }
        SectionName & get_mutable_section_name() { return section_name; }
        void set_section_name(const SectionName & value) { this->section_name = value; }

        const Byline & get_byline() const { return byline; }
        Byline & get_mutable_byline() { return byline; }
        void set_byline(const Byline & value) { this->byline = value; }

        const TypeOfMaterial & get_type_of_material() const { return type_of_material; }
        TypeOfMaterial & get_mutable_type_of_material() { return type_of_material; }
        void set_type_of_material(const TypeOfMaterial & value) { this->type_of_material = value; }

        const std::string & get_id() const { return id; }
        std::string & get_mutable_id() { return id; }
        void set_id(const std::string & value) { this->id = value; }

        const int64_t & get_word_count() const { return word_count; }
        int64_t & get_mutable_word_count() { return word_count; }
        void set_word_count(const int64_t & value) { this->word_count = value; }

        const std::string & get_uri() const { return uri; }
        std::string & get_mutable_uri() { return uri; }
        void set_uri(const std::string & value) { this->uri = value; }

        std::shared_ptr<std::string> get_subsection_name() const { return subsection_name; }
        void set_subsection_name(std::shared_ptr<std::string> value) { this->subsection_name = value; }

        std::shared_ptr<std::string> get_print_section() const { return print_section; }
        void set_print_section(std::shared_ptr<std::string> value) { this->print_section = value; }

        std::shared_ptr<std::string> get_print_page() const { return print_page; }
        void set_print_page(std::shared_ptr<std::string> value) { this->print_page = value; }
    };

    class Meta {
        public:
        Meta() = default;
        virtual ~Meta() = default;

        private:
        int64_t hits;
        int64_t offset;
        int64_t time;

        public:
        const int64_t & get_hits() const { return hits; }
        int64_t & get_mutable_hits() { return hits; }
        void set_hits(const int64_t & value) { this->hits = value; }

        const int64_t & get_offset() const { return offset; }
        int64_t & get_mutable_offset() { return offset; }
        void set_offset(const int64_t & value) { this->offset = value; }

        const int64_t & get_time() const { return time; }
        int64_t & get_mutable_time() { return time; }
        void set_time(const int64_t & value) { this->time = value; }
    };

    class Response {
        public:
        Response() = default;
        virtual ~Response() = default;

        private:
        std::vector<Doc> docs;
        Meta meta;

        public:
        const std::vector<Doc> & get_docs() const { return docs; }
        std::vector<Doc> & get_mutable_docs() { return docs; }
        void set_docs(const std::vector<Doc> & value) { this->docs = value; }

        const Meta & get_meta() const { return meta; }
        Meta & get_mutable_meta() { return meta; }
        void set_meta(const Meta & value) { this->meta = value; }
    };

    class TestQuestions {
        public:
        TestQuestions() = default;
        virtual ~TestQuestions() = default;

        private:
        std::string status;
        std::string copyright;
        Response response;

        public:
        const std::string & get_status() const { return status; }
        std::string & get_mutable_status() { return status; }
        void set_status(const std::string & value) { this->status = value; }

        const std::string & get_copyright() const { return copyright; }
        std::string & get_mutable_copyright() { return copyright; }
        void set_copyright(const std::string & value) { this->copyright = value; }

        const Response & get_response() const { return response; }
        Response & get_mutable_response() { return response; }
        void set_response(const Response & value) { this->response = value; }
    };
}

#endif /* NewsTopic_hpp */
