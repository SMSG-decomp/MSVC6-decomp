void __cdecl stmt_report_undefined_label(c1_symbol *label)

{
  c1_sym_link *link;
  
  diag_error(0x5e,label);
  while( true ) {
    link = label->next;
    if ((link == (c1_sym_link *)0x0) ||
       (label = (c1_symbol *)&link[-1].position, label == (c1_symbol *)0x0)) {
      g_function_labels = (c1_symbol *)0x0;
      return;
    }
    if (((link[-1].position & 0x100) == 0) && (link[1].type == (c1_type *)0x0)) break;
    if ((((uint)link[1].name & 3) == 0) && (link->name != (fe_name *)0x0)) {
      stmt_warn_unreferenced_label(label);
      return;
    }
    if ((link[-1].position & 0x100) != 0) {
      il_emit_symbol(3,label);
    }
  }
  stmt_report_undefined_label(label);
  return;
}

