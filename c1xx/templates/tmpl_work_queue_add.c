void __cdecl tmpl_work_queue_add(c1_symbol *sym,int *args)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[0].cur;
  if (g_template_work_queue == (c1_tmpl_work_queue *)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (pcVar1 == (c1_u8 *)0x0) {
      g_template_work_queue = (c1_tmpl_work_queue *)0x0;
    }
    else {
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1[4] = '\0';
      pcVar1[5] = '\0';
      pcVar1[6] = '\0';
      pcVar1[7] = '\0';
      pcVar1[8] = '\0';
      g_template_work_queue = (c1_tmpl_work_queue *)pcVar1;
    }
  }
  tmpl_work_queue_add_item(g_template_work_queue,sym,args);
  return;
}

