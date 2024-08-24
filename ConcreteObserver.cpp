//
// Created by Leo on 23/08/2024.
//
#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(collection *s): subject(s) {}

void ConcreteObserver::attach() {
    subject->registerObserver(this);
}

void ConcreteObserver::detach() {
    subject->removeObserver(this);
}

void ConcreteObserver::update() {
   NoteNumber= (subject->getBox()).size();
}
