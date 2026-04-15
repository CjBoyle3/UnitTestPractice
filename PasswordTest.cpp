/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

// Happy paths
TEST(PasswordTest, mixed_case_with_one_upper_one_lower)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("aB"));
}

TEST(PasswordTest, mixed_case_with_multiple_upper_and_lower)
{
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Hello"));
}

// Sad paths
TEST(PasswordTest, all_lowercase_returns_false)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("abc"));
}

TEST(PasswordTest, all_uppercase_returns_false)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("ABC"));
}

TEST(PasswordTest, empty_string_returns_false)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case(""));
}

TEST(PasswordTest, no_letters_only_digits_returns_false)
{
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("12345"));
}

TEST(PasswordTest, unique_characters_all_unique)
{
    Password my_password;
    ASSERT_EQ(4, my_password.unique_characters("abcd"));
}

TEST(PasswordTest, unique_characters_all_duplicates)
{
    Password my_password;
    ASSERT_EQ(1, my_password.unique_characters("aaaa"));
}

TEST(PasswordTest, unique_characters_mixed_duplicates)
{
    Password my_password;
    ASSERT_EQ(3, my_password.unique_characters("aabbcc"));
}

TEST(PasswordTest, unique_characters_single_character)
{
    Password my_password;
    ASSERT_EQ(1, my_password.unique_characters("a"));
}

TEST(PasswordTest, unique_characters_is_case_sensitive)
{
    Password my_password;
    ASSERT_EQ(2, my_password.unique_characters("aA"));
}

TEST(PasswordTest, unique_characters_empty_string_returns_zero)
{
    Password my_password;
    ASSERT_EQ(0, my_password.unique_characters(""));
}

TEST(PasswordTest, unique_characters_with_digits_and_symbols)
{
    Password my_password;
    ASSERT_EQ(3, my_password.unique_characters("1!2"));
}