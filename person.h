#include<iostream>
#include<string>
using namespace std;

namespace pass{
class person
{
private:
    string name,gender;
    int age;
public:
    void setName(string n)                  ///name setter
    {
        name=n;
    }
    void setGender(string n)                ///gender setter
    {
        gender=n;
    }
    void setAge(int n)                      ///age setter
    {
        age=n;
    }
    string getName()                        ///name getter
    {
        return name;
    }
    string getGender()                      ///gender getter
    {
        return gender;
    }
    int getAge()                            ///age getter
    {
        return age;
    }
};
class employe : public person
{
private:
    int salary;
    string post,skill;
public:
    void setSalary(int n)                       ///salary setter
    {
        salary=n;
    }
    void setPost(string n)                      ///post setter
    {
        post=n;
    }
    void setSkill(string n)                     ///skill setter
    {
        skill=n;
    }
    int getSalary()                            ///salary getter
    {
        return salary;
    }
    string getPost()                           ///post getter
    {
        return post;
    }
    string getSkill()                          ///skill getter
    {
        return skill;
    }
};

class company : public employe
{
private:
    string companyname;
public:
    void setCompanyname(string n)                      ///companyname setter
    {
        companyname=n;
    }
    string getCompanyname()                          ///companyname getter
    {
        return companyname;
    }
    void dataEntery()
    {
        int h;
        string l;
        cout<<"Enter Person Name "<<endl;
        cin>>l;
        setName(l);
        cout<<"Enter Person Gender "<<endl;
        cin>>l;
        setGender(l);
        cout<<"Enter Person Age "<<endl;
        cin>>h;
        setAge(h);
        cout<<"Enter Person Skill"<<endl;
        cin>>l;
        setSkill(l);
        cout<<"Enter Company Name "<<endl;
        cin>>l;
        setCompanyname(l);
        cout<<"Enter Post in Company "<<endl;
        cin.get();
        cin>>l;
        setPost(l);
        cout<<"Enter Person Salary "<<endl;
        cin>>h;
        setSalary(h);
    }
    void disp()
    {
        cout<<getName()<<" "<<getGender()<<" "<<getAge()<<" "<<getSkill()<<" "<<getCompanyname()<<" "<<getPost()<<" "<<getSalary();
    }
};

class process
{
public:
    void task()
    {
        company c;
        c.dataEntery();
        c.disp();
    }
};
}

