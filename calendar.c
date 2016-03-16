// A C program which takes a numerical input date and converts it into
// English words. Additionally provides day of week and calendar for
// the month according to the Gregorian calendar system.
// William Nguyen, April 6th, 2009.

// Revised April 25th, 2009. Removed unnecessary return statements,
// added guard to ensure day and month were larger than 0,
// and made other minor improvements.

#include <stdio.h>


int daysInMonth(int month, int year);
void monthWord(int month);
void dayWord(int day);
void yearWord(int year);
void dayOfWeek(int day, int month, int year);
void calendar(int month, int year);

int main(int argc, char *argv[]) {

   int day, month, year;
   int input, error = 0;
   char ch;

   printf("Enter date in DD/MM/YYYY format: ");
   input = scanf("%d/%d/%d", &day, &month, &year);
   // Checking for invalid characters to the end of the line.
   while ((ch = getchar()) != '\n' && error != 1) {
      if (ch != ' ') {
         error = 1;
      }
   }

   // Format check.
   if (input == 3 && error == 0 && year >= 1582 && month >= 1 && month <= 12
       && day >= 1 && day <= daysInMonth(month, year)) {
      monthWord(month);
      dayWord(day);
      yearWord(year);
      dayOfWeek(day, month, year);
      calendar(month, year);
   } else {
      printf("Format must be DD/MM/YYYY\n");
   }

   return 0;
}

// Leap year check.
int isLeapYear(int year) {

   if (year % 400 == 0) {
      return 1;
   } else if (year % 100 == 0) {
      return 0;
   } else if (year % 4 == 0) {
      return 1;
   } else {
      return 0;
   }
}

// Finding the number of days in a month for a certain year.
int daysInMonth(int month, int year) {

   if (month == 2 && !isLeapYear(year)) {
         return 28;
   } else if (month == 2 && isLeapYear(year)) {
         return 29;
   } else if (month == 4 || month == 6 || month == 9 || month == 11) {
         return 30;
   } else {
         return 31;
   }
}

// Converting month number into month name.
void monthWord(int month) {

   if (month == 1) {
      printf("January");
   } else if (month == 2) {
      printf("February");
   } else if (month == 3) {
      printf("March");
   } else if (month == 4) {
      printf("April");
   } else if (month == 5) {
      printf("May");
   } else if (month == 6) {
      printf("June");
   } else if (month == 7) {
      printf("July");
   } else if (month == 8) {
      printf("August");
   } else if (month == 9) {
      printf("September");
   } else if (month == 10) {
      printf("October");
   } else if (month == 11) {
      printf("November");
   } else if (month == 12) {
      printf("December");
   }
   printf("\n");
}

// Converting day number into ordinal word.
void dayWord(int day) {

   if (day == 1) {
      printf("First");
   } else if (day == 2) {
      printf("Second");
   } else if (day == 3) {
      printf("Third");
   } else if (day == 4) {
      printf("Fourth");
   } else if (day == 5) {
      printf("Fifth");
   } else if (day == 6) {
      printf("Sixth");
   } else if (day == 7) {
      printf("Seventh");
   } else if (day == 8) {
      printf("Eighth");
   } else if (day == 9) {
      printf("Ninth");
   } else if (day == 10) {
      printf("Tenth");
   } else if (day == 11) {
      printf("Eleventh");
   } else if (day == 12) {
      printf("Twelfth");
   } else if (day == 13) {
      printf("Thirteenth");
   } else if (day == 14) {
      printf("Fourteenth");
   } else if (day == 15) {
      printf("Fifteenth");
   } else if (day == 16) {
      printf("Sixteenth");
   } else if (day == 17) {
      printf("Seventeenth");
   } else if (day == 18) {
      printf("Eighteenth");
   } else if (day == 19) {
      printf("Nineteenth");
   } else if (day == 20) {
      printf("Twentieth");
   } else if (day == 21) {
      printf("Twenty first");
   } else if (day == 22) {
      printf("Twenty second");
   } else if (day == 23) {
      printf("Twenty third");
   } else if (day == 24) {
      printf("Twenty fourth");
   } else if (day == 25) {
      printf("Twenty fifth");
   } else if (day == 26) {
      printf("Twenty sixth");
   } else if (day == 27) {
      printf("Twenty seventh");
   } else if (day == 28) {
      printf("Twenty eighth");
   } else if (day == 29) {
      printf("Twenty ninth");
   } else if (day == 30) {
      printf("Thirtieth");
   } else if (day == 31) {
      printf("Thirty first");
   }
   printf("\n");
}

// Converting a digit into its word for use in yearWord function.
void digitWord(int digit) {

   if (digit == 1) {
      printf(" one");
   } else if (digit == 2) {
      printf(" two");
   } else if (digit == 3) {
      printf(" three");
   } else if (digit == 4) {
      printf(" four");
   } else if (digit == 5) {
      printf(" five");
   } else if (digit == 6) {
      printf(" six");
   } else if (digit == 7) {
      printf(" seven");
   } else if (digit == 8) {
      printf(" eight");
   } else if (digit == 9) {
      printf(" nine");
   }
}

