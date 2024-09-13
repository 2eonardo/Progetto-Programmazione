//
// Created by Leo on 23/08/2024.
//

#ifndef PROGETTO_PROGRAMMAZIONE_COLLECTIONOBSERVER_H
#define PROGETTO_PROGRAMMAZIONE_COLLECTIONOBSERVER_H
#include "Observer.h"
#include "Collection.h"
class CollectionObserver: public Observer{
    public:
        explicit CollectionObserver(Collection *s);

        int getNoteNumber() const;

        virtual void update(int n) override;

        virtual void  attach() override;

        void detach() override;

        virtual ~CollectionObserver() ;

    private:
        int NoteNumber;
        Collection * subject;
};

#endif //PROGETTO_PROGRAMMAZIONE_COLLECTIONOBSERVER_H
