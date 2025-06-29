cmake_minimum_required(VERSION 3.20)

project(Rooster)

# The include command sets up a new variable scope. The OUR_PROJECT_VERSION_AVAILABLE variable is being set in the
# three CMakeLists.txt files. We will see output saying that the project version is "One" because the variable
# set in included files live in their own scope.
set(OUR_PROJECT_VERSION "One")

# Set up a cache variable named THE_SKY_IS_BLUE
set(THE_SKY_IS_BLUE "Yes" CACHE STRING "Is the sky blue ?")

# The math library
add_subdirectory(math/)

# The stats library
add_subdirectory(stats/)

# Set the source files to use
set(SOURCE_FILES
	main/src/main.cpp
	main/src/information.cpp
	main/include/information.hpp)

function(create_and_link_executable EXEC_NAME LIB_NAME SOURCES)
	# We dereference SOURCES twice because we pass the SOURCES_FILE at the function
	# the function retrieve a variable inside of SOURCES, then you will need to dereference
	# SOURCES once to to to the variable inside SOURCES. Then we'll need to dereference again
	# to go to the content of the dereferenced SOURCES.
	add_executable(${EXEC_NAME} ${${SOURCES}})
	target_link_libraries(${EXEC_NAME} PUBLIC ${LIB_NAME})
	target_include_directories(${EXEC_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/main/include)
endfunction()

# The executable target
# add_executable(Rooster ${SOURCE_FILES})
# target_link_libraries(Rooster PIBLIC libstats)

create_and_link_executable(rooster libstats SOURCE_FILES)

message("Our project version is ${OUR_PROJECT_VERSION}")
message("Custom message: The used compiler is ${CMAKE_CXX_COMPILER}")
message("The processor architecture is $ENV{PROCESSOR_ARCHITECTURE}")
message(${THE_SKY_IS_BLUE})