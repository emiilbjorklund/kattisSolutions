import math

def inCricle(circle_x, circle_y, rad, x, y): 
    # Pythagoras theorem
    if ((x - circle_x) * (x - circle_x) + 
        (y - circle_y) * (y - circle_y) <= rad * rad): 
        return True
    else: 
        return False
if __name__ == "__main__":
    rounds = int(input(""))

    for i in range(rounds):
        inside = False
        userinput = input("").split()
        x = float(userinput[0])
        y = float(userinput[1])
        w = float(userinput[2])
        h = float(userinput[3])
        r = float(userinput[4])
        corners = [(x+r,y+r),(x+r,y+h-r),(x+w-r,y+r),(x+w-r,y+h-r)]

        for j in range(6,6 + int(userinput[5])*2,2):
            pX = float(userinput[j])
            pY = float(userinput[j+1])
            
            # Checking if the pont given is inside the area of the rectangle given by the corners minus the radius of the circle.
            if pX >= x+r and pX <= (x+w-r) and pY >=y and pY <= (y+h):
                inside = True
            
            elif pX >= x and pX <= (x+w) and pY >=(y+r) and pY <= (y+h-r):
                inside = True
            # If the points is not inside the above statements, the last thing to check is if the point is located in one of the rounded corners.
            else:
                for i in range(0,4,1):
                    if  inCricle(corners[i][0], corners[i][1],r, pX, pY):
                        inside = True
                        break

            if inside:
                print("inside")
            else:
                print("outside")
            inside = False
