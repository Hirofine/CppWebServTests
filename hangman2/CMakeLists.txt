cmake_minimum_required(VERSION 3.0.0)
project(hangman VERSION 0.1.0)

# Recherche de la bibliothèque Wt
find_package(Wt REQUIRED)

# Ajouter le répertoire d'en-tête de la bibliothèque Wt à CMAKE_INCLUDE_PATH
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /usr/local/include)

# Inclure les répertoires d'en-tête de la bibliothèque Wt
include_directories(${Wt_INCLUDE_DIR})

add_executable(hangman main.cpp)

# Lier les bibliothèques Wt
target_link_libraries(hangman 
    ${Wt_LIBRARIES}
    -L/usr/local/lib
    -lwthttp
    -lwt
    -lboost_system
    -lboost_thread
    -lboost_filesystem
    -lboost_program_options
)

# Paramètres d'exécution
set(HANGMAN_EXECUTABLE_ARGS "--docroot . --http-address 0.0.0.0 --http-port 9090")

# Définir la commande d'exécution
add_custom_target(run
    COMMAND hangman ${HANGMAN_EXECUTABLE_ARGS}
    DEPENDS hangman
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)