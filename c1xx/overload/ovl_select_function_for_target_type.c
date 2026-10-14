c1_symbol * __cdecl
ovl_select_function_for_target_type
          (c1_symbol *sym,c1_type *type,int report_errors,char skip_single_check)

{
  char report_errors_00;
  char cVar1;
  c1_symbol *pcVar2;
  c1_deferred_action *pcVar3;
  
  report_errors_00 = (char)report_errors;
  if ((char)report_errors == '\0') {
    g_tmpl_deduction_depth = g_tmpl_deduction_depth + 1;
  }
  if (skip_single_check == '\0') {
    cVar1 = ovl_names_single_function(sym,'\0');
    if (cVar1 != '\0') {
      pcVar2 = sym_first_function_of_overload_set(sym,'\0');
      if ((*(byte *)((int)&pcVar2->tail + 9) & 0x20) != 0) {
        pcVar2 = ovl_select_function_template_part(report_errors_00,pcVar2,type);
        return pcVar2;
      }
      goto LAB_1043ee02;
    }
  }
  if (type == (c1_type *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((sym->name->flags & 0x8000000) != 0) {
    report_errors = 0;
    tmpl_deduce_from_function
              (type,sym,(short **)&report_errors,(-(report_errors_00 != '\0') & 0xf8U) + 8);
  }
  pcVar2 = (c1_symbol *)
           ovl_find_function_with_type(sym,type,0,1,(c1_symbol *)0x0,(c1_declarator *)0x0,0);
LAB_1043ee02:
  if (report_errors_00 == '\0') {
    g_tmpl_deduction_depth = g_tmpl_deduction_depth + -1;
  }
  if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
    if (((report_errors_00 != '\0') && (pcVar2 == (c1_symbol *)0x0)) &&
       (pcVar3 = g_deferred_actions_head, g_tmpl_deduction_depth < 1)) {
      do {
        (**pcVar3->vtbl)();
        pcVar3 = pcVar3->next;
      } while (pcVar3 != (c1_deferred_action *)0x0);
    }
    g_deferred_actions_tail = (c1_deferred_action *)0x0;
    g_deferred_actions_head = (c1_deferred_action *)0x0;
  }
  return pcVar2;
}

