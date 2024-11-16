
add_subdirectory(colors)
add_subdirectory(utility)
add_subdirectory(graphic)

add_executable(example)
target_sources(example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(example PUBLIC Utility::ArgParser Graphics::Rainbow)
target_compile_features(example PUBLIC cxx_std_23)
