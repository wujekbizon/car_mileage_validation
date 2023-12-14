cmake_minimum_required(VERSION 3.22.1)
project(CarMileageValidation)
include(FetchContent)
enable_testing()

set(CMAKE_INCLUDE_DIRECTORIES
  src
  Testing
)

set(SOURCE_FILES
    src/main.cpp
    src/Car.cpp
    src/User.cpp
    # src/MileageData.cpp
    # src/DatabaseManager.cpp
    # src/MileageValidator.cpp
    Testing/CarDataSerializableTest.cpp
    src/UI.cpp)

set(HEADERS
    src/include/Car.h
    # src/include/MileageData.h
    # src/include/DatabaseManager.h
    # src/include/MileageValidator.h
    src/include/UI.h
    src/include/User.h
    )
add_executable(CarMileageValidation ${SOURCE_FILES} ${HEADERS})

# include nlohmann_json library
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(CarMileageValidation PRIVATE nlohmann_json::nlohmann_json)


FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
target_link_libraries(CarMileageValidation PRIVATE gtest_main)


