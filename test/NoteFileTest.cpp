//
// Created by Leo on 02/09/2024.
//

#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../ConcreteObserver.h"

TEST(NoteFileTest, CreateNote) {
    Note n("Pippo", "Ciao Pluto.");
    EXPECT_EQ(n.getTitle(), "Pippo");
}

TEST(NoteFileTest, CreateEmptyNote){
    Note n;
    EXPECT_EQ(n.getTitle(), "Note 1");
    EXPECT_EQ(n.getText(),"");
    EXPECT_EQ(n.isBlocked(), false);
}

TEST(NoteFileTest, SetTitleNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setTitle("Topolino");
    EXPECT_EQ(n.getTitle(),"Topolino");
}

TEST(NoteFileTest, SetTextNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setText("Ciao Paperino.");
    EXPECT_EQ(n.getText(),"Ciao Paperino.");
}

TEST(NoteFileTest, SetBlockNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setBlocked(true);
    EXPECT_EQ(n.isBlocked(), true);
}

TEST(NoteFileTest, CreateCollection){
    Collection c("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}

TEST(NoteFileTest, CreateEmptyCollection){
    Collection c;
    EXPECT_EQ(c.getTitle(), "Collection 1");
}

TEST(NoteFileTest, SetTitleCollection){
    Collection c;
    c.setTitle("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}



