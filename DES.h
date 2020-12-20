#include <string>
using namespace std;
//key tester functions

/*
These all functions are for the sake of GTESt all remaining function that you are going to use to implement the assignment must be made by yourself
otherwise all testcases will be faile.
Don't copy for internet i.e. geekforgeek, github and stackoverflow or by any other mean. And don't share with each other.



*/


string Permutate(int* array, int array_size, string key) {
    char* ReturnTo = new char[array_size + 1];

    for (int i = 0; i < array_size; i++) {
        ReturnTo[i] = key[array[i] - 1];
    }

    ReturnTo[array_size] = '\0';

    return ReturnTo;
}

string HexToBin(string key) {
    string result = "";

    for (int i = 0; i < key.length(); i++) {

        switch (key[i]) {
        case '0':
            result += "0000";
            break;
        case '1':
            result += "0001";
            break;
        case '2':
            result += "0010";
            break;
        case '3':
            result += "0011";
            break;
        case '4':
            result += "0100";
            break;
        case '5':
            result += "0101";
            break;
        case '6':
            result += "0110";
            break;
        case '7':
            result += "0111";
            break;
        case '8':
            result += "1000";
            break;
        case '9':
            result += "1001";
            break;
        case 'A': case 'a':
            result += "1010";
            break;
        case 'B': case 'b':
            result += "1011";
            break;
        case 'C': case 'c':
            result += "1100";
            break;
        case 'D': case 'd':
            result += "1101";
            break;
        case 'E': case 'e':
            result += "1110";
            break;
        case 'F': case 'f':
            result += "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                << key[i];
            break;
        }
    }
    return result;
}

string HexToBin2(string key) {
    string result = "";

    if ( key == "0" )
        result += "0000";
    if (key == "1")
        result += "0001";
    if (key == "2")
        result += "0010";
    if (key == "3")
        result += "0011";
    if (key == "4")
        result += "0100";
    if (key == "5")
        result += "0101";
    if (key == "6")
        result += "0110";
    if (key == "7")
        result += "0111";
    if (key == "8")
        result += "1000";
    if (key == "9")
        result += "1001";
    if (key == "10")
        result += "1010";
    if (key == "11")
        result += "1011";
    if (key == "12")
        result += "1100";
    if (key == "13")
        result += "1101";
    if (key == "14")
        result += "1110";
    if (key == "15")
        result += "1111";

    return result;
}

int binaryToDecimal1(string n)
{
    int result = 0;

    if (n == "00")
        result = 0;
    if (n == "01")
        result = 1;
    if (n == "10")
        result = 2;
    if (n == "11")
        result = 3;

    return result;

}
int binaryToDecimal2(string n)
{
    if (n == "0000")
        return 0;
    if (n == "0001")
        return 1;
    if (n == "0010")
        return 2;
    if (n == "0011")
        return 3;
    if (n == "0100")
       return 4;
    if (n == "0101")
        return 5;
    if (n == "0110")
        return 6;
    if (n == "0111")
        return 7;
    if (n == "1000")
        return 8;
    if (n == "1001")
        return 9;
    if (n == "1010")
        return 10;
    if (n == "1011")
        return 11;
    if (n == "1100")
        return 12;
    if (n == "1101")
        return 13;
    if (n == "1110")
        return 14;
    if (n == "1111")
        return 15;

}

//-------------- Test Functions-----------------------//

string initKeyPermutation(string key) { //one time function call

    int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
    
    return Permutate(PC1, 56, HexToBin(key));
}


string halfCircularShift(string half_key, int index) { //shift 

	return  half_key.substr(index, half_key.length()) + half_key.substr(0, index);

}

