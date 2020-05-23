add_executable(container_test container_test.cc)
add_executable(file_test file_test.cc)

target_link_libraries(container_test LINK_PUBLIC container)
target_link_libraries(container_test LINK_PUBLIC filestream)
target_link_libraries(file_test LINK_PUBLIC container)
target_link_libraries(file_test LINK_PUBLIC filestream)


install(DIRECTORY DESTINATION "output")
install(TARGETS file_test)
install(TARGETS container_test)
