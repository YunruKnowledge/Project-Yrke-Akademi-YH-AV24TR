CC = c++
CFLAGS = -MMD -c

LIB_DIR = lib
BUILD_DIR = build

TEST_EXE = test
MAIN_EXE = main

INCLUDES = $(wildcard $(LIB_DIR)/*/*.h) #Find all .h Files!
INCLUDES := $(sort $(dir $(INCLUDES))) # Sort all dir 
INCLUDES := $(addprefix -I./, $(INCLUDES:%/=%)) # Add -I as prefix and remove / from Includes

OBJECTS := $(notdir $(shell find . -name *.cpp)) # Use shell command to find all .cpp excluding all directories
OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS:%.cpp=%.o)) # Add build prefix and turn all object .cpp to .o

TEST_OBJ = $(filter-out $(BUILD_DIR)/$(MAIN_EXE).o, $(OBJECTS)) #Filter out main files from the test
MAIN_OBJ = $(filter-out $(BUILD_DIR)/$(TEST_EXE).o, $(OBJECTS)) #Filter out test files from the main

all: .mkbuild
	@echo "==================== Targets ===================="
	@echo "==> clean: to clean the project"
	@echo "==> check: to build and run the test"
	@echo "==> run NUM=xxx: to build and run main"
	@echo "        A number shall be passed to the program"
	@echo "================================================="

$(BUILD_DIR)/$(MAIN_EXE) : $(MAIN_OBJ) #build main files
	@$(CC) $^ -o $@

$(BUILD_DIR)/$(TEST_EXE) : $(TEST_OBJ) #build test files
	@$(CC) $^ -lunity -o $@

$(BUILD_DIR)/%.o : */%.cpp 			  #compile all the cpp files
	@$(CC) $(CFLAGS) $< $(INCLUDES) -Wall -o $@

$(BUILD_DIR)/%.o : $(LIB_DIR)/*/%.cpp #compile all lib cpp files
	@$(CC) $(CFLAGS) $< $(INCLUDES) -Wall -o $@

-include $(OBJECTS:.o=.d)

run: .mkbuild $(BUILD_DIR)/$(MAIN_EXE) #run build for main files
	@echo "=================================="
	@echo "====== Run The Main Program ======"
	@echo "=================================="
	@./$(BUILD_DIR)/$(MAIN_EXE) $(NUM)

check: .mkbuild $(BUILD_DIR)/$(TEST_EXE) #run build for test files
	@echo "=================================="
	@echo "====== Run The Test Program ======"
	@echo "=================================="
	@./$(BUILD_DIR)/$(TEST_EXE)

.mkbuild: 								 # Build the file if it doesn't exist
	@mkdir -p $(BUILD_DIR)

clean:									 # Delete build file
	@rm -rf $(BUILD_DIR) 				

.PHONY: all .mkbuild clean run check