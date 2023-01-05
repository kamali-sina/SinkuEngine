CC := g++ -pthread

BUILD_DIR=build
SRC_DIR=./src
COMPILER_FLAGS = -w -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
LINKER_FLAGS = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
OUTPUT_NAME=game.out

all: ${OUTPUT_NAME}

${OUTPUT_NAME}: rm mk ${BUILD_DIR}/main.o 
	$(CC) ${BUILD_DIR}/main.o ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ./${OUTPUT_NAME}

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	$(CC) -c ${SRC_DIR}/main.cpp ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ${BUILD_DIR}/main.o

run: ${OUTPUT_NAME}
	./${OUTPUT_NAME}

mk:
	mkdir ./${BUILD_DIR}

rm:
	rm -rf ${BUILD_DIR}/ ./${OUTPUT_NAME}