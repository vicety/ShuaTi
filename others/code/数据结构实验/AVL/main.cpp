#include<bits/stdc++.h>
#include<avlerror.h>
#include<time.h>
using namespace std;
#define INF 2147483647
class Node{
public:
    int val;
    int height, freq;
    Node *ls, *rs;
    Node(int _val){
        val = _val;
        height = 0, freq = 1, ls = nullptr, rs = nullptr;
    }
};

class AVL{
public:
    AVL(){
        rt = nullptr;
    }

    ~AVL(){
        clear();
    }

    //O(log(n))
    void insert(int val){
        _insert(rt, val);
    }

    //O(log(n))
    tuple<bool, int> find(int val){
        Node* target = _find(rt, val);
        if(!target) return make_tuple(false, -1);
        return make_tuple(target, target->freq);
    }

    //O(log(n))
    void erase(int val, bool clearAll = false){
        _erase(rt, val, clearAll);
    }

    //O(n)
    void clear(){
        if(!rt) return;
        _clear(rt);
    }

    //O(n)
    void print(){
        _print(rt);
    }

    private:
    int nodeHeight(Node *node) const{
        return node == nullptr ? -1:node->height;
    }

    void updateHeight(Node *&node){
        node->height = max(nodeHeight(node->ls), nodeHeight(node->rs)) + 1;
    }

    bool unBalancedRight(Node *& node) const{
        return nodeHeight(node->rs) - nodeHeight(node->ls) == 2;
    }

    bool unBalancedLeft(Node *& node) const{
        return nodeHeight(node->ls) - nodeHeight(node->rs) == 2;
    }

    void leftBalance(Node *&node){
        if(nodeHeight(node->ls->ls) - nodeHeight(node->ls->rs) == 1){
            rotateWithLeft(node);
        }
        else doubleRotateWithLeft(node);
    }

    void rightBalance(Node *&node){
        if(nodeHeight(node->rs->rs) - nodeHeight(node->rs->ls) == 1){
            rotateWithRight(node);
        }
        else doubleRotateWithRight(node);
    }

    void rotateWithLeft(Node *&node){
        Node* ls = node->ls;
        node->ls = ls->rs;
        ls->rs = node;
        updateHeight(node);
        updateHeight(ls);
        node = ls;  //改变父亲指向
    }

    void rotateWithRight(Node *&node){
        Node *rs = node->rs;
        node->rs = rs->ls;
        rs->ls = node;
        updateHeight(node);
        updateHeight(rs);
        node = rs;
    }

    void doubleRotateWithLeft(Node *&node){
        rotateWithRight(node->ls);
        rotateWithLeft(node);
    }

    void doubleRotateWithRight(Node *&node){
        rotateWithLeft(node->rs);
        rotateWithRight(node);
    }

    void _insert(Node *&node, int val){
        if(!node) node = new Node(val);
        else if(val < node->val){
            _insert(node->ls, val);
            if(unBalancedLeft(node)){
                leftBalance(node);
            }
        }
        else if(val > node->val){
            _insert(node->rs, val);
            if(unBalancedRight(node)){
                rightBalance(node);
            }
        }
        else node->freq++;
        updateHeight(node);
    }

    Node* _find(Node* node, int val){
        if(!node) return nullptr;
        else if(val < node->val) return _find(node->ls, val);
        else if(val > node->val) return _find(node->rs, val);
        else return node;
    }

    void _erase(Node *&node, int val, bool clearAll){
        if(!rt) throw DeleteInexistentValue(val);
        if(val < node->val){
            _erase(node->ls, val, clearAll);
            if(unBalancedRight(node)) rightBalance(node);
        }
        else if(val > node->val){
            _erase(node->rs, val, clearAll);
            if(unBalancedLeft(node)) leftBalance(node);
        }
        else{
            if(node->freq > 1 && (!clearAll)){
                node->freq--;
                return;
            }
            if(!node->ls){
                Node* toDelete = node;
                node = node->rs;
                delete toDelete;
            }
            else if(!node->rs){
                Node* toDelete = node;
                node = node->ls;
                delete toDelete;
            }
            else{
                Node* tmp = node->rs; // 选择用右子树中的最小值替代此点中的值
                while(tmp->ls) tmp = tmp->ls;
                node->val = tmp->val;
                node->freq = tmp->freq;
                _erase(node->rs, tmp->val, clearAll); // 从该节点的右子树找到这个被复制的点
            }
        }
    }

    void _clear(Node *& node){
        if(node->ls) _clear(node->ls);
        if(node->rs) _clear(node->rs);
        delete node;
    }

    void _print(Node *&root){
        if(!root) return;
        _print(root->ls);
        printf("(%d, %d) ", root->val, root->freq);
        _print(root->rs);
    }

    Node* rt;
};

int main(){
    srand(time(nullptr));
    time_t start = clock();
    AVL tree;

//    try{
//        tree.erase(1);
//    }
//    catch(DeleteInexistentValue &err){
//        cerr<<"An exception caught: "<<err.what()<<endl;
//        exit(-1);
//    }


//    for(int i = 1; i < 10; i++) tree.insert(i);
//    tree.erase(4);
//    tuple<bool, int> result = tree.find(5);
//    if(get<0>(result)) cout<<to_string(get<1>(result))<<endl;

    //for(int i = 0;i < 20000000; i++) tree.insert(rand()%INF);
    for(int i = 0;i < 20000000; i++) tree.insert(i);

    start = clock();
    for(int i = 19999999;i>=0;i--) tree.erase(i);

    cout<<"time used "<<(double)(clock()-start)/CLOCKS_PER_SEC<<"s"<<endl;
    //tree.print();
    return 0;
}

