c1_node * __cdecl expr_build_call(c1_node *node)

{
  c1_symbol *pcVar1;
  c1_type *pcVar2;
  byte bVar3;
  ushort uVar4;
  void *pvVar5;
  uint expected;
  c1_node *pcVar6;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (g_call_context == (c1_call_context *)0x0) {
    return node;
  }
  if ((g_call_context->flags & 1) == 0) {
    if (((0 < g_call_context->nformals) && ((*g_call_context->formal)->code != 0x80d)) &&
       ((g_call_context->flags & 2) == 0)) {
      pcVar6 = expr_report_too_few_arguments(g_call_context,node);
      return pcVar6;
    }
  }
  else {
    expected = *(byte *)((int)&g_call_context->callee->detail + 2) & 7;
    if (g_call_context->nargs != expected) {
      pcVar6 = expr_check_intrinsic_argument_count
                         (g_call_context->nargs,g_call_context,expected,node);
      return pcVar6;
    }
  }
  if ((node->type->code & 0x8f) == 0x82) {
    uVar4 = node->type->flags & 0x18;
    if (uVar4 == 0x18) {
      node = expr_based_pointer_fixup(node);
    }
    else if (uVar4 == 8) {
      pcVar6 = expr_report_argument_bytes_differ(node);
      return pcVar6;
    }
  }
  pcVar1 = g_call_context->callee;
  if (pcVar1 != (c1_symbol *)0x0) {
    pcVar2 = pcVar1->type;
    bVar3 = (byte)pcVar2->code;
    if ((((char)bVar3 < '\0') && (pcVar2 != (c1_type *)0x0)) &&
       (((bVar3 & 0x83) == 0x81 &&
        (((*(byte *)((-(uint)((pcVar2->code & 0x80) != 0) & (uint)pcVar2) + 2) & 7) == 5 ||
         ((*(byte *)((-(uint)((pcVar2->code & 0x80) != 0) & (uint)pcVar2) + 2) & 7) == 3)))))) {
      if (((pcVar1->flags4 & 8) == 0) && ((pcVar2->flags & 0x2000) == 0)) {
        pvVar5 = (void *)type_parameter_list_bytes((pcVar2->extra).params);
      }
      else {
        pvVar5 = (void *)expr_call_argument_size(node);
      }
      pcVar1 = g_call_context->callee;
      if ((pcVar1->flags4 & 0x40) == 0) {
        pcVar1->detail = pvVar5;
        g_call_context->callee->flags4 = g_call_context->callee->flags4 | 0x40;
        (*g_idb->vtbl->idb_note_dependency_64)(g_idb);
      }
      else if ((((pcVar1->flags4 & 8) != 0) || ((pcVar2->flags & 0x2000) != 0)) &&
              (pvVar5 != pcVar1->detail)) {
        diag_error(0x2c4,pcVar1);
        g_call_context = g_call_context->outer;
        return node;
      }
    }
  }
  g_call_context = g_call_context->outer;
  return node;
}

