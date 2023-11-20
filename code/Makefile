MAIN = fdir
CC = gcc
FLAGS = -Wall

SRC_DR = src/
OBJ_DR = obj/

SRC = $(wildcard $(SRC_DR)*.c)
OBJ = $(patsubst $(SRC_DR)%.c, $(OBJ_DR)%.o, $(SRC))

$(MAIN): $(OBJ) 
	$(CC) $(FLAGS) -o $(MAIN) $(OBJ) -lncurses -lpanel

$(OBJ_DR)%.o: $(SRC_DR)%.c 
	$(CC) -c $^ -o $@

clean:
	rm $(OBJ_DR)*.o $(MAIN)

debug:
	$(CC) $(SRC) -lar_list -lncurses -g
