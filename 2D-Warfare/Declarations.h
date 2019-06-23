#pragma once
bool Entities::loaded = false;
Texture* Entities::texture;
std::vector<Texture*> Entities::textures;
Vector2f Map::mapSize;
std::vector<Playables*> Playables::objects;
bool MainScreen::exited;
int MainScreen::numberofPlayers;
Font* Entities::font;
std::unique_ptr<MainScreen> ptr;
std::unique_ptr<Window_Manager> engineptr;