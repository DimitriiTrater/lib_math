# DimitriiTrater

cmake_minimum_required(VERSION 3.23)

project(lib_math VERSION 1.0)

include(cmake/utils.cmake)
include(GNUInstallDirs)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

option(LIB_MATH_BUILD_TESTS "Build lib_math tests" OFF)
option(LIB_MATH_BUILD_EXAMPLES "Build lib_math examples" OFF)
option(LIB_MATH_BUILD_DOCS "Build lib_math documentation" OFF)
option(LIB_MATH_INSTALL "Generate target for installing lib_math" ${is_top_level})
set_if_undefined(LIB_MATH_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/lib_math" CACHE STRING
   "Install path for lib_math package-related CMake files")

set_if_undefined(CMAKE_CXX_VISIBILITY_PRESET hidden)
set_if_undefined(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
    

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(APE_EXE StaticTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_library(
    lib_math   STATIC
    
    src/point2D.cpp      include/lib_math/point2D.hpp
    src/point3D.cpp      include/lib_math/point3D.hpp

    src/vector2D.cpp     include/lib_math/vector2D.hpp
    src/vector3D.cpp     include/lib_math/vector3D.hpp

    src/calc.cpp         include/lib_math/calc.hpp
)

add_library(lib_math::lib_math ALIAS lib_math)

include(GenerateExportHeader)

set(export_file_name "export_static.hpp")

generate_export_header(lib_math EXPORT_FILE_NAME include/lib_math/${export_file_name})

set(public_headers
    include/lib_math/export.hpp
    include/lib_math/lib_math.hpp
)

set(sources
    ${public_headers}
    src/lib_math.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

list(APPEND public_headers
    "${CMAKE_CURRENT_BINARY_DIR}/include/lib_math/${export_file_name}")
list(APPEND sources
    "${CMAKE_CURRENT_BINARY_DIR}/include/lib_math/${export_file_name}")



add_executable(
    ${APE_EXE} main.cpp
)

#----------------------------------------------------------------
# lib_math targets
#----------------------------------------------------------------

include(CMakePackageConfigHelpers)

target_sources(lib_math PRIVATE ${sources})

target_compile_definitions(lib_math
    PUBLIC
        "LIB_MATH_STATIC_DEFINE"
)

target_include_directories(lib_math
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

set_target_properties(lib_math PROPERTIES
    PUBLIC_HEADER "${public_headers}"
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION})

target_link_libraries(${APE_EXE} lib_math)

if(LIB_MATH_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    configure_package_config_file(cmake/lib_math-config.cmake.in lib_math-config.cmake
        INSTALL_DESTINATION "${LIB_MATH_INSTALL_CMAKEDIR}")

    write_basic_package_version_file(lib_math-config-version.cmake
        COMPATIBILITY SameMajorVersion)

    install(TARGETS lib_math EXPORT lib_math_export
        RUNTIME COMPONENT lib_math
        LIBRARY COMPONENT lib_math NAMELINK_COMPONENT lib_math-dev
        ARCHIVE COMPONENT lib_math-dev
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDE_DIR}")
    install(DIRECTORY include/
        TYPE INCLUDE
        COMPONENT lib_math-dev)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/lib_math/${export_file_name}"
        COMPONENT lib_math-dev
        DESTINATION "${CMAKE_INSTALL_INCLUDE_DIR}/lib_math")

    set(targets_file "lib_math-static-targets.cmake")

    install(EXPORT lib_math_export
        COMPONENT lib_math-dev
        FILE "${targets_file}"
        DESTINATION "${LIB_MATH_INSTALL_CMAKEDIR}"
        NAMESPACE lib_math::)

    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/lib_math-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/lib_math-config-version.cmake"
        COMPONENT lib_math-dev
        DESTINATION "${LIB_MATH_INSTALL_CMAKEDIR}")

    if(MSVC)
        set(pdb_file "")
        set(pdb_file_destination "")

        if(BUILD_SHARED_LIBS)
            set(pdb_file "$<TARGET_PDB_FILE:lib_math>")
            set(pdb_file_destination "${CMAKE_INSTALL_BINDIR}")
        else()
            # TARGET_PDB_FILE does not work for pdb file generated for static library build, determining it manually
            set(pdb_file "$<TARGET_FILE_DIR:lib_math>/$<TARGET_FILE_PREFIX:lib_math>$<TARGET_FILE_BASE_NAME:lib_math>.pdb")
            set(pdb_file_destination "${CMAKE_INSTALL_LIBDIR}")
        endif()

        install(FILES "${pdb_file}"
            COMPONENT lib_math-dev
            CONFIGURATIONS Debug RelWithDebInfo
            DESTINATION "${pdb_file_destination}"
            OPTIONAL)
    endif()
endif()



#----------------------------------------------------------------
# other target 
#----------------------------------------------------------------

include(CTest)

if(LIB_MATH_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(LIB_MATH_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(LIB_MATH_BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    doxygen_add_docs(docs include)
endif()


