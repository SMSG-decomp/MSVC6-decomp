void __fastcall warn_missing_return_value(c2_function *fn)

{
  c2_block *pcVar1;
  int must_return;
  c2_edge *pcVar2;
  
  if ((((g_opt_warn4715 != 0) && (((byte)fn->fsym->storage & 0xf) != 7)) &&
      (g_no_missing_return_warning == 0)) && (pcVar1 = fn->cfg->last, (pcVar1->flags & 1) != 0)) {
    must_return = analyze_return_paths(fn);
    if (((pcVar1->flags & 0x1000) == 0) && (pcVar2 = pcVar1->preds, pcVar2 != (c2_edge *)0x0)) {
      while ((pcVar2->flags & 0x40) != 0) {
        pcVar2 = pcVar2->next_pred;
        if (pcVar2 == (c2_edge *)0x0) {
          return;
        }
      }
      if (pcVar2 != (c2_edge *)0x0) {
        report_missing_return(fn,must_return);
      }
    }
  }
  return;
}

