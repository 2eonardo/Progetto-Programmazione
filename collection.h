//
// Created by Leo on 20/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#define PROGETTO_PROGRAMMAZIONE_COLLECTION_H
#include "note.h"
#include <string>
#include <list>
#include <vector>
using namespace std;
class collection {
public:
    collection(string t="");
    void AddNote(note* n);
    void DeleteNote(note* n );
private:
    string title;
    vector<note*> box;
    static int count;
};
#endif //PROGETTO_PROGRAMMAZIONE_COLLECTION_H
