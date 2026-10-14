int * __thiscall scope_lookup_for_declaration_innermost(c1_scope_stack *stack,c1_declarator *d)

{
  c1_u8 *pcVar1;
  c1xx_scope *pcVar2;
  c1_lookup_result *pcVar3;
  c1_symbol *pcVar4;
  c1_lookup_entry *pcVar5;
  int *piVar6;
  
  pcVar2 = scope_innermost_declaration_record(stack,'\0');
  pcVar3 = (*pcVar2->vtbl->lookup)(pcVar2,d->name,1);
  if (pcVar3 == (c1_lookup_result *)0x0) {
    pcVar4 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
    if (pcVar4 == (c1_symbol *)0x0) goto LAB_1040475a;
    piVar6 = arena_alloc(g_arenas + 5,0xc);
  }
  else {
    pcVar5 = lookup_check_ambiguous_symbol(pcVar3,'\x01');
    if ((pcVar5 == (c1_lookup_entry *)0x0) ||
       (pcVar4 = decl_redeclare_or_new(d,pcVar5->sym), pcVar4 == (c1_symbol *)0x0))
    goto LAB_1040475a;
    piVar6 = arena_alloc(g_arenas + 5,0xc);
  }
  if (piVar6 != (int *)0x0) {
    *piVar6 = (int)pcVar4;
    piVar6[1] = 0;
    piVar6[2] = 0;
    if (piVar6 != (int *)0x0) {
      return piVar6;
    }
  }
LAB_1040475a:
  if ((((pcVar2->kind != 0xfa) || (g_tmpl_binding_in_progress != '\0')) ||
      ((g_compile_flags_c8 & 0x10000000) != 0)) ||
     (pcVar2 = pcVar2->outer, pcVar2 == (c1xx_scope *)0x0)) {
    return (int *)0x0;
  }
  pcVar3 = (*pcVar2->vtbl->lookup)(pcVar2,d->name,1);
  if (pcVar3 == (c1_lookup_result *)0x0) {
    pcVar4 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
    pcVar1 = g_arenas[5].cur;
    if (pcVar4 != (c1_symbol *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 != (c1_u8 *)0x0) {
        *(c1_symbol **)pcVar1 = pcVar4;
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        return (int *)pcVar1;
      }
    }
  }
  else {
    pcVar5 = lookup_check_ambiguous_symbol(pcVar3,'\x01');
    if ((pcVar5 != (c1_lookup_entry *)0x0) &&
       (pcVar4 = decl_redeclare_or_new(d,pcVar5->sym), pcVar1 = g_arenas[5].cur,
       pcVar4 != (c1_symbol *)0x0)) {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 != (c1_u8 *)0x0) {
        *(c1_symbol **)pcVar1 = pcVar4;
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        return (int *)pcVar1;
      }
    }
  }
  return (int *)0x0;
}

