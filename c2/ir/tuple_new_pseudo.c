c2_tuple * __fastcall tuple_new_pseudo(uint32_t op,uint16_t type)

{
  c2_tuple *pcVar1;
  
  pcVar1 = (c2_tuple *)node_alloc('\x14');
  pcVar1->op = op;
  pcVar1->type = type;
  pcVar1->flags = pcVar1->flags | 1;
  pcVar1->line = g_cur_line;
  return pcVar1;
}

