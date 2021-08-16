#include <iostream>

using namespace std;
#define MAX 1000

//联系人结构体
struct Person{
    string name;
    string sex;
    int age;
    string phone;
    string address;
};

//通讯录结构体
struct Addressbooks{
    struct Person parr[MAX];
    int Size;
};
//菜单显示
void ShowMenu(){
    cout<<"***** 1、添加联系人 *****"<<endl;
    cout<<"***** 2、显示联系人 *****"<<endl;
    cout<<"***** 3、删除联系人 *****"<<endl;
    cout<<"***** 4、查找联系人 *****"<<endl;
    cout<<"***** 5、修改联系人 *****"<<endl;
    cout<<"***** 6、清空联系人 *****"<<endl;
    cout<<"***** 0、退出通讯录 *****"<<endl;
}

//添加联系人 传入地址同步更新
void addPerson(struct Addressbooks* ads){
    //先判断通讯录是否满了
    if(ads->Size==MAX){
        cout<<"通讯录已满"<<endl;
        return;
    }
    string name;
    cout<<"请输入添加的姓名："<<endl;
    cin>>name;
    ads->parr[ads->Size].name=name;

    string sex;
    cout<<"请输入性别："<<endl;
    cin>>sex;
    ads->parr[ads->Size].sex=sex;

    int age;
    cout<<"请输入年龄："<<endl;
    cin>>age;
    ads->parr[ads->Size].age=age;

    string phone;
    cout<<"请输入联系方式："<<endl;
    cin>>phone;
    ads->parr[ads->Size].phone=phone;

    string address;
    cout<<"请输入家庭住址："<<endl;
    cin>>address;
    ads->parr[ads->Size].address=address;

    ads->Size++;
    cout<<"添加成功！"<<endl;
    system("pause");
    //清屏操作
    system("cls");

}

//显示联系人
void ShowPerson(const Addressbooks* ads){
    if(ads->Size==0)
        cout<<"通讯录为空"<<endl;
    for(int i=0;i<ads->Size;i++){
        cout<<"姓名："<<ads->parr[i].name<<"\t";
        cout<<"性别："<<ads->parr[i].sex<<"\t";
        cout<<"年龄："<<ads->parr[i].age<<"\t";
        cout<<"电话："<<ads->parr[i].phone<<"\t";
        cout<<"住址："<<ads->parr[i].address<<endl;
    }
    system("pause");
    //清屏操作
    system("cls");
}

//删除联系人
void DeletePerson(Addressbooks* ads){
    if(ads->Size==0){
        cout<<"通讯录为空，不能删除"<<endl;
    }else{
        string name;
        cout<<"请输入删除的联系人："<<endl;
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
            cout<<"删除成功！"<<endl;
            ads->Size--;
        }else{
            cout<<"查无此人"<<endl;
        }
    }
    system("pause");
    //清屏操作
    system("cls");
}

//查找联系人
void SearchPerson(Addressbooks* ads){
    string name;
    cout<<"请输入查找的联系人："<<endl;
    cin>>name;
    int index=-1;
    for(int i=0;i<ads->Size;i++){
        if(ads->parr[i].name==name){
            index=i;
            cout<<"姓名："<<ads->parr[i].name<<"\t";
            cout<<"性别："<<ads->parr[i].sex<<"\t";
            cout<<"年龄："<<ads->parr[i].age<<"\t";
            cout<<"电话："<<ads->parr[i].phone<<"\t";
            cout<<"住址："<<ads->parr[i].address<<endl;
        }
    }
    if(index!=-1){
        cout<<"查找成功"<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
    system("pause");
    //清屏操作
    system("cls");

}

//修改联系人
void ModifyPerson(Addressbooks* ads){
    cout<<"请输入修改的联系人："<<endl;
    string name;
    cin>>name;
    int index=-1;
    for(int i=0;i<ads->Size;i++){
        if(ads->parr[i].name==name){
            index=i;
            string name1;
            cout<<"请输入姓名："<<endl;
            cin>>name1;
            ads->parr[i].name=name1;

            string sex;
            cout<<"请输入性别："<<endl;
            cin>>sex;
            ads->parr[i].sex=sex;

            int age;
            cout<<"请输入年龄："<<endl;
            cin>>age;
            ads->parr[i].age=age;

            string phone;
            cout<<"请输入联系方式："<<endl;
            cin>>phone;
            ads->parr[i].phone=phone;

            string address;
            cout<<"请输入家庭住址："<<endl;
            cin>>address;
            ads->parr[i].address=address;
        }
    }
    if(index!=-1){
        cout<<"修改成功"<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
    system("pause");
    //清屏操作
    system("cls");
}

//清空联系人
void ClearPerson(Addressbooks* ads){
    ads->Size=0;
    cout<<"通讯录已清空"<<endl;
    system("pause");
    //清屏操作
    system("cls");
}

int main()
{
    struct Addressbooks ads;
    //初始化通讯录人数
    ads.Size=0;


    int select=0;

    while(1){
        ShowMenu();
        cout<<"请输入选项："<<endl;
        cin>>select;

        switch(select){
        case 1://添加联系人
            addPerson(&ads);
            break;
        case 2://显示联系人
            ShowPerson(&ads);
            break;
        case 3://删除联系人
            DeletePerson(&ads);
            break;
        case 4://查找联系人
            SearchPerson(&ads);
            break;
        case 5://修改联系人
            ModifyPerson(&ads);
            break;
        case 6://清空联系人
            ClearPerson(&ads);
            break;
        case 0:
            cout<<"欢迎下次使用"<<endl;
            break;
        }
    }

    return 0;
}
