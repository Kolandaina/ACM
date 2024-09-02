class HashTable:
    def __init__(self):
        # 哈希表的初始大小已经被选择为 11。尽管这是任意的，但是重要的是，
        # 大小是质数，使得冲突解决算法可以尽可能高效。
        self.size = 11
        self.slots = [None] * self.size
        self.data = [None] * self.size

    # hash 函数实现简单的余数方法
    def hash(self, key, size):
        return key % size

    # 冲突解决技术是  加1  rehash 函数的线性探测
    def rehash(self, old_hash, size):
        return (old_hash + 1) % size

    # 假定最终将有一个空槽，除非 key 已经存在于  self.slots  中。 它计算原始
    # 哈希值，如果该槽不为空，则迭代 rehash 函数，直到出现空槽。如果非空槽已经包含 key，
    # 则旧数据值将替换为新数据值。
    def put(self, key, data):
        hash_value = self.hash(key, len(self.slots))

        if self.slots[hash_value] is None:
            self.slots[hash_value] = key
            self.data[hash_value] = data

        else:
            if self.slots[hash_value] == key:
                self.data[hash_value] = data
            else:
                next_slot = self.rehash(hash_value, len(self.slots))
                while self.slots[next_slot] is not None and \
                        self.slots[next_slot] != key:
                    next_slot = self.rehash(next_slot, len(self.slots))

                if self.slots[next_slot] is None:
                    self.slots[next_slot] = key
                    self.data[next_slot] = data
                else:
                    self.data[next_slot] = data

    # 从计算初始哈希值开始。如果值不在初始槽中，则 rehash 用
    # 于定位下一个可能的位置。
    def get(self, key):
        start_slot = self.hash(key, len(self.slots))

        data = None
        stop = False
        found = False
        pos = start_slot

        while self.slots[pos] is not None and not found and not stop:
            if self.slots[pos] == key:
                found = True
                data = self.data[pos]
            else:
                pos = self.rehash(pos, len(self.slots))
                if pos == start_slot:
                    stop = True
        return data

    # 我们重载  __getitem__  和 __setitem__  方法以允许使
    # 用  []  访问。 这意味着一旦创建了HashTable，索引操作符将可用。
    def __getitem__(self, item):
        return self.get(item)

    def __setitem__(self, key, value):
        self.put(key, value)

if __name__ == "__main__":
    H = HashTable()
    H[54] = "cat"
    H[26] = "dog"
    H[93] = "lion"
    H[17] = "tiger"
    H[77] = "bird"
    H[31] = "cow"
    H[44] = "goat"
    H[55] = "pig"
    H[20] = "chicken"
    print(H.slots)
    print(H.data)
    print(H[20])
    print(H[17])
    H[20] = "duck"
    print(H[20])
    print(H[99])
    print(H.slots)
    print(H.data)
