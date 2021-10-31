# 希尔排序
1.首批将时间复杂度降到 O(n2)O(n^2)O(n2) 以下的算法之一。虽然原始的希尔排序最坏时间复杂度仍然是 O(n2)O(n^2)O(n2) ，但经过优化
的希尔排序可以达到 O(n1.3)O(n^{1.3})O(n1.3) 甚至 O(n7/6)O(n^{7/6})O(n7/6)。

2.将待排序数组按照一定的间隔分为多个子数组，每组分别进行插入排序。这里按照间隔分组指的不是取连续的一段数组，而是每跳跃一定间隔取一个值组成一组
逐渐缩小间隔进行下一轮排序最后一轮时，取间隔为 111，也就相当于直接使用插入排序。但这时经过前面的「宏观调控」，数组已经基本有序了，所以此时的插入排序只需进行少量交换便可完成。

3.事实上，希尔排序的增量序列如何选择是一个数学界的难题，但它也是希尔排序算法的核心优化点。若增量元素不互质，则小增量可能根本不起作用。
数学界有不少的大牛做过这方面的研究。比较著名的有 Hibbard 增量序列、Knuth 增量序列、Sedgewick 增量序列。这道题用knuth序列。