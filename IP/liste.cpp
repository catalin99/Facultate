#include <iostream>

struct Node
{
    int value;
    Node* next;
};

// 1
void addEndNode(Node** root, int value)
{
    Node* toBeAdded = new Node;
    toBeAdded->value = value;
    toBeAdded->next = NULL;

    if (*root == NULL) {
        *root = toBeAdded;
        return;
    }

    Node* currentNode = *root;
    while (currentNode->next)
        currentNode = currentNode->next;

    currentNode->next = toBeAdded;
}

// 2
void printList(Node* root)
{
    std::cout << "Lista este: ";

    while (root) {
        std::cout << root->value << ' ';
        root = root->next;
    }

    std::cout << '\n';
}

// 3
int sumOddBetweenEven(Node* root)
{
    int sum = 0;

    if (!root || !root->next)
        return sum;

    while (root->next->next) {
        if (root->value % 2 == 0 && root->next->value % 2 && root->next->next->value % 2 == 0)
            sum += root->next->value;
        root = root->next;
    }

    return sum;
}

// 4
void addFrontNode(Node** root, int value)
{
    Node* toBeAdded = new Node;
    toBeAdded->value = value;
    toBeAdded->next = *root;

    *root = toBeAdded;
}

// 5
void deleteFrontNode(Node** root)
{
    if (*root) {
        Node* auxiliary = (*root)->next;
        delete *root;
        *root = auxiliary;
    }
}

// 6
int pairsOfCoprimes(Node* root)
{
    if (!root)
        return 0;

    int totalPairs = 0;

    while (root->next) {
        Node* second = root->next;

        while (second) {
            int auxiliary, left = root->value, right = second->value;

            while (left) {
                auxiliary = left;
                left = right % left;
                right = auxiliary;
            }

            if (right == 1)
                ++totalPairs;

            second = second->next;
        }

        root = root->next;
    }

    return totalPairs;
}

// 7
void insertBefore(Node** root, int valueToBeInserted, int element)
{
    if (!(*root))
        return;

    if ((*root)->value == element) {
        Node* toBeAdded = new Node;
        toBeAdded->value = valueToBeInserted;
        toBeAdded->next = *root;
        *root = toBeAdded;
        return;
    }

    Node* last = *root;
    while (last->next && last->next->value != element)
        last = last->next;

    if (!last->next)
        return;

    Node* toBeAdded = new Node;
    toBeAdded->value = valueToBeInserted;
    toBeAdded->next = last->next;

    last->next = toBeAdded;
}

// 8
void insertDoubleAfterEven(Node* root)
{
    while (root) {
        if (!(root->value % 2)) {
            Node* toBeAdded = new Node;
            toBeAdded->value = root->value * 2;
            toBeAdded->next = root->next;

            root->next = toBeAdded;
            root = toBeAdded->next;
        }
        else
            root = root->next;
    }
}

// 9
int listSize(Node* root)
{
    int totalElements = 0;

    while (root) {
        ++totalElements;
        root = root->next;
    }

    return totalElements;
}

// 10
int equalSubsequentPairs(Node* root)
{
    if (!root)
        return 0;

    int totalPairs = 0;

    while (root->next) {
        if (root->value == root->next->value)
            ++totalPairs;
        root = root->next;
    }

    return totalPairs;
}

// 11
void deleteAfter(Node* root, int element)
{
    while (root && root->value != element)
        root = root->next;

    if (!root || !root->next)
        return;

    if (root->next->next) {
        Node* afterDeletedElement = root->next->next;
        delete root->next;
        root->next = afterDeletedElement;
    }
    else {
        delete root->next;
        root->next = NULL;
    }
}

// 12
void deleteAt(Node** root, int element)
{
    if (!(*root))
        return;

    if ((*root)->value == element) {
        deleteFrontNode(root);
        return;
    }

    Node* currentNode = *root;

    while (currentNode->next && currentNode->next->value != element)
        currentNode = currentNode->next;

    if (!currentNode || !currentNode->next)
        return;

    if (currentNode->next->next) {
        Node* afterDeletedElement = currentNode->next->next;
        delete currentNode->next;
        currentNode->next = afterDeletedElement;
    }
    else {
        delete currentNode->next;
        currentNode->next = NULL;
    }
}

// 13
void deleteEvenElements(Node** root)
{
    if (!(*root))
        return;

    while (!((*root)->value % 2))
        deleteFrontNode(root);

    Node* currentNode = *root;

    while (true) {
        while (currentNode->next && currentNode->next->value % 2)
            currentNode = currentNode->next;

        if (!currentNode || !currentNode->next)
            return;

        if (currentNode->next->next) {
            Node* afterDeletedElement = currentNode->next->next;
            delete currentNode->next;
            currentNode->next = afterDeletedElement;
        }
        else {
            delete currentNode->next;
            currentNode->next = NULL;
        }
    }
}

