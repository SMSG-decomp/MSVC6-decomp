c1_node * __cdecl tree_add_offset_if_nonzero(c1_node *left,int value)

{
  c1_node *pcVar1;
  
  if (value != 0) {
    pcVar1 = tree_new_int_constant(value);
    pcVar1 = tree_new_binary('Q',left,pcVar1);
    return pcVar1;
  }
  return left;
}

