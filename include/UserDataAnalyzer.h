#ifndef USERDATAANALYZER_H
#define USERDATAANALYZER_H


class UserDataAnalyzer
{
    public:
        UserDataAnalyzer();
        virtual void run(char * userDataField, int length);
    protected: // subclasses能用但外部不能
        virtual void decode(char * data) = 0; // abstract method // 根据实时值数据格式，解析单个实时值
        virtual int getDecodeLength() = 0; // 获取实时值数据格式中的格式长度
    private:
};


class UserDataAnalyzerFactory
{
    public:
        UserDataAnalyzer * getAnalyzer(int opcode);
};


// opcode = 1
class RainfallAnalyzer: public UserDataAnalyzer
{
    void run(char * userDataField, int length);
    void decode(char * data);
    int getDecodeLength();
};


// opcode = 2
class WaterLevelAnalyzer: public UserDataAnalyzer
{
    void decode(char * data);
    int getDecodeLength();
};

#endif // USERDATAANALYZER_H
