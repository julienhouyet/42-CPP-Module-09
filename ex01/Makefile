NAME 		= RPN

ifeq ($(shell uname), Darwin)
    CXX = /opt/homebrew/bin/g++-14
else
    CXX = c++
endif

SRC_DIR 	= src
INC_DIR		= include
OBJ_DIR 	= obj

SRC 		= 	$(SRC_DIR)/RPN.cpp \
						$(SRC_DIR)/main.cpp 
				
OBJ			= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
CC 			= c++
RM 			= rm -f
CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic
INCS 		= -I$(INC_DIR) -I.
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re