#include <iostream>
#include "CurrencyType.hpp"

using namespace std;

/*
 * Tam olaraq testlerdem kecmeyib.
 * Oz proyektinizde istifade etmek ucun CurrencyType.hpp faylini inklud etmek lazim
 * Input iki cur ola biler. 1.23 ve 1,23
 * Input vaxti noqteden sonra 2-den cox regem olsa, CurrencyType-in qiymeti 0 olacaq.
 */

int main() {
    CurrencyType a(5,6);
    CurrencyType b;
    cin >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;

    return 0;
}