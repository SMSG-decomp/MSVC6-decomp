c1_ovl_candidate * __fastcall ovl_resolve_call_no_best(c1_ovl_resolution *res)

{
  c1_ovl_candidate *pcVar1;
  c1_ovl_candidate *pcVar2;
  bool bVar3;
  
  ovl_set_failure_reason(res,6,0);
  if ((g_ms_extensions != '\0') && ((res->set->flags1 & 0x10) != 0)) {
    pcVar2 = res->head;
    pcVar1 = (c1_ovl_candidate *)0x0;
    if (pcVar2 != (c1_ovl_candidate *)0x0) {
      do {
        if ((((pcVar2->flags & 0x80) == 0) &&
            ((*(byte *)((int)&pcVar2->function->tail + 8) & 0x20) != 0)) &&
           (bVar3 = pcVar1 != (c1_ovl_candidate *)0x0, pcVar1 = pcVar2, bVar3)) goto LAB_104a66c9;
        pcVar2 = pcVar2->next;
      } while (pcVar2 != (c1_ovl_candidate *)0x0);
      if (pcVar1 != (c1_ovl_candidate *)0x0) {
        return pcVar1;
      }
    }
  }
LAB_104a66c9:
  ovl_report_call_failure(res,(c1_ovl_candidate *)0x0,(c1_node *)0x0);
  return (c1_ovl_candidate *)0x0;
}

