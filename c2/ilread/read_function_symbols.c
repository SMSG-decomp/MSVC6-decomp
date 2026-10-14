void __fastcall read_function_symbols(c2_function *fn)

{
  c2_cv_scope **ppcVar1;
  byte bVar2;
  c2_list_cell *pcVar3;
  c2_reader_block *pcVar4;
  c2_reader_block *pcVar5;
  c2_cv_scope *pcVar6;
  uint uVar7;
  c2_fe_symbol *pcVar8;
  c2_fe_symbol *pcVar9;
  c2_list_cell *pcVar10;
  c2_reader_block *pcVar11;
  c2_fe_symbol *pcVar12;
  c2_scope_table *scope;
  c2_scope_table *scope_00;
  int local_4;
  
  if (fn == (c2_function *)0x0) {
    scope_00 = &g_global_scope;
    local_4 = 0;
  }
  else {
    scope_00 = fn->scope;
    local_4 = function_is_inline_candidate(fn->fsym,1);
  }
  if ((g_opt_debug_info != 0) && (fn != (c2_function *)0x0)) {
    pcVar6 = arena_alloc(1,0x18);
    pcVar6->symbols = (c2_list_cell *)0x0;
    g_cv_scope_tail = pcVar6;
    fn->cv_scopes = pcVar6;
    pcVar6->level = 0;
  }
switchD_10741dec_caseD_16:
  pcVar8 = il_read_fe_symbol_record(local_4);
  if (pcVar8 == (c2_fe_symbol *)0x0) {
    return;
  }
  pcVar12 = pcVar8;
  switch(pcVar8->cls) {
  case '\x01':
    uVar7 = pcVar8->storage;
    pcVar8->storage = uVar7 & 0xffff7fff;
    if ((((((uVar7 & 0x780) != 0x200) && ((uVar7 & 0x780) != 0x100)) &&
         ((uVar7 = uVar7 & 0x70, uVar7 == 0x20 || ((uVar7 == 0x50 || (uVar7 == 0x40)))))) &&
        ((pcVar8->attrs & 0x480) == 0)) && (((byte)pcVar8->attrs & 0x60) != 0x20)) {
      note_symbol_referenced(pcVar8);
    }
    fe_symbol_choose_section(pcVar8);
    scope = scope_00;
    if ((local_4 == 0) ||
       ((pcVar8->cls == '\x01' &&
        ((uVar7 = pcVar8->storage & 0x70, uVar7 == 0x10 || (uVar7 == 0x30)))))) {
LAB_10741cf6:
      scope_hash_insert(scope,pcVar8);
      pcVar12 = pcVar8;
    }
    else {
      pcVar12 = fe_scope_lookup_id(scope_00->parent,pcVar8->id);
      if (pcVar12 == (c2_fe_symbol *)0x0) {
        scope = scope_00->parent;
        goto LAB_10741cf6;
      }
    }
    if ((((byte)pcVar12->storage & 0x70) != 0x30) && ((pcVar12->attrs & 0x480) == 0)) {
      fe_symbol_assign_frame(pcVar12);
    }
    break;
  default:
    goto switchD_10741dec_caseD_2;
  case '\x03':
  case '\x05':
  case '\a':
  case '\b':
    goto switchD_10741dec_caseD_3;
  case '\x04':
    fe_symbol_choose_section(pcVar8);
    if (((byte)pcVar8->attrs & 0x1c) == 8) {
      pcVar8->storage = pcVar8->storage & 0xfffffbff | 0x300;
    }
    if ((pcVar8->storage & 0x4000) != 0) {
      if ((g_function_list_insert_link == (c2_fe_symbol **)0x0) ||
         ((int)(pcVar8->u4a).function.exp_offset <
          (int)((*g_function_list_insert_link)->u4a).function.exp_offset)) {
        g_function_list_insert_link = &g_function_list;
      }
      pcVar9 = *g_function_list_insert_link;
      if (pcVar9 != (c2_fe_symbol *)0x0) {
        do {
          if ((int)(pcVar8->u4a).function.exp_offset <= (int)(pcVar9->u4a).function.exp_offset)
          break;
          g_function_list_insert_link = &pcVar9->next_function;
          pcVar9 = pcVar9->next_function;
        } while (pcVar9 != (c2_fe_symbol *)0x0);
      }
      pcVar9 = *g_function_list_insert_link;
      *g_function_list_insert_link = pcVar8;
      pcVar8->next_function = pcVar9;
      if (g_pdb_il_mode != 0) {
        pcVar8->sym_offset = g_pdb_il_module_index;
      }
    }
    goto switchD_10741dec_caseD_3;
  case '\t':
    section_set_defaults(pcVar8);
    if ((pcVar8->u44).section_class == '\0') {
      (pcVar8->u3e).label_flags = g_code_section_align;
    }
    section_list_append(pcVar8);
    fe_symbol_hash_insert(pcVar8,0);
    break;
  case '\v':
    if (scope_00 != &g_global_scope) goto switchD_10741dec_caseD_3;
    pcVar8->next = g_global_class_b_symbols;
    g_global_class_b_symbols = pcVar8;
    break;
  case '\r':
    if (g_opt_debug_info != 0) {
      pcVar6 = arena_alloc(1,0x18);
      bVar2 = pcVar8->level;
      ppcVar1 = &g_cv_scope_tail->next;
      g_cv_scope_tail = pcVar6;
      *ppcVar1 = pcVar6;
      pcVar6->symbols = (c2_list_cell *)0x0;
      pcVar6->level = (ushort)bVar2;
    }
    if (g_reader_block_cursor != (c2_reader_block *)0x0) {
      pcVar11 = arena_alloc(1,0xc);
      pcVar4 = g_reader_block_cursor;
      pcVar5 = pcVar11;
      pcVar11->prev = g_reader_block_cursor;
      g_reader_block_cursor = pcVar5;
      pcVar4->next = pcVar11;
    }
    goto switchD_10741dec_caseD_16;
  case '\x12':
    source_file_record_add(pcVar8);
  case '\x16':
  case '\x17':
    goto switchD_10741dec_caseD_16;
  }
LAB_10741da3:
  if (g_cv_scope_tail != (c2_cv_scope *)0x0) {
    symbol_ref_list_add(&g_cv_scope_tail->symbols,pcVar12);
  }
  if ((g_reader_block_cursor != (c2_reader_block *)0x0) && (pcVar12->cls == '\x01')) {
    pcVar10 = arena_alloc(1,8);
    pcVar4 = g_reader_block_cursor;
    (pcVar10->u04).fe = pcVar12;
    pcVar3 = pcVar4->locals;
    pcVar4->locals = pcVar10;
    pcVar10->next = pcVar3;
  }
  goto switchD_10741dec_caseD_16;
switchD_10741dec_caseD_3:
  scope_hash_insert(scope_00,pcVar8);
  goto LAB_10741da3;
switchD_10741dec_caseD_2:
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x16f);
}

