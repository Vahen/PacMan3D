#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <glimac/Program.hpp>
#include <PointOfView.h>
#include <ColorText2DRenderer.h>

using namespace glimac;

class Renderer3D : public Renderer {

public:

	Renderer3D(int windowWidth, int windowHeight, const PointOfView &pointOfView,
	           const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> &map_model3D);

	void renderGame(const GameRepresentation &repr, const GameInformations &gameInfo) const override;

	void renderBeginTitle() const override;

	void renderBeginGame() const override;

	void renderPauseMenu(const map<control, SDLKey> &keyMap) const override;

	void renderEndTitle(const GameInformations &gameInfo) const override;

	~Renderer3D() override;

private:

	mat4 _ProjMatrix;
	const PointOfView &_pointOfView;
	map<GameRepresentation::ModelType, AbstractModel3D *> _models;
	ColorText2DRenderer _textRenderer;

	void renderModels(const GameRepresentation &repr) const;

	void renderTexts(const GameInformations &informations) const;

};

#endif
