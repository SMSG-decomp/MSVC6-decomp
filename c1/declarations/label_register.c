void __cdecl label_register(c1_symbol *label)

{
  uint uVar1;
  
  label->flags2 = label->flags2 | 2;
  if ((label->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar1 = label->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    label->entity = uVar1 & 0xffffff ^ label->entity;
  }
  if (g_function_labels != (c1_symbol *)0x0) {
    label->next = (c1_sym_link *)&g_function_labels->name;
    g_function_labels = label;
    return;
  }
  label->next = (c1_sym_link *)0x0;
  g_function_labels = label;
  return;
}

