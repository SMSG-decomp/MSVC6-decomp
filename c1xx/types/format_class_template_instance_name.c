void __cdecl format_class_template_instance_name(int buf,c1_symbol *cls)

{
  c1_dlist_node *top;
  c1_dlist_node *top_2;
  c1_dlist_node *cell;
  c1_dlist_node *pcVar1;
  c1_dlist_node *stack_head;
  c1_dlist_node **tail_slot;
  
  if ((g_format_name_flags & 8) == 0) {
    top = tmpl_template_of_instance(cls);
    top_2 = tmpl_lookup_parameter_list(top);
    stack_head = g_format_template_arg_stack;
    pcVar1 = g_format_template_arg_stack->prev;
    tail_slot = &g_format_template_arg_stack->prev;
    cell = arena_alloc(g_arenas + 5,0xc);
    if (stack_head == (c1_dlist_node *)0x0) {
      stack_head = cell;
    }
    cell->next = stack_head;
    if (pcVar1 == (c1_dlist_node *)0x0) {
      pcVar1 = cell;
    }
    cell->prev = pcVar1;
    *tail_slot = cell;
    cell->prev->next = cell;
    cell->value = top_2;
    g_format_template_arg_depth = g_format_template_arg_depth + 1;
    format_undecorated_name(buf,cls->name);
    if (g_format_template_arg_depth != 0) {
      pcVar1 = g_format_template_arg_stack->prev;
      pcVar1->prev->next = pcVar1->next;
      pcVar1->next->prev = pcVar1->prev;
      g_format_template_arg_depth = g_format_template_arg_depth + -1;
    }
    return;
  }
  format_undecorated_name(buf,cls->name);
  return;
}

