NAME =						phonebook
SRCS =						main.cpp\
							Contact.cpp\
							PhoneBook.cpp
OBJS = 						$(SRCS:.cpp=.o)
DEP =						$(OBJS:%.o=%.d)
CC = 						c++
CPPFLAGS =					-MMD
CFLAGS =					-Wall -Werror -Wextra -g3 -std=c++98
OBJ_COLOR =					\033[0;34m
LIB_COLOR =					\033[1;36m
NO_COLOR =					\033[0m
BOLD =						\033[1m

all:						$(NAME)

$(NAME):					$(OBJS)
							@echo "$(LIB_COLOR)[$(NAME)] Compiling$(NO_COLOR) $(LIB_COLOR)binary$(NO_COLOR)"
							@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS)


%.o:						%.cpp
							@echo "$(LIB_COLOR)[$(NAME)] $(NO_COLOR)Compiling $(OBJ_COLOR)$(notdir $<)$(NO_COLOR)"
							@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:						
							@rm -rfd $(OBJS) $(DEP)

fclean:						clean
							@rm -f $(NAME)

re:							fclean all

echo:
							echo $(OBJS)

-include $(DEP)

.PHONY:						all clean fclean re
