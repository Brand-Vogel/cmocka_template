add_executable(run_tests test_coin.c ../src/coin.c ../src/myrandom.c ../src/coin_di.c)
target_include_directories(run_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
#link with cmocka and 'wrap' option for symbol replacement
target_link_libraries(run_tests cmocka "-Wl,--wrap=myrandom_generate")



