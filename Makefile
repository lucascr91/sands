default:
	g++ src/utils.cpp src/sorting.cpp src/main.cpp -o main

tests:
	g++ test/test.cpp src/sorting.cpp src/utils.cpp -o main