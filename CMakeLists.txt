cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME polska_cow)
project(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(HEADERS
    cow.h
    )

set(SOURCES
    main.cpp
    cow.cpp
    )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable( #создаем исполняемый файл для тестов
  dancing_cow_tests
  cow.h
  cow.cpp
  dancing_cow_tests.cpp
)
target_link_libraries(
  dancing_cow_tests
  ${CONAN_LIBS}
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(dancing_cow_tests)