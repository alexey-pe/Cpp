#include <algorithm>
#include <iostream>
#include <string>

using std::string;

void Composition();
void Flip();

int main()
{
    Composition();
    Flip();
}

string Exclaim(const string& str)
{
    string res = str;
    res.push_back('!');
    return res;

}

string Capitalize(const string& str)
{
    string res = str;
    std::transform(res.begin(), res.end(), res.begin(), ::toupper);
    return res;
}

constexpr auto compose = [](auto f, auto g)
{
    // Capture by value.
    ////return [f, g](auto x) {}

    // Capture all by value.
    return [=](auto x)
    {
        return f(g(x));
    };
};

void Composition()
{
    using namespace std;
    const string text = "bring in the clowns";
    //cout << Exclaim(Capitalize(text)) << endl;

    auto Shout = compose(Exclaim, Capitalize);
    cout << Shout(text) << endl;
}

double Ratio(int a, int b)
{
    return a / (double)b;
}

double FlipRatio(int a, int b)
{
    return Ratio(b, a);
}

constexpr auto flip = [](auto f)
{
    return [=](auto a, auto b)
    {
        return f(b, a);
    };
};

void Flip()
{
    using namespace std;
    const auto a{ 2 };
    const auto b{ 3 };
    //cout << Ratio(a, b) << endl << FlipRatio(a, b) << endl;

    cout << Ratio(a, b) << endl << flip(Ratio)(a, b) << endl;
}