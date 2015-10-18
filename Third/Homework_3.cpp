#include <iostream> 
#include <string> 
using namespace std; 

class Worker{ 
protected: 
	string name; 
	int age; 
	string sex; 
	double pay_per_hour;
public: 
	virtual void Compute_pay(double hours){
		
	}

	friend ostream& operator<<(ostream& out, Worker& worker){ 
		return out<<"姓名为 "<<worker.name<<"\n年龄为 "<<worker.age<<
			"\n性别为 "<<worker.sex<<"\n时薪为 "<<worker.pay_per_hour<<endl; 
	} 

	string Name(){ 
		return name; 
	} 

	void init(string n, int a, string s, double pay){ 
		name = n; 
		age = a; 
		sex = s; 
		pay_per_hour = pay; 
	}
}; 

class HourlyWorker : public Worker{ 
public: 
	void Compute_pay(double hours){
		double pay; 
		if (hours < 40) 
			pay = pay_per_hour * hours; 
		else 
			pay = pay_per_hour * 40 + 1.5 * pay_per_hour * (hours - 40); 
		cout<<"周薪为 "<<pay<<endl; 
	} 
}; 

class SalariedWorker : public Worker{ 
public: 
	void Compute_pay(double hours){
		double pay; 
		if (hours >= 35) 
			pay = pay_per_hour * 40;
		else 
			pay = pay_per_hour * hours + 0.5 * pay_per_hour * (35 - hours);
		cout<<"周薪为 "<<pay<<endl; 
	} 
}; 

int main(){ 
	Worker* workers[5]; 
	for (int i = 0 ; i < 5 ; i++){ 
		string name; 
		int age; 
		string sex; 
		double pay_per_hour; 
		cout<<"请输入第"<<(i+1)<<"个工人的姓名、年龄、性别和时薪: "; 
		cin>>name>>age>>sex>>pay_per_hour; 
		if (pay_per_hour == 10 || pay_per_hour == 20 || pay_per_hour == 40) 
			workers[i] = new HourlyWorker();
		else if(pay_per_hour == 30 || pay_per_hour == 50) 
			workers[i] = new SalariedWorker();
		else { 
			cout<<"时薪输入有误!"; 
			break; 
		} 
		workers[i]->init(name, age, sex, pay_per_hour); 
	} 
	

	cout<<"--------------------------------"<<endl; 
	int select = 1;

	cout<<"请输入您的操作(1--查看工人信息; 其他--退出): ";
	cin>>select;

	while (select == 1) {
		if(select == 1){
			for(int i = 0 ; i < 5 ; i++){
				cout<<(i+1)<<". "<<workers[i]->Name()<<"\t";
			}
			cout<<endl;

			int index = -1;
			double hours = 0.0;
			cout<<"请输入工人的序号和工时: ";
			cin>>index>>hours;

			if(index > 0 && index <= 5) {
				cout<<*workers[index];
				workers[index]->Compute_pay(hours);
			} else {
				cout<<"数据输入有误!"<<endl;
			}
			cout<<"--------------------------------"<<endl; 

			cout<<"请输入您的操作(1. 查看工人信息; 2. 退出): ";
			cin>>select;
		}
	}

	return 0;
}
