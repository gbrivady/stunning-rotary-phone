add_executable(StunningRotaryPhoneTest test.cpp ${SOURCE_FILES})

target_include_directories(StunningRotaryPhoneTest PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(StunningRotaryPhoneTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin/tests)

target_link_libraries(StunningRotaryPhoneTest ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
