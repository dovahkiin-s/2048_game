CC = gcc
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
CFLAGS=-c -Wall -I$(INC_DIR)/..
LFLAGS = -Wall
SRCS = $(SRC_DIR)/BoardPosition.cpp $(SRC_DIR)/main.cpp
OBJS = $(OBJ_DIR)/BoardPosition.o $(OBJ_DIR)/main.o

DEPS = $(INC_DIR)/BoardPosition.h

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -lstdc++ -o 2048

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/Trace.o: $(DEPS)

