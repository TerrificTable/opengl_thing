TO_COMPILE 	:= src/TT55/Shader/Shader.cpp src/TT55/EBO/EBO.cpp src/TT55/VBO/VBO.cpp src/TT55/VAO/VAO.cpp
SRC_FILES 	:= out/comp/* src/TT55/Shape/Shapes.cpp  out/libs/glad.o src/main.cpp
OUT_FILE	:= -o out/main
INCLUDE 	:= -Iinclude/

# LINK_DIR 	:= -Llib/s
LINKS 		:= lib/libglfw3.a -lGL -lX11 -lpthread -lXrandr -lXi -ldl



all: build run

build:
	@echo " [ Building ] "
	g++ $(INCLUDE) $(SRC_FILES) $(OUT_FILE) $(LINKS)
	@echo " [ Building ] "
	@echo ""
	
comp:
	g++ $(INCLUDE) -c $(TO_COMPILE)
	@mv *.o out/comp

glad_comp:
	g++ $(INCLUDE) -c include/glad/glad.c -o out/libs/glad.o

run:
	@echo " [ Run ] "
	@./out/main
	@echo " [ Run ] "
	@echo ""
	
