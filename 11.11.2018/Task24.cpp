/* Для структуры Date напишите метод, определяющий, сколько дней осталось до Нового Года. */

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

};

int main()
{
  return 0;
}
