#pragma once

// The types u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantity, respectively
typedef unsigned char u1;
// The types u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantity, respectively
typedef unsigned short u2;
// represent a signed short
typedef short i2;
// The types u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantity, respectively
typedef unsigned __int32 u4;
// represents a signed int
typedef __int32 i4;
// The types u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantity, respectively
typedef unsigned __int64 u8;

typedef long LONG_PTR;
typedef float f4;
typedef double f8;

#define getu4(p) (u4)( (u4)((p)[0])<<24 & 0xFF000000 | (u4)((p)[1])<<16 & 0x00FF0000 | (u4)((p)[2])<<8 & 0x0000FF00| (u4)((p)[3]) & 0x000000FF)

//gets a short from 2 values in array 
#define getu2(p) (u2)((p)[0]<< 8 & 0x0000FF00 |(p)[1])


//--- Constant pool tags

#define CONSTANT_Utf8 1
//The CONSTANT_Utf8_info structure is used to represent constant string values:
struct CONSTANT_Utf8_info {
	u1 tag;
	u2 length;
	u1* bytes;//[length];
};

#define CONSTANT_Integer 3  
//The CONSTANT_Integer_info structure represent 4-byte numeric int constants:
struct CONSTANT_Integer_info {
	u1 tag;
	u4 bytes;
};

#define CONSTANT_Float 4  
//The CONSTANT_Float_info structures represent 4-byte numeric float constants:
struct CONSTANT_Float_info {
	u1 tag;
	u4 bytes;
};

#define CONSTANT_Long 5 
//The CONSTANT_Long_info represent 8-byte numeric long constants:
struct CONSTANT_Long_info {
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
};

#define CONSTANT_Double 6  
//The CONSTANT_Double_info represent 8-byte numeric double constants:
struct CONSTANT_Double_info {
	u1 tag;
	u4 high_bytes;
	u4 low_bytes;
};

#define CONSTANT_Class 7 
//The CONSTANT_Class_info structure is used to represent a class or an interface
struct CONSTANT_Class_info {
	u1 tag;
	u2 name_index; //The value of the name_index item must be a valid index into the constant_pool table
};

#define CONSTANT_String 8  
//The CONSTANT_String_info structure is used to represent constant objects of the type String:
struct CONSTANT_String_info {
	u1 tag;
	u2 string_index;
};

#define CONSTANT_Fieldref 9 
//Fields methods are represented by similar structures:
struct CONSTANT_Fieldref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
};

#define CONSTANT_Methodref 10  
//Methods are represented by similar structures:
struct CONSTANT_Methodref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
};

#define CONSTANT_InterfaceMethodref  11  

//Interface methods are represented by similar structures:
struct CONSTANT_InterfaceMethodref_info {
	u1 tag;
	u2 class_index;
	u2 name_and_type_index;
};

#define CONSTANT_NameAndType  12  
/*
The CONSTANT_NameAndType_info structure is used to represent a field or method, 
without indicating which class or interface type it belongs to:
*/
struct CONSTANT_NameAndType_info {
	u1 tag;
	u2 name_index;
	u2 descriptor_index;
};

#define CONSTANT_MethodHandle 15
//The CONSTANT_MethodHandle_info structure is used to represent a method handle:
struct CONSTANT_MethodHandle_info {
	u1 tag;
	u1 reference_kind;
	u2 reference_index;
};

#define CONSTANT_MethodType	16
//The CONSTANT_MethodType_info structure is used to represent a method type:
struct CONSTANT_MethodType_info{
	u1 tag;
	u2 descriptor_index;
};

#define CONSTANT_Dynamic 17
/*
	The CONSTANT_Dynamic_info structure is used to represent a dynamically-computed constant,
	an arbitrary value that is produced by invocation of a bootstrap method in the course of an
	ldc instruction (§ldc), among others
*/
struct CONSTANT_Dynamic_info{
	u1 tag;
	u2 bootstrap_method_attr_index;
	u2 name_and_type_index;
};

#define CONSTANT_InvokeDynamic	18
/*
The CONSTANT_InvokeDynamic_info structure is used to represent a dynamically-computed call site, 
an instance of java.lang.invoke.CallSite that is produced by invocation of a bootstrap method in 
the course of an invokedynamic instruction (§invokedynamic).
*/
struct CONSTANT_InvokeDynamic_info{
	u1 tag;
	u2 bootstrap_method_attr_index;
	u2 name_and_type_index;
};

//The CONSTANT_Module_info structure is used to represent a module:
#define CONSTANT_Module	19
struct CONSTANT_Module_info {
	u1 tag;
	u2 name_index;
};

#define CONSTANT_Package 20
//The CONSTANT_Package_info structure is used to represent a package exported or opened by a module:
struct CONSTANT_Package_info{
	u1 tag;
	u2 name_index;
};




// Java virtual machine instructions do not rely on the runtime layout of classes, interfaces, class instances, or arrays.
// Instead, instructions refer to symbolic information in the constant_pool table.
struct cp_info {
	u1 tag;
	u1* info;
};

struct exception_table {
	u2 start_pc;
	u2 end_pc;
	u2 handler_pc;
	u2 catch_type;
};
 

// Attributes are used in the ClassFile (§4.1), field_info (§4.5), method_info (§4.6), 
// and Code_attribute (§4.7.3) structures of the class file format. 
struct attribute_info {
	u2 attribute_name_index;
	u4 attribute_length;
	u1* info;//[attribute_length];
};

struct Code_attribute {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	u1* code;// [code_length] ;
	u2 exception_table_length;
	exception_table* exception_table;// [exception_table_length] ;
	u2 attributes_count;
	attribute_info* attributes;// [attributes_count] ;
};

// Each field is described by a field_info structure. No two fields in one 
// class file may have the same name and descriptor (§4.3.2
struct field_info {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info* attributes;// [attributes_count] ;
};


// Each method, including each instance initialization method (§3.9) and the class or
// interface initialization method (§3.9), is described by a method_info structure. 
// No two methods in one class file may have the same name and descriptor (§4.3.3).
struct method_info {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info* attributes;// [attributes_count] ;
};


// a class file structure
struct ClassFile {
public:
	u4 magic; //The magic item supplies the magic number identifying the class file format; it has the value 0xCAFEBABE
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	cp_info* constant_pool;// [constant_pool_count - 1] ;
	u2 access_flags;
	u2 this_class; //The constant_pool entry at that index must be a CONSTANT_Class_info structure (§4.4.1) representing the class or interface defined by this class file
	u2 super_class; //If the value of the super_class item is nonzero, the constant_pool entry at that index must be a CONSTANT_Class_info structure representing the direct superclass of the class defined by this class file
	u2 interfaces_count;
	u2* interfaces;// [interfaces_count] ;
	u2 fields_count;
	field_info* fields;// [fields_count] ;
	u2 methods_count;
	method_info* methods;// [methods_count] ;
	u2 attributes_count;
	attribute_info* attributes;// [attributes_count] ;
};

class Object
{
public:
	LONG_PTR heapPtr;
	u1 type;
};

union Variable
{ 
	u1 charValue;
	u2 shortValue;
	u4 intValue;
	f4 floatValue;
	LONG_PTR ptrValue;
	Object object;
};