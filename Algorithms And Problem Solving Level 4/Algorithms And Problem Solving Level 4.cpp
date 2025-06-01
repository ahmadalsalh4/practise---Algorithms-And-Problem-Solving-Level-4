#include "mylab.h"

void Problem1()
{
	cout << MyNumberToText(MyReadIntNumber()) << endl;
}

void Problem2()
{
	int year = MyReadIntNumber("please enter a year to check: ");
	if (MyIsLeapYearV1(year))
		cout << "yes, year [" << year << "] is a leap year.\n";
	else
		cout << "no, year [" << year << "] is not a leap year.\n";
}

void Problem3()
{
	int year = MyReadIntNumber("please enter a year to check: ");
	if (MyIsLeapYear(year))
		cout << "yes, year [" << year << "] is a leap year.\n";
	else
		cout << "no, year [" << year << "] is not a leap year.\n";
}

void Problem4()
{
	int year = MyReadIntNumber("please enter a year to check: ");

	cout << "\nNumber of days    in year [" << year << "] is " << MyNumberOfDaysInYear(year);
	cout << "\nNumber of hours   in year [" << year << "] is " << MyNumberOfHoursInYear(year);
	cout << "\nNumber of minuts  in year [" << year << "] is " << MyNumberOfMinutsInYear(year);
	cout << "\nNumber of seconds in year [" << year << "] is " << MyNumberOfSecondsInYear(year) << endl;
}

void Problem5()
{
	int year = MyReadIntNumber("please enter a year to check: ");
	int month = MyReadIntNumber("please enter a month to check: ");

	cout << "\nNumber of days    in month [" << month << "] is " << MyNumberOfDaysInMonthV1(year, month);
	cout << "\nNumber of hours   in month [" << month << "] is " << MyNumberOfHoursInMonth(year, month);
	cout << "\nNumber of minuts  in month [" << month << "] is " << MyNumberOfMinutsInMonth(year, month);
	cout << "\nNumber of seconds in month [" << month << "] is " << MyNumberOfSecondsInMonth(year, month) << endl;
}

void Problem6()
{
	int year = MyReadIntNumber("please enter a year to check: ");
	int month = MyReadIntNumber("please enter a month to check: ");

	cout << "\nNumber of days    in month [" << month << "] is " << MyNumberOfDaysInMonth(year, month);
	cout << "\nNumber of hours   in month [" << month << "] is " << MyNumberOfHoursInMonth(year, month);
	cout << "\nNumber of minuts  in month [" << month << "] is " << MyNumberOfMinutsInMonth(year, month);
	cout << "\nNumber of seconds in month [" << month << "] is " << MyNumberOfSecondsInMonth(year, month) << endl;

}

void Problem7()
{
	int year = MyReadIntNumber("please enter a year: ");
	int month = MyReadIntNumber("please enter a month: ");
	int day = MyReadIntNumber("please enter a day: ");
	int dayorder = MyFindDayOrder(year, month, day);

	cout << "\nDate      : " << day << "/" << month << "/" << year << endl;
	cout << "Day Order : " << dayorder << endl;
	cout << "Day Name  : " << MyGetDayName(dayorder) << endl;
}

void Problem8()
{
	int year = MyReadIntNumber("please enter a year: ");
	int month = MyReadIntNumber("please enter a month: ");
	MyPrintMonthCalendar(year, month);
}

void Problem9()
{
	MyPrintYearCalendar(MyReadIntNumber("please enter a year: "));
}

void Problem10()
{
	int day = MyReadIntNumber("please enter a day: ");
	int month = MyReadIntNumber("please enter a month: ");
	int year = MyReadIntNumber("please enter a year: ");
	cout << "\nnumber of days from begining of the year is: ";
	cout << MyCalculateHowManyDayGoneFromTheStartOfTheYear(year, month, day);
	cout << endl;
}

void Problem11()
{
	int day = MyReadIntNumber("please enter a day: ");
	int month = MyReadIntNumber("please enter a month: ");
	int year = MyReadIntNumber("please enter a year: ");
	int HowManyDayGone = MyCalculateHowManyDayGoneFromTheStartOfTheYear(year, month, day);
	cout << "\nnumber of days from begining of the year is: ";
	cout << HowManyDayGone << endl << endl;

	stdate date = MyCalculateDateForDayUsingTotalDays(HowManyDayGone, year);;
	cout << "Date for [" << HowManyDayGone << "] is : ";
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}

