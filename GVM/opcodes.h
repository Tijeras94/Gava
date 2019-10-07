#pragma once

#define ACC_PUBLIC  0x0001 /*Declared public; may be accessed from outside its package.  */
#define ACC_FINAL  0x0010  /*Declared final; no subclasses allowed.  */
#define ACC_SUPER  0x0020  /*Treat superclass methods specially when invoked by the invokespecial instruction.  */
#define ACC_INTERFACE  0x0200 /*Is an interface, not a class.  */
#define ACC_ABSTRACT  0x0400 /*Declared abstract; may not be instantiated.  */

//Method access
#define ACC_PUBLIC  0x0001  /*Declared public; may be accessed from outside its package.  */
#define ACC_PRIVATE  0x0002  /*Declared private; accessible only within the defining class.  */
#define ACC_PROTECTED  0x0004  /*Declared protected; may be accessed within subclasses.  */
#define ACC_STATIC  0x0008  /*Declared static.  */
#define ACC_FINAL  0x0010  /*Declared final; may not be overridden.  */
#define ACC_SYNCHRONIZED  0x0020  /*Declared synchronized; invocation is wrapped in a monitor lock.  */
#define ACC_NATIVE  0x0100  /*Declared native; implemented in a language other than Java.  */
#define ACC_ABSTRACT  0x0400  /*Declared abstract; no implementation is provided.  */
#define ACC_STRICT  0x0800  /*Declared strictfp; floating-point mode is FP-strict  */

//Constants

#define op_nop			   00 //(0x00)
#define op_aconst_null	   01 //(0x01)
#define op_iconst_m1	   02 //(0x02)
#define op_iconst_0	   3 //(0x03)
#define op_iconst_1	   4 //(0x04)
#define op_iconst_2	   5 //(0x05)
#define op_iconst_3	   6 //(0x06)
#define op_iconst_4	   7 //(0x07)
#define op_iconst_5	   8 //(0x08)
#define op_lconst_0	   9 //(0x09)
#define op_lconst_1	   10 //(0x0a)
#define op_fconst_0	   11 //(0x0b)
#define op_fconst_1	   12 //(0x0c)
#define op_fconst_2	   13 //(0x0d)
#define op_dconst_0	   14 //(0x0e)
#define op_dconst_1	   15 //(0x0f)
#define op_bipush		   16 //(0x10)
#define op_sipush		   17 //(0x11)
#define op_ldc			   18 //(0x12)
#define op_ldc_w		   19 //(0x13)
#define op_ldc2_w		   20 //(0x14)

//Loads

#define op_iload		   21 //(0x15)    
#define op_lload		   22 //(0x16)    
#define op_fload		   23 //(0x17)    
#define op_dload		   24 //(0x18)    
#define op_aload		   25 //(0x19)    
#define op_iload_0		   26 //(0x1a)    
#define op_iload_1		   27 //(0x1b)    
#define op_iload_2		   28 //(0x1c)    
#define op_iload_3		   29 //(0x1d)    
#define op_lload_0		   30 //(0x1e)    
#define op_lload_1		   31 //(0x1f)    
#define op_lload_2		   32 //(0x20)    
#define op_lload_3		   33 //(0x21)    
#define op_fload_0		   34 //(0x22)    
#define op_fload_1		   35 //(0x23)    
#define op_fload_2		   36 //(0x24)    
#define op_fload_3		   37 //(0x25)    
#define op_dload_0		   38 //(0x26)    
#define op_dload_1		   39 //(0x27)    
#define op_dload_2		   40 //(0x28)    
#define op_dload_3		   41 //(0x29)    
#define op_aload_0		   42 //(0x2a)    
#define op_aload_1		   43 //(0x2b)    
#define op_aload_2		   44 //(0x2c)    
#define op_aload_3		   45 //(0x2d)    
#define op_iaload		   46 //(0x2e)    
#define op_laload		   47 //(0x2f)    
#define op_faload		   48 //(0x30)    
#define op_daload		   49 //(0x31)    
#define op_aaload		   50 //(0x32)    
#define op_baload		   51 //(0x33)    
#define op_caload		   52 //(0x34)    
#define op_saload		   53 //(0x35)    

