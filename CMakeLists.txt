cmake_minimum_required(VERSION 3.17)
project(simple_cpp)

set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "-std=c++11 -lstdc++")
#message(${CMAKE_CXX_FLAGS})



set(ALONE
        01_basic
        03_projects/01_address_book_manage
        02_advance
        )

set(DEMOS
        03_projects/03_02_employee_manage

        )


foreach(_dir IN ITEMS ${ALONE})
    file(GLOB _cpps "${_dir}/*.cpp")
    message(STATUS "Pattern '${_dir}':")
    foreach(_file IN ITEMS ${_cpps})
        get_filename_component(_file_name ${_file} NAME)
#        set(_project_name "${_file_name}")
        string( REPLACE ".cpp" "" _project_name ${_file_name} )
        message(STATUS "  ${_dir}/${_file_name} is going to be built")
#        add_executable(${_project_name} ${_dir}/${_file_name})
        add_executable(${_project_name} ${_file})
    endforeach()
endforeach()


foreach(_dir IN ITEMS ${DEMOS})
    file(GLOB _cpps ${_dir}/*.cpp)
    message(STATUS "Pattern '${_dir}':")

    foreach(_file IN ITEMS ${_cpps})
        get_filename_component(_file_name ${_file} NAME)
        set(_project_name "${_file_name}")
        message(STATUS "  ${_dir}/${_file_name} is going to be built")
    endforeach()

    get_filename_component(_file_name ${_dir} NAME)
    message(STATUS "${_file_name}'s files: ${_cpps}\n\n")
    add_executable(${_file_name} ${_cpps})

    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" _exe ${_cpps})



endforeach()
