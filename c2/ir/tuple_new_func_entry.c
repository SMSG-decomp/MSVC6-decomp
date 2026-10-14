c2_tuple * __fastcall tuple_new_func_entry(c2_function *fn)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = (c2_tuple *)node_alloc('\x17');
  uVar1 = g_cur_line;
  (pcVar2->u14).fn = fn;
  pcVar2->op = 0x1b0;
  pcVar2->line = uVar1;
  return pcVar2;
}

