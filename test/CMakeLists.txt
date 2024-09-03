cmake_minimum_required(VERSION 3.28)

set(CXX_STANDARD 17)

add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR, lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp NoteFileTest.cpp NoteFileFixture.cpp)
add_executable(runNoteFileTests ${TEST_SOURCE_FILES})
target_link_libraries(runNoteFileTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)