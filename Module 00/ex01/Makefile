NAME = phone_book

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I .

SRCS_DIR = src/


FUNC =	


OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(FUNC:.cpp=.o)))

# Rule to compile .c files to .o files
$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $< to $@"
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the final executable
$(NAME): $(OBJS) 
	@echo "Linking $(NAME)"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	
# Clean object files
clean: 
	rm -rf $(OBJS_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

# Default target
all: $(NAME)

.PHONY: all clean fclean re