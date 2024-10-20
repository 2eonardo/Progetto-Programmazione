//
// Created by Leo on 20/08/2024.
//
#include "Collection.h"


int Collection::count =1;

Collection::Collection(const string &t): title(t){
    if (title.empty()){
        title = "Collection " + to_string(count);
        count++;
    }
}

void Collection::addNote(const string &t, const string &te, bool b, bool i) {
    Note n(t, te, b, i);
    notes.push_back(n);
    notify();
}

bool Collection::removeNote(int n) {
    bool deleted= false;
    if ( !notes[n].isBlocked() && n<notes.size()){
        deleted=true;
        notes.erase(notes.begin()+n);
        notify();
    }
    return deleted;
}
bool Collection::modifyTitleNote(int n, const string &t) {
    if(!notes[n].isBlocked() && n<notes.size())
    {
        notes[n].setTitle(t);
        return true;
    }
    else
        return false;
}

bool Collection::modifyTextNote(int n, const string &te) {
    if(!notes[n].isBlocked() && n<notes.size())
    {
        notes[n].setText(te);
        return true;
    }
    else
        return false;
}

bool Collection::setBlockedNote(int n, bool b) {
    if(n<notes.size()){
        notes[n].setBlocked(b);
        return true;
    }
    return false;
}

bool Collection::setImportantNote(int n, bool i) {
    if(n<notes.size()){
        notes[n].setImportant(i);
        return true;
    }
    return false;
}

const vector<Note> Collection::findNote( const string &t) const {
    vector<Note> NoteTrovate;
    for(auto itr: notes){
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
        itr->update(notes.size());
}

const string &Collection::getTitle() const {
    return title;
}

void Collection::setTitle(const string &title) {
    Collection::title = title;
}

const Note & Collection::readNote(int n) const {
    return notes.at(n);
}
