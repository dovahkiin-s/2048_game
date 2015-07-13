CC = gcc
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
CFLAGS=-c -Wall -I$(INC_DIR)/..
LFLAGS = -Wall
SRCS = $(SRC_DIR)/BoardPosition.cpp $(SRC_DIR)/Board.cpp $(SRC_DIR)/BoardView.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/main.cpp
OBJS = $(OBJ_DIR)/BoardPosition.o $(OBJ_DIR)/Board.o $(OBJ_DIR)/BoardView.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/main.o

DEPS = $(INC_DIR)/BoardPosition.h $(INC_DIR)/Board.h $(INC_DIR)/BoardView.h $(INC_DIR)/Game.h

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -lstdc++ -o 2048

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

SRCS_TEST = $(SRC_DIR)/BoardPosition.cpp $(SRC_DIR)/Board.cpp $(SRC_DIR)/TestBoard.cpp $(SRC_DIR)/main_test.cpp
OBJS_TEST = $(OBJ_DIR)/BoardPosition.o $(OBJ_DIR)/Board.o $(OBJ_DIR)/TestBoard.o $(OBJ_DIR)/main_test.o

test: $(OBJS_TEST)
	$(CC) $(LFLAGS) $(OBJS_TEST) -lstdc++ -o 2048_test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@