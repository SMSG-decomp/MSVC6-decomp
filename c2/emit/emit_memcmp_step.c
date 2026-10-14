c2_tuple * __fastcall
emit_memcmp_step(c2_operand *a,c2_operand *b,int off,uint16_t type,c2_tuple *fail,c2_tuple *at,
                c2_operand **out)

{
  int32_t *piVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  
  pcVar2 = (c2_operand *)node_clone((c2_node *)a);
  pcVar2->disp = pcVar2->disp + off;
  pcVar3 = tuple_new_unary_temp(1,type,pcVar2,tuple_insert_after,at);
  tuple_legalize_mem_operands(pcVar3);
  pcVar4 = operand_new_temp_sym(type);
  pcVar2 = pcVar3->dst;
  *out = pcVar4;
  pcVar3 = tuple_new(1,type,pcVar4,pcVar2,tuple_insert_after,pcVar3);
  pcVar2 = bind_value_to_new_temp(pcVar3,pcVar3->src->sym,1);
  pcVar3 = pcVar3->next;
  pcVar4 = (c2_operand *)node_clone((c2_node *)b);
  pcVar3 = emit_op_before_with_parts(0x2f,type,pcVar2,pcVar4,pcVar3);
  piVar1 = &pcVar3->src->next->disp;
  *piVar1 = *piVar1 + off;
  tuple_legalize_mem_operands(pcVar3);
  if (fail != (c2_tuple *)0x0) {
    pcVar3 = tuple_new_branch(0xf,'\x02',(c2_node *)fail,pcVar3->dst,pcVar3,tuple_insert_after,
                              pcVar3);
    return pcVar3;
  }
  return pcVar3;
}

