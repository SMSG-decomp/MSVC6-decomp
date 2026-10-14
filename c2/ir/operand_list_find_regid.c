c2_operand * __fastcall operand_list_find_regid(uint32_t regid,c2_operand *op)

{
  while ((op != (c2_operand *)0x0 &&
         ((op->kind != '\x01' || (((op->u18).reg)->storage->id != regid))))) {
    op = op->next;
  }
  return op;
}

