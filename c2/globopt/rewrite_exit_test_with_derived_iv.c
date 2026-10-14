void __fastcall rewrite_exit_test_with_derived_iv(c2_tuple *cmp,c2_loop *loop,c2_function *fn)

{
  uint16_t type;
  c2_symbol *biv;
  c2_symbol *sym;
  uint32_t uVar1;
  c2_operand *pcVar2;
  c2_iv_derived_choice *pcVar3;
  int iVar4;
  c2_operand *new_op;
  c2_operand *new_op_00;
  c2_tuple *pcVar5;
  c2_operand *local_2c;
  c2_operand *local_24;
  c2_operand *local_20;
  int local_1c;
  uint local_18;
  uint32_t local_14;
  c2_operand *local_4;
  
  free_pending_tuple_list();
  uVar1 = is_induction_variable_operand(cmp->src);
  local_20 = cmp->src;
  if (uVar1 == 0) {
    local_24 = local_20->next;
  }
  else {
    local_24 = local_20;
    local_20 = local_20->next;
  }
  biv = local_24->sym;
  local_2c = (c2_operand *)0x0;
  local_14 = 0;
  pcVar5 = (biv->defs->u04).tuple;
  if (pcVar5->flags13 == '\x04') {
    pcVar5 = pcVar5->prev;
    if ((pcVar5->flags13 == '\x04') && ((uVar1 = pcVar5->op, uVar1 == 0x16d || (uVar1 == 0x16e)))) {
      local_2c = pcVar5->src->next;
      local_14 = uVar1;
    }
    local_1c = 1;
    local_18 = 1;
    if (((local_2c != (c2_operand *)0x0) &&
        (uVar1 = is_loop_invariant_operand(local_2c), uVar1 != 0)) &&
       (pcVar2 = sr_materialize_operand_in_preheader(local_2c,loop), pcVar2->kind == '\a')) {
      uVar1 = (pcVar2->u18).lo;
      if (pcVar5->op == 0x16e) {
        uVar1 = -uVar1;
      }
      local_18 = (uint)(-1 < (int)uVar1);
      if (0 < (int)uVar1) {
        local_1c = 0;
      }
    }
    pcVar3 = collect_iv_rewrite_chain(biv,local_20,loop,cmp->type,local_18,local_1c);
    if (pcVar3 != (c2_iv_derived_choice *)0x0) {
      do {
        sym = pcVar3->iv;
        type = sym->type;
        new_op = operand_new_sym(0x14a,type,sym);
        pcVar2 = pcVar3->step;
        uVar1 = pcVar3->op;
        new_op_00 = derived_iv_hoisted(type,uVar1,(int)local_20,(int)pcVar2,loop);
        cmp->type = type;
        local_24 = tuple_replace_src(cmp,local_24,new_op);
        local_20 = tuple_replace_src(cmp,local_20,new_op_00);
        if (local_2c == (c2_operand *)0x0) {
LAB_10762003:
          if (uVar1 == 0x16f) goto LAB_10762137;
        }
        else {
          if (uVar1 != 0x16f) {
            local_2c = (c2_operand *)node_clone((c2_node *)local_2c);
            goto LAB_10762003;
          }
          local_2c = derived_iv_hoisted(local_2c->type,0x16f,(int)local_2c,(int)pcVar2,loop);
LAB_10762137:
          if (((cmp->type & 0xf000) == 0x1000) && (pcVar2->kind == '\a')) {
            if ((pcVar2->type & 0xfff) == 4) {
              uVar1 = (int)(pcVar2->u18).reg >> 0x1f;
            }
            else {
              uVar1 = pcVar2->tag;
            }
            if (((int)uVar1 < 1) && ((int)uVar1 < 0)) {
              compare_consumer_condition(cmp);
              pcVar5 = find_next_use_of_dst(cmp,&local_4);
              branch_swap_condition(pcVar5);
            }
          }
        }
        iVar4 = range_writes_alias(loop->preheader->head,&loop->preheader->end->next,local_24);
        if (iVar4 == 0) {
          g_cur_avail_set = g_iv_assigned_exprs;
          cse_replace_operands(cmp);
          pcVar2 = find_src_symbol_ref(cmp,sym);
          if ((pcVar2 != (c2_operand *)0x0) && (iVar4 = iv_def_dominated_by(cmp,sym), iVar4 == 0)) {
            if (local_2c == (c2_operand *)0x0) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\globlopt.c",0xf84);
            }
            materialize_iv_in_preheader(local_24,type,local_2c,local_14,biv,0,loop,fn);
          }
        }
        enter_tuple_in_expression_table(cmp,0);
        pcVar3 = pcVar3->next;
      } while (pcVar3 != (c2_iv_derived_choice *)0x0);
      free_pending_tuple_list();
    }
  }
  return;
}

