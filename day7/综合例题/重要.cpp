//���һ���ַ�����String��ͨ�����������ʵ���ַ��������롢����Լ�+=��==��!=��<��>��>=��[ ]�����㡣
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
int length;                     		//�ַ�������
char *sPtr;                     		//����ַ�����ָ��
void setString( const char *s2);	
friend ostream &operator<<(ostream &os, const String &s); 
friend istream &operator>>(istream &is, String &s);  //�������������
public:
    String( const char * = "" );                   
    const String &operator=(const String &R); 		//���ظ�ֵ����� =
    const String &operator+=(const String &R);		//�ַ��������� +=
    bool operator==(const String &R);				//�ַ�������ȱȽ� ==
    bool operator!=(const String &R);				//�ַ����Ĳ��ȱȽ� !=
    bool operator!() ;               				//�ж��ַ����Ƿ�Ϊ��
    bool operator<(const String &R) const;     		//�ַ�����С�ڱȽ� <
    bool operator>(const String &R);                	//�ַ����Ĵ��ڱȽ� >
    bool operator>=(const String &R);             	//�ַ����Ĵ��ڵ��ڱȽ�
    char &operator[](int);                         	//�ַ������±�����
    ~String();  
};
const String &String::operator+=(const String &R) {
    char *temp = sPtr;              
    length += R.length;           
    sPtr = new char[length+1]; 
    strcpy(sPtr,temp );           
    strcat(sPtr,R.sPtr );         
    delete [] temp;                 
    return *this;                         
}
bool String::operator==(const String &R){return strcmp(sPtr,R.sPtr)==0;}
bool String::operator!=(const String & R){return !(*this==R);}
bool String::operator!(){return length ==0;}
bool String::operator<(const String &R)const{return strcmp(sPtr,R.sPtr)<0;}
bool String::operator>(const String &R){return R<*this;}
bool String::operator>=(const String &R){return !(*this<R);}
char &String::operator[](int subscript){return sPtr[subscript];}
int main(){
    String s1("happy"),s2("new year"),s3;
    cout << "s1 is " << s1 << "\ns2 is " << s2 << "\ns3 is " << s3       
    << "\n�Ƚ�s2��s1:"
    << "\ns2 ==s1����� " << ( s2 == s1 ? "true" : "false")
    << "\ns2 != s1����� " << ( s2 != s1 ? "true" : "false")
    << "\ns2 >  s1����� " << ( s2 >  s1 ? "true" : "false") 
    << "\ns2 <  s1����� " << ( s2 <  s1 ? "true" : "false") 
    << "\ns2 >= s1����� " << ( s2 >= s1 ? "true" : "false");
    cout << "\n\n����s3�Ƿ�Ϊ��: ";                         	
    if (!s3){
        cout << "s3�ǿմ�"<<endl;                           	//L3
        cout<<"��s1����s3�Ľ���ǣ�";                    		       	
        s3 = s1;                                         
        cout << "s3=" << s3 << "\n";                          	//L5
    }
    cout << "s1 += s2 �Ľ���ǣ�s1=";                      	//L6
    s1 += s2;                                       
    cout << s1;                                             		//L7
                                                        
    cout << "\ns1 +=  to you �Ľ���ǣ�";                     	//L8
    s1 += " to you";                               
    cout << "s1 = " << s1 <<endl;                              	//L9
    s1[0] = 'H';      
    s1[6] = 'N';
    s1[10] = 'Y';
    cout << "s1 = " << s1 << "\n";                               //L10
    system("pause");
    return 0;
}