void Problem12()
{
	stdate date = MyReadDate();
	int DaysToAdd = MyReadIntNumber("please enter how many days to add: ");

	stdate DateAfterAdd = MyAddDaysToDate(date, DaysToAdd);
	cout << "date after adding [" << DaysToAdd << "] days is: ";
	cout << DateAfterAdd.day << "/" << DateAfterAdd.month << "/" << DateAfterAdd.year << endl;
}

void Problem13()
{
	stdate date1 = MyReadDate();
	cout << endl;
	stdate date2 = MyReadDate();

	if (MyIsDate1BeforeDate2(date1, date2))
		cout << "yes, date1 is less then date2.";
	else
		cout << "no, date1 is not less then date2.";
}

void Problem14()
{
	stdate date1 = MyReadDate();
	cout << endl;
	stdate date2 = MyReadDate();

	if (MyIsDate1equalDate2(date1, date2))
		cout << "\nyes, date1 equal date2.\n";
	else
		cout << "\nno, date1 not equal date2.\n";
}

void Problem15()
{
	stdate date1 = MyReadDate();
	
	if (MyIsLastDayInMonth(date1))
		cout << "\nyes, day is last day in month\n";
	else
		cout << "\nno, day is not last day in month\n";

	if (MyIsLastMonthInYear(date1.month))
		cout << "\nyes, month is last month in year\n";
	else
		cout << "\nno, month is not last month in year\n";
}

void Problem16()
{
	stdate date1 = MyReadDate();
	stdate DateAfterAdd = MyIncressDateByOneDay(date1);

	cout << "\ndate after adding 1 day is: ";
	cout << DateAfterAdd.day << "/" << DateAfterAdd.month << "/" << DateAfterAdd.year << endl;
}

void Problem17()
{
	stdate date1 = MyReadDate();
	cout << endl;
	stdate date2 = MyReadDate();
	
	cout << "\ndifrences is: " << MyCalculateDifrenceBetwen2Date(date1, date2) << " Day (s).";
	cout << "\ndifrences (includin end day) is: " << MyCalculateDifrenceBetwen2Date(date1, date2, 1) << " Day (s).\n";
}

void Problem18()
{
	cout << "please enter your date birth:\n";
	stdate date1 = MyReadDate();
	stdate systemDate = MyGetSystemTime();

	cout << "your age is: " << MyCalculateDifrenceBetwen2Date(date1, systemDate) << "Day (s)";
}

void Problem19()
{
	stdate date1 = MyReadDate();
	cout << endl;
	stdate date2 = MyReadDate();
	
	cout << "\ndifrences is: " << MyCalculateDifrenceBetwen2Date(date1, date2) << " Day (s).";
	cout << "\ndifrences (includin end day) is: " << MyCalculateDifrenceBetwen2Date(date1, date2, 1) << " Day (s).\n";

}

void Problem20_32()
{
	stdate date1 = MyReadDate();
	
	cout << "\nDate after:\n";
	
	cout << "\n01-Adding one day is: ";
	date1 = MyIncressDateByOneDay(date1);
	MyPrintDate(date1);

	cout << "\n02-Adding 10 days is: ";
	date1 = MyIncressDateByXDays(date1,10);
	MyPrintDate(date1);

	cout << "\n03-Adding one week is: ";
	date1 = MyIncressDateByOneWeek(date1);
	MyPrintDate(date1);

	cout << "\n04-Adding 10 weeks is: ";
	date1 = MyIncressDateByXWeeks(date1,10);
	MyPrintDate(date1);

	cout << "\n05-Adding one month is: ";
	date1 = MyIncressDateByOneMonth(date1);
	MyPrintDate(date1);

	cout << "\n06-Adding 5 Months is: ";
	date1 = MyIncressDateByXMonths(date1, 5);
	MyPrintDate(date1);

	cout << "\n07-Adding one year is: ";
	date1 = MyIncressDateByOneYear(date1);
	MyPrintDate(date1);

	cout << "\n08-Adding 10 years is: ";
	date1 = MyIncressDateByXYears(date1, 10);
	MyPrintDate(date1);

	cout << "\n09-Adding 10 years (faster) is: ";
	date1 = MyIncressDateByXYearsFaster(date1, 10);
	MyPrintDate(date1);

	cout << "\n10-Adding one decade is: ";
	date1 = MyIncressDateByOneDecade(date1);
	MyPrintDate(date1);

	cout << "\n11-Adding 10 decades is: ";
	date1 = MyIncressDateByXDecades(date1, 10);
	MyPrintDate(date1);

	cout << "\n12-Adding 10 decades (faster) is: ";
	date1 = MyIncressDateByXDecadesFaster(date1, 10);
	MyPrintDate(date1);

}

