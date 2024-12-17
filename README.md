# Project Overview
# What was the problem you were solving in the projects for this course?
The problem I aimed to solve in this project was to create a course planner program that allows users to load course data, display a sorted list of courses in alphanumeric order, and print detailed information about a specific course, including its prerequisites. The key focus was implementing data structures effectively to organize, access, and present the data efficiently.

# How did you approach the problem?
I used the map data structure, which automatically sorts keys in alphanumeric order. The course number served as the key, and the value stored the course title and its prerequisites.
I implemented three core functionalities:
Load Data: Read course details from a file and populate the map.
Print Course List: Display all courses sorted by course number.
Print Course Information: Show details about a specific course, including prerequisites.
Understanding data structures is crucial because they determine how efficiently data can be stored, accessed, and manipulated. The choice of map ensured both efficient lookups and automatic sorting, simplifying the implementation.

# How did you overcome any roadblocks you encountered while going through the activities or project?
During the project, one of the initial challenges was ensuring that the data file was correctly read and parsed. To address this:
I used careful error handling to check if the file existed and followed the expected format.
I added validation to skip malformed lines and prevent invalid data from being loaded into the map.
Another roadblock was ensuring prerequisites were stored and displayed correctly. I resolved this by iterating through the input line and splitting the prerequisites based on commas, storing them in a vector.

# How has your work on this project expanded your approach to designing software and developing programs?
Working on this project has enhanced my understanding of designing modular and efficient software. Key takeaways include:
Modular Design: Breaking the program into smaller functions (e.g., loadData, printCourseList, and printCourseInfo) improved code readability and reusability.
Data Structures: I learned how to select the right data structure (map) based on the problem requirements, such as sorting and searching.
User Interaction: Designing a user-friendly menu system allowed me to practice writing interactive programs that are intuitive and easy to use.

# How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
This project taught me the importance of clean, maintainable, and adaptable code:
Maintainability: I used clear function names, organized code into logical sections, and provided comments to explain the functionality. This makes the code easier to update or extend in the future.
Readability: The program is structured with clear input, processing, and output steps. Proper indentation, meaningful variable names, and comments enhance clarity.
Adaptability: By designing the program with flexibility in mind, additional features (e.g., searching courses, saving data) can be added without significant code rewrites.
