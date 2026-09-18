all:
	g++ -Wall -O3 TimeCodeTests.cpp TimeCode.cpp -o timeCode
debug:
	g++ -Wall -O3  -g TimeCodeTests.cpp TimeCode.cpp -o timeCode
time:
	g++ -Wall -O3 -g TimeCode.cpp
clean:
	rm -f timeCode
