# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 15:20:05 by donghunl          #+#    #+#              #
#    Updated: 2022/01/24 12:26:13 by donghunl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc #컴파일러
CFLAGS = -Wall -Wextra -Werror #컴파일 옵션
TARGET = bsq #실행파일 이름
SRC_DIR = ./src
OBJ_DIR = ./obj
HEADER = ./include
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c)) #디렉토리 부분은 제외하고 & 뒤 패턴에 만족하는 파일 전부
OBJS = $(SRCS:.c=.o) #파일명.c 들을 파일명.o 로 저장(인식한다는 뜻)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

all: $(TARGET) #모든 파일에 대해 실행
.PHONY: all clean #더미 정리 및 충돌 피하기
clean: #.o 파일 삭제
	rm -f *.o
test: #노미네트 검사
	norminette -R CheckForbiddenSourceHeader

# object 파일들은 전부 .c 파일을 컴파일해서 생성
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c


#BSQ 실행 -> object 파일들 전부 불러오고 컴파일
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)
