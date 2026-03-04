CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra

snake: main.cpp
	$(CXX) $(CXXFLAGS) -o snake main.cpp -lncurses

clean:
	rm -f snake

.PHONY: clean
