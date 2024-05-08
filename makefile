bin/main : src/main.cpp
	g++ src/main.cpp -o bin/main -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude       

run : bin/main
	./bin/main

bin/prueba : src/prueba.cpp
	g++ src/prueba.cpp -o bin/prueba -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude       

runPrueba : bin/prueba
	./bin/prueba
