//
// Created by Leo on 19/08/2024.
//
#include "note.h"
int note::count = 0;
note::note(std::string t , std::string te, bool b ): title(t), text(te), blocked(b) {
    if (this->title == ""){
        this->title = "Note " + to_string(count);
        count ++;
    }
}
