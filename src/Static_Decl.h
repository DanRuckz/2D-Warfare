bool Entities::loaded = false;
Texture* Entities::texture;
std::vector<Texture*> Entities::textures;
Vector2f Map::mapSize;
std::vector<Playables*> Playables::objects;
int MainMenuObjects::numberofPlayers;
Font* Entities::font;
MainMenuObjects* MainMenuObjects::instance = nullptr;
int Component::currentWindow = 0;
