//���߳���ռ���
#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hm;
//HANDLE hm2;
HANDLE h1; //�߳̾��
HANDLE h2;
int i = 0;
void ThreadUser_1(){ //�߳����
    cout<<"���߳�1��ʼ"<<"\n";
    while(i<=100)
    {
    	WaitForSingleObject(hm,INFINITE);
        cout<<"���߳�1��"<<i++<<"��ѭ����ռ��"<<"\n"; //�����Ϣ
        ReleaseMutex(hm);
        //Sleep(100); //��ռ��ʱ
    }
    cout<<"���߳̽���"<<"\n";
}

void ThreadUser_2(){ //�߳����
    cout<<"���߳�2��ʼ"<<"\n";
    while(i<=100)
    {
    	WaitForSingleObject(hm,INFINITE);
        cout<<"���߳�2��"<<i++<<"��ѭ����ռ��"<<"\n"; //�����Ϣ
        ReleaseMutex(hm);
        //Sleep(100); //��ռ��ʱ
    }
    cout<<"���߳̽���"<<"\n";
}

int main(){
    cout<<"���߳̿�ʼ"<<"\n";
    
    h1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadUser_1,NULL,1,0); //�������߳�1
    h2 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadUser_2,NULL,1,0); //�������߳�2
	CloseHandle(h1);
	CloseHandle(h2);
	hm = CreateMutex(NULL,FALSE,NULL);
	//hm2 = CreateMutex(NULL,FALSE,NULL);
    //ResumeThread(h1);  //�������߳�

    Sleep(1000); //�ȴ����߳�
    //SuspendThread(h);
    //delete h; //�������߳���Դ
    cout<<"���߳̽���"<<"\n";
    system("pause");
    return 0;
}