//Stores

#define op_istore		   54 //(0x36)    
#define op_lstore		   55 //(0x37)    
#define op_fstore		   56 //(0x38)    
#define op_dstore		   57 //(0x39)    
#define op_astore		   58 //(0x3a)    
#define op_istore_0	   59 //(0x3b)    
#define op_istore_1	   60 //(0x3c)    
#define op_istore_2	   61 //(0x3d)    
#define op_istore_3	   62 //(0x3e)    
#define op_lstore_0	   63 //(0x3f)    
#define op_lstore_1	   64 //(0x40)    
#define op_lstore_2	   65 //(0x41)    
#define op_lstore_3	   66 //(0x42)    
#define op_fstore_0	   67 //(0x43)    
#define op_fstore_1	   68 //(0x44)    
#define op_fstore_2	   69 //(0x45)    
#define op_fstore_3	   70 //(0x46)    
#define op_dstore_0	   71 //(0x47)    
#define op_dstore_1	   72 //(0x48)    
#define op_dstore_2	   73 //(0x49)    
#define op_dstore_3	   74 //(0x4a)    
#define op_astore_0	   75 //(0x4b)    
#define op_astore_1	   76 //(0x4c)    
#define op_astore_2	   77 //(0x4d)    
#define op_astore_3	   78 //(0x4e)    
#define op_iastore		   79 //(0x4f)    
#define op_lastore		   80 //(0x50)    
#define op_fastore		   81 //(0x51)    
#define op_dastore		   82 //(0x52)    
#define op_aastore		   83 //(0x53)    
#define op_bastore		   84 //(0x54)    
#define op_castore		   85 //(0x55)    
#define op_sastore		   86 //(0x56) 

// Stack

#define op_pop			  87 //(0x57)    
#define op_pop2		  88 //(0x58)    
#define op_dup			  89 //(0x59)    
#define op_dup_x1		  90 //(0x5a)    
#define op_dup_x2		  91 //(0x5b)    
#define op_dup2		  92 //(0x5c)    
#define op_dup2_x1		  93 //(0x5d)    
#define op_dup2_x2		  94 //(0x5e)    
#define op_swap		  95 //(0x5f)    

// Math

#define op_iadd		  96 //(0x60)    
#define op_ladd		  97 //(0x61)    
#define op_fadd		  98 //(0x62)    
#define op_dadd		  99 //(0x63)    
#define op_isub		  100// (0x64)   
#define op_lsub		  101// (0x65)   
#define op_fsub		  102// (0x66)   
#define op_dsub		  103// (0x67)   
#define op_imul		  104// (0x68)   
#define op_lmul		  105// (0x69)   
#define op_fmul		  106// (0x6a)   
#define op_dmul		  107// (0x6b)   
#define op_idiv		  108// (0x6c)   
#define op_ldiv		  109// (0x6d)   
#define op_fdiv		  110// (0x6e)   
#define op_ddiv		  111// (0x6f)   
#define op_irem		  112// (0x70)   
#define op_lrem		  113// (0x71)   
#define op_frem		  114// (0x72)   
#define op_drem		  115// (0x73)   
#define op_ineg		  116// (0x74)   
#define op_lneg		  117// (0x75)   
#define op_fneg		  118// (0x76)   
#define op_dneg		  119// (0x77)   
#define op_ishl		  120// (0x78)   
#define op_lshl		  121// (0x79)   
#define op_ishr		  122// (0x7a)   
#define op_lshr		  123// (0x7b)   
#define op_iushr		  124// (0x7c)   
#define op_lushr		  125// (0x7d)   
#define op_iand		  126// (0x7e)   
#define op_land		  127// (0x7f)   
#define op_ior			  128// (0x80)   
#define op_lor			  129// (0x81)   
#define op_ixor		  130// (0x82)   
#define op_lxor		  131// (0x83)   
#define op_iinc		  132// (0x84)   

