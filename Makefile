CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -fPIC
LDFLAGS := -lm

SRC_DIR := src
LIB_DIR := lib
BIN_DIR := bin

LIB_SOURCES := $(wildcard $(LIB_DIR)/*.c)
LIB_SHARED := $(LIB_SOURCES:.c=.so)
MAIN_SRC := $(SRC_DIR)/electrotest.c
MAIN_OBJ := $(MAIN_SRC:.c=.o)
MAIN := $(BIN_DIR)/electrotest

INSTALL_PATH := /usr/lib/

all: lib $(MAIN)

lib: $(LIB_SHARED)

%.so: %.c
	$(CC) $(CFLAGS) -shared -o $@ $<

$(MAIN): $(MAIN_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -Wl,-rpath,$(INSTALL_PATH) -Wl,-rpath,$(LIB_DIR) -o $@ $^ -L$(LIB_DIR) $(LDFLAGS) -lcomponent -lpower -lresistance

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

install: all
	install -m 755 $(MAIN) /usr/bin/
	install -m 644 $(BIN_DIR)/libresistance.so $(INSTALL_PATH)
	install -m 644 $(BIN_DIR)/libcomponent.so $(INSTALL_PATH)
	install -m 644 $(BIN_DIR)/libpower.so $(INSTALL_PATH)

clean:
	rm -f $(LIB_DIR)/*.so $(SRC_DIR)/*.o $(MAIN)

.PHONY: all lib install clean
