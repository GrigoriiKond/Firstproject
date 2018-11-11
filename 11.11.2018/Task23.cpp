//Для структуры Date напишите оператор минус возвращающий, количество дней прошедших между датами.

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

	
 
int &operator - (Date &B)
    {
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

    Date &operator + (int a)
    {
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
  
  int main () {
   Date D;
    cout << "1-st date: ";
    D.in();
   Date Second;
    cout << "2-nd date: ";
    Second.in();
    cout << "Between " << (D - Second) << " days " << '\n';
  
  return 0;
  
  }
