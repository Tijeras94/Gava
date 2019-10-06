#include <stdio.h>
#include <assert.h>
#include <memory>
#include "types.h"
#include "opcodes.h"
 
#include "ClassHeap.h"
#include "JavaClass.h"
#include "Stream.h" 


class Frame {
public:
	Frame(int stacklen = 20, int varlen = 20) {
		stack_len = stacklen;
		stack = new int[stack_len];
		var_len = varlen;
		variable = (int*)new int[var_len];
		sp = 0;
		vp = 0;
	}

	void pushs(int n) {
		stack[sp++] = n;
	}

	int pops() {
		return stack[--sp];
	}

	void setv(int i, int val) {
		variable[i] = val;
	}

	int getv(int i) {
		return variable[i];
	}

	int* variable;
	int var_len;
	int vp;
	int* stack;
	int sp;
	int stack_len;
};

void exec(Stream& code, Frame* f) {
	u1 opcode = code.readByte();
	if (opcode == op_bipush) {
		f->pushs(code.readByte());
	}
	else if (opcode == op_istore_1) {
		f->setv(1, f->pops());
	}
	else if (opcode == op_istore_2) {
		f->setv(2, f->pops());
	}
	else if (opcode == op_istore_3) {
		f->setv(3, f->pops());
	}
	else if (opcode == op_iload_1) {
		f->pushs(f->getv(1));
	}
	else if (opcode == op_iload_2) {
		f->pushs(f->getv(2));
	}
	else if (opcode == op_iload_3) {
		f->pushs(f->getv(3));
	}
	else if (opcode == op_iadd) {
		f->pushs(f->pops() + f->pops());
	}
	else if (opcode == op_invokestatic) {
		u2 ind = code.readShort();
		printf("Invoking static: %i\n", ind);
	}

	if (!code.eof())
		exec(code, f);
}


int main()
{
	JavaClass* jclass;
	ClassHeap map;
	map.LoadClass("Hello", jclass);  

	//char name[100];
	method_info info = jclass->GetMethod("main", "([Ljava/lang/String;)V");
	auto cd = jclass->getCodeFromMethod(info);
	Stream code(cd.code, cd.code_length);
	Frame frame[10];


	exec(code, frame);
	printf("Dine");


}
