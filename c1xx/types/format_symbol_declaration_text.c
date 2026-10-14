int __cdecl format_symbol_declaration_text(c1_symbol *sym,c1_type *type)

{
  c1_symbol *key;
  bool bVar1;
  c1_symbol *sym_00;
  byte bVar2;
  int buf;
  int handle;
  char *s;
  void *pvVar3;
  c1_dlist_node *pcVar4;
  c1_type *type_00;
  int local_4;
  c1_dlist_node **tail_slot;
  
  buf = format_buffer_alloc();
  sym_00 = sym;
  bVar1 = false;
  local_4 = buf;
  if ((((g_format_name_flags & 8) == 0) && (sym != (c1_symbol *)0x0)) &&
     ((bVar2 = sym->kind & 0x1f, bVar2 == 7 || (bVar2 == 8)))) {
    if ((*(byte *)((int)&sym->tail + 9) & 0x20) == 0) {
      if (((byte)g_compile_flags_cc & 0x20) == 0) {
        if (((sym->scope_index != 0) &&
            (key = g_scope_vector->entries[(short)sym->scope_index], (key->kind & 0x1f) == 4)) &&
           ((((key->detail).cls)->flags3e & 1) != 0)) {
          pvVar3 = tmpl_template_of_instance(key);
          pvVar3 = tmpl_lookup_parameter_list(pvVar3);
          tail_slot = &g_format_template_arg_stack->prev;
          pcVar4 = dlist_node_new(g_format_template_arg_stack,g_format_template_arg_stack->prev);
          *tail_slot = pcVar4;
          bVar1 = true;
          pcVar4->prev->next = pcVar4;
          pcVar4->value = pvVar3;
          g_format_template_arg_depth = g_format_template_arg_depth + 1;
          buf = local_4;
        }
      }
      else if (g_current_scope->current->kind == 0xfa) {
        sym = (g_current_scope->current->body).cls;
        dlist_insert_before(&g_format_template_arg_stack,&local_4,(int *)g_format_template_arg_stack
                            ,(int *)&sym);
        bVar1 = true;
      }
    }
    else {
      sym = tmpl_lookup_parameter_list(sym);
      dlist_insert_before(&g_format_template_arg_stack,&local_4,(int *)g_format_template_arg_stack,
                          (int *)&sym);
      bVar1 = true;
    }
  }
  type_00 = type;
  if (type == (c1_type *)0x0) {
    if (sym_00 == (c1_symbol *)0x0) {
      return buf;
    }
    type_00 = sym_00->type;
  }
  if (((sym_00 == (c1_symbol *)0x0) || ((bVar2 = sym_00->kind & 0x1f, bVar2 != 7 && (bVar2 != 8))))
     || ((bVar2 = sym_00->flags1, (bVar2 & 0x10) != 0x10 &&
         (((bVar2 & 0x20) != 0x20 && ((bVar2 & 0x40) == 0)))))) {
    if ((sym_00 != (c1_symbol *)0x0) ||
       (sym = (c1_symbol *)((uint)sym & 0xffffff00),
       (-(uint)((type_00->code & 0x80) != 0) & (uint)type_00) != 0)) {
      sym = (c1_symbol *)CONCAT31(sym._1_3_,1);
    }
    format_type_name_text(buf,type_00,(char)sym);
  }
  handle = format_symbol_name_and_declarator(sym_00,type_00);
  s = format_buffer_text(handle);
  format_buffer_append_string(buf,s);
  format_buffer_free(handle);
  if ((bVar1) && (g_format_template_arg_depth != 0)) {
    pcVar4 = g_format_template_arg_stack->prev;
    pcVar4->prev->next = pcVar4->next;
    pcVar4->next->prev = pcVar4->prev;
    g_format_template_arg_depth = g_format_template_arg_depth + -1;
  }
  return buf;
}

