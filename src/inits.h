#pragma once
#include "unistd.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <memory>
#include <random>
using namespace sf;
using std::vector;
const int VEC_SIZE = 25;
#define FULLSCREEN  Style::Fullscreen
#define WINDOW_MODE  Style::Resize | Style::Close
#define BORDERLESS 0
#define Fullscreen_Switch (Keyboard::isKeyPressed(Keyboard::LAlt) || Keyboard::isKeyPressed(Keyboard::RAlt)) && (Keyboard::isKeyPressed(Keyboard::Enter))
#define OBJ Playables::getObjectsVector()
#define EXITGAME 0
#define MENUSCREEN 1
#define GAMESCREEN 2
#define FIRSTSCREEN 3
