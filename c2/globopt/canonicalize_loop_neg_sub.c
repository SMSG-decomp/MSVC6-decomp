void __fastcall canonicalize_loop_neg_sub(c2_loop *loop)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *t;
  uint32_t uVar4;
  int iVar5;
  c2_const_operand *pcVar6;
  c2_tuple *pcVar7;
  code *insert_fn_00;
  c2_block *local_8;
  c2_insert_fn *insert_fn;
  
  init_list_node_pool();
  local_8 = loop->first;
  if (local_8 != loop->last->next) {
    do {
      pcVar2 = local_8->end;
      pcVar3 = local_8->head->next;
joined_r0x10744fb3:
      t = pcVar3;
      if (t != pcVar2) {
        uVar1 = t->flags13;
        pcVar3 = t->next;
        t->flags = t->flags & 0xbf;
        if ((((uVar1 == '\a') || (uVar1 == '\b')) || (uVar1 == '\n')) || (uVar1 == '\v')) {
          t->flags13 = '\0';
        }
        if (((t->op != 0x161) || ((t->type & 0xf000) != 0x1000)) ||
           (iVar5 = node_has_side_effects((c2_node *)t), iVar5 != 0)) goto LAB_10745096;
        insert_fn_00 = tuple_insert_before;
        pcVar7 = t;
        pcVar6 = operand_new_intconst(t->type,0xffffffff,-1);
        pcVar7 = tuple_new_cse_binary(0x16f,t->type,t->src,pcVar6,insert_fn_00,pcVar7);
        pcVar7->line = t->line;
        tuple_replace_src(t,t->src,pcVar7->dst);
        goto LAB_10745042;
      }
      local_8 = local_8->next;
    } while (local_8 != loop->last->next);
  }
  loop->trip_count = (c2_operand *)0x0;
  loop->exit_compare = (c2_tuple *)0x0;
  (loop->u30).iv_update_clones = (c2_list_cell *)0x0;
  g_countdown_test_tuple = (c2_tuple *)0x0;
  init_iv_scratch_list();
  return;
LAB_10745096:
  if (((t->op == 0x16e) && ((t->type & 0xf000) == 0x1000)) &&
     ((uVar4 = is_loop_invariant_operand(t->src), uVar4 != 0 &&
      ((uVar4 = is_loop_invariant_operand(t->src->next), uVar4 == 0 &&
       (iVar5 = node_has_side_effects((c2_node *)t), iVar5 == 0)))))) {
    insert_fn = tuple_insert_before;
    pcVar7 = t;
    pcVar6 = operand_new_intconst(t->type,0xffffffff,-1);
    pcVar7 = tuple_new_cse_binary(0x16f,t->type,t->src->next,pcVar6,insert_fn,pcVar7);
    pcVar7->line = t->line;
    pcVar7 = tuple_new_cse_binary(0x16d,t->type,pcVar7->dst,t->src,tuple_insert_before,t);
    pcVar7->line = t->line;
    tuple_replace_src(t,t->src,pcVar7->dst);
    tuple_remove_src(t,t->src->next);
LAB_10745042:
    t->op = 0x15b;
    number_assignment(t,1);
  }
  goto joined_r0x10744fb3;
}

