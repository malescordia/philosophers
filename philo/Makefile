NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

SRC = src/main.c src/parse.c src/init.c src/routine.c src/time.c src/utils.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m[success]\033[0m Philosopher's compiled!"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@
	@echo "\033[36m[compiled]\033[0m $<"

clean:
	@rm -f $(OBJ)
	@echo "\033[33m[clean]\033[0m Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[fclean]\033[0m Executable file removed!"

re: fclean all