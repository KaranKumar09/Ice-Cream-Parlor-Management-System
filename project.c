#include <stdio.h>
#include <string.h>

// Struct to represent an ice cream
struct IceCream {
    char flavor[20];
    float price;
};

// Struct to represent the ice cream parlor
struct IceCreamParlor {
    struct IceCream menu[10]; // Maximum 10 menu items
    int numMenuItems; // Number of menu items
    struct IceCream orders[10]; // Maximum 10 orders
    int numOrders; // Number of orders
};

// Function to add an item to the menu
void add_item_to_menu(struct IceCreamParlor *parlor, char flavor[20], float price) {
    if (parlor->numMenuItems < 10) {
        struct IceCream iceCream;
        strcpy(iceCream.flavor, flavor);
        iceCream.price = price;
        parlor->menu[parlor->numMenuItems++] = iceCream;
        printf("Successfully added %s to the menu!\n", flavor);
    } else {
        printf("Error: Maximum menu items reached.\n");
    }
}

// Function to place an order
void place_order(struct IceCreamParlor *parlor, char flavor[20]) {
    int found = 0;
    int i;
    for ( i = 0; i < parlor->numMenuItems; i++) {
        if (strcmp(parlor->menu[i].flavor, flavor) == 0) {
            parlor->orders[parlor->numOrders++] = parlor->menu[i];
            printf("Successfully added %s to your order!\n", flavor);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, %s is not available in the menu.\n", flavor);
    }
}

// Function to view the menu
void view_menu(struct IceCreamParlor *parlor) {
    printf("Menu:\n");
    int i;
    for (i = 0; i < parlor->numMenuItems; i++) {
        printf("%s: $%.2f\n", parlor->menu[i].flavor, parlor->menu[i].price);
    }
}

// Function to calculate total cost
float calculate_total_cost(struct IceCreamParlor *parlor) {
    float total_cost = 0;
    int i;
    for (i = 0; i < parlor->numOrders; i++) {
        total_cost += parlor->orders[i].price;
    }
    return total_cost;
}

// Function to view orders
void view_orders(struct IceCreamParlor *parlor) {
    printf("Order Details:\n");
    int i;
    for (i = 0; i < parlor->numOrders; i++) {
        printf("%d. %s: $%.2f\n", i + 1, parlor->orders[i].flavor, parlor->orders[i].price);
    }
}

int main() {
    struct IceCreamParlor parlor;
    parlor.numMenuItems = 0;
    parlor.numOrders = 0;

    // Adding menu items
    add_item_to_menu(&parlor, "Vanilla", 1.99);
    add_item_to_menu(&parlor, "Chocolate", 2.49);
    add_item_to_menu(&parlor, "Strawberry", 2.99);

    // Placing orders
    place_order(&parlor, "Vanilla");
    place_order(&parlor, "Strawberry");
   

