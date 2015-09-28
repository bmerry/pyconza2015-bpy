# Copyright 2015 SKA South Africa
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
