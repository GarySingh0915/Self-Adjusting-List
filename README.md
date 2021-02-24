# Self-Adjusting-List
Summary
For this assignment, we will build a self-adjusting list.  A self-adjusting list is one which will rearrange itself after operations. When creating a self-adjusting list, it can be approached in a few different ways.  For this assignment we willmove elements to the head (start) of the list. This is called Move-To-Front (MTF).  Self-adjusting lists have a wide range of uses, consider a cache. The most recently accessed item is moved to the front so it can be found again quickly. Specifications

1.You will implement a self-adjusting list(self_adjusting_array.h)based on our array_list. 

2.Start with the code we have written in class. 

3.Self-adjusting list operations:
  a.In a self-adjusting list, all insertions are performed at the front. 
  b.A self-adjusting list has a find operation, and when an element is accessed by a find, it is moved to the front of the list without changing the relative order of the other items. 
  c.NOTE: You will need extensive testcases to show these operations work as expected. Because theitemsare not sortedyou will have to use a basic linear searchto find the item. DO NOT assume the item for which you are looking is in the list. 
  
4.Write a main method which shows all operations of your lists are working as expected. Include a foreach loop so you can show the iterators work as expected and the find operation does in fact change the ordering of the elements.      
