import pygame as pg
import random
win=pg.display.set_mode((1920,1080))
fps=pg.time.Clock()
run = True
pulse = True

while run :
    for i in pg.event.get() :
        if i.type == pg.QUIT :
            run = False
        if i.type == pg.KEYDOWN :
            if i.key == pg.K_q :
                run = False
            if i.key == pg.K_p :
                pulse = not pulse
    if pulse :
        x=random.randint(0,255)
        y=random.randint(0,255)
        z=random.randint(0,255)
        # print(x,y,z)
    else :
        x=0;y=0;z=0
    win.fill((x,y,z))
    pg.display.flip()
    fps.tick(20)
pg.quit()

# P PAUSE
# Q QUIT