void Problem33_46()
{
	stdate date1 = MyReadDate();

	cout << "\nDate after:\n";

	cout << "\n01-Subtracting one day is: ";
	date1 = MyDecreaseDateByOneDay(date1);
	MyPrintDate(date1);
	
	cout << "\n02-Subtracting 10 days is: ";
	date1 = MyDecreaseDateByXDays(date1, 10);
	MyPrintDate(date1);
	
	cout << "\n03-Subtracting one week is: ";
	date1 = MyDecreaseDateByOneWeek(date1);
	MyPrintDate(date1);
	
	cout << "\n04-Subtracting 10 weeks is: ";
	date1 = MyDecreaseDateByXWeeks(date1, 10);
	MyPrintDate(date1);
	
	cout << "\n05-Subtracting one month is: ";
	date1 = MyDecreaseDateByOneMonth(date1);
	MyPrintDate(date1);

	cout << "\n06-Subtracting 5 Months is: ";
	date1 = MyDecreaseDateByXMonths(date1, 5);
	MyPrintDate(date1);
	
	cout << "\n07-Subtracting one year is: ";
	date1 = MyDecreaseDateByOneYear(date1);
	MyPrintDate(date1);

	cout << "\n08-Subtracting 10 years is: ";
	date1 = MyDecreaseDateByXYears(date1, 10);
	MyPrintDate(date1);

	cout << "\n09-Subtracting 10 years (faster) is: ";
	date1 = MyDecreaseDateByXYearsFaster(date1, 10);
	MyPrintDate(date1);
	
	cout << "\n10-Subtracting one decade is: ";
	date1 = MyDecreaseDateByOneDecade(date1);
	MyPrintDate(date1);

	cout << "\n11-Subtracting 10 decades is: ";
	date1 = MyDecreaseDateByXDecades(date1, 10);
	MyPrintDate(date1);

	cout << "\n12-Subtracting 10 decades (faster) is: ";
	date1 = MyDecreaseDateByXDecadesFaster(date1, 10);
	MyPrintDate(date1);

}

void Problem47_53()
{
	stdate date = MyGetSystemTime();
	int dayorder = MyFindDayOrder(date);
	
	cout << "Today is " << MyGetDayName(dayorder) << " , ";
	MyPrintDate(date);

	cout << "\n\nis it end of week ?\n";
	if (MyIsItEndOfWeek(date))
		cout << "yes, it is end of week.";
	else
		cout << "no, it is not end of week.";

	cout << "\n\nis it weekend ?\n";
	if (MyIsItWeekEnd(date))
		cout << "yes, it is weekend.";
	else
		cout << "no, it is not weekend.";

	cout << "\n\nis a business day ?\n";
	if (MyIsItBusinessDay(date))
		cout << "yes, it is a business day.";
	else
		cout << "no, it is not a business day.";

	cout << "\n\nDays until end of week : " << MyDaysUntilEndOfWeek(date) << " Day (s).\n";
	cout << "Days until end of month : " << MyDaysUntilEndOfMonth(date) << " Day (s).\n";
	cout << "Days until end of year : " << MyDaysUntilEndOfYear(date) << " Day (s).\n";

}

void Problem54()
{
	cout << "Vacation starts:\n\n";
	stdate date1 = MyReadDate();

	cout << "\n\nVacation ends:\n\n";
	stdate date2 = MyReadDate();

	cout << "\n\nVacation From: " << MyGetDayName(MyFindDayOrder(date1)) << " , ";;
	MyPrintDate(date1);

	cout << "\n\nVacation To: " << MyGetDayName(MyFindDayOrder(date2)) << " , ";;
	MyPrintDate(date2);

	cout << "\n\n\nActucal Vacation Days is: " << MyCalculateTotalVacationDays(date1, date2) << endl;

}

