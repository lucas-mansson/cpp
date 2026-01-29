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
PROGS = spell #test_edit_distance

all: $(PROGS)

# Link targets
#test_edit_distance: test_edit_distance.o
word: word.o
dictionary: dictionary.o	
spell: spell.o dictionary.o word.o

# Clean-up rules
.PHONY: all clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm -f *.d

# Include the dependency files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
