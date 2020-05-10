#include "data_storage.h"

DataStorage* DataStorage::getInstance(){

    if(!instance){
        instance = new DataStorage();
    }
    return instance;
};
DataStorage* DataStorage::instance = NULL;

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

