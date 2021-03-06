#include <iostream>
#include <future>
#define BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
#include <boost/stacktrace.hpp>

using namespace std;
using namespace boost::stacktrace;

void f1();
void f2();
void f3();

void f1() { f2(); }
void f2() { f3(); }
void f3() { cout << stacktrace() << endl << endl; }

int main(int argc, char** argv)
{
	f1();

	auto f = async(launch::async, []() { cout << stacktrace() << endl << endl; });
	f.get();

	return 1;
}
