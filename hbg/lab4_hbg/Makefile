# Define the compiler and the linker
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags
CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g 
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g 

# Targets
PROGS = seieve_eratosthenes string_cast tostring date_test test #example

all: $(PROGS)

# Link targets
#example: example.o
TagRemover: TagRemover.o
test: test.o TagRemover.o
seieve_eratosthenes: seieve_eratosthenes.o
date: date.o
date_test: date_test.o date.o
tostring: tostring.o date.o
string_cast: string_cast.o date.o

# Clean-up rules
.PHONY: all clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm -f *.d

# Include the dependency files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
