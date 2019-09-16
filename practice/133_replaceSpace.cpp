//
// Created by zqn on 2019/9/16.
//


//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

//思路：从前向后记录‘ ’数目，从后向前替换‘ ’。 重点：从后向前替换的时候的技巧 例如：“we are lucky”
//
//0 1 2 3 4 5 6 7 8 9 10 11
//w e a r e l u c k y
//可以得知count=2;//空格的个数。 所以在替换的时候7~11的字母要向后移动count×2个位置，3~5字母要向后移动（count-1）×2个位置。 所以得到 ：
//
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//w e   a r e   l u c  k y
//w e   a r a r e u c  k l u c k y
//在替换的时候直接在空格处写入%20了
//
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
//w e   a r e   l u c  k y

class Solution {
public:
	void replaceSpace(char *str,int length) {
		int count = 0;
		for(int i = 0; i < length; i++){
			if(str[i] == ' '){
				count++;
			}
		}
		for(int i = length-1; i >= 0; i--){
			if(str[i] != ' '){
				str[i+2*count] = str[i];
			}
			else{
				count--;
				str[i+2*count] = '%';
				str[i+2*count+1] = '2';
				str[i+2*count+2] = '0';
			}
		}

	}
};