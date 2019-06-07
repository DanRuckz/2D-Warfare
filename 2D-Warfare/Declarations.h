#pragma once
bool Entities::loaded = false;
Texture* Entities::texture;
std::vector<Texture*> Entities::textures;
Vector2f Map::mapSize;
std::vector<Playables*> Playables::objects;
std::vector<std::shared_ptr<Projectiles>> Projectiles::projectilesVector;