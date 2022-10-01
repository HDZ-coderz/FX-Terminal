#include "lib.h"
class other{
    public:
    void open_link(std::string x){
        if(x=="N/A"){
            std::cout << "Not available"<<std::endl;
        }else{
        ShellExecute(NULL,"open",x.c_str(),NULL,NULL,SW_SHOWNORMAL);}
    }
    //function for cd
};
class pkg:public other{
public:
     std::vector<std::string> arg={"python","ruby","r","jdk","jdk_msi_installer","tdm gcc/g++ compiler","mingw c/c++ compiler","node.js","php","vs code","avast","BeautifulSoup","git bash",""};
std::vector<std::string> pkg_main_file(){
    //get links
    std::string r;
     std::vector<std::string> links;
    std::ifstream f("link.txt");
    while(getline(f,r)){
            links.push_back(r);
          }
          f.close();
    return links;
}
void pkg_main(std::string i){
    std::vector<std::string> l=pkg_main_file();
   int len=arg.size();
   int n=0;
    while(n<len){
            if(i==arg[n]&&i!=""){
            open_link(l[n]);
            break;
        }else if(n==len-1){
            std::cout<<"No args found!"<<std::endl;
        }
        n++;
    }
}
};
void exc(std::string X){
    pkg p;
    p.pkg_main(X);
}
