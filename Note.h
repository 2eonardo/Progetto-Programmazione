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
        explicit Note(const string &t="", const string &te="", bool b=false, bool i= false);
        bool operator==(const Note &rhs) const;
        bool operator!=(const Note &rhs) const;
        const string &getTitle() const;
        void setTitle(const string &title);
        const string &getText() const;
        void setText(const string &text);
        bool isBlocked() const;
        void setBlocked(bool blocked);
        bool isImportant() const;
        void setImportant(bool important);

private:
        string title;
        string text;
        bool blocked;
        bool important;
        static int count ;
};

#endif //PROGETTO_PROGRAMMAZIONE_NOTE_H
