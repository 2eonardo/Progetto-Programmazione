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

    const string &getTitle() const;

    void setTitle(const string &title);

    const string &getText() const;

    void setText(const string &text);

    bool isBlocked() const;

    void setBlocked(bool blocked);

    static int getCount();

    static void setCount(int count);

private:
    string title;
    string text;
    bool blocked;
    static int count ;
};

#endif //PROGETTO_PROGRAMMAZIONE_NOTE_H