string roundPermutation(string key) {  //56 to 48 bit conversion

    int PC2[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

    return Permutate(PC2, 48, key); 

}
// Text

string initTextPermutation(string text) {

    int INITIAL_PERMUTATION_TABLE[] = { 58, 50, 42, 34, 26, 18, 10 , 2,
        60, 52, 44, 36, 28, 20, 12 , 4,
        62, 54, 46, 38, 30, 22, 14 , 6,
        64, 56, 48, 40, 32, 24, 16 , 8,
        57, 49, 41, 33, 25, 17, 9 , 1,
        59, 51, 43, 35, 27, 19, 11 , 3,
        61, 53, 45, 37, 29, 21, 13 , 5,
        63, 55, 47, 39, 31, 23, 15 , 7 };


    return Permutate(INITIAL_PERMUTATION_TABLE, 64, HexToBin(text));

}

string expandHalfText(string rightHalfText) {

    int EXPANSION_TABLE[] = { 32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };
 
    return Permutate(EXPANSION_TABLE, 48, rightHalfText);
}

string XOR(string text, string key) {

	string ReturnTo = "";

	for (int i = 0; i < text.length(); i++) {
		if (text[i] == key[i])
			ReturnTo += "0";
		else
			ReturnTo += "1";
	} 

	return ReturnTo;
}

string calcSBox(string text) {

    int Arr[8][6];
    int a = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 6; j++) {
            Arr[i][j] = text[a++] - '0';
        }
    // Box 1
    string N1_1 = "";
    N1_1 = to_string(Arr[0][0]) + to_string(Arr[0][5]);
    int row1 = binaryToDecimal1(N1_1);

    string N1_2 = "";
    N1_2 = to_string(Arr[0][1]) + to_string(Arr[0][2]) + to_string(Arr[0][3]) + to_string(Arr[0][4]);
    int column1 = binaryToDecimal2(N1_2);

    int Box1[4][16] =
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7} ,
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    };
    string B1 = HexToBin2(to_string(Box1[row1][column1]));

    // Box 2
    string N2_1 = "";
    N2_1 = to_string(Arr[1][0]) + to_string(Arr[1][5]);
    int row2 = binaryToDecimal1(N2_1);

    string N2_2 = "";
    N2_2 = to_string(Arr[1][1]) + to_string(Arr[1][2]) + to_string(Arr[1][3]) + to_string(Arr[1][4]);
    int column2 = binaryToDecimal2(N2_2);

    int Box2[4][16] =
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10} ,
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    };
    string B2 = HexToBin2(to_string(Box2[row2][column2]));
    // Box 3
    string N3_1 = "";
    N3_1 = to_string(Arr[2][0]) + to_string(Arr[2][5]);
    int row3 = binaryToDecimal1(N3_1);

    string N3_2 = "";
    N3_2 = to_string(Arr[2][1]) + to_string(Arr[2][2]) + to_string(Arr[2][3]) + to_string(Arr[2][4]);
    int column3 = binaryToDecimal2(N3_2);

    int Box3[4][16] =
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    };
    string B3 = HexToBin2(to_string(Box3[row3][column3]));
    // Box 4
    string N4_1 = "";
    N4_1 = to_string(Arr[3][0]) + to_string(Arr[3][5]);
    int row4 = binaryToDecimal1(N4_1);

    string N4_2 = "";
    N4_2 = to_string(Arr[3][1]) + to_string(Arr[3][2]) + to_string(Arr[3][3]) + to_string(Arr[3][4]);
    int column4 = binaryToDecimal2(N4_2);

    int Box4[4][16] =
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    };
    string B4 = HexToBin2(to_string(Box4[row4][column4]));
    // Box 5
    string N5_1 = "";
    N5_1 = to_string(Arr[4][0]) + to_string(Arr[4][5]);
    int row5 = binaryToDecimal1(N5_1);

    string N5_2 = "";
    N5_2 = to_string(Arr[4][1]) + to_string(Arr[4][2]) + to_string(Arr[4][3]) + to_string(Arr[4][4]);
    int column5 = binaryToDecimal2(N5_2);

    int Box5[4][16] =
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    };
    string B5 = HexToBin2(to_string(Box5[row5][column5]));
    // Box 6
    string N6_1 = "";
    N6_1 = to_string(Arr[5][0]) + to_string(Arr[5][5]);
    int row6 = binaryToDecimal1(N6_1);

    string N6_2 = "";
    N6_2 = to_string(Arr[5][1]) + to_string(Arr[5][2]) + to_string(Arr[5][3]) + to_string(Arr[5][4]);
    int column6 = binaryToDecimal2(N6_2);

    int Box6[4][16] =
    {
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11} ,
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    };
    string B6 = HexToBin2(to_string(Box6[row6][column6]));
    // Box 7
    string N7_1 = "";
    N7_1 = to_string(Arr[6][0]) + to_string(Arr[6][5]);
    int row7 = binaryToDecimal1(N7_1);

    string N7_2 = "";
    N7_2 = to_string(Arr[6][1]) + to_string(Arr[6][2]) + to_string(Arr[6][3]) + to_string(Arr[6][4]);
    int column7 = binaryToDecimal2(N7_2);

    int Box7[4][16] =
    {
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1} ,
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    };
    string B7 = HexToBin2(to_string(Box7[row7][column7]));
    // Box 8
    string N8_1 = "";
    N8_1 = to_string(Arr[7][0]) + to_string(Arr[7][5]);
    int row8 = binaryToDecimal1(N8_1);

    string N8_2 = "";
    N8_2 = to_string(Arr[7][1]) + to_string(Arr[7][2]) + to_string(Arr[7][3]) + to_string(Arr[7][4]);
    int column8 = binaryToDecimal2(N8_2);

    int Box8[4][16] =
    {
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7} ,
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    };
    string B8 = HexToBin2(to_string(Box8[row8][column8]));

    //
    return B1 + B2 + B3 + B4 + B5 + B6 + B7 + B8;

}
