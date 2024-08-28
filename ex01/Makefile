CXX=c++
CXXFLAGS=-Wall -Werror -Wextra -std=c++98
DEPS=
SRCS=main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS=$(SRCS:.cpp=.o)
NAME=ClapTrap
all: $(NAME)
$(NAME): $(OBJS) $(DEPS)
	@$(CXX) $(OBJS) $(DEPS) -o $(NAME)
clean:
	@rm $(OBJS)
fclean: clean
	@rm $(NAME)
re: fclean all