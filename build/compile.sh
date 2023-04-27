g++ -g -c ../src/*.cpp
g++ -no-pie *.o -o ../2D-Warfare -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++14 -Wall -Wextra
