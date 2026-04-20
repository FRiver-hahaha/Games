import sys
import pygame

# 游戏的事件监听
def check_events(ship):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()


        # 实现持续移动
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                ship.moving_left = True
            if event.key == pygame.K_RIGHT:
                ship.moving_right = True

        elif event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                ship.moving_left = False
            if event.key == pygame.K_RIGHT:
                ship.moving_right = False

# 更新屏幕
def update_screen(ai_settings, screen, ship):
    screen.fill(ai_settings.bgColor)

    ship.blitme()

    pygame.display.flip()