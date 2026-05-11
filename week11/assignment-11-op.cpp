// Oscar Perez - photo 2
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

class Photo
{
    // we could change this to protected: to gain access from subclasses
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
        virtual void display(); // added virtual to use subclass beahvior

        // added to make my loop work properly. couldn't see my functions since it was considered a "photo" not a "mattedPhoto"
        // similar to lecture, abstract
        virtual void setColor(string c) {}
        virtual void setMaterial(string m) {}
        virtual void setStyle(string s) {}

};

// subclass 1
class MattedPhoto : public Photo
{
    private:
        string color;
    public:
        // override
        void display()
        {
            cout << "Please see below for the properties of your photo:" << endl;
            cout << left << setw(25) << "Color:" << getColor() << endl;
            cout << left << setw(25) << "Width:" << getWidth() << endl;
            cout << left << setw(25) << "Height:" << getHeight() << endl;
            cout << left << setw(25) << "Calculated price:" << calculatePrice() + 10 << endl; // add 10 on base price
        };

        string getColor()
        { return color; }

        // noticed that i need setter functions for both subclasses:
        virtual void setColor(string c)
        { color = c; }
};

// subclass 2
class FramedPhoto : public Photo
{
    private:
        string material;
        string style;
    public:
        // override
        void display()
        {
            cout << "Please see below for the properties of your photo:" << endl;
            cout << left << setw(25) << "Material:" << getMaterial() << endl;
            cout << left << setw(25) << "Style:" << getStyle() << endl;
            cout << left << setw(25) << "Width:" << getWidth() << endl;
            cout << left << setw(25) << "Height:" << getHeight() << endl;
            cout << left << setw(25) << "Calculated price:" << calculatePrice() + 20 << endl; // add 20 on base price
        };

        string getMaterial()
        { return material; }

        string getStyle()
        { return style; }

        void setMaterial(string m)
        { material =  m; }

        void setStyle(string s)
        { style = s; }
};



struct FakePhotos
{
    double width;
    double height;
    string color = "";
    string material = "";
    string style = "";
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
    cout << left << setw(25) << "Width:" << getWidth() << endl;
    cout << left << setw(25) << "Height:" << getHeight() << endl;
    cout << left << setw(25) << "Calculated price:" << calculatePrice() << endl;
}



int main ()
{

    const int TOTAL_PHOTOS = 8;
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
    
    // mattedPhoto & framedPhoto
    FakePhotos p7 = {6, 66, "Pink",};
    FakePhotos p8 = {3, 8, "", "Silver", "Modern"};
    PhotoList[6] = p7;
    PhotoList[7] = p8;


    cout << fixed << setprecision(2) << showpoint;
    for (int i = 0; i < TOTAL_PHOTOS; i += 1)
    {
        Photo* currentPhoto = nullptr; // pointer
        
        if(i < 6)
        {
            currentPhoto = new Photo();
        }
        else if (i == 6)
        {
            currentPhoto = new MattedPhoto();
            currentPhoto->setColor(PhotoList[i].color);
            

        }
        else if (i == 7)
        {
            currentPhoto = new FramedPhoto();
            currentPhoto->setMaterial(PhotoList[i].material);
            currentPhoto->setStyle(PhotoList[i].style);

        }

        // had to switch these out bc now we're working with pointers not the object
        cout << "Photo " << i + 1 << endl;
        currentPhoto->setWidth(PhotoList[i].width);
        currentPhoto->setHeight(PhotoList[i].height);
        
        currentPhoto->display();
        cout << endl;
    }


    return 0;
    

}
