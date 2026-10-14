c1_node * __cdecl tree_new_offset_cast(c1_node *left,int value,c1_type *type)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(value);
  pcVar1 = tree_new_binary(0x9e,left,pcVar1);
  pcVar1 = tree_new_cast(type,pcVar1);
  return pcVar1;
}

