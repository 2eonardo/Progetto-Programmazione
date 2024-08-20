//
// Created by Leo on 19/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_NOTE_H
#define PROGETTO_PROGRAMMAZIONE_NOTE_H

#include <string>

using namespace std;

class note {
public:
explicit note(string t="", string te="", bool b=false);

private:
    string title;
    string text;
    bool blocked;
    static int count ;
};

#endif //PROGETTO_PROGRAMMAZIONE_NOTE_H
