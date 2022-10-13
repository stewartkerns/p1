cmake_minimum_required(VERSION 3.23)
project(p1)

set(CMAKE_CXX_STANDARD 14)

add_executable(p1 p1.cpp MemberList MemberList.cpp RatingList RatingList.cpp BookList BookList.cpp)
