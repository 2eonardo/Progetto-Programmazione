//
// Created by Leo on 23/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_SUBJECT_H
#define PROGETTO_PROGRAMMAZIONE_SUBJECT_H
#include "Observer.h"
class Subject {
    public:
        virtual void registerObserver(Observer * o)=0;

        virtual void removeObserver(Observer * o)=0;

        virtual void notify()=0;

        virtual ~Subject() {}
};
#endif //PROGETTO_PROGRAMMAZIONE_SUBJECT_H
