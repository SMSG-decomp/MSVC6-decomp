c1_u8 * __thiscall class_lookup_qualified_name(void *scope,void *name)

{
  c1_u8 *pcVar1;
  c1_lookup_entry *pcVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  
  pcVar2 = lookup_name_in_context(scope,name,0x20);
  if (pcVar2 == (c1_lookup_entry *)0x0) {
    pcVar4 = (c1_symbol *)0x0;
  }
  else {
    pcVar4 = pcVar2->sym;
  }
  if (pcVar4 == (c1_symbol *)0x0) {
LAB_10437b3b:
    g_qualified_lookup_found_overloads = 0;
  }
  else {
    if ((pcVar4->kind & 0x1f) == 0x12) {
      pcVar5 = *(c1_symbol **)(*(int *)pcVar4->type + 8);
LAB_10437b23:
      g_qualified_lookup_found_overloads = 1;
    }
    else {
      pcVar5 = pcVar4;
      if (((pcVar2->scope->kind == g_current_scope->current->kind) &&
          (pcVar2->scope->outer == g_current_scope->current->outer)) ||
         ((*(char *)(*(int *)((int)scope + 4) + 8) == -6 && ((g_compile_flags_c8 & 0x10000000) == 0)
          ))) goto LAB_10437b23;
      g_qualified_lookup_found_overloads = 0;
    }
    pcVar3 = pcVar4;
    if ((pcVar5->flags2 & 0x10) == 0) {
      pcVar3 = sym_hiding_partner(pcVar5);
      if (pcVar3 == (c1_symbol *)0x0) goto LAB_10437b3b;
      if ((pcVar4->kind & 0x1f) == 0x12) {
        *(c1_symbol **)(*(int *)pcVar4->type + 8) = pcVar3;
        pcVar3 = pcVar4;
      }
    }
    pcVar1 = g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0xc;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      *(c1_symbol **)pcVar1 = pcVar3;
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
  return (c1_u8 *)0x0;
}

