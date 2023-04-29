//Dale King 4/17/23
//########################################################
//Chipotle Chat Bot - Data File - Nutrution Facts
//To be updated with sql functionality
//########################################################

#include <iostream>
#include <string>

using namespace std;

string getItem(int);
int getItemCal(int);
int getItemFat(int);
int getItemProtien(int);
int getItemCarb(int);

class Item 
{
    public:
        string name = "";
        int category;
        int cal = 0;
        int fat = 0;
        int protien = 0;
        int carbs = 0;

    bool operator==(const Item& rhs) const;

};

class Bowl
{
    public:
        Item ingredients[20];
        
        int getCal()
        {
            int cal = 0;
            for (int i = 0; i < 20; i++)
            {
                cal = ingredients[i].cal + cal;
            }

            return cal;
        }

        int getFat()
        {
            int fat = 0;
            for (int i = 0; i < 20; i++)
            {
                fat = ingredients[i].fat + fat;
            }

            return fat;
        }

        int getCarbs()
        {
            int carb = 0;
            for (int i = 0; i < 20; i++)
            {
                carb = ingredients[i].carbs + carb;
            }

            return carb;
        }

        int getProtien()
        {
            int protien = 0;
            for (int i = 0; i < 20; i++)
            {
                protien = ingredients[i].protien + protien;
            }

            return protien;
        }

        
};

string itemName[20] = 
{
"White Rice",
"Brown Rice",
"Black Beans",
"Pinto Beans",
"Chicken",
"Steak",
"Barbacoa",
"Carnitas",
"Sofritas",
"LTO // Chicken Al Pastor",
"Guacamole",
"Fresh Tomato Salsa",
"Roasted Chili-Corn Salsa",
"Tomatillo-Green Chili Salsa",
"Tomatillo-Red Chili Salsa",
"Sour Cream",
"Fajita Veggies",
"Cheese",
"Lettuce",
"Queso Balnco",

};
int itemNutrition[20][5] = 
{
    {210,4,4,40,1},
    {210,6,4,36,1},
    {130,2,8,22,2},
    {130,2,8,21,2},
    {180,7,32,0,3},
    {150,6,21,1,3},
    {170,7,24,2,3},
    {210,12,23,0,3},
    {150,10,8,9,3},
    {200,11,23,4,3},
    {230,22,2,8,4},
    {25,0,0,4,4},
    {80,2,3,16,4},
    {15,0,0,4,4},
    {30,0,0,4,4},
    {110,9,2,2,4},
    {20,0,1,5,4},
    {110,8,6,1,4},
    {5,0,0,1,4},
    {120,9,5,4,4},

};


/* old testing
    //Display Nutrition Contents

    //CALORIES | FAT | PROTIEN | CARBS

    
    
        for(int i = 0; i < 20; i++)
    {
        for(int k = 0; k<4; k++)
        {
            cout << itemNutrition[i][k];
            cout << " ";
        }
        cout << "\n";
    }

    
    

   //Display menu items
   
   for(int i = 0; i < 20; i++)
   {
    if(i % 5 == 0)
    {
        cout << "\n";
    }
        cout << itemName[i] << ", ";
   }
   

    //Displays each item and its nutriton
    
    for (int i = 0; i < 20; i++)
    {
        cout << itemName[i] << " ";
        for (int k = 0; k < 4; k++)
        {
            cout << itemNutrition[i][k] << ", ";
        }
        cout << "\n";
    }
    


    //testing getters
    
    cout << getItem(2) <<  " " << getItemCal(2);
    
*/

string getItem(int n)
{
    n = n-1;
    return itemName[n];
}

int getItemCal(int n)
{
    n = n - 1;
    switch(n)
    {
        case 0:
            return itemNutrition[n][0];
            break;
        case 1:
            return itemNutrition[n][0];
            break;
        case 2:
            return itemNutrition[n][0];
            break;
        case 3:
            return itemNutrition[n][0];
            break;
        case 4:
            return itemNutrition[n][0];
            break;
        case 5:
            return itemNutrition[n][0];
            break;
        case 6:
            return itemNutrition[n][0];
            break;
        case 7:
            return itemNutrition[n][0];
            break;
        case 8:
            return itemNutrition[n][0];
            break;
        case 9:
            return itemNutrition[n][0];
            break;
        case 10:
            return itemNutrition[n][0];
            break;
        case 11:
            return itemNutrition[n][0];
            break;
        case 12:
            return itemNutrition[n][0];
            break;
        case 13:
            return itemNutrition[n][0];
            break;
        case 14:
            return itemNutrition[n][0];
            break;
        case 15:
            return itemNutrition[n][0];
            break;
        case 16:
            return itemNutrition[n][0];
            break;
        case 17:
            return itemNutrition[n][0];
            break;
        case 18:
            return itemNutrition[n][0];
            break;
        case 19:
            return itemNutrition[n][0];
            break;
        default:
            return 0;
        
    }
}

