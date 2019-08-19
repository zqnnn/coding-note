# coding-note
# 刷题记录本


## 分解让复杂问题简单
### 1.字符串的排列
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。


## 时间效率
### 2.数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

### 3.最小的K个数
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

### 4.连续子数组的最大和
输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。例如输入的数组为{1,-2,3,10,-4,7,2,-5}，和最大的子数组为{3,10,-4,7,2}，因此输出为该子数组的和18。

### 5.求从 1 到 n 的整数中 1 出现的次数
题目：输入一个整数 n 求从 1 到 n 这 n 个整数的十进制表示中 1 出现的次数。
举例说明：例如输入 12 ，从 1 到 12 这些整数中包含 1 的数字有 1、10、11 和 12，1 一共出现了 5 次。

### 6.把数组排成最小的数
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

### 7.第n个丑数
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

### 8.第一个只出现一次的字符
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置.

### 9.逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007


### 10.链表公共节点
输入两个链表，找出它们的第一个公共结点。

### 11. 数字在排序数组中出现的次数
统计一个数字在排序数组中出现的次数。

### 12.求二叉树深度


### 13.平衡二叉树
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

### 14.出现一次的数字
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。


### 15.两个数和是S
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

### 16.所有和为S的连续正数序列
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

### 17.	左旋转字符串
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

### 18. 翻转单词顺序列
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

### 19.扑克牌顺子
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

### 20.孩子们的游戏(圆圈中最后剩下的数)
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

### 21. 求1+2+3+...+n
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。


### 22.两数之和
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

### 23.找出两个排序数组的中位数并且总的运行时间复杂度为 O(log (m+n))
有两个大小为 m 和 n 的排序数组 nums1 和 nums2, 请找出两个排序数组的中位数并且总的运行时间复杂度为 O(log (m+n))

### 24.盛最多水的容器
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

### 25.所有和为0的三个元素

### 26.删除排序数组中的重复项
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

### 27.搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

### 28. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

### 29. 没有出现的最小的正整数
给定一个未排序的整数数组，找出其中没有出现的最小的正整数

### 30. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

### 31. 旋转图像
给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。

### 32. 螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

### 33. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个位置。

### 34. 整数区间合并——LeetCode未通过
给定一个列表，将有重叠部分的合并。例如[ [ 1 3 ] [ 2 6 ] ] 合并成 [ 1 6 ] 。

### 35. Add Two Numbers 两数相加
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

### 36. 最长不重复子串
给定一个字符串，找出不含有重复字符的最长子串的长度。

### 37. 最长回文子串

### 38. 颠倒整数

### 39. 验证回文

### 40. 字符串转为整数

### 41.正则表达式匹配(没看懂)

### 42.罗马数字转整数

### 43.不同路径

### 44.最长公共前缀

### 45. 电话号码的字母组合

### 46. 括号组合

### 47.删除链表的倒数第N个节点

### 48.有效的括号

### 49.合并两个有序链表

### 50.合并 k 个排序链表

### 51.实现 strStr() 函数

### 52.两数相除,要求不使用乘法、除法和 mod 运算符。

### 53.有效的数独

### 54.报数

### 55.通配符匹配

### 56.全排列

### 57.字母异位词分组

### 58.计算 x 的 n 次幂函数

### 59.给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。

### 60.实现 int sqrt(int x) 函数。

### 61.给定两个数组，求数组的交集。输出结果中的元素不唯一，输出数组可以无序。

### 62.爬楼梯

### 63.矩阵置零 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

### 64.分类颜色

### 65.给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

### 66.最小覆盖子串
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

### 67.单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

### 68.删除重复出现的元素，使得每个元素最多出现两次

### 69.求直方图中最大的矩形

### 70.搜索旋转排序数组 II

### 71.合并两个有序数组

### 72.解码方法

### 73.二叉树的中序遍历

### 74.是否是二叉搜索树

### 75.是否是对称二叉树

### 76.二叉树的层次遍历

### 77.二叉树的锯齿形层次遍历

### 78.二叉树的最大深度

### 79.从前序与中序遍历序列构造二叉树

### 80.将有序数组转换为二叉搜索树

### 81.填充同一层的兄弟节点

### 82.杨辉三角

### 83.买卖股票的最佳时机

### 84.买卖股票的最佳时机二

### 85.二叉树中的最大路径和

### 86.单词接龙

### 87.给定一个未排序的整数数组，找出最长连续序列的长度

### 88.被围绕的区域

### 89.分割回文串

### 90.加油站问题

### 91.找出只出现了一次的元素

### 92.拷贝带有随机指针的链表

### 93.单词拆分
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

### 94.单词拆分2
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

### 95.判断一个单链表是否有环

### 96.LRU 缓存器

### 97.sortList链表排序（归并排序）

### 98.找落在同一条直线上最多的点的个数

### 99.计算逆波兰表达式

### 100.求最大子数组乘积

### 101.最小栈

### 102.求两个链表的交点

### 103.求数组的一个峰值

### 104.分数转循环小数

### 105.求大多数

### 106.求Excel表列序号

### 107.求一个数的阶乘末尾0的个数

### 108.最大组合数

### 109.旋转数组

### 110.翻转二进制数

### 111. Bits 位1的个数

### 112.打家劫舍 系列