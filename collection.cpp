//
// Created by Leo on 20/08/2024.
//
#include "collection.h"
#include <algorithm>
int collection::count =0;
collection::collection(string t): title(t){
    if (title.empty()){
        title = "Collection " + to_string(count);
        count++;
    }
}

void collection::AddNote(note* b) {
    box.push_back(b);
    notify();
}
void collection::DeleteNote(note *n) {
    auto itr = find(box.begin(), box.end(), n);
    box.erase(itr);
    notify();
}

const vector<note *> &collection::getBox() const {
    return box;
}

void collection::registerObserver(Observer * o) {
    observers.push_back(o);
}

void collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void collection::notify() {
    for(auto itr : observers)
        itr->update();
}
