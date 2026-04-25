CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -pthread
TARGET := combo2
SOURCES := main.cpp CDominoes.cpp CPlayer.cpp CRandom.cpp CTable.cpp
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)

.PHONY: all run test clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)