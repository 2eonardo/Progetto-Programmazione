//
// Created by Leo on 19/08/2024.
//
#include "note.h"
#include "collection.h"
int note::count = 0;
note::note(std::string t , std::string te, bool b ): title(t), text(te), blocked(b) {
    if (title.empty()){
        title = "Note " + to_string(count);
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
void note::DeleteNote() {
    note::~note();
}

note::~note() {
    for(auto itr : directory)
        itr->DeleteNote(this);
}

const list<collection *> &note::getDirectory() const {
    return directory;
}

void note::setDirectory(const list<collection *> &directory) {
    note::directory = directory;
}
