#include <gtest/gtest.h>
extern "C" int abs_asm(int x);
extern "C" int sum_asm(int x);
extern "C" void *memcpy_asm(void *dest, const void *src, int n);
extern "C" void quick_sort(int arr[], int low, int high);

TEST(AbsTest, HandlesAbs) {
    EXPECT_EQ(abs_asm(5), 5);
    EXPECT_EQ(abs_asm(0), 0);
    EXPECT_EQ(abs_asm(-5), 5);
}

TEST(SumTest, HandleSum){
    EXPECT_EQ(sum_asm(1),1);
    EXPECT_EQ(sum_asm(2),3);
    EXPECT_EQ(sum_asm(4),10);
}

TEST(MemCpyTest, HandleMemCpy){
    int dest[] = {1, 2, 3, 4, 5};
    int src[] = {4,5,6};
    memcpy_asm(dest,src,3* sizeof(int));
    EXPECT_EQ(dest[0],4);
    EXPECT_EQ(dest[1],5);
    EXPECT_EQ(dest[2],6);
}

TEST(QuickSortTest, HandleQuickSort){
    int arr[] = {10, 7, 8, 9, 1, 5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],5);
    EXPECT_EQ(arr[2],6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}