#include <SFML/Graphics.hpp>
#include <iostrem>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>

class DataStorage
{
    public:
	    DataStorage();
	    bool CreateObject (GameObject);
		bool DeleteObject (std:: string);
		Game Object* GetObject (std::string);
};

