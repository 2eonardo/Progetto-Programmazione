#include <iostream>

#include "Collection.h"
#include "ConcreteObserver.h"
void printCollection(const Collection &c){
    for (auto itr: c.getBox())
        cout<< itr->getTitle() << " : " << itr->getText() << endl;
};

int main() {
    Note * nota1= new Note;
    Note * nota2= new Note("Calcio");
    Note * nota3= new Note("Tennis", "Speriamo Sinner vinca un'altro grande slam");
    Note * nota4= new Note("Ping-Pong", "Ci ho giocato tutta l'estate, mi sono divertito tanto :)", true);
    Note * nota5=new Note("", "Carne grigliata: 2 bistecche, 20 salsicce");
    Note * nota6 = new Note;
    Collection collezione1;
    Collection collezione2("Importanti");
    Collection collezione3;
    ConcreteObserver observer1(&collezione1);
    ConcreteObserver observer2(&collezione2);
    collezione2.addNote(nota2);
    //stampa elementi collezione
    printCollection(collezione2);
    collezione2.addNote(nota3);
    //stampa elementi collezione
    printCollection(collezione2);
    collezione2.addNote(nota4);
    //stampa elementi collezione
    printCollection(collezione2);
    collezione2.removeNote(nota3);
    //stampa elementi collezione
    printCollection(collezione2);
    collezione2.addNote(nota5);
    //stampa elementi collezione
    printCollection(collezione2);
    // trova note
    cout<<(collezione2.findNote("Note 2"))->getTitle()<< ", " <<"Trovato"<< endl;
    collezione1.addNote(nota1);
    //stampa elementi collezione
    printCollection(collezione1);
    collezione1.addNote(nota5);
    //stampa elementi collezione
    printCollection(collezione1);
    collezione1.addNote(nota6);
    //stampa elementi collezione
    printCollection(collezione1);
    collezione1.removeNote(nota5);
    //stampa elementi collezione
    printCollection(collezione1);
    delete nota6;
    //stampa elementi collezione
    printCollection(collezione1);
    //provare a modificare le note
    nota1->setTitle("Cose da fare");
    nota4->setTitle("Table Tennis");
    nota1->setText("Consegnare pacco");
    nota4->setText("Ho bisogno di una nuova racchetta");
    //stampa nota 1 e 4
    cout << nota1->getTitle() << " : " << nota1->getText() << endl;
    cout << nota4->getTitle() << " : " << nota4->getText() << endl;
    nota4->setBlocked(false);
    nota4->setTitle("Table Tennis");
    nota4->setText("Ho bisogno di una nuova racchetta");
    //Stampa nota4
    cout << nota4->getTitle() << " : " << nota4->getText() << endl;
    delete nota1;
    delete nota2;
    delete nota3;
    delete nota4;
    delete nota5;
    return 0;
}
