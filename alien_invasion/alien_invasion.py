import sys

import pygame

from settings import Settings

def runGame() :
    # 创建屏幕对象，初始化设置
    pygame.init()
    aiSettings = Settings()
    screen = pygame.display.set_mode((aiSettings.screenWidth, aiSettings.screenHeight))
    pygame.display.set_caption("Alien Invasion")

    # 开始游戏的主循环
    while True:
        
        # 用来退出游戏的事件监听
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        
        # 填充背景颜色
        screen.fill(aiSettings.bgColor)

        pygame.display.flip()

runGame()