c1_node * __cdecl tree_new_three_fields_flagged(c1_u32 low,c1_u32 high,int size)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_sized_int_constant(low,high,size);
  if (low == 0 && high == 0) {
    pcVar1->kind = pcVar1->kind | 0x80;
  }
  return pcVar1;
}

