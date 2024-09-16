//
// Created by Leo on 02/09/2024.
//

#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../CollectionObserver.h"

TEST(NoteTest, CreateNote) {
    Note n("Pippo", "Ciao Pluto.");
    EXPECT_EQ(n.getTitle(), "Pippo");
}

TEST(NoteTest, CreateEmptyNote){
    Note n;
    EXPECT_EQ(n.getTitle(), "Note 1");
    EXPECT_EQ(n.getText(),"");
    EXPECT_EQ(n.isBlocked(), false);
}

TEST(NoteTest, SetTitleNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setTitle("Topolino");
    EXPECT_EQ(n.getTitle(),"Topolino");
}

TEST(NoteTest, SetTextNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setText("Ciao Paperino.");
    EXPECT_EQ(n.getText(),"Ciao Paperino.");
}

TEST(NoteTest, SetBlockTitleTextNote){
    Note n;
    n.setBlocked(true);
    EXPECT_EQ(n.setTitle("Pippo"), false);
    EXPECT_EQ(n.setText("Ciao Pluto."), false);
}

TEST(NoteTest, SetBlockNote){
    Note n("Pippo", "Ciao Pluto.");
    n.setBlocked(true);
    EXPECT_EQ(n.isBlocked(), true);
}

TEST(NoteTest, CreateCollection){
    Collection c("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}

TEST(NoteTest, CreateEmptyCollection){
    Collection c;
    EXPECT_EQ(c.getTitle(), "Collection 1");
}

TEST(NoteTest, SetTitleCollection){
    Collection c;
    c.setTitle("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}



