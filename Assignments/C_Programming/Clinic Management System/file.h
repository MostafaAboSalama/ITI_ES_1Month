#ifndef FILE_H
#define FILE_H

#define AdminPass 1234

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

typedef enum {
    false,
    true
} bool;

typedef struct Node_Type Node;

struct Node_Type {
    u8 Name[30];
    u8 Age;
    u8 Gender[30];
    u16 ID;
    u8 res;
    Node *Next;
};

extern Node* head;
extern u8 PasswordFlag;
extern u8 ExitFlag;
extern u16 ListLength;
extern u8* AvailableSlots[6];
extern u8 ReservedSlots[6];

void AddPatient(void);
void EditPatient(void);
void ReserveSlot(void);
void CancelReservation(void);
void ViewRecord(void);
void ViewReservation(void);

#endif // FILE_H
