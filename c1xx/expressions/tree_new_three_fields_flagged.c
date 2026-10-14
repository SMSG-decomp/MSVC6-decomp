c1_node * __cdecl tree_new_three_fields_flagged(uint lo,int hi,int size)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_sized_int_constant(lo,hi,size);
  if (lo == 0 && hi == 0) {
    pcVar1->kind = pcVar1->kind | 0x80;
  }
  return pcVar1;
}

