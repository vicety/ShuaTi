#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<linkedlisterror.h>
using namespace std;

template<class T>
class Node{
public:
    Node(T content);
    Node();
    Node<T>* nxt;
    T val;
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(T arr[], int size);
    LinkedList(const LinkedList<T>& list);
    void insertFront(T content);
    void insertRear(T content);
    void insertByPos(T val, int pos);
    T deleteByPos(int pos);
    void print();
    bool isEmpty();
    int length();
    T getVal(int pos);
    void toArray(T arr[]);
    void sort(int l, int r);
    void merge(LinkedList<T> listB);
    void reverse();
    void clear();
    ~LinkedList();
private:
    int len;
    Node<T>* head;
    void initList();
    Node<T>* getPointer(int pos);
    void _sort(T arr[], int l, int r);
};

template<class T>
void LinkedList<T>::initList(){
    len = 0;
    head = new Node<T>();
}

template<class T>
Node<T>* LinkedList<T>::getPointer(int pos){
    if(pos > len || pos <= 0) throw IndexOutOfRange(len, pos); // throw
    Node<T>* cursor = head;
    while(pos--){
        cursor = cursor->nxt;
    }
    return cursor;
}

// 序号从1开始
template<class T>
T LinkedList<T>::getVal(int pos){
    return getPointer(pos)->val;
}

template<class T>
int LinkedList<T>::length(){
    return len;
}

template<class T>
void LinkedList<T>::print(){
    if(isEmpty()) return ;
    Node<T>* cursor = head->nxt;
    while(cursor){
       cout<<cursor->val<<" ";
       cursor = cursor->nxt;
    }
    cout<<endl;
}

template<class T>
Node<T>::Node(){
    nxt = nullptr;
}

template<class T>
LinkedList<T>::LinkedList()
{
    initList();
}

template<class T>
LinkedList<T>::LinkedList(T arr[], int size){
    initList();
    for(int i = size-1; i >= 0; i--) insertFront(arr[i]);
}

template<class T>
bool LinkedList<T>::isEmpty(){
    return len == 0;
}

template <class T>
void LinkedList<T>::insertFront(T content){
    Node<T>* newNode = new Node<T>(content);
    if(head->nxt) newNode->nxt = head->nxt;
    head->nxt = newNode;
    len++;
}

template<class T>
void LinkedList<T>::insertRear(T content){
    Node<T>* cursor = head;
    while(cursor->nxt) cursor = cursor->nxt;
    cursor->nxt = new Node<T>(content);
    len++;
}

// 在第pos个节点后方插入
template <class T>
void LinkedList<T>::insertByPos(T val, int pos){
    Node<T>* cursor = getPointer(pos);
    Node<T>* newNode =  new Node<T>(val); // 栈上的空间随时会归还,所以应该申请
    newNode->nxt = cursor->nxt;
    cursor->nxt = newNode;
    len++;
}

// 序号从1开始
template<class T>
T LinkedList<T>::deleteByPos(int pos){
    if(pos > len || pos <= 0 ) throw IndexOutOfRange(len, pos) ; // throw
    Node<T>* cursor = getPointer(pos - 1);
    Node<T>* toDelete = nullptr;
    toDelete = cursor->nxt;
    cursor->nxt = cursor->nxt->nxt;
    T toDeleteVal = toDelete->val;
    delete toDelete;
    len--;
    return toDeleteVal;
}

template<class T>
void LinkedList<T>::clear(){
    if(!len) return; // 为空直接返回
    Node<T>* cursor = head->nxt;
    Node<T>* toDelete = nullptr;
    while(cursor->nxt){
        toDelete = cursor;
        cursor = cursor->nxt;
        delete toDelete;
    }
    delete cursor;
    head->nxt = nullptr;
    len = 0;
}

template <class T>
Node<T>::Node(T content){
    val = content;
    nxt = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    initList();
    Node<T>* cursor = head;
    Node<T>* listcursor = list.head;
    while(listcursor->nxt){
        cursor->nxt = new Node<T>(listcursor->nxt->val);
        cursor = cursor->nxt;
        listcursor = listcursor->nxt;
        len++;
    }
}

template<class T>
void LinkedList<T>::toArray(T arr[]){
    if(isEmpty()) return ;
    // T* arr = new T[len];
    // auto_ptr<T> apt(arr);
    int cnt = 0;
    Node<T>* cursor = head;
    while(cursor->nxt){
        arr[cnt++] = cursor->nxt->val;
        cursor = cursor->nxt;
    }
}

template<class T>
void LinkedList<T>::_sort(T* a, int l, int r){
    int i,j,x;
    x=a[(l+r)>>1]; //基准
    i=l;
    j=r;
    do{
        while (a[i]<x) ++i;
        while (a[j]>x) --j; //跳过排序完毕的元素
        if (i<=j)
        {
            a[0]=a[i];
            a[i]=a[j];
            a[j]=a[0];
            ++i;
            --j; //交换
        }
    }while (i<=j);
    if (l<j) _sort(a, l, j);
    if (i<r) _sort(a, i,r); //排序左右子序列
}

template<class T>
void LinkedList<T>::sort(int l, int r){
    T* arr = new T[len], cnt = 0;
    toArray(arr);
    _sort(arr, l, r);
    Node<T>* cursor = head;
    while(cursor->nxt){
        cursor->nxt->val = arr[cnt++];
        cursor = cursor->nxt;
    }
    delete arr;
}



template<class T>
void LinkedList<T>::merge(LinkedList<T> listB){
    Node<T>* cursorA = head;
    Node<T>* cursorB = listB.head;
    while(cursorA->nxt || cursorB->nxt){
        if(!cursorB->nxt) break;
        if(!cursorA->nxt){
            while(cursorB->nxt){
                insertRear(cursorB->nxt->val);
                cursorB = cursorB->nxt;
            }
            break;
        }
        int aNext = cursorA->nxt->val, bNext = cursorB->nxt->val;
        if(aNext > bNext){
            Node<T>* newNode = new Node<T>(cursorB->nxt->val);
            newNode->nxt = cursorA->nxt;
            cursorA->nxt = newNode;
            cursorA = cursorA->nxt, cursorB = cursorB->nxt;
            len++;
        }
        if(aNext == bNext) cursorB = cursorB->nxt;
        if(aNext < bNext) cursorA = cursorA->nxt;
    }
}

template<class T>
void LinkedList<T>::reverse(){
    Node<T> *p, *q, *r;
    p = getPointer(1), q = getPointer(2), p->nxt = nullptr;
    while(q){
        r = q->nxt;
        q->nxt = p;
        p = q, q = r;
    }
    head->nxt = p;
}

template<class T>
LinkedList<T>::~LinkedList(){
    clear();
    delete head;
}


#endif // LINKEDLIST_H
