/*
 * bygg - Component-based HTML/CSS builder for C++
 *
 * Copyright 2024-2025 - Jacob Nilsson & contributors
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <vector>
#include <variant>

#include <bygg/types.hpp>
#include <bygg/except.hpp>
#include <bygg/HTML/find_enum.hpp>
#include <bygg/HTML/tag.hpp>
#include <bygg/HTML/properties.hpp>
#include <bygg/HTML/element.hpp>

namespace bygg::HTML {
    class Section;

    /**
     * @brief Container type for storing data of type Section. Equivalent to std::vector<Section>.
     */
    using SectionList = std::vector<Section>;
    /**
     * @brief Container type for storing data of type Element. Equivalent to std::vector<Element>.
     */
    using ElementList = std::vector<Element>;

    /**
     * @brief A class to represent an HTML section (head, body, etc.)
     */
    class Section {
        public:
            /**
             * @brief Iterator for elements.
             */
            using element_iterator = ElementList::iterator;
            /**
             * @brief Const iterator for elements.
             */
            using element_const_iterator = ElementList::const_iterator;
            /**
             * @brief Reverse iterator for elements.
             */
            using element_reverse_iterator = ElementList::reverse_iterator;
            /**
             * @brief Const reverse iterator for elements.
             */
            using element_const_reverse_iterator = ElementList::const_reverse_iterator;
            /**
             * @brief Iterator for sections.
             */
            using section_iterator = SectionList::iterator;
            /**
             * @brief Const iterator for sections.
             */
            using section_const_iterator = SectionList::const_iterator;
            /**
             * @brief Reverse iterator for sections.
             */
            using section_reverse_iterator = SectionList::reverse_iterator;
            /**
             * @brief Const reverse iterator for sections.
             */
            using section_const_reverse_iterator = SectionList::const_reverse_iterator;
            /**
             * @brief Variant type holding either an Element or a Section.
             */
            using variant_t = std::variant<Element, Section>;
            /**
             * @brief List of variants. May be used to iterate over multiple types.
             */
            using variant_list = std::vector<variant_t>;
            /**
             * @brief Iterator for variants.
             */
            using iterator = variant_list::iterator;
            /**
             * @brief Const iterator for variants.
             */
            using const_iterator = variant_list::const_iterator;
            /**
             * @brief Reverse iterator for variants.
             */
            using reverse_iterator = variant_list::reverse_iterator;
            /**
             * @brief Const reverse iterator for variants.
             */
            using const_reverse_iterator = variant_list::const_reverse_iterator;

            /**
             * @brief Return a variant_list of all elements and sections.
             * @note To use the result, you must use std::visit.
             * @example std::visit([](auto&& arg) { if constexpr (std::is_same_v<decltype(arg), Element>) {}}, section.get_all());
             */
            [[nodiscard]] variant_list& get_all() const {
                return members;
            }
            /**
             * @brief Get a variant_t at a specific index.
             * @param index The index to get the variant_t from.
             * @return variant_t The variant_t at the index.
             */
            [[nodiscard]] variant_t& get_any(size_type index) {
                for (size_type i{}; i < members.size(); ++i) {
                    if (i == index) {
                        return members.at(i);
                    }
                }

                throw out_of_range("Index out of range");
            }

            /**
             * @brief Return an iterator to the beginning.
             * @return element_iterator The iterator to the beginning.
             */
            element_iterator element_begin() {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_iterator(elements.begin());
            }
            /**
             * @brief Return an iterator to the end.
             * @return element_iterator The iterator to the end.
             */
            element_iterator element_end() {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_iterator(elements.end());
            }
            /**
             * @brief Return an iterator to the beginning.
             * @return element_const_iterator The iterator to the beginning.
             */
            [[nodiscard]] element_const_iterator element_begin() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_const_iterator(elements.cbegin());
            }
            /**
             * @brief Return an iterator to the end.
             * @return element_const_iterator The iterator to the end.
             */
            [[nodiscard]] element_const_iterator element_end() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_const_iterator(elements.cend());
            }
            /**
             * @brief Return a const iterator to the beginning.
             * @return element_const_iterator The const iterator to the beginning.
             */
            [[nodiscard]] element_const_iterator element_cbegin() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_const_iterator(elements.cbegin());
            }
            /**
             * @brief Return a const iterator to the end.
             * @return element_const_iterator The const iterator to the end.
             */
            [[nodiscard]] element_const_iterator element_cend() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }
                return element_const_iterator(elements.cend());
            }
            /**
             * @brief Return a reverse iterator to the beginning.
             * @return element_reverse_iterator The reverse iterator to the beginning.
             */
            [[nodiscard]] element_reverse_iterator element_rbegin() {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }

                return element_reverse_iterator(elements.rbegin());
            }
            /**
             * @brief Return a reverse iterator to the end.
             * @return element_reverse_iterator The reverse iterator to the end.
             */
            [[nodiscard]] element_reverse_iterator element_rend() {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }

                return element_reverse_iterator(elements.rbegin());
            }
            /**
             * @brief Return a const reverse iterator to the beginning.
             * @return element_const_reverse_iterator The const reverse iterator to the beginning.
             */
            [[nodiscard]] element_const_reverse_iterator element_crbegin() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }

                return element_const_reverse_iterator(elements.crbegin());
            }
            /**
             * @brief Return a const reverse iterator to the end.
             * @return element_const_reverse_iterator The const reverse iterator to the end.
             */
            [[nodiscard]] element_const_reverse_iterator element_crend() const {
                elements.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Element>(it)) {
                        elements.push_back(std::get<Element>(it));
                    }
                }

                return element_const_reverse_iterator(elements.crend());
            }
            /**
             * @brief Return an iterator to the beginning.
             * @return section_iterator The iterator to the beginning.
             */
            section_iterator section_begin() {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_iterator(sections.begin());
            }
            /**
             * @brief Return an iterator to the end.
             * @return section_iterator The iterator to the end.
             */
            section_iterator section_end() {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_iterator(sections.end());
            }
            /**
             * @brief Return an iterator to the beginning.
             * @return section_const_iterator The iterator to the beginning.
             */
            [[nodiscard]] section_const_iterator section_begin() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return {sections.begin()};
            }
            /**
             * @brief Return an iterator to the end.
             * @return section_const_iterator The iterator to the end.
             */
            [[nodiscard]] section_const_iterator section_end() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return {sections.end()};
            }
            /**
             * @brief Return a const iterator to the beginning.
             * @return section_const_iterator The const iterator to the beginning.
             */
            [[nodiscard]] section_const_iterator section_cbegin() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_const_iterator(sections.cbegin());
            }
            /**
             * @brief Return a const iterator to the end.
             * @return section_const_iterator The const iterator to the end.
             */
            [[nodiscard]] section_const_iterator section_cend() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_const_iterator(sections.cend());
            }
            /**
             * @brief Return a reverse iterator to the beginning.
             * @return section_reverse_iterator The reverse iterator to the beginning.
             */
            [[nodiscard]] section_reverse_iterator section_rbegin() {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_reverse_iterator(sections.rbegin());
            }
            /**
             * @brief Return a reverse iterator to the end.
             * @return section_reverse_iterator The reverse iterator to the end.
             */
            [[nodiscard]] section_reverse_iterator section_rend() {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_reverse_iterator(sections.rend());
            }
            /**
             * @brief Return a const reverse iterator to the beginning.
             * @return section_const_reverse_iterator The const reverse iterator to the beginning.
             */
            [[nodiscard]] section_const_reverse_iterator section_crbegin() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_const_reverse_iterator(sections.crbegin());
            }
            /**
             * @brief Return a const reverse iterator to the end.
             * @return section_const_reverse_iterator The const reverse iterator to the end.
             */
            [[nodiscard]] section_const_reverse_iterator section_crend() const {
                sections.clear();
                for (const auto& it : members) {
                    if (std::holds_alternative<Section>(it)) {
                        sections.push_back(std::get<Section>(it));
                    }
                }
                return section_const_reverse_iterator(sections.crend());
            }
            /**
             * @brief Return an iterator to the beginning.
             * @return iterator The iterator to the beginning.
             */
            [[nodiscard]] iterator begin() { return get_all().begin(); }
            /**
             * @brief Return an iterator to the end.
             * @return iterator The iterator to the end.
             */
            [[nodiscard]] iterator end() { return get_all().end(); }
            /**
             * @brief Return an iterator to the beginning.
             * @return const_iterator The iterator to the beginning.
             */
            [[nodiscard]] const_iterator begin() const { return get_all().cbegin(); }
            /**
             * @brief Return an iterator to the end.
             * @return const_iterator The iterator to the end.
             */
            [[nodiscard]] const_iterator end() const { return get_all().cend(); }
            /**
             * @brief Return a const iterator to the beginning.
             * @return const_iterator The const iterator to the beginning.
             */
            [[nodiscard]] const_iterator cbegin() const { return get_all().cbegin(); }
            /**
             * @brief Return a const iterator to the end.
             * @return const_iterator The const iterator to the end.
             */
            [[nodiscard]] const_iterator cend() const { return get_all().cend(); }
            /**
             * @brief Return a reverse iterator to the beginning.
             * @return reverse_iterator The reverse iterator to the beginning.
             */
            [[nodiscard]] reverse_iterator rbegin() { return get_all().rbegin(); }
            /**
             * @brief Return a reverse iterator to the end.
             * @return reverse_iterator The reverse iterator to the end.
             */
            [[nodiscard]] reverse_iterator rend() { return get_all().rend(); }
            /**
             * @brief Return a const reverse iterator to the beginning.
             * @return const_reverse_iterator The const reverse iterator to the beginning.
             */
            [[nodiscard]] const_reverse_iterator crbegin() const { return get_all().crbegin(); }
            /**
             * @brief Return a const reverse iterator to the end.
             * @return const_reverse_iterator The const reverse iterator to the end.
             */
            [[nodiscard]] const_reverse_iterator crend() const { return get_all().crend(); }

            /**
             * @brief The npos value
             */
            static constexpr size_type npos = -1;

            /**
             * @brief Prepend an element to the section
             * @param element The element to add
             */
            void push_front(const Element& element);
            /**
             * @brief Prepend a section to the section
             * @param section The section to add
             */
            void push_front(const Section& section);
            /**
             * @brief Append an element to the section
             * @param element The element to add
             */
            void push_back(const Element& element);
            /**
             * @brief Append a section to the section
             * @param section The section to add
             */
            void push_back(const Section& section);
            /**
             * @brief Append a property list to the section
             * @param properties The properties of the element
             */
            void push_back(const Properties& properties);
            /**
             * @brief Append a property to the section
             * @param property The property to add
             */
            void push_back(const Property& property);
            /**
             * @brief Append an element list to the section
             * @param elements The elements to add
             */
            void push_back(const ElementList& elements);
            /**
             * @brief Append a section list to the section
             * @param sections The sections to add
             */
            void push_back(const SectionList& sections);
            /**
             * @brief Get the element at an index. To get a section, use at_section()
             * @param index The index of the element
             * @return Element The element at the index
             */
            [[nodiscard]] Element at(size_type index) const;
            /**
             * @brief Get the section at an index. To get an element, use at()
             * @param index The index of the section
             * @return Section The section at the index
             */
            [[nodiscard]] Section at_section(size_type index) const;
            /**
             * @brief Get the element at an index. To get a section, use at_section()
             * @param index The index of the element
             * @return Element The element at the index
             */
            [[nodiscard]] Element& at(size_type index);
            /**
             * @brief Get the section at an index. To get an element, use at()
             * @param index The index of the section
             * @return Section The section at the index
             */
            [[nodiscard]] Section& at_section(size_type index);

            /**
             * @brief Erase an element from the section. Note that this will NOT change the size/index.
             * @param index The index of the element to erase
             */
            void erase(size_type index);
            /**
             * @brief Erase a section from the section, by reading from a section. The section will be erased if it's identical to section. Note that this will NOT change the size/index.
             * @param section The section to erase
             */
            void erase(const Section& section);
            /**
             * @brief Erase an element from the section, by reading from an element. The element will be erased if it's identical to element. Note that this will NOT change the size/index.
             * @param element The element to erase
             */
            void erase(const Element& element);
            /**
             * @brief Find an element in the section
             * @param element The element to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the element
             */
            [[nodiscard]] size_type find(const Element& element, size_type begin = 0, FindParameters params = FindParameters::Search_Tag | FindParameters::Search_Data | FindParameters::Exact) const;
            /**
             * @brief Find a section in the section
             * @param section The section to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the section
             */
            [[nodiscard]] size_type find(const Section& section, size_type begin = 0, FindParameters params = FindParameters::Search_Tag | FindParameters::Search_Data | FindParameters::Exact) const;
            /**
             * @brief Find an element or section in the section
             * @param str The element or section to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the element or section
             */
            [[nodiscard]] size_type find(const string_type& str, size_type begin = 0, FindParameters params = FindParameters::Search_Tag|FindParameters::Search_Data | FindParameters::Exact) const;
            /**
             * @brief Find an element or section in the section
             * @param tag The tag of the element or section to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the element or section
             */
            [[nodiscard]] size_type find(Tag tag, size_type begin = 0, FindParameters params = FindParameters::Search_Tag | FindParameters::Search_Data | FindParameters::Exact) const;
            /**
             * @brief Find an element or section in the section
             * @param properties The properties of the element or section to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the element or section
             */
            [[nodiscard]] size_type find(const Properties& properties, size_type begin = 0, FindParameters params = FindParameters::Search_Properties | FindParameters::Exact) const;
            /**
             * @brief Find an element or section in the section
             * @param property The property of the element or section to find
             * @param begin The index to start searching from
             * @param params Search parameters
             * @return size_type The index of the element or section
             */
            [[nodiscard]] size_type find(const Property& property, size_type begin = 0, FindParameters params = FindParameters::Search_Properties | FindParameters::Exact) const;
            /**
             * @brief Insert an element into the section
             * @param index The index to insert the element
             * @param element The element to insert
             */
            void insert(size_type index, const Element& element);
            /**
             * @brief Insert a section into the section
             * @param index The index to insert the section
             * @param section The section to insert
             */
            void insert(size_type index, const Section& section);
            /**
             * @brief Get the first element of the section
             * @return Element The first element of the section
             */
            [[nodiscard]] Element front() const;
            /**
             * @brief Get the first element of the section
             * @return Element The first element of the section
             */
            [[nodiscard]] Element& front();
            /**
             * @brief Get the last element of the section
             * @return Element The last element of the section
             */
            [[nodiscard]] Element back() const;
            /**
             * @brief Get the last element of the section
             * @return Element The last element of the section
             */
            [[nodiscard]] Element& back();
            /**
             * @brief Get the first section of the section
             * @return Section The first section of the section
             */
            [[nodiscard]] Section front_section() const;
            /**
             * @brief Get the first section of the section
             * @return Section The first section of the section
             */
            Section& front_section();
            /**
             * @brief Get the last section of the section
             * @return Section The last section of the section
             */
            [[nodiscard]] Section back_section() const;
            /**
             * @brief Get the last section of the section
             * @return Section The last section of the section
             */
            [[nodiscard]] Section& back_section();
            /**
             * @brief Get the size of the section
             * @return size_type The size of the section
             */
            [[nodiscard]] size_type size() const;
            /**
             * @brief Clear the section
             */
            void clear();
            /**
             * @brief Check if the section is empty
             * @return bool True if the section is empty, false otherwise
             */
            [[nodiscard]] bool empty() const;
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             */
            explicit Section(string_type tag, const Properties& properties = {}) : tag(std::move(tag)), properties(properties) {};
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             */
            explicit Section(const Tag tag, const Properties& properties = {}) : tag(resolve_tag(tag).first), properties(properties) {};
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param elements The elements of the section
             */
            Section(string_type tag, const Properties& properties, const ElementList& elements) : tag(std::move(tag)), properties(properties) {
                for (const auto& element : elements) this->push_back(element);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param elements The elements of the section
             */
            Section(const Tag tag, const Properties& properties, const ElementList& elements) : tag(resolve_tag(tag).first), properties(properties) {
                for (const auto& element : elements) this->push_back(element);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param args The elements and/or sections of the section
             */
            template <typename... Args>
            explicit Section(const Tag tag, Args&&... args) : tag(resolve_tag(tag).first) {
                (this->push_back(std::forward<Args>(args)), ...);
            }
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param args The elements and/or sections of the section
             */
            template <typename... Args>
            Section(const Tag tag, const Properties& properties, Args&&... args) : tag(resolve_tag(tag).first), properties(properties) {
                (this->push_back(std::forward<Args>(args)), ...);
            }
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param args The elements and/or sections of the section
             */
            template <typename... Args>
            explicit Section(string_type tag, Args&&... args) : tag(std::move(tag)) {
                (this->push_back(std::forward<Args>(args)), ...);
            }
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param args The elements and/or sections of the section
             */
            template <typename... Args>
            Section(string_type tag, const Properties& properties, Args&&... args) : tag(std::move(tag)), properties(properties) {
                (this->push_back(std::forward<Args>(args)), ...);
            }
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param sections The sections of the section
             */
            Section(string_type tag, const Properties& properties, const SectionList& sections) : tag(std::move(tag)), properties(properties) {
                for (const auto& section : sections) this->push_back(section);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param properties The properties of the section
             * @param sections The sections of the section
             */
            Section(const Tag tag, const Properties& properties, const SectionList& sections) : tag(resolve_tag(tag).first), properties(properties) {
                for (const auto& section : sections) this->push_back(section);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param elements The elements of the section
             */
            Section(string_type tag, const ElementList& elements) : tag(std::move(tag)) {
             for (const auto& element : elements) this->push_back(element);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param elements The elements of the section
             */
            Section(const Tag tag, const ElementList& elements) : tag(resolve_tag(tag).first) {
             for (const auto& element : elements) this->push_back(element);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param sections The sections of the section
             */
            Section(string_type tag, const SectionList& sections) : tag(std::move(tag)) {
             for (const auto& section : sections) this->push_back(section);
            };
            /**
             * @brief Construct a new Section object
             * @param tag The tag of the section
             * @param sections The sections of the section
             */
            Section(const Tag tag, const SectionList& sections) : tag(resolve_tag(tag).first) {
             for (const auto& section : sections) this->push_back(section);
            };
            /**
             * @brief Construct a new Section object
             * @param section The section to set
             */
            Section(const Section& section) {
                this->tag = section.tag;
                this->properties = section.properties;
                this->members = section.members;
            }
            /**
             * @brief Construct a new Section object
             */
            Section() = default;
            /**
             * @brief Destroy the Section object
             */
            ~Section() = default;
            /**
             * @brief Set the tag and properties of the section
             * @param tag The tag to assign to the section
             * @param properties The properties to assign to the section tag
             */
            void set(const string_type& tag, const Properties& properties);
            /**
             * @brief Set the tag, id, and classes of the section
             * @param tag The tag of the section
             * @param properties The properties to assign the tag
             */
            void set(Tag tag, const Properties& properties);
            /**
             * @brief Set the tag of the section
             * @param tag The tag of the section
             */
            void set_tag(const string_type& tag);
            /**
             * @brief Set the tag of the section
             * @param tag The tag of the section
             */
            void set_tag(Tag tag);
            /**
             * @brief Set the properties of the section
             * @param properties The properties of the section
             */
            void set_properties(const Properties& properties);
            /**
             * @brief Swap two elements in the section
             * @param index1 The index of the first element
             * @param index2 The index of the second element
             */
            void swap(size_type index1, size_type index2);
            /**
             * @brief Swap two elements in the section
             * @param element1 The first element
             * @param element2 The second element
             */
            void swap(const Element& element1, const Element& element2);
            /**
             * @brief Swap two sections in the section
             * @param section1 The first section
             * @param section2 The second section
             */
            void swap(const Section& section1, const Section& section2);
            /**
             * @brief Get the elements of the section
             * @return ElementList The elements of the section
             */
            [[nodiscard]] ElementList get_elements() const;
            /**
             * @brief Get the sections of the section
             * @return SectionList The sections of the section
             */
            [[nodiscard]] SectionList get_sections() const;

            /**
             * @brief Dump the entire section.
             * @return string_type The section
             */
            [[nodiscard]] string_type get(Formatting formatting = Formatting::None, integer_type tabc = 0) const;
            /**
             * @brief Get the element in the form of a specific type.
             * @return T The element in the form of a specific type
             */
            template <typename T> [[nodiscard]] T get(const Formatting formatting = Formatting::None, const integer_type tabc = 0) const {
                if (std::is_same_v<T, string_type>) {
                    return this->get(formatting, tabc);
                }
                return T(this->get(formatting, tabc));
            }

            /**
             * @brief Get the tag of the section
             * @return string_type The tag of the section
             */
            [[nodiscard]] string_type get_tag() const;
            /**
             * @brief Get the tag of the section in a specific type
             * @return T The tag of the section
             */
            template <typename T> T get_tag() const {
                if (std::is_same_v<T, string_type>) {
                    return this->tag;
                }
                return T(this->tag);
            }
            /**
             * @brief Get the properties of the section
             * @return Properties The properties of the section
             */
            [[nodiscard]] Properties get_properties() const;

            Section& operator=(const Section& section);
            Section& operator+=(const Element& element);
            Section& operator+=(const Section& section);
            bool operator==(const Element& element) const;
            bool operator==(const Section& section) const;
            bool operator!=(const Element& element) const;
            bool operator!=(const Section& section) const;
            variant_t operator[](const int& index) const;
            variant_t& operator[](const int& index);
        private:
            string_type tag{};
            Properties properties{};

            mutable variant_list members{};
            mutable ElementList elements{};
            mutable SectionList sections{};
    };

    /**
     * @brief Create a section container
     * @param args The elements and/or sections of the section
     * @return Section The section container
     */
    template <typename... Args> Section make_section_container(Args&&... args) { return Section(bygg::HTML::Tag::Empty, make_properties(), {std::forward<Args>(args)...}); }
} // namespace bygg