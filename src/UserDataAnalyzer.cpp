#include "UserDataAnalyzer.h"

#include <iostream>

using namespace std;

UserDataAnalyzer::UserDataAnalyzer()
{
    //ctor
}

void
UserDataAnalyzer::run(char * userDataField, int length)
{
    cout << "This is the analyze method, I am going to call decode() repeatedly" << endl;
    int decodeLength = getDecodeLength();
    int N = (length - 4) / decodeLength;
    for (int i = 0; i < N; i++) {
        decode(userDataField + i * decodeLength)
    }
}

UserDataAnalyzer *
UserDataAnalyzerFactory::getAnalyzer(int opcode)
{
    UserDataAnalyzer * analyzer;
    switch (opcode) {
        //TODO:
        //analyzer = new SomeAnalyzer();
        case 1:
            analyzer = new RainfallAnalyzer();
            break;
        case 2:
            analyzer = new WaterLevelAnalyzer();
            break;
        // default: not implemented
    }
    return analyzer;
}

void
RainfallAnalyzer::run(char * userDataField, int length)
{
    cout << "overwrite" << endl;
    decode();
}

void
RainfallAnalyzer::decode(char * data)
{
    cout << "This is the rainfall analyzer decode method" << getDecodeLength() << endl;
}

int
RainfallAnalyzer::getDecodeLength()
{
    return 3;
}

void
WaterLevelAnalyzer::decode(char * data)
{
    cout << "This is the water level analyzer decode method" << getDecodeLength() << endl;
}

int
WaterLevelAnalyzer::getDecodeLength()
{
    return 4;
}
