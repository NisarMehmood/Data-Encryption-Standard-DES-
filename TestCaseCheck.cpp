#include <limits.h>
#include <string>
#include "DES.h"
#include "gtest/gtest.h"
using namespace std;


/*============================
===========KEY TESTS==========
============================*/

TEST(KeyInitPermutationTest, TestOne) {
	
	// Test initial permutation
	const string key = "C2345678ABCEDFF9";
	const string permutedKey = "11110001111011011001101011000111010101100110111110001110";

	EXPECT_EQ(permutedKey, initKeyPermutation(key));
}

TEST(KeyCircularShiftTest, TestOne) {
	
	// Test circular shifting of key
	const string leftHalfKey = "1111000111101101100110101100";
	const string rightHalfKey = "0111010101100110111110001110";
	const string shiftedLeftHalf = "1110001111011011001101011001";
	const string shiftedRightHalf = "1110101011001101111100011100";
	
	EXPECT_EQ(shiftedLeftHalf, halfCircularShift(leftHalfKey, 1));
	EXPECT_EQ(shiftedRightHalf, halfCircularShift(rightHalfKey, 1));
}

TEST(KeySingleRoundPermutationTest, TestOne) {
	
	// Test round permutation of key
	const string key = "11100011110110110011010110011110101011001101111100011100";
	const string permutedKey = "000110111001011001110111111110100111100001110010";
	
	EXPECT_EQ(permutedKey, roundPermutation(key));
}


/*============================
==========TEXT TESTS==========
============================*/

TEST(TextInitPermutationTest, TestOne) {
	
	// Test initial permutation
	const string text = "C123456789CBCDEF";
	const string permutedText = "1110110100000000110011001111111111110001100010101111000010101010";

	EXPECT_EQ(permutedText, initTextPermutation(text));
}

TEST(TextExpansionTableTest, TestOne) {
	
	// Test expansion table
	const string rightHalfText = "11110001100010101111000010101010";
	const string expandedRightHalf = "011110100011110001010101011110100001010101010101";
	
	EXPECT_EQ(expandedRightHalf, expandHalfText(rightHalfText));
}

TEST(TextXORTest, TestOne) {
	
	// Test text XOR key
	const string text    = "011110100011110001010101011110100001010101010101";
	const string key     = "000110111001011001110111111110100111100001110010";
	const string XORtext = "011000011010101000100010100000000110110100100111";
	
	EXPECT_EQ(XORtext, XOR(text, key));
}

TEST(TextSboxTest, TestOne) {
	
	// Test S Box calculation
	const string text = "011000011010101000100010100000000110110100100111";
	const string output = "01010000100001100100111101100111";
	
	EXPECT_EQ(output, calcSBox(text));
}
