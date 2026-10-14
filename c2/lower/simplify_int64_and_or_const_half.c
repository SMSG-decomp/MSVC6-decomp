c2_tuple * __fastcall simplify_int64_and_or_const_half(c2_tuple *t,uint32_t op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  bool bVar4;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_tuple *t_00;
  
  if (op == 0x2e) {
    op = 0x172;
  }
  else if (op == 0x30) {
    op = 0x173;
  }
  pcVar6 = t->src;
  pcVar1 = pcVar6->next;
  if (pcVar1->kind != '\a') {
    return t;
  }
  if ((pcVar6->kind == '\x06') &&
     (((((pcVar2 = pcVar6->base, pcVar2 != (c2_operand *)0x0 &&
         ((1 << (pcVar2->kind & 0x1f) & 6U) != 0)) && (pcVar2->sym->def != (c2_tuple *)0x0)) &&
       (uVar5 = temp_operand_piece_mismatch(pcVar2), uVar5 != 0)) ||
      (((pcVar2 = pcVar6->index, pcVar2 != (c2_operand *)0x0 &&
        ((1 << (pcVar2->kind & 0x1f) & 6U) != 0)) &&
       ((pcVar2->sym->def != (c2_tuple *)0x0 &&
        (uVar5 = temp_operand_piece_mismatch(pcVar2), uVar5 != 0)))))))) {
    return t;
  }
  pcVar3 = (pcVar1->u18).reg;
  if ((pcVar3 != (c2_symbol *)0x0) && (pcVar3 != (c2_symbol *)0xffffffff)) {
    return t;
  }
  if (op == 0x172) {
    if (pcVar3 != (c2_symbol *)0x0) {
LAB_1076d5c2:
      bVar4 = false;
      goto LAB_10759f4e;
    }
  }
  else if ((op != 0x173) || (pcVar3 == (c2_symbol *)0x0)) goto LAB_1076d5c2;
  bVar4 = true;
  pcVar6 = pcVar1;
LAB_10759f4e:
  pcVar1 = t->dst;
  t_00 = tuple_new(1,0x1004,pcVar1,pcVar6,tuple_insert_after,t);
  if (((pcVar1->kind == '\x01') && (pcVar3 = pcVar1->sym, pcVar3->cls == '\x03')) &&
     (pcVar3->def != (c2_tuple *)0x0)) {
    pcVar3->def = t_00;
  }
  pcVar6 = t->dst->next;
  if (((pcVar6 != (c2_operand *)0x0) && (tuple_append_dst(t_00,pcVar6), pcVar6->kind == '\x01')) &&
     ((pcVar3 = pcVar6->sym, pcVar3->cls == '\x03' && (pcVar3->def != (c2_tuple *)0x0)))) {
    pcVar3->def = t_00;
  }
  t->dst = (c2_operand *)0x0;
  if (!bVar4) {
    tuple_unlink_free(t);
    return t_00;
  }
  tuple_delete_if_dead((c2_node *)t,0);
  return t_00;
}

