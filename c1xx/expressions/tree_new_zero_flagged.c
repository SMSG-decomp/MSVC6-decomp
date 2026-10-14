c1_node * __cdecl tree_new_zero_flagged(void)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(0);
  pcVar1->kind = pcVar1->kind | 8;
  return pcVar1;
}

