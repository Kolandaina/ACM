class sequence_List:
    def __init__(self):
        self.seqlist = []
        self.length = 0

    def bubblesort(self):  # 冒泡排序
        for i in range(self.length):
            for j in range(self.length - i - 1):
                if self.seqlist[j] > self.seqlist[j + 1]:
                    t = self.seqlist[j]
                    self.seqlist[j] = self.seqlist[j + 1]
                    self.seqlist[j + 1] = t

    def quicksort(self, low, high):  # 快排
        if low < high:
            pivot_index = self.partition(low, high)
            self.quicksort(low, pivot_index - 1)
            self.quicksort(pivot_index + 1, high)

    def partition(self, low, high):
        pivot = self.seqlist[high]
        i = low - 1
        for j in range(low, high):
            if self.seqlist[j] <= pivot:
                i += 1
                self.seqlist[i], self.seqlist[j] = self.seqlist[j], self.seqlist[i]
        self.seqlist[i + 1], self.seqlist[high] = (
            self.seqlist[high],
            self.seqlist[i + 1],
        )
        return i + 1

    def selectionsort(self):  # 选择排序
        for i in range(self.length - 1):
            min_index = i
            for j in range(i + 1, self.length):
                if self.seqlist[j] < self.seqlist[min_index]:
                    min_index = j
            if min_index != i:
                self.seqlist[i], self.seqlist[min_index] = (
                    self.seqlist[min_index],
                    self.seqlist[i],
                )

    def insertionsort(self):  # 插入排序
        for i in range(1, self.length):
            key = self.seqlist[i]
            j = i - 1
            while j >= 0 and self.seqlist[j] > key:
                self.seqlist[j + 1] = self.seqlist[j]
                j -= 1
            self.seqlist[j + 1] = key

    def shellsort(self):  # 希尔排序
        gap = self.length // 2
        while gap > 0:
            for i in range(gap, self.length):
                temp = self.seqlist[i]
                j = i
                while j >= gap and self.seqlist[j - gap] > temp:
                    self.seqlist[j] = self.seqlist[j - gap]
                    j -= gap
                self.seqlist[j] = temp
            gap //= 2

    def mergesort(self):  # 归并排序
        if self.length > 1:
            mid = self.length // 2
            left_half = self.seqlist[:mid]
            right_half = self.seqlist[mid:]

            left_list = sequence_List()
            left_list.seqlist = left_half
            left_list.length = len(left_half)

            right_list = sequence_List()
            right_list.seqlist = right_half
            right_list.length = len(right_half)

            left_list.mergesort()
            right_list.mergesort()

            i = j = k = 0

            while i < len(left_half) and j < len(right_half):
                if left_half[i] < right_half[j]:
                    self.seqlist[k] = left_half[i]
                    i += 1
                else:
                    self.seqlist[k] = right_half[j]
                    j += 1
                k += 1

            while i < len(left_half):
                self.seqlist[k] = left_half[i]
                i += 1
                k += 1

            while j < len(right_half):
                self.seqlist[k] = right_half[j]
                j += 1
                k += 1

    def radix_sort(self):  # 基数排序
        max_num = max(self.seqlist)
        place = 1
        while max_num >= 10**place:
            place += 1

        for i in range(place):
            buckets = [[] for _ in range(10)]
            for num in self.seqlist:
                radix = int(num / (10**i) % 10)
                buckets[radix].append(num)
            j = 0
            for k in range(10):
                for num in buckets[k]:
                    self.seqlist[j] = num
                    j += 1

    def heapify(self, n, i):  # 堆排序
        largest = i  # 将当前节点标记为最大值
        left = 2 * i + 1  # 左子节点的索引
        right = 2 * i + 2  # 右子节点的索引

        # 如果左子节点存在且大于根节点，则更新最大值的索引
        if left < n and self.seqlist[i] < self.seqlist[left]:
            largest = left
        # 如果右子节点存在且大于当前最大值，则更新最大值的索引
        if right < n and self.seqlist[largest] < self.seqlist[right]:
            largest = right
        # 如果最大值的索引发生变化，则交换根节点和最大值节点的值，并对交换后的子树进行堆化
        if largest != i:
            self.seqlist[i], self.seqlist[largest] = (
                self.seqlist[largest],
                self.seqlist[i],
            )
            self.heapify(n, largest)

    def heap_sort(self):
        n = self.length

        # 构建最大堆（从最后一个非叶节点开始）
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(n, i)

        # 逐步取出最大值，放到已排序部分的末尾
        for i in range(n - 1, 0, -1):
            self.seqlist[0], self.seqlist[i] = (
                self.seqlist[i],
                self.seqlist[0],
            )  # 将最大值移到已排序部分的末尾
            self.heapify(i, 0)  # 对剩余的未排序部分进行堆化

    def insert_item(self, item):
        self.seqlist.append(item)
        self.length += 1

    def creat_list(self):
        emenlt = int(input("请输入数的个数:"))
        for i in range(emenlt):
            a = int(input("请输入数:"))
            self.insert_item(a)

    def print_list(self):
        print("排序后的结果是:")
        for i in range(self.length):
            print(self.seqlist[i], end=" ")


if __name__ == "__main__":
    s = sequence_List()
    s.creat_list()
    s.radix_sort()
    s.print_list()
