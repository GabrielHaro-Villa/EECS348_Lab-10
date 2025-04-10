CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = calculator

OBJS = main.o calculator.o
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp calculator.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

calculator.o: calculator.cpp main.cpp calculator.hpp
	$(CXX) $(CXXFLAGS) -c calculator.cpp

clean:
	rm -f $(OBJS) $(TARGET)