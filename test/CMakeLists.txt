add_executable(coin_tests test_coin.c ../src/coin.c ../src/myrandom.c ../src/coin_di.c)
target_include_directories(coin_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
#link with cmocka and 'wrap' option for symbol replacement
target_link_libraries(coin_tests cmocka "-Wl,--wrap=myrandom_generate")

add_executable(dicoin_tests test_coindi.c ../src/coin_di.c ../src/myrandom.c)
target_include_directories(dicoin_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
# No symbol replacement needed since we can inject the mock into the struct
target_link_libraries(dicoin_tests cmocka)



