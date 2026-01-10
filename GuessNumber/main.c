// 2026.1.10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>

#define COLOR_RESET "\033[0m" // 重置 
#define COLOR_WELCOME "\033[1;34m" // 欢迎界面(粗体蓝色)
#define COLOR_DISPLAY "\033[1;33m" // 游戏界面(粗体黄色)
#define COLOR_ERROR "\033[1;31m" // 显示错误个数(粗体红色)
#define COLOR_WIN "\033[1;36m" // 胜利界面(粗体青色)

void FirstShow();
void IntroduceGame();
void ExitGame();
void IntroduceAuthor();
void StartGame();
int SearchNumber(char [], char []);
void Qsort(int arr[], int low, int high);

int main() {
    char ch;
    FirstShow();
    printf("start!\n");
    sleep(1);
    StartGame();
    do {
        printf("是否还要再来一轮？(按c继续，按q退出...)\n");
        getchar();
        ch = getchar();
        if(ch == 'c') {
            printf("start!\n");
            sleep(1);
            StartGame();
        }
    }while(ch != 'q'); 
    ExitGame();
    exit(EXIT_SUCCESS);
}

void Qsort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int key = arr[low];
    if(i > j) {
        return;
    }
    while(i < j) {
        while(i < j && arr[j] >= key) {
            j--;
        }

        while(i < j && arr[i] <= key) {
            i++;
        }

        if(i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[low];
    arr[low] = arr[i];
    arr[i] = tmp;
    Qsort(arr, low, i - 1);
    Qsort(arr, i + 1, high);
}

int SearchNumber(char nums[], char pnums[]) {
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        if(nums[i] != pnums[i]) {
            cnt++;
        }
    }
    return cnt;
}

void StartGame() {
    srand(time(NULL));
    int cnt = 0;
    int min = 10000, max = 99999;
    int number = rand() % (max - min + 1) + min;
    char nums[10], pnums[10];
    int snums[5];
    int tmp = number;
    for(int i = 4; i >= 0; i--) {
        nums[i] = '0' + (tmp % 10);
        snums[i] = tmp % 10;
        tmp /= 10;
    }
    nums[5] = '\0';
    printf("已生成数字!\n");
    Qsort(snums, 0, 4);
    printf("当前可选数字有:");
    for(int i = 0; i < 5; i++) {
        printf("%d", snums[i]);
        if(!(i == 5 - 1)) {
            printf(" ");
        }   
    }
    printf("\n");
    sleep(1);
    do {
        printf("请输入你的答案：\n");
        scanf("%s",pnums);
        pnums[5] = '\0';
        cnt = SearchNumber(nums, pnums);
        if(cnt) {
            printf("%s有%d个错误！%s\n",COLOR_ERROR, cnt, COLOR_RESET);
        }
    }while(cnt != 0);
    printf("%s正确！%s\n",COLOR_WIN, COLOR_RESET);
    return;
}

void IntroduceAuthor() {
    int fd = open("author.md", O_RDWR);
    char ch[2];
    ssize_t readnumber;
    if(fd == -1) {
        printf("打开失败！请检查文件夹内是否有 author.md 文件\n");
        return;
    }
    while((readnumber = read(fd, ch, 1)) > 0) {
        ch[1] = '\0';
        printf("%s", ch);
    }
    close(fd);
    return;
}

void IntroduceGame() {
    int fd = open("readme.md", O_RDWR);
    char ch[2];
    ssize_t readnumber;
    if(fd == -1) {
        printf("打开失败！请检查文件夹内是否有 readme.md 文件\n");
        return;
    }
    while((readnumber = read(fd, ch, 1)) > 0) {
        ch[1] = '\0';
        printf("%s", ch);
    }
    close(fd);
    return;
}

void ExitGame() {
    printf("游戏已退出...");
    printf("感谢您的游玩，我们下次再见...\n");
    exit(EXIT_SUCCESS);
}

void FirstShow() {
    int time;
    char ch, flag = '#';
    char* wl = "Welcome";
    char* wl2 = "GAME";
    for(time = 1; time <= 10; time++) {
        for(int i = 0; i < 30; i++) {
            printf("%c",flag);
            if((i == 29)) {
                printf("\n");
            }
        }
        if(time == 10 / 2) {
            for(int i = 0; i < 10; i++) {
                printf("%c",flag);
            }
            printf("%s%s%s", COLOR_WELCOME, wl, COLOR_RESET);
            for(int i = 0; i < 13; i++) {
                printf("%c",flag);
                if(i == 12) {
                    printf("\n");
                }
            }
            for(int i = 0; i < 12; i++) {
                printf("%c",flag);
            }
            printf("%s%s%s", COLOR_WELCOME, wl2, COLOR_RESET);
            for(int i = 0; i < 14; i++) {
                printf("%c",flag);
                if(i == 13) {
                    printf("\n");
                }
            }
        }
        usleep(50000);
    };
    printf("按任意键继续(q退出)...\n");
    ch = getchar();
    if(ch == 'q') {
        ExitGame();
    }
    while(ch != 'q') {
        printf("%ss 开始游戏%s\t", COLOR_DISPLAY, COLOR_RESET);
        printf("%sh 游戏简介%s\t", COLOR_DISPLAY, COLOR_RESET);
        printf("%sq 退出游戏%s\t", COLOR_DISPLAY, COLOR_RESET);
        printf("%sm 制作人员%s\n", COLOR_DISPLAY, COLOR_RESET);
        getchar();
        ch = getchar();
        switch(ch) {
            case 's': return;
            case 'h': IntroduceGame();break;
            case 'q': ExitGame();break;
            case 'm': IntroduceAuthor();break;
            default: break;
        }
    }
}
