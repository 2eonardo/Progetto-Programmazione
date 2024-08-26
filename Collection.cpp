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

void Collection::AddNote(Note* b) {
    box.push_back(b);
    b->AddDirectory(this);
    notify();
}

void Collection::DeleteNote(Note *n) {
    auto itr = find(box.begin(), box.end(), n);
    box.erase(itr);
    n->RemoveDirectory(this);
    notify();
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
