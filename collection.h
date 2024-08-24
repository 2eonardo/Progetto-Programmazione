//
// Created by Leo on 20/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#include "note.h"
#include <string>
#include <list>
#include <vector>
#include "Subject.h"
using namespace std;
class collection: public Subject{
public:
    explicit collection(string t="");

    void AddNote(note* n);

    void DeleteNote(note* n );

    const vector<note *> &getBox() const;

    void registerObserver(Observer * o) override;

    void removeObserver(Observer * o) override;

    virtual void notify() override;
private:
    string title;
    vector<note*> box;
    static int count;
    list<Observer *> observers;
};
#endif //PROGETTO_PROGRAMMAZIONE_COLLECTION_H
