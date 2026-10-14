void il_emit_function_labels(void)

{
  c1_symbol *label;
  
  label = g_function_labels;
  if (g_error_count == 0) {
    for (; label != (c1_symbol *)0x0; label = (c1_symbol *)&label->next[-1].position) {
      if (((label->flags1 & 1) == 0) && (label->detail == (void *)0x0)) {
        stmt_report_undefined_label(label);
        return;
      }
      if (((label->key_ref & 3) == 0) && (label->name != (fe_name *)0x0)) {
        stmt_warn_unreferenced_label(label);
        return;
      }
      if ((label->flags1 & 1) != 0) {
        il_emit_symbol(3,label);
      }
      if (label->next == (c1_sym_link *)0x0) {
        g_function_labels = (c1_symbol *)0x0;
        return;
      }
    }
  }
  g_function_labels = (c1_symbol *)0x0;
  return;
}

