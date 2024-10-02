#include <stdio.h>
#include <stdlib.h>
#include "file.h"

Node* head = NULL;          
u8 PasswordFlag = false;
u8 ExitFlag = false;
u16 ListLength = 0;
u8* AvailableSlots[6] = {"2pm to 2:30pm", "2:30pm to 3pm", "3pm to 3:30pm", "4pm to 4:30pm", "4:30pm to 5pm", "Not Reserved"};
u8 ReservedSlots[6] = {0};

void AddPatient(void) {
    u8 flag = 0;
    u16 id;

    printf("Enter Patient's ID: "); fflush(stdout);
    scanf("%d", &id);

    if (ListLength == 0) {
        Node* temp = (Node*)malloc(sizeof(Node));
        printf("Enter Patient's Name: "); fflush(stdout);
        scanf("%s", temp->Name);
        printf("Enter Patient's age: "); fflush(stdout);
        scanf("%d", &temp->Age);
        printf("Enter Patient's Gender: "); fflush(stdout);
        scanf("%s", temp->Gender);
        temp->ID = id;
        temp->res = 5;
        temp->Next = head;
        head = temp;

        printf("New patient added successfully.\n\n");
    } else {
        Node* temp = (Node*)malloc(sizeof(Node));
        Node* Last = head;
        while (Last != NULL) {
            if (Last->ID == id) {
                flag = 1;
                break;
            }
            Last = Last->Next;
        }

        if (flag == 1) {
            printf("ID already exists.\n\n");
        } else {
            printf("Enter Patient's Name: "); fflush(stdout);
            scanf("%s", temp->Name);
            printf("Enter Patient's age: "); fflush(stdout);
            scanf("%d", &temp->Age);
            printf("Enter Patient's Gender: "); fflush(stdout);
            scanf("%s", temp->Gender);
            temp->ID = id;
            temp->res = 5;
            temp->Next = NULL;
            Last = head;
            while ((Last->Next) != NULL) {
                Last = Last->Next;
            }
            Last->Next = temp;
            printf("New patient added successfully.\n\n");
        }
    }
    ListLength++;
}

void EditPatient(void) {
    u8 flag = 0;
    u16 id;
    printf("Enter Patient's ID to Edit: "); fflush(stdout);
    scanf("%d", &id);
    if (ListLength == 0) {
        printf("No information available.\n\n");
    } else {
        Node* Last = head;
        while (Last != NULL) {
            if (Last->ID == id) {
                flag = 1;
                break;
            }
            Last = Last->Next;
        }
        if (flag == 1) {
            printf("Enter new information.\n");
            printf("Enter Patient's Name: "); fflush(stdout);
            scanf("%s", Last->Name);
            printf("Enter Patient's age: "); fflush(stdout);
            scanf("%d", &Last->Age);
            printf("Enter Patient's Gender: "); fflush(stdout);
            scanf("%s", Last->Gender);
            printf("Edit patient successfully.\n\n");
        } else {
            printf("Wrong ID.\n\n");
        }
    }
}

void ReserveSlot(void) {
    u16 id;
    Node *ptr = head;
    u16 pos = 0; // position of id
    u8 check = 0; // check if user can reserve or not
    u8 resv = 0;
    printf("\n\nEnter The Id To Reserve: "); fflush(stdout);
    scanf("%d", &id); // Taking id from user
    while (ptr != NULL) {
        if (ptr->ID == id) {
            pos++;
            break;
        }
        ptr = ptr->Next;
    } // end of while loop

    if (pos > 0) {
        for (u8 i = 0; i < 5; i++) {
            if (ReservedSlots[i] == 0)
                printf("%d- %s\n", i + 1, AvailableSlots[i]);
            else {
                check++;
            }
        }
        if (check >= 5) {
            printf("\nSorry, no available reservations!");
            return;
        } else {
            printf("\nYour choice: ");
            scanf("%d", &resv);
        }
        if (resv > 0 && resv <= 5) {
            ptr->res = resv - 1;
            ReservedSlots[resv - 1] = 1;
        } else
            printf("Wrong choice!");
    } else
        printf("Incorrect ID!");
}

void CancelReservation(void) {
    u16 id;
    Node *ptr = head;
    u16 pos = 0; // position of id

    printf("\n\nEnter The Id To Cancel Reserve: ");
    scanf("%d", &id); // Taking id from user
    while (ptr != NULL) {
        if (ptr->ID == id) {
            pos++;
            break;
        }
        ptr = ptr->Next;
    } // end of while loop

    if (pos > 0) {
        if (ReservedSlots[ptr->res] == 1) {
            printf("Your reservation: (%s) is cancelled \n", AvailableSlots[ptr->res]);
            ReservedSlots[ptr->res] = 0;
            ptr->res = 5;
        } else {
            printf("This ID didn't reserve!");
        }
    } else
        printf("Incorrect ID!");
}

void ViewRecord(void) {
    u8 flag = 0;
    u16 id;

    printf("Enter Patient's ID to View Record: "); fflush(stdout);
    scanf("%d", &id);
    if (ListLength == 0) {
        printf("No information available.\n\n");
    } else {
        Node* Last = head;
        while (Last != NULL) {
            if (Last->ID == id) {
                flag = 1;
                break;
            }
            Last = Last->Next;
        }
        if (flag == 1) {
            printf("Patient's Name: %s \n", Last->Name);
            printf("Patient's age: %d \n", Last->Age);
            printf("Patient's Gender: %s \n\n", Last->Gender);
        } else {
            printf("Wrong ID.\n\n");
        }
    }
}

void ViewReservation(void) {
    Node* Last = head;

    printf("All reservations: \n\n");

    if (ListLength == 0) {
        printf("No information available.\n\n");
    } else {
        while (Last != NULL) {
            if (Last->res == 5) {
                printf("Patient: (%s) with ID: (%d) has not reserved yet. \n\n", Last->Name, Last->ID);
            } else {
                printf("Patient: (%s) with ID: (%d) has reservation at (%s) \n\n", Last->Name, Last->ID, AvailableSlots[Last->res]);
            }
            Last = Last->Next;
        }
    }
}
