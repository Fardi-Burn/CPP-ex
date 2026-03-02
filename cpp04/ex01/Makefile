# Makefile to compile the Animal/Dog/Cat project

# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = animals

# Default rule
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything (objects + executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Avoid conflicts with files named clean/fclean/re
.PHONY: all clean fclean re
