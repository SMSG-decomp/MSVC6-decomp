uint32_t __fastcall is_substitutable_address_use(c2_tuple *t,c2_operand *op)

{
  int iVar1;
  c2_operand *pcVar2;
  c2_operand *local_4;
  
  iVar1 = *(int *)((((op->u18).reg)->u38).index + 0x18);
  if (*(int *)(iVar1 + 4) != 0x14c) {
    local_4 = (c2_operand *)t;
    pcVar2 = find_mem_operand_using(t,op,&local_4);
    if ((pcVar2->op != 0x14c) && ((*(int *)(iVar1 + 4) != 0x14f || ((pcVar2->flags & 0xf) != 0)))) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x20) != 0) && (pcVar2->base_sym != (c2_symbol *)0x0)) {
      return 0;
    }
  }
  return 1;
}

