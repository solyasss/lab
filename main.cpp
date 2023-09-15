#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date date_1(2, 11, 2023);
    Date date_2(1, 3, 2023);

    date_1 += 2;
    date_2 -= 3;

    if (date_1 > date_2)
    {
        cout << "date1 is later than date2" << endl;
    }
    else if (date_1 < date_2)
    {
        cout << "date1 is earlier than date2" << endl;
    }
    else
    {
        cout << "date1 and date2 are the same" << endl;
    }

    return 0;
}
