/*#######################################################
DALE KING ~ Chippy, the chipotle chat bot.

Current functionalities: Talk to chippy about chipotle's nutritonal facts
                         Talk to chippy, creating your own bowl and learn about the nutrtional facts
                         Have chippy surprise you with a bowl just for you! and learn about the nutritonal facts

To be added: Talk to chippy about chiptole's "culture"
             Misspelling check
             Add other entrees other than bowl. (OBJECT -> ENTREE -> BOWL -> ITEM) (highearcy)
             


#######################################################*/




#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <stdio.h>
#include<vector>
#include<boost/algorithm/string.hpp>
#include "Nutrition.cpp"

using namespace std;

Bowl randomizer();
Bowl creator();
void perfectEntree();
void nutrtionInfo(string tm);
Item getWhich(string itemname);

string welcomeMessage = "Hello! I'm Chippy your virtual Chipotle assistant.\n"
                         "What can I get started for you?\n"
                         "1: Randomizer: Make a unique entree just for you.\n"
                         "2: Creator: Make your own entree.\n"
                         "3: Perfect Entree Maker: Talk to me about your tastes and I'll do the rest.\n"
                         "Or you can ask me about our nutrition or culture.\n";
                         
Item items[20];

string perfectBowlMessage = "Get ready for your taste buds to be blown away!\n"
                            "I'll make your bowl for you and all you have to do is tell me things you already like.\n"
                            "You can tell me anything, but if you're not sure what to say just ask, and i'll give you some tips!\n";

string perfectTips[20] =
{
   // "Tell me about your diet, are you Vegan? Keto?";
    //"Any allergies I should know about?";
    //"";
};

string triggerNutrition[5] =
{
    "cal",
    "calories",
    "fat",
    "carbs",
    "protien",
};

string keyPhrases[20] =
{
    //add phrases
    //prolly move to different file
};

int main()
{
    for (int i = 0; i < 20; i++)
    {
        items[i].name = getItem(i+1);
        items[i].cal = getItemCal(i+1);
        items[i].carbs = getItemCarb(i+1);
        items[i].category = getItemCategory(i+1);
        items[i].fat = getItemFat(i+1);
        items[i].protien = getItemProtien(i+1);
    }

    string userInput;
    vector<string> v;


    cout << welcomeMessage;
    
    //cout << items[0].name << " " << items[0].category;
    if(userInput == "randomizer")
        randomizer();

    if(userInput == "creator")
        creator();

    if(userInput == "perfect entree maker")
        perfectEntree();

    while(getline(cin, userInput) != "bye")
    {
    
        boost::split(v, userInput, boost::is_any_of(" "));
        for(int i = 0; i < v.size(); i ++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(v[i] == "how" and v[i+2] == triggerNutrition[j])
                {
                    for(int k = 0; k < v.size(); k++)
                    {
                        if(v[k] == "white")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "brown")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "black")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "pinto")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "chicken")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "steak")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "barbacoa")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "carnitas")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "sofritas")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "lto")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "guacamole" or v[k] == "guac")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "tomato" or v[k] == "mild")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "corn")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "green" or v[k] == "medium")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "red" or v[k] == "hot")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "sour")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "fajitas" or v[k] == "veggies")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "cheese")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "lettuce")
                            nutrtionInfo(v[k]);
                        else if(v[k] == "queso")
                            nutrtionInfo(v[k]);


                    }
                }
            }

            if(v[i] == "bowl") 
            {
                Bowl userBowl = creator();

                cout << "Great choice! Here's your bowl's nutrition:\n";
                cout << "Your bowl has " << userBowl.getCal() << " calories, " << userBowl.getFat() << " grams of fat, " << userBowl.getCarbs() << " grams of carbs, and " << userBowl.getProtien() << " grams of protien.";
            }

            if(v[i] == "surprise")
            {
                cout << "Heres what I've come up with for you:";
                Bowl randomBowl = randomizer();
                cout << "\nYour bowl has " << randomBowl.getCal() << " calories, " << randomBowl.getFat() << " grams of fat, " << randomBowl.getCarbs() << " grams of carbs, and " << randomBowl.getProtien() << " grams of protien.";
            }
        }
    } 
    

}


