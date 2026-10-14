c2_node * __fastcall tuple_delete_if_dead(c2_node *t,int keep_side_effects)

{
  ushort uVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  int iVar4;
  c2_const_operand *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_operand *pcVar8;
  c2_node *pcVar9;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  c2_operand *dst_opnd;
  c2_operand *src_opnd;
  
  if (t == (c2_node *)0x0) {
    return (c2_node *)0x0;
  }
  if ((1 << (t->kind & 0x1f) & 0xffeU) != 0) {
    iVar4 = node_has_side_effects(t);
    if (iVar4 != 0) {
      pcVar3 = (c2_tuple *)t->rank_or_prev;
      tuple_unlink((c2_tuple *)t);
      uVar1 = t->type;
      insert_fn = tuple_splice_after;
      if ((uVar1 & 0xf000) != 0x5000) {
        pcVar8 = operand_new_temp_sym(uVar1);
        pcVar3 = tuple_new(0x15b,uVar1,pcVar8,(c2_operand *)t,insert_fn,pcVar3);
        return (c2_node *)pcVar3;
      }
      pcVar5 = operand_new_intconst(0x1004,uVar1 & 0xfff,0);
      pcVar8 = (c2_operand *)t;
      pcVar6 = operand_new_temp(uVar1);
      pcVar3 = tuple_new_blockop(0x16b,uVar1,pcVar6,pcVar8,pcVar5,insert_fn,pcVar3);
      pcVar7 = tuple_new_pseudo(0x19e,t->type);
      tuple_append_src(pcVar7,pcVar3->dst);
      pcVar3->dst->sym->def = pcVar3;
      tuple_splice_after(pcVar3,pcVar7);
      return (c2_node *)pcVar7;
    }
    pcVar3 = (c2_tuple *)t->rank_or_prev;
    tuple_unlink((c2_tuple *)t);
    pcVar8 = (c2_operand *)t;
    if ((((t->kind == '\x06') &&
         ((iVar4 = *(int *)&t[2].kind, iVar4 == 0 ||
          (((1 << (*(byte *)(iVar4 + 8) & 0x1f) & 6U) != 0 &&
           (*(int *)(*(int *)(iVar4 + 0x14) + 0x14) != 0)))))) &&
        ((uVar2 = t[2].rank_or_prev, uVar2 == 0 ||
         (((1 << (*(byte *)(uVar2 + 8) & 0x1f) & 6U) != 0 &&
          (*(int *)(*(int *)(uVar2 + 0x14) + 0x14) != 0)))))) && (iVar4 != 0)) {
      pcVar8 = *(c2_operand **)&t[2].kind;
    }
    if (((1 << (pcVar8->kind & 0x1f) & 6U) != 0) &&
       (pcVar7 = pcVar8->sym->def, pcVar7 != (c2_tuple *)0x0)) {
      if (pcVar7 == pcVar3) {
        pcVar3 = tuple_drop_unused_results(pcVar8);
      }
      else {
        tuple_drop_unused_results(pcVar8);
      }
    }
    if ((t->kind != '\x1f') && (((uint)t[1].next & 0x10) == 0)) {
      node_free(t);
      return (c2_node *)pcVar3;
    }
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\sdsu.c",0x147);
  }
  if ((t->flags & 1) != 0) {
    pcVar8 = (c2_operand *)t[1].rank_or_prev;
    while (pcVar6 = pcVar8, pcVar6 != (c2_operand *)0x0) {
      pcVar8 = pcVar6->next;
      if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
        if (pcVar6->kind == 1) {
          tuple_drop_dead_dst((c2_tuple *)t,pcVar6);
        }
        else if ((t->op == 0x16a) || (t->op == 0x16b)) {
          tuple_remove_dst((c2_tuple *)t,pcVar6);
          pcVar9 = tuple_delete_if_dead_dst_loop((c2_tuple *)t,pcVar8,keep_side_effects);
          return pcVar9;
        }
      }
    }
    for (dst_opnd = (c2_operand *)t[1].rank_or_prev; dst_opnd != (c2_operand *)0x0;
        dst_opnd = dst_opnd->next) {
      if (dst_opnd->kind != '\x01') {
        return t;
      }
      if (((dst_opnd->u18).reg)->cls != '\x01') {
        return t;
      }
    }
    if ((keep_side_effects == 0) && (iVar4 = node_has_side_effects(t), iVar4 != 0)) {
      switch(t->kind) {
      case '\f':
        if (t[1].rank_or_prev == 0) {
          pcVar3 = (c2_tuple *)t;
          for (src_opnd = *(c2_operand **)&t[1].kind; src_opnd != (c2_operand *)0x0;
              src_opnd = src_opnd->next) {
            if ((src_opnd->flags & 0x20) == 0) {
              uVar1 = src_opnd->type;
              insert_fn_00 = tuple_splice_after;
              if ((src_opnd->type & 0xf000) == 0x5000) {
                pcVar5 = operand_new_intconst(uVar1,uVar1 & 0xfff,0);
                pcVar8 = (c2_operand *)node_clone((c2_node *)src_opnd);
                pcVar6 = operand_new_temp_sym(uVar1);
                pcVar3 = tuple_new_blockop(0x16b,uVar1,pcVar6,pcVar8,pcVar5,insert_fn_00,pcVar3);
              }
              else {
                pcVar8 = (c2_operand *)node_clone((c2_node *)src_opnd);
                pcVar6 = operand_new_temp_sym(uVar1);
                pcVar3 = tuple_new(0x15b,uVar1,pcVar6,pcVar8,insert_fn_00,pcVar3);
              }
            }
          }
          tuple_unlink((c2_tuple *)t);
          node_free(t);
          return (c2_node *)pcVar3;
        }
        break;
      default:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\sdsu.c",0x1bb);
      case '\x0e':
      case '\x0f':
      case '\x11':
      case '\x12':
      case '\x14':
      case '\x15':
        break;
      }
    }
    else {
      for (pcVar8 = *(c2_operand **)&t[1].kind; pcVar8 != (c2_operand *)0x0; pcVar8 = pcVar8->next)
      {
        if (((1 << (pcVar8->kind & 0x1f) & 6U) != 0) && (pcVar8->sym->def != (c2_tuple *)0x0)) {
          tuple_drop_unused_results(pcVar8);
        }
      }
      pcVar9 = (c2_node *)t->rank_or_prev;
      tuple_unlink((c2_tuple *)t);
      node_free(t);
      t = pcVar9;
    }
  }
  return t;
}

