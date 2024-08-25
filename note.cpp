//
// Created by Leo on 19/08/2024.
//
#include "note.h"
#include "collection.h"
#include <iostream>
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

bool note::setTitle(const string &title) {
    if (!blocked){
        note::title = title;
        return true;
    }
    else
        return false;
}

const string &note::getText() const {
    return text;
}

bool note::setText(const string &text) {
    if (!blocked){
        note::text = text;
        return true;
    }
    else
        return false;
}

bool note::isBlocked() const {
    return blocked;
}

void note::setBlocked(bool blocked) {
    note::blocked = blocked;
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
