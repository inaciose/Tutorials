#include <iostream>
#include <cassert> // for assert()


/*
    An assert statement is a preprocessor macro that evaluates a conditional expression.
    If the conditional expression is true, the assert statement does nothing.
    assert will terminate the program (usually with a message quoting the assert statement) if its argument turns out
    to be false. It's commonly used during debugging to make the program fail more obviously if an unexpected condition occurs.

    When you're doing a release (non-debug) build, you can also remove the overhead of evaluating assert
    statements by defining the NDEBUG macro, usually with a compiler switch. The corollary of this is that
    your program  should never rely on the assert macro running.
*/


int assertExample()
{
    int nIndex=12;
    int g_anArray[10];
    // we're asserting that nIndex is between 0 and 9
    assert(nIndex >= 0 && nIndex <= 9); // this is line 7 in Test.cpp
    return g_anArray[nIndex];
}


int main(int argc, char *argv[])
{
    assertExample();
    return 0;
}
