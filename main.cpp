#include <iostream>

using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
struct Person{
    string name;
    string sex;
    int age;
    string phone;
    string address;
};

//ͨѶ¼�ṹ��
struct Addressbooks{
    struct Person parr[MAX];
    int Size;
};
//�˵���ʾ
void ShowMenu(){
    cout<<"***** 1�������ϵ�� *****"<<endl;
    cout<<"***** 2����ʾ��ϵ�� *****"<<endl;
    cout<<"***** 3��ɾ����ϵ�� *****"<<endl;
    cout<<"***** 4��������ϵ�� *****"<<endl;
    cout<<"***** 5���޸���ϵ�� *****"<<endl;
    cout<<"***** 6�������ϵ�� *****"<<endl;
    cout<<"***** 0���˳�ͨѶ¼ *****"<<endl;
}

//�����ϵ�� �����ַͬ������
void addPerson(struct Addressbooks* ads){
    //���ж�ͨѶ¼�Ƿ�����
    if(ads->Size==MAX){
        cout<<"ͨѶ¼����"<<endl;
        return;
    }
    string name;
    cout<<"��������ӵ�������"<<endl;
    cin>>name;
    ads->parr[ads->Size].name=name;

    string sex;
    cout<<"�������Ա�"<<endl;
    cin>>sex;
    ads->parr[ads->Size].sex=sex;

    int age;
    cout<<"���������䣺"<<endl;
    cin>>age;
    ads->parr[ads->Size].age=age;

    string phone;
    cout<<"��������ϵ��ʽ��"<<endl;
    cin>>phone;
    ads->parr[ads->Size].phone=phone;

    string address;
    cout<<"�������ͥסַ��"<<endl;
    cin>>address;
    ads->parr[ads->Size].address=address;

    ads->Size++;
    cout<<"��ӳɹ���"<<endl;
    system("pause");
    //��������
    system("cls");

}

//��ʾ��ϵ��
void ShowPerson(const Addressbooks* ads){
    if(ads->Size==0)
        cout<<"ͨѶ¼Ϊ��"<<endl;
    for(int i=0;i<ads->Size;i++){
        cout<<"������"<<ads->parr[i].name<<"\t";
        cout<<"�Ա�"<<ads->parr[i].sex<<"\t";
        cout<<"���䣺"<<ads->parr[i].age<<"\t";
        cout<<"�绰��"<<ads->parr[i].phone<<"\t";
        cout<<"סַ��"<<ads->parr[i].address<<endl;
    }
    system("pause");
    //��������
    system("cls");
}

//ɾ����ϵ��
void DeletePerson(Addressbooks* ads){
    if(ads->Size==0){
        cout<<"ͨѶ¼Ϊ�գ�����ɾ��"<<endl;
    }else{
        string name;
        cout<<"������ɾ������ϵ�ˣ�"<<endl;
        cin>>name;
        int index=-1;
        for(int i=0;i<ads->Size;i++){
            if(ads->parr[i].name==name){
                index=i;
                for(int j=i;j<ads->Size-1;j++){
                    ads->parr[j]=ads->parr[j+1];
                }
                break;
            }
        }

        if(index!=-1){
            cout<<"ɾ���ɹ���"<<endl;
            ads->Size--;
        }else{
            cout<<"���޴���"<<endl;
        }
    }
    system("pause");
    //��������
    system("cls");
}

//������ϵ��
void SearchPerson(Addressbooks* ads){
    string name;
    cout<<"��������ҵ���ϵ�ˣ�"<<endl;
    cin>>name;
    int index=-1;
    for(int i=0;i<ads->Size;i++){
        if(ads->parr[i].name==name){
            index=i;
            cout<<"������"<<ads->parr[i].name<<"\t";
            cout<<"�Ա�"<<ads->parr[i].sex<<"\t";
            cout<<"���䣺"<<ads->parr[i].age<<"\t";
            cout<<"�绰��"<<ads->parr[i].phone<<"\t";
            cout<<"סַ��"<<ads->parr[i].address<<endl;
        }
    }
    if(index!=-1){
        cout<<"���ҳɹ�"<<endl;
    }else{
        cout<<"���޴���"<<endl;
    }
    system("pause");
    //��������
    system("cls");

}

//�޸���ϵ��
void ModifyPerson(Addressbooks* ads){
    cout<<"�������޸ĵ���ϵ�ˣ�"<<endl;
    string name;
    cin>>name;
    int index=-1;
    for(int i=0;i<ads->Size;i++){
        if(ads->parr[i].name==name){
            index=i;
            string name1;
            cout<<"������������"<<endl;
            cin>>name1;
            ads->parr[i].name=name1;

            string sex;
            cout<<"�������Ա�"<<endl;
            cin>>sex;
            ads->parr[i].sex=sex;

            int age;
            cout<<"���������䣺"<<endl;
            cin>>age;
            ads->parr[i].age=age;

            string phone;
            cout<<"��������ϵ��ʽ��"<<endl;
            cin>>phone;
            ads->parr[i].phone=phone;

            string address;
            cout<<"�������ͥסַ��"<<endl;
            cin>>address;
            ads->parr[i].address=address;
        }
    }
    if(index!=-1){
        cout<<"�޸ĳɹ�"<<endl;
    }else{
        cout<<"���޴���"<<endl;
    }
    system("pause");
    //��������
    system("cls");
}

//�����ϵ��
void ClearPerson(Addressbooks* ads){
    ads->Size=0;
    cout<<"ͨѶ¼�����"<<endl;
    system("pause");
    //��������
    system("cls");
}

int main()
{
    struct Addressbooks ads;
    //��ʼ��ͨѶ¼����
    ads.Size=0;


    int select=0;

    while(1){
        ShowMenu();
        cout<<"������ѡ�"<<endl;
        cin>>select;

        switch(select){
        case 1://�����ϵ��
            addPerson(&ads);
            break;
        case 2://��ʾ��ϵ��
            ShowPerson(&ads);
            break;
        case 3://ɾ����ϵ��
            DeletePerson(&ads);
            break;
        case 4://������ϵ��
            SearchPerson(&ads);
            break;
        case 5://�޸���ϵ��
            ModifyPerson(&ads);
            break;
        case 6://�����ϵ��
            ClearPerson(&ads);
            break;
        case 0:
            cout<<"��ӭ�´�ʹ��"<<endl;
            break;
        }
    }

    return 0;
}
