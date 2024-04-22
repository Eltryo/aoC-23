DAY :=
INPUT :=

SRC_DIR := src
DAY_SRC_DIR := $(SRC_DIR)/$(DAY)

MAIN_SOURCES := $(SRC_DIR)/main.c $(DAY_SRC_DIR)/solve.c

TEST_SOURCES := $(DAY_SRC_DIR)/test.c $(DAY_SRC_DIR)/solve.c

LIB_DIR := lib
LIB_SOURCES := $(wildcard $(LIB_DIR)/*.c)

BUILD_DIR := build
LIB_OBJECTS := $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_SOURCES))

BIN_DIR := bin
LIB := $(BIN_DIR)/libutils.so

CFLAGS := -Werror -fsanitize=address
LDFLAGS := -L./$(BIN_DIR) -lutils

main: $(MAIN_SOURCES) $(LIB)
	export LD_LIBRARY_PATH=bin:$${LD_LIBRARY_PATH}; \
    gcc $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/main $(MAIN_SOURCES); \
    $(BIN_DIR)/main $(DAY) $(INPUT);

test: $(TEST_SOURCES) $(LIB)
	export LD_LIBRARY_PATH=bin:$${LD_LIBRARY_PATH}; \
    gcc $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/test $(TEST_SOURCES); \
    $(BIN_DIR)/test;

$(LIB): $(LIB_OBJECTS)
	gcc -shared -o $(BIN_DIR)/libutils.so $^

$(LIB_OBJECTS): $(LIB_SOURCES)
	@mkdir -p $(BUILD_DIR); \
    gcc -fPIC $(CFLAGS) -o $@ -c $<

day%: 
	mkdir $(SRC_DIR)/$@;
	mkdir input/$@;
	cp src/template/* src/$@;
	cp input/template/* input/$@;

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
