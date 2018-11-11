/* Для структуры Date напишите оператор плюс, принимающий целое число дней и возвращающий дату, 
отстоящую на это количество дней. */

#include <iostream>
using namespace std;

struct Date
{
	int Day;
	int Month;
	int Year;

	Date ()
	{
		Day = 0;
		Month = 0;
		Year = 0;
	}

	void in()
	{
		cin >> Day >> Month >> Year;
	}

	void out()
	{
		if ((Day / 10) == 0) cout << 0;
		cout << Day << ".";
		if ((Month / 10) == 0) cout << 0;
		cout << Month << "." << Year;
	}

	bool vis() {
		if ((Year % 400) == 0) {return true;}
		else
			{
				if ((Year % 100) == 0) {return false;}
				else
				{
					if ((Year % 4) == 0) {return true;}
					else {return false;}
				}
			}
	}

	int day() {
		if (Month == 2)
		{
			if (vis()) {return 29;}
			else {return 28;};
		}
		else
		{
			if (((Month <= 7) && (((Month % 2) != 0))) || ((Month >= 8) && ((Month % 2) == 0)))
			{
				return 31;
			}
			else {return 30;}
		}
	}
	
        int kon() {
        int a = Day, b = Month, c = Year;
        int p = 0;
        while (Month < 12)
        {
            p += day();
            Month++;
        }
        while (Day <= 31)
        {
            p++;
            Day++;
        }

        Day = a;
        Month = b;
        Year = c;

        return p;
    } 

    int &operator - (Date &Q)   {
        int a = Day, b = Month, c = Year;
        int n = (kon() - kon()), p = 0;

        if (Year > Q.Year)
        {
            while (Q.Year < Year)
            {
                Q.Year++;
                if (Q.vis()) {p -= 366;}
                else {p -= 365;}
            }
        }
        else
        {
            while (Year < Q.Year)
            {
                Year++;
                if (vis()) {p += 366;}
                else {p += 365;}
            }
        }

        Q.Day = 0;
        Q.Day += n;
        Q.Day += p;
        if (Q.Day < 0) {Q.Day = (-Q.Day);}

        Day = a;
        Month = b;
        Year = c;

        return (Q.Day);
    }

    Date &operator + (int a)    {
        Day += a;

        while (Day > dni())
        {
            Day -= dni();
            Month++;
        }

        while (Month > 12)
        {
            Month -= 12;
            Year++;
        }
        return *this;
    }


};

int main()
{
    Date D;
    cout << "1-st date: ";
    D.in();
	
    int p;
    cout << "Number of days: ";
    cin >> p;
    D + p;
    cout << "2-nd date: ";
    D.out();
    cout << '\n';
  return 0;
}
