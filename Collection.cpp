//
// Created by Leo on 20/08/2024.
//
#include "Collection.h"
#include <algorithm>

int Collection::count =1;

Collection::Collection(string t): title(t){
    if (title.empty()){
        title = "Collection " + to_string(count);
        count++;
    }
}

void Collection::addNote(Note* b) {
    box.push_back(b);
    b->addDirectory(this);
    notify();
}

void Collection::removeNote(Note *n) {
    n->removeDirectory(this);
    this->deleteNote(n);
}

void Collection::deleteNote(Note *n) {
    auto itr = find(box.begin(), box.end(), n);
    box.erase(itr);
    notify();
}

Note * Collection::findNote(string t) const {
    Note * n=NULL;
    int i =0;
    for (; (i<box.size()) && (box.at(i)->getTitle().compare(t)!=0); i++);
    if (i!=box.size())
        n = box.at(i);
    return n;
}

const vector<Note *> &Collection::getBox() const {
    return box;
}

void Collection::registerObserver(Observer * o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collection::notify() {
    for(auto itr : observers)
        itr->update();
}

const string &Collection::getTitle() const {
    return title;
}

void Collection::setTitle(const string &title) {
    Collection::title = title;
}
