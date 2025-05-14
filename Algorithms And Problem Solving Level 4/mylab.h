#pragma once
#pragma warning(disable : 4996)

//srand((unsigned)time(NULL));

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

namespace mygeneral
{
    void CallSystem(string massege)
    {
        cout << massege;
        system("pause>0");
        system("cls");
    }

    int MyReadIntNumber(string message = "please enter a number : \n", int min = -2000000000, int max = 2000000000)
    {
        int number;
        cout << message;
        cin >> number;
        while (cin.fail() || number < min || number > max)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "invalid input, " << message;
            cin >> number;
        }
        return number;
    }

    float MyReadFloatNumber(string message = "please enter a number : \n", float min = -2000000000, float max = 2000000000)
    {
        float number;
        cout << message;
        cin >> number;
        while (cin.fail() || number < min || number > max)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "invalid input, " << message;
            cin >> number;
        }
        return number;
    }

    string MyReadText(string massage = "please enter your text : \n")
    {
        string text;
        cout << massage;
        getline(cin >> ws, text);
        return text;
    }

    char MyReadLetter(string massage = "please enter your text : \n")
    {
        char c;
        cout << massage;
        cin >> c;
        return c;
    }

    bool MyCheckPrime(int x)
    {
        int m = round(x / 2);
        for (int i = 2; i <= m; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    void MySwapNumber(int& num1, int& num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    enum enOddEven { odd, even };

    enOddEven MyCheckOddEven(int number)
    {
        if (number % 2 == 0)
            return even;
        else
            return odd;
    }

    float MyAbs(float number)
    {
        if (number < 0)
            return number * -1;
        else
            return number;
    }

    float MyGetFraction(float number)
    {
        return number - (int)number;
    }

    float MyRound(float number)
    {
        int int_part = (int)number;
        float faraction_part = MyGetFraction(number);
        if (number >= 0)
            if (faraction_part >= 0.5)
                return int_part + 1;
            else
                return int_part;
        else if (faraction_part <= -0.5)
            return int_part - 1;
        else
            return int_part;
    }

    float MyFloor(float number)
    {
        if (number >= 0)
            return (int)number;
        else
            return (int)number - 1;
    }

    float MyCeil(float number)
    {
        if (number >= 0)
        {
            if (abs(MyGetFraction(number)) > 0)
                return (int)number + 1;
            else
                return (int)number;
        }
        else
            return (int)number;
    }

    float Mypower(float number, float power)
    {
        float result = 1;
        for (int i = 1; i <= power; i++)
            result *= number;
        return result;
    }

    float MySqrt(float number)
    {
        return pow(number, 0.5);
    }

}
using namespace mygeneral;

namespace myrandom
{
    int MyRandomNumber(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }

    enum enTypeOfChar { small_letter, capital_letter, special_chars, digit };

    char MyRandomcahr(enTypeOfChar type)
    {
        switch (type)
        {
        case enTypeOfChar::small_letter:
            return MyRandomNumber(97, 122);
        case enTypeOfChar::capital_letter:
            return MyRandomNumber(65, 90);
        case enTypeOfChar::special_chars:
            return MyRandomNumber(33, 47);
        case enTypeOfChar::digit:
            return MyRandomNumber(48, 57);
        }
    }

    string MyGetRandomWord(enTypeOfChar type, int wordlength)
    {
        string word = "";
        for (int i = 1; i <= wordlength; i++)
            word += MyRandomcahr(type);
        return word;
    }

    string MyGetRandomKey()
    {
        string key = "";
        for (int i = 1; i <= 4; i++)
        {
            key += MyGetRandomWord(enTypeOfChar::capital_letter, 4);
            if (i == 4)
                continue;
            key += "-";
        }
        return key;
    }

    void MyGetRandomKeys(int number)
    {
        cout << endl;
        for (int i = 1; i <= number; i++)
            cout << "key [" << i << "] : " << MyGetRandomKey() << endl;
    }

}
using namespace myrandom;

namespace myarray
{
    void MyPrintArray(int arr[], int arr_length)
    {
        //cout << "length [" << arr_length << "] -> ";
        for (int i = 0; i <= arr_length - 1; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void MyPrintArrayOfString(string arr[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            cout << "Array[" << i + 1 << "] : " << arr[i] << endl;
        cout << endl;
    }

    void MyFillArrayWithRandomNumbers(int arr[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr[i] = MyRandomNumber(1, 100);

    }

    int MyNumberHowManyTimesRepetedInArray(int arr[], int arr_length, int serched_number)
    {
        int repeted = 0;
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (arr[i] == serched_number)
                repeted++;
        }
        return repeted;
    }

    void MyReadArray(int arr[], int& arr_length)
    {
        arr_length = MyReadIntNumber("how many element you want in the array (max 100) :\n");

        cout << "enter array element: \n\n";
        for (int i = 0; i <= arr_length - 1; i++)
        {
            cout << "element [" << i + 1 << "]" << ": ";
            cin >> arr[i];
            cout << endl;
        }
    }

    int MyMaxNumberInArray(int arr[], int arr_length)
    {
        int max = arr[0];
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    int MyMinNumberInArray(int arr[], int arr_length)
    {
        int min = arr[0];
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (min > arr[i])
                min = arr[i];
        }
        return min;
    }

    int MySumNumberInArray(int arr[], int arr_length)
    {
        int sum = 0;
        for (int i = 0; i <= arr_length - 1; i++)
            sum += arr[i];
        return sum;
    }

    float MyAverageOfArray(int arr[], int arr_length)
    {
        return (float)MySumNumberInArray(arr, arr_length) / arr_length;
    }

    void MyCopyArray(int arr_source[], int arr_destination[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr_destination[i] = arr_source[i];
    }

    void MyCopyPrimeNumberFromArrayToAnotherArray(int arr_source[], int arr_destination[], int arr_source_length, int& arr_destination_length)
    {
        for (int i = 0; i <= arr_source_length - 1; i++)
        {
            if (MyCheckPrime(arr_source[i]))
            {
                arr_destination[arr_destination_length] = arr_source[i];
                arr_destination_length++;
            }
        }
    }

    void MySum2Array(int arr1[], int arr2[], int arrsum[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arrsum[i] = arr1[i] + arr2[i];
    }

    void MyFillArrayFrom1ToN(int arr[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr[i] = i + 1;
    }

    bool MySercheElementInArray(int arr[], int arr_length, int key)
    {
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (key == arr[i])
                return true;
        }
        return false;
    }

    void MyShuffleArray(int arr[], int arr_length)
    {
        int temp;
        int temparr[100];
        for (int i = 0; i <= arr_length - 1; i++)
        {
            do
            {
                temp = MyRandomNumber(1, arr_length);
            } while (MySercheElementInArray(temparr, arr_length, temp));
            temparr[i] = temp;
        }
        MyCopyArray(temparr, arr, arr_length);
    }

    void MyShuffleArray2(int arr[], int arr_length)
    {
        for (int i = 1; i <= arr_length; i++)
            MySwapNumber(arr[MyRandomNumber(0, arr_length - 1)], arr[MyRandomNumber(0, arr_length - 1)]);
    }

    void MyReverseArray(int arr[], int arr2[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr2[i] = arr[arr_length - 1 - i];
    }

    void MyFillArrayWithRandomKeys(string arr[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr[i] = MyGetRandomKey();
    }

    int MyReturnIndexOfElement(int arr[], int arr_length, int element)
    {
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }

    bool MySercheElementInArray2(int arr[], int arr_length, int key)
    {
        return MyReturnIndexOfElement(arr, arr_length, key) != -1;
    }

    void MyAddElementToArray(int arr2[], int& arr2_length, int add_element)
    {
        arr2[arr2_length] = add_element;
        arr2_length++;
    }

    void MyUserInputNumberToArray(int arr[], int& arr_length)
    {
        bool add_more;
        do
        {
            MyAddElementToArray(arr, arr_length, MyReadIntNumber("please enter a number: "));
            cout << "do you want to add more numbers? (0 = no), (1 = yes): ";
            cin >> add_more;
        } while (add_more);
    }

    void MyCopyArrayUsingAddElementToArray(int arr[], int arr_length, int arr2[], int arr2_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            MyAddElementToArray(arr2, arr2_length, arr[i]);
    }

    void MyCopyOddNumbersToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (MyCheckOddEven(arr[i]) == enOddEven::odd)
                MyAddElementToArray(arr2, arr2_length, arr[i]);
        }
    }

    void MyCopyPrimeNumberUsingAddElementToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            if (MyCheckPrime(arr[i]))
                MyAddElementToArray(arr2, arr2_length, arr[i]);
    }

    void MyCopyDistinctNumbersToArray(int arr[], int arr_length, int arr2[], int& arr2_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            if (!MySercheElementInArray(arr2, arr2_length, arr[i]))
                MyAddElementToArray(arr2, arr2_length, arr[i]);
    }

    bool MyIsPalindromeArray(int arr[], int arr_length)
    {
        for (int i = 0; i <= (arr_length - 1) / 2; i++)
            if (arr[i] != arr[arr_length - 1 - i])
                return false;
        return true;
    }

    short MyCountOddNumbersInArray(int arr[], int arr_length)
    {
        int c = 0;
        for (int i = 0; i <= arr_length - 1; i++)
            if (MyCheckOddEven(arr[i]) == enOddEven::odd)
                c++;
        return c;
    }

    short MyCountEvenNumbersInArray(int arr[], int arr_length)
    {
        int c = 0;
        for (int i = 0; i <= arr_length - 1; i++)
            if (MyCheckOddEven(arr[i]) == enOddEven::even)
                c++;
        return c;
    }

    void MyFillArrayWithRandomNumbers_minus100_100(int arr[], int arr_length)
    {
        for (int i = 0; i <= arr_length - 1; i++)
            arr[i] = MyRandomNumber(-100, 100);
    }

    int MyCountPositiveNumberInArray(int arr[], int arr_length)
    {
        int c = 0;
        for (int i = 0; i <= arr_length - 1; i++)
            if (arr[i] > 0)
                c++;
        return c;
    }

    int MyCountNegativeNumberInArray(int arr[], int arr_length)
    {
        int c = 0;
        for (int i = 0; i <= arr_length - 1; i++)
            if (arr[i] <= 0)
                c++;
        return c;
    }

    bool MyIfNumberInArray(int arr[], int arr_length, int number)
    {
        for (int i = 0; i <= arr_length - 1; i++)
        {
            if (number == arr[i])
                return 1;
        }
        return 0;
    }

    void MyDeleteDuplicateNumbersInArray(int arrbefore[], int arrafter[], int arrbefore_l, int& arrafter_l)
    {
        int number;
        for (int i = 0; i <= arrbefore_l - 1; i++)
        {
            number = arrbefore[i];
            if (!MyIfNumberInArray(arrafter, arrafter_l, number))
            {
                arrafter[arrafter_l] = number;
                arrafter_l++;
            }
        }
    }



}
using namespace myarray;

namespace mymatrix
{
    void MyFillArrayWithRandomMatrix(int arr[3][3], short rows, short colm)
    {
        for (int i = 0; i <= rows - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                arr[i][j] = MyRandomNumber(1, 10);
            }
        }
    }

    void MyPrintArrayLikeMatrix(int arr[3][3], short rows, short colm)
    {
        for (int i = 0; i <= rows - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                printf("%02d\t", arr[i][j]);
            }
            cout << endl;
        }
    }

    int MySumArrayRow(int arr[3][3], short row, short colm)
    {
        int sum = 0;
        for (int i = 0; i <= colm - 1; i++)
        {
            sum += arr[row][i];
        }
        return sum;
    }

    void MyPrintEechRowSum(int arr[3][3], short row, short colm)
    {
        for (int i = 0; i <= row - 1; i++)
        {
            cout << "row " << i + 1 << " sum = " << MySumArrayRow(arr, i, colm) << endl;
        }
    }
    void MySumArrayRowsToNewArray(int arr[3][3], short row, short colm, int sumarr[3])
    {
        for (int i = 0; i <= row - 1; i++)
            sumarr[i] = MySumArrayRow(arr, i, colm);
    }

    void MyPrintEechRowSumUsingSumArray(int sumarr[3], short row)
    {
        for (int i = 0; i <= row - 1; i++)
            cout << "row " << i + 1 << " sum = " << sumarr[i] << endl;
    }

    int MySumArrayColm(int arr[3][3], short row, short colm)
    {
        int sum = 0;
        for (int i = 0; i <= row - 1; i++)
        {
            sum += arr[i][colm];
        }
        return sum;
    }

    void MyPrintEechColmSum(int arr[3][3], short row, short colm)
    {
        for (int i = 0; i <= colm - 1; i++)
        {
            cout << "colm " << i + 1 << " sum = " << MySumArrayColm(arr, row, i) << endl;
        }
    }

    void MySumArrayColmsToNewArray(int arr[3][3], short row, short colm, int sumarr[3])
    {
        for (int i = 0; i <= colm - 1; i++)
            sumarr[i] = MySumArrayColm(arr, row, i);
    }

    void MyPrintEechColmsSumUsingSumArray(int sumarr[3], short colm)
    {
        for (int i = 0; i <= colm - 1; i++)
            cout << "colm " << i + 1 << " sum = " << sumarr[i] << endl;
    }

    void MyFillMatrixInOrder(int arr[3][3], short row, short colm)
    {
        int c = 0;
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                c++;
                arr[i][j] = c;
            }
        }
    }

    void MyTransposMatrix(int arr[3][3], short row, short colm, int tarr[3][3])
    {
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                tarr[j][i] = arr[i][j];
            }
        }
    }

    void Mul2Array(int arr1[3][3], int arr2[3][3], int marr[3][3], int row, int colm)
    {
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
                marr[i][j] = arr1[i][j] * arr2[i][j];
        }
    }

    void MyPrintMiddleRow(int arr[3][3], short row, short colm)
    {
        short middlerow = row / 2;
        for (int i = 0; i <= colm - 1; i++)
            printf("%02d\t", arr[middlerow][i]);
        cout << endl;
    }

    void MyPrintMiddlecolm(int arr[3][3], short row, short colm)
    {
        short middlecolm = colm / 2;
        for (int i = 0; i <= row - 1; i++)
            printf("%02d\t", arr[i][middlecolm]);
        cout << endl;
    }

    int MySumOfMatrixElement(int arr[3][3], int row, int colm)
    {
        int sum = 0;
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
                sum += arr[i][j];
        }
        return sum;
    }

    bool MyCheckIfSumOfMatricesAreEqual(int matrix1[3][3], int matrix2[3][3], int row, int colm)
    {
        return MySumOfMatrixElement(matrix1, row, colm) == MySumOfMatrixElement(matrix2, row, colm);
    }

    bool MyCheckIfMatricesAreTypical(int matrix1[3][3], int matrix2[3][3], int row, int colm)
    {
        for (int i = 0; i <= row - 1; i++)
            for (int j = 0; j <= colm; j++)
                if (matrix1[i][j] != matrix2[i][j])
                    return 0;
        return 1;
    }

    bool MyIsMatrixIdentity(int arr[3][3], short row, short colm)
    {
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                if (i == j)
                {
                    if (arr[i][j] != 1)
                        return 0;
                }
                else
                {
                    if (arr[i][j] != 0)
                        return 0;
                }
            }
        }
        return 1;
    }

    bool MyIsMatrixScaler(int arr[3][3], short row, short colm)
    {
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                if (i == j)
                {
                    if (arr[i][j] != arr[0][0])
                        return 0;
                }
                else
                {
                    if (arr[i][j] != 0)
                        return 0;
                }
            }
        }
        return 1;
    }

    short MyCountNumberInMatrix(int arr[3][3], short row, short colm, int number)
    {
        short c = 0;
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                if (arr[i][j] == number)
                    c++;
            }
        }
        return c;
    }

    bool MyItIsSparseMatrix(int arr[3][3], short row, short colm)
    {
        short matrixsize = row * colm;
        return (MyCountNumberInMatrix(arr, 3, 3, 0) >= ceil((float)matrixsize / 2));
    }

    bool MyCheckIfThenumberInTheMatrix(int arr[3][3], short row, short colm, int number)
    {
        if (number < 1 || number >10)
            return 0;
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                if (arr[i][j] == number)
                    return 1;
            }
        }
        return 0;
    }


    void MyGetIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], short row, short colm, int intersected_arr[9], int& length)
    {
        int number;
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                number = matrix1[i][j];
                if (MyCheckIfThenumberInTheMatrix(matrix2, 3, 3, number))
                {
                    intersected_arr[length] = number;
                    length++;
                }
            }
        }
    }

    void MyMinMaxValueInMatrix(int matrix1[3][3], int row, int colm, int& min, int& max)
    {
        min = matrix1[0][0];
        max = matrix1[0][0];
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm - 1; j++)
            {
                if (matrix1[i][j] > max)
                    max = matrix1[i][j];
                if (matrix1[i][j] < min)
                    min = matrix1[i][j];
            }
        }
    }

    bool MyIsPalindromeMatrix(int matrix1[3][3], int row, int colm)
    {
        for (int i = 0; i <= row - 1; i++)
        {
            for (int j = 0; j <= colm / 2 - 1; j++)
            {
                if (matrix1[i][j] != matrix1[i][colm - 1 - j])
                    return 0;
            }
        }
        return 1;
    }



}
using namespace mymatrix;

