class MinStack {
public:
    stack<int>data, tmp;
    void push(int x) {
        data.push(x);
        if(tmp.empty() || x <= tmp.top())
            tmp.push(x);
    }

    void pop() {
        if(data.top() == tmp.top()) tmp.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return tmp.top();
    }
};