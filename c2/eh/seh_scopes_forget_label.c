void __fastcall seh_scopes_forget_label(c2_function *fn,c2_fe_symbol *label)

{
  c2_seh_try_scope *scope;
  
  for (scope = fn->seh_try_scopes; scope != (c2_seh_try_scope *)0x0; scope = scope->next) {
    if (scope->filter_label == label) {
      scope->filter_label = (c2_fe_symbol *)0x0;
    }
    if (scope->handler_label == label) {
      scope->handler_label = (c2_fe_symbol *)0x0;
    }
    if (scope->finally_resume_label == label) {
      scope->finally_resume_label = (c2_fe_symbol *)0x0;
    }
    if (scope->continuation_label == label) {
      scope->continuation_label = (c2_fe_symbol *)0x0;
    }
    if (scope->body_end_label == label) {
      scope->body_end_label = (c2_fe_symbol *)0x0;
    }
  }
  return;
}