int getItemFat(int n)
{
    n = n - 1;
    switch(n)
    {
        case 0:
            return itemNutrition[n][1];
            break;
        case 1:
            return itemNutrition[n][1];
            break;
        case 2:
            return itemNutrition[n][1];
            break;
        case 3:
            return itemNutrition[n][1];
            break;
        case 4:
            return itemNutrition[n][1];
            break;
        case 5:
            return itemNutrition[n][1];
            break;
        case 6:
            return itemNutrition[n][1];
            break;
        case 7:
            return itemNutrition[n][1];
            break;
        case 8:
            return itemNutrition[n][1];
            break;
        case 9:
            return itemNutrition[n][1];
            break;
        case 10:
            return itemNutrition[n][1];
            break;
        case 11:
            return itemNutrition[n][1];
            break;
        case 12:
            return itemNutrition[n][1];
            break;
        case 13:
            return itemNutrition[n][1];
            break;
        case 14:
            return itemNutrition[n][1];
            break;
        case 15:
            return itemNutrition[n][1];
            break;
        case 16:
            return itemNutrition[n][1];
            break;
        case 17:
            return itemNutrition[n][1];
            break;
        case 18:
            return itemNutrition[n][1];
            break;
        case 19:
            return itemNutrition[n][1];
            break;
        default:
            return 0;
        
    }
}

int getItemProtien(int n)
{
    n = n - 1;
    switch(n)
    {
        case 0:
            return itemNutrition[n][2];
            break;
        case 1:
            return itemNutrition[n][2];
            break;
        case 2:
            return itemNutrition[n][2];
            break;
        case 3:
            return itemNutrition[n][2];
            break;
        case 4:
            return itemNutrition[n][2];
            break;
        case 5:
            return itemNutrition[n][2];
            break;
        case 6:
            return itemNutrition[n][2];
            break;
        case 7:
            return itemNutrition[n][2];
            break;
        case 8:
            return itemNutrition[n][2];
            break;
        case 9:
            return itemNutrition[n][2];
            break;
        case 10:
            return itemNutrition[n][2];
            break;
        case 11:
            return itemNutrition[n][2];
            break;
        case 12:
            return itemNutrition[n][2];
            break;
        case 13:
            return itemNutrition[n][2];
            break;
        case 14:
            return itemNutrition[n][2];
            break;
        case 15:
            return itemNutrition[n][2];
            break;
        case 16:
            return itemNutrition[n][2];
            break;
        case 17:
            return itemNutrition[n][2];
            break;
        case 18:
            return itemNutrition[n][2];
            break;
        case 19:
            return itemNutrition[n][2];
            break;
        default:
            return 0;
        
    }
}

int getItemCarb(int n)
{
    n = n - 1;
    switch(n)
    {
        case 0:
            return itemNutrition[n][3];
            break;
        case 1:
            return itemNutrition[n][3];
            break;
        case 2:
            return itemNutrition[n][3];
            break;
        case 3:
            return itemNutrition[n][3];
            break;
        case 4:
            return itemNutrition[n][3];
            break;
        case 5:
            return itemNutrition[n][3];
            break;
        case 6:
            return itemNutrition[n][3];
            break;
        case 7:
            return itemNutrition[n][3];
            break;
        case 8:
            return itemNutrition[n][3];
            break;
        case 9:
            return itemNutrition[n][3];
            break;
        case 10:
            return itemNutrition[n][3];
            break;
        case 11:
            return itemNutrition[n][3];
            break;
        case 12:
            return itemNutrition[n][3];
            break;
        case 13:
            return itemNutrition[n][3];
            break;
        case 14:
            return itemNutrition[n][3];
            break;
        case 15:
            return itemNutrition[n][3];
            break;
        case 16:
            return itemNutrition[n][3];
            break;
        case 17:
            return itemNutrition[n][3];
            break;
        case 18:
            return itemNutrition[n][3];
            break;
        case 19:
            return itemNutrition[n][3];
            break;
        default:
            return 0;
        
    }
}

int getItemCategory(int n)
{
    n = n - 1;
    switch(n)
    {
        case 0:
            return itemNutrition[n][4];
            break;
        case 1:
            return itemNutrition[n][4];
            break;
        case 2:
            return itemNutrition[n][4];
            break;
        case 3:
            return itemNutrition[n][4];
            break;
        case 4:
            return itemNutrition[n][4];
            break;
        case 5:
            return itemNutrition[n][4];
            break;
        case 6:
            return itemNutrition[n][4];
            break;
        case 7:
            return itemNutrition[n][4];
            break;
        case 8:
            return itemNutrition[n][4];
            break;
        case 9:
            return itemNutrition[n][4];
            break;
        case 10:
            return itemNutrition[n][4];
            break;
        case 11:
            return itemNutrition[n][4];
            break;
        case 12:
            return itemNutrition[n][4];
            break;
        case 13:
            return itemNutrition[n][4];
            break;
        case 14:
            return itemNutrition[n][4];
            break;
        case 15:
            return itemNutrition[n][4];
            break;
        case 16:
            return itemNutrition[n][4];
            break;
        case 17:
            return itemNutrition[n][4];
            break;
        case 18:
            return itemNutrition[n][4];
            break;
        case 19:
            return itemNutrition[n][4];
            break;
        default:
            return 0;
        
    }
}
