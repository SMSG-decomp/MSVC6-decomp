int __fastcall fold_bitfield_merge(c2_tuple *t)

{
  uint16_t type;
  bool bVar1;
  int iVar2;
  c2_operand *arm_a;
  c2_tuple *and_b;
  c2_tuple *and_a;
  c2_operand *pcVar3;
  c2_operand *kept_mask;
  c2_operand *mask_a;
  uint64_t uVar4;
  c2_operand *arm_b;
  c2_operand *mask_b;
  
  pcVar3 = t->src;
  kept_mask = pcVar3->next;
  if (((pcVar3->op == 0x172) && (kept_mask != (c2_operand *)0x0)) && (kept_mask->op == 0x172)) {
    for (mask_a = (pcVar3->u18).children; mask_a != (c2_operand *)0x0; mask_a = mask_a->next) {
      if (mask_a->kind == '\a') {
        for (mask_b = (kept_mask->u18).children; mask_b != (c2_operand *)0x0; mask_b = mask_b->next)
        {
          if ((mask_b->kind == '\a') &&
             (uVar4 = const_normalize(t->type,0xffffffff,-1),
             uVar4 == CONCAT44(mask_b->tag ^ mask_a->tag,(mask_b->u18).lo ^ (mask_a->u18).lo))) {
            if ((mask_b->tag < mask_a->tag) ||
               ((mask_b->tag <= mask_a->tag && ((mask_b->u18).reg <= (mask_a->u18).reg)))) {
              bVar1 = false;
              iVar2 = tree_is_bitfield_mergeable((c2_node *)t->src);
              if (iVar2 == 0) {
                return 0;
              }
            }
            else {
              bVar1 = true;
              iVar2 = tree_is_bitfield_mergeable((c2_node *)kept_mask);
              if (iVar2 == 0) {
                return 0;
              }
            }
            pcVar3 = t->src;
            g_simplify_changed = 1;
            tuple_detach_src((c2_node *)pcVar3,mask_a);
            arm_a = (c2_operand *)simplify_node_algebraic((c2_tuple *)pcVar3,t);
            tuple_detach_src((c2_node *)t,arm_a);
            tuple_detach_src((c2_node *)kept_mask,mask_b);
            arm_b = (c2_operand *)simplify_node_algebraic((c2_tuple *)kept_mask,t);
            tuple_detach_src((c2_node *)t,arm_b);
            pcVar3 = arm_a;
            kept_mask = mask_b;
            if (bVar1) {
              pcVar3 = arm_b;
              kept_mask = mask_a;
              mask_a = mask_b;
              arm_b = arm_a;
            }
            node_free((c2_node *)mask_a);
            type = t->type;
            and_b = tuple_new_binary_temp
                              (0x174,type,pcVar3,arm_b,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
            tuple_unlink_mem_subops(and_b);
            and_b->flags12 = '\x02';
            kept_mask = (c2_operand *)
                        tuple_new_binary_temp
                                  (0x172,type,(c2_operand *)and_b,kept_mask,(c2_insert_fn *)0x0,
                                   (c2_tuple *)0x0);
            tuple_unlink_mem_subops((c2_tuple *)kept_mask);
            *(undefined1 *)&kept_mask->x12 = 2;
            and_a = (c2_tuple *)bitfield_clone_tree((c2_node *)pcVar3);
            pcVar3 = (c2_operand *)
                     tuple_new_binary_temp
                               (0x174,type,kept_mask,(c2_operand *)and_a,(c2_insert_fn *)0x0,
                                (c2_tuple *)0x0);
            tuple_unlink_mem_subops((c2_tuple *)pcVar3);
            *(undefined1 *)&pcVar3->x12 = 2;
            tuple_append_src(t,pcVar3);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

