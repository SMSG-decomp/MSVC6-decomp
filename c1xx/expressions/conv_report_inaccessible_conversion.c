c1_node * __cdecl
conv_report_inaccessible_conversion
          (uint op,c1_node *obj,uint op_byte,c1_type *type,int *path,int sign)

{
  c1_node *pcVar1;
  
  if (((char)op == -0x38) || (((byte)g_compile_flags_c8 & 1) == 0)) {
    diag_error(0xf3,op_byte,obj->type,type);
  }
  else {
    diag_warning(3,0xf3,op_byte,obj->type,type);
  }
  pcVar1 = expr_member_offset(op,obj,path,(char)sign,type);
  return pcVar1;
}

