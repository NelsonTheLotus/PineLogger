# Pine Logger
A dynamic, fast and flexible logging library for C++.

## Project Structure

The project is structured in several folders. The top folders are:
 - Build: Contains all the object files as well as the binaries and release files.
 - Docs: Contains all the documentation for the use of PineLogger.
 - Scripts: Contains scripts to build and deploy the program in various manners.
 - Sources: Contains the source code.

Following is the source folder structure:

### Event
This folder is responsible for managing events. It contains several files:
 - Manager: is the entity responsible for linking events to loggers, triggering events and dispatching trigger signals.
 - Pusher: Is reposnible for calling the defined method upon event trigger.
 - Listener: Is responsible for listening to events and reporting them.

### Logger
This folder contains the file necessary for all user-accessible logging functions:
 - Entity: Is the logging entity from which all logs come from.

### Pine
Pine is the folder that contains all library-specific settings and parameters:
 - PineLib: First file included in any pine-project file, except the files located in this folder.
 - Settings: Determines macros and parameters needed for compillation/execution
 - Types: defines library-wide structures, objects, types.

### Render
Render is reposnible for all log generations:
 - Frame: will take in a message and map it to it's defined skeleton format, as well as retrieve the needed information for the desired format.

### Schedule
Schedule is reponsible for all time-management functionnalities:
 - Async: Covers all asynchronous operations
 - Thread: Manages logging threads
 - Timer: keeps track of time and triggers the appropriate event(s)

### Storage
Storage will keep track of the logs and dispatch where necessary:
 - Buffer: Will store the logs until the user decides to flush them.
 - Stream: Is the object responsible for determining the destination of the log.


## Naming conventions

We will use the name `new type name` as an example to demonstrate the sytax of the naming conventions.

### Variables
Variable are written in camel case. Example: `newTypeName`.

### Typenamed types
Typenamed types (for example `typedef char byte`) are written in snake case. Example: `new_type_name`.

### Macros
Macros defined with teh `#define` preprocessor keyword are written in upper snake case. Example: `NEW_TYPE_NAME`.

### Classes
Classes are named in pascal case. Example: `NewTypeName`.

### Files
Files are named in pascal case. Example: `NewTypeName`.

### Functions
Functions are named in camel case. Example: `newTypeName`.
