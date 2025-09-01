cmake_minimum_required(VERSION 3.16)

project(JimGoldGame VERSION 0.1
                    DESCRIPTION "Game about one russian youtuber:/"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(JimGoldGame main.cpp)

include_directories(include)

add_executable(JimGoldGame
    src/main.cpp src/game.h src/game.cpp
    entitys/Entity/entity.cpp entitys/Entity/entity.h
    core/scenemanager.h core/scenemanager.cpp
    core/audiomanager.h core/audiomanager.cpp
    entitys/Player/player.h entitys/Player/player.cpp
    UI/ui.h UI/ui.cpp
    core/scene/scene.h
    core/scene/housescene.h core/scene/housescene.cpp
    core/scene/scene2.h core/scene/scene2.cpp
    GameObjekt/gameobject.h GameObjekt/gameobject.cpp
    entitys/NPC/npc.h entitys/NPC/npc.cpp
    entitys/NPC/dialoguewindow.h entitys/NPC/dialoguewindow.cpp
    
)


include_directories(${CMAKE_SOURCE_DIR}/core)
include_directories(${CMAKE_SOURCE_DIR}/entitys/Entity)
include_directories(${CMAKE_SOURCE_DIR}/entitys/Player)
include_directories(${CMAKE_SOURCE_DIR}/entitys/NPC)
include_directories(${CMAKE_SOURCE_DIR}/UI)
include_directories(${CMAKE_SOURCE_DIR}/core/scene)
include_directories(${CMAKE_SOURCE_DIR}/GameObjekt)



add_custom_command(TARGET JimGoldGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:JimGoldGame>/assets"
    COMMENT "Copying assets directory to binary location"
)


target_link_libraries(JimGoldGame PRIVATE raylib m pthread)

include(GNUInstallDirs)
install(TARGETS JimGoldGame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
