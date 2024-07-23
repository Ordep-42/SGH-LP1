cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(SGH-LP1)

# Versão do C++
set(CMAKE_CXX_STANDARD 17)

# Flags do compilador
set(CMAKE_CXX_FLAGS "-Werror -Wfatal-errors")

# Diretório de headers
include_directories(include)

# Arquivos cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(SQLite3)

include_directories(${SQLite3_INCLUDE_DIRS})

# Executável
add_executable(SGH-LP1 ${SOURCES})

target_link_libraries(SGH-LP1 ${SQLite3_LIBRARIES})
