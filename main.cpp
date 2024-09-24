#include <iostream>

#include "Collection.h"
#include "CollectionObserver.h"

void stampa(const vector<Note> &c){
    for(auto itr : c){
        cout<<itr.getTitle()<<" "<< itr.getText() << endl;
    }
}

int main() {
    Collection c;
    c.addNote("sport, calcio", "Forza Fiorentina");
    c.addNote("Sport, tennis", "Sinner sei il numero uno");
    c.addNote("Cibo da asporto", "Pizza, panino ecc.");
    cout << c.getTitle() << endl;
    c.setTitle("Sport");
    cout << c.getTitle() << endl;
    CollectionObserver o(&c);
    c.addNote();
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    c.addNote();
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    stampa(c.getNotes());
    cout << "Trovato: " << endl;
    stampa(c.findNote("sport"));
    c.modifyTitleNote(2, "Sport, nuoto");
    c.modifyTextNote(2, "La Pellegrini si è ritirata");
    c.modifyBlockedNote(0, true);
    c.modifyTitleNote(0, "Sport, nuoto");
    c.modifyTextNote(0, "La Pellegrini si è ritirata");
    cout << "Modificato: " << endl;
    stampa(c.getNotes());
    c.removeNote(4);
    c.removeNote(0);
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    c.removeNote(3);
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    cout << "Eliminato: " << endl;
    stampa(c.getNotes());
    return 0;
}
