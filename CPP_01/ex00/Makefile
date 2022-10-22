# Makefile

NAME				= BraiiiiiiinnnzzzZ
# Sources
FILES				= $(wildcard *.cpp)
SRCS_DIR			= .
SRCS				= $(addprefix $(SRCS_DIR)/,$(FILES))\
# Objects 
OBJS_DIR			= ./objs
OBJS				= $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.cpp=.o))
# Compilation, Flags and header files
CC					= clang++
INCLUDES			= $(shell find . -name "*.hpp" -print)
# CFLAGS 				= -Wall -Wextra -Werror 
CFLAGS 				= -Wall -Wextra -Werror -std=c++98

# Rules
all:				$(NAME)

$(NAME):			$(OBJS) 
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo $(GREEN)$(NAME)"\tSuccessfully compiled" $(RESET)

$(OBJS_DIR)/%.o: 	$(SRCS_DIR)/%.cpp $(INCLUDES)
					@mkdir -p $(@D)
					@$(CC) -c $(CFLAGS)  $< -o $@

$(OBJS): 			| $(OBJS_DIR)

$(OBJS_DIR):
					@mkdir $(OBJS_DIR)

clean:				
					@rm -f $(OBJS)
					@echo $(GREEN)$(NAME)"\tSuccessfully removed objects" $(RESET)

fclean: 			clean
					@rm -f $(NAME)
					@rm -f $(OBJS)
					@rm -rf $(OBJS_DIR)
					@echo $(GREEN)$(NAME)"\tSuccessfully removed executable and cleaned folder" $(RESET)

re: 				fclean all

.PHONY: 			all clean fclean re test

# Colors
RESET		:= "\033[0m"
BLACK		:= "\033[30m"
RED			:= "\033[31m"
GREEN		:= "\033[32m"
YELLOW		:= "\033[33m"
BLUE		:= "\033[34m"
MAGENTA		:= "\033[35m"
CYAN		:= "\033[36m"
WHITE		:= "\033[37m"
BOLDBLACK	:= "\033[1m\033[30m"
BOLDRED		:= "\033[1m\033[31m"
BOLDGREEN	:= "\033[1m\033[32m"
BOLDYELLOW	:= "\033[1m\033[33m"
BOLDBLUE	:= "\033[1m\033[34m"
BOLDMAGENTA	:= "\033[1m\033[35m"
BOLDCYAN	:= "\033[1m\033[36m"
BOLDWHITE	:= "\033[1m\033[37m"