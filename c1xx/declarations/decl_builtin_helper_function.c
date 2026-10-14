void __cdecl
decl_builtin_helper_function
          (void *name,int pointee,int modifier,int unused,int helper_kind,char not_eh)

{
  c1_decl_record *pcVar1;
  c1_type *pcVar2;
  int iVar3;
  c1_declarator *d;
  c1_u32 *spec_word;
  c1_u8 *pcVar4;
  c1_u32 *spec_word_2;
  c1_decl_modifier layer_modifier;
  c1xx_decl_specifiers local_24;
  
  d = (c1_declarator *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    d->name = name;
    *(c1_u8 *)((int)d + 0x28) = '\0';
    *(c1_u8 *)((int)d + 0x29) = '\0';
    *(c1_u8 *)((int)d + 0x2a) = '\0';
    *(c1_u8 *)((int)d + 0x2b) = '\0';
    *(c1_u8 *)((int)d + 0x30) = '\x01';
    *(c1_u8 *)((int)d + 0x4c) = '\0';
    *(c1_u8 *)((int)d + 0x4d) = '\0';
    *(c1_u8 *)((int)d + 0x4e) = '\0';
    *(c1_u8 *)((int)d + 0x4f) = '\0';
    pcVar1 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar1 == (c1_decl_record *)0x0) {
      *(c1_u8 *)((int)d + 4) = '\0';
      *(c1_u8 *)((int)d + 5) = '\0';
      *(c1_u8 *)((int)d + 6) = '\0';
      *(c1_u8 *)((int)d + 7) = '\0';
      *(int *)((int)d + 0x24) = g_token_position;
    }
    else {
      pcVar1 = decl_record_init_default(pcVar1,d->name,*(c1_overload_set **)((int)d + 0x28));
      *(c1_decl_record **)((int)d + 4) = pcVar1;
      *(int *)((int)d + 0x24) = g_token_position;
    }
  }
  d->flags54 = d->flags54 | 0x20;
  pcVar4 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar4 == (c1_u8 *)0x0) {
    pcVar4 = (c1_u8 *)0x0;
  }
  else {
    pcVar4[0x10] = '\x04';
    pcVar4[0x11] = '\0';
    pcVar4[0x12] = '\0';
    pcVar4[0x13] = '\0';
    pcVar4[0x14] = '\0';
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
  }
  pcVar2 = type_pointer_to((c1_u16)pointee);
  param_list_add_compiler_formal(pcVar4,(void *)0x0,pcVar2);
  param_list_add_compiler_formal(pcVar4,(void *)0x0,PTR_104d151c);
  param_list_add_compiler_formal(pcVar4,(void *)0x0,g_type_int);
  pcVar2 = type_record_new_45f0(pointee,(ushort)modifier);
  param_list_add_compiler_formal(pcVar4,(void *)0x0,pcVar2);
  if ((helper_kind == 0xe) || (helper_kind == 0xf)) {
    pcVar2 = type_record_new_45f0(pointee,(ushort)modifier);
    param_list_add_compiler_formal(pcVar4,(void *)0x0,pcVar2);
  }
  pcVar1 = d->decl;
  layer_modifier.bits._0_2_ = 5;
  layer_modifier.based = (void *)0x0;
  type_check_based_form(pcVar1,&layer_modifier);
  decl_append_function_layer((int *)pcVar1,pcVar4);
  local_24.spec[0] = local_24.spec[0] & 0xf9 | 1;
  spec_word_2 = (c1_u32 *)&local_24;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  local_24.spec[0] = local_24.spec[0] ^ (local_24.spec[0] ^ 1) & 7;
  if (not_eh != '\0') {
    local_24.spec[0] = local_24.spec[0] | 0x40;
  }
  local_24.type = g_type_void;
  decl_check_conversion_return_type(pcVar1,&local_24);
  decl_finish_declarator(pcVar1);
  d->special_kind = (c1_u8)helper_kind;
  if ((helper_kind != 0) && ((helper_kind < 0xe || (0x10 < helper_kind)))) {
    d->flags56 = d->flags56 | 4;
  }
  spec_word = (c1_u32 *)&local_24;
  pcVar4 = d->spec;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(c1_u32 *)pcVar4 = *spec_word;
    spec_word = spec_word + 1;
    pcVar4 = pcVar4 + 4;
  }
  decl_declare_and_check(d,local_24.spec);
  return;
}

