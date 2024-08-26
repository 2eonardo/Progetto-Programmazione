//
// Created by Leo on 19/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_NOTE_H
#define PROGETTO_PROGRAMMAZIONE_NOTE_H
#include <string>
#include <list>

using namespace std;

class Collection;

class Note {
    public:
        explicit Note(string t="", string te="", bool b=false);

        const list<Collection *> &getDirectory() const;

        const string &getTitle() const;

        bool setTitle(const string &title);

        const string &getText() const;

        bool setText(const string &text);

        bool isBlocked() const;

        void setBlocked(bool blocked);

        void RemoveDirectory(Collection * c);

        void AddDirectory(Collection * c);

        virtual ~Note();

    private:
        string title;
        string text;
        bool blocked;
        static int count ;
        list<Collection*> directory;

};

#endif //PROGETTO_PROGRAMMAZIONE_NOTE_H
