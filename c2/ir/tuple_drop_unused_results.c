c2_tuple * __fastcall tuple_drop_unused_results(c2_operand *op)

{
  uint uVar1;
  c2_symbol *sym;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_operand *local_c;
  c2_operand *local_8;
  c2_operand *local_4;
  
  pcVar3 = op->sym->def;
  pcVar2 = find_dst_symbol_ref(pcVar3,op->sym);
  local_8 = pcVar2;
  for (pcVar6 = pcVar3->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
    if (pcVar6 != pcVar2) {
      if (pcVar6->kind == 1) {
        sym = pcVar6->sym;
        if ((sym->cls != '\x01') &&
           ((sym->def == (c2_tuple *)0x0 ||
            (local_c = (c2_operand *)
                       find_next_use_of_symbol((c2_node *)pcVar3,sym,(c2_operand **)0x0),
            local_c->op != 0x19e)))) goto LAB_10750883;
      }
      else if (((1 << (pcVar6->kind & 0x1f) & 6U) == 0) ||
              ((pcVar6->sym->def == (c2_tuple *)0x0 ||
               (pcVar4 = operand_list_find_reg(pcVar3->src,(pcVar6->u18).reg),
               pcVar4 == (c2_operand *)0x0)))) {
LAB_10750883:
        if (pcVar6 != (c2_operand *)0x0) {
          uVar1 = pcVar3->op;
          if (((uVar1 != 0) && (uVar1 < 0x144)) &&
             (((g_x86_op_flags[uVar1] & 0x40) != 0 ||
              ((pcVar3->kind == '\f' &&
               ((((1 << (pcVar2->kind & 0x1f) & 6U) == 0 || (pcVar2->sym->def == (c2_tuple *)0x0))
                || (pcVar6 = operand_list_find_reg(pcVar3->src,(pcVar2->u18).reg),
                   pcVar6 == (c2_operand *)0x0)))))))) {
            pcVar5 = tuple_new_pseudo(0x19e,0x1004);
            tuple_append_src(pcVar5,pcVar2);
            tuple_insert_after(pcVar3,pcVar5);
            return pcVar3;
          }
          tuple_drop_dead_dst(pcVar3,pcVar2);
          return pcVar3;
        }
        break;
      }
    }
  }
  pcVar6 = pcVar3->dst;
  while (pcVar4 = pcVar6, pcVar4 != (c2_operand *)0x0) {
    pcVar6 = pcVar4->next;
    local_4 = pcVar6;
    if ((pcVar4 != pcVar2) && ((pcVar4->kind != 1 || (pcVar4->sym->cls != '\x01')))) {
      if (((1 << (pcVar4->kind & 0x1f) & 6U) == 0) || (pcVar4->sym->def == (c2_tuple *)0x0)) break;
      pcVar5 = find_next_use_of_symbol((c2_node *)pcVar3,pcVar4->sym,&local_c);
      if (pcVar5->op == 0x19e) {
        tuple_remove_dst(pcVar3,pcVar4);
        tuple_unlink_free(pcVar5);
        pcVar2 = local_8;
      }
      else {
        pcVar6 = operand_list_find_reg(pcVar3->src,(pcVar4->u18).reg);
        tuple_replace_src(pcVar5,local_c,pcVar6);
        tuple_remove_dst(pcVar3,pcVar4);
        pcVar2 = operand_new_temp_sym(pcVar6->type);
        tuple_replace_src(pcVar3,pcVar6,pcVar2);
        pcVar6 = local_4;
        pcVar2 = local_8;
      }
    }
  }
  pcVar3 = (c2_tuple *)tuple_delete_if_dead((c2_node *)pcVar3,0);
  return pcVar3;
}

