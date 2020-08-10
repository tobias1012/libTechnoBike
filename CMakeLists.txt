cmake_minimum_required(VERSION 3.11)

# Defome tje project
project(LibTechnoBike VERSION 0.1
                      DESCRIPTION "API for TechnoGym GROUP CONNECT Bikes"
                      LANGUAGES CXX)

file(GLOB_RECURSE src_code
     "*.hpp"
     "*.cpp"
)

#find SFML
find_package(SFML REQUIRED COMPONENTS network system)


#We're making a library, therefore a library will be added
add_library(TechnoBike SHARED ${src_code})

#Add all headers
target_include_directories(TechnoBike PUBLIC include)