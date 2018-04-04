#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
char press;
int n;

class person 
{
public:
   int No; //编号
   string post;   //邮箱地址
   string addre;   //联系地址
   string Name; //姓名
   char Sex;  //性别
   string Tel;  //联系电话  
};

class manage 
{
public:
	void FName();//按姓名查找   
	void FNo();//按编号查找  
	void Add(); //添加信息      
	void Modify(); //修改信息  
	void Save(); //保存数据     
	void Look();//预览  
private:
	person per[100];//创建通讯录数组容量，person类的per[100]对象又作为manage类的成员
};


//输入功能
void manage::Add()
{
	cout<<"输入通讯录人数个数：（上限100）";
	cin>>n;
	for(int a=1;a<=n;a++)//利用for循环录入全部通讯录的资料
	{
		cout<<"请输入第"<<a<<"的通讯录资料："<<endl;
		per[a].No=a;
		cout<<"姓名：";
		cin>>per[a].Name;
		cout<<"性别：";
		cin>>per[a].Sex;
		cout<<"邮箱地址：";
		cin>>per[a].post;
		cout<<"联系电话：";
		cin>>per[a].Tel;
		cout<<"联系地址：";
		cin>>per[a].addre;
   	}
}

//查询功能（按姓名）
void manage::FName()
{
	do
	{
		string find_name;
			cout<<"请输入你要查询的姓名：";cin>>find_name;
		int i;
		int j;
		int k=1;
		for(i=0;i<=n;i++)//完全查找，即使有重名的也全都可以查询
		{	
			if(per[i].Name==find_name)
			{    
				cout<<"编号："<<per[i].No<<' '<<"姓名："<<per[i].Name<<' '<<"性 
别："<<per[i].Sex<<' '<<"邮箱地址："
					<<per[i].post<<' '<<"联系电话："<<per[i].Tel<<"联系地址 
："<<per[i].addre<<endl;k++;
			}
		}	             
		if(k==1)//判断该名字是否在通讯录里面
		{
			cout<<"无法找到该名字"<<endl;
			cout<<"是否重新查找姓名？（Y/N）"<<endl;cin>>press;
		}		else {break;}
	}
	while(press=='Y');
}



//查询功能（按编号）
void manage::FNo()
{
	do
	{
		int find_number;
		cout<<"请输入你要查询的编号：";cin>>find_number;
		int i;
		for(i=0;i<=n;i++)
			if(per[i].No==find_number)
			{
				cout<<"编号："<<per[i].No<<' '<<"姓名："<<per[i].Name<<' '<<"性 
别："<<per[i].Sex<<' '<<"邮箱地址："<<per[i].post<<' '<<"联系电话："<<per[i].Tel<<' '<<"联系地 
址："<<per[i].addre<<endl;
				return;//循环外面的语句不做了，用ruturn语句终止for循环
			}
			if(per[i].No!=find_number)
				cout<<"无法找到该编号"<<endl;
			cout<<"是否重新查找编号？（Y/N）"<<endl;cin>>press;
	}
	while(press=='Y');//输入Y时继续进行查询功能
}


//修改功能
void manage::Modify()
{
	do
	{
		int find_no;//begin:
	    int i;
	    cout<<"请输入要修改的通讯录的编号："<<endl;
	    cin>>find_no;
	    for(i=0;i<=n;i++)
			if(per[i].No==find_no)
			{
			  	cout<<"编号："<<per[i].No<<' '<<"姓名："<<per[i].Name<<' '<<"性 
别："<<per[i].Sex<<' '<<"邮箱地址："
					<<per[i].post<<' '<<"联系电话："<<per[i].Tel<<"联系地址 
："<<per[i].addre<<endl;
			
				{cout<<"请输入新的信息："<<endl;//修改通讯录资料
				  cout<<"姓名：";
				  cin>>per[i].Name;
				  cout<<"性别：";
				  cin>>per[i].Sex;
				  cout<<"邮箱地址：";
				  cin>>per[i].post;
				  cout<<"联系电话：";
				  cin>>per[i].Tel;
				  cout<<"联系地址：";
				  cin>>per[i].addre;}
				 return;//循环外面的语句不做了，用ruturn语句终止for循环
			}
			if(per[i].No!=find_no)
			{
			  cout<<"无法找到该名字"<<endl;
			  cout<<"请重新查找！"<<endl;			  
			  cout<<"是否继续查找？（Y/N）"<<endl;
			  cin>>press;
			}
	}
	while(press=='Y');//输入Y时继续进行查询功能  goto begin;//输入的名字没有找到时返回重新 
输入
}

//预览功能
void manage::Look() 
{    
	int i;
	for(i=1;i<=n;i++)//for循环将所有对象数组显示出来
    cout<<"编号："<<per[i].No<<' '<<"姓名："<<per[i].Name<<' '<<"性别："<<per[i].Sex<<' '<<"邮 
箱地址："
					<<per[i].post<<' '<<"联系电话："<<per[i].Tel<<"联系地址 
："<<per[i].addre<<endl;

}
//保存数据 
void  manage::Save()
{
	ofstream outfile("f1.dat",ios::app);//定义文件刘对象，打开磁盘文件"f1.dat"
	if(! outfile)                       //如果打开失败，outfile返回0值    
	{
		cerr<<"open error!"<<endl;
		exit(1);
	}
	outfile<<"编号："<<' '<<"姓名："<<' '<<"性别："<<' '<<"邮箱地址："<<' '<<"联系电 
话："<<' '<<"联系地址："<<endl;
	for(int i=1;i<=n;i++)
	{
		outfile<<per[i].No<<' '<<per[i].Name<<' '<<per[i].Sex<<' '<<per[i].post<<'  
'<<per[i].Tel<<per[i].addre<<endl; //向磁盘文件"f1.dat"输入数据
	}
	outfile.close();  //关闭磁盘文件"f1.dat"
} 
	



int main() 
{   manage m;
	int c;
	do  //do语句进行循环操作 
	{   
		cout<<endl<<endl;   
		cout<<"            *    ***^.^ 欢迎来到通讯录菜单 ^.^ ***   *"<<endl;
		cout<<"            *                                        *"<<endl;   
		cout<<"            *  1.新增通讯录      4.编号查询详细信息  *"<<endl;   
		cout<<"            *  2.修改通讯录      5.姓名查询详细信息  *"<<endl;    
		cout<<"            *  3.预览信息        6.保存数据          *"<<endl;  
		cout<<"            *               0.退出                   *"<<endl;          
		cout<<"            * * * * * * * * * * * * * * * * * * * * **"<<endl;            
          
		cout<<"请选择:";   
		cin>>c;   
		switch(c)//switch语句进行选择    
		{    
		case 1: m.Add(); 
			break;
		case 2:m.Modify();
            break;
		case 3: m.Look(); 
			break; 
        case 4: m.FNo(); 
			break;
		case 5: m.FName(); 
			break; 
		case 6: m.Save();
			break;   
		case 0:break;   
		default: break;
		}
	}
	while(c!=0);   
	int s;  
	cout<<"是否要保存您的所有操作(1.保存 0.不保存):"<<endl;  
	cin>>s;  
	if(s==1)   //退出之前还要保存
		m.Save();
    return 0; 
}