namespace mystring
{
    void MyPrintFirstLetterOfEcheWord(string text)
    {
        cout << "first letters of this string:\n";
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= text.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && text[i] != ' ')
                cout << text[i] << endl;
            IsNextCharFirstLetter = (text[i] == ' ') ? 1 : 0;
        }
    }

    string MyUpperEcheLetterOfEcheWord(string s1)
    {
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && s1[i] != ' ')
                s1[i] = toupper(s1[i]);
            IsNextCharFirstLetter = (s1[i] == ' ') ? 1 : 0;
        }
        return s1;
    }

    string MyLowerEcheLetterOfEcheWord(string s1)
    {
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && s1[i] != ' ')
                s1[i] = tolower(s1[i]);
            IsNextCharFirstLetter = (s1[i] == ' ') ? 1 : 0;
        }
        return s1;
    }

    string MyLowerStringChars(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = tolower(s1[i]);
        return s1;
    }

    string MyUpperStringChars(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = toupper(s1[i]);
        return s1;
    }

    char MyInvertLetter(char x)
    {
        return isupper(x) ? tolower(x) : toupper(x);
    }

    string InvertAllStringLetter(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = MyInvertLetter(s1[i]);
        return s1;
    }


    enum enLetterCounter { capital = 1, small, digit, space, other, all };

    int MyLetterCounter(string s1, enLetterCounter lettercounter)
    {
        if (lettercounter == enLetterCounter::all)
            return s1.length();
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            switch (lettercounter)
            {
            case(enLetterCounter::capital):
            {
                if (isupper(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::small):
            {
                if (islower(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::digit):
            {
                if (isdigit(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::space):
            {
                if (isspace(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::other):
            {
                if (!isupper(s1[i]) && !islower(s1[i]) && !isdigit(s1[i]) && !isspace(s1[i]))
                    counter++;
                break;
            }
            }
        }
        return counter;
    }

    int MyCountCapitalLetters(string s1)
    {
        int c = 0;
        for (int i = 0; i <= s1.length()-1; i++)
            if (isupper(s1[i]))
                c++;
        return c;
    }

    int MyCountSmallLetters(string s1)
    {
        int c = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
            if (islower(s1[i]))
                c++;
        return c;
    }

    int MyCountLetterInString(string s1, char x,bool CareToCaseSensitive = false)
    {
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (CareToCaseSensitive)
            {
                if (s1[i] == x)
                    counter++;
            }
            else
            {
                if (s1[i] == x || MyInvertLetter(s1[i]) == x)
                    counter++;
            }      
        }
        return counter;
    }

    bool MyIsItVowel(char ch1)
    {
        char vowel[5] = { 'a','e','i','o','u' };
        ch1 = tolower(ch1);
        for (char c : vowel)
            if (ch1 == c)
                return 1;
        return 0;
    }

    int MyCountVowels(string s1)
    {
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
            if (MyIsItVowel(s1[i]))
                counter++;
        return counter;
    }

    void MyPrintVowelsInString(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            if (MyIsItVowel(s1[i]))
                cout << s1[i] << "    ";
    }

    void MyPrintEachWordInString(string s1)
    {
        string delim = " ";
        string NullString = "";
        string word;
        int pos = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            if (word != NullString)
                cout << word << endl;
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            cout << s1 << endl;
    }

    int MyPrintNumberOfWordsInString(string s1)
    {
        string delim = " ";
        string NullString = "";
        string word;
        int pos = 0;
        int counter = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            if (word != NullString)
                counter++;
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            counter++;
        return counter;
    }

    vector <string> MySplitString(string s1, string delim)
    {
        vector <string> vs1;
        string NullString = "";
        string word;
        int pos = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            if (word != NullString)
                vs1.push_back(word);
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            vs1.push_back(s1);
        return vs1;
    }

    string MyTrimRight(string s1)
    {
        for (short i = s1.length() - 1; i >= 0; i--)
        {
            if (s1[i] != ' ')
                return s1.substr(0, i + 1);
        }
        return "";
    }

    string MyTrimLeft(string s1)
    {
        for (short i = 0; i <= s1.length() - 1; i++)
        {
            if (s1.at(i) != ' ')
                return s1.substr(i, s1.length() - i);
        }
        return "";
    }

    string MyTrim(string s1)
    {
        return MyTrimLeft(MyTrimRight(s1));
    }

    string MyJoinString(vector <string> vs1, string separator)
    {
        string s1 = "";
        for (string& word : vs1)
            s1 += word + separator;
        return s1.substr(0, s1.length() - separator.length());
    }

    string MyJoinString(string arrofstring[], string separator, short arrofstring_length)
    {
        string s1 = "";
        for (short i = 0; i <= arrofstring_length - 1; i++)
            s1 += arrofstring[i] + separator;
        return s1.substr(0, s1.length() - separator.length());
    }

    string MyReverseString(string s1)
    {
        vector <string> vs1 = MySplitString(s1, " ");
        string s2 = "";
        vector <string>::iterator iter;
        iter = vs1.end();
        while (iter != vs1.begin())
        {
            iter--;
            s2 += *iter + " ";
        }
        return s2.substr(0, s2.length() - 1);
    }

    string MyRemovePunctions(string s1)
    {
        string s2 = "";
        for (short i = 0; i <= s1.length() - 1; i++)
        {
            if (!ispunct(s1[i]))
                s2 += s1[i];
        }
        return s2;
    }

    string MyReplaceWordUsingBuiltInFunction(string s1, string ojword, string newword)
    {
        int pos = s1.find(ojword);
        while (pos != s1.npos)
        {
            s1 = s1.replace(pos, ojword.length(), newword);
            pos = s1.find(ojword);
        }
        return s1;
    }

    string MyReplaceWord(string s1, string oldword, string newword, bool CaseSensitive = 1)
    {
        vector <string> vs1 = MySplitString(s1, " ");
        for (string& word : vs1)
        {
            if (CaseSensitive)
            {
                if (word == oldword)
                    word = newword;
            }
            else
            {
                if (MyLowerStringChars(word) == MyLowerStringChars(oldword))
                    word = newword;
            }
        }
        return MyJoinString(vs1, " ");
    }



}
using namespace mystring;

namespace myfile
{
    void MyAppendDatatoFile(string filename, string line)
    {
        fstream myfile;
        myfile.open(filename, ios::out | ios::app);

        if (myfile.is_open())
        {
            myfile << line << endl;
            myfile.close();
        }
        else
            cout << "\nerror file is not opend!\n";
    }

    void MyPrintFileContent(string filename)
    {
        fstream myfile;
        myfile.open(filename, ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
                cout << line << endl;
            myfile.close();
        }
    }

    void MyLoadFileContentToVector(string filename, vector <string>& vfilecontent)
    {
        fstream myfile;

        myfile.open(filename, ios::in);

        if (myfile.is_open())
        {
            string line;

            while (getline(myfile, line))
                vfilecontent.push_back(line);

            myfile.close();
        }
        else
            cout << "!error!";
    }

    void MySaveContentFromVectorToFile(string filename, vector <string>& vfilecontent)
    {
        fstream myfile;

        myfile.open(filename, ios::out);

        if (myfile.is_open())
        {
            for (string& c_line : vfilecontent)
            {
                if (c_line == "")
                    continue;
                myfile << c_line << endl;
            }
            myfile.close();
        }
    }

    void MyDeleteLineFromFile(string filename, string delete_this_line)
    {
        vector <string> vfilecontent;
        MyLoadFileContentToVector(filename, vfilecontent);
        for (string& line : vfilecontent)
        {
            if (line == delete_this_line)
                line = "";
        }
        MySaveContentFromVectorToFile(filename, vfilecontent);
    }

    void MyUpdateLineInFile(string filename, string update_from_this, string update_to_this)
    {
        vector <string> vfile;
        MyLoadFileContentToVector(filename, vfile);
        for (string& line : vfile)
        {
            if (line == update_from_this)
            {
                line = update_to_this;
                break;
            }
        }
        MySaveContentFromVectorToFile(filename, vfile);
    }



}
using namespace myfile;

namespace mybank
{
    const string ClientFileName = "ClientList.txt";

    struct stClient
    {
        string AccountNumber;
        string PinCode;
        string Name;
        string PhoneNumber;
        double AccountBalance;
    };

    bool IsClientExist(string AccountNumber);
    
    stClient MyReadNewClient()
    {
        stClient Client;
        cout << "Please enter your account number: ";
        getline(cin >> ws, Client.AccountNumber); //cin >> ws to fix input problem
        while (IsClientExist(Client.AccountNumber))
        {
            cout << "\nClient with [" << Client.AccountNumber
                << "] already exists, enter another account number:";
            getline(cin >> ws, Client.AccountNumber); //cin >> ws to fix input problem 
        }
        Client.PinCode = MyReadText("Please enter your pincode: ");
        Client.Name = MyReadText("Please enter your name: ");
        Client.PhoneNumber = MyReadText("Please enter your phone number: ");
        Client.AccountBalance = MyReadFloatNumber("Please enter your account balance: ");
        return Client;
    }

    string MyConvertRecordToLine(stClient Client, string separator = "#//#")
    {
        string ClientDataString = "";

        ClientDataString += Client.AccountNumber + separator;
        ClientDataString += Client.PinCode + separator;
        ClientDataString += Client.Name + separator;
        ClientDataString += Client.PhoneNumber + separator;
        ClientDataString += to_string(Client.AccountBalance);
        
        return ClientDataString;
    }

    void MyPrintClientData(stClient Client)
    {
        cout << "Account number  : " << Client.AccountNumber << endl;
        cout << "pincode         : " << Client.PinCode << endl;
        cout << "name            : " << Client.Name << endl;
        cout << "phone number    : " << Client.PhoneNumber << endl;
        cout << "Account balance : " << Client.AccountBalance << endl;
    }

    stClient MyConvertLineDataToRecord(string ClientData, string separator = "#//#")
    {
        vector <string> vRecord;
        vRecord = MySplitString(ClientData, separator);

        stClient Client;
        Client.AccountNumber = vRecord[0];
        Client.PinCode = vRecord[1];
        Client.Name = vRecord[2];
        Client.PhoneNumber = vRecord[3];
        Client.AccountBalance = stod(vRecord[4]);

        return Client;
    }
    
    vector <stClient> MyLoadRecordsToVector(string FileName)
    {
        vector <string> VFileContant;
        MyLoadFileContentToVector(ClientFileName, VFileContant);
        vector <stClient> VClients;
        for (string& line : VFileContant)
            VClients.push_back(MyConvertLineDataToRecord(line));
        return VClients;
    }

    bool MyFindClientByAccountNumber(string AccountNumber, stClient& Client)
    {
        vector <stClient> VClients;
        VClients = MyLoadRecordsToVector(ClientFileName);
        for (stClient& c : VClients)
            if (AccountNumber == c.AccountNumber)
            {
                Client = c;
                return 1;
            }
        return 0;
    }

    void MyAddClients()
    {
        char AddMore;
        stClient Client;
        do
        {
            system("cls");
            cout << "Adding new client:\n\n";
            MyAppendDatatoFile(ClientFileName, MyConvertRecordToLine(MyReadNewClient()));
            cout << "\nclient added successfully, do you want to add more clients Y/N: ";
            cin >> AddMore;
        } while (toupper(AddMore) == 'Y');
    }

    void MyPrintClientDataInList(stClient Client)
    {
        cout << "| " << setw(16) << left << Client.AccountNumber;
        cout << " | " << setw(9) << left << Client.PinCode;
        cout << " | " << setw(25) << left << Client.Name;
        cout << " | " << setw(14) << left << Client.PhoneNumber;
        cout << " | " << setw(13) << left << Client.AccountBalance << " |";
    }

    void MyPrintClientsList(vector <string> VFileContant)
    {
        cout << "\t\t\t\tClient List (" << VFileContant.size() << ") Client (s)\n";
        cout << "_____________________________________________________________________________________________\n";
        cout << "|  Account Number  |  PinCode  |        Client Name        |  Phone Number  |    Balance    |\n";
        cout << "_____________________________________________________________________________________________\n";
        for (string& line : VFileContant)
        {
            MyPrintClientDataInList(MyConvertLineDataToRecord(line));
            cout << endl;
        }
        cout << "_____________________________________________________________________________________________\n";
    }

    void MyPrintClientDataByAccountNumber(string AccountNumber)
    {
        stClient Client;
        if (MyFindClientByAccountNumber(AccountNumber, Client))
        {
            cout << "\nthe following are client details:\n\n";
            MyPrintClientData(Client);
        }
        else
            cout << "\nClient with account number (" << AccountNumber << ") not found!";
    }

    void MyDeleteClient(string AccountNumber)
    {
        stClient Client;

        if (MyFindClientByAccountNumber(AccountNumber, Client))
        {
            cout << "\nthe following are client details:\n\n";
            MyPrintClientData(Client);
            if (toupper(MyReadLetter("\nAre you sure you want to delete this client (Y/N) ?")) == 'Y')
            {
                MyDeleteLineFromFile(ClientFileName, MyConvertRecordToLine(Client));
                cout << "\nClient Deleted Successfully\n";
            }
        }
        else
            cout << "\nClient with account number (" << AccountNumber << ") not found!";
    }

    stClient MyUpdateClientData(stClient Client)
    {
        cout << "\nPlease enter your pincode: ";
        getline(cin >> ws, Client.PinCode); //cin >> ws to fix input problem
        Client.Name = MyReadText("Please enter your name: ");
        Client.PhoneNumber = MyReadText("Please enter your phone number: ");
        Client.AccountBalance = MyReadFloatNumber("Please enter your account balance: ");

        return Client;
    }

    void MyUpdateClientDataByAccountNumber(string AccountNumber)
    {
        stClient Client;

        if (MyFindClientByAccountNumber(AccountNumber, Client))
        {
            cout << "\nthe following are client details:\n\n";
            MyPrintClientData(Client);
            if (toupper(MyReadLetter("\nAre you sure you want to update this client (Y/N) ?")) == 'Y')
            {
                stClient UpdatedClientData = MyUpdateClientData(Client);
                MyUpdateLineInFile(ClientFileName, MyConvertRecordToLine(Client), MyConvertRecordToLine(UpdatedClientData));
                cout << "\nClient Updated Successfully\n";
            }
        }
        else
            cout << "\nClient with account number (" << AccountNumber << ") not found!";

    }

    bool IsClientExist(string AccountNumber)
    {
        vector <stClient> VClients;
        VClients = MyLoadRecordsToVector(ClientFileName);
        for (stClient& c : VClients)
            if (AccountNumber == c.AccountNumber)
                return 1;
        return 0;
    }

}
using namespace mybank;

namespace myother2
{
    void MyPrintMultiplicationTableUpSide()
    {
        cout << "\n\n\t\t\tMultiplication Table From 1 to 10\n\n";
        for (int i = 1; i <= 10; i++)
            cout << "\t" << i;
        cout << "\n-----------------------------------------------------------------------------------\n";
    }

    void MyPrintMultiplicationTableLeftSide(int i)
    {
        cout << " " << i;
        if (i >= 10)
            cout << "  | ";
        else
            cout << "   | ";
    }

    void MyCalculateMultiplicationTable(int i)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << "\t" << i * j;
        }
    }

    void MyPrintMultiplicationTable()
    {
        MyPrintMultiplicationTableUpSide();

        for (int i = 1; i <= 10; i++)
        {
            MyPrintMultiplicationTableLeftSide(i);
            MyCalculateMultiplicationTable(i);
            cout << endl;
        }
    }
    
    void MyPrintPrimeNumbersFrom1ToN(int number)
    {

        cout << "\nprime numbers from 1 to " << number << " are :\n\n";
        for (int i = 1; i <= number; i++)
        {
            if (MyCheckPrime(i) == true)
                cout << i << endl;
        }
    }
    
    bool MyIsPerfectNumber(int number)
    {
        int sum = 0;
        for (int i = 1; i < number; i++)
        {
            if (number % i == 0)
                sum += i;
        }
        return sum == number;
    }

    void MyPrintIsPerfect(int number)
    {
        if (MyIsPerfectNumber(number))
            cout << number << " is perfect number";
        else cout << number << " is not perfect number";
    }

    void MyPrintPerfectNumbersFrom1ToN(int number)
    {
        cout << "\nperfect numbers from 1 to " << number << " are :\n\n";
        for (int i = 1; i <= number; i++)
        {
            if (MyIsPerfectNumber(i) == true)
                cout << i << endl;
        }
    }

    void MyPrintDigits(int number)
    {
        cout << endl;
        while (number > 0)
        {
            cout << number % 10 << endl;
            number = number / 10;
        }
    }

    int MySumOfDigits(int number)
    {
        int sum = 0;
        while (number > 0)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    void MyPrintSumOfDigits(int number)
    {
        cout << "\nsum of " << number << " digits = " << MySumOfDigits(number);
    }

    int MyReverseDigit(int number)
    {
        int reversed_number = 0;
        while (number > 0)
        {
            reversed_number = reversed_number * 10 + number % 10;
            number /= 10;
        }
        return reversed_number;
    }

    void MyPrintReverseOfDigit(int number)
    {
        cout << "reversed digit is:\n" << MyReverseDigit(number) << endl;
    }

    int MyCheckFrequencyOfSearchedDigitInNumber(int number, int searched_digit)
    {
        int frequency = 0;
        while (number > 0)
        {
            if (number % 10 == searched_digit)
                frequency++;
            number /= 10;
        }
        return frequency;
    }

    void MyPrintFrequencyOfDigit(int number, int searched_digit)
    {
        int frequency = MyCheckFrequencyOfSearchedDigitInNumber(number, searched_digit);
        cout << "\ndigit " << searched_digit << " frequency is " << frequency << " time(s)\n";
    }

    void MyPrintAllDigitsFrequency(int number)
    {
        int frequency;
        for (int i = 1; i <= 9; i++)
        {
            frequency = MyCheckFrequencyOfSearchedDigitInNumber(number, i);
            if (frequency == 0)
                continue;
            cout << "\ndigit " << i << " frequency is " << frequency << " time(s)\n";
        }
    }

    bool MyIsPalindromeNumber(int number)
    {
        return number == MyReverseDigit(number);
    }

    void MyPrintInvertedNumberPattern(int number)
    {
        cout << endl;
        for (int i = number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
                cout << i;
            cout << endl;
        }
    }

    void MyPrintNumberPattern(int number)
    {
        cout << "\n";
        for (int i = 1; i <= number; i++)
        {
            for (int j = 1; j <= i; j++)
                cout << i;
            cout << "\n";
        }
    }

    void MyPrintInvertedLetterPattern(int number)
    {
        cout << endl;
        for (int i = 64 + number; i >= 65; i--)
        {
            for (int j = 65; j <= i; j++)
                cout << char(i);
            cout << endl;
        }
    }

    void MyPrintLetterPattern(int number)
    {
        cout << endl;
        for (int i = 65; i <= 64 + number; i++)
        {
            for (int j = 1; j <= i - 64; j++)
                cout << char(i);
            cout << endl;
        }
    }

    void MyPrintAllWordsFromAAAToZZZ()
    {
        string word;
        for (int i = 65; i <= 90; i++)
            for (int j = 65; j <= 90; j++)
                for (int t = 65; t <= 90; t++)
                {
                    word = char(i);
                    word += char(j);
                    word += char(t);
                    cout << word << endl;
                    word = "";
                }
    }

    bool MySercheForPassword(string password)
    {
        cout << endl;
        string word;
        int trial = 0;
        for (int i = 65; i <= 90; i++)
            for (int j = 65; j <= 90; j++)
                for (int t = 65; t <= 90; t++)
                {
                    trial++;
                    cout << "trail [" << trial << "] : ";
                    word = char(i);
                    word += char(j);
                    word += char(t);
                    cout << word << endl;
                    if (word == password)
                    {
                        cout << "\npassword is " << word << "\nfound after " << trial << " trial(s)\n";
                        return true;
                    }
                    word = "";
                }
        cout << "\npassword not found!\n";
        return false;
    }

    string MyEncrypt_Password(string password, short encryption_key)
    {
        for (int i = 0; i <= password.length(); i++)
            password[i] = char((int)password[i] + encryption_key);
        return password;
    }

    string MyDecrypt_Password(string password, short encryption_key)
    {
        for (int i = 0; i <= password.length(); i++)
            password[i] = char((int)password[i] - encryption_key);
        return password;
    }

    void MyPrintFibonacciSeriesUsingFor(int c)
    {
        int prev2, prev1;
        prev2 = 0;
        prev1 = 1;
        int fibonacci_number;
        cout << "1  ";
        for (int i = 1; i <= c - 1; i++)
        {
            fibonacci_number = prev2 + prev1;
            cout << fibonacci_number << "  ";
            prev2 = prev1;
            prev1 = fibonacci_number;
        }
    }

    void MyPrintFibonacciSeriesUsingRecursion(int c, int prev1, int prev2)
    {
        if (c - 1 >= 1)
        {
            int fibo = prev1 + prev2;
            cout << fibo << "  ";
            prev2 = prev1;
            prev1 = fibo;
            MyPrintFibonacciSeriesUsingRecursion(c - 1, prev1, prev2);
        }
    }



}
using namespace myother2;

namespace mytimedate
{
    string MyNumberToText(int number)
    {
        if (number < 20)
        {
            string arr1[] = { "","one","two","three","four","five","six","seven","eight","nine",
                              "ten","eleven","twelve","thirteen","fourteen","fifteen",
                              "sixteen","seventeen","eighteen","nineteen" };
            return arr1[number];
        }
        if (number < 99)
        {
            string arr2[] = { "","","twenty","thirty","forty","fifty",
                              "sixty","seventy","eighty","ninety" };
            return arr2[number / 10] + " " + MyNumberToText(number % 10);
        }

        if (number < 199)
            return  "one hundred " + MyNumberToText(number % 100);

        if (number < 999)
            return  MyNumberToText(number / 100) + " hundreds " + MyNumberToText(number % 100);

        if (number < 1999)
            return  "one thousand " + MyNumberToText(number % 1000);

        if (number < 999999)
            return  MyNumberToText(number / 1000) + " thousands " + MyNumberToText(number % 1000);

        if (number < 1999999)
            return  "one million " + MyNumberToText(number % 1000000);

        if (number < 999999999)
            return  MyNumberToText(number / 1000000) + " millions " + MyNumberToText(number % 1000000);

        if (number < 1999999999)
            return  "one billion " + MyNumberToText(number % 1000000);

        if (number < 999999999999)
            return  MyNumberToText(number / 1000000) + " billions " + MyNumberToText(number % 1000000);

        return "";
    }

    bool MyIsLeapYearV1(int year)
    {
        if (year % 400 == 0)
            return 1;
        else if (year % 100 == 0)
            return 0;
        else if (year % 4 == 0)
            return 1;
        else
            return 0;
    }

    bool MyIsLeapYear(int year)
    {
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }


    int MyNumberOfDaysInYear(int year)
    {
        return MyIsLeapYear(year) ? 366 : 365;
    }

    int MyNumberOfHoursInYear(int year)
    {
        return MyNumberOfDaysInYear(year) * 24;
    }

    int MyNumberOfMinutsInYear(int year)
    {
        return MyNumberOfHoursInYear(year) * 60;
    }

    int MyNumberOfSecondsInYear(int year)
    {
        return MyNumberOfMinutsInYear(year) * 60;
    }


    int MyNumberOfDaysInMonthV1(int year, int month)
    {
        if (month == 2)
            return MyIsLeapYear(year) ? 29 : 28;
        int arr[] = { 1,3,5,7,8,10,12 };
        for (int i = 0; i <= 7 - 1; i++)
        {
            if (month == arr[i + 1])
                return 31;
        }
        return 30;
    }

    int MyNumberOfDaysInMonth(int year, int month)
    {
        int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (MyIsLeapYear(year) && month == 2) ? 29 : arr[month];
    }

    int MyNumberOfHoursInMonth(int year, int month)
    {
        return MyNumberOfDaysInMonthV1(year, month) * 24;
    }

    int MyNumberOfMinutsInMonth(int year, int month)
    {
        return MyNumberOfHoursInMonth(year, month) * 60;
    }

    int MyNumberOfSecondsInMonth(int year, int month)
    {
        return MyNumberOfMinutsInMonth(year, month) * 60;
    }


    int MyFindDayOrder(int year, int month, int day)
    {
        int a = ((14 - month) / 12);
        int y = year - a;
        int m = month + (12 * a) - 2;
        int d = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
        return d;
    }

    string MyGetDayName(int DayOrder)
    {
        string arr[] = { "sun","mon","tue","wed","thu","fri","sat" };
        return arr[DayOrder];
    }

    string MyGetMonthName(int month)
    {
        string arr[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return arr[month];
    }

    void MyPrintMonthCalendar(int year, int month)
    {
        cout << "\n\n  _______________" << MyGetMonthName(month) << "_______________" << endl << endl;
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        int DaysInMonth = MyNumberOfDaysInMonth(year, month);
        int DayOrder = MyFindDayOrder(year, month, 1);
        int iindex;

        for (iindex = 0; iindex <= DayOrder - 1; iindex++)
            cout << "     ";

        for (int i = 1; i <= DaysInMonth; i++)
        {
            printf("%5d", i);

            iindex++;
            if (iindex == 7 && i != DaysInMonth)
            {
                cout << endl;
                iindex = 0;
            }
        }
        cout << "\n  __________________________________" << endl;
    }

    void MyPrintYearCalendar(int year)
    {
        cout << "  _________________________________";
        cout << "\n             " << year << " - calendar\n";
        cout << "  _________________________________";

        for (int i = 1; i <= 12; i++)
        {
            MyPrintMonthCalendar(year, i);
            cout << "\n";
        }
    }

    int MyCalculateHowManyDayGoneFromTheStartOfTheYear(int year, int month, int day)
    {
        int TotalDays = 0;
        for (int i = 1; i <= month - 1; i++)
        {
            TotalDays += MyNumberOfDaysInMonth(year, i);
        }
        TotalDays += day;
        return TotalDays;
    }

    struct stdate
    {
        int year;
        int month;
        int day;
    };

    stdate MyCalculateDateForDayUsingTotalDays(int remaninDays, int year)
    {
        stdate date;

        date.year = year;
        date.month = 1;

        int daysInMonth = MyNumberOfDaysInMonth(year, date.month);

        while (remaninDays > daysInMonth)
        {
            remaninDays -= daysInMonth;
            date.month++;
            daysInMonth = MyNumberOfDaysInMonth(year, date.month);
        }

        date.day = remaninDays;

        return date;
    }

    stdate MyAddDaysToDate(stdate date, int DaysToAdd)
    {
        int remaninDays = DaysToAdd + MyCalculateHowManyDayGoneFromTheStartOfTheYear(date.year, date.month, date.day);

        date.month = 1;

        int daysInMonth = MyNumberOfDaysInMonth(date.year, date.month);

        while (remaninDays > daysInMonth)
        {
            remaninDays -= daysInMonth;
            date.month++;
            if (date.month == 13)
            {
                date.month = 1;
                date.year++;
            }
            daysInMonth = MyNumberOfDaysInMonth(date.year, date.month);
        }
        date.day = remaninDays;
        return date;
    }

    stdate MyReadDate()
    {
        stdate date;

        date.day = MyReadIntNumber("please enter a day: ");
        date.month = MyReadIntNumber("please enter a month: ");
        date.year = MyReadIntNumber("please enter a year: ");

        return date;
    }

    bool MyIsDate1BeforeDate2(stdate date1, stdate date2)
    {
        if (date1.year < date2.year)
            return 1;
        else if (date1.year > date2.year)
            return 0;
        else if (date1.month < date2.month)
            return 1;
        else if (date1.month > date2.month)
            return 0;
        else if (date1.day < date2.day)
            return 1;
        else if (date1.day > date2.day)
            return 0;
        else
            return 0;
    }

    bool MyIsDate1equalDate2(stdate date1, stdate date2)
    {
        return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? 1 : 0) : 0) : 0;
    }

    bool MyIsLastMonthInYear(int month)
    {
        return 12 == month;
    }

    bool MyIsLastDayInMonth(stdate date)
    {
        return MyNumberOfDaysInMonth(date.year, date.month) == date.day;
    }

    stdate MyIncressDateByOneDay(stdate date)
    {
        if (MyIsLastDayInMonth(date))
        {
            if (MyIsLastMonthInYear(date.month))
            {
                date.day = 1;
                date.month = 1;
                date.year++;
            }
            else
            {
                date.day = 1;
                date.month++;
            }
        }
        else
            date.day++;

        return date;
    }

    void MySwapStruct(stdate& date1, stdate& date2)
    {
        stdate temp;

        temp = date1;
        date1 = date2;
        date2 = temp;
    }

    int MyCalculateDifrenceBetwen2Date(stdate date1, stdate date2, bool includeLastDay = 0)
    {
        int days = 0;
        int multiplayer = 1;

        if (!MyIsDate1BeforeDate2(date1, date2))
        {
            MySwapStruct(date1, date2);
            multiplayer = -1;
        }

        while (MyIsDate1BeforeDate2(date1, date2))
        {
            date1 = MyIncressDateByOneDay(date1);
            days++;
        }

        return  includeLastDay ? ++days * multiplayer : days * multiplayer;
    }

    stdate MyGetSystemTime()
    {
        stdate date;
        time_t t = time(0);
        tm* now = localtime(&t);
        date.year = now->tm_year + 1900;
        date.month = now->tm_mon + 1;
        date.day = now->tm_mday;
        return date;
    }

    void MyPrintDate(stdate date)
    {
        cout << date.day << "/" << date.month << "/" << date.year;
    }

    
    stdate MyIncressDateByXDays(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyIncressDateByOneDay(date);
        return date;
    }

    stdate MyIncressDateByOneWeek(stdate date)
    {
        for (int i = 1; i <= 7; i++)
            date = MyIncressDateByOneDay(date);
        return date;
    }

    stdate MyIncressDateByXWeeks(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyIncressDateByOneWeek(date);
        return date;
    }

    stdate MyIncressDateByOneMonth(stdate date)
    {

        date.month++;

        if (date.month == 13)
        {
            date.month = 1;
            date.year++;
        }
        int NumberOfDaysInMonth = MyNumberOfDaysInMonth(date.year, date.month);
        if (date.day > NumberOfDaysInMonth)
            date.day = NumberOfDaysInMonth;

        return date;
    }

    stdate MyIncressDateByXMonths(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyIncressDateByOneMonth(date);
        return date;
    }

    stdate MyIncressDateByOneYear(stdate date)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year++;

        return date;
    }

    stdate MyIncressDateByXYears(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyIncressDateByOneYear(date);
        return date;
    }
    
    stdate MyIncressDateByXYearsFaster(stdate date, int c)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year += c;

        return date;
    }

    stdate MyIncressDateByOneDecade(stdate date)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year += 10;

        return date;
    }

    stdate MyIncressDateByXDecades(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyIncressDateByOneDecade(date);
        return date;
    }

    stdate MyIncressDateByXDecadesFaster(stdate date, int c)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;

        date.year += 10 * c;

        return date;
    }


    stdate MyDecreaseDateByOneDay(stdate date)
    {
        if (date.day == 1)
        {
            if (date.month == 1)
            {
                date.month = 12;
                date.day = 31;
                date.year--;
            }
            else
            {
                date.month--;
                date.day = MyNumberOfDaysInMonth(date.year, date.month);
            }
        }
        else
            date.day--;

        return date;
    }

    stdate MyDecreaseDateByXDays(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyDecreaseDateByOneDay(date);
        return date;
    }

    stdate MyDecreaseDateByOneWeek(stdate date)
    {
        for (int i = 1; i <= 7; i++)
            date = MyDecreaseDateByOneDay(date);
        return date;
    }

    stdate MyDecreaseDateByXWeeks(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyDecreaseDateByOneWeek(date);
        return date;
    }

    stdate MyDecreaseDateByOneMonth(stdate date)
    {

        date.month--;

        if (date.month == 0)
        {
            date.month = 12;
            date.year--;
        }
        int NumberOfDaysInMonth = MyNumberOfDaysInMonth(date.year, date.month);
        if (date.day > NumberOfDaysInMonth)
            date.day = NumberOfDaysInMonth;

        return date;
    }

    stdate MyDecreaseDateByXMonths(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyDecreaseDateByOneMonth(date);
        return date;
    }

    stdate MyDecreaseDateByOneYear(stdate date)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year--;

        return date;
    }

    stdate MyDecreaseDateByXYears(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyDecreaseDateByOneYear(date);
        return date;
    }

    stdate MyDecreaseDateByXYearsFaster(stdate date, int c)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year -= c;

        return date;
    }

    stdate MyDecreaseDateByOneDecade(stdate date)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;
        date.year -= 10;

        return date;
    }

    stdate MyDecreaseDateByXDecades(stdate date, int c)
    {
        for (int i = 1; i <= c; i++)
            date = MyDecreaseDateByOneDecade(date);
        return date;
    }

    stdate MyDecreaseDateByXDecadesFaster(stdate date, int c)
    {
        if (date.day == 29 && date.month == 2)
            date.day--;

        date.year -= 10 * c;

        return date;
    }

    int MyFindDayOrder(stdate date)
    {
        return MyFindDayOrder(date.year, date.month, date.day);
    }

    int MyCalculateHowManyDayGoneFromTheStartOfTheYear(stdate date)
    {
        return MyCalculateHowManyDayGoneFromTheStartOfTheYear(date.year, date.month, date.day);
    }

    bool MyIsItEndOfWeek(stdate date)
    {
        return MyFindDayOrder(date) == 6;
    }

    bool MyIsItWeekEnd(stdate date)
    {
        int dayorder = MyFindDayOrder(date);
        return ((dayorder == 5) || (dayorder == 6));
    }

    bool MyIsItBusinessDay(stdate date)
    {
        return !MyIsItWeekEnd(date);
    }

    int MyDaysUntilEndOfWeek(stdate date)
    {
        return 6 - MyFindDayOrder(date);
    }

    int MyDaysUntilEndOfMonth(stdate date)
    {
        stdate endOfMonth;

        endOfMonth.day = MyNumberOfDaysInMonth(date.year, date.month);
        endOfMonth.month = date.month;
        endOfMonth.year = date.year;

        return MyCalculateDifrenceBetwen2Date(date, endOfMonth, 1);
    }

    int MyDaysUntilEndOfYear(stdate date)
    {
        stdate endOfyear;

        endOfyear.day = 31;
        endOfyear.month = 12;
        endOfyear.year = date.year;

        return MyCalculateDifrenceBetwen2Date(date, endOfyear, 1);
    }

    int MyCalculateTotalVacationDays(stdate from, stdate to)
    {
        int c = 0;
        while (!MyIsDate1equalDate2(from, to))
        {
            if (MyIsItBusinessDay(from))
                c++;
            from = MyIncressDateByOneDay(from);
        }
        return c;
    }

    stdate MyVacationReturnDate(stdate date1, int VacationPeriod)
    {
        while (VacationPeriod != 0)
        {
            if (MyIsItBusinessDay(date1))
                VacationPeriod--;
            date1 = MyIncressDateByOneDay(date1);
        }
        return date1;
    }

    bool MyIsDate1AfterDate2(stdate date1, stdate date2)
    {
        return !MyIsDate1BeforeDate2(date1, date2) && !MyIsDate1equalDate2(date1, date2);
    }

    enum enDateCompareResult { Before = -1, Equal = 0, After = 1 };

    enDateCompareResult MyCompareResult(stdate date1, stdate date2)
    {
        if (MyIsDate1BeforeDate2(date1, date2))
            return enDateCompareResult::Before;
        else if (MyIsDate1equalDate2(date1, date2))
            return enDateCompareResult::Equal;
        return enDateCompareResult::After;
    }

    struct stDatePeriod
    {
        stdate StartDate;
        stdate EndDate;
    };

    bool MyIsPeriodsOverLap(stDatePeriod period1, stDatePeriod period2)
    {
        return !(MyIsDate1BeforeDate2(period1.EndDate, period2.StartDate) || MyIsDate1AfterDate2(period1.StartDate, period2.EndDate));

    }

    int MyCalculetePeriodlength(stDatePeriod Period1, bool includeEndDay = 0)
    {
        return MyCalculateDifrenceBetwen2Date(Period1.StartDate, Period1.EndDate, includeEndDay);
    }

    bool MyIsDateWithinPeriod(stDatePeriod Period, stdate date)
    {
        return MyIsDate1AfterDate2(date, Period.StartDate) && MyIsDate1BeforeDate2(date, Period.EndDate);
    }

    int MyOverlapDaysCount(stDatePeriod period1, stDatePeriod period2)
    {
        if (MyIsPeriodsOverLap(period1, period2))
        {
            stdate start, end;

            if (MyIsDate1AfterDate2(period1.StartDate, period2.StartDate))
                start = period1.StartDate;
            else
                start = period2.StartDate;

            if (MyIsDate1BeforeDate2(period1.EndDate, period2.EndDate))
                end = period1.EndDate;
            else
                end = period2.EndDate;

            int c = 0;
            while (!MyIsDate1equalDate2(start, end))
            {
                c++;
                start = MyIncressDateByOneDay(start);
            }

            return c;
        }
        else
            return -1;
    }

    stDatePeriod MyReadPeriod()
    {
        stDatePeriod Period;
        cout << "\nplease enter start date:\n";
        Period.StartDate = MyReadDate();
        cout << "\nplease enter end date:\n";
        Period.EndDate = MyReadDate();
        return Period;
    }

    bool MyIsValidDate(stdate date)
    {
        if (date.day < 1 || date.day > MyNumberOfDaysInMonth(date.year, date.month))
            return 0;

        if (date.month < 1 || date.month > 12)
            return 0;

        if (date.year < 1980 || date.year > 2030)
            return 0;

        return 1;
    }

    string MyConvertDateToDateString(stdate date)
    {
        return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    }

    stdate MyConvertDateStringToDate(string s1)
    {
        vector <string> v1 = MySplitString(s1, "/");
        stdate date;
        date.day = stoi(v1[0]);
        date.month = stoi(v1[1]);
        date.year = stoi(v1[2]);
        return date;
    }

    string MyFormateDate(stdate date, string format = "dd/mm/yyyy")
    {
        format = MyReplaceWordUsingBuiltInFunction(format, "dd", to_string(date.day));
        format = MyReplaceWordUsingBuiltInFunction(format, "mm", to_string(date.month));
        format = MyReplaceWordUsingBuiltInFunction(format, "yyyy", to_string(date.year));
        return format;
    }



}
using namespace mytimedate;
