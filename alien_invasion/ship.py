import pygame

class Ship():
    def __init__(self, aiSettings, screen):
        # 加载飞船，设置初始位置
        self.screen = screen
        self.aiSettings = aiSettings
        
        

        self.image = pygame.image.load('images/ship.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # 存储速度
        self.center = float(self.rect.centerx)

        self.moving_left = False
        self.moving_right = False

    def update(self):# 检测向左移动
        if self.moving_left:
            self.center -= self.aiSettings.ship_speed_factor
        
        if self.moving_right:
            self.center += self.aiSettings.ship_speed_factor

        self.rect.centerx = self.center

    def blitme(self):
        self.screen.blit(self.image, self.rect)

    