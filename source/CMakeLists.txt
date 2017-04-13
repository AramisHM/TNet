FILE(GLOB_RECURSE MyLib_Sources "./TNet/*.cpp" "./TNet/*.c")
FILE(GLOB_RECURSE MyLib_Sources2 "./dependencies/*.cpp" "./dependencies/*.c")

ADD_LIBRARY (TNet STATIC ${MyLib_Sources} ${MyLib_Sources2})

target_include_directories (TNet PUBLIC ../include)
target_include_directories (TNet PUBLIC ../include/tnet)
add_definitions(-DHAS_SOCKLEN_T) # if we dont define this, under some linux distros it will not compile.
add_subdirectory (./dependencies/enet)

