#ifndef INTELMOC_H
#define INTELMOC_H
#include "thirdparty/glm/glm/glm/ext.hpp"
#include "MaskedOcclusionCulling.h"


static bool depth_shoot = false;
static int d_shot_delay = 0;
void WriteBMP(const char *filename, const unsigned char *data, int w, int h);
void TonemapDepth(float *depth, unsigned char *image, int w, int h);

class intelmoc
{
public:
	MaskedOcclusionCulling *moc;
	MaskedOcclusionCulling *getMoc();
	/* TODO
			void saveDepthBufferAsBPM();
	*/
	intelmoc();
	~intelmoc();

};


#endif
