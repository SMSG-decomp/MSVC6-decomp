void __cdecl stmt_warn_unreferenced_label(c1_symbol *label)

{
  int position;
  c1_sym_link *link;
  
  position = sym_decl_position(label);
  diag_begin_global(position);
  diag_warning(3,0x66,label);
  diag_end_global();
  while( true ) {
    if ((label->flags1 & 1) != 0) {
      il_emit_symbol(3,label);
    }
    link = label->next;
    if ((link == (c1_sym_link *)0x0) ||
       (label = (c1_symbol *)&link[-1].position, label == (c1_symbol *)0x0)) break;
    if (((link[-1].position & 0x100) == 0) && (link[1].type == (c1_type *)0x0)) {
      stmt_report_undefined_label(label);
      return;
    }
    if ((((uint)link[1].name & 3) == 0) && (link->name != (fe_name *)0x0)) {
      stmt_warn_unreferenced_label(label);
      return;
    }
  }
  g_function_labels = (c1_symbol *)0x0;
  return;
}

