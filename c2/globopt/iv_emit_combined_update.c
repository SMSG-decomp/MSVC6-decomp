c2_tuple * __fastcall iv_emit_combined_update(c2_operand *a,c2_operand *b,uint32_t op)

{
  uint16_t type;
  c2_tuple *pcVar1;
  int iVar2;
  c2_operand *pcVar3;
  c2_operand *op_00;
  c2_tuple *pcVar4;
  c2_symbol *pcVar5;
  c2_tuple *local_8;
  c2_tuple *local_4;
  
  free_pending_tuple_list();
  pcVar1 = g_iv_scratch_tail;
  type = a->type;
  pcVar3 = (c2_operand *)node_clone((c2_node *)a);
  op_00 = (c2_operand *)node_clone((c2_node *)b);
  operand_retype_keep_sets(op_00,type);
  pcVar4 = tuple_new_binary_temp(op,type,pcVar3,op_00,tuple_insert_before,pcVar1);
  clone_temp_def_tree(pcVar4->dst->sym,&local_8,&local_4);
  free_pending_tuple_list();
  while (local_8 != (c2_tuple *)0x0) {
    pcVar4 = local_8->next;
    tuple_insert_before(pcVar1,local_8);
    local_8 = pcVar4;
  }
  pcVar4 = pcVar1->prev;
  for (pcVar3 = pcVar4->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
    operand_retype_keep_sets(pcVar3,type);
  }
  pcVar5 = pcVar4->dst->sym;
  if (pcVar5->storage->part_next == (c2_symbol *)0x0) {
    pcVar5->def = (c2_tuple *)0x0;
  }
  else {
    symbol_mark_overlapping_parts(pcVar5,(c2_tuple *)0x0);
  }
  resimplify_tuple(pcVar4);
  pcVar1 = pcVar1->prev;
  if (((pcVar1->op == 0x16e) && (pcVar3 = pcVar1->src, pcVar3->kind == '\a')) &&
     (pcVar3->next->kind == '\x03')) {
    pcVar5 = pcVar3->next->sym;
    iVar2 = pcVar5->offset;
    if ((int)(pcVar3->u18).lo <= iVar2) {
      pcVar5 = symbol_get_part(pcVar5->storage,0x5000,0,iVar2 - (pcVar3->u18).lo);
      tuple_remove_src(pcVar1,pcVar1->src);
      pcVar1->op = 0x161;
      pcVar1->src->sym = pcVar5;
    }
  }
  return pcVar1;
}

