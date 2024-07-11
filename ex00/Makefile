NAME =						megaphone
SRCS =						megaphone.cpp
OBJS = 						$(SRCS:.cpp=.o)
DEP =						$(OBJS:%.o=%.d)
CC = 						clang++
CPPFLAGS =					-MMD
CFLAGS =					-Wall -Werror -Wextra -g3 -std=c++98
OBJ_COLOR =					\033[0;34m
NO_COLOR =					\033[0m
BOLD =						\033[1m

all:						$(NAME)

$(NAME):					$(OBJS)
							@$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS)


%.o:						%.cpp
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
