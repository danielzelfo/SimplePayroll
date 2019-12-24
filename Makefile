OBJS = SimplePayroll.cpp

#Change compiler here if required
CC = g++

OBJ_NAME = SimplePayroll

all :
	$(CC) $(OBJS) -std=c++11 -o $(OBJ_NAME)