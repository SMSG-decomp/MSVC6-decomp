void __thiscall diag_message_load(fe_message *m,short base,short id,va_list a)

{
  uchar *lpBuffer;
  
  m->base = base;
  m->id = id;
  lpBuffer = g_arenas[6].cur;
  g_arenas[6].cur = g_arenas[6].cur + 0x100;
  if (g_arenas[6].end < g_arenas[6].cur) {
    arena_grow(g_arenas + 6);
  }
  LoadStringA(g_module_handle,(uint)m->id,(LPSTR)lpBuffer,0x100);
  m->text = (char *)lpBuffer;
  diag_message_collect_args(m,(va_list *)a);
  return;
}

