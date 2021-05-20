#include "unity.h"

void test_TheFirst(void)
{
  TEST_ASSERT_EQUAL(1, 1);
}

void test_should_ApplyValidMask(void) 
{
  char *prefix      = "122.1.1.1";
  //char *str_prefix  = "122.1.1.0";
  char empty_prefix[16]  = "\0";
  char *str_prefix = empty_prefix;
  unsigned int mask = 24;
  
  apply_mask(prefix, mask, str_prefix);

  TEST_ASSERT_EQUAL_STRING(prefix, str_prefix);
}

int main(void) 
{
  UNITY_BEGIN();
  
  RUN_TEST(test_TheFirst);
  RUN_TEST(test_should_ApplyValidMask);
  
  return UNITY_END();
}