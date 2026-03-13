#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Potion.h"

// ===== main =====
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "russian");
    Potion A("A", "a", 20, { "a","b","v","g" }, 100);
    Potion B("B", "v", 10, { "v","g","m" }, 50);

    Potion C = A + B;
    C.info();

    A += B;
    A.info();

    Potion K = A * B;
    K.info();

}