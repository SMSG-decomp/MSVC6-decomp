c1_symbol * __cdecl
ovl_select_function_template_part(char report_errors,c1_symbol *fn,c1_type *type)

{
  c1_symbol *pcVar1;
  c1_deferred_action *pcVar2;
  
  pcVar1 = tmpl_deduce_from_target_type(type,fn,(-(report_errors != '\0') & 0xf8U) + 8);
  if (report_errors == '\0') {
    g_tmpl_deduction_depth = g_tmpl_deduction_depth + -1;
  }
  if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
    if (((report_errors != '\0') && (pcVar1 == (c1_symbol *)0x0)) &&
       (pcVar2 = g_deferred_actions_head, g_tmpl_deduction_depth < 1)) {
      do {
        (**pcVar2->vtbl)();
        pcVar2 = pcVar2->next;
      } while (pcVar2 != (c1_deferred_action *)0x0);
    }
    g_deferred_actions_tail = (c1_deferred_action *)0x0;
    g_deferred_actions_head = (c1_deferred_action *)0x0;
  }
  return pcVar1;
}

