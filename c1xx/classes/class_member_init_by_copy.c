void __cdecl class_member_init_by_copy(int *member,c1_node *value)

{
  c1_node *pcVar1;
  char sign;
  c1_type *type;
  
  type = value->type;
  sign = '\x01';
  pcVar1 = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = expr_member_offset(1,pcVar1,member,sign,type);
  conv_check_copy_conversion(pcVar1,value);
  return;
}

