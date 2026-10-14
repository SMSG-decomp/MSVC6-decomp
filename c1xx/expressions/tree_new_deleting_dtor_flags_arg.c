c1_node * __cdecl tree_new_deleting_dtor_flags_arg(int kind,char do_delete)

{
  c1_node *pcVar1;
  uint value;
  int flag;
  
  value = (kind != 5) - 1 & 2 | (uint)(do_delete != '\0');
  if ((kind != 4) && (kind != 5)) {
    return (c1_node *)0x0;
  }
  pcVar1 = tree_new_int_constant(value);
  pcVar1->type = g_type_unsigned_int;
  flag = 2;
  pcVar1 = tree_new_int_constant(value);
  pcVar1 = tree_append_list_item((c1_node *)0x0,pcVar1,flag);
  return pcVar1;
}

