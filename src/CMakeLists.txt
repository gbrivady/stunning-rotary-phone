add_executable(StunningRotaryPhone main.cpp
                                   entity.cpp
                                   render.cpp
                                   scene.cpp
                                   terrain.cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/physic)
target_include_directories(StunningRotaryPhone PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(StunningRotaryPhone ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

set_target_properties(StunningRotaryPhone PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/bin)

