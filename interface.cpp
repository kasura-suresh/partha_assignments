#include <iostream>
 
using namespace std;
class Shape 
{
	protected:
      int width;
      int height;
    public:
      virtual int getArea() = 0;
      void setW(int w) 
	  {
         width = w;
      }
   
      void setH(int h) 
	  {
         height = h;
      }
};
class Rectangle: public Shape 
{
    public:
      int getArea() 
	  { 
         return (width * height); 
      }
};

class Triangle: public Shape 
{
    public:
      	int getArea() 
		{ 
         return (width * height)/2; 
        }
};
 
int main(void) 
{
   int rW,rH,tW,tH; 
   Rectangle Rect;
   Triangle  Tri;
   cout<<"Enter width and height of the rectangle:\n";
   cin>>rW>>rH;
   cout<<"Enter width and height of the triangle:\n";
   cin>>tW>>tH;
   Rect.setW(rW);
   Rect.setH(rH);
   cout << "Total Rectangle area: " << Rect.getArea() << endl;
   Tri.setW(tW);
   Tri.setH(tH);
   cout << "Total Triangle area: " << Tri.getArea() << endl; 

   return 0;
}