// Converting year number into words.
void yearWord(int year) {

   // Extracting single digits from year.
   int thousands = year / 1000;
   int hundreds = year % 1000 / 100;
   int tens = year % 100 / 10;
   int units = year % 10;

   if (thousands == 1) {
      printf("One thousand");
   } else if (thousands == 2) {
      printf("Two thousand");
   } else if (thousands == 3) {
      printf("Three thousand");
   } else if (thousands == 4) {
      printf("Four thousand");
   } else if (thousands == 5) {
      printf("Five thousand");
   } else if (thousands == 6) {
      printf("Six thousand");
   } else if (thousands == 7) {
      printf("Seven thousand");
   } else if (thousands == 8) {
      printf("Eight thousand");
   } else if (thousands == 9) {
      printf("Nine thousand");
   }

   if (hundreds != 0) {
      digitWord(hundreds);
      printf(" hundred");
   }

   if (tens != 0 || units != 0) {
      printf(" and");
      if (year % 100 == 10) {
         printf(" ten");
      } else if (year % 100 == 11) {
         printf(" eleven");
      } else if (year % 100 == 12) {
         printf(" twelve");
      } else if (year % 100 == 13) {
         printf(" thirteen");
      } else if (year % 100 == 14) {
         printf(" fourteen");
      } else if (year % 100 == 15) {
         printf(" fifteen");
      } else if (year % 100 == 16) {
         printf(" sixteen");
      } else if (year % 100 == 17) {
         printf(" seventeen");
      } else if (year % 100 == 18) {
         printf(" eighteen");
      } else if (year % 100 == 19) {
         printf(" nineteen");
      } else if (tens == 2) {
         printf(" twenty");
      } else if (tens == 3) {
         printf(" thirty");
      } else if (tens == 4) {
         printf(" forty");
      } else if (tens == 5) {
         printf(" fifty");
      } else if (tens == 6) {
         printf(" sixty");
      } else if (tens == 7) {
         printf(" seventy");
      } else if (tens == 8) {
         printf(" eighty");
      } else if (tens == 9) {
         printf(" ninety");
      }
      if (tens != 1) {
      digitWord(units);
      }
   }

   printf("\n");
}

// Finding day of the week for input date.
void dayOfWeek(int day, int month, int year) {

   int i, j;
   int totalDays = 0;

   // Calculating the total number of days since Friday, January 1st, 1582.
   for (i = 1582; i < year; i++) {
      if (isLeapYear(i)) {
         totalDays += 366;
      } else if (!isLeapYear(i)) {
         totalDays += 365;
      }
   }
   for (j = 1; j < month; j++) {
      totalDays += daysInMonth(j, year);
   }
   totalDays += day - 1;

   if (totalDays % 7 == 0) {
      printf("Friday");
   } else if (totalDays % 7 == 1) {
      printf("Saturday");
   } else if (totalDays % 7 == 2) {
      printf("Sunday");
   } else if (totalDays % 7 == 3) {
      printf("Monday");
   } else if (totalDays % 7 == 4) {
      printf("Tuesday");
   } else if (totalDays % 7 == 5) {
      printf("Wednesday");
   } else if (totalDays % 7 == 6) {
      printf("Thursday");
   }
   printf("\n");
}

// Printing out the calendar for the month.
void calendar(int month, int year) {

   int i, j;
   int totalDays = 0;
   int startColumn;
   int column;
   int date = 1;

   printf("Su Mo Tu We Th Fr Sa\n");

   // Using previous formula to find "totalDays" up to beginning of month,
   for (i = 1582; i < year; i++) {
      if (isLeapYear(i)) {
         totalDays += 366;
      } else if (!isLeapYear(i)) {
         totalDays += 365;
      }
   }
   for (j = 1; j < month; j++) {
      totalDays += daysInMonth(j, year);
   }
   // then modifying so that data fits calendar nicely.
   startColumn = (totalDays + 5) % 7 + 1;
   // Was going to subtract 2 from "totalDays" to set (mod 7 = 0) to be Sunday,
   // but when a day in January 1582 is entered,
   // "totalDays" = 0 and mod 7 does not work the same for negative numbers.
   // Add 1 at end so startColumn ranges from 1 to 7.

   // Once the end of the next "for" loop is reached,
   // "while" checks whether dates still need printing.
   while (date <= daysInMonth(month, year)) {
      for (column = 1; column <= 7; column++) {
         // "startColumn" used to print space 
         // until day 1 is in the correct column.
         if (date == 1 && column < startColumn) {
            printf("   ");
         // The following guard used to end calendar function
         // once final day reached,
         } else if (date == daysInMonth(month, year)) {
            printf("%2d\n", date);
            date++;
            column = 7;
         // otherwise, dates are printed.
         } else if (column == 7) {
            printf("%2d\n", date);
            date++;
         } else if (column < 7) {
            printf("%2d ", date);
            date++;
         }
      }
   }
}