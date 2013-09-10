#include "../include/Chest.hpp"


Chest::~Chest() {
	
}

SDL_Rect Chest::getCurrentFrame() {
	return frameCycle[getFrameKey()];
}

std::string Chest::getSpeech() {
	return speech;
}
void Chest::setSpeech(std::string text) {
	speech = text;
}

// associates a key string to an array of rectangles
// used for cutting walk frames
void Chest::generateSpriteFrame(SDL_Surface* tileImage, int tileWidth, int tileHeight) {
	int ctr=0;
	for (int i=0; i<tileImage->w;i+=tileWidth) {
    	for (int j=0; j<tileImage->h; j+=tileHeight) {
    		SDL_Rect temp;
    		temp.x = i;
    		temp.y = j;
    		temp.w = tileWidth;
    		temp.h = tileHeight;
    		frameCycle[keys[ctr]]=temp;
    		ctr++;
    	}
	}
}

// changes your direction by either updating the 
// frameCycle or setting it to the new direction
// fixme 100 could be a frame rate number
void Chest::updateSpriteFrame(std::string key, int ticks) {
	if (key.compare("UP")==0) {
		if (getFrameKey().compare("UP0")==0 || getFrameKey().compare("UP1")==0 || getFrameKey().compare("UP2")==0 || getFrameKey().compare("UP3")==0) {
			cycleSpriteFrame(ticks);
		}else {
			setFrameKey("UP1");
		}
	}else if (key.compare("DOWN")==0) {
		if (getFrameKey().compare("DOWN0")==0 || getFrameKey().compare("DOWN1")==0 || getFrameKey().compare("DOWN2")==0 || getFrameKey().compare("DOWN3")==0) {
			cycleSpriteFrame(ticks);
		}else {
			setFrameKey("DOWN1");
		}
	}else if (key.compare("LEFT")==0) {
		if (getFrameKey().compare("LEFT0")==0 || getFrameKey().compare("LEFT1")==0 || getFrameKey().compare("LEFT2")==0 || getFrameKey().compare("LEFT3")==0) {
			cycleSpriteFrame(ticks);
		}else {
			setFrameKey("LEFT0");
		}
	}else if (key.compare("RIGHT")==0) {
		if (getFrameKey().compare("RIGHT0")==0 || getFrameKey().compare("RIGHT1")==0 || getFrameKey().compare("RIGHT2")==0 || getFrameKey().compare("RIGHT3")==0) {
			cycleSpriteFrame(ticks);
		}else {
			setFrameKey("RIGHT0");
		}
	}
}

// altering the walk frames by
// changing the direction key
void Chest::cycleSpriteFrame() {
	// moving down
	if (getFrameKey().compare(keys[4]) == 0 ) {
		setFrameKey(keys[8]);
	}else if (getFrameKey().compare(keys[8]) == 0) {
		setFrameKey(keys[12]);
	}else if (getFrameKey().compare(keys[12]) == 0) {
		setFrameKey(keys[0]);
	}else if (getFrameKey().compare(keys[0]) == 0) {
		setFrameKey(keys[4]);
	}

	// moving up
	if (getFrameKey().compare(keys[5]) == 0) {
		setFrameKey(keys[9]);
	}else if (getFrameKey().compare(keys[9]) == 0) {
		setFrameKey(keys[13]);
	}else if (getFrameKey().compare(keys[13]) == 0) {
		setFrameKey(keys[1]);
	}else if (getFrameKey().compare(keys[1]) == 0) {
		setFrameKey(keys[5]);
	}

	// moving right
	if (getFrameKey().compare(keys[2]) == 0) {
		setFrameKey(keys[6]);
	}else if (getFrameKey().compare(keys[6]) == 0) {
		setFrameKey(keys[10]);
	}else if (getFrameKey().compare(keys[10]) == 0) {
		setFrameKey(keys[14]);
	}else if (getFrameKey().compare(keys[14]) == 0) {
		setFrameKey(keys[2]);
	}

	// moving left
	if (getFrameKey().compare(keys[3]) == 0) {
		setFrameKey(keys[7]);
	}else if (getFrameKey().compare(keys[7]) == 0) {
		setFrameKey(keys[11]);
	}else if (getFrameKey().compare(keys[11]) == 0) {
		setFrameKey(keys[15]);
	}else if (getFrameKey().compare(keys[15]) == 0) {
		setFrameKey(keys[3]);
	}
}


// altering the walk frames by
// changing the direction key
void Chest::cycleSpriteFrame(int ticks) {
	if ((ticks-lastUpdate)>100) {
		// moving down
		if (getFrameKey().compare(keys[4]) == 0 ) {
			setFrameKey(keys[8]);
		}else if (getFrameKey().compare(keys[8]) == 0) {
			setFrameKey(keys[12]);
		}else if (getFrameKey().compare(keys[12]) == 0) {
			setFrameKey(keys[0]);
		}else if (getFrameKey().compare(keys[0]) == 0) {
			setFrameKey(keys[4]);
		}

		// moving up
		if (getFrameKey().compare(keys[5]) == 0) {
			setFrameKey(keys[9]);
		}else if (getFrameKey().compare(keys[9]) == 0) {
			setFrameKey(keys[13]);
		}else if (getFrameKey().compare(keys[13]) == 0) {
			setFrameKey(keys[1]);
		}else if (getFrameKey().compare(keys[1]) == 0) {
			setFrameKey(keys[5]);
		}

		// moving right
		if (getFrameKey().compare(keys[2]) == 0) {
			setFrameKey(keys[6]);
		}else if (getFrameKey().compare(keys[6]) == 0) {
			setFrameKey(keys[10]);
		}else if (getFrameKey().compare(keys[10]) == 0) {
			setFrameKey(keys[14]);
		}else if (getFrameKey().compare(keys[14]) == 0) {
			setFrameKey(keys[2]);
		}

		// moving left
		if (getFrameKey().compare(keys[3]) == 0) {
			setFrameKey(keys[7]);
		}else if (getFrameKey().compare(keys[7]) == 0) {
			setFrameKey(keys[11]);
		}else if (getFrameKey().compare(keys[11]) == 0) {
			setFrameKey(keys[15]);
		}else if (getFrameKey().compare(keys[15]) == 0) {
			setFrameKey(keys[3]);
		}
		lastUpdate = ticks;
	}
}

void Chest::setOpen(bool to_me) {
	open = to_me;
}
bool Chest::getOpen() {
	return open;
}


IHoldable* Chest::getContents() {
	return contents;
}

void Chest::deleteConetents() {
	contents = NULL;
}