//Convertions

#define op_i2l			  133 //(0x85)    
#define op_i2f			  134 //(0x86)    
#define op_i2d			  135 //(0x87)    
#define op_l2i			  136 //(0x88)    
#define op_l2f			  137 //(0x89)    
#define op_l2d			  138 //(0x8a)    
#define op_f2i			  139 //(0x8b)    
#define op_f2l			  140 //(0x8c)    
#define op_f2d			  141 //(0x8d)    
#define op_d2i			  142 //(0x8e)    
#define op_d2l			  143 //(0x8f)    
#define op_d2f			  144 //(0x90)    
#define op_i2b			  145 //(0x91)    
#define op_i2c			  146 //(0x92)    
#define op_i2s			  147 //(0x93)    


// Comparisons

#define op_lcmp		  148 //(0x94)    
#define op_fcmpl		  149 //(0x95)    
#define op_fcmpg		  150 //(0x96)    
#define op_dcmpl		  151 //(0x97)    
#define op_dcmpg		  152 //(0x98)    
#define op_ifeq		  153 //(0x99)    
#define op_ifne		  154 //(0x9a)    
#define op_iflt		  155 //(0x9b)    
#define op_ifge		  156 //(0x9c)    
#define op_ifgt		  157 //(0x9d)    
#define op_ifle		  158 //(0x9e)    
#define op_if_icmpeq	  159 //(0x9f)    
#define op_if_icmpne	  160 //(0xa0)    
#define op_if_icmplt	  161 //(0xa1)    
#define op_if_icmpge	  162 //(0xa2)    
#define op_if_icmpgt	  163 //(0xa3)    
#define op_if_icmple	  164 //(0xa4)    
#define op_if_acmpeq	  165 //(0xa5)    
#define op_if_acmpne	  166 //(0xa6)    

// Control

#define op_goto		  167 //(0xa7)    
#define op_jsr			  168 //(0xa8)    
#define op_ret			  169 //(0xa9)    
#define op_tableswitch	  170 //(0xaa)    
#define op_lookupswitch  171 //(0xab)    
#define op_ireturn		  172 //(0xac)    
#define op_lreturn		  173 //(0xad)    
#define op_freturn		  174 //(0xae)    
#define op_dreturn		  175 //(0xaf)    
#define op_areturn		  176 //(0xb0)    
#define op_return		  177 //(0xb1)    

// References

#define op_getstatic		 178 //(0xb2)    
#define op_putstatic		 179 //(0xb3)    
#define op_getfield		 180 //(0xb4)    
#define op_putfield		 181 //(0xb5)    
#define op_invokevirtual	 182 //(0xb6)    
#define op_invokespecial	 183 //(0xb7)    
#define op_invokestatic	 184 //(0xb8)    
#define op_invokeinterface	 185 //(0xb9)    
#define op_invokedynamic	 186 //(0xba)    
#define op_new				 187 //(0xbb)    
#define op_newarray		 188 //(0xbc)    
#define op_anewarray		 189 //(0xbd)    
#define op_arraylength		 190 //(0xbe)    
#define op_athrow			 191 //(0xbf)    
#define op_checkcast		 192 //(0xc0)    
#define op_instanceof		 193 //(0xc1)    
#define op_monitorenter	 194 //(0xc2)    
#define op_monitorexit		 195 //(0xc3) 

// Extended 
#define op_wide			 196 //(0xc4)    
#define op_multianewarray	 197 //(0xc5)    
#define op_ifnull			 198 //(0xc6)    
#define op_ifnonnull		 199 //(0xc7)    
#define op_goto_w			 200 //(0xc8)    
#define op_jsr_w			 201 //(0xc9)    

// Reserved

#define breakpoint		 202 //(0xca)    
#define impdep1			 254 //(0xfe)    
#define impdep2			 255 //(0xff)    