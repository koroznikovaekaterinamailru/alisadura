#include "user_api.h"

void ge::runApplication(){
	Singleton_R_C::runApplication();
}

bool ge::makeSprite(std::string object_name, std::string file_name){
	GameObject* obj = ge::getObject(object_name);
	if (obj->getComponent<Renderer>() != nullptr){
		obj->getComponent<Renderer>()->makeSprite(file_name);
		return true;
	}
	else return false;
}

void ge::createObject(std::string object_name){
	Singleton_R_C::getInstance()->data_storage.createObject(object_name);
}

void ge::deleteObject(std::string object_name){
	GameObject* obj = Singleton_R_C::getInstance()->data_storage.getObject(object_name);
	if (obj)
		obj->remove();
}

GameObject* ge::getObject(std::string object_name){
	return Singleton_R_C::getInstance()->data_storage.getObject(object_name);
}

void ge::setWindowSize(float x, float y){
	Singleton_R_C::getInstance()->render_controller.setWindowSize(x, y);
}

void ge::setWindowTitle(std::string title){
	Singleton_R_C::getInstance()->render_controller.setTitle(title);
}

void ge::setLayer(std::string object_name, int n){
	GameObject* obj = ge::getObject(object_name);
	if (n > Singleton_R_C::getInstance()->render_controller.getLayersCount())
		Singleton_R_C::getInstance()->render_controller.setLayersCount(n);
	if (obj->getComponent<Renderer>()){
		obj->getComponent<Renderer>()->setLayer(n);
	}
}

void ge::makeAnimation(std::string object_name, float x, float y, float w, float h, int count, float speed){
	GameObject* obj = ge::getObject(object_name);
	if (obj)
		obj->getComponent<Renderer>()->makeAnimation(x, y, w, h, count, speed);
}

	





