//
// Created by Akbar on 02.03.2020.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void Test(){
    Assert(IsPalindrom(""),"null");
    Assert(IsPalindrom("a"),"onesymbol");
    Assert(IsPalindrom(" aec b cea "),"spaces");
    Assert(IsPalindrom("abcba"),"normal");
    Assert(!IsPalindrom("baaaaaaaaaaaaaaac"),"borders");
    Assert(!IsPalindrom("baaaaaabdaaaaaab"),"middle1");
    Assert(!IsPalindrom("baaaaaaacbaaaaaab"),"middle2");
    Assert(!IsPalindrom("aaaaaaaaaaaaaaaaaaab"),"last1");
    Assert(!IsPalindrom("aaaaaaaaaaaaaaaaaaaab"),"last2");
    Assert(!IsPalindrom("aaaaaaaaaaaaaaaaaaa "),"last3");
    Assert(!IsPalindrom("aaaaaaaaaaaaaaaaaaaa "),"last4");
    Assert(!IsPalindrom(" aaaaaaaaaaaaaaaaaaa"),"first1");
    Assert(!IsPalindrom(" aaaaaaaaaaaaaaaaaaaa"),"first2");
    Assert(!IsPalindrom("baaaaaaaaaaaaaaaaaaa"),"first3");
    Assert(!IsPalindrom("baaaaaaaaaaaaaaaaaaaa"),"first4");
    Assert(!IsPalindrom("aea b baea"),"spaces4");
    Assert(!IsPalindrom("aea b aeb"),"spaces3");
    Assert(!IsPalindrom("aea b beb"),"spaces5");
    Assert(!IsPalindrom(" aec b  cea "),"spaces2");
    Assert(!IsPalindrom("ab"),"spaces2");
    Assert(!IsPalindrom("Aa"),"capital");
}

/*bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}*/

int main() {
    TestRunner runner;
    runner.RunTest(Test,"Test");
    // добавьте сюда свои тесты
    return 0;
}
