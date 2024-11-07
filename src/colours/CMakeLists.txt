
add_library(Colours INTERFACE)
add_library(Graphics::Colours ALIAS Colours)
target_include_directories(Colours INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
