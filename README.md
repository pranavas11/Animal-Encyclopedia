# Animal-Encyclopedia
This project creates a small encyclopedia application that will display various bits of information on a selection of animals. A base class will be created to define an underlying structure, and we'll extend this with individual animal records, making use of polymorphism to fetch their data.


# Steps
1. Start by including all the files that you'll need for the application.
2. Create a struct, AnimalInfo, that can store Name, Origin, Life Expectancy, and Weight.
3. Create a function to print that data out in a neat format. Name it PrintAnimalInfo.
4. Now, create the base class for our animals. Name it Animal. It should provide a member variable of type AnimalInfo, and a function to return it. Be sure to use appropriate access modifiers.
5. Next, create the first derived class, Lion. This class will inherit from Animal, be final, and fill out the AnimalInfo member in its constructor.
6. Next, create the second derived class, Tiger. Fill out the same data.
7. Create the final derived class, Bear, also filling out the AnimalInfo member.
8. Define the main function. Declare a vector of pointers to the base Animal type and add one of each of the animal-derived types. Don't forget to output the application title!
9. Create the main outer loop for the application and output a message to the user prompting them to select an index.
10. Output the possible selections to the user. Use a for loop for this, and each option should include an index and the name of the animal. Also, include an option for the user to be able to quit the application by entering -1.
11. Fetch the user input and convert it to an integer.
12. Check whether the user entered -1 and thus wants to quit the application. Handle this if they do.
13. Next, check that the user entered an invalid index. An invalid index is one that's less than -1 and greater than the size of the animal vector -1 (because indices start at 0, not 1). If they did, output an error message and have them choose again.
14. If the user input a valid index, make a call to the PrintAnimalInfo created earlier, passing in the animal's info that you'll get from the vector.
15. Outside of the main loop, clean up the pointers. This means deleting their memory, setting them to 0, and then clearing the vector.