void Problem55()
{
	cout << "Vacation starts:\n\n";
	stdate date1 = MyReadDate();

	int VacationPeriod = MyReadIntNumber("Please enter vacation days period: ");

	stdate ReturnDate = MyVacationReturnDate(date1, VacationPeriod);

	cout << "Return Date: " << MyGetDayName(MyFindDayOrder(ReturnDate)) << ", ";
	MyPrintDate(ReturnDate);
	cout << endl;

}

void Problem56()
{
	cout << "please enter date1:\n\n";
	stdate date1 = MyReadDate();

	cout << "\n\nplease enter date2:\n\n";
	stdate date2 = MyReadDate();

	if (MyIsDate1AfterDate2(date1, date2))
		cout << "\nyes, date1 is after date2\n";
	else
		cout << "\nno, date1 is not after date2\n";

}

void Problem57()
{
	cout << "please enter date1:\n\n";
	stdate date1 = MyReadDate();

	cout << "\n\nplease enter date2:\n\n";
	stdate date2 = MyReadDate();

	cout << "comopare result: " << MyCompareResult(date1, date2) << endl;
}

void Problem58()
{
	stDatePeriod Period1;
	cout << "please enter period 1\n";
	cout << "\nplease enter start date:\n";
	Period1.StartDate = MyReadDate();
	cout << "\nplease enter end date:\n";
	Period1.EndDate = MyReadDate();

	stDatePeriod Period2;
	cout << "\n\nplease enter period 2\n";
	cout << "\nplease enter start date:\n";
	Period2.StartDate = MyReadDate();
	cout << "\nplease enter end date:\n";
	Period2.EndDate = MyReadDate();

	if (MyIsPeriodsOverLap(Period1, Period2))
		cout << "\nyes, Periods Overlap.\n";
	else
		cout << "\nno, Periods is not Overlap.\n";

}

void Problem59()
{
	stDatePeriod Period1;
	cout << "please enter period 1\n";
	cout << "\nplease enter start date:\n";
	Period1.StartDate = MyReadDate();
	cout << "\nplease enter end date:\n";
	Period1.EndDate = MyReadDate();

	cout << "\nperiod length is: " << MyCalculetePeriodlength(Period1) << endl;
	cout << "period length (including end day) is: " << MyCalculetePeriodlength(Period1, 1) << endl;

}

void Problem60()
{
	stDatePeriod Period;
	cout << "please enter period\n";
	cout << "\nplease enter start date:\n";
	Period.StartDate = MyReadDate();
	cout << "\nplease enter end date:\n";
	Period.EndDate = MyReadDate();

	cout << "\nplease enter date to check:\n\n";
	stdate date = MyReadDate();

	if (MyIsDateWithinPeriod(Period, date))
		cout << "\nyes, date is within period\n";
	else
		cout << "\nno, date is not within period\n";

}

void Problem61()
{
	cout << "please enter period 1\n";
	stDatePeriod Period1 = MyReadPeriod();

	cout << "please enter period 2\n";
	stDatePeriod Period2 = MyReadPeriod();

	cout << "\noverlap days count is: " << MyOverlapDaysCount(Period1, Period2) << endl;
}

void Problem62()
{
	stdate date1 = MyReadDate();

	if (MyIsValidDate(date1))
		cout << "\nyes, its valid date.\n";
	else
		cout << "\nno, its not valid date.\n";
}

void Problem63_64()
{
	string s1 = MyReadText("please enter date dd/mm/yyyy : ");
	stdate date1 = MyConvertDateStringToDate(s1);

	cout << "\nDay:" << date1.day << endl;
	cout << "\month:" << date1.month << endl;
	cout << "\year:" << date1.year << endl;

	string s2 = MyConvertDateToDateString(date1);

	cout << "\nyou entered: " << s2;
}

void Problem65()
{
	string s1 = MyReadText("please enter date dd/mm/yyyy : ");
	stdate date = MyConvertDateStringToDate(s1);

	cout << endl << MyFormateDate(date, "dd/mm/yyyy") << endl;
	cout << endl << MyFormateDate(date, "yyyy/dd/mm") << endl;
	cout << endl << MyFormateDate(date, "mm/dd/yyyy") << endl;
	cout << endl << MyFormateDate(date, "mm/dd/yyyy") << endl;
	cout << endl << MyFormateDate(date, "dd/mm/yyyy") << endl;
	cout << endl << MyFormateDate(date, "Day:dd, month:mm, year:yyyy,") << endl;
}

int main()
{

	CallSystem("\nPress any key to exit...");
	return 0;
}
