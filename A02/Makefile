SUBMIT_NAME = Assignment02+3230106230+LiuRenqin.zip
SUBMIT_DIR = ./code README.md Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC_DIR = ./code
BUILD_DIR = .

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = $(BUILD_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(SUBMIT_NAME)

submit: clean
	zip -r $(SUBMIT_NAME) $(SUBMIT_DIR)