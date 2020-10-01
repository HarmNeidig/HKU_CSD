from graphics import *

def main():
    Xwidth = 500
    Yheight = 500
    win = GraphWin("window", Xwidth, Yheight)
    win.setBackground(color_rgb(0,0,0))
    Xmiddle = Xwidth/2
    Ymiddle = Yheight/2
    mainCircle = Circle(Point(Xmiddle,Ymiddle),250)
    mainCircle.setFill(color_rgb(125,125,125))
    XminPT = Point(Xwidth/2,0)
    YminPT = Point(0,Yheight/2)
    XplusPT = Point(Xwidth/2, Yheight)
    YplusPT = Point(Xwidth, Yheight/2)
    Yline = Line(YminPT,YplusPT)
    Xline = Line(XminPT,XplusPT)
    Xline.setWidth(6)
    Yline.setWidth(6)
    Xline.setOutline(color_rgb(0,0,0))
    Yline.setOutline(color_rgb(0,0,0))
    mainCircle.draw(win)
    Yline.draw(win)
    Xline.draw(win)
    win.getMouse() # Pause to view result
    win.close()    # Close window when done

main()
