void __cdecl pch_relocate_list_15bc(void)

{
  void *node;
  c1_class_instance_cell **ppcVar1;
  c1_class_instance_cell *slot;
  
  ppcVar1 = g_class_template_instances;
  if (g_class_template_instances == (c1_class_instance_cell **)0x0) {
    return;
  }
  pch_relocate_slot_once(&g_pch_image,(uint *)g_class_template_instances);
  slot = *ppcVar1;
  if (slot == (c1_class_instance_cell *)0x0) {
    return;
  }
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)slot);
    pch_relocate_slot_once(&g_pch_image,(uint *)&slot->bodies);
    pch_relocate_slot_once(&g_pch_image,(uint *)&slot->next);
    node = slot->bodies;
    if (node != (void *)0x0) {
      pch_relocate_token_record_list((int)node);
    }
    slot = slot->next;
  } while (slot != (c1_class_instance_cell *)0x0);
  return;
}

