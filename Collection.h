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
        explicit Collection(string t="");

        void addNote(Note* b);

        void removeNote(Note* n );

        void deleteNote(Note* n);

        const vector<Note *> &getBox() const;

        const string &getTitle() const;

        void setTitle(const string &title);

        void registerObserver(Observer * o) override;

        void removeObserver(Observer * o) override;

        virtual void notify() override;

    private:
        string title;
        vector<Note*> box;
        static int count;
        list<Observer *> observers;
};
#endif //PROGETTO_PROGRAMMAZIONE_COLLECTION_H
