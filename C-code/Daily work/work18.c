//1.
int main()
{
	int x, y, z;
	x = 1;
	y = 1;
	z = x++, y++, ++y;
	printf("%d,%d,%d\n", x, y, z);
	//x=2  y=3  z=1 赋值运算符优先级高于逗号表达式，所以先算
	//(z=x++),y++,++y
}

//2.
int main()
{
	int i = 10;
	int j = 10, k = 3;
	k *= i + j;
	printf("%d\n", k);
	//  k=3  +优先级高于*=
}

//3.letcode27
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//csdn：https://blog.csdn.net/qq_42913794/article/details/104026252

//双指针法：一个指针用于寻找，跳过值为val的位置。一个指针用于放入非val的值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++)
        {
            if(nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

//remove和erase搭配用法：remove负责将所有非val的元素放到vector的首部，值为val的元素放到vector的尾部，返回新的end()值（相当于val部分的begin）。
                      //erase负责将尾部去除。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(),nums.end(),val),nums.end());
        return nums.size();
    }
};