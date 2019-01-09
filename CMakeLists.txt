#-----------------------------------
# cmake version
#-----------------------------------
cmake_minimum_required (VERSION 3.4)

#-----------------------------------
# project name
#-----------------------------------
project(tetris VERSION 0.1 LANGUAGES CXX)

#-----------------------------------
# packages
#-----------------------------------
#find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)

#-----------------------------------
# own vars
#-----------------------------------
# add flags to compiler
add_compile_options(-std=c++11)


#-----------------------------------
# sources
#-----------------------------------
add_executable (${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/src/Board.cpp
  ${CMAKE_SOURCE_DIR}/src/GameController.cpp
  ${CMAKE_SOURCE_DIR}/src/GameFlowPlaying.cpp
  ${CMAKE_SOURCE_DIR}/src/GraphicHandlerFactory.cpp
  ${CMAKE_SOURCE_DIR}/src/GraphicSdlImp.cpp
  ${CMAKE_SOURCE_DIR}/src/InputHandlerFactory.cpp
  ${CMAKE_SOURCE_DIR}/src/InputSdlImp.cpp
  ${CMAKE_SOURCE_DIR}/src/JShape.cpp
  ${CMAKE_SOURCE_DIR}/src/LineShape.cpp
  ${CMAKE_SOURCE_DIR}/src/LShape.cpp
  ${CMAKE_SOURCE_DIR}/src/Source.cpp
  ${CMAKE_SOURCE_DIR}/src/SquareShape.cpp
  ${CMAKE_SOURCE_DIR}/src/SShape.cpp
  ${CMAKE_SOURCE_DIR}/src/TShape.cpp
  ${CMAKE_SOURCE_DIR}/src/ZShape.cpp
)


#-----------------------------------
# include headers
#-----------------------------------
target_include_directories (${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/sdl2/include)
#target_include_directories (${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})


#-----------------------------------
# link libraries
#-----------------------------------
#target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_link_libraries(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/lib/sdl2/linux/64/libSDL2.so
)
