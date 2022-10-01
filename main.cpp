#include "lib.h"
#include "links.h"
#define greetings std::cout<<"Welcome"<<std::endl;
class commands:public pkg{
    public:
    void package(std::string x,int l){
        //filter
        x.replace(0,l,"");
        exc(x);
    }
    void cd(std::string x){
        //filter
        x.replace(0,3,"");
        const char *xc=x.c_str();
        //check if that loaction exists
        DIR *d;
        struct dirent *e;
        d=opendir(xc);
        if(d){
        //change dir
        chdir(xc);
        }
        else{
            std::cout << "dir don't exist or not accesibile" <<std::endl;
        }
        closedir(d);
    }
    void pkg_list(){
         int len=arg.size();
         for(int i=0;i<len;i++){
            std::cout << arg[i] <<std::endl;
         }
    }
    void help(std::string x[]){
        std::string des[]={"-Installs softwares and programs.Use pkg list for list of installable softwares.","-To exit","","-changes directory to home directory.","-changes directory.","-lists installable softwares","-for help with commands"};
        int len=sizeof(x)-1;
            for(int i=0;i<len;i++){
            std::cout << x[i]<<" "<<des[i]<<std::endl;
        }
    }
     void check_command(std::string x,int l){
         //the result of looping
        std::string result="";
        for(int i=0;i<l;i++){
            result+=x[i];
        }
        if(result=="cd "){
            cd(x);
        }
        if(result=="pkg install "){
            package(x,l);
        }
    }
};
//main func's class
class terminal:public commands{
    public:
void t(){
    //gets value of home location
     char home[628];
    getcwd(home,628);
    //commands
    std::string cmd[]={"pkg install ","exit","","cd home","cd ","pkg list","help"};
    //userinput
    std::string i;
    //infinite loop for repeation
    while(true){
        //get user input
        std::cout << "FX ";
        getline(std::cin,i);
        //prefrix
        if(i.find(cmd[0])!=std::string::npos){
                check_command(i,cmd[0].size());
        }else if(i==cmd[1]){
            exit(0);
        }else if(i==cmd[2]){
            continue;
        }else if(i==cmd[3]){
            //for change dir to home dir
            chdir(home);
        }
        else if(i.find(cmd[4])!=std::string::npos){
            check_command(i,cmd[4].size());
        }
        else if(i==cmd[5]){
           pkg_list();
        }
        else if(i==cmd[6]){
            help(cmd);
        }
        else{
            //if command is not found then the command is given to system
            system((i).c_str());
        }
    }
}};
int main(){
    //obj
    terminal ter;
    //set colour
    system("Color 03");
    greetings;
    //main terminal function
    ter.t();
    getch();
    return 0;
}
