#OS X compilation flags
CPPFLAGS=-Wno-deprecated-declarations -I. 
LDFLAGS= -framework GLUT -framework OpenGL -lstdc++ -O3 -lIL -lILU -framework GLUI

compile:
	g++ -o main.out main.cpp shader_utils.cpp gl_utils.cpp camera.cpp vector3D.cpp world.cpp sphere.cpp triangle.cpp quadric.cpp renderengine.cpp color.cpp ray.cpp material.cpp pointlightsource.cpp -lIL -lILU -lglut -lGL -lglui -lGLEW -Wno-deprecated-declarations -O3 -fopenmp -std=c++11
	#g++ -o main.out main.cpp shader_utils.cpp gl_utils.cpp camera.cpp vector3D.cpp world.cpp sphere.cpp triangle.cpp quadric.cpp renderengine.cpp color.cpp ray.cpp material.cpp pointlightsource.cpp ${CPPFLAGS} ${LDFLAGS} -std=c++11

run: compile
	./main.out 900 600

clean:
	rm -f main.out