Bowl randomizer()
{
    //Generate random seed
    srand((unsigned)time(0)); 

    //Generate BOWL size
    int numIngredients = 0;
    int counter = 0;
    numIngredients = (rand()%12)+3; //alows a bowl with at most 15 ingredients (only 2 meats)
    Bowl bowl;

    //ingredients
    while (counter < numIngredients)
    {
        int numMeats = 0;
        int ingredient = 0;
        ingredient = (rand()%20)+1;
        Item item = items[ingredient];

        //check if item is already in bowl
        bool isInBowl = false;
        for (int i = 0; i < 20; i++)
        {
            //generates a number of ingredients MAX for a random bowl
            int k = 0;
            k = (rand()%20)+1; 
            for(int j = 0; j < numIngredients; j++)
            {
                //
                if(item.name == bowl.ingredients[j].name)
                {
                    isInBowl = true;
                }
                //keeps track of the number of meats in the bowl, allowing for max 2
                if(bowl.ingredients[j].category == 3)
                {
                    numMeats++;
                }
            }
            //if the item is in the bowl, find a new item
            if(isInBowl)
            continue;
            //not in the bowl? add the item and continue to generate the next
            else
            {
                if(numMeats >= 2 && item.category == 3)
                continue;
                else{
                    bowl.ingredients[counter] = item;
                    counter++;
                }
            }

        }

    }


    //prints bowl ingredients
    for(int i = 0; i < numIngredients; i++)
    {
        if(bowl.ingredients[i].name != "")
        {
            cout << "\n\t" << bowl.ingredients[i].name;
        }
    }
    //returns bowl full of items
    return bowl;


    


    /* BASIC REFERENCE LOGIC FOR ABOVE CODE
    Bowl bowl;

    srand((unsigned)time(0)); 

    for (int i = 0; i < 20; i++)
    {
        int k = 0;
        k = (rand()%20)+1; 
        bool it = false;
        for(int j = 0; j < 20; j++)
        {
            if(items[k].name == bowl.ingredients[j].name)
            {
                it = true;
            }
        }
        if (it != true)
        {
            bowl.ingredients[i] = items[k];
        }
    }

    for(int i = 0; i < 20; i++)
    {
        if(bowl.ingredients[i].name != "")
        {
            cout << "\n" << bowl.ingredients[i].name;
        }
    }

*/
}

