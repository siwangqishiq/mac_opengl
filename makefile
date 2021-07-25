CC := g++

SRC_DIR := src
BUILD_DIR := build
STD := c++11
OUTPUT := output 

build_dir:
	mkdir -p ${BUILD_DIR}

compile: build_dir \
		${BUILD_DIR}/main.o 
		
# ${BUILD_DIR}/glad.o:${SRC_DIR}/glad.cpp
# 	${CC} -std=${STD} -c ${SRC_DIR}/glad.cpp -o ${BUILD_DIR}/glad.o -I include/ 

${BUILD_DIR}/main.o:${SRC_DIR}/main.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o -I include/  -Wdeprecated-declarations

link:compile
	${CC} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/main -Llib -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL -Wdeprecated-declarations
run:link
	${BUILD_DIR}/main

clean:
	rm -f ${BUILD_DIR}/*.o 
	rm -f ${BUILD_DIR}/main