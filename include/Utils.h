#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>
#include <map>

using namespace std;

class Utils {

public:

	enum class Orientation {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
	
	static const string SHADER_PATH;
	
	static Utils::Orientation orientationFromString(string strOrientation);

	static float degreesOfOrientation(Utils::Orientation orientation);
	
	static Utils::Orientation randomOrientation();
	static Utils::Orientation randomOrientation(vector<Utils::Orientation> orientations);
	
	static Utils::Orientation oppositeOrientation(Utils::Orientation orientation);
	
	template<typename T>
	static void cleanVector(vector<T*> vector) {
		for (T * value : vector) {
			delete value;
		}
	}
	
	template<typename K, typename V>
	static void cleanMap(map<K, V*> map) {
		//TODO
	}

private:

	Utils() = default;

};

#endif
