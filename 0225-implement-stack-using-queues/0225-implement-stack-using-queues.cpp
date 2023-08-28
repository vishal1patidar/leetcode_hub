class MyStack {
private:
    std::queue<int> q;

public:
    void push(int x) {
        q.push(x);
    }

    int pop() {
        int count = q.size();
        for (int i = 0; i < count - 1; i++) {
            push(q.front());
            q.pop();
        }
        int topValue = q.front();
        q.pop();
        return topValue;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

