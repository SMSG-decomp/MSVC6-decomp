uint32_t index_stack_objects(void)

{
  c2_symbol *pcVar1;
  uint32_t n;
  
  n = 0;
  for (pcVar1 = g_stack_object_order_head; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->order_next)
  {
    g_stack_object_table[n] = pcVar1;
    if (pcVar1->cls == '\x05') {
      bitset_set(g_stack_param_set,n);
      g_stack_param_slot_count = g_stack_param_slot_count + 1;
    }
    (pcVar1->u38).index = n;
    g_stack_object_total_size = g_stack_object_total_size + pcVar1->size;
    n = n + 1;
  }
  return n;
}

