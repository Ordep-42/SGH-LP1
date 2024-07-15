cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(SGH-LP1)

# Versão do C++
set(CMAKE_CXX_STANDARD 17)

# Diretório de headers
include_directories(include)

# Arquivos cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executável
add_executable(SGH-LP1 ${SOURCES})
