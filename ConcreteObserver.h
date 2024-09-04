//
// Created by Leo on 23/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
#define PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
#include "Observer.h"
#include "Collection.h"
class ConcreteObserver: public Observer{
    public:
        explicit ConcreteObserver(Collection *s);

        int getNoteNumber() const;

        virtual void update() override;

        virtual void  attach() override;

        void detach() override;

        virtual ~ConcreteObserver() ;

    private:
        int NoteNumber;
        Collection * subject;
};

#endif //PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
