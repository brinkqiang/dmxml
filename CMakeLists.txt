cmake_minimum_required(VERSION 3.8)

PROJECT(dmxml)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

LibImport("dmxml" "src")

if (PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dmxml")
endif(PROJECT_IS_TOP_LEVEL)

