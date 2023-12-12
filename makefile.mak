CXX = g++
CXXFLAGS = -Wall -g

SRCS = main.cpp testfile.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o output

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) output