#include "gameObjectManager.h"

gameObjectManager::gameObjectManager() {
	gameObjectMap_.clear();
	nextFreeId_ = 0;
}

