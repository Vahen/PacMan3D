#include <GhostClyde.h>

Utils::Orientation GhostClyde::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::Model GhostClyde::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_CLYDE, Ghost::getOrientation());
}