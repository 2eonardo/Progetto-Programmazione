//
// Created by Leo on 02/09/2024.
//
#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../ConcreteObserver.h"
class NoteFixture: public ::testing::Test{
    protected:
        Note * n;
        Collection * c;
        ConcreteObserver * o;

        void SetUp() override{
            n= new Note("Star Wars", "Che bel personaggio l'Imperatore");
            c= new Collection("Film");
            o= new ConcreteObserver(c);
        }

        void TearDown() override{
            delete n;
            delete o;
            delete c;
        }
};


TEST_F(NoteFixture, NoteManagementTest){
    c->addNote(n);
    EXPECT_EQ(c->findNote("Star Wars"), n);
    EXPECT_EQ((n->getDirectory()).size(), 1);
    c->removeNote(n);
    EXPECT_EQ(c->findNote("Star Wars"), nullptr);
    EXPECT_EQ((n->getDirectory()).size(), 0);
}

TEST_F(NoteFixture, TestObserver){
    c->addNote(n);
    EXPECT_EQ(o->getNoteNumber(), 1);
    c->removeNote(n);
    EXPECT_EQ(o->getNoteNumber(), 0);
}

TEST_F(NoteFixture, DetachAttachTest){
    c->addNote(n);
    EXPECT_EQ(o->getNoteNumber(), 1);
    o->detach();
    c->removeNote(n);
    EXPECT_EQ(o->getNoteNumber(), 1);
    o->attach();
    c->addNote(n);
    EXPECT_EQ(o->getNoteNumber(), 1);
    c->removeNote(n);
    EXPECT_EQ(o->getNoteNumber(), 0);
}


