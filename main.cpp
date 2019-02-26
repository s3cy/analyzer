#include "UserDataAnalyzer.h"

#include <iostream>


int main()
{
    using namespace std;
    char * userDataField = "abcdef";

    UserDataAnalyzerFactory factory;
    UserDataAnalyzer* analyzer = factory.getAnalyzer(2);
    analyzer->run(userDataField, 5);

    return 0;
}

