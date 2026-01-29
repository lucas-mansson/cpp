#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using std::cout;

class ascending {
  public:
    ascending() = default;
    bool operator()(int) { return false; }

  private:
};

template <typename InIt, typename OutIt>
OutIt copy_ascending(InIt, InIt, OutIt out)
{
    return out;
}

bool expect(bool act, bool exp)
{
    auto res = act == exp;
    if (!res) {
        cout << "Fail: expected " << std::boolalpha << exp << ", got " << act
             << '\n';
    }
    return res;
}

void test_ascending()
{
    ascending a{};
    auto res = true;
    res &= expect(a(1), true);
    res &= expect(a(1), false);
    res &= expect(a(2), true);
    res &= expect(a(1), false);
    res &= expect(a(2), false);
    res &= expect(a(4), true);
    res &= expect(a(3), false);
    res &= expect(a(2), false);

    cout << "test_ascending " << (res ? "passed" : "failed") << "\n";
}

void example()
{
    std::vector<int> a{1, 3, 2, 5, 3, 7, 4, 6, 5, 7, 6, 9, 7, 8};
    std::vector<int> res{};
    copy_ascending(begin(a), end(a), back_inserter(res));
    for (const auto& x : res) {
        cout << x << " ";
    }
    cout << '\n';
}

template <typename It>
std::string print_value_or_end(It i, It e)
{
    std::ostringstream ss;
    if (i != e) {
        ss << *i;
    } else {
        ss << "[end]";
    }
    return ss.str();
}

template <typename P, typename It>
void check_result(P err, It res, It exp)
{
    if (err.first != res || err.second != exp) {
        cout << "Fail: mismatch : " << print_value_or_end(err.first, res)
             << " != " << print_value_or_end(err.second, exp) << '\n';
    } else {
        cout << "Success!\n";
    }
}

void test_ints()
{
    std::vector<int> a{1, 3, 2, 5, 3, 7, 4, 6, 5, 7, 6, 9, 7, 8};
    cout << "test_ints copying to new vector:\n";
    std::vector<int> res{};
    copy_ascending(begin(a), end(a), back_inserter(res));
    std::vector<int> exp{1,3,5,7,9};
    auto err = std::mismatch(begin(res), end(res), begin(exp));
    check_result(err, end(res), end(exp));

    cout << "test_ints copying to same vector:\n";
    auto it = copy_ascending(begin(a), end(a), begin(a));

    auto i = begin(a);
    auto found = false;
    while(!found && i != end(a)){
        if(i == it){
            found = true;
        }
        ++i;
    }
    if(!found){
        cout << "failure: returned iterator not in [begin(a), end(a))\n";
    } else {
        auto err2 = std::mismatch(begin(a), it, begin(exp));
        check_result(err2, it, end(exp));
        if (it != begin(a) + exp.size()){
            cout << "failure: wrong value for returned iterator\n";
        }
    }
}

#if 0
void example2()
{
    std::vector<std::string> a{"kalle", "anka", "testar", "programmering"};
    std::vector<std::string> res{};
    copy_ascending(begin(a), end(a), back_inserter(res));
    for(const auto& x: res){
        cout << x << " ";
    }
    cout << '\n';
}

void test_strings()
{
    std::vector<std::string> a{"kalle", "anka", "testar", "programmering"};
    std::vector<std::string> res{};
    copy_ascending(begin(a), end(a), back_inserter(res));
    std::vector<std::string> exp{"kalle", "testar"};
    auto err = std::mismatch(begin(res), end(res), begin(exp));
    check_result(err, end(res), end(exp));
}

void example3()
{
    std::vector<std::string> a{"kalle", "anka", "testar", "programmering"};
    auto it = copy_ascending(begin(a), end(a), begin(a));
    a.erase(it, end(a));
    for(const auto& x: a){
        cout << x << " ";
    }
    cout << '\n';
}
#endif

int main()
{
    test_ascending();
    example();
    test_ints();
#if 0
    example2();
    test_strings();
    example3();
#endif
}
