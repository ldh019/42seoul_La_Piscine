# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 15:20:05 by donghunl          #+#    #+#              #
#    Updated: 2022/01/24 18:14:52 by donghunl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc #컴파일러
CFLAGS = -Wall -Wextra -Werror -g #컴파일 옵션
TARGET = bsq #실행파일 이름
HEADER = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))

all: $(TARGET) #모든 파일에 대해 실행
clean: #.o 파일 삭제
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)
test: #노미네트 검사
	norminette -R CheckForbiddenSourceHeader
.PHONY: all clean #더미 정리 및 충돌 피하기

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) -I $(HEADER)
