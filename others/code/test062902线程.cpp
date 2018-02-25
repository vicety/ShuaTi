//多线程抢占输出
#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hm;
//HANDLE hm2;
HANDLE h1; //线程句柄
HANDLE h2;
int i = 0;
void ThreadUser_1(){ //线程入口
    cout<<"子线程1开始"<<"\n";
    while(i<=100)
    {
    	WaitForSingleObject(hm,INFINITE);
        cout<<"子线程1第"<<i++<<"次循环抢占；"<<"\n"; //输出信息
        ReleaseMutex(hm);
        //Sleep(100); //抢占延时
    }
    cout<<"子线程结束"<<"\n";
}

void ThreadUser_2(){ //线程入口
    cout<<"子线程2开始"<<"\n";
    while(i<=100)
    {
    	WaitForSingleObject(hm,INFINITE);
        cout<<"子线程2第"<<i++<<"次循环抢占；"<<"\n"; //输出信息
        ReleaseMutex(hm);
        //Sleep(100); //抢占延时
    }
    cout<<"子线程结束"<<"\n";
}

int main(){
    cout<<"主线程开始"<<"\n";
    
    h1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadUser_1,NULL,1,0); //创建子线程1
    h2 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadUser_2,NULL,1,0); //创建子线程2
	CloseHandle(h1);
	CloseHandle(h2);
	hm = CreateMutex(NULL,FALSE,NULL);
	//hm2 = CreateMutex(NULL,FALSE,NULL);
    //ResumeThread(h1);  //启动子线程

    Sleep(1000); //等待子线程
    //SuspendThread(h);
    //delete h; //回收子线程资源
    cout<<"主线程结束"<<"\n";
    system("pause");
    return 0;
}
