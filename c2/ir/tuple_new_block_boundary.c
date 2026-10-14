c2_tuple * __fastcall tuple_new_block_boundary(void)

{
  c2_tuple *pcVar1;
  
  pcVar1 = (c2_tuple *)node_alloc('\x19');
  pcVar1->op = 0x1af;
  pcVar1->line = 0;
  return pcVar1;
}

