void __cdecl init_push_brace_level(c1_symbol *sym)

{
  c1_u8 *pcVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  
  pcVar1 = g_arenas[1].cur;
  g_init_brace_depth = g_init_brace_depth + 1;
  g_init_level = g_init_levels + g_init_brace_depth;
  if (g_init_brace_depth < 0x20) {
    if (g_init_level->sym == (c1_symbol *)0x0) {
      g_arenas[1].cur = g_arenas[1].cur + (g_symbol_size_table[1] + 3 & 0xfffffffc);
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      if (pcVar1 == (c1_u8 *)0x0) {
        pcVar3 = (c1_symbol *)0x0;
      }
      else {
        pcVar3 = sym_init_kind((c1_symbol *)pcVar1,'\x01',(void *)0x0,1);
      }
      g_init_level->sym = pcVar3;
      pcVar1 = g_arenas[1].cur;
      g_arenas[1].cur = g_arenas[1].cur + 0x48;
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      g_init_level->detail = pcVar1;
    }
    sym_copy_record(g_init_level->sym,sym,g_init_level->detail,1);
    g_init_level->type = sym->type;
    g_init_level->sym->type = g_init_level->type;
    g_init_level->string_seen = '\0';
    g_init_level->count = 0;
    g_init_level->flags = '\0';
    bVar2 = sym->kind & 0x1f;
    if (((bVar2 == 2) || (bVar2 == 3)) && ((sym->flags2 & 3) != 3)) {
      diag_error(0x22d,sym);
    }
    return;
  }
  diag_fatal_simple(0x36);
}

