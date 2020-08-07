#include <iostream>
#include <string>

struct DispHelper
{
    DispHelper(char const* iTitle, void const* iPointer)
    {
        std::cout << iTitle << iPointer << "\n";
    }
};

class Foo
{
    DispHelper  mDispHelper;
    std::string mString;
public:
    // コンストラクタ１（const参照で受け取る）
    Foo(std::string const& iString) :
        mDispHelper("Copy:\niString.data()=", iString.data()),
        mString(iString)
    {
        std::cout << "mString.data()=";
        std::cout .operator<<(mString.data());
        std::cout << "\n";
    }

    // コンストラクタ２（右辺値参照で受け取る）
    Foo(std::string&& iString) :
        mDispHelper("Move:\niString.data()=", iString.data()),
        mString(std::move(iString))
    {
        std::cout << "mString.data()=";
        std::cout .operator<<(mString.data());
        std::cout << "\n";
    }
};

int main()
{
    Foo aFoo0(std::string("0123456789012345"));

    std::string aString("abc3456789012345");
    Foo aFoo1(aString);
    std::cout << "aString = " << aString << "\n";

    Foo aFoo2(std::move(aString));
    std::cout << "aString = " << aString << "\n";
}