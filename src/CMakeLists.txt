set(SOURCE_FILES main.cpp)

add_executable(StunningRotaryPhone ${SOURCE_FILES})

target_include_directories(StunningRotaryPhone PUBLIC ${PROJECT_SOURCE_DIR}/inc)

set_target_properties(StunningRotaryPhone PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(StunningRotaryPhone ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
