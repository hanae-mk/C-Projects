
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, SpecialCharacter = 4, Mix = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == Mix)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
		default:
			return char(RandomNumber(65, 90));
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;

	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;

	}

	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;

	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;

	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void ShuffleArray(int Arr[100], int ArrayLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrayLength) - 1], Arr[RandomNumber(1, ArrayLength) - 1]);
		}

	}

	static void ShuffleArray(string Arr[100], int ArrayLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrayLength) - 1], Arr[RandomNumber(1, ArrayLength) - 1]);
		}

	}

	static void FillArrayWithRandomNumbers(int Arr[100], int ArrayLength, int From, int To)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}

	}

	static void FillArrayWithRandomWords(string Arr[100], int ArrayLength, enCharType CharType, short WordLength)
	{

		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = GenerateWord(CharType, WordLength);
		}

	}

	static void FillArrayWithRandomKeys(string Arr[100], int ArrayLength, enCharType CharType)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = GenerateKey(CharType);
		}

	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i <= NumberOfTabs; i++)
		{
			t += "\t";
		}

		return t;
	}

	static string EncryptText(string Text, short EncryptionKey = 2) //hanae jcpcg
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2) //f*l*c
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] - EncryptionKey);
		}

		return Text;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { " ", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
							"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen",
							 "Eighteen","Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { " ", " ","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty",
							 "Ninety" };


			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundered " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return  NumberToText(Number / 100) + "Hundereds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return  NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return  NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}

		else
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}




	}

};

