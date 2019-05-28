#pragma once
#include "intelmoc.h"
#include <cstdio>

intelmoc::intelmoc() {
	moc = MaskedOcclusionCulling::Create();
	printf("intelmoc initiated!\n");
}

intelmoc::~intelmoc() {
	MaskedOcclusionCulling::Destroy(moc);
	printf("intelmoc destroyed!\n");
}


MaskedOcclusionCulling *intelmoc::getMoc() {
	return moc;
}
