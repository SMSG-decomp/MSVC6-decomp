c2_operand * __fastcall split_reload_spilled_def(c2_tuple *t,c2_operand *op)

{
  uint8_t *puVar1;
  byte bVar2;
  ushort uVar3;
  c2_symbol *pcVar4;
  uint uVar5;
  c2_operand *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *t_00;
  
  t_00 = t->next;
  while ((t_00->op != 0x164 || ((t_00->src->u18).reg != (op->u18).reg))) {
    t_00 = t_00->next;
  }
  uVar5 = can_use_memory_operand(t,op);
  if (uVar5 != 0) {
    tuple_unlink_free(t_00);
    operand_make_sym(op);
    return op;
  }
  pcVar6 = operand_new_temp(op->type);
  pcVar7 = tuple_replace_dst(t,op,pcVar6);
  uVar3 = pcVar7->type;
  pcVar7->flags11 = pcVar7->flags11 | 0x10;
  pcVar4 = (pcVar6->u18).reg;
  pcVar4->def = t;
  if ((uVar3 & 0xfff) == 1) {
    puVar1 = &pcVar4->flags5;
    *puVar1 = *puVar1 | 0x80;
  }
  pcVar6 = tuple_replace_src(t_00,t_00->src,pcVar6);
  bVar2 = pcVar6->flags11;
  t_00->op = 1;
  pcVar6->flags11 = bVar2 | 0x10;
  return pcVar7;
}

