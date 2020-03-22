#pragma once
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <boost/functional/hash.hpp>

#include "NeuralInputInterface.h"

typedef std::pair<uint32_t, uint32_t> PixelPoint;
typedef std::unordered_set<uint32_t> NodeIdSet;

class VisualInputer {
public:
    VisualInputer(uint32_t height, uint32_t width, NeuralInputInterface *neural);
    virtual ~VisualInputer();

    void updateImage(cv::Mat* image);
private:
    NeuralInputInterface *input;
    std::unordered_map<PixelPoint, NodeIdSet, boost::hash<PixelPoint> >pixelMap;
    uint32_t width;
    uint32_t height;

    void addMission(uint32_t nodeId);

    //1d id convert to 3d
    /*
     * TODO:
     * Create mission list from set of nodes,
     * do a neural id <-> pixel space mapping
     * (x,y,r,g,b) have 8 bit of data
     */

};