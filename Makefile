#**************************************************
# Name: Blaine Smith, (Lane Campbell)
# Project: Game Library
# Description:
# Makefile to compile and build the Game Library
# program.
#**************************************************

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRCS = main.cpp library.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
