#include "VisualInputer.h"

#include <iostream>

VisualInputer::VisualInputer(uint32_t height, uint32_t width, NeuralInputInterface *input) {
    this->width = width;
    this->height = height;
    this->input = input;

    uint32_t range = width * height * 24;
    std::unordered_set<uint32_t> nodeIdSet = input->getInputNodeIds(range);
    for (auto it = nodeIdSet.begin(); it != nodeIdSet.end(); ++it) {
        this->addMission(*it);
    }
}

VisualInputer::~VisualInputer() {
}

void VisualInputer::updateImage(cv::Mat* image) {
    this->input->reset();
    for (auto it = this->pixelMap.begin(); it != this->pixelMap.end(); ++it) {
        uint32_t y = it->first.first;
        uint32_t x = it->first.second;
        cv::Vec3b intensity = image->at<cv::Vec3b>(y, x);

        auto nodeSet = it->second;
        for (auto nodeIterator = nodeSet.begin(); nodeIterator != nodeSet.end(); ++nodeIterator) {
            uint32_t nodeId = *nodeIterator;
            uint8_t data = (*nodeIterator) - (y * this->width + x)*24;
            uint8_t colorId = data / 8;
            uint8_t mask = 0x1 << (data % 8);
            uchar color = intensity.val[colorId];
            this->input->setValue(nodeId, color & mask);
        }
    }
}

/**
 * Add a input mission
 * 
 * @param nodeId
 */
void VisualInputer::addMission(uint32_t nodeId) {
    uint32_t pixel1D = nodeId / 24;
    uint32_t y = pixel1D / width;
    uint32_t x = pixel1D % width;

    auto search = this->pixelMap.find(std::make_pair(y, x));
    if (search != this->pixelMap.end()) {
        search->second.insert(nodeId);
    } else {
        NodeIdSet set({nodeId});
        auto data = std::make_pair(std::make_pair(y, x), set);
        this->pixelMap.insert(data);
    }
}