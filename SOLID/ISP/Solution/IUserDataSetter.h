#pragma once
#include <string>
class IUserDataSetter
{
public:
        virtual void SetUserName(std::string name) = 0;
        virtual void SetUserLevel(int level) = 0;
        virtual void SetUserValue1(int value1) = 0;
        virtual void SetUserValue2(int value2) = 0;
        virtual void SetUserValue3(int value3) = 0;
};

