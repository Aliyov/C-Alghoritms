#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 21
#define MAX_ID_LEN 6
#define MAX_PRODUCT_LEN 21

typedef struct Product {
    char name[MAX_PRODUCT_LEN];
    int price;
    struct Product *next;
} Product;

typedef struct Producer {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    Product *products;
    struct Producer *next;
} Producer;

// Function prototypes
void addProducer(Producer **head, char *name, char *id);
Producer* findProducer(Producer *head, char *name);
void addProduct(Producer *head, char *id, char *productName, int price);
void printProducts(Producer *producer);
void printAffordableProducts(Producer *head, int budget);
void freeMemory(Producer *head);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <producer_file> <product_file> [budget]\n", argv[0]);
        return 1;
    }

    const char *producerFilename = argv[1];
    const char *productFilename = argv[2];
    int budget = -1;
    if (argc == 4) {
        budget = atoi(argv[3]);
    }

    FILE *producerFile = fopen(producerFilename, "r");
    FILE *productFile = fopen(productFilename, "r");

    if (!producerFile || !productFile) {
        perror("Error opening file");
        return 1;
    }

    Producer *producers = NULL;
    char producerName[MAX_NAME_LEN], producerId[MAX_ID_LEN];
    while (fscanf(producerFile, "%20s %5s", producerName, producerId) != EOF) {
        addProducer(&producers, producerName, producerId);
    }

    char productId[MAX_ID_LEN], productName[MAX_PRODUCT_LEN];
    int price;
    while (fscanf(productFile, "%5s %20s %d", productId, productName, &price) != EOF) {
        addProduct(producers, productId, productName, price);
    }

    fclose(producerFile);
    fclose(productFile);

    char query[MAX_NAME_LEN];
    printf("Enter manufacturer name: ");
    while (scanf("%20s", query) != EOF) {
        Producer *producer = findProducer(producers, query);
        if (producer) {
            printProducts(producer);
            if (budget >= 0) {
                printf("\nProducts within budget %d:\n", budget);
                printAffordableProducts(producers, budget);
            }
        } else {
            printf("Producer not found.\n");
        }
        printf("Enter manufacturer name: ");
    }

    freeMemory(producers);
    return 0;
}

void addProducer(Producer **head, char *name, char *id) {
    Producer *newProducer = (Producer *)malloc(sizeof(Producer));
    if (!newProducer) {
        perror("Failed to allocate memory for new producer");
        exit(1);
    }
    strncpy(newProducer->name, name, MAX_NAME_LEN);
    strncpy(newProducer->id, id, MAX_ID_LEN);
    newProducer->products = NULL;
    newProducer->next = *head;
    *head = newProducer;
}

Producer* findProducer(Producer *head, char *name) {
    Producer *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void addProduct(Producer *head, char *id, char *productName, int price) {
    Producer *current = head;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            Product *newProduct = (Product *)malloc(sizeof(Product));
            if (!newProduct) {
                perror("Failed to allocate memory for new product");
                exit(1);
            }
            strncpy(newProduct->name, productName, MAX_PRODUCT_LEN);
            newProduct->price = price;
            newProduct->next = current->products;
            current->products = newProduct;
            return;
        }
        current = current->next;
    }
}

void printProducts(Producer *producer) {
    printf("Products of %s:\n", producer->name);
    Product *current = producer->products;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->price);
        current = current->next;
    }
}

void printAffordableProducts(Producer *head, int budget) {
    Producer *currentProducer = head;
    while (currentProducer != NULL) {
        Product *currentProduct = currentProducer->products;
        while (currentProduct != NULL) {
            if (currentProduct->price <= budget) {
                printf("%s %d\n", currentProduct->name, currentProduct->price);
            }
            currentProduct = currentProduct->next;
        }
        currentProducer = currentProducer->next;
    }
}

void freeMemory(Producer *head) {
    while (head != NULL) {
        Product *currentProduct = head->products;
        while (currentProduct != NULL) {
            Product *tmpProduct = currentProduct;
            currentProduct = currentProduct->next;
            free(tmpProduct);
        }
        Producer *tmpProducer = head;
        head = head->next;
        free(tmpProducer);
    }
}
