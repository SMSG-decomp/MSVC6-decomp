void __fastcall coff_record_function_fixup(uint32_t section)

{
  c2_coff_fn_section *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_coff_fn_section *pcVar3;
  void *pvVar4;
  
  pcVar3 = arena_alloc(0,8);
  pcVar2 = g_cur_func_sym;
  pcVar3->number = section;
  pcVar1 = pcVar2->incr->sections;
  pcVar2->incr->sections = pcVar3;
  pcVar3->next = pcVar1;
  pvVar4 = coff_chunked_array_get(g_coff_sections,section);
  *(byte *)((int)pvVar4 + 0x12) = *(byte *)((int)pvVar4 + 0x12) | 0x10;
  return;
}

