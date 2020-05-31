#include "miner.h"
#include<iostream>
#include<string>

using namespace PoW;

Proof Miner::findProof(BHeader inp)
{
    uint32_t nonce = 0;
    std::string ans;
    while (true)
    {
        while (nonce < MAX_NONCE)
        {
            inp.setNonce(nonce);
            std::string in = inp.makeString();
            Proof pf;
            std::string test = sha256(sha256(in));
            /*if (nonce%10000 == 1)
            {
                std::cout << nonce << " " << test << '\n';
            }*/
            bool is_solution = true;
            for (int i = 0; i < inp.getDiff(); ++i)
            {
                if (test[i] != '0') is_solution = false;
            }
            if (is_solution)
            {
                return Proof(inp, test);
            }
            nonce++;
        }
        inp.updateTimestamp();
        nonce = 0;
    }
}
