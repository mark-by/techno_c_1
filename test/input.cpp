#include "gtest/gtest.h"
#include <stdio.h>
#include <errno.h>

extern "C" {
#include "input/input.h"
}

TEST(InputTest, CorrectInput) {
    FILE * input_file = fopen("../../test/test_input", "r");
    errno = 0;
    ASSERT_FLOAT_EQ(100, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    ASSERT_FLOAT_EQ(200, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    ASSERT_FLOAT_EQ(300, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    ASSERT_FLOAT_EQ(45.5, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    fclose(input_file);
}

TEST(InputTest, IncorrectInput) {
    FILE * input_file = fopen("../../test/test_incorrect_input", "r");
    errno = 0;
    ASSERT_FLOAT_EQ(234234.4534534345, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    input_float(input_file, stderr);
    ASSERT_NE(0, errno);
    errno = 0;
    input_float(input_file, stderr);
    ASSERT_NE(0, errno);
    errno = 0;
    ASSERT_FLOAT_EQ(45.5, input_float(input_file, stderr));
    ASSERT_EQ(0, errno);
    fclose(input_file);
}
