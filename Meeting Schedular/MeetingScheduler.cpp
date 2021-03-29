#include<bits/stdc++.h>
using namespace std;

class Slot
{
    int startTime;
    int endTime; 
public:
    Slot(){
        startTime=0;
        endTime=0;
    };
    Slot(int,int);
    int getStartTime() const { return startTime;}
    int getEndTime() const { return endTime; }
};
class Meeting
{
    Slot slot;
    string room;
public:
    Meeting(){
        slot = Slot{};
        room = "";
    };
    void NewMeeting(Slot, string);
};
typedef vector<Slot> Calendar;
class Room
{
    string roomName;
    Calendar calendar;

public:
    Room(string);
    string getRoomName() const { return roomName; }
    void addSlot(Slot slot) { calendar.push_back(slot); }
    Calendar getCalendar() { return calendar; }
};
typedef vector<Room> Rooms;
typedef vector<Meeting> Meetings;
class ScheduleMeeting
{
    Rooms rooms;
    Meetings meetings;

public:
    ScheduleMeeting(Rooms);
    string BookMeeting(Slot);
    string BookMeeting(Slot, string);

};
Slot::Slot(int startTime,int endTime)
{
    this->endTime = endTime;
    this->startTime = startTime;
}
Room::Room(string roomName)
{
    this->roomName = roomName;
}
ScheduleMeeting::ScheduleMeeting(Rooms rooms){
    this->rooms = rooms;
}

bool isSlotAvailable(Slot slot, Calendar calendar)
{
    for(Slot cal: calendar){
        if(slot.getStartTime() <= cal.getEndTime() && slot.getStartTime() >= cal.getStartTime() && slot.getEndTime() >= cal.getStartTime() && slot.getEndTime() <= cal.getEndTime())   
            return false;
    }
    return true;
}
void Meeting::NewMeeting(Slot slot, string roomName){
    this->slot = slot;
    this->room = roomName;
}

string ScheduleMeeting::BookMeeting(Slot slot) 
{
    for(Room &room : rooms){
        if(isSlotAvailable(slot, room.getCalendar())){
            room.addSlot(slot);
            Meeting M1;
            M1.NewMeeting(slot, room.getRoomName());
            meetings.push_back(M1);
            return room.getRoomName();
        }
    }
    return " No room available for this slot.";
}

string ScheduleMeeting::BookMeeting(Slot slot, string roomName) 
{
    for(Room &room : rooms){
        if(room.getRoomName() == roomName){
            if(isSlotAvailable(slot, room.getCalendar())){
                room.addSlot(slot);
                Meeting M1;
                M1.NewMeeting(slot, roomName);
                meetings.push_back(M1);
                return roomName;
            }
            else return "Room already booked. Try other room or just give time slot to book any available room.";
        }
    }
    return "No such room present"; 
}

int main(){
    Slot s1(600, 700), s2(1800,1900);
    Room R1("100"), R2("200"), R3("400");
    Rooms R{R1, R2, R3};
    ScheduleMeeting Schedular(R);
    cout<<Schedular.BookMeeting(s1, R1.getRoomName())<<endl;
    cout<<Schedular.BookMeeting(s1, R1.getRoomName())<<endl;
    cout<<Schedular.BookMeeting(s1)<<endl;
    cout<<Schedular.BookMeeting(s1)<<endl;
    cout<<Schedular.BookMeeting(s2, "300")<<endl;
    cout<<Schedular.BookMeeting(s2)<<endl;
    cout<<Schedular.BookMeeting(s2, R1.getRoomName())<<endl;
    cout<<Schedular.BookMeeting(s2, R2.getRoomName())<<endl;
    cout<<Schedular.BookMeeting(s1)<<endl;
    return 0;
}