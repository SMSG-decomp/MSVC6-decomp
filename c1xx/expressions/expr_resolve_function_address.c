c1_node * __cdecl expr_resolve_function_address(c1_type *target,c1_node *node)

{
  c1_u16 cVar1;
  byte bVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  ushort uVar6;
  c1_type local_10;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  cVar1 = node->type->code;
  if ((cVar1 == 0x80c) || (pcVar3 = node, cVar1 == 0x80e)) {
    pcVar3 = expr_strip_to_function_ref(node,(uint *)&node);
    if (pcVar3 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar5 = pcVar3->left;
    if ((pcVar5->flags1 & 0x10) == 0x10) {
      if ((pcVar5->kind & 0x1f) == 0x12) {
        pcVar5 = *(c1_symbol **)(*(int *)pcVar5->type + 8);
      }
      diag_error(0x115,pcVar5);
      return (c1_node *)0x0;
    }
    bVar2 = pcVar5->kind & 0x1f;
    if (bVar2 == 0x12) {
      pcVar3 = expr_member_function_address_for_type(target,(int)pcVar5);
      return pcVar3;
    }
    if (((((bVar2 == 0x10) || (bVar2 == 7)) || (bVar2 == 6)) ||
        (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))) ||
       ((bVar2 == 0x1a &&
        (((bVar2 = **(byte **)pcVar5->type & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) ||
         ((bVar2 == 6 || (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))))))))) {
      pcVar4 = (c1_type *)0x0;
      if (target != (c1_type *)0x0) {
        uVar6 = target->code & 0x8f;
        if (((uVar6 == 0x86) || (uVar6 == 0x8e)) || (((char)target->code < '\0' && (uVar6 == 0x84)))
           ) {
          pcVar4 = type_base(target);
        }
        else {
          pcVar4 = (c1_type *)0x0;
        }
      }
      pcVar5 = ovl_select_function_for_target_type(pcVar5,pcVar4,1,'\0');
      if (pcVar5 == (c1_symbol *)0x0) {
        diag_error(0x233);
        return (c1_node *)0x0;
      }
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->reference_symbol)((int)pcVar5);
      }
      pcVar3->left = pcVar5;
      local_10.base = pcVar5->type;
      local_10.debug_index = 0;
      local_10.flags = (byte)(local_10.base)->flags & 0x1f;
      local_10.code = 0x4086;
      local_10.extra.cls = (c1_symbol *)0x0;
      pcVar4 = type_intern(&local_10);
      pcVar3->type = pcVar4;
    }
  }
  return pcVar3;
}

