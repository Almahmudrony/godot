#pragma once
#include "intelmoc.h"
#include <cstdio>
#include <algorithm>

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


void WriteBMP(const char *filename, const unsigned char *data, int w, int h)
{
	short header[] = { 0x4D42, 0, 0, 0, 0, 26, 0, 12, 0, (short)w, (short)h, 1, 24 };
	FILE *f = fopen(filename, "wb");
	fwrite(header, 1, sizeof(header), f);
	fwrite(data, 1, w * h * 3, f);
	fclose(f);
}

void TonemapDepth(float *depth, unsigned char *image, int w, int h)
{
	// Find min/max w coordinate (discard cleared pixels)
	float minW = FLT_MAX, maxW = 0.0f;
	for (int i = 0; i < w * h; ++i) {
		if (depth[i] > 0.0f) {
			minW = std::min(minW, depth[i]);
			maxW = std::max(maxW, depth[i]);
		}
	}

	// Tonemap depth values
	for (int i = 0; i < w * h; ++i) {
		int intensity = 0;
		if (depth[i] > 0)
			intensity = (unsigned char)(223.0 * (depth[i] - minW) / (maxW - minW) + 32.0);

		image[i * 3 + 0] = intensity;
		image[i * 3 + 1] = intensity;
		image[i * 3 + 2] = intensity;
	}
}
