#pragma once
#include <string>
class IUserDataStorage
{
public:
        virtual long GetUserId() = 0;
        virtual std::string GetUserName() = 0;
        virtual int GetUserLevel() = 0;
        virtual int GetUserValue1() = 0;
        virtual int GetUserValue2() = 0;
        virtual int GetUserValue3() = 0;
        virtual void SetUserName(std::string name) = 0;
        virtual void SetUserLevel(int level) = 0;
        virtual void SetUserValue1(int value1) = 0;
        virtual void SetUserValue2(int value2) = 0;
        virtual void SetUserValue3(int value3) = 0;
};

