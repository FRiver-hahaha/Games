# 2026.4.16 完成飞船的导入和绘制

# 下次完整重构代码模块

import sys

import pygame

from settings import Settings

from ship import Ship

def runGame() :
    # 创建屏幕对象，初始化设置
    pygame.init()
    aiSettings = Settings()
    screen = pygame.display.set_mode((aiSettings.screenWidth, aiSettings.screenHeight))
    pygame.display.set_caption("Alien Invasion")

    ship = Ship(screen)

    # 开始游戏的主循环
    while True:
        
        # 用来退出游戏的事件监听
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
        
        # 填充背景颜色
        screen.fill(aiSettings.bgColor)
        ship.blitme()

        pygame.display.flip()

runGame()