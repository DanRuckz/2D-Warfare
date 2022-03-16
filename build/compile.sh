g++ -g -c /homes/bogdano/git_repos/2D-Warfare-old/src/*.cpp
g++ -no-pie *.o -o ../2D-Warfare -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -Wall -Wextra
