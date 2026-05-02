# Car Rental System

## Overview
This project implements a simple car rental system using C++.
It allows users to rent, return, and view cars, and get recommendations.

---

## How to Run

g++ pj.cpp -o pj2
./pj2

---

UML (please view the edit/code/blame mode for the correct verson)

##Class Diagram

        Car
-------------------------
- name
- type
- available
- startDate
- endDate
-------------------------
+ display()
+ rent()
+ giveBack()

        ▲
        │
 ┌──────┼──────┐
 │      │      │
Sedan   SUV   Truck


CarRentalSystem
-------------------------
- cars
- history
-------------------------
   + listCars()
 + rentCar()
+ returnCar()
+ sortCars()
+ showRecommendation()

---

Use Case

User → View Cars  
User → Rent Car  
User → Return Car  
User → Get Recommendation
