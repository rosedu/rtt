# 1 "sample.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "sample.c"
# 1 "sample.h" 1



int test_fun(int num);
int test_max(int num);
# 2 "sample.c" 2




int main(void)
{
 test_fun(25);
 test_max(((5) > (10) ? (5) : (10)));

 return 0;
}
