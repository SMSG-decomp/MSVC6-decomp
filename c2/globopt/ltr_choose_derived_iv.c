int __thiscall
ltr_choose_derived_iv(c2_loop *loop,c2_symbol *biv,c2_operand **limit,uint32_t a,int b,int c)

{
  c2_symbol_u34 *pcVar1;
  c2_symbol *s;
  c2_symbol *s_00;
  int iVar2;
  int iVar3;
  c2_tuple *pcVar4;
  c2_operand *op;
  c2_operand *opnd;
  uint32_t uVar5;
  c2_operand *pcVar6;
  uint32_t uVar7;
  void *pvVar8;
  int local_14;
  c2_symbol *local_10;
  c2_node *local_4;
  
  s_00 = biv;
  pcVar1 = &biv->u34;
  local_14 = -1;
  local_10 = biv;
  biv = pcVar1->parent;
  if (pcVar1->parent != (c2_symbol *)0x0) {
    do {
      iVar2 = iv_tuple_is_add_sub_of((c2_operand *)biv->storage,s_00);
      if (iVar2 != 0) {
        s = biv->storage;
        uVar7 = map_iv_update_opcode(((s->u18).expr)->op);
        pcVar6 = tuple_iv_second_source((c2_tuple *)s,s_00);
        iVar2 = iv_derivation_depth(s,s_00,1);
        if ((local_14 < iVar2) &&
           ((iVar3 = iv_operand_is_variable(pcVar6), iVar3 == 0 ||
            (iVar3 = iv_operand_is_variable(*limit), iVar3 != 0)))) {
          if ((uVar7 == 0x16f) &&
             ((((pcVar6->kind == '\a' && ((pcVar6->type & 0xf000) == 0x1000)) &&
               ((int)pcVar6->tag < 1)) && ((int)pcVar6->tag < 0)))) {
            c = 1;
            b = 1;
LAB_107623a3:
            iVar3 = sr_combine_fits((uint16_t)a,uVar7,*limit,pcVar6,loop);
            if (iVar3 == 0) goto LAB_10762312;
          }
          else if (b != 0) goto LAB_107623a3;
          if (c != 0) {
            op = operand_new_sym(0x14a,s_00->type,s_00);
            ensure_preheader_value(op,loop);
            uVar5 = is_loop_invariant_operand(opnd);
            if ((uVar5 == 0) ||
               (iVar3 = sr_combine_fits((uint16_t)a,uVar7,opnd,pcVar6,loop), iVar3 == 0))
            goto LAB_10762312;
          }
          pcVar6 = sr_materialize_operand_in_preheader(pcVar6,loop);
          pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar6);
          pcVar4 = iv_emit_combined_update(*limit,pcVar6,uVar7);
          if (pcVar4->op == 0x15b) {
            local_4 = node_clone((c2_node *)pcVar4->src);
            local_14 = iVar2;
            local_10 = s;
          }
        }
      }
LAB_10762312:
      biv = (c2_symbol *)biv->fe;
    } while ((c2_fe_symbol *)biv != (c2_fe_symbol *)0x0);
    if (local_10 != s_00) {
      pcVar6 = tuple_iv_second_source((c2_tuple *)local_10,s_00);
      uVar7 = map_iv_update_opcode(((local_10->u18).expr)->op);
      pvVar8 = alloc_quad_arena3((int)local_10,(int)pcVar6,uVar7,(int)s_00);
      pcVar6 = (c2_operand *)node_clone(local_4);
      *limit = pcVar6;
      return (int)pvVar8;
    }
  }
  return 0;
}

