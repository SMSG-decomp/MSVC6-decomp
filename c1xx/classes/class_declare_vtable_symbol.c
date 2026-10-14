c1_symbol * __cdecl class_declare_vtable_symbol(int table_kind,c1_vtable_record *rec,c1_symbol *cls)

{
  uint uVar1;
  uint uVar2;
  c1_declarator *d;
  fe_name *pfVar3;
  c1_decl_record *pcVar4;
  c1_u8 *pcVar5;
  c1_symbol *sym;
  int iVar6;
  uint uVar7;
  c1_u32 *spec_word;
  c1_u32 *spec_word_2;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  c1_u16 local_34 [2];
  uint ptr_extra_word1;
  ushort local_2c [2];
  uint ptr_mods_position;
  c1xx_decl_specifiers local_24;
  
  d = arena_alloc(g_arenas + 5,0x58);
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    pfVar3 = g_name_local_vftable;
    if ((table_kind != 5) && ((rec->kind == 0 || (pfVar3 = g_name_vbtable, rec->kind == 2)))) {
      pfVar3 = g_name_vftable;
    }
    d->name = pfVar3;
    d->qualifier = (c1_overload_set *)0x0;
    d->op_token = '\x01';
    d->kind = 0;
    pcVar4 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar4 == (c1_decl_record *)0x0) {
      d->decl = (c1_decl_record *)0x0;
      d->position = g_token_position;
    }
    else {
      pcVar4 = decl_record_init_default(pcVar4,d->name,d->qualifier);
      d->decl = pcVar4;
      d->position = g_token_position;
    }
  }
  d->flags54 = d->flags54 | 0x20;
  if ((table_kind == 0) || (table_kind == 5)) {
    d->flags56 = d->flags56 | 0x80;
  }
  d->unk3c = (c1_u32)rec;
  d->type = g_type_const_int;
  class_vtable_declarator_set_decorated_name(d,cls);
  d->type = (c1_type *)0x0;
  local_24.spec[0] = local_24.spec[0] & 0xf9 | 1;
  spec_word_2 = (c1_u32 *)&local_24;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  local_24.spec[0] = local_24.spec[0] ^ (local_24.spec[0] ^ 1) & 7;
  if ((table_kind != 5) && ((cls->flags22 & 0xc) != 0)) {
    local_24.spec[2] = local_24.spec[2] ^ (cls->flags22 ^ local_24.spec[2]) & 0xc;
  }
  pcVar4 = d->decl;
  if (table_kind != 0) {
    if (table_kind == 1) {
      local_44 = rec->nslots;
      local_40 = local_44 >> 0x1f;
      decl_append_array_layer(pcVar4,&local_44);
      local_24.type = type_int();
      local_24.type = type_with_added_qualifiers(local_24.type,rec->cv);
      goto LAB_1043a4d0;
    }
    if (table_kind != 5) goto LAB_1043a4d0;
  }
  local_3c = rec->nslots;
  local_38 = local_3c >> 0x1f;
  decl_append_array_layer(pcVar4,&local_3c);
  local_34[0] = rec->cv;
  ptr_extra_word1 = 0;
  local_2c[0] = 0;
  ptr_mods_position = 0;
  decl_add_pointer_modifier(pcVar4,local_2c,local_34);
  pcVar5 = class_record_new_kind5();
  decl_append_function_layer((int *)pcVar4,pcVar5);
  local_24.type = g_type_void;
LAB_1043a4d0:
  decl_check_conversion_return_type(pcVar4,&local_24);
  decl_finish_declarator(pcVar4);
  spec_word = (c1_u32 *)&local_24;
  pcVar5 = d->spec;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(c1_u32 *)pcVar5 = *spec_word;
    spec_word = spec_word + 1;
    pcVar5 = pcVar5 + 4;
  }
  if (((byte)g_compile_flags_cc & 8) == 0) {
    sym = decl_declare_and_check(d,local_24.spec);
    pcVar5 = g_arenas[0].cur;
    if (g_block_depth != '\0') {
      g_arenas[0].cur = g_arenas[0].cur + (g_symbol_size_table[sym->kind & 0x1f] + 3 & 0xfffffffc);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar5 == (c1_u8 *)0x0) {
        sym = (c1_symbol *)0x0;
      }
      else {
        sym = sym_copy_unlinked((c1_symbol *)pcVar5,sym,0);
      }
      sym->next = (c1_symbol *)0x0;
      (*g_current_scope->global_scope->vtbl->insert)(sym);
    }
  }
  else {
    g_compile_flags_c8 = g_compile_flags_c8 | 0x2000000;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    sym = decl_declare_and_check(d,local_24.spec);
    uVar2 = g_compile_flags_c8;
    uVar7 = g_compile_flags_c8 & 0xfdffffff;
    uVar1 = g_compile_flags_c8 & 0x30000000;
    g_compile_flags_c8 = uVar7;
    if ((((uVar1 != 0) ||
         ((((uVar2 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
          ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x10) != 0)) ||
       (((uVar2 & 0x4000000) != 0 && ((g_compile_flags_c4 & 0x8000) == 0)))) {
      g_context_arena_index = 0;
      g_expr_arena_index = 0;
      return sym;
    }
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return sym;
    }
  }
  return sym;
}

