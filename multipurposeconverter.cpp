#include<iostream>
using namespace std;

int main(){
    double length, area, volume, mass, temperature;
    char input, input1, input2, input3;

    cout << "WELCOME TO MULTIPURPOSE CONVERTER!\n";
    cout << "Enter 'S' to begin or 'Q' to quit: ";
    cin >> input;
    if (input == 'S' || input == 's')
    { beginning:
        cout << "\n-------------MULTPURPOSE CONVERSION APK-------------\n";
        cout << "Please select the type of conversion you want to perform:\n";
        cout << "~TYPE L for LENGTH CONVERSION\n";
        cout << "~TYPE A for AREA CONVERSION\n";
        cout << "~TYPE V for VOLUME CONVERSION\n";
        cout << "~TYPE M for MASS CONVERSION\n";
        cout << "~TYPE T for TEMPERATURE CONVERSION\n";
        cin >> input1;
    }
    else if (input == 'Q' || input == 'q')
    {
        cout << "GOODBYE!\n";
        return 0;
    }
    else{
        cout << "Invalid input. Please try again.\n";
    }
    
    if (input1 == 'L' || input1 == 'l')
    {
        cout << "*******LENGHT CONVERSION*******\n";
        cout << "Type M for METERS TO CENTIMETERS\n";
        cout << "Type C for CENTIMETERS TO METERS\n";
        cout << "Type F for FEET TO METERS\n";
        cout << "Type I for INCHES TO METERS\n";
        cin >> input2;

        if (input2 == 'M' || input2 == 'm')
        {
            cout << "Enter the length in meters: ";
            cin >> length;
            length = length * 100;
            cout << "Length in Centimeters is: " << length << "cm\n";
        }
        else if (input2 == 'C' || input2 == 'c')
        {
            cout << "Enter the lenght in centimeters: ";
            cin >> length;
            length = length / 100;
            cout << "Length in meters is: " << length << "m\n";
        }
        else if (input2 == 'F' || input2 == 'f')
        {
            cout << "Enter the length in feet: ";
            cin >> length;
            length = length * 0.3048;
            cout << "Length in meters is: " << length << "m\n";
        }
        else if (input2 == 'I' || input2 == 'i')
        {
            cout << "Enter the length in inches: ";
            cin >> length;
            length = length * 0.0254;
            cout << "Length in meters is: " << length << "m\n";
        }
        else {
            cout << "Invalid Input\n";
        }
    }

    else if (input1 == 'A' || input1 == 'a')
    {
        cout << "*******AREA CONVERISON*******\n";
        cout << "Type M for SQUARE METERS TO SQUARE CENTIMETERS\n";
        cout << "Type C for SQUARE CENTIMETERS TO SQUARE METERS\n";
        cout << "Type F for SQUARE METERS TO SQUARE FEET \n";
        cout << "Type I for SQUARE METERS TO SQUARE INCHES\n";
        cin >> input2;

        if (input2 == 'M' || input2 == 'm')
        {
            cout << "Enter the area in square meters: ";
            cin >> area;
            area = area * 10000;
            cout << "Area in centimeter square is " << area << "cmsq\n";
        }
        else if (input2 == 'C' || input2 == 'c')
        {
            cout << "Enter the area in square centimeters";
            cin >> area;
            area = area * 0.0001;
            cout << "Ares in meter square is " << area << "msq\n";
        }
        else if (input2 == 'F' || input2 == 'f')
        {
            cout << "Enter the area in square meters: ";
            cin >> area;
            area = area * 10.764;
            cout << "Area in square feet is " << area << "ftsq\n";
        }
        else if (input2 == 'I' || input2 == 'i')
        {
            cout << "Enter the area in square meters: ";
            cin >> area;
            area = area * 1550;
            cout << "Area in square inches is " << area << "inchesq\n";
        }
        else {
            cout << "Invalid Input\n";
        }
    }   

    else if (input1 == 'V' || input1 == 'v')
    {
        cout << "*******VOLUME CONVERSION*******\n";
        cout << "Type M for CUBIC METERS TO CUBIC CENTIMETERS\n";
        cout << "Type L for LITER TO MILLILITER\n";
        cout << "Type I for CUBIC INCH TO LITER\n";
        cout << "Type C for LITER TO CUBIC METERS\n";
        cin >> input2;
    
        if (input2 == 'M' || input2 =='m')
        {
            cout << "Enter the volume in cubic meters: ";
            cin >> volume;
            volume = volume * 1000000;
            cout << "Volume in cubic centimeters is " << volume << "cm3\n";
        }
        else if (input2 == 'L' || input2 == 'l')
        {
            cout << "Enter the volume in liters: ";
            cin >> volume;
            volume = volume * 1000;
            cout << "Volume in milliliters is " << volume << "ml3\n";
        }
        else if (input2 == 'I' || input2 == 'i')
        {
            cout << "Enter the volume in cubic inches: ";
            cin >> volume;
            volume = volume * 0.016387;
            cout << "Volume in Liters is " << volume << "lt3\n";
        }
        else if (input2 == 'C' || input2 == 'c')
        {
            cout << "Enter the volume in liters: ";
            cin >> volume;
            volume = volume * 0.001;
            cout << "Volume in cubic meters is " << volume << "m3\n";
        }
        else {
            cout << "Invlaid Input!\n";
        }
    }
    else if (input1 == 'M' || input1 == 'm')
    {
        cout << "*******MASS CONVERSION*******\n";
        cout << "Type K for KILOGRAM TO POUNDS\n";
        cout << "Type T for TONNE TO KILOGRAM\n";
        cout << "Type G for GRAM TO OUNCE\n";
        cout << "Type P for POUND TO GRAM\n";
        cin >> input2;

        if (input2 == 'K' || input2 == 'k')
        {
            cout << "Enter the mass in kilograms: ";
            cin >> mass;
            mass = mass * 2.20462;
            cout << "Mass in Pounds is " << mass << "lb\n";
        }
        else if (input2 == 'T' || input2 == 't')
        {
            cout << "Enter the mass in tonnes: ";
            cin >> mass;
            mass = mass * 1000;
            cout << "Mass in kilograms is " << mass << "kg\n";
        }
        else if (input2 == 'G' || input2 == 'g')
        {
            cout << "Enter the mass in grams: ";
            cin >> mass;
            mass = mass * 0.00220462;
            cout << "Mass in Ounces is " << mass << "oz\n";
        }
        else if (input2 == 'P' || input2 == 'p')
        {
            cout << "Enter the mass in pounds: ";
            cin >> mass;
            mass = mass * 453.592;
            cout << "Mass in Grams is " << mass << "g\n";
        }
        else {
            cout << "Invalid Input!\n";
        }
    }
    else if (input1 == 'T' || input1 == 't')
    {
        cout << "*******TEMPERATURE CONVERSION*******\n";
        cout << "Type C for CELSIUS TO FAHRENHEIT\n";
        cout << "Type F for FAHRENHEIT TO CELSIUS\n";
        cin >> input2;

        if (input2 == 'C' || input2 == 'c')
        {
            cout << "Enter the temperature in Celsius: ";
            cin >> temperature;
            temperature = (temperature * 9/5) + 32;
            cout << "Temperature in Fahrenheit is " << temperature << "F\n";
        }
        else if (input2 == 'F' || input2 == 'f')
        {
            cout << "Enter the temperature in Fahrenheit: ";
            cin >> temperature;
            temperature = (temperature - 32) * 5/9;
            cout << "Temperature in Celsius is " << temperature << "C\n";
        }
        else {
            cout << "Invalid Input!\n";
        }
    }
    else{
        cout << "Invalid Input, Try again!\n";
    }

    cout << "Do you want to continue? (Y/N): ";
    cin >> input3;
    if (input3 == 'Y' || input3 == 'y')
    {
        goto beginning;
    }
    else if (input3 == 'N' || input3 == 'n')
    {
        cout << "You are done with the APK";
    }
    else {
        cout << "Invalid Input, Try again!\n";
    }
    
    cout << "------------------------------------\n";
    return 0;
}
