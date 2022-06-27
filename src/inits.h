#pragma once
#include "unistd.h"
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
using namespace sf;
using std::vector;
extern VideoMode resolution;
const int VEC_SIZE = 25;
#define FULLSCREEN  Style::Fullscreen
#define WINDOW_MODE  Style::Resize | Style::Close
#define Fullscreen_Switch (Keyboard::isKeyPressed(Keyboard::LAlt) || Keyboard::isKeyPressed(Keyboard::RAlt)) && (Keyboard::isKeyPressed(Keyboard::Enter))
#define OBJ Playables::getObjectsVector()
