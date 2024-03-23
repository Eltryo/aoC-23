DAY :=
INPUT :=

SRC_DIR := src
DAY_SRC_DIR := $(SRC_DIR)/$(DAY)
MAIN_SOURCES := $(SRC_DIR)/main.c $(DAY_SRC_DIR)/partOne.c

#TODO: implement possibility to test library functions
TEST_SOURCES := $(DAY_SRC_DIR)/test.c $(DAY_SRC_DIR)/partOne.c

LIB_DIR := lib
LIB_SOURCES := $(wildcard $(LIB_DIR)/*.c)

BUILD_DIR := build
LIB_OBJECTS := $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_SOURCES))

BIN_DIR := bin

CFLAGS := -Werror -fsanitize=address
LDFLAGS := -L./$(BIN_DIR) -lutils 

main: $(MAIN_SOURCES) $(BIN_DIR)/libutils.so
	export LD_LIBRARY_PATH=bin:$${LD_LIBRARY_PATH}; \
    gcc $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/main $(MAIN_SOURCES); \
    $(BIN_DIR)/main $(DAY);

test: $(TEST_SOURCES) $(BIN_DIR)/libutils.so
	export LD_LIBRARY_PATH=bin:$${LD_LIBRARY_PATH}; \
    gcc $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/test $(TEST_SOURCES); \
    $(BIN_DIR)/test;

$(BIN_DIR)/libutils.so: $(LIB_OBJECTS)
	gcc -shared -o $(BIN_DIR)/libutils.so $^

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(BUILD_DIR); \
    gcc -fPIC $(CFLAGS) -o $@ -c $<

$(TEST_SOURCES):

day%: 
	mkdir $(SRC_DIR)/$@;
	mkdir input/$@;
	cp src/template/* src/$@;
	cp input/template/* input/$@;

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
