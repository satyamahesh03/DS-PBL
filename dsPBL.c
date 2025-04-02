#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent product details
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Function to display product details
void displayProduct(Product product) {
    printf("\n======================================\n");
    printf(" Product ID      : %d\n", product.id);
    printf(" Product Name    : %s\n", product.name);
    printf(" Product Price   : ₹%.2f\n", product.price);
    printf(" Product Quantity: %d\n", product.quantity);
    printf("======================================\n");
}

// Function to add product
int addProduct(Product products[], int n) {
    Product newProduct;
    printf("\nEnter Product Details:\n");
    printf("-----------------------\n");
    printf("Enter Product ID: ");
    scanf("%d", &newProduct.id);
    getchar(); // Clear newline from buffer

    printf("Enter Product Name: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Remove newline

    printf("Enter Product Price: ");
    while (scanf("%f", &newProduct.price) != 1 || newProduct.price < 0) {
        printf("Invalid input. Enter a valid price: ");
        while (getchar() != '\n'); // Clear buffer
    }

    printf("Enter Product Quantity: ");
    while (scanf("%d", &newProduct.quantity) != 1 || newProduct.quantity < 0) {
        printf("Invalid input. Enter a valid quantity: ");
        while (getchar() != '\n'); // Clear buffer
    }

    products[n] = newProduct;
    n++;
    printf("\n✅ Product added successfully!\n");
    return n;
}

// Function to find product by ID
int findProduct(Product products[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to update product details
void updateProduct(Product products[], int n) {
    int id, index;
    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);
    index = findProduct(products, n, id);
    if (index == -1) {
        printf("\n❌ Product not found.\n");
        return;
    }
    getchar(); // Clear buffer

    printf("\nEnter New Details for Product ID %d:\n", id);
    printf("Enter Product Name: ");
    fgets(products[index].name, sizeof(products[index].name), stdin);
    products[index].name[strcspn(products[index].name, "\n")] = '\0'; // Remove newline

    printf("Enter Product Price: ");
    while (scanf("%f", &products[index].price) != 1 || products[index].price < 0) {
        printf("Invalid input. Enter a valid price: ");
        while (getchar() != '\n'); // Clear buffer
    }

    printf("Enter Product Quantity: ");
    while (scanf("%d", &products[index].quantity) != 1 || products[index].quantity < 0) {
        printf("Invalid input. Enter a valid quantity: ");
        while (getchar() != '\n'); // Clear buffer
    }

    printf("\n✅ Product updated successfully!\n");
}

// Function to delete product by ID
int deleteProduct(Product products[], int n) {
    int id, index;
    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);
    index = findProduct(products, n, id);
    if (index == -1) {
        printf("\n❌ Product not found.\n");
        return n;
    }
    for (int i = index; i < n - 1; i++) {
        products[i] = products[i + 1];
    }
    n--;
    printf("\n✅ Product deleted successfully!\n");
    return n;
}

int main() {
    int n = 0;
    Product products[100];
    int choice;
    while (1) {
        printf("\n======================================\n");
        printf("         PRODUCT MANAGEMENT SYSTEM    \n");
        printf("======================================\n");
        printf("1️⃣  Add Product\n");
        printf("2️⃣  Display Products\n");
        printf("3️⃣  Update Product\n");
        printf("4️⃣  Delete Product\n");
        printf("5️⃣  Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                n = addProduct(products, n);
                break;
            case 2:
                if (n == 0) {
                    printf("\nℹ️ No products available.\n");
                } else {
                    for (int i = 0; i < n; i++) {
                        displayProduct(products[i]);
                    }
                }
                break;
            case 3:
                updateProduct(products, n);
                break;
            case 4:
                n = deleteProduct(products, n);
                break;
            case 5:
                printf("\n🚀 Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\n❌ Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
