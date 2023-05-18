#include "LocationManagement.h"

LocationManagement::LocationManagement(){
    uint depth = 1;
    location_qtree(Vector2f{Map::getMapSize().x/2, Map::getMapSize().y/2}, depth);
}

LocationManagement::location_qtree::location_qtree(Vector2f center, uint depth): center(center), depth(depth){
    Vector2f size{Map::getMapSize().x/(2*depth), Map::getMapSize().y/(2*depth)};
    std::cout << "Depth: " << depth << '\n' << "Center: " << '(' << center.x << ", " << center.y << ')' << '\n' << "Size: " << '(' << size.x << ", " << size.y << ')' << '\n';
    ptr_top_left = nullptr;
    ptr_top_right = nullptr;
    ptr_bottom_left = nullptr;
    ptr_bottom_right = nullptr;
        if (depth <= 3){
            ptr_top_left = std::make_unique<location_qtree>(Vector2f{center.x - (center.x/2), center.y - (center.y/2)}, depth+=1);
            ptr_top_right = std::make_unique<location_qtree>(Vector2f{center.x + (center.x/2), center.y - (center.y/2)}, depth+=1);
            ptr_bottom_left = std::make_unique<location_qtree>(Vector2f{center.x - (center.x/2), center.y + (center.y/2)}, depth+=1);
            ptr_bottom_right = std::make_unique<location_qtree>(Vector2f{center.x + (center.x/2), center.y + (center.y/2)}, depth+=1);
    }
}