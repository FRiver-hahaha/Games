# 2026.4.16 完成飞船的导入和绘制

# 下次完整重构代码模块
import pygame

from settings import Settings
from ship import Ship
import game_functions as gf

def runGame() :
    # 创建屏幕对象，初始化设置
    pygame.init()
    aiSettings = Settings()
    screen = pygame.display.set_mode((aiSettings.screenWidth, aiSettings.screenHeight))
    pygame.display.set_caption("Alien Invasion")

    ship = Ship(aiSettings, screen)

    # 开始游戏的主循环
    while True:
        
        # 游戏的事件监听
        gf.check_events(ship)
        ship.update()
        # 填充背景颜色
        gf.update_screen(aiSettings, screen, ship)

runGame()