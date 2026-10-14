void __fastcall tmpl_deferred_report_c2893(c1xx_obj_104ceea4 *action)

{
  c1_arg_item *pcVar1;
  
  diag_begin_global(g_token_position);
  diag_error(0x37d,action->tmpl);
  if (action->args != (c1_arg_list *)0x0) {
    pcVar1 = action->args->first;
    diag_note(0x190a);
    for (; pcVar1 != (c1_arg_item *)0x0; pcVar1 = pcVar1->next) {
      if ((pcVar1->kind & 3) == 0) {
        diag_note(0x190b,(pcVar1->value).type);
      }
    }
  }
  diag_end_global();
  return;
}

