NAME = 
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
C_FLAGS = -Wall -Wextra -Werror -std=c++98 -g #leaks --atExit --

#control codes
RESET       =   \033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling [$(NAME)]"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

#compile object files
%.o: %.cpp Makefile
	@echo "Compiling $< "
	@$(CC) $(C_FLAGS) -c $< -o $@

#clean rule
clean:
	@echo "$(RED)Cleaning object files$(RESET)"
	rm -rf $(OBJ)

#fclean rule 
fclean: clean
	@echo "$(RED)Cleaning executable$(RESET)"
	rm -f $(NAME)

#re rule
re: fclean all

.PHONY: all clean fclean re