#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_object.h"
#include <map>

class GameObject;

class DataStorage
{
    public:
	    bool createObject(std::string name, GameObject* object);
		bool deleteObject(std::string name);
		GameObject* getObject(std::string name);
        static DataStorage* getInstance();
	private:
        static DataStorage* instance;
		std::map<std::string, GameObject*> objects;
};

#endif//DATA_STORAGE_H
