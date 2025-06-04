#include <stdio.h>


#define MAX_ROOMS 10
#define ROOM_AVAILABLE 0
#define ROOM_BOOKED 1

typedef struct {
int roomNumber;
int status; 
char guestName[50];
float billAmount;
} 
Room;

Room hotelRooms[MAX_ROOMS];

void initializeRooms()
{
for (int i = 0; i < MAX_ROOMS; i++) 
    {
hotelRooms[i].roomNumber = i + 1;
hotelRooms[i].status = ROOM_AVAILABLE;
strcpy(hotelRooms[i].guestName, "");
hotelRooms[i].billAmount = 0.0;
    }
}
void displayAvailableRooms()
{
printf("\nAvailable Rooms:\n");
for (int i = 0; i < MAX_ROOMS; i++)
{
if (hotelRooms[i].status == ROOM_AVAILABLE)
{
printf("Room %d\n", hotelRooms[i].roomNumber);
}
}
}
void bookRoom() 
{
int roomNum;
char guestName[50];

displayAvailableRooms();

printf("Enter the room number to book: ");
scanf("%d", &roomNum);

 if (roomNum <= 0 || roomNum > MAX_ROOMS)
{
printf("Invalid room number.\n");
return;
 }

if (hotelRooms[roomNum - 1].status == ROOM_BOOKED)
{
printf("Room is already booked.\n");
return;
}
    printf("Enter guest name: ");
    scanf(" %[^\n]s", guestName);

    hotelRooms[roomNum - 1].status = ROOM_BOOKED;
    strcpy(hotelRooms[roomNum - 1].guestName, guestName);
    printf("Room %d booked for %s.\n", roomNum, guestName);
}
void displayRoomStatus()
{
printf("\nRoom Status:\n");
for (int i = 0; i < MAX_ROOMS; i++)
{
printf("Room %d: ", hotelRooms[i].roomNumber);
if (hotelRooms[i].status == ROOM_AVAILABLE)
{
printf("Available\n");
} else {
printf("Booked by %s, Bill: %.2f\n", hotelRooms[i].guestName, hotelRooms[i].billAmount);
}
}
}
void checkoutRoom() {
int roomNum;

printf("Enter room number to checkout: ");
scanf("%d", &roomNum);

if (roomNum <= 0 || roomNum > MAX_ROOMS) 
{
printf("Invalid room number.\n");
return;
}

if (hotelRooms[roomNum - 1].status == ROOM_AVAILABLE) 
{
printf("Room is not booked.\n");
return;
}

printf("Checkout completed for room %d. Total bill: %.2f\n", roomNum, hotelRooms[roomNum - 1].billAmount);
hotelRooms[roomNum - 1].status = ROOM_AVAILABLE;
strcpy(hotelRooms[roomNum - 1].guestName, "");
hotelRooms[roomNum - 1].billAmount = 0.0;
}


int main() {
initializeRooms();
int choice;

do {
printf("\n===Hotel Management System===\n");
printf("1. Display Available Rooms\n");
printf("2. Book a Room\n");
printf("3. Display Room Status\n");
printf("4. Checkout Room\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
displayAvailableRooms();
break;
case 2:
bookRoom();
 break;
case 3:
displayRoomStatus(); 
break;
case 4:
checkoutRoom();
break;
case 5:
printf("Exiting the application.\n");
break;
default:
printf("Invalid choice.\n");
}
} while (choice != 5);
return 0;
}