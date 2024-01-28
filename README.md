# cmocka_template
Starter code for a c repository with cmocka unit testing

## Dependencies
It requires cmocka installed. Ubuntu package: libcmocka-dev. Binaries available for windows.

## Build the example
The repository can be built with cmake. The generated binaries are:
- src/app: an example dummy application
- src/run_tests: example cmocka unit tests 

Alternatively, the app and tests can be built manually (e.g. with gcc)

app:
gcc src/myrandom.c src/main.c src/coin.c -I include/  -o app

tests:
gcc test/test_coin.c src/coin.c src/myrandom.c -lcmocka -I include/ -Wl,--wrap=myrandom_generate -o run_tests

