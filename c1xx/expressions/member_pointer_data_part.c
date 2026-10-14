c1_node * __cdecl member_pointer_data_part(c1_node *mp,int k)

{
  char cVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  
  pcVar2 = type_int();
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  cVar1 = (&g_type_rank_table)[(byte)pcVar2->code & 0xf];
  pcVar2 = type_int();
  pcVar3 = tree_new_int_constant(cVar1 * k);
  pcVar3 = tree_new_node('S',mp,pcVar3,pcVar2);
  pcVar3 = tree_new_rvalue(pcVar3);
  return pcVar3;
}