// 14
void insertAfter(Node* root, int valueToBeInserted, int element)
{
    while (root && root->value != element)
        root = root->next;

    if (!root)
        return;

    Node* toBeAdded = new Node;
    toBeAdded->value = valueToBeInserted;
    toBeAdded->next = root->next;

    root->next = toBeAdded;
}

// 15
void insertDoubleBeforeEven(Node** root)
{
    if (!(*root))
        return;

    Node* currentNode = *root;

    if (!((*root)->value % 2)) {
        Node* toBeAdded = new Node;
        toBeAdded->value = (*root)->value * 2;
        toBeAdded->next = *root;
        *root = toBeAdded;
    }

    while (currentNode->next) {
        if (!(currentNode->next->value % 2)) {
            Node* toBeAdded = new Node;
            toBeAdded->value = currentNode->next->value * 2;
            toBeAdded->next = currentNode->next;

            currentNode->next = toBeAdded;
            currentNode = toBeAdded->next;
        }
        else
            currentNode = currentNode->next;
    }
}

// 16
void ascendingSort(Node** root)
{
    if (!(*root))
        return;

    Node* sortedList = NULL;

    while (*root) {
        Node* currentNode = *root;
        int minValue = currentNode->value;

        while (currentNode) {
            if (currentNode->value < minValue)
                minValue = currentNode->value;
            currentNode = currentNode->next;
        }

        addEndNode(&sortedList, minValue);
        deleteAt(root, minValue);
    }

    *root = sortedList;
}

int main()
{
    Node* root = NULL;

    int totalElements = 0;
    std::cout << "Introduceti numarul de elemente al listei: ";
    std::cin >> totalElements;

    for (int index = 0, element; index < totalElements; ++index) {
        std::cout << "Introduceti un element la sfarsitul listei: ";
        std::cin >> element;
        addEndNode(&root, element);
    }

    printList(root);

    std::cout << "Suma elementelor impare care sunt situate intre doua elemente pare: " << sumOddBetweenEven(root) << '\n';

    std::cout << "Introduceti numarul de elemente ce vor fi adaugate la inceputul listei: ";
    std::cin >> totalElements;

    for (int index = 0, element; index < totalElements; ++index) {
        std::cout << "Introduceti un element la inceputul listei: ";
        std::cin >> element;
        addFrontNode(&root, element);
    }

    printList(root);

    std::cout << "Introduceti de cate ori sa se elimine primul element al listei: ";
    std::cin >> totalElements;

    for (int index = 0; index < totalElements; ++index)
        deleteFrontNode(&root);

    printList(root);

    std::cout << "Numarul de perechi de elemente prime intre ele: " << pairsOfCoprimes(root) << '\n';

    std::cout << "Introduceti numarul de elemente ce vor fi adaugate: ";
    std::cin >> totalElements;

    for (int index = 0, value, element; index < totalElements; ++index) {
        std::cout << "Introduceti o valoare: ";
        std::cin >> value;
        std::cout << "Introduceti elementul in spatele caruia va fi plasata valoarea citita anterior: ";
        std::cin >> element;
        insertBefore(&root, value, element);
    }

    printList(root);

    std::cout << "Se insereaza dupa fiecare element par dublul sau. ";
    insertDoubleAfterEven(root);

    printList(root);

    std::cout << "Numarul de elemente ale listei este acum: " << listSize(root) << '\n';
    std::cout << "Numarul de perechi de elemente consecutive egale este: " << equalSubsequentPairs(root) << '\n';

    std::cout << "Introduceti numarul de elemente ce vor fi sterse: ";
    std::cin >> totalElements;

    for (int index = 0, element; index < totalElements; ++index) {
        std::cout << "Introduceti un element. Cel situat dupa acesta va fi sters: ";
        std::cin >> element;
        deleteAfter(root, element);
    }

    printList(root);

    std::cout << "Introduceti numarul de elemente ce vor fi sterse: ";
    std::cin >> totalElements;

    for (int index = 0, element; index < totalElements; ++index) {
        std::cout << "Introduceti elementul PE CARE doriti sa-l stergeti: ";
        std::cin >> element;
        deleteAt(&root, element);
    }

    printList(root);

    std::cout << "Se sterg elementele pare din lista. ";
    deleteEvenElements(&root);

    printList(root);

    std::cout << "Introduceti numarul de elemente ce vor fi adaugate: ";
    std::cin >> totalElements;

    for (int index = 0, value, element; index < totalElements; ++index) {
        std::cout << "Introduceti o valoare: ";
        std::cin >> value;
        std::cout << "Introduceti elementul in fata caruia va fi plasata valoarea citita anterior: ";
        std::cin >> element;
        insertAfter(root, value, element);
    }

    printList(root);

    std::cout << "Se insereaza inainte de fiecare element par dublul sau. ";
    insertDoubleBeforeEven(&root);

    printList(root);

    std::cout << "Se sorteaza lista crescator: ";
    ascendingSort(&root);

    printList(root);
    return 0;
}
