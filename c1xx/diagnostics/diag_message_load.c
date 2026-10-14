void __thiscall diag_message_load(c1_message *msg,short kind,short number,char *args)

{
  c1_u8 *lpBuffer;
  
  msg->base = kind;
  msg->id = number;
  lpBuffer = g_arenas[9].cur;
  g_arenas[9].cur = g_arenas[9].cur + 0x100;
  if (g_arenas[9].end < g_arenas[9].cur) {
    arena_grow(g_arenas + 9);
  }
  LoadStringA(g_module_handle,(uint)msg->id,(LPSTR)lpBuffer,0x100);
  msg->text = (char *)lpBuffer;
  diag_message_collect_args(msg,(int *)args);
  return;
}

