//
// Created by Leo on 23/08/2024.
//
#include "CollectionObserver.h"

CollectionObserver::CollectionObserver(Collection *s): subject(s) {
    subject->registerObserver(this);
}

CollectionObserver::~CollectionObserver() {
    subject->removeObserver(this);
}

void CollectionObserver::attach() {
    subject->registerObserver(this);
}

void CollectionObserver::detach() {
    subject->removeObserver(this);
}

void CollectionObserver::update(int n) {
    NoteNumber=n;
}

int CollectionObserver::getNoteNumber() const {
    return NoteNumber;
}
