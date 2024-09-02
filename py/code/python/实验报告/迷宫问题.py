class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        return self.stack.pop()

    def is_empty(self):
        return not bool(self.stack)
    

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        return self.queue.pop(0)

    def is_empty(self):
        return not bool(self.queue)

class fs:
    def __init__(self, maze):
        self.maze = maze
        self.pre_node = {(0, 0): None}
        self.visited = {(0, 0)}

    def dfs(self, x, y):
        if (x, y) == (len(self.maze)-1, len(self.maze[0])-1):
            path = [(len(self.maze)-1, len(self.maze[0])-1)]
            while self.pre_node[(x, y)]:
                path.append(self.pre_node[(x, y)])
                x, y = self.pre_node[(x, y)]
            return path[::-1]

        for next_x, next_y in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
            if 0 <= next_x < len(self.maze) and 0 <= next_y < len(self.maze) and \
                        self.maze[next_x][next_y] == 0 and (next_x, next_y) not in self.visited:
                self.visited.add((next_x, next_y))
                self.pre_node[(next_x, next_y)] = (x, y)
                if res := self.dfs(next_x, next_y):
                    return res
        return None
    
    def dfs_stack(self):
        stack = Stack()
        stack.push((0, 0))
        visited = {(0, 0)}
        pre_node = {(0, 0): None}

        while not stack.is_empty():
            cur = stack.pop()
            if cur == (len(self.maze)-1, len(self.maze[0])-1):
                path = []
                while cur:
                    path.append(cur)
                    cur = pre_node[cur]
                return path[::-1]

            for next in [(cur[0]+1, cur[1]), (cur[0]-1, cur[1]),(cur[0], cur[1]+1), (cur[0], cur[1]-1)]:
                if len(self.maze) > next[0] >= 0 == self.maze[next[0]][next[1]] and 0 <= next[1] < len(self.maze[0]) and next not in visited:
                    stack.push(next)
                    visited.add(next)
                    pre_node[next] = cur
        return None

    def bfs(self):
        queue = Queue()
        queue.enqueue((0, 0))
        self.visited = {(0, 0)}
        self.pre_node = {(0, 0): None}

        while not queue.is_empty():
            cur = queue.dequeue()
            if cur == (len(self.maze)-1, len(self.maze[0])-1):
                path = []
                while cur:
                    path.append(cur)
                    cur = self.pre_node[cur]
                return path[::-1]

            for next in [(cur[0]+1, cur[1]), (cur[0]-1, cur[1]),(cur[0], cur[1]+1), (cur[0], cur[1]-1)]:
                if 0 <= next[0] < len(self.maze) and 0 <= next[1] < len(self.maze[0]) and self.maze[next[0]][next[1]] == 0 and next not in self.visited:
                    queue.enqueue(next)
                    self.visited.add(next)
                    self.pre_node[next] = cur

        return None
    


if __name__ == "__main__":
    maze = [[0, 1, 1, 0, 0],
            [0, 1, 0, 1, 0],
            [0, 0, 0, 0, 0],
            [0, 1, 1, 1, 0],
            [0, 0, 0, 1, 0]]
    f = fs(maze)
    #print(f.bfs())
    #print(f.dfs_stack())
    print(f.dfs(0,0))
    
