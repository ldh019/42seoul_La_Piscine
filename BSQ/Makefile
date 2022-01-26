# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 15:20:05 by donghunl          #+#    #+#              #
#    Updated: 2022/01/26 17:46:19 by donghunl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = bsq
HEADER = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

all: $(TARGET)
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f donghun.txt
fclean: clean
	rm -f $(TARGET)
re: fclean all
.PHONY: all clean fclean re

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) -I $(HEADER)
