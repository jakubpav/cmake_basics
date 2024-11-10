
add_library(Rainbow INTERFACE)
add_library(Graphics::Rainbow ALIAS Rainbow)
target_include_directories(Rainbow INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Rainbow INTERFACE Graphics::Colors)
