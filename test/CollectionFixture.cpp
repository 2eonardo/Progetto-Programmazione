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
    EXPECT_EQ(c->setImportantNote(1,true), true);
    EXPECT_EQ(c->setBlockedNote(1, true), true);
}

TEST_F(NoteFixture, BlockedTest){
    EXPECT_EQ(c->modifyTitleNote(2, "Anakin Skywalker"), false);
    EXPECT_EQ(c->modifyTextNote(2, "che storia triste"),false);
    EXPECT_EQ(c->removeNote(2), false);
}
TEST_F(NoteFixture, FindNoteTest){
    EXPECT_EQ(c->findNote("Nulla").size(), 0);
    EXPECT_EQ(c->findNote("St").size(), 2);
    EXPECT_EQ(c->findNote("Star").size(), 1);
}

TEST_F(NoteFixture, ReadNoteTest){
    const Note& n = c->readNote(0);
    EXPECT_EQ(n.isBlocked(), false);
    EXPECT_EQ(n.isImportant(), false);
    EXPECT_EQ(n.getText(), "L'imperatore Palpatine non è morto");
    EXPECT_EQ(n.getTitle(), "Star Wars");
}

TEST_F(NoteFixture, ReadNoteOutOfRangeTest){
    const Note& n1 = c->readNote(-2);
    EXPECT_EQ(n1.isBlocked(), false);
    EXPECT_EQ(n1.isImportant(), false);
    EXPECT_EQ(n1.getText(), "");
    EXPECT_EQ(n1.getTitle(), "Note 1");
    const Note& n2 = c->readNote(5);
    EXPECT_EQ(n2.isBlocked(), false);
    EXPECT_EQ(n2.isImportant(), false);
    EXPECT_EQ(n2.getText(), "");
    EXPECT_EQ(n2.getTitle(), "Note 2");
}

TEST_F(NoteFixture, PositiveIndexOutOfRangeTest){
    EXPECT_EQ(c->removeNote(5), false);
    EXPECT_EQ(c->modifyTitleNote(5, ""), false);
    EXPECT_EQ(c->modifyTextNote(5,""), false);
    EXPECT_EQ(c->setBlockedNote(5, true), false);
    EXPECT_EQ(c->setImportantNote(5, true), false);
}

TEST_F(NoteFixture, NegativeIndexOutOfRangeTest){
    EXPECT_EQ(c->removeNote(-5), false);
    EXPECT_EQ(c->modifyTitleNote(-5, ""), false);
    EXPECT_EQ(c->modifyTextNote(-5,""), false);
    EXPECT_EQ(c->setBlockedNote(-5, true), false);
    EXPECT_EQ(c->setImportantNote(-5, true), false);
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

TEST_F(NoteFixture, AttachDetachObserverTest){
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







