//
// Created by Leo on 20/08/2024.
//
#include "Collection.h"
#include <algorithm>

int Collection::count =1;

Collection::Collection(const string &t): title(t){
    if (title.empty()){
        title = "Collection " + to_string(count);
        count++;
    }
}

void Collection::addNote(const Note &b) {
    box.push_back(b);
    notify();
}

bool Collection::removeNote(const Note &n) {
    bool deleted= false;
    auto itr = find(box.begin(), box.end(), n);
    if (itr!= box.end() && !n.isBlocked())
        deleted=true;
    return deleted;
}
bool Collection::modifyTitleNote(Note &n, const string &t) {
    if(!n.isBlocked())
    {
        n.setTitle(t);
        return true;
    }
    else
        return false;
}

bool Collection::modifyTextNote(Note &n, const std::string &te) {
    if(!n.isBlocked())
    {
        n.setText(te);
        return true;
    }
    else
        return false;
}

void Collection::modifyBlockedNote(Note &n, bool b) {
    n.setBlocked(b);
}

void Collection::modifyImportantNote(Note &n, bool i) {
    n.setImportant(i);
}

vector<Note> Collection::findNote( const string &t) const {
    vector<Note> NoteTrovate;
    for(auto itr: box){
       if(((itr.getTitle()).find(t, 0 ))!=-1)
        NoteTrovate.push_back(itr);
    }
    return NoteTrovate;
}

void Collection::registerObserver(Observer * o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collection::notify() {
    for(auto itr : observers)
        itr->update(box.size());
}

const string &Collection::getTitle() const {
    return title;
}

void Collection::setTitle(const string &title) {
    Collection::title = title;
}
