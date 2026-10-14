int __fastcall merge_parallel_induction_variables(c2_loop *loop,c2_function *fn)

{
  c2_symbol *pcVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_node *node;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_40;
  c2_node *local_3c;
  int local_34;
  int local_30;
  uint local_2c;
  uint32_t local_28;
  c2_operand *local_24;
  c2_function *local_20;
  uint32_t local_1c;
  c2_operand *local_18;
  c2_tuple *local_14;
  int local_10;
  c2_block *local_c;
  c2_block *local_8;
  int local_4;
  
  local_40 = 0;
  local_34 = 0;
  local_20 = fn;
  reset_iv_worklists();
  collect_iv_candidates(loop,4);
  free_pending_tuple_list();
  pcVar3 = iv_worklist_pop();
  do {
    if (pcVar3 == (c2_tuple *)0x0) {
      free_pending_tuple_list();
      pcVar3 = loop->preheader->end;
      pcVar4 = loop->preheader->head->next;
      while (pcVar5 = pcVar4, pcVar5 != pcVar3) {
        pcVar4 = pcVar5->next;
        if (pcVar5->flags13 == '\t') {
          tuple_unlink_free(pcVar5);
        }
      }
      return local_40;
    }
    pcVar1 = pcVar3->dst->sym;
    pcVar4 = (pcVar1->defs->u04).tuple;
    local_14 = pcVar4->prev;
    local_28 = local_14->op;
    local_2c = ((byte)~pcVar4->src->flags11 & 0x10) >> 4;
    local_24 = local_14->src->next;
    local_8 = tuple_get_block(local_14);
    local_10 = list_length((c2_link *)pcVar1->uses);
    local_30 = operand_live_after_loop(pcVar3->dst);
    pcVar4 = iv_worklist_pop();
    while( true ) {
      if (pcVar4 == (c2_tuple *)0x0) goto LAB_10745cdb;
      pcVar1 = pcVar4->dst->sym;
      pcVar5 = (pcVar1->defs->u04).tuple;
      pcVar7 = pcVar5->prev;
      local_1c = pcVar7->op;
      uVar8 = ((byte)~pcVar5->src->flags11 & 0x10) >> 4;
      local_18 = pcVar7->src->next;
      local_c = tuple_get_block(pcVar7);
      iVar9 = operand_live_after_loop(pcVar4->dst);
      iVar10 = types_compatible(pcVar3->type,pcVar4->type);
      if ((((((iVar10 != 0) && (iVar10 = operand_compare(local_24,local_18), iVar10 == 0)) &&
            (local_28 == local_1c)) && (local_8 == local_c)) && ((local_30 == 0 || (iVar9 == 0))))
         && ((local_2c == 0 || (uVar8 == 0)))) break;
LAB_1074603b:
      iv_retry_list_push(pcVar4);
LAB_10745fbe:
      pcVar4 = iv_worklist_pop();
    }
    local_4 = list_length((c2_link *)pcVar1->uses);
    if (((local_4 < local_10) || (local_30 != 0)) || (local_2c != 0)) {
      pcVar5 = iv_emit_combined_update(pcVar4->src,pcVar3->src,0x16e);
      pcVar5 = iv_find_preheader_equivalent
                         (pcVar5,pcVar4->dst,pcVar3->dst,local_18,local_1c,loop,local_20);
      if ((((pcVar5 == (c2_tuple *)0x0) || (local_30 != 0)) || (iVar9 != 0)) ||
         ((local_2c != 0 || (uVar8 != 0)))) {
        pcVar5 = iv_emit_combined_update(pcVar4->src,pcVar3->src,0x16e);
        pcVar6 = accept_iv_init_difference(pcVar5);
        if (((pcVar6 == (c2_operand *)0x0) || ((iVar9 != 0 || (uVar8 != 0)))) ||
           (iVar9 = iv_merge_blocked_by_alias(pcVar4->dst,local_14,pcVar7), iVar9 != 0))
        goto LAB_1074603b;
        rewrite_iv_uses_from_survivor(loop,pcVar4,pcVar3,pcVar6,&local_10);
        local_40 = 1;
        goto LAB_10745fbe;
      }
      pcVar7 = iv_emit_combined_update(pcVar3->src,pcVar5->src,0x16e);
      node = node_clone((c2_node *)pcVar7);
      pcVar7 = iv_emit_combined_update(pcVar4->src,pcVar5->src,0x16e);
      local_3c = node_clone((c2_node *)pcVar7);
      uVar2 = node->op;
      if (((uVar2 == 0x15b) || (uVar2 == 0x161)) &&
         ((local_3c->op == 0x15b || (local_3c->op == 0x161)))) {
        if (uVar2 == 0x15b) {
          rewrite_iv_uses_from_survivor(loop,pcVar3,pcVar5,*(c2_operand **)&node[1].kind,&local_34);
          local_40 = 1;
        }
        if (local_3c->op == 0x15b) {
          rewrite_iv_uses_from_survivor
                    (loop,pcVar4,pcVar5,*(c2_operand **)&local_3c[1].kind,&local_34);
          local_40 = 1;
        }
        pcVar3 = iv_worklist_pop();
        while (pcVar3 != (c2_tuple *)0x0) {
          iv_retry_list_push(pcVar3);
          pcVar3 = iv_worklist_pop();
        }
      }
    }
    else {
      pcVar5 = iv_emit_combined_update(pcVar3->src,pcVar4->src,0x16e);
      pcVar5 = iv_find_preheader_equivalent
                         (pcVar5,pcVar3->dst,pcVar4->dst,local_24,local_28,loop,local_20);
      if (((pcVar5 == (c2_tuple *)0x0) || (iVar9 != 0)) || (uVar8 != 0)) {
        pcVar5 = iv_emit_combined_update(pcVar3->src,pcVar4->src,0x16e);
        pcVar6 = accept_iv_init_difference(pcVar5);
        if ((pcVar6 == (c2_operand *)0x0) ||
           (iVar9 = iv_merge_blocked_by_alias(pcVar3->dst,local_14,pcVar7), iVar9 != 0))
        goto LAB_1074603b;
        rewrite_iv_uses_from_survivor(loop,pcVar3,pcVar4,pcVar6,&local_4);
        local_40 = 1;
        iv_retry_list_push(pcVar4);
        pcVar3 = iv_worklist_pop();
        while (pcVar3 != (c2_tuple *)0x0) {
          iv_retry_list_push(pcVar3);
          pcVar3 = iv_worklist_pop();
        }
        goto LAB_10745cdb;
      }
      pcVar7 = iv_emit_combined_update(pcVar3->src,pcVar5->src,0x16e);
      node = node_clone((c2_node *)pcVar7);
      pcVar7 = iv_emit_combined_update(pcVar4->src,pcVar5->src,0x16e);
      local_3c = node_clone((c2_node *)pcVar7);
      uVar2 = node->op;
      if (((uVar2 == 0x15b) || (uVar2 == 0x161)) &&
         ((local_3c->op == 0x15b || (local_3c->op == 0x161)))) {
        if (uVar2 == 0x15b) {
          rewrite_iv_uses_from_survivor(loop,pcVar3,pcVar5,*(c2_operand **)&node[1].kind,&local_34);
          local_40 = 1;
        }
        if (local_3c->op == 0x15b) {
          rewrite_iv_uses_from_survivor
                    (loop,pcVar4,pcVar5,*(c2_operand **)&local_3c[1].kind,&local_34);
          local_40 = 1;
        }
        pcVar3 = iv_worklist_pop();
        while (pcVar3 != (c2_tuple *)0x0) {
          iv_retry_list_push(pcVar3);
          pcVar3 = iv_worklist_pop();
        }
      }
    }
    node_free(node);
    node_free(local_3c);
LAB_10745cdb:
    pcVar3 = iv_retry_list_pop();
    while (pcVar3 != (c2_tuple *)0x0) {
      iv_worklist_push(pcVar3);
      pcVar3 = iv_retry_list_pop();
    }
    pcVar3 = iv_worklist_pop();
  } while( true );
}

