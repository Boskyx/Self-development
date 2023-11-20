#Worked example 3.2
#Graphic program that draws two circles,
#each defined by its center and radius, and determines whether the two circles intersect.
#The user decides where to draw the two circles

from ezgraphics import GraphicsWindow
from sys import exit
from math import *
WIDHT=input("Insert the value for the widht:")
HEIGHT=input("Insert the value for the height:")
message=""
if (WIDHT.isalpha() or HEIGHT.isalpha()):
    exit("one of the two variables did not receive a numerical input")
#Radius of Circles
First_Radius=int(input("insert the value of r for the first circle:"))
Second_Radius=int(input("insert the value of r for the second circle:"))
#Creation of the Windows
win=GraphicsWindow(WIDHT, HEIGHT)
canvas=win.canvas()
win.setTitle("Intersection of circles")

""" Creation of the circles with the interaction of the user
First we save the coordinates of the mouse click, where you click will be the center of the first circle
After we save the coordinates in two variables and we convert the cm in pixel (size_One variable, tipicaly people think in cm not in pixel), in that way we can create the square
that contain the circle. size_One variable is equal to the diameter of the circle and is the side of the square where is inscript the circle.
Due to the fact that when the user click on the window, that is not the center of the circle but it's the initial point where the square inside which it is inscript the circle.
So we had the widht and height in pixel (size_One variable), if we divided by 2 whe have the center of the circle coordinates x and y."""

#Circle One
print("for the first circle you have chose the value of r=", First_Radius)
message="Select in the window the center of your first circle"
canvas.drawText(1,1, message)
Coordinats_One=win.getMouse()
x_One=Coordinats_One[0]
y_One=Coordinats_One[1]
size_One=2*(First_Radius/0.0225)
canvas.setOutline("blue")
canvas.clear()
canvas.drawOval((x_One-size_One/2), (y_One-size_One/2),size_One, size_One) #we reduce the x and y coordinates by 1/2 of the side square pixels, in that way the center corresponds with the point clicked by the user
#Circle Two
print("for the second circle you have chose the value of r=", Second_Radius)
message="Select in the window the center of your second circle"
canvas.drawText(1,1, message)
Coordinats_Two=win.getMouse()
x_Two=Coordinats_Two[0]
y_Two=Coordinats_Two[1]
size_Two=2*(Second_Radius/0.0225)
canvas.setOutline("red")
canvas.drawOval((x_Two-size_Two/2), (y_Two-size_Two/2),size_Two, size_Two)
#Determine if there are one or more intersections
Euclidean_Distance= sqrt(((x_One)-(x_Two))**2+((y_One)-(y_Two))**2)
Euclidean_Result=""
if Euclidean_Distance > (size_One/2+size_Two/2):
    message="no intersections"
elif Euclidean_Distance < abs((size_One/2-size_Two/2)):
    message="no intersections and one is included"
elif Euclidean_Distance == (size_One/2+size_Two/2):
    message="intersections in one point"
elif Euclidean_Distance==0 and size_One/2==size_Two/2 :
    message="coincident circles"
else:
    message="intersections in two points"
canvas.drawText(1,int(HEIGHT)-20,message)
print(Euclidean_Distance, "\n", (size_One/2-size_Two/2))
print(x_One-size_One/2, x_Two-size_Two/2)
win.wait()


#elif Euclidean_Distance < (size_One/2+size_Two/2):
    #message="Intersections in two points"

"""
NOTES
    1)Sometimes it makes a mistake in understanding that the second circle is included in the first, because it turns out that the distance is not less than the difference of the 2*radius. 
        Bug fixed, error in the Euclidean Distance formula, as I adjusted it by moving its center.

"""
