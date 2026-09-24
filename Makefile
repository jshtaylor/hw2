all:
	g++ -Wall -O3 TimeCodeTests.cpp TimeCode.cpp -o timeCode
debug:
	g++ -Wall -O3  -g TimeCodeTests.cpp TimeCode.cpp -o timeCode
time:
	g++ -Wall -O3 -g TimeCode.cpp
clean:
	rm -f timeCode nasa paint
nasa:
	g++ -Wall -O3 -g NasaLaunchAnalysis.cpp TimeCode.cpp -o nasa
paint:
	g++ -Wall -O3 -g PaintDryTimer.cpp TimeCode.cpp -o paint