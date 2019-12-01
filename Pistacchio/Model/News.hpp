//
//  News.hpp
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#include <nlohmann_json/json.hpp>
#include <ostream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <regex>
#include <stdio.h>

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

    enum class Source : int { REUTERS, THE_NEW_YORK_TIMES, AP, IHT, OTHER };

    class Person {
        public:
        Person() = default;
        virtual ~Person() = default;

        private:
        std::shared_ptr<std::string> firstname;
        std::shared_ptr<std::string> middlename;
        std::shared_ptr<std::string> lastname;
        nlohmann::json qualifier;
        nlohmann::json title;
        std::shared_ptr<std::string> role;
        std::shared_ptr<std::string> organization;
        std::shared_ptr<int64_t> rank;

        public:
        std::shared_ptr<std::string> get_firstname() const { return firstname; }
        void set_firstname(std::shared_ptr<std::string> value) { this->firstname = value; }

        std::shared_ptr<std::string> get_middlename() const { return middlename; }
        void set_middlename(std::shared_ptr<std::string> value) { this->middlename = value; }

        std::shared_ptr<std::string> get_lastname() const { return lastname; }
        void set_lastname(std::shared_ptr<std::string> value) { this->lastname = value; }

        const nlohmann::json & get_qualifier() const { return qualifier; }
        nlohmann::json & get_mutable_qualifier() { return qualifier; }
        void set_qualifier(const nlohmann::json & value) { this->qualifier = value; }

        const nlohmann::json & get_title() const { return title; }
        nlohmann::json & get_mutable_title() { return title; }
        void set_title(const nlohmann::json & value) { this->title = value; }

        std::shared_ptr<std::string> get_role() const { return role; }
        void set_role(std::shared_ptr<std::string> value) { this->role = value; }

        std::shared_ptr<std::string> get_organization() const { return organization; }
        void set_organization(std::shared_ptr<std::string> value) { this->organization = value; }

        std::shared_ptr<int64_t> get_rank() const { return rank; }
        void set_rank(std::shared_ptr<int64_t> value) { this->rank = value; }
    };

    class Byline {
        public:
        Byline() = default;
        virtual ~Byline() = default;

        private:
        std::shared_ptr<std::string> original;
        std::shared_ptr<std::vector<Person>> person;
        std::shared_ptr<Source> organization;

        public:
        std::shared_ptr<std::string> get_original() const { return original; }
        void set_original(std::shared_ptr<std::string> value) { this->original = value; } 

        std::shared_ptr<std::vector<Person>> get_person() const { return person; }
        void set_person(std::shared_ptr<std::vector<Person>> value) { this->person = value; }

        std::shared_ptr<Source> get_organization() const { return organization; }
        void set_organization(std::shared_ptr<Source> value) { this->organization = value; }
    };

    enum class DocumentType : int { ARTICLE };

    class Headline {
        public:
        Headline() = default;
        virtual ~Headline() = default;

        private:
        std::shared_ptr<std::string> main;
        std::shared_ptr<std::string> kicker;
        nlohmann::json content_kicker;
        std::shared_ptr<std::string> print_headline;
        nlohmann::json name;
        nlohmann::json seo;
        nlohmann::json sub;

        public:
        std::shared_ptr<std::string> get_main() const { return main; }
        void set_main(std::shared_ptr<std::string> value) { this->main = value; }

        std::shared_ptr<std::string> get_kicker() const { return kicker; }
        void set_kicker(std::shared_ptr<std::string> value) { this->kicker = value; }

        const nlohmann::json & get_content_kicker() const { return content_kicker; }
        nlohmann::json & get_mutable_content_kicker() { return content_kicker; }
        void set_content_kicker(const nlohmann::json & value) { this->content_kicker = value; }

        std::shared_ptr<std::string> get_print_headline() const { return print_headline; }
        void set_print_headline(std::shared_ptr<std::string> value) { this->print_headline = value; }

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
        std::shared_ptr<Name> name;
        std::shared_ptr<std::string> value;
        std::shared_ptr<int64_t> rank;
        std::shared_ptr<Major> major;

        public:
        std::shared_ptr<Name> get_name() const { return name; }
        void set_name(std::shared_ptr<Name> value) { this->name = value; }

        std::shared_ptr<std::string> get_value() const { return value; }
        void set_value(std::shared_ptr<std::string> value) { this->value = value; }

        std::shared_ptr<int64_t> get_rank() const { return rank; }
        void set_rank(std::shared_ptr<int64_t> value) { this->rank = value; }

        std::shared_ptr<Major> get_major() const { return major; }
        void set_major(std::shared_ptr<Major> value) { this->major = value; }
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
        std::shared_ptr<int64_t> rank;
        std::shared_ptr<std::string> subtype;
        nlohmann::json caption;
        nlohmann::json credit;
        std::shared_ptr<Type> type;
        std::shared_ptr<std::string> url;
        std::shared_ptr<int64_t> height;
        std::shared_ptr<int64_t> width;
        std::shared_ptr<Legacy> legacy;
        std::shared_ptr<std::string> sub_type;
        std::shared_ptr<std::string> crop_name;

        public:
        std::shared_ptr<int64_t> get_rank() const { return rank; }
        void set_rank(std::shared_ptr<int64_t> value) { this->rank = value; }

        std::shared_ptr<std::string> get_subtype() const { return subtype; }
        void set_subtype(std::shared_ptr<std::string> value) { this->subtype = value; }

        const nlohmann::json & get_caption() const { return caption; }
        nlohmann::json & get_mutable_caption() { return caption; }
        void set_caption(const nlohmann::json & value) { this->caption = value; }

        const nlohmann::json & get_credit() const { return credit; }
        nlohmann::json & get_mutable_credit() { return credit; }
        void set_credit(const nlohmann::json & value) { this->credit = value; }

        std::shared_ptr<Type> get_type() const { return type; }
        void set_type(std::shared_ptr<Type> value) { this->type = value; }

        std::shared_ptr<std::string> get_url() const { return url; }
        void set_url(std::shared_ptr<std::string> value) { this->url = value; }

        std::shared_ptr<int64_t> get_height() const { return height; }
        void set_height(std::shared_ptr<int64_t> value) { this->height = value; }

        std::shared_ptr<int64_t> get_width() const { return width; }
        void set_width(std::shared_ptr<int64_t> value) { this->width = value; }

        std::shared_ptr<Legacy> get_legacy() const { return legacy; }
        void set_legacy(std::shared_ptr<Legacy> value) { this->legacy = value; }

        std::shared_ptr<std::string> get_sub_type() const { return sub_type; }
        void set_sub_type(std::shared_ptr<std::string> value) { this->sub_type = value; }

        std::shared_ptr<std::string> get_crop_name() const { return crop_name; }
        void set_crop_name(std::shared_ptr<std::string> value) { this->crop_name = value; }
    };

    enum class TypeOfMaterial : int { BRIEFING, NEWS, OTHER };
    
    class Doc {
        public:
        Doc() = default;
        virtual ~Doc() = default;

        private:
        std::shared_ptr<std::string> abstract;
        std::shared_ptr<std::string> web_url;
        std::shared_ptr<std::string> snippet;
        std::shared_ptr<std::string> lead_paragraph;
        std::shared_ptr<Source> source;
        std::shared_ptr<std::vector<Multimedia>> multimedia;
        std::shared_ptr<Headline> headline;
        std::shared_ptr<std::vector<Keyword>> keywords;
        std::shared_ptr<std::string> pub_date;
        std::shared_ptr<DocumentType> document_type;
        std::shared_ptr<std::string> news_desk;
        std::shared_ptr<std::string> section_name;
        std::shared_ptr<Byline> byline;
        std::shared_ptr<TypeOfMaterial> type_of_material;
        std::shared_ptr<std::string> id;
        std::shared_ptr<int64_t> word_count;
        std::shared_ptr<std::string> uri;
        std::shared_ptr<std::string> subsection_name;
        std::shared_ptr<std::string> print_section;
        std::shared_ptr<std::string> print_page;

        public:
        std::shared_ptr<std::string> get_abstract() const { return abstract; }
        void set_abstract(std::shared_ptr<std::string> value) { this->abstract = value; }

        std::shared_ptr<std::string> get_web_url() const { return web_url; }
        void set_web_url(std::shared_ptr<std::string> value) { this->web_url = value; }

        std::shared_ptr<std::string> get_snippet() const { return snippet; }
        void set_snippet(std::shared_ptr<std::string> value) { this->snippet = value; }

        std::shared_ptr<std::string> get_lead_paragraph() const { return lead_paragraph; }
        void set_lead_paragraph(std::shared_ptr<std::string> value) { this->lead_paragraph = value; }

        std::shared_ptr<Source> get_source() const { return source; }
        void set_source(std::shared_ptr<Source> value) { this->source = value; }

        std::shared_ptr<std::vector<Multimedia>> get_multimedia() const { return multimedia; }
        void set_multimedia(std::shared_ptr<std::vector<Multimedia>> value) { this->multimedia = value; }

        std::shared_ptr<Headline> get_headline() const { return headline; }
        void set_headline(std::shared_ptr<Headline> value) { this->headline = value; }

        std::shared_ptr<std::vector<Keyword>> get_keywords() const { return keywords; }
        void set_keywords(std::shared_ptr<std::vector<Keyword>> value) { this->keywords = value; }

        std::shared_ptr<std::string> get_pub_date() const { return pub_date; }
        void set_pub_date(std::shared_ptr<std::string> value) { this->pub_date = value; }

        std::shared_ptr<DocumentType> get_document_type() const { return document_type; }
        void set_document_type(std::shared_ptr<DocumentType> value) { this->document_type = value; }

        std::shared_ptr<std::string> get_news_desk() const { return news_desk; }
        void set_news_desk(std::shared_ptr<std::string> value) { this->news_desk = value; }

        std::shared_ptr<std::string> get_section_name() const { return section_name; }
        void set_section_name(std::shared_ptr<std::string> value) { this->section_name = value; }

        std::shared_ptr<Byline> get_byline() const { return byline; }
        void set_byline(std::shared_ptr<Byline> value) { this->byline = value; }

        std::shared_ptr<TypeOfMaterial> get_type_of_material() const { return type_of_material; }
        void set_type_of_material(std::shared_ptr<TypeOfMaterial> value) { this->type_of_material = value; }

        std::shared_ptr<std::string> get_id() const { return id; }
        void set_id(std::shared_ptr<std::string> value) { this->id = value; }

        std::shared_ptr<int64_t> get_word_count() const { return word_count; }
        void set_word_count(std::shared_ptr<int64_t> value) { this->word_count = value; }

        std::shared_ptr<std::string> get_uri() const { return uri; }
        void set_uri(std::shared_ptr<std::string> value) { this->uri = value; }

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
        std::shared_ptr<int64_t> hits;
        std::shared_ptr<int64_t> offset;
        std::shared_ptr<int64_t> time;

        public:
        std::shared_ptr<int64_t> get_hits() const { return hits; }
        void set_hits(std::shared_ptr<int64_t> value) { this->hits = value; }

        std::shared_ptr<int64_t> get_offset() const { return offset; }
        void set_offset(std::shared_ptr<int64_t> value) { this->offset = value; }

        std::shared_ptr<int64_t> get_time() const { return time; }
        void set_time(std::shared_ptr<int64_t> value) { this->time = value; }
    };

    class Response {
        public:
        Response() = default;
        virtual ~Response() = default;

        private:
        std::shared_ptr<std::vector<Doc>> docs;
        std::shared_ptr<Meta> meta;

        public:
        std::shared_ptr<std::vector<Doc>> get_docs() const { return docs; }
        void set_docs(std::shared_ptr<std::vector<Doc>> value) { this->docs = value; }

        std::shared_ptr<Meta> get_meta() const { return meta; }
        void set_meta(std::shared_ptr<Meta> value) { this->meta = value; }
    };

    class Welcome {
        public:
        Welcome() = default;
        virtual ~Welcome() = default;

        private:
        std::shared_ptr<std::string> status;
        std::shared_ptr<std::string> copyright;
        std::shared_ptr<Response> response;

        public:
        std::shared_ptr<std::string> get_status() const { return status; }
        void set_status(std::shared_ptr<std::string> value) { this->status = value; }

        std::shared_ptr<std::string> get_copyright() const { return copyright; }
        void set_copyright(std::shared_ptr<std::string> value) { this->copyright = value; }

        std::shared_ptr<Response> get_response() const { return response; }
        void set_response(std::shared_ptr<Response> value) { this->response = value; }
    };
}

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

    void from_json(const json & j, news_by_topic::Welcome & x);
    void to_json(json & j, const news_by_topic::Welcome & x);

    void from_json(const json & j, news_by_topic::Source & x);
    void to_json(json & j, const news_by_topic::Source & x);

    void from_json(const json & j, news_by_topic::DocumentType & x);
    void to_json(json & j, const news_by_topic::DocumentType & x);

    void from_json(const json & j, news_by_topic::Major & x);
    void to_json(json & j, const news_by_topic::Major & x);

    void from_json(const json & j, news_by_topic::Name & x);
    void to_json(json & j, const news_by_topic::Name & x);

    void from_json(const json & j, news_by_topic::Type & x);
    void to_json(json & j, const news_by_topic::Type & x);

    void from_json(const json & j, news_by_topic::TypeOfMaterial & x);
    void to_json(json & j, const news_by_topic::TypeOfMaterial & x);
}
