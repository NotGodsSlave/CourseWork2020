#ifndef COURSEWORK_PROOF_H
#define COURSEWORK_PROOF_H

#include <cstdint>
#include <string>
#include "input.h"

namespace PoW
{
    struct Proof
    {
        BHeader inp;
        std::string hash;

        Proof() : inp(BHeader()),  hash(""){};
        Proof(BHeader inp, std::string hash) : inp(inp),hash(hash){};

        void printProof();
        bool validateProof();
    };
}

#endif //COURSEWORK_PROOF_H
