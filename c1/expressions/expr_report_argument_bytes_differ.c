c1_node * __cdecl expr_report_argument_bytes_differ(c1_node *call)

{
  c1_symbol *pcVar1;
  c1_type *pcVar2;
  byte bVar3;
  void *pvVar4;
  c1_node *node;
  
  node = expr_based_pointer_fixup(call);
  pcVar1 = g_call_context->callee;
  if (pcVar1 != (c1_symbol *)0x0) {
    pcVar2 = pcVar1->type;
    bVar3 = (byte)pcVar2->code;
    if (((((char)bVar3 < '\0') && (pcVar2 != (c1_type *)0x0)) && ((bVar3 & 0x83) == 0x81)) &&
       (((*(byte *)((-(uint)((pcVar2->code & 0x80) != 0) & (uint)pcVar2) + 2) & 7) == 5 ||
        ((*(byte *)((-(uint)((pcVar2->code & 0x80) != 0) & (uint)pcVar2) + 2) & 7) == 3)))) {
      if (((pcVar1->flags4 & 8) == 0) && ((pcVar2->flags & 0x2000) == 0)) {
        pvVar4 = (void *)type_parameter_list_bytes((pcVar2->extra).params);
      }
      else {
        pvVar4 = (void *)expr_call_argument_size(node);
      }
      pcVar1 = g_call_context->callee;
      if ((pcVar1->flags4 & 0x40) == 0) {
        pcVar1->detail = pvVar4;
        g_call_context->callee->flags4 = g_call_context->callee->flags4 | 0x40;
        (*g_idb->vtbl->idb_note_dependency_64)(g_idb);
      }
      else if ((((pcVar1->flags4 & 8) != 0) || ((pcVar2->flags & 0x2000) != 0)) &&
              (pvVar4 != pcVar1->detail)) {
        diag_error(0x2c4,pcVar1);
        g_call_context = g_call_context->outer;
        return node;
      }
    }
  }
  g_call_context = g_call_context->outer;
  return node;
}

