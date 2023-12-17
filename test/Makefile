LIB = -lncurses -lncursesw

OBJ_DIR = ../code/obj/
SRC_DIR = ../code/src/

ALL = dirfunc

SRC = $(SRC_DIR)dirfunc.c $(SRC_DIR)dirlist.c
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

TEST_SRC = $(wildcard *.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST_SRC))

dirfunc: $(TEST_OBJ) $(OBJ)
	gcc -o $@ $^ $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -o $@ -c $^ $(LIB)

%.o: %.c
	gcc -o $@ -c $^ $(LIB)

clear: 
	rm *.o $(ALL)

