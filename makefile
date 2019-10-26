all: buildFrontend link
withEngine: buildEngine buildFrontend link
link:
	@g++  build/Frontend.o  build/olcPixelGameEngine.o -pthread -lpng -lX11 -lGL
buildFrontend:
	@g++ -c src/Frontend.cpp -o build/Frontend.o
buildEngine:
	@g++ -c olcPixelGameEngine/olcPixelGameEngine.cpp -o build/olcPixelGameEngine.o
