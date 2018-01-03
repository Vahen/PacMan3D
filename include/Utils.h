#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>
#include <map>
#include <glm/vec3.hpp>
#include <SDL/SDL_keysym.h>
#include <algorithm>

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
	
	static string orientationToString(Utils::Orientation orientation);

	static float degreesOfOrientation(Utils::Orientation orientation);
	
	static glm::vec3 vectorOfOrientation(Utils::Orientation orientation);

	static Utils::Orientation randomOrientation();

	static Utils::Orientation randomOrientation(vector<Utils::Orientation> orientations);

	static Utils::Orientation oppositeOrientation(Utils::Orientation orientation);

	static Utils::Orientation relativeOrientation(Utils::Orientation viewOrientation, Utils::Orientation orientation);

	template<typename T>
	static vector<T> intersection(vector<T> a, vector<T> b) {
		vector<T> sa(a);
		vector<T> sb(b);
		vector<T> result;
		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());
		set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(result));
		return result;
	};
	
	template<typename T>
	static void cleanVector(vector<T *> vector) {
		for (T *value : vector) {
			delete value;
		}
	};

	template<typename K, typename V>
	static void cleanMap(map<K, V *> map) {
		for (auto &entry : map) {
			delete entry.second;
		}
	};

	static SDLKey stringToKey(string s);

	static string keyToString(SDLKey key);

	static string stringToUpper(string str);

private:

	Utils() = default;

};

#endif
