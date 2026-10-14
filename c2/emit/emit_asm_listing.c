void __fastcall emit_asm_listing(c2_function *fn)

{
  uint8_t uVar1;
  c2_tuple *t;
  bool bVar2;
  uint32_t uVar3;
  int iVar4;
  c2_tuple *pcVar5;
  c2_fe_symbol *section;
  uint32_t uVar6;
  uint32_t code_offset;
  c2_function *local_10;
  c2_tuple *local_c;
  int saved_esp_adjust_params;
  int saved_esp_adjust_locals;
  c2_fe_symbol *label_sym;
  
  saved_esp_adjust_params = g_esp_adjust_params;
  saved_esp_adjust_locals = g_esp_adjust_locals;
  bVar2 = false;
  if (g_listing_on != 0) {
    local_10 = fn;
    if (g_opt_listing_source != 0) {
      listing_collect_lines(fn);
    }
    code_offset = 0xffffffff;
    uVar6 = 0;
    g_diag_line_needs_mapping = 0;
    g_current_line_abs = 0;
    pcVar5 = fn->cfg->first->head;
    section = g_ehtext_section;
    while (t = pcVar5, g_ehtext_section = section, t != (c2_tuple *)0x0) {
      if ((t->flags & 1) == 0) {
        local_c = t->next;
        uVar1 = t->kind;
        if (uVar1 == '\x17') {
          asm_print_proc((t->u14).fn);
          code_offset = g_cur_func_sym->offset;
          pcVar5 = local_c;
          section = g_ehtext_section;
          if (t->line != 0) {
            g_current_line_abs = line_to_file_line(fn->line_base + (uint)t->line,&g_cur_source_file)
            ;
            iVar4 = asm_print_file_header();
            pcVar5 = local_c;
            section = g_ehtext_section;
            if (iVar4 != 0) {
              uVar6 = 0;
            }
          }
        }
        else if (uVar1 == '\x18') {
          if (bVar2) {
            g_asm_current_segment = (c2_fe_symbol *)asm_print_segment_end(g_asm_current_segment);
          }
          asm_print_endp(fn);
          pcVar5 = local_c;
          section = g_ehtext_section;
        }
        else {
          pcVar5 = local_c;
          if (uVar1 == '\x1a') {
            label_sym = (c2_fe_symbol *)t->src;
            if (((label_sym->role == 'T') || (label_sym->role == 'U')) && (!bVar2)) {
              g_esp_adjust_params = 0;
              g_esp_adjust_locals = 0;
              bVar2 = true;
              if ((g_cur_func_sym->attrs & 0x20) != 0) {
                section = coff_select_data_section(g_cur_func_sym,section);
              }
              g_asm_current_segment = asm_switch_segment(section,0);
            }
            code_offset = label_sym->offset;
            if (t->line != 0) {
              g_current_line_abs =
                   line_to_file_line(local_10->line_base + (uint)t->line,&g_cur_source_file);
              iVar4 = asm_print_file_header();
              if (iVar4 != 0) {
                uVar6 = 0;
              }
            }
            uVar3 = g_current_line_abs;
            if (uVar6 != g_current_line_abs) {
              uVar6 = uVar3;
              if (g_opt_listing_source == 0) {
                asm_printf("; Line %ld",g_current_line_abs);
                g_asm_column = 0;
                asm_printf(g_asm_newline);
              }
              else {
                asm_print_source_lines(g_current_line_abs);
              }
            }
            asm_print_symbol_name(t->src);
            asm_printf(":");
            g_asm_column = 0;
            asm_printf(g_asm_newline);
            pcVar5 = local_c;
            fn = local_10;
            section = g_ehtext_section;
          }
        }
      }
      else {
        if (t->line != 0) {
          g_current_line_abs = line_to_file_line(fn->line_base + (uint)t->line,&g_cur_source_file);
          iVar4 = asm_print_file_header();
          if (iVar4 != 0) {
            uVar6 = 0;
          }
        }
        uVar3 = g_current_line_abs;
        if (uVar6 != g_current_line_abs) {
          uVar6 = uVar3;
          if (g_opt_listing_source == 0) {
            asm_printf("; Line %ld",g_current_line_abs);
            g_asm_column = 0;
            asm_printf(g_asm_newline);
          }
          else {
            asm_print_source_lines(g_current_line_abs);
          }
        }
        pcVar5 = asm_print_code_line(t,&code_offset);
        local_c = pcVar5->next;
        pcVar5 = local_c;
        section = g_ehtext_section;
      }
    }
    g_diag_line_needs_mapping = 1;
    g_esp_adjust_params = saved_esp_adjust_params;
    g_esp_adjust_locals = saved_esp_adjust_locals;
    arena_reset(4);
  }
  return;
}

