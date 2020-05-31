#include <iostream>
#include "miner.h"
#include<chrono>
#include<string.h>

using namespace std;
using namespace PoW;

void helpMessage()
{
    cout << "Usage: [-h] [-d D] [-i D H M]\n";
    cout << "Details:\n";
    cout << "\t-h prints this  message\n\t-d specify difficulty in D value\n\t-i specify difficulty, pervious block hash value and Merkle Root valuer\n";
}

int main(int argc, char *argv[]) {
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        helpMessage();
        exit(1);
    }
    int input_type = 0;
    int d = 0;
    string hsh, mrkl;
    if (argc > 1 && !strcmp(argv[1], "-d"))
    {
        input_type = 1;
        d = atoi(argv[2]);
    }
    else if (argc > 1 && !strcmp(argv[1], "-i"))
    {
        input_type = 2;
        d = atoi(argv[2]);
        hsh = argv[3];
        mrkl = argv[4];
    }
    Miner whoever;
    BHeader input;
    if (input_type == 0){
        input = BHeader();
    }
    else if (input_type == 1){
        input = BHeader(d);
    }
    else if (input_type == 2){
        input = BHeader(d, hsh, mrkl);
    }
    auto start = std::chrono::system_clock::now();
    Proof pr = whoever.findProof(input);
    auto finish = std::chrono::system_clock::now();
    if (pr.validateProof()) {
        cout << "Proof found:\n";
        pr.printProof();
        auto time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
        cout << "\tTime taken: " << time_taken << "ms\n";
    }
    else
        cout << "Fake proof found\n";
}