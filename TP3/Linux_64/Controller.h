int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_lastIdEmployee(LinkedList* pArrayListEmployee);
int controller_searchEmployeeById(LinkedList* pArrayListEmployee,int id,int* index);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_PrintEmployee(LinkedList* pArrayListEmployee, int index);
int controller_PrintEmployeeWithFields(LinkedList* pArrayListEmployee, int index);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


