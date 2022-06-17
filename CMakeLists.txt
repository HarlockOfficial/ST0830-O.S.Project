cmake_minimum_required(VERSION 3.22)
project(ST0830_O_S_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(ST0830_O_S_Project "")
target_sources(ST0830_O_S_Project
                PRIVATE
                    Steno/main.c
                    Steno/utilities.c
                    Steno/commandList.c
                    Steno/stenography.c
                    Steno/list.c
                    Steno/manageFile.c
                PUBLIC
                    Steno/byteType.h
                    Steno/utilities.h
                    Steno/commandList.h
                    Steno/stenography.h
                    Steno/list.h
                    Steno/manageFile.h
                )
