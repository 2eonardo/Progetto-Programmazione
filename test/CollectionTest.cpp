//
// Created by Leo on 02/09/2024.
//

#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../CollectionObserver.h"

TEST(NoteTest, CreateCollection){
    Collection c("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}

TEST(NoteTest, CreateEmptyCollection){
    Collection c1;
    Collection c2;
    EXPECT_EQ(c1.getTitle(), "Collection 1");
    EXPECT_EQ(c2.getTitle(), "Collection 2");
}

TEST(NoteTest, SetTitleCollection){
    Collection c;
    c.setTitle("Walt Disney");
    EXPECT_EQ(c.getTitle(), "Walt Disney");
}

TEST(NoteTest, CreateNote) {
    Collection c("Walt Disney");
    c.addNote("Star Wars", "L'imperatore Palpatine non è morto", true, true);
    EXPECT_EQ(c.readNote(0).getTitle(), "Star Wars");
    EXPECT_EQ(c.readNote(0).getText(), "L'imperatore Palpatine non è morto");
    EXPECT_EQ(c.readNote(0).isBlocked(), true);
    EXPECT_EQ(c.readNote(0).isBlocked(), true);
}

TEST(NoteTest, CreateEmptyNote){
    Collection c;
    c.addNote();
    EXPECT_EQ(c.readNote(0).getTitle(), "Note 1");
    EXPECT_EQ(c.readNote(0).getText(), "");
    EXPECT_EQ(c.readNote(0).isBlocked(), false);
    EXPECT_EQ(c.readNote(0).isBlocked(), false);
    c.addNote();
    EXPECT_EQ(c.readNote(1).getTitle(), "Note 2");
}

TEST(NoteTest, DeleteNote){
    Collection c;
    c.addNote();
    EXPECT_EQ(c.removeNote(0), true);
}



