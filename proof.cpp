#include "proof.h"
#include<iostream>

using namespace PoW;
using namespace std;

void Proof::printProof()
{
    cout << "\tThe solution:\n " << this->inp.makeString() << '\n';
    cout << "\tResulting nonce: " << this->inp.getNonce() << '\n';
    cout << "\tHash value: " << this->hash << '\n';
}

bool Proof::validateProof()
{
    return (sha256(sha256(this->inp.makeString())) == this->hash);
}