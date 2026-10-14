c2_tuple * __fastcall tuple_new_marker(uint32_t op)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = (c2_tuple *)node_alloc('\x16');
  uVar1 = g_cur_line;
  pcVar2->op = op;
  pcVar2->line = uVar1;
  return pcVar2;
}

