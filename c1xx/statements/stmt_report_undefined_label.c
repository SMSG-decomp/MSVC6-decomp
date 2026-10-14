void __cdecl stmt_report_undefined_label(c1_symbol *label)

{
  c1_symbol *pcVar1;
  int iVar2;
  
  diag_error(0x5e,label);
  while( true ) {
    pcVar1 = label->next;
    if ((pcVar1 == (c1_symbol *)0x0) ||
       (label = (c1_symbol *)((int)&pcVar1[-1].tail + 4), label == (c1_symbol *)0x0)) {
      g_function_labels = (c1_symbol *)0x0;
      return;
    }
    if (((*(byte *)((int)&pcVar1[-1].tail + 6) & 4) == 0) && (pcVar1->entity == 0)) break;
    if (((pcVar1->position & 3) == 0) &&
       (iVar2._0_1_ = pcVar1->kind, iVar2._1_1_ = pcVar1->flags1, iVar2._2_1_ = pcVar1->flags2,
       iVar2._3_1_ = pcVar1->flags3, iVar2 != 0)) {
      stmt_warn_unreferenced_label(label);
      return;
    }
    if ((*(byte *)((int)&pcVar1[-1].tail + 6) & 4) != 0) {
      il_emit_symbol(3,label);
    }
  }
  stmt_report_undefined_label(label);
  return;
}

