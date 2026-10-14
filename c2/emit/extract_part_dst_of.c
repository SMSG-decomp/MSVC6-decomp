c2_operand * __fastcall extract_part_dst_of(c2_tuple *t,c2_operand *op,int *reg)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  c2_operand *list;
  uint32_t uVar3;
  c2_operand *op_00;
  c2_operand *pcVar4;
  
  pcVar4 = (c2_operand *)0x0;
  if (op->kind == '\x01') {
    pcVar2 = op->sym;
    uVar1 = pcVar2->cls;
    *reg = 0;
    if ((uVar1 == '\x03') && (pcVar2->def != (c2_tuple *)0x0)) {
      uVar3 = temp_operand_piece_mismatch(op);
      if (uVar3 != 0) {
        pcVar2 = (op->u18).reg;
        *reg = (int)pcVar2;
        list = t->dst;
        op_00 = operand_list_find_reg(list,pcVar2);
        if ((op_00 != (c2_operand *)0x0) && (op_00 != list)) {
          pcVar4 = (c2_operand *)node_clone((c2_node *)op_00);
          tuple_remove_dst(t,op_00);
        }
      }
    }
    return pcVar4;
  }
  return (c2_operand *)0x0;
}

