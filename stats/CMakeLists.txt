# The stats library
set(TARGET_NAME libstats)
set(OUR_PROJECT_VERSION "Three")
add_library(${TARGET_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/stats.cpp)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${TARGET_NAME} PRIVATE libmath)