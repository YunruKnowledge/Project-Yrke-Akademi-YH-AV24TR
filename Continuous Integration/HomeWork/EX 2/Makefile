CC = c++
CFLAGS = -Wall

LIB_DIR = lib
UNITY_DIR = unity
BUILD_DIR = build

TEST_EXE = test
MAIN_EXE = main

INCLUDES = $(wildcard $(LIB_DIR)/*/*.h)
INCLUDES := $(sort $(dir $(INCLUDES)))
INCLUDES := $(addprefix -I./, $(INCLUDES:%/=%))

OBJECTS := $(notdir $(shell find . -name *.cpp))
OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS:%.cpp=%.o))

TEST_OBJS := $(filter-out $(BUILD_DIR)/$(MAIN_EXE).o, $(OBJECTS))
MAIN_OBJS := $(filter-out $(BUILD_DIR)/$(TEST_EXE).o $(BUILD_DIR)/$(UNITY_DIR).o, $(OBJECTS))

all: .mkbuild
	@echo "==================== Targets ===================="
	@echo "==> clean: to clean the project"
	@echo "==> check: to build and run the test"
	@echo "==> run NUM=xxx: to build and run main"
	@echo "        A number shall be passed to the program"
	@echo "================================================="

$(BUILD_DIR)/$(MAIN_EXE) : $(MAIN_OBJS)
	@$(CC) $^ -o $@

$(BUILD_DIR)/$(TEST_EXE) : $(TEST_OBJS)
	@$(CC) $^ -o $@

$(BUILD_DIR)/%.o: */%.cpp
	@$(CC) -MMD -c $< $(INCLUDES) -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/*/%.cpp
	@$(CC) -MMD -c $< $(INCLUDES) -o $@

-include $(OBJECTS:.o=.d)

run: .mkbuild $(BUILD_DIR)/$(MAIN_EXE)
	@echo "=================================="
	@echo "====== Run The Main Program ======"
	@echo "=================================="
	@./$(BUILD_DIR)/$(MAIN_EXE) $(NUM)

check: .mkbuild $(BUILD_DIR)/$(TEST_EXE)
	@echo "=================================="
	@echo "====== Run The Test Program ======"
	@echo "=================================="
	@./$(BUILD_DIR)/$(TEST_EXE)

.mkbuild: 
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all .mkbuild clean run check