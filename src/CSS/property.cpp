/*
 * bygg - Component-based HTML/CSS builder for C++
 *
 * Copyright 2024 - Jacob Nilsson & contributors
 * SPDX-License-Identifier: MIT
 */

#include <bygg/CSS/property.hpp>

bygg::string_type bygg::CSS::Property::get_key() const {
    return this->property.first;
}

bygg::string_type bygg::CSS::Property::get_value() const {
    return this->property.second;
}

std::pair<bygg::string_type, bygg::string_type> bygg::CSS::Property::get_pair() const {
    return this->property;
}

bygg::string_type bygg::CSS::Property::get() const {
    return this->get_key() + ": " + this->get_value() + ";";
}

void bygg::CSS::Property::set_key(const bygg::string_type& key) {
    this->property.first = key;
}

void bygg::CSS::Property::set_value(const bygg::string_type& value) {
    this->property.second = value;
}

void bygg::CSS::Property::set(const bygg::string_type& key, const bygg::string_type& value) {
    this->property = std::make_pair(key, value);
}

bygg::CSS::Property& bygg::CSS::Property::operator=(const bygg::CSS::Property& property) {
    this->set(property.get_pair().first, property.get_pair().second);
    return *this;
}

bool bygg::CSS::Property::operator==(const bygg::CSS::Property& property) const {
    return this->get_pair() == property.get_pair();
}

bool bygg::CSS::Property::operator!=(const bygg::CSS::Property& property) const {
    return this->get_pair() != property.get_pair();
}