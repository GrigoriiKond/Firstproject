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

	bool vis()
	{
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

	int day()
	{
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
	
	   int me ()  {
        if ((Month == 1) || (Month == 10)) {return 0;};
        if (Month == 5) {return 1;};
        if (Month == 8) {return 2;};
        if ((Month == 2) || (Month == 3) || (Month == 11)) {return 3;};
        if (Month == 6) {return 4;};
        if ((Month == 9) || (Month == 12)) {return 5;};
        if ((Month == 4) || (Month == 7)) {return 6;};
    }

    int ye ()  {
        int n = (Year / 100);
        n -= mdn(n, 4);
        n *= 5;
        n -= mdn(n, 7);
        return n;
    }


    int ned ()  {
        int m = Day + cod_mes();
        m -= mdn(m, 7);

        int p = (Year % 100);
        p -= mdn(p, 28);
        p += ((Year % 100)/4);
        p += cod_year();
        if (((Month == 1) || (Month == 2)) && (visokos() == 1)) {p--;};

        m += p;
        m -= mdn(m, 7);

        return m;
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

    int &operator - (Date &B)   {
        int a = Day, b = Month, c = Year;
        int n = (kon() - kon()), p = 0;

        if (Year > B.Year)
        {
            while (B.Year < Year)
            {
                B.Year++;
                if (B.vis()) {p -= 366;}
                else {p -= 365;};
            }
        }
        else
        {
            while (Year < B.Year)
            {
                Year++;
                if (vis()) {p += 366;}
                else {p += 365;};
            }
        }

        B.Day = 0;
        B.Day += n;
        B.Day += p;
        if (B.Day < 0) {B.Day = (-B.Day);};

        Day = a;
        Month = b;
        Year = c;

        return (B.Day);
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
