# Ride Sharing App

There are two cases here:
1. User can't create multiple rides.
2. User can create multiple rides.

Ride sharing application where drivers can offer rides (origin, destination, no of seats), any rider
can request rides (origin, destination, no of seats).
There is an algo to choose to calculate Ride amount charged for a given ride based on distance and no of
seats
1. When the ride closes, show the amount charged to the rider.
2. Ride amount if No of seats >= 2 : No of kilometers * No of seats * 0.75 * Amount Charged per KM
3. Ride amount if No of seats = 1 : No of kilometers * Amount Charged per KM
4. The rider is a preferred rider if he has done more than 10 rides.
5. Preferred Rider amount if No of seats >= 2 : No of kilometers * No of seats * 0.5 * Amount Charged per KM
6. Preferred Ride amount if No of seats = 1 : No of kilometers * Amount Charged per KM * 0.75

The program take input as drivers and a set of riders requesting rides. Multiple rides
can happen simultaneously.

Assumptions :
1. Assume Amount charged per KM = 20
2. No of Kilometers = destination - origin
3. All values are Integer

Functionalities:
1. Driver(name)
2. Rider(name)
3. Create Ride (id, origin, destination, no of seats)
4. Create/Update Ride (id, origin, destination, no of seats)
5. Withdraw Ride (id)
6. Close ride and return ride amount charged

