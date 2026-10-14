c2_symbol * __fastcall inline_fold_result_copy(c2_tuple *call,c2_tuple **anchor,c2_tuple *limit)

{
  ushort type;
  c2_operand *op;
  int iVar1;
  uint32_t uVar2;
  c2_fe_symbol *fs;
  c2_operand *src;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  int16_t kind;
  uint8_t uVar5;
  uint32_t attrs;
  c2_operand *local_14;
  c2_tuple *local_10;
  c2_tuple **local_c;
  c2_tuple *local_8;
  c2_symbol *local_4;
  
  if (((((((1 << (call->dst->kind & 0x1f) & 6U) != 0) && (call->dst->sym->def != (c2_tuple *)0x0))
        && (local_c = anchor, local_8 = call, local_10 = find_next_use_of_dst(call,&local_14),
           (local_14->flags & 0x20) == 0)) &&
       ((local_10->op == 0x15b && (op = local_10->dst, op->kind == '\x02')))) &&
      (call->dst->type == local_10->type)) &&
     (((pcVar4 = op->sym, local_4 = pcVar4, (pcVar4->flags5 & 2) == 0 &&
       (((uVar5 = pcVar4->cls, uVar5 == '\x03' || (uVar5 == '\x04')) ||
        ((uVar5 == '\x05' || (uVar5 == '\x06')))))) ||
      (iVar1 = inline_range_conflicts_with(op,&limit->next,(c2_tuple *)0x0), iVar1 == 0)))) {
    pcVar3 = *anchor;
    iVar1 = inline_range_conflicts_with(op,&pcVar3->next,call);
    if ((iVar1 == 0) && (iVar1 = inline_range_conflicts_with(op,&call->next,local_10), iVar1 == 0))
    {
      if ((pcVar4->cls == '\x03') && (pcVar4->storage->part_next == (c2_symbol *)0x0)) {
        type = op->type;
        attrs = 0;
        uVar5 = '\x04';
        iVar1 = 1;
        kind = 1;
        uVar2 = type_class_to_symbol_class(type);
        fs = fe_symbol_new_local_cur((uint16_t)uVar2,type & 0xfff,kind,iVar1,uVar5,attrs);
        src = operand_for_fe_symbol(fs);
        pcVar3 = tuple_new(0x15b,type,op,src,tuple_insert_after,pcVar3);
        *local_c = pcVar3;
        pcVar4 = local_4;
        call = local_8;
      }
      symbol_free_chain(local_14->sym);
      node_free((c2_node *)call->dst);
      call->dst = (c2_operand *)0x0;
      tuple_unlink_free(local_10);
      return pcVar4;
    }
  }
  return (c2_symbol *)0x0;
}

