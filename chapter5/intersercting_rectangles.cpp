/**************************************************************************/
/* Task:    Write a program which tests if two rectangles have a          */
/*          nonempty intersection. If the intersection is nonempty,       */
/*          return the rectangle formed by their intersection.            */
/*          probability? All values in [a,b] should be equally likely.    */
/* Date:    2025-08-26                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>

using namespace std;

struct  Rectangle
{
    int x, y, width, height;
};

bool    IsIntersect(const Rectangle& R1, const Rectangle& R2)
{
    return (R1.x <= R2.x + R2.width && R1.x + R1.width >= R2.x &&
            R1.y <= R2.y + R2.height && R1.y + R1.height >= R2.y);
}

Rectangle   IntersectRectangle(const Rectangle& R1, const Rectangle& R2)
{
    if (!IsIntersect(R1, R2))
        return {0, 0, -1, -1}; // No intersection.
    return { max(R1.x, R2.x), max(R1.y, R2.y),
             min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
             min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)};
}

int main()
{
    Rectangle   R1{2, 2, 4, 4};
    Rectangle   R2{4, 4, 4, 4};
    Rectangle   R3 { IntersectRectangle(R1, R2) };

    if (R3.width < 0 || R3.height < 0)
        cout << "No intersection" << endl;
    else
        cout << "Intersection: (" << R2.x << "," << R3.y
             << "), width=" << R3.width
             << ", height=" << R3.height << endl;
    return (0);
}
