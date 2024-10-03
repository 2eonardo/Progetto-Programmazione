#include <iostream>

#include "Collection.h"
#include "CollectionObserver.h"

void printNote(const Note &n){
    cout<< n.getTitle() << "  " << n.getText() << endl;
}

void printCollection(const Collection &c, int n) {
    for(int i=0; i<n; i++){
        printNote(c.readNote(i));
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
    printCollection(c, o.getNoteNumber());
    cout << "Trovato: " << endl;
    for (auto itr : c.findNote("sport")){
        cout<< itr.getTitle() << "  " << itr.getText() << endl;
    }
    c.modifyTitleNote(2, "Sport, nuoto");
    c.modifyTextNote(2, "La Pellegrini si è ritirata");
    c.modifyBlockedNote(0, true);
    c.modifyTitleNote(0, "Sport, nuoto");
    c.modifyTextNote(0, "La Pellegrini si è ritirata");
    cout << "Modificato: " << endl;
    printNote(c.readNote(0));
    printNote(c.readNote(2));
    c.removeNote(4);
    c.removeNote(0);
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    c.removeNote(3);
    cout << "Numero Note: " << o.getNoteNumber() << endl;
    cout << "Eliminato: " << endl;
    printCollection(c, o.getNoteNumber());
    return 0;
}
