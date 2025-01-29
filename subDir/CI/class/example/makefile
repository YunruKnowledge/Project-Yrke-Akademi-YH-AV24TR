
#Variables
COMPILER = g++
BUILD_DIR = build

#*use [%] to search and apply.
SOURCE = main.o data.o display.o
OBJECT = $(SOURCE:%.o=$(BUILD_DIR)/%.o)

#*autorun
.DEFAULT_GOAL:=run

#[filename]: [list_of_files_look_for_changes]
#[tab_4_spaces][commands_upon_change]
#*commands are executed per line on their own bash session.

$(BUILD_DIR)/app: $(OBJECT)
		$(COMPILER) $^ -o $(BUILD_DIR)/app

$(BUILD_DIR)/main.o: main.cpp data.h display.h
		$(COMPILER) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/data.o: data.cpp data.h
		$(COMPILER) -c data.cpp -o $(BUILD_DIR)/data.o

$(BUILD_DIR)/display.o: display.cpp display.h
		$(COMPILER) -c display.cpp -o $(BUILD_DIR)/display.o

run: $(BUILD_DIR)/app
		$(BUILD_DIR)/app

.build:
		mkdir -p $(BUILD_DIR)/

clean:
		rm -f ./$(BUILD_DIR)/*.o

#*use [\] for line breaks
#*use [@] for hiding console prints.
test:
	@echo "nah id \
	win"

#*[.PHONY] allows you to call the variables/clauses directly. E.g: make clean
.PHONY: clean test