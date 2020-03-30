#include <SFML/Graphics.hpp>
#include <iostrem>
#include <fstream>
#include <vector>

class DataStorage
{
    public:
	    DataStorage();
	    bool createObject(GameObject game_object);
		bool deleteObject(std::string name);
		Game Object* GetObject (std::string name);
	private:
		std::vector<GameObject> objects;
};
