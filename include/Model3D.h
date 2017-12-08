#ifndef __MODEL_3D_H__
#define __MODEL_3D_H__

#include <GL/glew.h>

class Model3D {

public:
	
	Model3D(); //TODO should be private:load from file
	Model3D(float r, float g, float b); //TODO should be private:load from file
	
	void bindVAO() const; // TODO may be not const
	void unbindVAO() const;
	
	GLsizei count() const;

private:

	// TODO model may have a matrix for init transform (scale, ...) 

	GLuint vao;

};

#endif