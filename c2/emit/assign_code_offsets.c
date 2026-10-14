void __fastcall assign_code_offsets(c2_function *fn,int align_jump_tables)

{
  char cVar1;
  c2_fe_symbol *sym;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  bool bVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  uint uVar7;
  uint32_t cur_offset;
  uint32_t uVar8;
  c2_fe_symbol *cur_section;
  int in_prolog;
  uint32_t text_end_offset;
  int saved_esp_adjust_locals;
  int saved_esp_adjust_params;
  
  saved_esp_adjust_locals = g_esp_adjust_locals;
  saved_esp_adjust_params = g_esp_adjust_params;
  sym = fn->fsym;
  bVar4 = false;
  cur_section = fe_symbol_lookup_id(sym->section_id);
  cur_offset = 0xffffffff;
  pcVar6 = fn->cfg->first->head;
  while (pcVar6 != (c2_tuple *)0x0) {
    pcVar2 = pcVar6->next;
    if ((pcVar6->line != 0) &&
       (g_current_line_abs = fn->line_base + (uint)pcVar6->line, g_func_source_file == (char *)0x0))
    {
      g_func_first_line = line_to_file_line(g_current_line_abs,&g_func_source_file);
    }
    switch(pcVar6->kind) {
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
      cur_offset = cur_offset + pcVar6->flags12;
      break;
    case '\x16':
      switch(pcVar6->op) {
      case 0x1b4:
        if (pcVar6->flags12 == '\0') {
          if (in_prolog != 0) {
            in_prolog = 0;
            if (cur_offset == 0xffffffff) {
              uVar8 = 0;
            }
            else {
              uVar8 = cur_offset - sym->offset;
            }
            sym->dbg_start = uVar8;
          }
          if ((g_opt_global == 0) && (g_opt_debug_info != 0)) {
            pcVar6->src->op = cur_offset;
          }
        }
        break;
      case 0x1b5:
        if (((pcVar6->flags12 == '\0') && (g_opt_global == 0)) && (g_opt_debug_info != 0)) {
          pcVar3 = pcVar6->src;
          pcVar3->kind = (char)cur_offset;
          pcVar3->flags9 = (char)(cur_offset >> 8);
          pcVar3->type = (short)(cur_offset >> 0x10);
        }
        break;
      case 0x1b7:
        if (cur_offset == 0xffffffff) {
          sym->dbg_end = 0;
        }
        else {
          sym->dbg_end = cur_offset - sym->offset;
        }
        break;
      case 0x1ba:
        uVar7 = (int)(pcVar6->u14).arg - cur_offset & (int)(pcVar6->u14).arg - 1U;
        if ((uVar7 != 0) && (align_jump_tables != 0)) {
          pcVar6 = tuple_new_nooperands(0xa9,0x6000,tuple_insert_before,pcVar6);
          pcVar6->flags12 = (uint8_t)uVar7;
          pcVar6->flags = pcVar6->flags | 2;
        }
        cur_offset = cur_offset + uVar7;
      }
      break;
    case '\x17':
      if (g_opt_cbstring == 0) {
        in_prolog = 1;
        cur_offset = cur_section->offset;
        sym->offset = cur_offset;
      }
      else {
        in_prolog = 1;
        cur_offset = cur_section->offset;
        sym->offset = cur_offset;
      }
      break;
    case '\x18':
      if (bVar4) {
        cur_offset = text_end_offset;
      }
      if (cur_offset == 0xffffffff) {
        sym->code_size = 0;
      }
      else {
        sym->code_size = cur_offset - sym->offset;
      }
      break;
    case '\x1a':
      cVar1 = *(char *)&pcVar6->src[1].next;
      uVar8 = cur_offset;
      if (cVar1 == '\x02') {
        if ((((align_jump_tables != 0) && (pcVar6->next->op == 0xbb)) &&
            ((pcVar6->next->type & 0xfff) == 4)) &&
           ((g_opt_favor_speed != 0 && (g_opt_global != 0)))) {
          uVar7 = -cur_offset & 3;
          if (uVar7 != 0) {
            pcVar5 = tuple_new_nooperands(0xa9,0x6000,tuple_insert_before,pcVar6);
            pcVar5->flags12 = (uint8_t)uVar7;
          }
          uVar8 = cur_offset + uVar7;
        }
      }
      else if (((cVar1 == 'T') || (cVar1 == 'U')) && (!bVar4)) {
        g_esp_adjust_params = 0;
        g_esp_adjust_locals = 0;
        bVar4 = true;
        if (((sym->attrs & 0x20) == 0) && (g_opt_incremental == 0)) {
          cur_section = g_ehtext_section;
        }
        else {
          cur_section = coff_select_data_section(sym,g_ehtext_section);
        }
        uVar8 = cur_section->offset;
        text_end_offset = cur_offset;
      }
      pcVar3 = pcVar6->src;
      cur_offset = cur_section->id;
      pcVar3->rank = uVar8;
      pcVar3->disp = cur_offset;
      cur_offset = uVar8;
    }
    pcVar6 = pcVar2;
  }
  g_esp_adjust_params = saved_esp_adjust_params;
  g_esp_adjust_locals = saved_esp_adjust_locals;
  return;
}

