function(setup_test test_file)
  file(GLOB source ${test_file}.cpp)
	add_executable(${test_file} ${test_file})
	target_link_libraries(${test_file} procedured)
	add_test(NAME ${test_file} COMMAND ${test_file})
endfunction()


include_directories(.)

if(WIN32)
  set(ENV{PATH} "$ENV{PATH}:${CMAKE_RUNTIME_OUTPUT_PATH}")
  set(ENV{PATH} "$ENV{PATH}:${CMAKE_LIBRARY_OUTPUT_PATH}")
  set(ENV{PATH} "$ENV{PATH}:${CMAKE_ARCHIVE_OUTPUT_PATH}")
endif()

file(GLOB files "*_test.cpp")
foreach(file ${files})
  get_filename_component(basename "${file}" NAME_WE)
  setup_test(${basename})
endforeach()

