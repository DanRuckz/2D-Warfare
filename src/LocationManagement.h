#include "inits.h"
#include "Map.h"
class LocationManagement{

    public:
        static LocationManagement& getInstance(){
            static LocationManagement instance;
            return instance;
        }
        

    private:
        LocationManagement();
        LocationManagement(const LocationManagement&) = delete;
        LocationManagement& operator=(const LocationManagement&) = delete;
        Vector2f center;
        struct location_qtree{
            location_qtree(Vector2f center, uint depth);
            std::unique_ptr<location_qtree> ptr_top_left;
            std::unique_ptr<location_qtree> ptr_top_right;
            std::unique_ptr<location_qtree> ptr_bottom_left;
            std::unique_ptr<location_qtree> ptr_bottom_right;
            Vector2f center;
            uint depth;
            uint tileSize = 125;
            uint areaSize = tileSize*10;
        };
};
