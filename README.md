# Corner-Grocer
I was tasked with developing an item-tracking program for Corner Grocer. They outlined specific features to enhance the program's performance and functionality, requiring careful consideration of its structure.

To ensure maintainability and reusability, I organized my code into separate files. The `GroceryItem` class file contains the data structures, along with their getters and constructors. In contrast, the data processing code resides in the `Source` class.

The `Source` class implements various menu options. Option one allows users to search for an item by name and retrieve its corresponding numeric value. Option two provides a list of items along with their quantities. Option three generates a histogram, and option four exits the program. Additionally, the program includes functionality for creating a backup file named `frequency.dat`. Furthermore, it allows users to add new items to the inventory. I tested this feature by adding a kiwi to the inventory.

I believe that to make this code even better, I could have implemented a function to remove items, allowing users to delete items from the inventory and providing greater flexibility. While all aspects of this code have their advantages and disadvantages, the item search section was the most complex, as users were required to input items. I had to ensure everything was functioning as intended.

One noteworthy feature I implemented is a map class, which enhances the program's reusability. Since Corner Grocer may wish to rearrange their produce section in the future, this map class, defined as `map<string, GroceryItem>& items`, enables users to adapt the code to their changing needs. This is something I will implement to improve future projects with similar functionality.

