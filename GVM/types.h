#pragma once

// The types u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantity, respectively
typedef char u1;
typedef short u2;
typedef __int32 u4;
typedef __int64 u8;


// Java virtual machine instructions do not rely on the runtime layout of classes, interfaces, class instances, or arrays.
// Instead, instructions refer to symbolic information in the constant_pool table.
struct cp_info {
	u1 tag;
	u1* info;
};

// Attributes are used in the ClassFile (§4.1), field_info (§4.5), method_info (§4.6), 
// and Code_attribute (§4.7.3) structures of the class file format. 
struct attribute_info {
	u2 attribute_name_index;
	u4 attribute_length;
	u1* info;//[attribute_length];
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
	u4 magic;
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	cp_info* constant_pool;// [constant_pool_count - 1] ;
	u2 access_flags;
	u2 this_class;
	u2 super_class;
	u2 interfaces_count;
	u2* interfaces;// [interfaces_count] ;
	u2 fields_count;
	field_info* fields;// [fields_count] ;
	u2 methods_count;
	method_info* methods;// [methods_count] ;
	u2 attributes_count;
	attribute_info* attributes;// [attributes_count] ;
};