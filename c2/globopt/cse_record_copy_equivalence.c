void __fastcall
cse_record_copy_equivalence(c2_tuple *t,c2_cse_expr *expr,c2_operand *v,c2_operand *a,c2_operand *b)

{
  uint16_t type;
  c2_copy_link *pcVar1;
  c2_symbol *pcVar2;
  c2_cse_expr *pcVar3;
  uint32_t uVar4;
  int iVar5;
  c2_symbol *s;
  uint32_t uVar6;
  c2_operand *pcVar7;
  c2_operand *pcVar8;
  c2_tuple *t_00;
  
  for (pcVar1 = (v->sym->u34).source_links; pcVar1 != (c2_copy_link *)0x0;
      pcVar1 = pcVar1->next_of_source) {
    pcVar2 = pcVar1->copy;
    pcVar3 = (pcVar2->u18).expr;
    if (((((pcVar3 != (c2_cse_expr *)0x0) && (pcVar3->op == 0x15b)) &&
         (pcVar2->def == (c2_tuple *)0x0)) &&
        ((uVar4 = bitset_test(g_cur_avail_set,pcVar2->id), uVar4 != 0 &&
         (iVar5 = operand_compare(v,pcVar3->operands->next), iVar5 == 0)))) &&
       (iVar5 = operand_compare(pcVar3->operands,pcVar3->operands->next), iVar5 != 0)) {
      pcVar7 = a;
      if (v == a) {
        pcVar7 = pcVar3->operands;
      }
      pcVar8 = b;
      if (v == b) {
        pcVar8 = pcVar3->operands;
      }
      type = expr->type;
      uVar4 = expr->op;
      s = cse_find_or_make(uVar4,type,pcVar7,pcVar8);
      link_expression_operands(s);
      pcVar2 = expr->sym;
      if (((s->def != (c2_tuple *)0x0) || (uVar6 = bitset_test(g_cur_avail_set,s->id), uVar6 == 0))
         && (pcVar2 != s)) {
        pcVar7 = operand_new_sym(0x14a,type,pcVar2);
        pcVar8 = operand_new_sym(0x14a,type,s);
        t_00 = tuple_new(0x15b,type,pcVar8,pcVar7,tuple_insert_after,t);
        g_next_tuple_cursor = t_00;
        iVar5 = is_compare_branch_op(uVar4);
        if (iVar5 != 0) {
          t_00->flags13 = '\x01';
        }
        t_00->flags = t_00->flags | 0x20;
        number_assignment(t_00,0);
      }
    }
  }
  return;
}

