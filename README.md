A vector<string> is used to store participant IDs because it allows dynamic resizing and efficient addition of new participants.
Exceptions
This file defines custom exceptions used to handle logical runtime errors in the system.
The stdexcept library is used to create standard, readable, and manageable runtime error classes.
Use of runtime_error
The runtime_error class is used for errors that occur during program execution.
Using map<string, Event> events
Because each event is managed by a unique identifier, and map provides fast lookup based on the event ID.

Using map<string, Participant> participants
To allow direct and efficient access to participants without iterating through the entire collection.

Including <map> and <vector>
To manage dynamic collections using standard STL containers instead of manual data structure implementations.

Including <algorithm>
To use standard functions such as std::sort and avoid implementing sorting algorithms manually.

Using map::find
For safe and efficient key lookup and to easily detect whether an element exists in the map.
Using sort with lambda expressions
To improve code readability and define custom sorting logic directly at the point of use.


