//
// Created by Leo on 19/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_NOTE_H
#define PROGETTO_PROGRAMMAZIONE_NOTE_H
#include <string>
#include <list>

using namespace std;

class collection;

class note {
    public:
        explicit note(string t="", string te="", bool b=false);

        const list<collection *> &getDirectory() const;

        void setDirectory(const list<collection *> &directory);

        const string &getTitle() const;

        bool setTitle(const string &title);

        const string &getText() const;

        bool setText(const string &text);

        bool isBlocked() const;

        void setBlocked(bool blocked);

        virtual ~note();

    private:
        string title;
        string text;
        bool blocked;
        static int count ;
        list<collection*> directory;

};

#endif //PROGETTO_PROGRAMMAZIONE_NOTE_H
