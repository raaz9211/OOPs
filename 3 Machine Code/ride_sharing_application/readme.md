# Ride-Sharing Application - SDE II

## **Duration:** 2 hrs (90 min Coding + 30 min Review)

## **Description**
Implement a ride-sharing application with the expected features below.

---

## **Features**
- The application allows users to share rides on a route.
- Users can either:
  - **Offer a shared ride** (Driver)
  - **Consume a shared ride** (Passenger)
- Users can **search and select a ride** from multiple available rides with the same source and destination.

---

## **Requirements**
### **1️⃣ User Onboarding**
- `add_user(user_detail)`  
  - Adds basic user details.  
- `add_vehicle(vehicle_detail)`  
  - Adds a user’s vehicle(s) details.  

### **2️⃣ Offer a Shared Ride**
- `offer_ride(ride_detail)`
  - Ride will have:
    - Vehicle
    - Origin
    - Destination
    - Available Seats  
  - A ride will **not** have intermediate stops.  
  - A user can only offer a ride if there are **no active rides** for that vehicle.  

### **3️⃣ Select a Ride**
- `select_ride(source, destination, seats, selection_strategy)`
- A user can request a ride for **1 or 2 people**.
- **Selection Strategy:**
  - Preferred Vehicle (`Activa` / `Polo` / `XUV`)
  - Most Vacant Ride  

### **4️⃣ End a Ride**
- `end_ride(ride_details)`  
- A ride can only be offered again once the previous one ends.

### **5️⃣ Ride Statistics**
- `print_ride_stats()`
- Find total **rides offered** and **rides taken** by all users.

---

## **Bonus Feature (Optional)**
- If a direct ride is unavailable but possible via **multiple rides**, return multiple rides.
  - Example:  
    **Input:** `Bangalore -> Mumbai`  
    **Output:** `Bangalore -> Goa` and `Goa -> Mumbai`

---

## **Other Notes**
- Implement a **driver class** to execute all commands and run test cases.
- Use **in-memory data structures** (No database or NoSQL).
- **No UI** is required.
- Prioritize **code compilation, execution, and completion**.
- Focus on:
  - **Abstraction, modeling, separation of concerns**
  - **Modular, readable, and unit-testable code**
  - **Exception handling**
  - **Scalability for new features**

---

## **Sample Test Cases**

### **1️⃣ User Onboarding**
```plaintext
add_user(“Rohan, M, 36”)
add_vehicle(“Rohan, Swift, KA-01-12345”)

add_user(“Shashank, M, 29”)
add_vehicle(“Shashank, Baleno, TS-05-62395”)

add_user(“Nandini, F, 29”)

add_user(“Shipra, F, 27”)
add_vehicle(“Shipra, Polo, KA-05-41491”)
add_vehicle(“Shipra, Activa, KA-12-12332”)

add_user(“Gaurav, M, 29”)

add_user(“Rahul, M, 35”)
add_vehicle(“Rahul, XUV, KA-05-1234”)
```

---

### **2️⃣ Offer Rides**
```plaintext
offer_ride(“Rohan, Origin=Hyderabad, Available Seats=1, Vehicle=Swift, KA-01-12345, Destination=Bangalore”)

offer_ride(“Shipra, Origin=Bangalore, Available Seats=1, Vehicle=Activa, KA-12-12332, Destination=Mysore”)

offer_ride(“Shipra, Origin=Bangalore, Available Seats=2, Vehicle=Polo, KA-05-41491, Destination=Mysore”)

offer_ride(“Shashank, Origin=Hyderabad, Available Seats=2, Vehicle=Baleno, TS-05-62395, Destination=Bangalore”)

offer_ride(“Rahul, Origin=Hyderabad, Available Seats=5, Vehicle=XUV, KA-05-1234, Destination=Bangalore”)

offer_ride(“Rohan, Origin=Bangalore, Available Seats=1, Vehicle=Swift, KA-01-12345, Destination=Pune”)
```
❌ **This call should fail** (A ride is already active for this vehicle).  

---

### **3️⃣ Select Rides**
```plaintext
select_ride(“Nandini, Origin=Bangalore, Destination=Mysore, Seats=1, Most Vacant”)
✅ Expected Output: `2(c)`

select_ride(“Gaurav, Origin=Bangalore, Destination=Mysore, Seats=1, Preferred Vehicle=Activa”)
✅ Expected Output: `2(b)`

select_ride(“Shashank, Origin=Mumbai, Destination=Bangalore, Seats=1, Most Vacant”)
❌ Expected Output: `No rides found`

select_ride(“Rohan, Origin=Hyderabad, Destination=Bangalore, Seats=1, Preferred Vehicle=Baleno”)
✅ Expected Output: `2(d)`

select_ride(“Shashank, Origin=Hyderabad, Destination=Bangalore, Seats=1, Preferred Vehicle=Polo”)
❌ Expected Output: `No rides found`
```

---

### **4️⃣ End Rides**
```plaintext
end_ride(2-a)
end_ride(2-b)
end_ride(2-c)
end_ride(2-d)
```

---

### **5️⃣ Print Ride Statistics**
```plaintext
print_ride_stats()
```
✅ **Expected Output:**
```plaintext
Nandini: 1 Taken, 0 Offered  
Rohan: 1 Taken, 1 Offered  
Shashank: 0 Taken, 1 Offered  
Gaurav: 1 Taken, 0 Offered  
Rahul: 0 Taken, 0 Offered  
Shipra: 0 Taken, 2 Offered  
```


**Test input for console** 
```
Rohan M 36
Rohan Swift KA-01-12345
Rohan Swift KA-01-12345 Hyderabad 1 Bangalore
Raj Hyderabad 1 Bangalore Swift
```