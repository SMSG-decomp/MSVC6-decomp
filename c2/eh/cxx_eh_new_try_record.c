c2_cxx_try_block * cxx_eh_new_try_record(void)

{
  c2_cxx_try_block *pcVar1;
  c2_fe_symbol *label_sym;
  
  pcVar1 = arena_alloc(1,0x34);
  pcVar1->index = g_eh_try_block_count;
  g_eh_try_block_count = g_eh_try_block_count + 1;
  pcVar1->trymap_next = (c2_cxx_try_block *)0x0;
  pcVar1->ncatches = 0;
  pcVar1->catches = (c2_cxx_catch *)0x0;
  (pcVar1->u24).catch_tail = (c2_cxx_catch *)0x0;
  label_sym = label_symbol_new();
  pcVar1->end_label = label_sym;
  tuple_new_label(label_sym);
  return pcVar1;
}

