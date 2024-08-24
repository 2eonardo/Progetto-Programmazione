//
// Created by Leo on 23/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
#define PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
#include "Observer.h"
#include "collection.h"
class ConcreteObserver: public Observer{
public:
    explicit ConcreteObserver(collection *s);

    virtual void update() override;

    virtual void  attach() override;

    void detach() override;

    virtual ~ConcreteObserver() { }

private:
    int NoteNumber;
    collection * subject;
};

#endif //PROGETTO_PROGRAMMAZIONE_CONCRETEOBSERVER_H
