#include "WellGlModelGenerator.h"

#include <cmath>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& rawModel)
	: rawModel{rawModel}, layerAngle{0},
	  creator{0, rawModel.getInnerRadius(), 0},
	  innerAngle{360.0f / rawModel.getSideCount()} { }

WellGlModel WellGlModelGenerator::generate() {
	for(unsigned layerIndex = 0; layerIndex < rawModel.getLayerCount(); ++layerIndex) {
		generateLayer(layerIndex);

		layerAngle = std::fmod(layerAngle + rawModel.getLayerRotationAngle(), 360.0f);
	}

	return std::move(glModel);
}

void WellGlModelGenerator::generateLayer(unsigned layerIndex) {
	
}

void WellGlModelGenerator::generateOneBrick() {
	BrickGlModel newBrick;

}
