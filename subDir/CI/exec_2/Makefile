


CC = g++
CFLAGS = -Wall

LIB_DIR = lib
UNITY_DIR = unity
BUILD_DIR = build

TEST_FILENAME = test
MAIN_FILENAME = main

INCLUDES = ${wildcard ${LIB_DIR}/*/*.h}
INCLUDES := ${sort ${dir ${INCLUDES}}}
INCLUDES := ${addprefix -I./, ${INCLUDES:%/=%}}

OBJECTS := ${notdir ${shell find . -name *.cpp}}
OBJECTS := ${addprefix ${BUILD_DIR}/, ${OBJECTS:%.cpp=%.o}}

TEST_OBJS := ${filter-out ${BUILD_DIR}/${MAIN_FILENAME}.o, ${OBJECTS}}
MAIN_OBJS := ${filter-out ${BUILD_DIR}/${TEST_FILENAME}.o ${BUILD_DIR}/${UNITY_DIR}.o, ${OBJECTS}}

all: .mkbuild
	@echo ">> Targets:"
	@echo "> clean"
	@echo "> check"
	@echo "> run NUM=XX"

${BUILD_DIR}/${MAIN_FILENAME}: ${MAIN_OBJS}
	@g++ $^ -o $@

${BUILD_DIR}/${TEST_FILENAME}: ${TEST_OBJS}
	@g++ $^ -o $@

${BUILD_DIR}/%.o: */%.cpp
	g++ -MMD -c $< ${INCLUDES} -o $@

${BUILD_DIR}/%.o: ${LIB_DIR}/*/%.cpp
	g++ -MMD -c $< ${INCLUDES} -o $@

-include ${OBJECTS:.o=.d}

run: .mkbuild ${BUILD_DIR}/${MAIN_FILENAME}
	@echo ">> Running main program."
	@./${BUILD_DIR}/${MAIN_FILENAME} ${NUM}

check: .mkbuild ${BUILD_DIR}/${TEST_FILENAME}
	@echo ">> Running test program."
	@./${BUILD_DIR}/${TEST_FILENAME}

.mkbuild:
	@mkdir -p ${BUILD_DIR}

clean:
	@rm -rf ${BUILD_DIR}

.PHONY: all .mkbuild clean run check
