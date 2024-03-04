# cmocka_template
Starter code for a c repository with cmocka unit testing

## Dependencies
It requires cmocka installed. Ubuntu package: libcmocka-dev. Binaries and source code available for Windows.

## Build the example
The repository can be built with cmake. The generated binaries are:
- src/app: an example dummy application
- {build dir}/test/coin_tests: example cmocka unit tests 
- {build dir}/test/coindi_tests: example cmocka unit tests using dependency injection instead of symbol replacement

PRO TIP: define environment variable `CMOCKA_MESSAGE_OUTPUT=xml` when running the tests for JUnit output.
```
 CMOCKA_MESSAGE_OUTPUT=xml ./test/coin_tests
```

Alternatively, the app and tests can be built manually (e.g. with gcc)

app:
gcc src/myrandom.c src/main.c src/coin.c -I include/  -o app

coin tests:
gcc test/test_coin.c src/coin.c src/myrandom.c -lcmocka -I include/ -Wl,--wrap=myrandom_generate -o coin_tests
tests:
gcc test/test_coindi.c src/coindi.c src/myrandom.c -lcmocka -I include/ -o coindi_tests

### Building on Windows
- Specify your cmocka install directory with the CMOCKA_INSTALL_PATH environment variable
```
set CMOCKA_INSTALL_PATH=C:\cmocka
cmake . -G "MinGW Makefiles"
mingw32-make
```
- The generated executables depend on libcmocka.dll at runtime, make sure it's accessible to your application (e.g. add cmocka\bin to your path) 

