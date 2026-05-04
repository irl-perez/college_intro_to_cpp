// Oscar Perez - corp sales
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

class Photo
{
    private:
        double width;
        double height;
    public:
        // const to avoid changing data
        double getWidth() const;
        double getHeight() const;

        void setWidth(double w);
        void setHeight(double h);
        
        double calculatePrice();
        void display();

};

struct FakePhotos
{
    double width;
    double height;
};


// member functions

double Photo::getWidth() const
{
    return width;
}

double Photo::getHeight() const
{
    return height;
}

void Photo::setWidth(double w)
{
    width = w;
}

void Photo::setHeight(double h)
{
    height = h;
}

double Photo::calculatePrice()
{
    // added for easier updating
    const double EIGHT_BY_TEN_PRICE = 3.99;
    const double TEN_BY_TWELVE_PRICE = 5.99;

    double price;

    double w = getWidth();
    double h = getHeight();


    if ((w == 8 and h == 10) || (w == 10 and h == 8))
        price = EIGHT_BY_TEN_PRICE;
    else if ((w == 10 and h == 12) || (w == 12 and h == 10))
        price = TEN_BY_TWELVE_PRICE;
    else
        price = 9.99;
    
    return price;


}
void Photo::display()
{
    cout << "Please see below for the properties of your photo:" << endl;
    cout << "Width:\t" << getWidth() << endl;
    cout << "Height:\t" << getHeight() << endl;
    cout << "Calculated price:\t" << calculatePrice() << endl;
}



int main ()
{

    const int TOTAL_PHOTOS = 6;
    FakePhotos PhotoList[TOTAL_PHOTOS]; // somewhere store all photo structures

    // multiple values for testing
    // 8 x 10
    FakePhotos p1 = {8, 10};
    FakePhotos p2 = {10, 8};
    PhotoList[0] = p1;
    PhotoList[1] = p2;


    // 10 x 12
    FakePhotos p3 = {10, 12};
    FakePhotos p4 = {12, 10};
    PhotoList[2] = p3;
    PhotoList[3] = p4;
    
    // custom
    FakePhotos p5 = {6, 66};
    FakePhotos p6 = {3, 8};
    PhotoList[4] = p5;
    PhotoList[5] = p6;

    cout << fixed << setprecision(2) << showpoint;
    for (int i = 0; i < TOTAL_PHOTOS; i += 1)
    {
        // loop through array and run all functions.
        
        Photo currentPhoto;
        cout << "Photo " << i + 1 << endl;
        currentPhoto.setWidth(PhotoList[i].width);
        currentPhoto.setHeight(PhotoList[i].height);
        
        currentPhoto.display();
        cout << endl;
    }

    return 0;
    

}
