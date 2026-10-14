c2_operand * __fastcall retarget_push_value_register(c2_tuple *t,c2_operand *op)

{
  c2_tuple *t_00;
  uint uVar1;
  c2_symbol *reg;
  uint32_t uVar2;
  int iVar3;
  c2_operand *pcVar4;
  
  t_00 = op->sym->def;
  reg = reg_find_subreg((op->u18).reg,(t_00->dst->type & 0xfff) << 3,0);
  uVar2 = temp_operand_piece_mismatch(t_00->dst);
  if (((uVar2 == 0) || ((t_00->dst->u18).reg == reg)) &&
     (iVar3 = range_touches_reg(&t_00->next,t,reg), iVar3 == 0)) {
    uVar1 = t_00->op;
    (t_00->dst->u18).reg = reg;
    if (((uVar1 != 0) && (uVar1 < 0x144)) && ((g_x86_op_flags[uVar1] & 0x40) != 0)) {
      tie_dest_to_source_temp(t_00);
    }
    return op;
  }
  pcVar4 = t_00->dst;
  pcVar4->u18 = (c2_operand_u18)pcVar4->sym;
  pcVar4 = emit_load_into_register(1,t,pcVar4,reg);
  tuple_replace_src(t,op,pcVar4);
  return pcVar4;
}

