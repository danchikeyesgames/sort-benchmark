

.PHONY: build clean

exec.out: src/test_main.cpp
	g++ -g -I./src/ -std=c++11 $^ -o $@

build: exec.out
	echo "Build $^ [OK]"

clean:
	rm exec.out

