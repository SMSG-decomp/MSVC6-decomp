void incr_remap_function_section_indices(void)

{
  c2_coff_fn_section *pcVar1;
  c2_fe_symbol *pcVar2;
  uint32_t uVar3;
  
  for (pcVar2 = g_incr_compiled_functions; pcVar2 != (c2_fe_symbol *)0x0;
      pcVar2 = pcVar2->next_function) {
    for (pcVar1 = pcVar2->incr->sections; pcVar1 != (c2_coff_fn_section *)0x0; pcVar1 = pcVar1->next
        ) {
      uVar3 = coff_section_symbol_index(pcVar1->number);
      pcVar1->number = uVar3;
    }
  }
  return;
}

