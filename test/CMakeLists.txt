#If cmocka is installed in an external directory, its path can be specified with CMOCKA_INSTALL_PATH
#This is particularly useful when building on Windows
if(DEFINED ENV{CMOCKA_INSTALL_PATH})
    link_directories($ENV{CMOCKA_INSTALL_PATH}/lib)
    include_directories($ENV{CMOCKA_INSTALL_PATH}/include)
endif()

set(COIN_TESTS_NAME coin_tests)
add_executable(${COIN_TESTS_NAME} test_coin.c ${CMAKE_SOURCE_DIR}/src/coin.c ${CMAKE_SOURCE_DIR}/src/myrandom.c ${CMAKE_SOURCE_DIR}/src/coin_di.c)
target_include_directories(${COIN_TESTS_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
#link with cmocka and 'wrap' option for symbol replacement
target_link_libraries(${COIN_TESTS_NAME} cmocka "-Wl,--wrap=myrandom_generate")

set(DICOIN_TESTS_NAME dicoin_tests)
add_executable(${DICOIN_TESTS_NAME} test_coindi.c ${CMAKE_SOURCE_DIR}/src/coin_di.c ${CMAKE_SOURCE_DIR}/src/myrandom.c)
target_include_directories(${DICOIN_TESTS_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
# No symbol replacement needed since we can inject the mock into the struct
target_link_libraries(${DICOIN_TESTS_NAME} cmocka)



