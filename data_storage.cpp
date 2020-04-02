#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_object.h"
#include <vector>
#include <map>

class GameObject;

class DataStorage
{
    public:
	    DataStorage();
	    bool createObject(std::string name, GameObject* object);
		bool deleteObject(std::string name);
		GameObject* getObject(std::string name);
	private:
		std::map<std::string, GameObject*> objects;
};

bool DataStorage::createObject(std::string name , GameObject* object)
{
    if(objects[name] = object)
      	return true;
    else 
    	return false;
}

bool DataStorage::deleteObject(std::string name)
{
    if(objects.count(name) == 1)
    {
        delete objects[name];
        objects.erase(name);
        return true;
    }
    return false;
}

GameObject* DataStorage::getObject(std::string name)
{
    return objects[name];
}

#endif//DATA_STORAGE_H
