#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include "String.h"

using namespace std;

String operator+ (char c, String s)
{
    String result;

    result = c;
    result = result + s;
    return result;

}

String toString(unsigned int x)
{
    String result;

    if (x < 10)
    {
        //result.operator= ('0'+x);
        result = '0' + x;
        return result;
    }
    while (x > 0)
    {
        //A @ b
        //A.operator@(b)
        //result.operator+ ('0' + x%10);
        //b @ A
        //b.operator@(A)
        //A @ b
        //operator@ (A,b)
        result = ('0' + x % 10) + result;
        x /= 10;

    }

    return result;
}

String toUpper(String s)
{
    String result = s.str;

    for (size_t i = 0; i < result.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] = result[i] + ('A' - 'a');
        }
    }
    return result;
}

TEST_CASE("Modification test")
{
    String maths("Mathematics");
    String inf("Programming");

    String mix = maths + inf;
    
    if (mix == "Mathematics Programming")
        std::cout << mix;
}

TEST_CASE("Equation/different test")
{
    String a("dog");
    String b("cat");
    String c("dog");

    if (a == c)
        std::cout << a << " ";

    if (a != b)
        std::cout << b << " ";

    String f("nasko");
    String g("nasko");

    char c1 = f[0];
    char c2 = g[0];

    CHECK(c1 == c2);
}

TEST_CASE("Upper case test")
{
    String name1("john");

    String upper = toUpper(name1);
    
    CHECK(upper == "JOHN");
}

TEST_CASE("Lower case test")
{
    String name("NASKO");
    name.toLower();
    cout << name << " ";
}

TEST_CASE("Operator + and = test")
{
    String s1("Hello");
    String foo("Blablabla");
    String s2(" world!");

    foo = s2;

    s1.operator+(foo).print();
}

TEST_CASE("Contains test")
{
    String str("Hello world!");
    String subStr("world");

    CHECK(str.contains(subStr));
}

TEST_CASE("Cin test")
{
    String str;

    std::cout << "Please input a string: ";
    std::cin >> str;
    std::cout << "You just entered: " << str << std::endl;
}

int main()
{
    doctest::Context().run();
}
