/* Для структуры Date напишите метод, находящий следующую дату-палиндром. */


#include <iostream>
#include <locale>
using namespace std;

int mdn (int a, int b)
{
    int m = 0;
    for (int i = a; i > 1; i--)
    {
        if ((i % b) == 0)
        {
            m = i;
            break;
        }
    }
    return m;
}

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
        if ((Day / 10) == 0) {cout << 0;};
        cout << Day << ".";
        if ((Month / 10) == 0) {cout << 0;};
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
                    else {return false;};
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
            else {return 30;};
        }
    }

    

   int kon()
    {
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

    Date pal()
    {
       int* gt= new int [8];
       int k = 0;

       while (k == 0)
       {
           int m = 0;
           gt[0] = (Day / 10);
           gt[1] = (Day % 10);
           gt[2] = (Month / 10);
           gt[3] = (Month % 10);
           gt[4] = (Year / 1000);
           gt[5] = ((Year / 100) % 10);
           gt[6] = ((Year / 10) % 10);
           gt[7] = (Year % 10);

           for (int i = 0; i <= 3; i++)
           {
               if (gt[i] != gt[7 - i]) break;
                m++;
           }

           if (m == 4) {break;}
           else
           {
               Day++;
               if (Day > day())
               {
                   Day -= day();
                   Month++;
               }
               if (Month > 12)
               {
                   Month -= 12;
                   Year++;
               }
           }
       }

       return *this;
    } 
};

int main()
{
    Date D;
    cout << "1-st date: ";
    D.in();
	
    cout << "Palindrom: ";
    D.pal();
    D.out();
	
	return 0;
} 


 
