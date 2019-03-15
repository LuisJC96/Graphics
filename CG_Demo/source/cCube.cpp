//Luis Juan Centurión A01650501

//NPOT = Nearest Power Of Two

#include "cCube.h"

Cube::Cube(float side, bool use_mipmaps)
{

	this->side = side;
	hside = side / 2.0f;

	texture_id = 0;
	// Generate my texture ID (just 1):
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	GLfloat texture_data[TEX_SIDE][TEX_SIDE][3];
	for (int u = 0; u < TEX_SIDE; u++) {
		for (int v = 0; v < TEX_SIDE; v++) {
			texture_data[u][v][0] = (GLfloat)rand() / RAND_MAX;
			texture_data[u][v][1] = (GLfloat)rand() / RAND_MAX;
			texture_data[u][v][2] = (GLfloat)rand() / RAND_MAX;
		}
	}
	if (use_mipmaps) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D,
			3,
			TEX_SIDE,
			TEX_SIDE,
			GL_RGB,
			GL_FLOAT,
			texture_data);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGB,
			TEX_SIDE,
			TEX_SIDE,
			0,
			GL_RGB,
			GL_FLOAT,
			texture_data);
	}
	glBindTexture(GL_TEXTURE_2D, NULL);

}

Cube::~Cube(void)
{
	glDeleteTextures(1, &texture_id);
}

void Cube::draw(void)
{
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glBegin(GL_QUADS);//Front
	{
		glNormal3f(0.0f, 0.0f, 1.0f);//1
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);//2
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);//3
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);//4
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, hside);
	}
	glEnd();
	glBegin(GL_QUADS);//Right
	{
		glNormal3f(1.0f, 0.0f, 0.0f);//2
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(1.0f, 0.0f, 0.0f);//5
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, -hside, -hside);

		glNormal3f(1.0f, 0.0f, 0.0f);//6
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, -hside);

		glNormal3f(1.0f, 0.0f, 0.0f);//3
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, hside, hside);

	}
	glEnd();
	glBegin(GL_QUADS);//back
	{
		glNormal3f(0.0f, 0.0f, -1.0f);//5
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(hside, -hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);//7
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, -hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);//8
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-hside, hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);//6
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, hside, -hside);

		

	}
	glEnd();
	glBegin(GL_QUADS);//left
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);//7
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, -hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);//1
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);//4
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-hside, hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);//8
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, -hside);

	}
	glEnd();
	glBegin(GL_QUADS);//top
	{

		glNormal3f(0.0f, 1.0f, 0.0f);//4
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);//3
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);//6
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, -hside);

		glNormal3f(0.0f, 1.0f, 0.0f);//8
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, -hside);

	}
	glEnd();
	glBegin(GL_QUADS);//button
	{
		//2,1,3,5
		glNormal3f(0.0f, -1.0f, 0.0f);//2
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(0.0f, -1.0f, 0.0f);//1
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(0.0f, -1.0f, 0.0f);//3
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(0.0f, -1.0f, 0.0f);//5
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, -hside, -hside);

	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, NULL);
}