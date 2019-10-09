#include <stdio.h>
#include <assert.h>
#include <memory>
#include "types.h"
#include "opcodes.h"
 
#include "ClassHeap.h"
#include "JavaClass.h"
#include "CStream.h" 


class Frame {
public:
	Frame(int stacklen = 50, int varlen = 50) {
		stack_len = stacklen;
		stack = (Variable*)new Variable[stack_len];
		var_len = varlen;
		variable = (Variable*)new Variable[var_len];
		sp = 0;
		vp = 0;
	}

	void pushs(Variable n) {
		stack[sp++] = n;
	}

	Variable pops() {
		return stack[--sp];
	}

	void setv(int i, Variable val) {
		variable[i] = val;
	}

	Variable getv(int i) {
		return variable[i];
	}

	Variable* variable;
	int var_len;
	int vp;
	Variable* stack;
	int sp;
	int stack_len;
};

void exec(Stream& code, Frame* f, JavaClass* jclass) {
	u1 opcode = code.readByte();
	if (opcode == op_bipush) {
		Variable v;
		v.intValue = code.readByte();
		f->pushs(v);
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
	else if (opcode == op_dstore_1) {
		f->setv(1, f->pops());
	}
	else if (opcode == op_fstore_1) {
		f->setv(1, f->pops());
	}
	else if (opcode == op_iconst_0) {
		Variable v;
		v.intValue = 0;
		f->pushs(v);
	}
	else if (opcode == op_iconst_1) {
		Variable v;
		v.intValue = 1;
		f->pushs(v);
	}
	else if (opcode == op_iconst_2) {
		Variable v;
		v.intValue = 2;
		f->pushs(v);
	}
	else if (opcode == op_iconst_3) {
		Variable v;
		v.intValue = 3;
		f->pushs(v);
	}
	else if (opcode == op_iconst_4) {
		Variable v;
		v.intValue = 4;
		f->pushs(v);
	}
	else if (opcode == op_iconst_5) {
		Variable v;
		v.intValue = 5;
		f->pushs(v);
	}
	else if (opcode == op_dconst_0) {
		Variable v;
		v.floatValue = 0;
		f->pushs(v);
	}
	else if (opcode == op_dconst_1) {
		Variable v;
		v.floatValue = 1;
		f->pushs(v);
	}
	else if (opcode == op_fconst_0) {
		Variable v;
		v.floatValue = 0;
		f->pushs(v);
	}
	else if (opcode == op_fconst_1) {
		Variable v;
		v.floatValue = 1;
		f->pushs(v);
	}
	else if (opcode == op_ldc) {
		auto c = jclass->GetStreamConstant(code.readByte());
		if (c.tag == CONSTANT_Float) {
			Variable val;
			val.floatValue = c.readFloat();
			f->pushs(val);
		}
	}
	else if (opcode == op_ldc2_w) { 
		auto c = jclass->GetStreamConstant(code.readSignedShort());
		if (c.tag == CONSTANT_Double) {
			Variable val;  
			val.floatValue = c.readDouble(); 
			f->pushs(val); 
		} 
	}
	else if (opcode == op_iload) {
		f->pushs(f->getv(code.readByte()));
	}
	else if (opcode == op_iload_0) {
		f->pushs(f->getv(0));
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
	else if (opcode == op_dload_1) {
		f->pushs(f->getv(1));
	}
	else if (opcode == op_fload_1) {
		f->pushs(f->getv(1));
	}
	/// MATH
	else if (opcode == op_fadd) {
		Variable v;
		v.floatValue = f->pops().floatValue + f->pops().floatValue;
		f->pushs(v);
	}
	else if (opcode == op_dadd) {
		Variable v;
		v.floatValue = f->pops().floatValue + f->pops().floatValue;
		f->pushs(v);
	}
	else if (opcode == op_iadd) {
		Variable v;
		v.intValue = f->pops().intValue + f->pops().intValue;
		f->pushs(v);
	}
	else if (opcode == op_isub) {
		Variable v;
		v.intValue = f->pops().intValue - f->pops().intValue;
		f->pushs(v);
	}
	else if (opcode == op_iinc) {
		int index = code.readByte();
		int cons = code.readByte();
		Variable v;
		v.intValue = f->getv(index).intValue + cons;
		f->setv(index, v);
	}
	else if (opcode == op_imul) {
		Variable v;
		v.intValue = f->pops().intValue * f->pops().intValue;
		f->pushs(v);
	}
	else if (opcode == op_return) {  
		auto as = f - 1;

		return;
	} 
	else if (opcode == op_ireturn) {
		return;
	}
	else if (opcode == op_invokestatic) {
		u2 ind = code.readShort(); 
		auto inf = jclass->GetStreamConstant(ind); 
		auto ci = jclass->GetStreamConstant(inf.readShort());
		auto nti = jclass->GetStreamConstant(inf.readShort());
		char name[120];
		char sig[120];
		//method
		jclass->GetUtf8String(jclass->GetConstant(nti.readShort()), name);
		//sig
		jclass->GetUtf8String(jclass->GetConstant(nti.readShort()), sig);

		auto method = jclass->GetMethod(name, sig); 
		if (method.access_flags & ACC_NATIVE) { 
			// TODO: needs better management for native functions 

			//check method if its a void method
			if (strstr(sig, ")V") != NULL) {  //  if its void, do nothing to the stack

				//check if current function its a native print function 
				if (strcmp("Print", name) == 0) { // check if method is a print
					auto as = f->pops(); // pop value
					if (strstr(sig, "D)V") != NULL) { // its a double
						printf("%f", as.floatValue);
					}else if (strstr(sig, "F)V") != NULL) { // its a double
						printf("%f", as.floatValue);
					}
					else {
						printf("%i", as.intValue);
					} 

				}

			}
			else {
				// if native functions that are not void, therefore needs to return object

			}
		}
		else {
			//printf("Invoking static: %s%s\n", name, sig);
			
			//method is not native
			auto cd = jclass->getCodeFromMethod(method);
			Frame* nf = f + 1; // go to the nex frame
			
			// TODO: this needs to be the args count 
			//fill the variables with parametes method parameters
			for (int i = 0; i < cd.max_locals; i++) {

				nf->setv(i, f->pops());
			}
			//nf->setv(0, f->pops());
			//nf->setv(1, f->pops());

			//code. 
			Stream code(cd.code, cd.code_length);
			exec(code, nf, jclass);

			//check if its a void method if its not push return value to the stack
			if (strstr(sig, ")V") == NULL) {  
				f->pushs(nf->pops()); // push return value to the end of the stack of the parent
			} 

		}

		
		
	} // comparisons
	else if (opcode == op_ifne) {
		i4 jmp = code.readSignedShort() - 3;
		if(0 != f->pops().intValue)
			code.seekoffset(jmp); 
	}
	else if (opcode == op_goto) {
		i4 jmp = code.readSignedShort() - 3; // jmp contains offset address starting  at opcode offet therefore subtract 3(opcodebyte(1) + i2(2)) will give you right offset
		code.seekoffset(jmp); 
	}
	else if (opcode == op_if_icmpge) {
		i4 jmp = code.readSignedShort() - 3;
		//value1, value2 
		int v2 = f->pops().intValue;
		int v1 = f->pops().intValue;

		//if value1 is greater than or equal to value2, branch to instruction at
		if(v1 >= v2)
			code.seekoffset(jmp); 
	}
	// references
	else if (opcode == op_new) {
		
	}
	else
	{ 
		printf("Invalid opcode \"%i\" :( \n", opcode);
		return;
	}

	if (!code.eof())
		exec(code, f, jclass);
}

int main()
{
	JavaClass* jclass;
	ClassHeap map; 
	if (map.LoadClass("Hello", jclass)) {
		//char name[100];
		method_info info = jclass->GetMethod("main", "([Ljava/lang/String;)V");
		auto cd = jclass->getCodeFromMethod(info);
		Stream code(cd.code, cd.code_length);
		Frame frame[10];

		exec(code, frame, jclass);
	}

	return 0;
}
