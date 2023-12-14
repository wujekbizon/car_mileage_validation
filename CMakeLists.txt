cmake_minimum_required(VERSION 3.16)
project(CarMileageValidation)
include(FetchContent)

set(SOURCE_FILES
    src/main.cpp
    src/Car.cpp
    # src/MileageData.cpp
    # src/DatabaseManager.cpp
    # src/MileageValidator.cpp
    src/UI.cpp)

set(HEADERS
    src/include/Car.h
    # src/include/MileageData.h
    # src/include/DatabaseManager.h
    # src/include/MileageValidator.h
    src/include/UI.h)

# include nlohmann_json library
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(CarMileageValidation ${SOURCE_FILES} ${HEADERS})
target_link_libraries(CarMileageValidation PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(CarMileageValidation PRIVATE gtest_main)