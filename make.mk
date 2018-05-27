CC=g++
FLAGS=-c -std=c++14 -Wall -Werror
NAME = course
MAIN = main
FILE_1 = interface
FILE_2 = polynom

all: $(NAME)

$(NAME): $(MAIN).o $(FILE_1).o $(FILE_2).o
	$(CC) $(MAIN).o $(FILE_1).o $(FILE_2).o -o $(NAME)

$(MAIN).o: $(MAIN).cpp
	$(CC) $(FLAGS) $(MAIN).cpp

$(FILE_1).o: $(FILE_1).cpp
	$(CC) $(FLAGS) $(FILE_1).cpp

$(FILE_2).o: $(FILE_2).cpp
	$(CC) $(FLAGS) $(FILE_2).cpp

clean:
	rm -rf *.o $(NAME)