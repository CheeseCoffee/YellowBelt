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

class Rational {
public:
    // Вы можете вставлять сюда различные реализации,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    Rational();
    Rational(int numerator, int denominator) {
    }

    int Numerator() const {
    }

    int Denominator() const {
    }
};

void DefaultConstructorTest(){
    Rational r;
    AssertEqual(r.Denominator(),0);
    AssertEqual(r.Numerator(),1);
}

void SimplifyTest(){
    Ratinal r(4,6);
    AssertEqual(r.Denominator(),2);
    AssertEqual(r.Numerator(),3);
}

void NegativeTest(){
    Ratinal r(-4,6);
    AssertEqual(r.Denominator(),-2);
    AssertEqual(r.Numerator(),3);
    Ratinal r(4,-6);
    AssertEqual(r.Denominator(),-2);
    AssertEqual(r.Numerator(),3);
}

void PositiveTest(){
    Ratinal r(-4,-6);
    AssertEqual(r.Denominator(),2);
    AssertEqual(r.Numerator(),3);
}

void ZeroTest(){
    Ratinal r(0,32);
    AssertEqual(r.Denominator(),0);
    AssertEqual(r.Numerator(),1);
}

int main() {
    TestRunner runner;
    runner.RunTest(DefaultConstructorTest,"DefaultConstructorTest");
    runner.RunTest(SimplifyTest,"SimplifyTest");
    runner.RunTest(NegativeTest,"NegativeTest");
    runner.RunTest(PositiveTest,"PositiveTest");
    runner.RunTest(ZeroTest,"ZeroTest");
    // добавьте сюда свои тесты
    return 0;
}
