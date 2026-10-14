c1_symbol * __cdecl decl_declare_anonymous_union_object(c1xx_decl_specifiers *spec)

{
  void *pvVar1;
  c1_decl_record *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  c1_declarator *d;
  c1xx_decl_specifiers *pcVar5;
  c1_u8 *pcVar6;
  
  pcVar6 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  d = (c1_declarator *)0x0;
  if (pcVar6 != (c1_u8 *)0x0) {
    pvVar1 = name_new_S();
    *(void **)pcVar6 = pvVar1;
    pcVar6[0x28] = '\0';
    pcVar6[0x29] = '\0';
    pcVar6[0x2a] = '\0';
    pcVar6[0x2b] = '\0';
    pcVar6[0x30] = '\x01';
    pcVar6[0x4c] = '\0';
    pcVar6[0x4d] = '\0';
    pcVar6[0x4e] = '\0';
    pcVar6[0x4f] = '\0';
    pcVar2 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar2 == (c1_decl_record *)0x0) {
      pcVar2 = (c1_decl_record *)0x0;
    }
    else {
      pcVar2 = decl_record_init_default
                         (pcVar2,*(void **)pcVar6,*(c1_overload_set **)(pcVar6 + 0x28));
    }
    *(c1_decl_record **)(pcVar6 + 4) = pcVar2;
    *(int *)(pcVar6 + 0x24) = g_token_position;
    d = (c1_declarator *)pcVar6;
  }
  pcVar2 = d->decl;
  d->flags54 = d->flags54 | 0x20;
  decl_check_conversion_return_type(pcVar2,spec);
  decl_finish_declarator(pcVar2);
  pcVar5 = spec;
  pcVar6 = d->spec;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5->spec;
    pcVar5 = (c1xx_decl_specifiers *)(pcVar5->spec + 4);
    pcVar6 = pcVar6 + 4;
  }
  pcVar3 = decl_declare_from_declarator(d,spec->spec);
  return pcVar3;
}

