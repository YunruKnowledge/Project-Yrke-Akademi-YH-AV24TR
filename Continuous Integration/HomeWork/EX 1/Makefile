BUILD_DIR = Build

MAIN_DIR = Src
LIBRARY_DIR = Lib
TEST_DIR = Test

#SOURCES = index.cpp fizzbuzz.cpp test.cpp
#OBJECTS = $(SOURCES:%.cpp=$(SOURCES)%(BUILD_DIR)%.o)

# Targets for building the executable
$(BUILD_DIR)/app: $(BUILD_DIR) $(BUILD_DIR)/index.o $(BUILD_DIR)/fizzbuzz.o
	@g++ $(BUILD_DIR)/index.o $(BUILD_DIR)/fizzbuzz.o -o $(BUILD_DIR)/app

$(BUILD_DIR)/test: $(BUILD_DIR) $(BUILD_DIR)/test.o $(BUILD_DIR)/fizzbuzz.o
	@g++ $(BUILD_DIR)/test.o $(BUILD_DIR)/fizzbuzz.o -lunity -o $(BUILD_DIR)/test

# Targets for object files
$(BUILD_DIR)/index.o: ./$(MAIN_DIR)/index.cpp ./$(LIBRARY_DIR)/fizzbuzz.h
	@g++ -c ./$(MAIN_DIR)/index.cpp -I./$(LIBRARY_DIR) -o $(BUILD_DIR)/index.o

$(BUILD_DIR)/fizzbuzz.o: ./$(LIBRARY_DIR)/fizzbuzz.cpp ./$(LIBRARY_DIR)/fizzbuzz.h
	@g++ -c ./$(LIBRARY_DIR)/fizzbuzz.cpp -I./$(LIBRARY_DIR) -o $(BUILD_DIR)/fizzbuzz.o

$(BUILD_DIR)/test.o: ./$(TEST_DIR)/test.cpp ./$(LIBRARY_DIR)/fizzbuzz.h
	@g++ -c ./$(TEST_DIR)/test.cpp -I./$(LIBRARY_DIR) -o $(BUILD_DIR)/test.o

# Create $(BUILD_DIR) directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Run the application with argument 20
run: $(BUILD_DIR)/app
	@./$(BUILD_DIR)/app 20

# Run the tests
test: $(BUILD_DIR)/test
	@./$(BUILD_DIR)/test

# Clean the $(BUILD_DIR) directory
clean:
	@rm -rf $(BUILD_DIR)

# Declare that these targets don't correspond to actual files
.PHONY: clean run test