Bowl creator()
{
    string userInput;
    int counter = 0;

    Bowl bowl;
    cout << "What kind of rice would you like?\n";
    getline(cin, userInput);
    if(userInput == "white")
    {
        bowl.ingredients[counter] = getWhich("white"); ///////////// LATER OPTMIZATION PULL FROM .name NOT A ARRAY LOCATION
        counter++;                            ///////////// ALLOWS FOR ADDING ITEMS MUCH EASIER
                                                // ***UPDATE*** ///// getwhich() returns an item given a string name, still could prolly be better
    }
    else if(userInput == "brown")
    {
        bowl.ingredients[counter] = getWhich("brown");
        counter++;
    }
    else if(userInput == "both")
    {
        bowl.ingredients[counter] = getWhich("white");
        counter++;
        bowl.ingredients[counter] = getWhich("brown");
        counter++;
    }
    //beans
    cout << "Would you like any beans?\n";
    getline(cin, userInput);
    if(userInput == "black")
    {
        bowl.ingredients[counter] = getWhich("black");
        counter++;
    }
    else if(userInput == "pinto")
    {
        bowl.ingredients[counter] = getWhich("pinto");
        counter++;
    }
    else if(userInput == "both")
    {
        bowl.ingredients[counter] = getWhich("black");
        counter++;
        bowl.ingredients[counter] = getWhich("pinto");
        counter++;
    }

    //meats (will add second meat option later once we get string parsing)
    cout << "And what would you like for your choice of protien?\n";
    getline(cin, userInput);

    if(userInput == "chicken")
    {
        bowl.ingredients[counter] = getWhich("chicken");
        counter++;
    }
    else if(userInput == "steak")
    {
        bowl.ingredients[counter] = getWhich("steak");
        counter++;
    }
    else if(userInput == "barbacoa")
    {
        bowl.ingredients[counter] = getWhich("barbacoa");
        counter++;
    }
    else if(userInput == "carnitas")
    {
        bowl.ingredients[counter] = getWhich("carnitas");
        counter++;
    }
    else if(userInput == "sofritas")
    {
        bowl.ingredients[counter] = getWhich("sofritas");
        counter++;
    }
    else if(userInput == "lto")
    {
        bowl.ingredients[counter] = getWhich("lto");
        counter++;
    }

    //queso or veggies
    cout << "would you like to add queso or veggies?\n";
    getline(cin, userInput);

    if(userInput == "queso")
    {
        bowl.ingredients[counter] = getWhich("queso");
        counter++;
    }
    else if(userInput == "veggies")
    {
        bowl.ingredients[counter] = getWhich("veggies");
        counter++;
    }
    else if(userInput == "both")
    {
        bowl.ingredients[counter] = getWhich("queso");
        counter++;
        bowl.ingredients[counter] = getWhich("veggies");
        counter++;
    }



    //salsas
    cout << "Would you like any salsas?\n";
    getline(cin, userInput);

    if(userInput == "mild")
    {
        bowl.ingredients[counter] = getWhich("mild");
        counter++;
    }
    else if(userInput == "medium")
    {
        bowl.ingredients[counter] = getWhich("medium");
        counter++;
    }
    else if(userInput == "hot")
    {
        bowl.ingredients[counter] = getWhich("hot");
        counter++;
    }
    else if(userInput == "mild and medium")
    {
        bowl.ingredients[counter] = getWhich("mild");
        counter++;
        bowl.ingredients[counter] = getWhich("medium");
        counter++;
    }
    else if(userInput == "mild and hot")
    {
        bowl.ingredients[counter] = getWhich("mild");
        counter++;
        bowl.ingredients[counter] = getWhich("hot");
        counter++;
    }
    else if(userInput == "medium and hot")
    {
        bowl.ingredients[counter] = getWhich("medium");
        counter++;
        bowl.ingredients[counter] = getWhich("hot");
        counter++;
    }
    else if(userInput == "all three")
    {
        bowl.ingredients[counter] = getWhich("mild");
        counter++;
        bowl.ingredients[counter] = getWhich("medium");
        counter++;
        bowl.ingredients[counter] = getWhich("hot");
        counter++;
    }


    //corn or sourcream
    cout << "Corn or Sour Cream?\n";
    getline(cin, userInput);


    if(userInput == "corn")
    {
        bowl.ingredients[counter] = getWhich("corn");
        counter++;
    }
    else if(userInput == "sour cream")
    {
        bowl.ingredients[counter] = getWhich("sour");
        counter++;
    }
    else if(userInput == "both")
    {
        bowl.ingredients[counter] = getWhich("corn");
        counter++;
        bowl.ingredients[counter] = getWhich("sour");
        counter++;
    }

    //cheese guac or lettuce?
    cout << "Cheese, Guac or Lettuce?\n";
    getline(cin, userInput);

    if(userInput == "cheese")
    {
        bowl.ingredients[counter] = getWhich("cheese");
        counter++;
    }
    else if(userInput == "guac")
    {
        bowl.ingredients[counter] = getWhich("guac");
        counter++;
    }
    else if(userInput == "lettuce")
    {
        bowl.ingredients[counter] = getWhich("lettuce");
        counter++;
    }
    else if(userInput == "cheese and guac")
    {
        bowl.ingredients[counter] = getWhich("cheese");
        counter++;
        bowl.ingredients[counter] = getWhich("guac");
        counter++;
    }
    else if(userInput == "cheese and lettuce")
    {
        bowl.ingredients[counter] = getWhich("cheese");
        counter++;
        bowl.ingredients[counter] = getWhich("lettuce");
        counter++;
    }
    else if(userInput == "guac and lettuce")
    {
        bowl.ingredients[counter] = getWhich("guac");
        counter++;
        bowl.ingredients[counter] = getWhich("lettuce");
        counter++;
    }
    else if(userInput == "all three")
    {
        bowl.ingredients[counter] = getWhich("cheese");
        counter++;
        bowl.ingredients[counter] = getWhich("guac");
        counter++;
        bowl.ingredients[counter] = getWhich("lettuce");
        counter++;
    }

    return bowl;

}

void perfectEntree()
{
    cout << "\n" << perfectBowlMessage;
}

void nutrtionInfo(string tm)
{
    Item itemGiven = getWhich(tm);
    cout << "Let me get that for you.\n" << "There is " << itemGiven.cal << " calories, " << itemGiven.fat << " grams of fat, " << itemGiven.carbs << " grams of carbs, and " << itemGiven.protien << " grams of protien in our " << itemGiven.name;     
        
    cout << "\n";
}

Item getWhich(string itemname)
{
    if(itemname == "white")
        return items[0];
    else if(itemname == "brown")
        return items[1];
    else if(itemname == "black")
        return items[2];
    else if(itemname == "pinto")
        return items[3];
    else if(itemname == "chicken")
        return items[4];
    else if(itemname == "steak")
        return items[5];
    else if(itemname == "barbacoa")
        return items[6];
    else if(itemname == "carnitas")
        return items[7];
    else if(itemname == "sofritas")
        return items[8];
    else if(itemname == "lto")
        return items[9];
    else if(itemname == "guacamole" or itemname == "guac")
        return items[10];
    else if(itemname == "tomato" or itemname == "mild")
        return items[11];
    else if(itemname == "corn")
        return items[12];
    else if(itemname == "green" or itemname == "medium")
        return items[13];
    else if(itemname == "red" or itemname == "hot")
        return items[14];
    else if(itemname == "sour")
        return items[15];
    else if(itemname == "fajitas" or itemname == "veggies")
        return items[16];
    else if(itemname == "cheese")
        return items[17];
    else if(itemname == "lettuce")
        return items[18];
    else if(itemname == "queso")
        return items[19];
    return items[0];
}
