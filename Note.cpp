//
// Created by Leo on 19/08/2024.
//
#include "Note.h"
#include "Collection.h"
int Note::count = 1;

Note::Note(const string &t ,const string &te, bool b, bool i ): title(t), text(te), blocked(b), important(i) {
    if (title.empty()){
        title = "Note " + to_string(count);
        count ++;
    }
}

const string &Note::getTitle() const {
    return title;
}

const string &Note::getText() const {
    return text;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}

void Note::setTitle(const string &title) {
    Note::title = title;
}

void Note::setText(const string &text) {
    Note::text = text;
}

bool Note::isImportant() const {
    return important;
}

void Note::setImportant(bool important) {
    Note::important = important;
}
