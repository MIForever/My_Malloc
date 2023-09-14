CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -g3
SOURCES = main.c src/*.c
TARGET = my_malloc

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:
	fclean

fclean:
	@rm -f $(OBJECTS) $(TARGET)