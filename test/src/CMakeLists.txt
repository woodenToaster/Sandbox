set(TEST_SRC test.cpp)

add_executable(sample_test ${TEST_SRC})
add_dependencies(sample_test gtest)

target_link_libraries(
    sample_test
    ${GTEST_LIBRARIES}
    #${GMOCK_LIBRARIES}
)

#install(TARGETS sample_test DESTINATION bin)
