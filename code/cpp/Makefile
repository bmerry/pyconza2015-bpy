CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS =
SOURCES = test_petshop.cpp petshop.cpp
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
TARGETS = test_petshop

all : $(TARGETS)

test_petshop: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp *.h
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f *.o $(TARGETS)
