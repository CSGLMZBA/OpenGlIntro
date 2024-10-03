#set minimum required Cmake version
cmake_minimum_required(VERSION 3.22.1)

#set project properties
project(Project C CXX) 

#set standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

#Add libraries needed for the other projects
add_subdirectory(ThirdParty)

#Add custom core project
add_subdirectory(Core)
#Add app project
add_subdirectory(App)