#include "input.h"
#include<iostream>
#include<chrono>
#include<random>

using namespace std;
using namespace PoW;

std::string GenerateRandomString()
{
    srand(time(NULL));
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    string s = "";
    for (int i = 0; i < 80; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}

void BHeader::setNonce(uint32_t finalNonce) {
    nonce = finalNonce;
}

uint32_t BHeader::getDiff() {
    return diff;
}

BHeader::BHeader()
{
    this->diff = DIFF;
    this->prev_hash = sha256(GenerateRandomString());
    this->mrkl_root = sha256(GenerateRandomString());
    this->version = VERSION;
    this->nonce = 0;
    updateTimestamp();
}

BHeader::BHeader(uint32_t diff)
{
    this->diff = diff;
    this->prev_hash = sha256(GenerateRandomString());
    this->mrkl_root = sha256(GenerateRandomString());
    this->version = VERSION;
    this->nonce = 0;
    updateTimestamp();
}

BHeader::BHeader(uint32_t diff, std::string prev_hash, std::string mrkl_root)
{
    this->diff = diff;
    this->prev_hash = prev_hash;
    this->mrkl_root = mrkl_root;
    this->version = VERSION;
    this->nonce = 0;
    updateTimestamp();
}

uint32_t BHeader::getNonce() {
    return nonce;
}

void BHeader::updateTimestamp()
{
    const auto t = std::chrono::system_clock::now();
    timestamp = std::chrono::duration_cast<std::chrono::seconds>(t.time_since_epoch()).count();
}

string BHeader::makeString()
{
    string s = "";
    s+="01000000";
    s+=to_string(timestamp);
    s+=prev_hash;
    s+=mrkl_root;
    s+=to_string(diff);
    s+=to_string(nonce);
    return s;
}


