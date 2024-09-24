//
// Created by Leo on 02/09/2024.
//
#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../CollectionObserver.h"
class NoteFixture: public ::testing::Test{
protected:
    Collection * c;
    CollectionObserver * o;

    void SetUp() override{
        c= new Collection("Film");
        o= new CollectionObserver(c);
        c->addNote("Star Wars", "L'imperatore Palpatine non è morto");
        c->addNote("Topolino", "A breve uscirà un nuovo fumetto");
        c->addNote("Storm trupper", "Dovrebbero aggiustare la mira", true);
    }

    void TearDown() override{
        delete o;
        delete c;
    }
};

TEST_F(NoteFixture, ModifyNoteTest){
    EXPECT_EQ(c->modifyTitleNote(1, "Anakin Skywalker"), true);
    EXPECT_EQ(c->modifyTextNote(1, "che storia triste"), true);
    c->modifyImportantNote(1, true);
    EXPECT_EQ(c->getNotes().at(1).isImportant(), true);
    c->modifyBlockedNote(1,true);
    EXPECT_EQ(c->getNotes().at(1).isBlocked(), true);
}

TEST_F(NoteFixture, BlockedTest){
    EXPECT_EQ(c->modifyTitleNote(2, "Anakin Skywalker"), false);
    EXPECT_EQ(c->modifyTextNote(2, "che storia triste"),false);
    EXPECT_EQ(c->removeNote(2), false);
}
TEST_F(NoteFixture, FindNoteTest){
    EXPECT_EQ(c->findNote("St").size(), 2);
    EXPECT_EQ(c->findNote("Star").size(), 1);
}

TEST_F(NoteFixture, ObserverTest){
    c->addNote("Test");
    EXPECT_EQ(o->getNoteNumber(), 4);
    c->addNote("Test");
    EXPECT_EQ(o->getNoteNumber(), 5);
    c->removeNote(1);
    EXPECT_EQ(o->getNoteNumber(), 4);
    c->removeNote(0);
    EXPECT_EQ(o->getNoteNumber(), 3);
}

TEST_F(NoteFixture, TestAttachDetachObserver){
    EXPECT_EQ(o->getNoteNumber(), 3);
    o->detach();
    c->addNote("Test");
    EXPECT_EQ(o->getNoteNumber(), 3);
    c->removeNote(1);
    EXPECT_EQ(o->getNoteNumber(), 3);
    o->attach();
    c->addNote("Test");
    EXPECT_EQ(o->getNoteNumber(), 4);
    c->removeNote(0);
    EXPECT_EQ(o->getNoteNumber(), 3);
}







