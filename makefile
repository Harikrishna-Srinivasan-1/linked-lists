CXX := g++

SRC := test/test_initialize.cpp
HEADER := ../singly_linked_list.h
OBJ := $(SRC:.cpp=.o)

# Target executable
TARGET := test_initialize

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

# Compiling the source files
%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the test
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
