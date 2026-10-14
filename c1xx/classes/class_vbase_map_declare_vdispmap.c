c1_symbol * __cdecl class_vbase_map_declare_vdispmap(c1_vbase_map_key *key)

{
  c1_vbase_vector *pcVar1;
  ushort uVar2;
  c1_declarator *d;
  c1_decl_record *pcVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  fe_name *pfVar6;
  uint uVar7;
  int iVar8;
  c1xx_decl_specifiers *pcVar9;
  c1_u8 *pcVar10;
  bool bVar11;
  c1_vbase_map_key *key_00;
  c1_type local_34;
  c1xx_decl_specifiers local_24;
  
  d = arena_alloc(g_arenas + 5,0x58);
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    d->name = g_name_vdispmap;
    d->qualifier = (c1_overload_set *)0x0;
    d->op_token = '\x01';
    d->kind = 0;
    pcVar3 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar3 == (c1_decl_record *)0x0) {
      d->decl = (c1_decl_record *)0x0;
      d->position = g_token_position;
    }
    else {
      pcVar3 = decl_record_init_default(pcVar3,d->name,d->qualifier);
      d->decl = pcVar3;
      d->position = g_token_position;
    }
  }
  local_34.base = (c1_type *)0x0;
  local_34.debug_index = 0;
  local_34._0_4_ = (uint)local_34.flags << 0x10;
  uVar2 = decl_apply_default_calling_convention(0x83,0);
  local_34._0_4_ = CONCAT22(uVar2,local_34.code) | 0x200000;
  local_34.extra.cls = (c1_symbol *)0x0;
  pcVar4 = type_intern(&local_34);
  d->type = pcVar4;
  d->flags54 = d->flags54 | 0x28;
  key_00 = key;
  pcVar5 = sym_new_from_declarator(d,5);
  pfVar6 = class_vbase_map_decorated_name(pcVar5,key_00);
  d->name = pfVar6;
  local_24.spec[0] = local_24.spec[0] & 0xf9 | 1;
  pcVar9 = &local_24;
  for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
    pcVar9->spec[0] = '\0';
    pcVar9->spec[1] = '\0';
    pcVar9->spec[2] = '\0';
    pcVar9->spec[3] = '\0';
    pcVar9 = (c1xx_decl_specifiers *)(pcVar9->spec + 4);
  }
  local_24.spec[1] = local_24.spec[1] | 0x20;
  local_24.spec[0] = (local_24.spec[0] ^ 1) & 7 ^ local_24.spec[0] | 0x40;
  pcVar3 = d->decl;
  if (key->reverse == '\0') {
    pcVar5 = key->cls_b;
  }
  else {
    pcVar5 = key->cls_a;
  }
  pcVar1 = ((pcVar5->detail).cls)->vbases;
  if (pcVar1 == (c1_vbase_vector *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)pcVar1->count;
  }
  local_34._0_4_ = uVar7 + 1;
  local_34.base = (c1_type *)0x0;
  decl_append_array_layer(pcVar3,(int *)&local_34);
  local_24.type = type_int();
  decl_check_conversion_return_type(pcVar3,&local_24);
  decl_finish_declarator(pcVar3);
  pcVar9 = &local_24;
  pcVar10 = d->spec;
  for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9->spec;
    pcVar9 = (c1xx_decl_specifiers *)(pcVar9->spec + 4);
    pcVar10 = pcVar10 + 4;
  }
  if (((byte)g_compile_flags_cc & 8) == 0) {
    pcVar5 = decl_declare_and_check(d,local_24.spec);
  }
  else {
    g_compile_flags_c8 = g_compile_flags_c8 | 0x2000000;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    pcVar5 = decl_declare_and_check(d,local_24.spec);
    uVar7 = g_compile_flags_c8 & 0xfdffffff;
    if ((g_compile_flags_c8 & 0x30000000) == 0) {
      if ((((((g_compile_flags_c8 & 0x40000000) == 0) || (((byte)g_compile_flags_cc & 8) != 0)) ||
           ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
         (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
        g_context_arena_index = 5;
        g_expr_arena_index = 5;
        g_compile_flags_c8 = uVar7;
        if (((byte)g_compile_flags_cc & 1) != 0) {
          g_context_arena_index = 4;
          g_expr_arena_index = 4;
        }
        goto LAB_104b2d60;
      }
    }
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    g_compile_flags_c8 = uVar7;
  }
LAB_104b2d60:
  pcVar5->flags1 = pcVar5->flags1 & 0xfe | 2;
  if ((g_il_block_level != '\0') &&
     (bVar11 = g_c9il_mode == '\0', pcVar5->flags3 = bVar11 << 4 | pcVar5->flags3 & 0xef, bVar11)) {
    iVar8 = (*g_idb->vtbl->idb_note_global_il_record)(g_idb);
    if (iVar8 == 0) {
      diag_fatal(0x49,"p1inl.inl",0x2ee);
    }
  }
  return pcVar5;
}

