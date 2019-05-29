#pragma once
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )

#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif
#ifdef _WIN32
#include <direct.h>
// MSDN recommends against using getcwd & chdir names
#define cwd _getcwd
#define cd _chdir
#else
#include "unistd.h"
#define cwd getcwd
#define cd chdir
#endif
#pragma once
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
using namespace sf;
using std::vector;
const int VEC_SIZE = 25;
#define FULLSCREEN  Style::Fullscreen
#define WINDOW_MODE  Style::Resize | Style::Close
#define Fullscreen_Switch (Keyboard::isKeyPressed(Keyboard::LAlt) || Keyboard::isKeyPressed(Keyboard::RAlt)) && (Keyboard::isKeyPressed(Keyboard::Enter))
