CC := g++ -pthread

BUILD_DIR=build
SRC_DIR=.
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_image
OUTPUT_NAME=main.out

all: ${OUTPUT_NAME}

${OUTPUT_NAME}: rm mk ${BUILD_DIR}/main.o  ${BUILD_DIR}/tools.o ${BUILD_DIR}/window.o ${BUILD_DIR}/component.o
	$(CC) ${BUILD_DIR}/main.o ${BUILD_DIR}/tools.o ${BUILD_DIR}/window.o ${BUILD_DIR}/component.o ${COMPILER_FLAGS} ${LINKER_FLAGS} ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ./${OUTPUT_NAME}

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	$(CC) -c ${SRC_DIR}/main.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${BUILD_DIR}/main.o

${BUILD_DIR}/tools.o: ${SRC_DIR}/tools.cpp
	$(CC) -c ${SRC_DIR}/tools.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${BUILD_DIR}/tools.o

${BUILD_DIR}/window.o: ${SRC_DIR}/window.cpp
	$(CC) -c ${SRC_DIR}/window.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${BUILD_DIR}/window.o

${BUILD_DIR}/component.o: ${SRC_DIR}/component.cpp
	$(CC) -c ${SRC_DIR}/component.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${BUILD_DIR}/component.o

mk:
	mkdir ./${BUILD_DIR}

rm:
	rm -rf ${BUILD_DIR}/ ./${OUTPUT_NAME}