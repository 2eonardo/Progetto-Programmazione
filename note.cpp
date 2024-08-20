//
// Created by Leo on 19/08/2024.
//
#include "note.h"
int note::count = 0;
note::note(std::string t , std::string te, bool b ): title(t), text(te), blocked(b) {
    if (this->title == ""){
        this->title = "Note " + to_string(count);
        count ++;
    }
}

const string &note::getTitle() const {
    return title;
}

void note::setTitle(const string &title) {
    note::title = title;
}

const string &note::getText() const {
    return text;
}

void note::setText(const string &text) {
    note::text = text;
}

bool note::isBlocked() const {
    return blocked;
}

void note::setBlocked(bool blocked) {
    note::blocked = blocked;
}

int note::getCount() {
    return count;
}

void note::setCount(int count) {
    note::count = count;
}
