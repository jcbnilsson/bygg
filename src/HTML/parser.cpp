/*
 * bygg - Component-based HTML/CSS builder for C++
 *
 * Copyright 2024 - Jacob Nilsson & contributors
 * SPDX-License-Identifier: MIT
 */

#include <bygg/HTML/parser.hpp>
#include <bygg/HTML/impl/libxml2.hpp>
#include <stack>

bygg::HTML::Section bygg::HTML::Parser::parse_html_string(const string_type& html, const Options& options) {
    Section container{Tag::Empty, make_properties()};
    TagList list = bygg::parse_html_string(html);

    std::stack<Section*> section_stack;
    section_stack.push(&container);

    for (size_t i = 0; i < list.size(); ++i) {
        const auto& it = list[i];
        bool is_container = bygg::HTML::is_container(it.tag);

        while (section_stack.size() > it.depth + 1) {
            section_stack.pop();
        }

        Section* current_section = section_stack.top();

        if (is_container) {
            current_section->push_back(Section(it.tag, it.properties));
            section_stack.push(&current_section->back_section());
        } else {
            if (i > 0 && list[i].depth > list[i - 1].depth && list[i].data.empty() && list[i-1].data.empty()) {
                Section new_sect = Section(it.tag, it.properties);
                current_section->push_back(new_sect);
                section_stack.push(&current_section->back_section());
            } else {
                current_section->push_back(Element(it.tag, it.properties, it.data, it.type));
            }
        }
    }

    return container;
}