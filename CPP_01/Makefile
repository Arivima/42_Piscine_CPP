# Makefile
NAME				= CPP_01
SUBDIRS				= $$(find . -print | grep "Makefile" | sed 's/Makefile//g' | grep ex)

# Rules
all:				
					@echo $(BOLDCYAN)$(NAME)"\tCompiling exercices" $(RESET)
					@for dir in $(SUBDIRS); do \
						echo $(BLUE)"Compiling "$(NAME)" "$$dir$(RESET);\
						$(MAKE) -C $$dir; \
					done;
					@echo $(BOLDCYAN)$(NAME)"\tSuccessfully compiled exercices\n" $(RESET)

test:				
					@echo $(BOLDCYAN)$(NAME)"\tTesting exercices" $(RESET)
					@for dir in $(SUBDIRS); do \
						echo $(BLUE)"\nTesting "$(NAME)" "$$dir$(RESET);\
						$(MAKE) -C $$dir test; \
					done;
					@echo $(BOLDCYAN)$(NAME)"\tSuccessfully tested exercices\n" $(RESET)
fclean: 			
					@echo $(BOLDCYAN)$(NAME)"\tCleaning exercices" $(RESET)
					@for dir in $(SUBDIRS); do \
						echo $(BLUE)"Cleaning "$(NAME)" "$$dir$(RESET);\
						$(MAKE) -C $$dir fclean; \
					done;
					@echo $(BOLDCYAN)$(NAME)"\tSuccessfully cleaned exercices\n" $(RESET)

re: 				fclean all

.PHONY: 			all clean fclean re

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