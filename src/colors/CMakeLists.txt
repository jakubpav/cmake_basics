
add_library(Colors INTERFACE)
add_library(Graphics::Colors ALIAS Colors)
target_include_directories(Colors INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
