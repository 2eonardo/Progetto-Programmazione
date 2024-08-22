//
// Created by Leo on 20/08/2024.
//
#include "collection.h"
#include <algorithm>
int collection::count =0;
collection::collection(string t): title(t){
    if (title.empty()){
        title = "Collection " + to_string(count);
    }
}

void collection::AddNote(note* b) {
    box.push_back(b);
}
void collection::DeleteNote(note *n) {
    auto itr = find(box.begin(), box.end(), n);
    box.erase(itr);
}