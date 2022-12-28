#include "inits.h"
#include "Entities.h"

class MainMenuObjects : public Entities
{
public:


	MainMenuObjects();
	~MainMenuObjects();
	void initialize();
	Sound menuMusic;
	Sprite backgroundSprite;
	Sprite arrowUp;
	Sprite arrowDown;
	Sprite Play;
	Sprite Exit;
	Sprite Players;
	Sprite Rect;
	Font font;
	Text number;
	SoundBuffer sb;
	int numberofPlayers = 1;

private:
	Entities* baseptr;

	};