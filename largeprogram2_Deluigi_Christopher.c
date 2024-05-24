//Christopher Deluigi
//Dr. Steinberg
//COP3223C Section 1
//Large Program 2

#include<stdio.h>
#include <ctype.h>

void greeting(); //welcome the user
void order(double *balance); //user will make a purchase
void viewHand(double *balance); //display current amount in hand
void transaction(double *balance, double price); //transaction with user
void pullMoney(double *balance); //grab more money from the unlimited ←-wallet 
void displayVendingOptions(); //display beverage options and prices

int main()
{  
    double money_left = 0.0; //delcares variable and sets to 0
    greeting(); //calls the greeting function
    char user_optionL = 'z'; //creates new variable  for user inputed option as a char and auto set it to z so while loop starts
    while(user_optionL != 'e') //loops runs until e is inputed and then program ends
    {
        printf("Please select one of the following options.\n"); //provides user with options at the vending machine
        printf("O: Order from the unlimited vending machine.\n");
        printf("V: View what you have in your hand currently.\n");
        printf("D: Display what the unlimited vending machine contains.\n");
        printf("G: Grab money out of unlimited wallet\n");
        printf("E: Exit\n");
        printf("*****************************************************\n");
        printf("Please select what you would like to do.\n");
        printf("\n");
        printf("Option Selected: "); //takes in user option as a char under user_optionL
        scanf(" %c", &user_optionL);
        
        switch (tolower(user_optionL)) //checks to see if user input is valid and then auto converts to lowercase in the before the switch
        {
            case 'o': 
                printf("You have selected to order something from the unlimited vending machine.\n"); //switch checks if user input matches and if it does it calls the order with passing variable money_left with it, starts ordering process
                order(&money_left);
                printf("*****************************************************\n");
                printf("*****************************************************\n");
                break;

            case 'v':
                printf("You selected to see how much cash you have in your hand currently.\n");//switch checks if user input matches and if it does it calls the viewHand with passing variable money_left with it, check how much money they have
                viewHand(&money_left);
                printf("*****************************************************\n");
                printf("*****************************************************\n");
                break;

            case 'd':
                printf("You selected the view vending machine option.\n"); //switch checks if user input matches and if it does it calls the displayVendingOptions, which shows menu
                displayVendingOptions();
                printf("*****************************************************\n");
                printf("*****************************************************\n");
                break;

            case 'g':
                printf("You have selected to pull more money out of the unlimited wallet.\n"); //switch checks if user input matches and if it does it calls the pullMoney with passing variable money_left with it, gives user more money
                pullMoney(&money_left);
                printf("*****************************************************\n");
                printf("*****************************************************\n");
                break;

            case 'e':
                printf("Thank you for visiting the unlimited vending machine!\n"); //switch checks if user input matches and if it does it prints exit message with amount of money user has at time of exit
                printf("*****************************************************\n");
                printf("You have $%0.2lf in your hand. Make sure to put that back into your unlimited wallet.\n", money_left);
                printf("Have a great day!\n");
                user_optionL == 'e';
                break;

                default: //if user enters something not listed, wont work and has to input again
                printf("Invalid Option.");
                break;
        }
        
    }
    ///////////////////////

    return 0;
}
void greeting() //Sets up welcome message and rules
{
    printf("Welcome to the Unlimited Vending Machine\n");
    printf("We have an unlimted variety of drinks.\n");
    printf("With your unliminted wallet, you will never run out of cash!\n");
    printf("What would you like to order today?\n");
    printf("*****************************************************\n");
}
void displayVendingOptions() //prints and shows user the menu options with price
{
    printf("Here are the options!\n");
    printf("*****************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
}

void order(double *balance) //process users order when they order an item
{
    int vending_option; //new variable  for users input on menu options
    printf("*****************************************************\n");
    displayVendingOptions(); //trigger menu to print from function being called
    printf("What would you like today?\n"); //asks user for selection
    printf("Option Selected: "); //takes in user input to select an item and save it into variable vending_option
    scanf("%d", &vending_option);
    switch(vending_option) //runs switch statement and if case matches the item is pritned and balnce is updated
    {
        case 1:
            printf("Sprite has been selected. Total cost is: $2.50\n");//runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 2.50);
            break;
        case 2:
            printf("Coca-Cola has been selected. Total cost is: $2.50\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 2.50);
            break;
        case 3:
            printf("Water has been selected. Total cost is: $2.00\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 2.00);
            break;
        case 4:
            printf("Gatoradea has been selected. Total cost is: $3.00\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 3.00); 
            break;
        case 5:
            printf("Diet Cola has been selected. Total cost is: $2.55\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 2.55);
            break;
        case 6:
            printf("Fanta has been selected. Total cost is: $2.55\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 2.55);
            break;
        case 7:
            printf("Root Beer has been selected. Total cost is: $1.50\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 1.50);
            break;
        case 8:
            printf("Dr. Pepper has been selected. Total cost is: $1.55\n"); //runs switch statement and if case matches the item is pritned and balnce is updated by calling function transaction with balance and value of item
            transaction(balance, 1.55);
            break;
    }
}

void viewHand(double *balance) //checks to see how much money user has
{
    printf("*****************************************************\n");
    printf("You have $%0.2lf in your hand currently.\n", *balance); //prints how much money they have left
}
void pullMoney(double *balance) //function to get more money
{
    double x = 1; //variable  created and sent to 1
    int amount_pulled; //ariable crearted for amount user wantsto get
    while(x == 1) //loop auto runs since x is 1 since it was defined already
    {
        printf("How much would you like to pull from the unlimited wallet?\n"); //prints denomination of amount available  for user to select
        printf("1:$1.00\n");
        printf("2:$5.00\n");
        printf("3:$10.00\n");
        printf("Option Selected: "); //saves users option in variable amount_pulled
        scanf("%d", &amount_pulled);
        switch(amount_pulled)
        {
            case 1: //depending on users option balance is updated with denomination they chose
                (*balance)+= 1.00;
                x = 0;
                break;
            
            case 2:
                (*balance)+= 5.00; //depending on users option balance is updated with denomination they chose
                x = 0;
                break;
            
            case 3:
                (*balance)+= 10.00; //depending on users option balance is updated with denomination they chose
                x = 0;
                break;

            default:
                printf("Invalid option.\n"); //if user choses something thats not available they must re-enter 
                break;
        }
    }
    printf("$%.2lf has been added to your hand successfully!\n", *balance); // once user gets money added to balance, new print statement prints showing their new balance
}

void transaction(double *balance, double price) //checks to see if user has enough money for purchase
{
    if(*balance < price) //if user doesnt have enough then if statement continues , if they do then print statement for pruchase prints and updated balance is printed
    {
        while(*balance < price) //loop runs while user doesnt have enough for purchase, once they do loop finishes
        {
            printf("Beginning Transaction Process.\n"); //prints statement for transaction
            printf("You do not have enough in your account.\n");
            printf("Please pull more money from the unlimited wallet.\n"); //if user doesnt have enough then function pullMoney(balance) is called to get the user more money
            pullMoney(balance);
        }
    }
    printf("You have $%.2lf in your hand before transaction.\n", *balance); //ones user has enough print statement is ran for amount of money before the purchase
    *balance -= price; //updates balance after purchase
    printf("Putting $%.2lf into the vending machine.\n", price); 
    printf("Transaction was successful!\n");
    printf("You now have $%.2lf in your hand.\n", *balance); //statement showing how much they have left after purchase
}