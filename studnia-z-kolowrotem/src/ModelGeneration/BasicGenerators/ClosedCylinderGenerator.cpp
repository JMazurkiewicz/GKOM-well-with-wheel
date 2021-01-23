#include "ClosedCylinderGenerator.h"

void ClosedCylinderGenerator::constructModel() {
	CylinderGenerator::constructModel();
	if(getSampleRate() >= 4) {
		createConnections();
	}
}

void ClosedCylinderGenerator::createConnections() {
	const unsigned lastIndex = getSampleRate() - 1;
	for(unsigned index = 1; index < lastIndex; ++index) {
		const unsigned next = nextIndex(index);

		const IndexGroup upperTriangle{
			0 + getUpperCircleOffset(),
			index + getUpperCircleOffset(),
			next + getUpperCircleOffset()
		};
		indices.push_back(upperTriangle);

		const IndexGroup lowerTriangle{
			0 + getLowerCircleOffset(),
			index + getLowerCircleOffset(),
			next + getLowerCircleOffset()
		};
		indices.push_back(lowerTriangle);
	}
}

unsigned ClosedCylinderGenerator::nextIndex(unsigned index) {
	++index;
	if(index == getSampleRate()) {
		index = 0;
	}
	return index;
}
