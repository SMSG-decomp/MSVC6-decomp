void init_frame_layout_state(void)

{
  c2_symbol *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_symbol *sym;
  int iVar3;
  c2_symbol_chunk *chunk;
  
  g_stack_object_order_head = (c2_symbol *)0x0;
  g_stack_object_count = 0;
  g_stack_object_total_size = 0;
  g_stack_param_slot_count = 0;
  g_stack_object_table = (c2_symbol **)0x0;
  g_stack_interference = (c2_bitset **)0x0;
  g_stack_slot_count = 0;
  g_stack_local_bytes = 0;
  g_stack_slot_bias = 0;
  g_stack_param_list = (c2_symbol *)0x0;
  scope_for_each(1,clear_auto_home_flag_cb);
  g_frame_cursor = 0;
  if (g_frame_eh_record != (c2_fe_symbol *)0x0) {
    iVar3 = frame_alloc_local(g_frame_eh_record->size,0);
    pcVar2 = g_frame_eh_record;
    g_frame_eh_record->offset = iVar3;
    pcVar2->attrs = pcVar2->attrs | 0x800;
  }
  chunk = g_symbol_chunks;
  if ((g_opt_eh_enabled == 0) && (g_eh_guard_local != (c2_symbol *)0x0)) {
    pcVar2 = g_eh_guard_local->fe;
    iVar3 = frame_alloc_local(pcVar2->size,0);
    pcVar2->offset = iVar3;
    pcVar2->attrs = pcVar2->attrs | 0x800;
    chunk = g_symbol_chunks;
  }
  for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
    pcVar1 = chunk->cursor;
    for (sym = chunk->syms; sym < pcVar1; sym = sym + 1) {
      if ((sym->cls != '\x10') && ((sym->u38).index = -1, sym->cls == '\x05')) {
        sym->order_next = g_stack_param_list;
        g_stack_param_list = sym;
      }
    }
  }
  g_stack_param_set = bitset_new(6);
  return;
}

