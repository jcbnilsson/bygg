/*
 * bygg - Component-based HTML/CSS builder for C++
 *
 * Copyright 2024-2025 - Jacob Nilsson & contributors
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <unordered_map>

#include <bygg/types.hpp>
#include <bygg/HTML/tag.hpp>
#include <bygg/HTML/type_enum.hpp>

namespace bygg::HTML {
    /**
     * @brief Enum for element tags.
     */
    enum class Tag {
        Empty, /* Empty element */
        Empty_No_Formatting, /* Empty element, that ignores any formatting by get() calls. */
        Abbreviation, /* <abbr></abbr> */
        Abbr, /* <abbr></abbr> */
        Acronym, /* <acronym></acronym> */
        Address, /* <address></address> */
        Anchor, /* <a></a> */
        A, /* <a></a> */
        Applet, /* <applet></applet> */
        Article, /* <article></article> */
        Area, /* <area></area> */
        Aside, /* <aside></aside> */
        Audio, /* <audio></audio> */
        Base, /* <base></base> */
        Basefont, /* <basefont></basefont> */
        Bdi, /* <bdi></bdi> */
        Bdo, /* <bdo></bdo> */
        Bgsound, /* <bgsound></bgsound> */
        Big, /* <big></big> */
        Blockquote, /* <blockquote></blockquote> */
        Body, /* <body></body> */
        Bold, /* <b></b> */
        B, /* <b></b> */
        Br, /* <br> */
        Break, /* <br> */
        Button, /* <button></button> */
        Caption, /* <caption></caption> */
        Canvas, /* <canvas></canvas> */
        Center, /* <center></center> */
        Cite, /* <cite></cite> */
        Code, /* <code></code> */
        Colgroup, /* <colgroup></colgroup> */
        Col, /* <col></col> */
        Column, /* <col></col> */
        Data, /* <data></data> */
        Datalist, /* <datalist></datalist> */
        Dd, /* <dd></dd> */
        Dfn, /* <dfn></dfn> */
        Define, /* <dfn></dfn> */
        Delete, /* <del></del> */
        Del, /* <del></del> */
        Details, /* <details></details> */
        Dialog, /* <dialog></dialog> */
        Dir, /* <dir></dir> */
        Div, /* <div></div> */
        Dl, /* <dl></dl> */
        Dt, /* <dt></dt> */
        Ul, /* <ul></ul> */
        UnorderedList, /* <ul></ul> */
        Ol, /* <ol></ol> */
        OrderedList, /* <ol></ol> */
        Embed, /* <embed></embed> */
        Em, /* <em></em> */
        Emphasis, /* <em></em> */
        Fieldset, /* <fieldset></fieldset> */
        Figcaption, /* <figcaption></figcaption> */
        Figure, /* <figure></figure> */
        Font, /* <font></font> */
        Footer, /* <footer></footer> */
        Form, /* <form></form> */
        Frame, /* <frame></frame> */
        Frameset, /* <frameset></frameset> */
        Head, /* <head></head> */
        Header, /* <header></header> */
        H1, /* <h1></h1> */
        H2, /* <h2></h2> */
        H3, /* <h3></h3> */
        H4, /* <h4></h4> */
        H5, /* <h5></h5> */
        H6, /* <h6></h6> */
        Hgroup, /* <hgroup></hgroup> */
        Hr, /* <hr> */
        Html, /* <html></html> */
        Iframe, /* <iframe></iframe> */
        Image, /* <img> */
        Img, /* <img> */
        Input, /* <input> */
        Ins, /* <ins></ins> */
        Isindex, /* <isindex></isindex> */
        Italic, /* <i></i> */
        I, /* <i></i> */
        Kbd, /* <kbd></kbd> */
        Keygen, /* <keygen></keygen> */
        Label, /* <label></label> */
        Legend, /* <legend></legend> */
        List, /* <li></li> */
        Li, /* <li></li> */
        Link, /* <link></link> */
        Main, /* <main></main> */
        Mark, /* <mark></mark> */
        Marquee, /* <marquee></marquee> */
        Menuitem, /* <menuitem></menuitem> */
        Meta, /* <meta></meta> */
        Meter, /* <meter></meter> */
        Nav, /* <nav></nav> */
        Nobreak, /* <nobr></nobr> */
        Nobr, /* <nobr></nobr> */
        Noembed, /* <noembed></noembed> */
        Noscript, /* <noscript></noscript> */
        Object, /* <object></object> */
        Optgroup, /* <optgroup></optgroup> */
        Option, /* <option></option> */
        Output, /* <output></output> */
        Paragraph, /* <p></p> */
        P, /* <p></p> */
        Param, /* <param></param> */
        Phrase, /* <pharse></pharse> */
        Pre, /* <pre></pre> */
        Progress, /* <progress></progress> */
        Quote, /* <q></q> */
        Q, /* <q></q> */
        Rp, /* <rp></rp> */
        Rt, /* <rt></rt> */
        Ruby, /* <ruby></ruby> */
        Outdated, /* <s></s> */
        S, /* <s></s> */
        Sample, /* <samp></samp> */
        Samp, /* <samp></samp> */
        Script, /* <script></script> */
        Section, /* <section></section> */
        Small, /* <small></small> */
        Source, /* <source></source> */
        Spacer, /* <spacer></spacer> */
        Span, /* <span></span> */
        Strike, /* <strike></strike> */
        Strong, /* <strong></strong> */
        Style, /* <style></style> */
        Select, /* <select></select> */
        Sub, /* <sub></sub> */
        Subscript, /* <sub></sub> */
        Sup, /* <sup></sup> */
        Superscript, /* <sup></sup> */
        Summary, /* <summary></summary> */
        Svg, /* <svg></svg> */
        Table, /* <table></table> */
        Tbody, /* <tbody></tbody> */
        Td, /* <td></td> */
        Template, /* <template></template> */
        Tfoot, /* <tfoot></tfoot> */
        Th, /* <th></th> */
        Thead, /* <thead></thead> */
        Time, /* <time></time> */
        Title, /* <title></title> */
        Tr, /* <tr></tr> */
        Track, /* <track></track> */
        Tt, /* <tt></tt> */
        Underline, /* <u></u> */
        U, /* <u></u> */
        Var, /* <var></var> */
        Video, /* <video></video> */
        Wbr, /* <wbr></wbr> */
        Xmp, /* <xmp></xmp> */
    };

    /**
     * @brief Get a map of tags to strings and types.
     * @return std::unordered_map<bygg::HTML::Tag, std::pair<string_type, bygg::HTML::Type>> The map of tags to strings and types.
     */
    std::unordered_map<bygg::HTML::Tag, std::pair<string_type, bygg::HTML::Type>> get_tag_map();
    /**
     * @brief Resolve a tag to a string and type.
     * @param tag The tag to resolve
     * @return std::pair<string_type, Type> The resolved tag
     */
    std::pair<string_type, Type> resolve_tag(Tag tag);
    /**
     * @brief Resolve a string tag to a Tag enum.
     * @param tag The tag to resolve
     * @return Tag The resolved tag
     */
    Tag resolve_tag(const string_type& tag);

    /**
     * @brief Get the name of the enum for a tag.
     * @param tag The tag to get the enum name for
     */
    string_type resolve_tag_enum_name(Tag tag);
    /**
     * @brief Check if a tag is a container.
     * @param tag The tag to check
     * @return bool True if the tag is a container, false otherwise
     */
    bool is_container(const string_type& tag);
    bool is_container(Tag tag);
} // namespace bygg
