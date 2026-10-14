c1_lookup_entry * __fastcall sym_new_kind1b(c1_lookup_result *result)

{
  fe_name *name;
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  
  name = result->head->sym->name;
  pcVar2 = sym_alloc_record(0x38,0x1b,5);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\x1b',name,5);
  }
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 4;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar2->type = (c1_type *)pcVar1;
  *(c1_lookup_entry **)pcVar1 = result->head;
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar1 != (c1_u8 *)0x0) {
    *(c1_symbol **)pcVar1 = pcVar2;
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    pcVar1[8] = '\0';
    pcVar1[9] = '\0';
    pcVar1[10] = '\0';
    pcVar1[0xb] = '\0';
    return (c1_lookup_entry *)pcVar1;
  }
  return (c1_lookup_entry *)0x0;
}

