void __fastcall emit_eh_section_symbols(c2_function *fn)

{
  c2_fe_symbol *pcVar1;
  c2_cv_scope *pcVar2;
  c2_list_cell **link;
  c2_list_cell *cell;
  uint32_t ehtext_id;
  
  pcVar2 = fn->cv_scopes;
  if (pcVar2 != (c2_cv_scope *)0x0) {
    if (((fn->fsym->attrs & 0x20) != 0) || (pcVar1 = g_ehtext_section, g_opt_incremental != 0)) {
      pcVar1 = coff_select_data_section(fn->fsym,g_ehtext_section);
    }
    ehtext_id = pcVar1->id;
    do {
      link = &pcVar2->symbols;
      for (cell = pcVar2->symbols; cell != (c2_list_cell *)0x0; cell = cell->next) {
        pcVar1 = (cell->u04).fe;
        if ((pcVar1->cls == '\x03') && (pcVar1->section_id == ehtext_id)) {
          emit_symbol_definition_edx0(pcVar1);
          *link = cell->next;
        }
        else {
          link = &(*link)->next;
        }
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != (c2_cv_scope *)0x0);
  }
  return;
}

