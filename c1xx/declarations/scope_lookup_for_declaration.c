c1_u8 * __thiscall scope_lookup_for_declaration(void *scope,c1_declarator *d,int flags)

{
  c1_u8 *pcVar1;
  c1_lookup_result *result;
  c1_symbol *pcVar2;
  c1_lookup_entry *pcVar3;
  
  result = (c1_lookup_result *)(**(code **)(*(int *)scope + 0xc))(d->name,flags);
  if (result == (c1_lookup_result *)0x0) {
    pcVar2 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
    pcVar1 = g_arenas[5].cur;
    if (pcVar2 != (c1_symbol *)0x0) {
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
        return pcVar1;
      }
    }
  }
  else {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar3 != (c1_lookup_entry *)0x0) {
      pcVar2 = decl_redeclare_or_new(d,pcVar3->sym);
      pcVar1 = g_arenas[5].cur;
      if (pcVar2 != (c1_symbol *)0x0) {
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
          return pcVar1;
        }
      }
    }
  }
  return (c1_u8 *)0x0;
}

