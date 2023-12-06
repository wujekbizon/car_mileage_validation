cmake_minimum_required(VERSION 3.16)
project(CarMileageValidation)

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

add_executable(CarMileageValidation ${SOURCE_FILES} ${HEADERS})