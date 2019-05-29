#ifndef INTELMOC_H
#define INTELMOC_H
#include "MaskedOcclusionCulling.h"

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
