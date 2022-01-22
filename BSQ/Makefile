CC = gcc #컴파일러
CFLAGS = -Wall -Wextra -Werror #컴파일 옵션
#사용하는 라이브러리 추가하기
LDFLAGS = #라이브러리나 라이브러리 패스(링커 옵션)
SRC_DIR = . #소스 파일 디렉토리
OBJ_DIR = . #오브젝트 파일 디렉토리
TARGET = BSQ #실행파일 이름
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c)) #디렉토리 부분은 제외하고 & 뒤 패턴에 만족하는 파일 전부
OBJS = $(SRCS:.c=.o) #파일명.c 들을 파일명.o 로 저장(인식한다는 뜻)
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS)) #앞에 디렉토리 붙여주기
DEPS = $(OBJECTS:.o=.d) #무시할 파일들 목록 -> -include

all: $(TARGET) #모든 파일에 대해 실행
.PHONY: all clean fclean re #더미 정리 및 충돌 피하기
clean: #.o .d 파일 삭제
	rm -f *.o *.d
fclean: clean #실행파일 삭제
	rm -f $(TARGET) 
re: fclean all #모든 파일 삭제
test: #노미네트 검사
	norminette -R CheckForbiddenSourceHeader

# object 파일들은 전부 .c 파일을 컴파일해서 생성
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

#BSQ 실행 -> object 파일들 전부 불러오고 컴파일
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

#무시 파일 설정
-include $(DEPS)