#ifndef COURSEWORK_MINER_H
#define COURSEWORK_MINER_H

#include <string>
#include "sha256.h"
#include "proof.h"

namespace PoW
{
    const uint32_t MAX_NONCE = 0xFFFFF;

    class Miner {
    public:
        Miner() {}

        Proof findProof(BHeader inp);
    };
}

#endif //COURSEWORK_MINER_H
