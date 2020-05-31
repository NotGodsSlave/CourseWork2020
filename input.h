#ifndef COURSEWORK_INPUT_H
#define COURSEWORK_INPUT_H

#include <string>
#include "sha256.h"

namespace PoW
{
    const uint32_t VERSION = 1;
    const uint32_t DIFF = 4;

    class BHeader
    {
    public:
        BHeader();
        BHeader(uint32_t diff);
        BHeader(uint32_t diff, std::string prev_hash, std::string mrkl_root);
        void setNonce(uint32_t finalNonce);
        uint32_t getNonce();
        std::string makeString();
        void updateTimestamp();
        uint32_t getDiff();
    private:
        uint32_t timestamp;
        uint32_t version;
        uint32_t diff;
        std::string prev_hash;
        std::string mrkl_root;
        uint32_t nonce;
    };
}

#endif //COURSEWORK_INPUT_H
