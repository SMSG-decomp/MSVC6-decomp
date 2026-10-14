void __cdecl func_end_emit_il(c1_symbol *sym)

{
  c1_u32 *pcVar1;
  c1_symbol *sym_00;
  c1_u8 cVar2;
  uint uVar3;
  int iVar4;
  
  sym_00 = sym;
  if (g_opt_E_preprocess != 0) {
    return;
  }
  if (g_opt_Zg != '\0') {
    return;
  }
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  if (g_ilstore_status == 4) {
LAB_1042a4f5:
    if (g_c9il_mode != '\0') {
      il_buffer_flush(&g_il_sy);
      il_buffer_flush(&g_il_ex);
      goto LAB_1042a516;
    }
  }
  else if (g_c9il_mode != '\0') {
    if ((g_compile_flags_cc & 0x800) == 0) {
      cVar2 = il_buffer_reserve_ok(&g_il_in,1);
      if (cVar2 != '\0') {
        *g_il_in.bytes.cur = '\t';
        g_il_in.bytes.cur = g_il_in.bytes.cur + 1;
      }
      if (g_current_function == (c1_symbol *)0x0) {
        uVar3 = 0;
      }
      else if (g_c9il_mode == '\0') {
        if ((g_current_function->key_ref & 0xfffffff8) == 0) {
          uVar3 = il_symbol_key_assign(g_current_function);
        }
        else {
          uVar3 = g_current_function->key_ref >> 3;
        }
      }
      else {
        uVar3 = g_current_function->entity & 0xffffff;
      }
      func_in_write_key(&g_il_in,uVar3);
      if ((g_opt_E_preprocess != 0) || (g_opt_Zg != '\0')) goto LAB_1042a516;
    }
    goto LAB_1042a4f5;
  }
  if (g_ilstore_status != 4) {
    il_emit_tuple(0x4d,(node *)0x0);
    sym = (c1_symbol *)CONCAT31(sym._1_3_,((sym->flags21 & 1) != 0) + '\x01');
    if (g_c9il_mode == '\0') {
      if ((sym_00->key_ref & 0xfffffff8) == 0) {
        uVar3 = il_symbol_key_assign(sym_00);
      }
      else {
        uVar3 = sym_00->key_ref >> 3;
      }
    }
    else {
      uVar3 = sym_00->entity & 0xffffff;
    }
    ilstore_put_record(&g_il_ex,uVar3,(int)sym);
    ilstore_put_record(&g_il_sy,sym_00->key_ref >> 3,(int)sym);
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      iVar4 = func_wants_inline(sym_00);
      if ((char)iVar4 == '\0') {
        iVar4 = expr_string_pooling_enabled();
        if ((char)iVar4 == '\0') {
          il_buffer_append_buffer(&g_il_pending_init,&g_il_in);
        }
        cVar2 = il_buffer_reserve_ok(&g_il_in,1);
        if (cVar2 != '\0') {
          *g_il_in.bytes.cur = '\x0f';
          g_il_in.bytes.cur = g_il_in.bytes.cur + 1;
        }
        ilstore_put_record(&g_il_in,sym_00->key_ref >> 3,(int)sym);
      }
      else {
        ilstore_delete_record(&g_il_in,sym_00->key_ref >> 3);
      }
    }
  }
LAB_1042a516:
  g_compile_flags_cc = g_compile_flags_cc & 0xffffefff;
  g_function_record_block->records[g_function_record_index].symbol_entry =
       (c1_sym_link *)&sym_00->name;
  if ((g_pch_creating == 0) || (g_pch_written != 0)) {
    g_function_record_block->records[g_function_record_index].flags =
         g_function_record_block->records[g_function_record_index].flags & 0xffffffef;
  }
  else {
    g_function_record_block->records[g_function_record_index].flags =
         g_function_record_block->records[g_function_record_index].flags | 0x10;
    if (g_use_pch != '\0') {
      g_function_ex_offset = g_function_ex_offset + 0x3f4 + g_pch_header.ex_size;
      g_function_sy_offset = g_function_sy_offset + g_pch_header.sy_size;
    }
    if ((((sym_00->flags22 & 4) != 0) &&
        ((((sym_00->storage & 7) != 3 || ((sym_00->flags1 & 4) != 0)) &&
         ((sym_00->flags21 & 1) != 0)))) &&
       ((((sym_00->flags21 & 0x10) == 0 && (g_pch_automatic == '\0')) && (g_opt_noexpinl == '\0'))))
    {
      g_pch_object_has_code = 1;
    }
  }
  g_function_record_block->records[g_function_record_index].ex_offset = g_function_ex_offset;
  g_function_record_block->records[g_function_record_index].sy_offset = g_function_sy_offset;
  g_function_record_block->records[g_function_record_index].tuple_count = g_function_tuple_count;
  g_function_record_block->records[g_function_record_index].start_line = g_function_start_line;
  uVar3 = g_function_record_block->records[g_function_record_index].flags;
  g_function_record_block->records[g_function_record_index].flags =
       (uVar3 ^ g_function_auto_inline) & 1 ^ uVar3;
  pcVar1 = &g_function_record_block->records[g_function_record_index].flags;
  *pcVar1 = (g_function_has_body & 1U) << 1 | *pcVar1 & 0xfffffffd;
  pcVar1 = &g_function_record_block->records[g_function_record_index].flags;
  *pcVar1 = (g_function_not_inlinable & 1) << 2 | *pcVar1 & 0xfffffffb;
  g_function_record_block->records[g_function_record_index].flags =
       g_function_record_block->records[g_function_record_index].flags & 0xfffffff7;
  g_function_record_block->records[g_function_record_index].formal_count = g_function_formal_count;
  g_function_record_block->records[g_function_record_index].source_file = g_ilstore_module_ni;
  pcVar1 = &g_function_record_block->records[g_function_record_index].flags;
  *pcVar1 = ((byte)g_function_il_reused & 1) << 5 | *pcVar1 & 0xffffffdf;
  g_function_tuple_count = 0;
  g_function_il_reused = '\0';
  return;
}

