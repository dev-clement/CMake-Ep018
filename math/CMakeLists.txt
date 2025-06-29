# The math library
set(TARGET_NAME libmath)
set(OUR_PROJECT_VERSION "Two")
add_library(${TARGET_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/supermath.cpp)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)