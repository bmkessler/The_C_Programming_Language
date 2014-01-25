# include <stdio.h>

int main()
{
  int day_of_year(int, int, int);
  void month_day(int, int, int *, int *);
  
  int day, month;
  
  day = day_of_year(1982,2,21);
  printf("Feb 21, 1982 was the %d day of the year\n",day);
  month_day(2014,137,&month,&day);
  printf("The 137th day of 2014 is day %d of month %d\n",day,month);
  day_of_year(1920,14,5);           /* error for month out of bounds */
  day_of_year(1991,2,29);           /* error for non-leap year  */
  day_of_year(1992,2,29);           /* no error for leap year   */
  month_day(2012,366,&month,&day);  /* no error for leap year   */
  month_day(2013,366,&month,&day);  /* error for non-leap year  */
  return 0;
}

static char nonleapyear[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leapyear[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[] = { nonleapyear, leapyear };

/* day_of_year: return day of year from month and day */
int day_of_year( int year, int month, int day)
{
  int i, leap;
  
  leap = year%4 == 0 && year %100 != 0 || year %400 == 0;
  if( month >= 1 && month <= 12  ) {
    if( day <= *(daytab[leap]+month)) {
      for( i=1; i < month; i++)
        day += *(daytab[leap]+i);
      return day;
    } else {
      printf("Error: month %d does not have %d days in year %d\n",month,day,year);
    }
  } else {
    printf("Error: month must be between 1 and 12\n");
    return -1;
  }
}

/* month_day: set month,day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  
  leap = year%4 == 0 && year %100 != 0 || year %400 == 0;
  if( yearday <= (365+leap) ) {
    for( i=1; yearday > *(daytab[leap]+i); i++)
      yearday -= *(daytab[leap]+i);
    *pmonth = i;
    *pday = yearday;
  } else {
    printf("Error: year %d does not have %d days in it\n",year,yearday);
  }
}

/* month_name: return the name of the n-th month */
char *month_name(int n)
{
  static char *names[] = { "Illegal Month", "January", "February", "March", "April",
                          "May", "June", "July", "August", "September", "October",
                          "November", "December"};
  
  return (n < 1 || n > 12) ? names[0] : names [n];
}
