add_executable(app main.c coin.c myrandom.c)
target_include_directories(app PUBLIC ${CMAKE_SOURCE_DIR}/include)
