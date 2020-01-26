CXX 		:= -c++
CXXFLAGS	:= -Wall -Wextra -Werror
BUILD		:= ./build
OBJ_DIR		:= $(BUILD)/o
APP_DIR 	:= $(BUILD)/apps
TARGET		:= main
SRC := \
    $(wildcard src/*.cpp) \
OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS_UNITE := $(SRC:Unite.cpp=$(OBJ_DIR)/Unite.o) 

Unite: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS_UNITE)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS_UNITE)


all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

releae: CXXFLAG += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*  
	-@rm -rvf $(APP_DIR)/*
