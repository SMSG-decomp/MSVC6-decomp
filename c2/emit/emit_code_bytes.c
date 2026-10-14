void __fastcall emit_code_bytes(c2_function *fn)

{
  char cVar1;
  c2_tuple *t;
  c2_fe_symbol *sym;
  uint32_t uVar2;
  c2_fe_symbol *sym_00;
  char *pcVar3;
  uint uVar4;
  uint32_t offset;
  uint uVar5;
  c2_fe_symbol *sym_01;
  uint8_t *puVar6;
  c2_fe_symbol *ehtext_label;
  uint32_t prev_line;
  char *prev_file;
  uint32_t ehtext_start_offset;
  char *file_name;
  int file_line;
  int saved_esp_adjust_params;
  int saved_esp_adjust_locals;
  uint8_t code_buf [64];
  c2_fe_symbol *label_sym;
  
  sym_00 = fn->fsym;
  saved_esp_adjust_locals = g_esp_adjust_locals;
  sym_01 = (c2_fe_symbol *)0x0;
  saved_esp_adjust_params = g_esp_adjust_params;
  ehtext_label = (c2_fe_symbol *)0x0;
  ehtext_start_offset = 0;
  sym = fe_symbol_lookup_id(sym_00->section_id);
  offset = 0xffffffff;
  prev_line = 0;
  g_current_line_abs = 0;
  prev_file = (char *)0x0;
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if ((((t->flags & 1) != 0) && (t->line != 0)) &&
       (uVar2 = fn->line_base + (uint)t->line, g_current_line_abs = uVar2, prev_line != uVar2)) {
      file_line = line_to_file_line(uVar2,&file_name);
      if (file_name != prev_file) {
        prev_file = file_name;
        (*g_hook_lines_file_changed)(file_name);
      }
      if (sym_01 != sym) {
        (*g_hook_pad_section)(sym);
        sym_01 = sym;
      }
      (*g_hook_lines_add_entry)(file_line,offset);
      prev_line = uVar2;
    }
    switch(t->kind) {
    case '\f':
    case '\r':
    case '\x0e':
    case '\x0f':
    case '\x10':
    case '\x11':
    case '\x12':
    case '\x13':
    case '\x14':
    case '\x15':
      uVar2 = encode_instruction(t,code_buf,offset,1,sym_01);
      (*g_hook_write_code_bytes)(code_buf,uVar2);
      offset = offset + uVar2;
      sym_01->offset = sym_01->offset + uVar2;
      break;
    case '\x17':
      offset = sym_00->offset;
      (*g_hook_pad_section)(sym);
      if ((g_opt_cbstring != 0) && (offset != sym->offset)) {
        uVar4 = offset - sym->offset;
        puVar6 = code_buf;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          puVar6[0] = '\0';
          puVar6[1] = '\0';
          puVar6[2] = '\0';
          puVar6[3] = '\0';
          puVar6 = puVar6 + 4;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = '\0';
          puVar6 = puVar6 + 1;
        }
        (*g_hook_write_code_bytes)(code_buf,uVar4);
        sym->offset = sym->offset + uVar4;
      }
      (*g_hook_lines_function_done)(sym_00);
      sym_01 = sym;
      break;
    case '\x1a':
      label_sym = (c2_fe_symbol *)t->src;
      cVar1 = label_sym->role;
      if (((cVar1 == 'T') || (cVar1 == 'U')) && (ehtext_label == (c2_fe_symbol *)0x0)) {
        g_esp_adjust_params = 0;
        g_esp_adjust_locals = 0;
        if (((sym_00->attrs & 0x20) != 0) || (sym_01 = g_ehtext_section, g_opt_incremental != 0)) {
          sym_01 = coff_select_data_section(sym_00,g_ehtext_section);
        }
        (*g_hook_pad_section)(sym_01);
        ehtext_label = label_sym;
        ehtext_start_offset = offset;
      }
      offset = t->src->rank;
    }
  }
  g_esp_adjust_params = saved_esp_adjust_params;
  g_esp_adjust_locals = saved_esp_adjust_locals;
  (*g_hook_pad_section)(sym);
  (*g_hook_emit_line_symbols)(sym_00);
  if ((g_opt_favor_speed != 0) && (g_opt_global != 0)) {
    if (ehtext_label != (c2_fe_symbol *)0x0) {
      offset = ehtext_start_offset;
    }
    uVar5 = offset - sym_00->offset & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    uVar5 = 0x10 - uVar5 & 0x8000000f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xfffffff0) + 1;
    }
    if (0 < (int)uVar5) {
      puVar6 = code_buf;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        puVar6[0] = 0x90;
        puVar6[1] = 0x90;
        puVar6[2] = 0x90;
        puVar6[3] = 0x90;
        puVar6 = puVar6 + 4;
      }
      for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = 0x90;
        puVar6 = puVar6 + 1;
      }
    }
    (*g_hook_write_code_bytes)(code_buf,uVar5);
    sym->offset = sym->offset + uVar5;
  }
  if (((fn->flags & 0x40000) != 0) && ((fn->flags & 0x80000) == 0)) {
    if ((sym_00->storage & 0x1000) != 0) {
      sym_00 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)sym_00);
    }
    pcVar3 = fe_symbol_name(sym_00,1);
    warning(1,799,pcVar3);
  }
  return;
}

