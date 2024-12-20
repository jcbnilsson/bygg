/*
 * bygg - Component-based HTML/CSS builder for C++
 *
 * Copyright 2024 - Jacob Nilsson & contributors
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <string>
#include <bygg/types.hpp>
#include <bygg/HTML/tag.hpp>
#include <bygg/CSS/property.hpp>
#include <bygg/CSS/properties.hpp>
#include <bygg/CSS/formatting_enum.hpp>

namespace bygg::CSS {
    /**
     * @brief A class to represent the properties of a CSS element
     */
    class Element {
            std::pair<string_type, bygg::CSS::Properties> element{};
        public:
            using iterator = bygg::CSS::Properties::iterator;
            using const_iterator = bygg::CSS::Properties::const_iterator;
            using reverse_iterator = bygg::CSS::Properties::reverse_iterator;
            using const_reverse_iterator = bygg::CSS::Properties::const_reverse_iterator;

            /**
             * @brief Return an iterator to the beginning.
             * @return iterator The iterator to the beginning.
             */
            iterator begin() { return element.second.begin(); }
            /**
             * @brief Return an iterator to the end.
             * @return iterator The iterator to the end.
             */
            iterator end() { return element.second.end(); }
            /**
             * @brief Return a const_iterator to the beginning.
             * @return const_iterator The const_iterator to the beginning.
             */
            [[nodiscard]] const_iterator begin() const { return element.second.begin(); }
            /**
             * @brief Return a const_iterator to the end.
             * @return const_iterator The const_iterator to the end.
             */
            [[nodiscard]] const_iterator end() const { return element.second.end(); }
            /**
             * @brief Return a const iterator to the beginning.
             * @return const_iterator The const iterator to the beginning.
             */
            [[nodiscard]] const_iterator cbegin() const { return element.second.cbegin(); }
            /**
             * @brief Return a const iterator to the end.
             * @return const_iterator The const iterator to the end.
             */
            [[nodiscard]] const_iterator cend() const { return element.second.cend(); }
            /**
             * @brief Return a reverse iterator to the beginning.
             * @return reverse_iterator The reverse iterator to the beginning.
             */
            reverse_iterator rbegin() { return element.second.rbegin(); }
            /**
             * @brief Return a reverse iterator to the end.
             * @return reverse_iterator The reverse iterator to the end.
             */
            reverse_iterator rend() { return element.second.rend(); }
            /**
             * @brief Return a const reverse iterator to the beginning.
             * @return const_reverse_iterator The const reverse iterator to the beginning.
             */
            [[nodiscard]] const_reverse_iterator crbegin() const { return element.second.crbegin(); }
            /**
             * @brief Return a const reverse iterator to the end.
             * @return const_reverse_iterator The const reverse iterator to the end.
             */
            [[nodiscard]] const_reverse_iterator crend() const { return element.second.crend(); }

            /**
             * @brief The npos value
             */
            static constexpr bygg::size_type npos = -1;

            /**
             * @brief Construct a new Element object
             * @param tag The tag of the element
             * @param properties The properties of the element
             */
            Element(const string_type& tag, const bygg::CSS::Properties& properties) : element(std::make_pair(tag, properties)) {};
            Element(HTML::Tag tag, const bygg::CSS::Properties& properties) : element(std::make_pair(resolve_tag(tag).first, properties)) {};
            /**
             * @brief Construct a new Element object
             * @param element The element to set
             */
            Element(const Element& element) = default;

            /**             *
             * @brief Construct a new Element object
             * @param tag The tag of the element
             * @param args The properties of the element
             */
            template <typename... Args> explicit Element(const string_type& tag, Args&&... args) :
                element(std::make_pair(tag, bygg::CSS::Properties(std::forward<Args>(args)...))) {};

            /**
             * @brief Construct a new Element object
             * @param tag The tag of the element
             * @param args The properties of the element
             */
            template <typename... Args> explicit Element(HTML::Tag tag, Args&&... args) :
                element(std::make_pair(resolve_tag(tag).first, bygg::CSS::Properties(std::forward<Args>(args)...))) {};
            /**
             * @brief Construct a new Element object
             */
            Element() = default;
            /**
             * @brief Destroy the Element object
             */
            ~Element() = default;

            /**
             * @brief Prepend a property to the element
             * @param property The property to push
             */
            void push_front(const Property& property);
            /**
             * @brief Append a property to the element
             * @param property The property to push
             */
            void push_back(const Property& property);
            /**
             * @brief Insert a property into the element
             * @param index The index to insert the property
             * @param property The property to insert
             */
            void insert(size_type index, const Property& property);
            /**
             * @brief Erase a property from the element
             * @param index The index of the property to erase
             */
            void erase(size_type index);
            /**
             * @brief Find a property in the element
             * @param property The property to find
             * @return size_type The index of the property
             */
            [[nodiscard]] bygg::size_type find(const Property &property) const;
            /**
             * @brief Get the property at an index
             * @param index The index of the property
             * @return Property The property at the index
             */
            [[nodiscard]] Property& at(size_type index);
            /**
             * @brief Get the property at an index
             * @param index The index of the property
             * @return Property The property at the index
             */
            [[nodiscard]] Property at(size_type index) const;
            /**
             * @brief Find a property in the element
             * @param str The property to find
             * @return size_type The index of the property
             */
            [[nodiscard]] size_type find(const string_type& str) const;
            /**
             * @brief Swap two properties in the element
             * @param index1 The index of the first property
             * @param index2 The index of the second property
             */
            void swap(size_type index1, size_type index2);
            /**
             * @brief Swap two properties in the element
             * @param property1 The first property
             * @param property2 The second property
             */
            void swap(const Property& property1, const Property& property2);
            /**
             * @brief Get the first property of the element
             * @return Property The first property of the element
             */
            [[nodiscard]] Property& front();
            /**
             * @brief Get the last property of the element
             * @return Property The last property of the element
             */
            [[nodiscard]] Property& back();
            /**
             * @brief Get the first property of the element
             * @return Property The first property of the element
             */
            [[nodiscard]] Property front() const;
            /**
             * @brief Get the last property of the element
             * @return Property The last property of the element
             */
            [[nodiscard]] Property back() const;
            /**
             * @brief Get the size of the element
             * @return size_type The size of the element
             */
            [[nodiscard]] size_type size() const;
            /**
             * @brief Clear the element
             */
            void clear();
            /**
             * @brief Check if the element is empty
             * @return bool True if the element is empty, false otherwise
             */
            [[nodiscard]] bool empty() const;
            /**
             * @brief Set the properties of the element
             * @param tag The tag of the element
             * @param properties The properties to set
             */
            void set(const string_type& tag, const bygg::CSS::Properties& properties);
            /**
             * @brief Set the properties of the element
             * @param tag The tag of the element
             * @param properties The properties to set
             */
            void set(HTML::Tag tag, const bygg::CSS::Properties& properties);
            /**
             * @brief Set the tag of the element
             * @param tag The tag to set
             */
            void set_tag(const string_type& tag);
            /**
             * @brief Set the tag of the element
             * @param tag The tag to set
             */
            void set_tag(HTML::Tag tag);
            /**
             * @brief Set the properties of the element
             * @param properties The properties to set
             */
            void set_properties(const bygg::CSS::Properties& properties);
            /**
             * @brief Get the element
             * @return std::pair<string_type, bygg::CSS::Properties> The element
             */
            [[nodiscard]] string_type get(Formatting formatting = Formatting::None, integer_type tabc = 0) const;
            /**
             * @brief Get the element in the form of a specific type.
             * @return T The element in the form of a specific type
             */
            template <typename T> T get(const Formatting formatting = Formatting::None, const integer_type tabc = 0) const {
                if (std::is_same_v<T, string_type>) {
                    return this->get(formatting, tabc);
                }
                return T(this->get(formatting, tabc));
            }
            /**
             * @brief Get the tag of the element
             * @return string_type The tag of the element
             */
            [[nodiscard]] string_type get_tag() const;
            /**
             * @brief Get the tag of the element in a specific type
             * @return T The tag of the element
             */
            template <typename T> T get_tag() const {
                if (std::is_same_v<T, string_type>) {
                    return this->element.first;
                }
                return T(this->element.first);
            }
            /**
             * @brief Get the properties of the element
             * @return bygg::CSS::Properties The properties of the element
             */
            [[nodiscard]] bygg::CSS::Properties get_properties() const;

            Element& operator=(const Element& element);
            Element& operator=(const std::pair<string_type, bygg::CSS::Properties>& element);
            Element& operator+=(const Property& property);
            Property& operator[](const size_type& index);
            bool operator==(const Element& element) const;
            bool operator!=(const Element& element) const;
    };

    template <typename... Args> Element make_element(Args&&... args) { return Element(std::forward<Args>(args)...); }
} // namespace bygg
