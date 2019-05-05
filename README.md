
Abril Marina González Ramírez A01280904\
Juan Luis Flores Garza A01280767\
Sergio Díaz Navarro\
Miguel Bazán Aviña A01281010

# KWIC_Archillects
KeyWord-In-Context (KWIC) system - Software Design and Architecture Activity

The KWIC index system accepts an ordered set of lines; each line is an ordered set of words, and each word is an ordered
set of characters. Any line may be “circularly shifted” by repeatedly removing the first word and appending it at the end
of the line. The KWIC index system outputs a list of all circular shifts of all lines in alphabetical order.

KeyWord-In-Context (KWIC) system\
	**input:** strings, each of which consists of several words.\
	**output:** a sorted list of all orderings of each input string.

Example of KWIC operation
- **input**\
		“Clouds are white.”\
		“Pittsburgh is beautiful.”
- **output**\
		are white clouds\
		beautiful pittsburgh is\
		clouds are white\
		is beautiful pittsburgh\
		pittsburgh is beautiful\
		white clouds are

# Version 2
## **Update:** 
- Allows the user to enter a list of stop words (words to be deleted from lines)
- Select which type of sorting (ascending or descending)
- Delete lines from input
- Delete lines from output

## Software Architecture

### Logic View
![](diagrams/ClassDiagram_v2.png)

### Process View
![](diagrams/ProcessView_v2.png)

### Development View
![](diagrams/DevelopmentView.png)

### Physical View
![](diagrams/PhysicalView.png)

### Scenario View
![](/diagrams/ScenarioView_v2.png)

## How to Run
Compile and run from terminal\
	`g++ main.cpp -o KWIC`\
	`./KWIC`

Write input\
	`example.txt`

Enter stop words.\
_Type "end" to finish stop words._\
	`white`\
	`end`

Enter lines from input to delete.\
_Type "-1" to finish._\
	`0`\
	`-1`

Select which kind of sort\
_(Ascending order = 0, Descending order = 1)_\
	`0`

Enter lines from output to delete.\
_Type "-1" to finish._\
	`-1`

## Result
![](image_v2.png)



