c1_node * __cdecl tree_new_int_constant(int value)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant_raw(value);
  if (value == 0) {
    pcVar1->kind = pcVar1->kind | 0x80;
  }
  return pcVar1;
}

