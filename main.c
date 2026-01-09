// 2026.1.9

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COLOR_RESET "\033[0m" // 重置 
#define COLOR_WELCOME "\033[1;34m" // 欢迎界面
#define COLOR_DISPLAY "\033[1;33m" // 游戏界面

void FirstShow();
void IntroduceGame();
void ExitGame();
void IntroduceAuthor();

int main() {
    FirstShow();
    printf("start!");

    exit(EXIT_SUCCESS);
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
