//
// Created by Leo on 19/08/2024.
//
#include "Note.h"
#include "Collection.h"
int Note::count = 1;

Note::Note(string t , string te, bool b ): title(t), text(te), blocked(b) {
    if (title.empty()){
        title = "Note " + to_string(count);
        count ++;
    }
}

const string &Note::getTitle() const {
    return title;
}

bool Note::setTitle(const string &title) {
    if (!blocked){
        Note::title = title;
        return true;
    }
    else
        return false;
}

const string &Note::getText() const {
    return text;
}

bool Note::setText(const string &text) {
    if (!blocked){
        Note::text = text;
        return true;
    }
    else
        return false;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}

Note::~Note() {
    for(auto itr : directory)
        itr->deleteNote(this);
}

const list<Collection *> &Note::getDirectory() const {
    return directory;
}

void Note::removeDirectory(Collection *c) {
    directory.remove(c);
}

void Note::addDirectory(Collection *c) {
    directory.push_back(c);
}
