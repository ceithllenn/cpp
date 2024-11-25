NAME = harlFilter

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
INCLUDES = -I .

SRCS_DIR = src/
FUNC =	main.cpp \
		Harl.cpp


OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(FUNC:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

# Couleurs et emojis
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m
SUCCESS_EMOJI = ✅
FAIL_EMOJI = ❌

# Rule to compile .cpp files to .o files and generate .d files
$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ || \
	 (echo "$(RED)Compilation failed for $< $(FAIL_EMOJI)$(RESET)" && exit 1)

# Rule to create the final executable
$(NAME): $(OBJS) 
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) && \
	 (echo "$(GREEN)Compilation successful! $(SUCCESS_EMOJI)$(RESET)") || \
	 (echo "$(RED)Linking failed! $(FAIL_EMOJI)$(RESET)" && exit 1)

# Include dependency files if they exist
-include $(DEPS)

# Clean object files and dependency files
clean: 
	@rm -rf $(OBJS_DIR)
	@echo "Cleaned object files and dependencies."

# Full clean
fclean: clean
	@rm -f $(NAME)
	@echo "Fully cleaned $(NAME)."

# Recompile everything
re: fclean all

# Default target
all: $(NAME)

.PHONY: all clean fclean re