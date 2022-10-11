#pragma once
#include <string>
class IUserDataGetter
{
public:
        virtual long GetUserId() = 0;
        virtual std::string GetUserName() = 0;
        virtual int GetUserLevel() = 0;
        virtual int GetUserValue1() = 0;
        virtual int GetUserValue2() = 0;
        virtual int GetUserValue3() = 0;
};

