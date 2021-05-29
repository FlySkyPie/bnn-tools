#pragma once
#include <string>
#include <cstdint>

typedef struct LinkDescriptorType LinkDescriptor;
struct LinkDescriptorType
{
    uint32_t from;
    uint32_t to;
    bool weight;
};

class EncoderBuffer {
public:
    EncoderBuffer(uint32_t scale);
    virtual ~EncoderBuffer();

    bool isEmpty();
    bool addLink(LinkDescriptor link);
    std::string dump();


private:
    uint32_t scale;
    uint32_t counter;
    uint32_t size;
    unsigned char weightBuffer;
    std::string stringBuffer;

    static std::string coverInt2String(uint32_t value, uint32_t size);
};
