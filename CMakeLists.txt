include_directories(${WordsCounter_SOURCE_DIR})
cmake_minimum_required(VERSION 3.6)
project(WordsCounter)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp linesCounter.cpp countingFunctions.cpp configurationReader.cpp outPutFunc.cpp)
add_executable(WordsCounter ${SOURCE_FILES})
TARGET_LINK_LIBRARIES (WordsCounter pthread)
