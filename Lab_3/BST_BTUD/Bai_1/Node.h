#ifndef NODE_H
#define NODE_H
class Node {
public:
    Node();
    Node(char);
    virtual ~Node();
    Node *Getleft() { return left; }
    void Setleft(Node *val) { left = val; }
    Node *Getright() { return right; }
    void Setright(Node *val) { right = val; }
    char Getkey() { return key; }
    void Setkey(char val) { key = val; }
    int Getquantity() { return quantity; }
    void Setquantity(int val) { quantity = val; }
    void IncrementQuantity() { quantity++; }

protected:
private:
    Node *left;
    Node *right;
    char key;
    int quantity;
};
#endif // NODE_H