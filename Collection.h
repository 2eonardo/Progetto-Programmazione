//
// Created by Leo on 20/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#include "Note.h"
#include <string>
#include <list>
#include <vector>
#include "Subject.h"
using namespace std;
class Collection: public Subject{
    public:
        explicit Collection(const string &t="");
        void addNote(const string &t = "", const string &te = "", bool b= false, bool i= false);
        bool removeNote(int n );
        bool modifyTitleNote(int n, const string &t);
        bool modifyTextNote(int n, const string &te);
        bool setBlockedNote(int n, bool b);
        bool setImportantNote(int n, bool i);
        const vector<Note> findNote(const string &t) const;
        const string &getTitle() const;
        const Note & readNote(int n) const;
        void setTitle(const string &title);
        void registerObserver(Observer * o) override;
        void removeObserver(Observer * o) override;
        virtual void notify() override;

    private:
        string title;
        vector<Note> notes;
        static int count;
        list<Observer *> observers;
};
#endif //PROGETTO_PROGRAMMAZIONE_COLLECTION_H
