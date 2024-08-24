//
// Created by Leo on 23/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_OBSERVER_H
#define PROGETTO_PROGRAMMAZIONE_OBSERVER_H
class Observer{
public:
    virtual void update()=0;

    virtual void attach()=0;

    virtual void detach()=0;

    virtual ~Observer() {}
};
#endif //PROGETTO_PROGRAMMAZIONE_OBSERVER_H
