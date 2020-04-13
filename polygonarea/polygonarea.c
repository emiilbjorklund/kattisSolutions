#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

void getArea(struct Point *points, double *area, int *orientation, int degree)
{
    double left = 0,right = 0;

    points[degree] = points[0];

    // Calculates the area with the Shoelace formula
	for(int i=0;i<degree;i++){
		left += points[i].x*points[i+1].y;
		right += points[i+1].x*points[i].y;
	}
 
	*area =  0.5*fabs(left - right);

    // If the sum of the left and right side is > 0 the points are ordered in CW
    *orientation = (left - right);
}


int main(void) 
{ 
    int vertices, items,x,y;
    int orientation;
    double area;


    items = scanf("%d", &vertices);
    if (items != EOF || items != 0) {
        
        while(vertices != 0){
            // Allocate memeory for array depending on points inputs by user
            struct Point *points = malloc((vertices + 1)* sizeof(*points));
            for (int i = 0; i < vertices; i++)
            {
                scanf("%d %d", &x, &y);
                if (items != EOF || items != 0) {
                    points[i].x = x;
                    points[i].y = y;
                }
            }
            getArea(points,&area,&orientation,vertices);
            if (orientation > 0)
            {
                printf("CCW %.1f\n",area);
            }
            else
            {
                printf("CW %.1f\n",area);
            }

            free(points);
            int input;
            items = scanf("%d", &input);
            if (items != EOF || items != 0) {
                vertices = input;
            }
        }
    }
    return 0; 
} 