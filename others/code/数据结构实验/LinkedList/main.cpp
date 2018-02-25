#include <iostream>
#include <linkedlist.h>
#include<linkedlisterror.h>
#include<time.h>
#include<windows.h>
using namespace std;

void printList(LinkedList<int>& list){
    cout<<"current list length: "<<list.length()<<endl;
    cout<<"list content: "<<endl;
    list.print();
    cout<<endl;
}

int main()
{
    time_t start, end;
    start = clock();

    // 用数组初始化listA
    int arrA[4] = {0, 10, 30, 50};
    LinkedList<int> listA(arrA, 4);
    double arrADouble[4] = {0, 10, 30, 50};
    LinkedList<double> listADouble(arrADouble, 4);
    printList(listA);

    LinkedList<int> listB;
    listB.insertRear(20);
    listB.insertRear(25);
    listB.insertRear(30);
    listB.insertRear(40);
    listB.insertRear(60);
    listB.insertFront(5);
    // 在第5个元素后加入80
    listB.insertByPos(80, 5);
    printList(listB);

    // 合并listA与listB 除重
    listA.merge(listB);
    printList(listA);

    // 翻转listA
    cout<<"list reverse"<<endl;
    listA.reverse();
    printList(listA);

    // 用数组初始化listC
    int ar[5] = {8, 2, 5, 3, 11};
    LinkedList<int> listC(ar, 5);
    printList(listC);

    // 用listC初始化数组arr
    cout<<"print array"<<endl;
    int arr[listC.length()];
    listC.toArray(arr);
    for(int i = 0; i < listC.length(); i++) cout<<arr[i]<<" "; // 怎么用 list.toArray 返回一个不用手动析构的arr
    cout<<endl<<endl;

    // 对listC排序
    cout<<"print listC after sorting"<<endl;
    listC.sort(0, listC.length()-1);
    printList(listC);

    // 用listC初始化listD
    cout<<"print listD"<<endl;
    LinkedList<int> listD(listC);
    printList(listD);

    // 删除操作
    listD.deleteByPos(2);
    printList(listD);

    // 清空列表 异常
//    listD.clear();
//    try{
//        listD.getVal(1);
//    }
//    catch(IndexOutOfRange& err){
//        cerr<<"An exception caught: "<<err.what();
//        exit(-1);
//    }

    LinkedList<int> listE;
    for(int i = 0;i < 20000000; i++) listE.insertFront(-i);
    cout<<"time used "<<(clock()-start)*1000/CLOCKS_PER_SEC<<endl;
    start = clock();
    listE.sort(0, listE.length()-1);
    cout<<"time used "<<(clock()-start)*1000/CLOCKS_PER_SEC<<endl;
    start = clock();
    listE.reverse();
    cout<<"time used "<<(clock()-start)*1000/CLOCKS_PER_SEC<<endl;

    return 0;
}
