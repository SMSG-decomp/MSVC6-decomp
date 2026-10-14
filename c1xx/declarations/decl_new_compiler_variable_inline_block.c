c1_symbol * __cdecl
decl_new_compiler_variable_inline_block
          (c1_symbol *func,c1_declarator *d,byte spec_byte0,byte storage,c1_type *type)

{
  c1_u8 *pcVar1;
  void *pvVar2;
  c1_symbol *pcVar3;
  c1_declarator *pcVar4;
  c1_decl_record *pcVar5;
  int iVar6;
  byte bVar7;
  c1_u32 *spec_word;
  c1_u32 *spec_word_2;
  c1_u32 *spec_dst;
  c1_type *pcStack00000024;
  
  pcVar1 = g_arenas[5].cur;
  if ((func->storage & 7) == 3) {
    g_arenas[5].cur = g_arenas[5].cur + 0x58;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if ((c1_declarator *)pcVar1 != d) {
      pvVar2 = name_new_S();
      *(void **)pcVar1 = pvVar2;
      *(c1_declarator **)(pcVar1 + 0x28) = d;
      pcVar1[0x30] = '\x01';
      *(c1_declarator **)(pcVar1 + 0x4c) = d;
      pcVar4 = arena_alloc(g_arenas + 5,0x4c);
      if (pcVar4 == d) {
        pcVar5 = (c1_decl_record *)0x0;
      }
      else {
        pcVar5 = decl_record_init_default
                           ((c1_decl_record *)pcVar4,*(void **)pcVar1,
                            *(c1_overload_set **)(pcVar1 + 0x28));
      }
      *(c1_decl_record **)(pcVar1 + 4) = pcVar5;
      *(int *)(pcVar1 + 0x24) = g_token_position;
      d = (c1_declarator *)pcVar1;
    }
  }
  else {
    g_arenas[5].cur = g_arenas[5].cur + 0x58;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if ((c1_declarator *)pcVar1 != d) {
      *(void **)pcVar1 = g_name_local_static_guard;
      *(c1_declarator **)(pcVar1 + 0x28) = d;
      pcVar1[0x30] = '\x01';
      *(c1_declarator **)(pcVar1 + 0x4c) = d;
      pcVar4 = arena_alloc(g_arenas + 5,0x4c);
      if (pcVar4 == d) {
        pcVar1[4] = '\0';
        pcVar1[5] = '\0';
        pcVar1[6] = '\0';
        pcVar1[7] = '\0';
        *(int *)(pcVar1 + 0x24) = g_token_position;
        d = (c1_declarator *)pcVar1;
      }
      else {
        pcVar5 = decl_record_init_default
                           ((c1_decl_record *)pcVar4,*(void **)pcVar1,
                            *(c1_overload_set **)(pcVar1 + 0x28));
        *(c1_decl_record **)(pcVar1 + 4) = pcVar5;
        *(int *)(pcVar1 + 0x24) = g_token_position;
        d = (c1_declarator *)pcVar1;
      }
    }
  }
  d->flags54 = d->flags54 | 0x20;
  if ((((byte)g_compile_flags_c4 & 0x20) != 0) && (storage != 3)) {
    storage = 3;
  }
  spec_byte0 = spec_byte0 ^ (spec_byte0 ^ storage) & 7;
  bVar7 = spec_byte0 & 7;
  spec_word_2 = (c1_u32 *)&spec_byte0;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  spec_byte0 = spec_byte0 ^ (spec_byte0 ^ bVar7) & 7;
  pcStack00000024 = type;
  decl_record_init(&stack0x00000030,type,g_default_decl_specifiers);
  decl_finish_declarator((c1_decl_record *)&stack0x00000030);
  d->decl = (c1_decl_record *)&stack0x00000030;
  spec_word = (c1_u32 *)&spec_byte0;
  spec_dst = (c1_u32 *)d->spec;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *spec_dst = *spec_word;
    spec_word = spec_word + 1;
    spec_dst = spec_dst + 1;
  }
  pcVar3 = decl_declare_and_check(d,&spec_byte0);
  return pcVar3;
}

