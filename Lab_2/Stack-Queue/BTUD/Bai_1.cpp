#if 0 // ! Thư viện Stack và Queue
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Định nghĩa 4 hướng di chuyển: Trái, Phải, Lên, Xuống
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int m, n;
vector<vector<int>> maze;

// Hàm kiểm tra một ô có hợp lệ không
bool isValid(int x, int y, const vector<vector<bool>>& visited) {
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// BFS (dùng Queue)
bool bfsPathExists(int x1, int y1, int x2, int y2) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == x2 && y == y2) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

// DFS (dùng Stack)
bool dfsPathExists(int x1, int y1, int x2, int y2) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    stack<pair<int, int>> s;
    s.push({x1, y1});
    visited[x1][y1] = true;
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        if (x == x2 && y == y2) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
    return false;
}

// Hàm in mê cung
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

// Hàm main
int main() {
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;
    maze.resize(m, vector<int>(n));
    cout << "Nhap ma tran (0: khong di duoc, 1: co the di):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    cout << "Ma tran vua nhap:\n";
    printMaze(maze);
    int x1, y1, x2, y2;
    cout << "Nhap toa do bat dau (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Nhap toa do dich (x2 y2): ";
    cin >> x2 >> y2;
    if (maze[x1][y1] == 0 || maze[x2][y2] == 0) {
        cout << "Khong the di tu vi tri bat dau hoac dich do la tuong.\n";
        return 0;
    }
    cout << "Kiem tra bang BFS (Queue): ";
    if (bfsPathExists(x1, y1, x2, y2)) 
        cout << "CO duong di.\n";
    else cout << "KHONG co duong di.\n";
    cout << "Kiem tra bang DFS (Stack): ";
    if (dfsPathExists(x1, y1, x2, y2)) 
        cout << "CO duong di.\n";
    else cout << "KHONG co duong di.\n";
    return 0;
}
#endif

#if 1 // ! Tự viết Stack và Queue
#include <iostream>
#include <vector>
using namespace std;

// Định nghĩa 4 hướng di chuyển: Trái, Phải, Lên, Xuống
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int m, n;
vector<vector<int>> maze;

// Class Node chung cho cả Stack và Queue
template<typename T>
class Node {
public:
    T x, y;
    Node* next;
    Node(T x, T y) : x(x), y(y), next(nullptr) {}
};

// Class Queue tự triển khai
template<typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    bool empty() { return front == nullptr; }
    
    void push(T x, T y) {
        Node<T>* newNode = new Node<T>(x, y);
        if (rear) rear->next = newNode;
        else front = newNode;
        rear = newNode;
    }
    
    void pop() {
        if (front) {
            Node<T>* temp = front;
            front = front->next;
            if (!front) rear = nullptr;
            delete temp;
        }
    }
    
    Node<T>* peek() { return front; }
};

// Class Stack tự triển khai
template<typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}
    
    bool empty() { return top == nullptr; }
    
    void push(T x, T y) {
        Node<T>* newNode = new Node<T>(x, y);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (top) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    Node<T>* peek() { return top; }
};

// Hàm kiểm tra một ô có hợp lệ không
bool isValid(int x, int y, const vector<vector<bool>>& visited) {
    return (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

// BFS (dùng Queue)
bool bfsPathExists(int x1, int y1, int x2, int y2) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    Queue<int> q;
    q.push(x1, y1);
    visited[x1][y1] = true;
    while (!q.empty()) {
        Node<int>* current = q.peek();
        int x = current->x, y = current->y;
        q.pop();
        if (x == x2 && y == y2) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                q.push(nx, ny);
            }
        }
    }
    return false;
}

// DFS (dùng Stack)
bool dfsPathExists(int x1, int y1, int x2, int y2) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    Stack<int> s;
    s.push(x1, y1);
    visited[x1][y1] = true;
    while (!s.empty()) {
        Node<int>* current = s.peek();
        int x = current->x, y = current->y;
        s.pop();
        if (x == x2 && y == y2) return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                s.push(nx, ny);
            }
        }
    }
    return false;
}

// Hàm in mê cung
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

// Hàm main
int main() {
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;
    maze.resize(m, vector<int>(n));
    cout << "Nhap ma tran (0: khong di duoc, 1: co the di):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    cout << "Ma tran vua nhap:\n";
    printMaze(maze);
    int x1, y1, x2, y2;
    cout << "Nhap toa do bat dau (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Nhap toa do dich (x2 y2): ";
    cin >> x2 >> y2;
    if (maze[x1][y1] == 0 || maze[x2][y2] == 0) {
        cout << "Khong the di tu vi tri bat dau hoac dich do la tuong.\n";
        return 0;
    }
    cout << "Kiem tra bang BFS (Queue): ";
    if (bfsPathExists(x1, y1, x2, y2)) 
        cout << "CO duong di.\n";
    else cout << "KHONG co duong di.\n";
    cout << "Kiem tra bang DFS (Stack): ";
    if (dfsPathExists(x1, y1, x2, y2)) 
        cout << "CO duong di.\n";
    else cout << "KHONG co duong di.\n";
    return 0;
}
#endif