CC = gcc
CFLAGS = -I./incl
LDFLAGS = -L./lib
LDLIBS = -l_strfun

OBJ_DIR = ./obj

SRCS = $(wildcard ./src/*.c)
OBJS = $(patsubst ./src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET = run

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
