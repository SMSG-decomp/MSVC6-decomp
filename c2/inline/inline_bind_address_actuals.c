int __fastcall inline_bind_address_actuals(c2_function *callee,c2_tuple *entry,c2_tuple *call)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  
  iVar3 = 0;
  if ((callee->flags & 1) == 0) {
    if (callee->struct_return == (c2_fe_symbol *)0x0) {
      pcVar4 = call->src->next;
    }
    else {
      pcVar1 = call->src->next;
      pcVar4 = pcVar1->next;
      callee->struct_return->storage_sym->order_next = (c2_symbol *)pcVar1->sym->def->src;
    }
    pcVar1 = entry->src;
    while ((((pcVar4 != (c2_operand *)0x0 && ((1 << (pcVar4->kind & 0x1f) & 6U) != 0)) &&
            (pcVar2 = pcVar4->sym->def, pcVar2 != (c2_tuple *)0x0)) &&
           ((pcVar2->op == 0x15a || (pcVar2->op == 0x16a))))) {
      if ((1 << (*(byte *)&((c2_symbol *)pcVar2->src)->storage & 0x1f) & 0x18U) == 0) {
        pcVar1->sym->order_next = (c2_symbol *)0x0;
      }
      else {
        iVar3 = iVar3 + 1;
        pcVar1->sym->order_next = (c2_symbol *)pcVar2->src;
      }
      pcVar4 = pcVar4->next;
      pcVar1 = pcVar1->next;
    }
    return iVar3;
  }
  return 0;
}

