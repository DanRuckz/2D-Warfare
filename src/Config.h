#include <cstdlib>
#include <SFML/Window.hpp>
#define DEFAULT_WIDTH 1920
#define DEFAULT_HEIGHT 1080

class Config {
public:
    static Config& getInstance();


    void setResolution(uint width, uint height);
    sf::VideoMode getResolution() const{
        return resolution;
    };

private:
    Config();
    const uint m_def_width = DEFAULT_WIDTH;
    const uint m_def_height = DEFAULT_HEIGHT;
    sf::VideoMode resolution;
};
